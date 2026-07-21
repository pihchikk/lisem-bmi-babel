# cython: c_string_type=unicode, c_string_encoding=utf8

cimport numpy as np
from libcpp.string cimport string
from libcpp.vector cimport vector

import numpy as np

np.import_array()

# start: lisem.pyx

cdef extern from "BmiLisem.h":
    cdef cppclass BmiLisem:
        BmiLisem() except +

        #  Model control functions.
        void Initialize(string config_file) except +
        void Update() except +
        void UpdateUntil(double time) except +
        void Finalize() except +

        #  Model information functions.
        string GetComponentName() except +
        int GetInputItemCount() except +
        int GetOutputItemCount() except +
        vector[string] GetInputVarNames() except +
        vector[string] GetOutputVarNames() except +

        #  Variable information functions
        int GetVarGrid(string name) except +
        string GetVarType(string name) except +
        string GetVarUnits(string name) except +
        int GetVarItemsize(string name) except +
        int GetVarNbytes(string name) except +
        string GetVarLocation(string name) except +

        double GetCurrentTime() except +
        double GetStartTime() except +
        double GetEndTime() except +
        string GetTimeUnits() except +
        double GetTimeStep() except +

        #  Variable getters
        void GetValue(string name, void *dest) except +
        void *GetValuePtr(string name) except +
        void GetValueAtIndices(string name, void *dest, int *inds, int count) except +

        #  Variable setters
        void SetValue(string name, void *src) except +
        void SetValueAtIndices(string name, int *inds, int count, void *src) except +

        #  Grid information functions
        int GetGridRank(const int grid) except +
        int GetGridSize(const int grid) except +
        string GetGridType(const int grid) except +

        void GetGridShape(const int grid, int *shape) except +
        void GetGridSpacing(const int grid, double *spacing) except +
        void GetGridOrigin(const int grid, double *origin) except +

        void GetGridX(const int grid, double *x) except +
        void GetGridY(const int grid, double *y) except +
        void GetGridZ(const int grid, double *z) except +

        int GetGridNodeCount(const int grid) except +
        int GetGridEdgeCount(const int grid) except +
        int GetGridFaceCount(const int grid) except +

        void GetGridEdgeNodes(const int grid, int *edge_nodes) except +
        void GetGridFaceEdges(const int grid, int *face_edges) except +
        void GetGridFaceNodes(const int grid, int *face_nodes) except +
        void GetGridNodesPerFace(const int grid, int *nodes_per_face) except +


cdef bytes _as_bytes(name):
    """Py3-safe conversion of a BMI variable name to bytes for std::string."""
    if isinstance(name, bytes):
        return name
    return (<object>name).encode("utf-8")


# Map a BMI type string to a numpy dtype so callers can size their buffers.
_BMI_TYPE_TO_DTYPE = {
    "double": np.float64,
    "float": np.float32,
    "int": np.intc,
    "int32": np.int32,
    "int64": np.int64,
}


cdef class Lisem:
    cdef BmiLisem _bmi

    METADATA = "../data/Lisem"

    def __cinit__(self):
        pass

    def initialize(self, config_file):
        self._bmi.Initialize(_as_bytes(config_file))

    def update(self):
        self._bmi.Update()

    def update_until(self, time):
        self._bmi.UpdateUntil(time)

    def finalize(self):
        self._bmi.Finalize()

    cpdef int get_var_grid(self, name):
        return self._bmi.GetVarGrid(_as_bytes(name))

    cpdef string get_var_type(self, name):
        return self._bmi.GetVarType(_as_bytes(name))

    cpdef string get_var_units(self, name):
        return self._bmi.GetVarUnits(_as_bytes(name))

    cpdef int get_var_itemsize(self, name):
        return self._bmi.GetVarItemsize(_as_bytes(name))

    cpdef int get_var_nbytes(self, name):
        return self._bmi.GetVarNbytes(_as_bytes(name))

    cpdef string get_var_location(self, name):
        return self._bmi.GetVarLocation(_as_bytes(name))

    cpdef string get_component_name(self):
        return self._bmi.GetComponentName()

    cpdef int get_input_item_count(self):
        return self._bmi.GetInputItemCount()

    cpdef int get_output_item_count(self):
        return self._bmi.GetOutputItemCount()

    def get_input_var_names(self):
        return tuple(v.decode("utf-8") if isinstance(v, bytes) else v
                     for v in self._bmi.GetInputVarNames())

    def get_output_var_names(self):
        return tuple(v.decode("utf-8") if isinstance(v, bytes) else v
                     for v in self._bmi.GetOutputVarNames())

    cpdef double get_current_time(self):
        return self._bmi.GetCurrentTime()

    cpdef double get_start_time(self):
        return self._bmi.GetStartTime()

    cpdef double get_end_time(self):
        return self._bmi.GetEndTime()

    cpdef string get_time_units(self):
        return self._bmi.GetTimeUnits()

    cpdef double get_time_step(self):
        return self._bmi.GetTimeStep()

    cdef void _check_buffer(self, name, np.ndarray buff, bint writing):
        """Validate dtype width and C-contiguity before a raw memcpy."""
        if not buff.flags["C_CONTIGUOUS"]:
            raise ValueError(
                "buffer for '%s' must be C-contiguous" % name)
        cdef int nbytes = self._bmi.GetVarNbytes(_as_bytes(name))
        if buff.nbytes != nbytes:
            expected = self.get_var_type(name)
            raise ValueError(
                "buffer for '%s' has %d bytes but the variable needs %d "
                "(expected dtype '%s'); check ndarray dtype/size"
                % (name, buff.nbytes, nbytes, expected))

    cpdef get_value(self, name, np.ndarray buff):
        self._check_buffer(name, buff, False)
        self._bmi.GetValue(_as_bytes(name), buff.data)
        return buff

    def get_value_ptr(self, name):
        """Return an ndarray that views the model's internal buffer.

        Note: some variables (e.g. the erosion map, stored as kg/cell but
        exposed as kg/m2 by get_value) have no valid pointer representation and
        will raise from the C++ layer — use get_value for those.
        """
        cdef bytes bname = _as_bytes(name)
        cdef void *ptr = self._bmi.GetValuePtr(bname)
        cdef int nbytes = self._bmi.GetVarNbytes(bname)
        cdef int itemsize = self._bmi.GetVarItemsize(bname)
        cdef np.npy_intp n = nbytes // itemsize
        dtype = np.dtype(_BMI_TYPE_TO_DTYPE[self.get_var_type(name)])
        cdef np.ndarray arr = np.PyArray_SimpleNewFromData(
            1, &n, np.dtype(dtype).num, ptr)
        return arr

    cpdef get_value_at_indices(self, name, np.ndarray buff, np.ndarray[int, ndim=1] indices):
        if not buff.flags["C_CONTIGUOUS"]:
            raise ValueError("buffer for '%s' must be C-contiguous" % name)
        self._bmi.GetValueAtIndices(
            _as_bytes(name), buff.data, &indices[0], <int>indices.size)
        return buff

    cpdef set_value(self, name, np.ndarray buff):
        self._check_buffer(name, buff, True)
        self._bmi.SetValue(_as_bytes(name), buff.data)
        return buff

    cpdef set_value_at_indices(self, name, np.ndarray[int, ndim=1] indices, np.ndarray buff):
        if not buff.flags["C_CONTIGUOUS"]:
            raise ValueError("buffer for '%s' must be C-contiguous" % name)
        self._bmi.SetValueAtIndices(
            _as_bytes(name), &indices[0], <int>indices.size, buff.data)
        return buff

    cpdef int get_grid_rank(self, gid):
        return self._bmi.GetGridRank(gid)

    cpdef int get_grid_size(self, gid):
        return self._bmi.GetGridSize(gid)

    cpdef int get_grid_node_count(self, gid):
        return self._bmi.GetGridNodeCount(gid)

    cpdef int get_grid_edge_count(self, gid):
        return self._bmi.GetGridEdgeCount(gid)

    cpdef int get_grid_face_count(self, gid):
        return self._bmi.GetGridFaceCount(gid)

    cpdef string get_grid_type(self, gid):
        return self._bmi.GetGridType(gid)

    cpdef get_grid_shape(self, gid, np.ndarray[int, ndim=1] shape):
        self._bmi.GetGridShape(gid, &shape[0])
        return shape

    cpdef get_grid_spacing(self, gid, np.ndarray[double, ndim=1] spacing):
        self._bmi.GetGridSpacing(gid, &spacing[0])
        return spacing

    cpdef get_grid_origin(self, gid, np.ndarray[double, ndim=1] origin):
        self._bmi.GetGridOrigin(gid, &origin[0])
        return origin

    cpdef get_grid_x(self, gid, np.ndarray[double, ndim=1] buff):
        self._bmi.GetGridX(gid, &buff[0])
        return buff

    cpdef get_grid_y(self, gid, np.ndarray[double, ndim=1] buff):
        self._bmi.GetGridY(gid, &buff[0])
        return buff

    cpdef get_grid_z(self, gid, np.ndarray[double, ndim=1] buff):
        self._bmi.GetGridZ(gid, &buff[0])
        return buff

    cpdef get_grid_face_nodes(self, gid, np.ndarray[int, ndim=1] buff):
        self._bmi.GetGridFaceNodes(gid, &buff[0])
        return buff

    cpdef get_grid_nodes_per_face(self, gid, np.ndarray[int, ndim=1] buff):
        self._bmi.GetGridNodesPerFace(gid, &buff[0])
        return buff

    cpdef get_grid_edge_nodes(self, gid, np.ndarray[int, ndim=1] buff):
        self._bmi.GetGridEdgeNodes(gid, &buff[0])
        return buff
