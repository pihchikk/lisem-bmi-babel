/*************************************************************************
**  openLISEM: a spatial surface water balance and soil erosion model
**  Copyright (C) 1992, 2003, 2016, 2024  Victor Jetten
**  contact: v.g.jetten AD utwente DOT nl
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License GPLv3 as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program. If not, see <http://www.gnu.org/licenses/>.
**
**  Authors: Victor Jetten, Bastian van de Bout, Meindert Commelin
**  Developed in: MingW/Qt/, GDAL, PCRaster
**  website, information and code: https://github.com/vjetten/openlisem
**
*************************************************************************/

/*!
\file TMmapVariables.h
\brief List of maps with descriptions and units. Linked directly in the model class.
*/

QVector <cTMap*> *inith = nullptr; // swatre matrix potential nodes

cTMap
*DEM = nullptr,                        //!< DEM [m]
*MBm = nullptr,
*ShadeBW = nullptr,                      //!< Shaded relief for display [0-1]
*DX = nullptr,                         //!< cell length divided by cosine slope (so corrected for terrain gradient) [m]
*CellArea = nullptr,                   //!< cell area = DX * _dx [m^2]
*Grad = nullptr,                       //!< sine of the DEM gradient [-]
*LDD = nullptr,                        //!< local drain direction map [-]
*Outlet = nullptr,                     //!< main outlet of the catchment, value 5 in LDD map [-]
*PointMap = nullptr,                   //!< map with output points, values > 0 [-]
*FlowBoundary = nullptr,               //!< map with open boundary fior diffusive runoff (1) or closed boundary (0)
*WaterSheds = nullptr,                 //!< map with numbered siubcatchments, must be 1,2,3 ... n
*QBoundFlow = nullptr,
*DomainEdge = nullptr,

*IDRainPoints = nullptr,                   //!< rainfall zone map (clasified map, numers corrspond to raingaug number in rainfall file) [-]
*RainZone = nullptr,                   //!< rainfall zone map (clasified map, numers corrspond to raingaug number in rainfall file) [-]
*ETZone = nullptr,                     //!< rainfall zone map (clasified map, numers corrspond to raingaug number in rainfall file) [-]
*Rain = nullptr,                       //!< map with rain from tis time intervall [m]
*Rainc = nullptr,                      //!< map with rain from tis time intervall, spread over the surface (corrected or slope) [m]
*RainCumInt = nullptr,                 //!< cumulative rainfall, as spreadoutover slope [m], needed for interception
*RainCumCrust = nullptr,               //!< cumulative rainfall, as spreadoutover slope [m], needed for crusting
*RainCumFlat = nullptr,                //!< cumulative rainfall [m]
*RainNet = nullptr,                    //!< net rainfall after interception [m]
*LeafDrain = nullptr,                  //!< drainge from canopy, storage overflow [m]
*CStor = nullptr,                      //!< actual canopy storage [m]
*Interc = nullptr,                     //!< actual canopy storage volume, corrected for surfaces without vegetation (like roads) [m^3]
*IntercETa = nullptr,                     //!< actual canopy storage volume, corrected for surfaces without vegetation (like roads) [m^3]
*LCStor = nullptr,                     //!< actual Litter storage [m]
*LInterc = nullptr,                    //!< actual Litter storage volume, corrected for surfaces without vegetation (like roads) [m^3]
*DStor = nullptr,                      //!< actual drum storage of rainwater [m^3]
*HStor = nullptr,                      //!< actual roof storage of rainwater [m]
*IntercHouse = nullptr,                //!< actual roof storage volume [m^3]
*HouseCover = nullptr,                 //!< fraction cover of house in pixel [-]
*RoofStore = nullptr,                  //!< Max storage of roof in [mm]
*DrumStore = nullptr,                  //!< Max storage of rainwter drums [m^3]
*InterceptionmmCum = nullptr,
*ETa = nullptr,
*ETaCum = nullptr,
*ETp = nullptr,
*ETpCum = nullptr,

*SnowmeltZone = nullptr,               //!< snowmelt zone map, values corrspond to snowmelt gauge numbers [-]
*Snowcover = nullptr,                  //!< snowmelt cover map, value 1.0 if there is snowcover, 0 without [-]
*Snowmelt = nullptr,                   //!< snowmelt depth in water equivalent [m]
*Snowmeltc = nullptr,                  //!< snowmelt depth in water equivalent, corrected for DEM gradient [m]
*SnowmeltCum = nullptr,                //!< cumulative showmelt depth [m]

*WH = nullptr,                         //!< water height on the surface [m]
//*WHold,                      //!< water height on the surface before infiltration [m]
//*WHnew,                      //!< water height on the surface before infiltration [m]
*WHrunoff = nullptr,                   //!< water height available for runoff [m]
*WHmax = nullptr,                      //!< max runoff wh in m for reporting
*WHstore = nullptr,                    //!< water heigth stored in micro depressions [m]
*MicroStoreVol = nullptr,
*WaterVolall = nullptr,                //!< water volume total (incl surface storage) [m^3]
*WaterVolin = nullptr,                 //!< water volume total before kin wave (after tochannel) [m^3]
//*flowmask,
//*WaterVolRunoff,                //!< water volume for runoff [m^3]

*FlowWidth = nullptr,                  //!< width of the flow overland, based on ponded area/roughness, +roads etc [m]
*V = nullptr,                          //!< velocity of overland flow [m/s]
*Alpha = nullptr,                      //!< alpha in A = alphaQ^b
*Q = nullptr,                          //!< discharge of overland flow before kin wave [m^3/s]
*DischargeUserPoints = nullptr,
*QuserIn = nullptr,
*WHbound = nullptr,
*WHboundarea = nullptr,
*WHboundRain = nullptr,
*Qbase = nullptr,
*GWVol = nullptr,
*GWWH = nullptr,
*GWU = nullptr,
*GWV = nullptr,
*GWN = nullptr,
*GWWHmax = nullptr,
*GWdeep = nullptr,
*GWrecharge = nullptr,
*GWout = nullptr,
*GWz = nullptr,
*GWgrad = nullptr,
*Qn = nullptr,                         //!< new discharge of overland flow after kin wave [m^3/s]
*Qdiag = nullptr,
*VH = nullptr,
*QinKW = nullptr,
*QKW = nullptr,
*Qm3total = nullptr,
*Qm3max = nullptr,
*FHI = nullptr,
*Qoutput = nullptr,                    //!< new discharge for output purposes, sum of overland flow and channel, converted [l/s]
*Qs = nullptr,                         //!< sediment discharge before kin wave [kg/s]
*Qsn = nullptr,                        //!< new sediment discharge after kin wave [kg/s]
*Qsoutput = nullptr,                   //!< sediment outflow for screen/file output, sum of overland flow and channel [kg/s]
//*q,                          //!< infiltration surplus going in kin wave (<= 0) [m2/s]
*R = nullptr,                          //!< hydraulic radius overland flow [m]
*N = nullptr,                          //!< Manning's n
*Norg = nullptr,                          //!< Manning's n
*RR = nullptr,                         //!< Random roughness, locally converted to m [cm]
*MDS = nullptr,                        //!< Maximum depression storage [m]
//*fpa,                        //!< fraction ponded area [-]
*SoilWidthDX = nullptr,                //!< width of soil surface, excluding roads and channels [m]
*RoadWidthDX = nullptr,                //!< width of tarred roads [m]
*RoadWidthHSDX = nullptr,
*StoneFraction = nullptr,              //!< fraction of stones on the surface, affects splash [-]
*CompactFraction = nullptr,            //!< fraction compacted at the surface, uses ksat compact [-]
*CrustFraction = nullptr,              //!< fraction crusted at the surface, uses ksat crust [-]
*CrustFraction0 = nullptr,              //!< fraction crusted at the surface, uses ksat crust [-]
//*RepellencyFraction,         //!< fraction of water repellency of node 1 in Swatre [-]
//*RepellencyCell,             //!< Cell included in water repellency in Swatre [-]
*HardSurface = nullptr,                //!< value 1 if 'hard' surface: no interception, infiltration, detachment [-]
*fractionImperm = nullptr,            //!<// 0 is fully permeable, 1 = impermeable [-]
*runoffTotalCell = nullptr,
*hSwatre = nullptr,
*thetaSwatre = nullptr,

*PlantHeight = nullptr,                //!< height of vegetation/crops [m]
*Cover = nullptr,                      //!< vegetation canopy cover fraction [-]
*Litter = nullptr,                     //!< vegetation litter cover fraction [-]
*CanopyStorage = nullptr,              //!< canopy storage [m]
*LAI = nullptr,                        //!< leaf area index [m^2/m^2]
*LandUnit = nullptr,                   //!< land unit class (> 0) [-]

*Cohesion = nullptr,                   //!< total cohesion of the soil surface: coh soil *(1-cover) + coh plant (cover) [kPa]
*RootCohesion = nullptr,               //!< cohesion soil [kPa]
*CohesionSoil = nullptr,               //!< cohesion by plant roots [kPa]
*Y = nullptr,                          //!< erosion efficiency 0-1, basd on cohesion [-]
*AggrStab = nullptr,                   //!< aggregate stability, median of drops in lowe test [-]
*SplashStrength = nullptr,                   //!< aggregate stability, median of drops in lowe test [-]
//*splashb,                   //!< aggregate stability, median of drops in lowe test [-]
*D50 = nullptr,                        //!< median of grainsize distribution [mu]
*D90 = nullptr,                        //!< 90 % of grainsize distribution is below this value [mu]
*D50CH = nullptr,                        //!< median of grainsize distribution [mu]
*D90CH = nullptr,                        //!< 90 % of grainsize distribution is below this value [mu]
*cgovers = nullptr,
*dgovers = nullptr,
*DETSplash = nullptr,                  //!< splash detachment [kg/cell]
*DETSplashCum = nullptr,
*DETFlow = nullptr,                    //!< flow detachment [kg/cell]
*DETFlowCum = nullptr,
*DEPCum = nullptr,
*DEP = nullptr,                        //!< deposition [kg/cell]
*TC = nullptr,                         //!< transport capacity [kg/m^3]
*Conc = nullptr,                       //!< sediment concentration in flow [kg/m^3]
*Sed = nullptr,                        //!< sediment content of flow [kg]
*SettlingVelocitySS = nullptr,           //!< settling velocity according to Stokes [m/s]
*SettlingVelocityBL = nullptr,           //!< settling velocity according to Stokes [m/s]

// infiltration
*Fcum = nullptr,                       //!< cumulative infiltration [m]
//*FSurplus,                   //!< surplus infiltration for kinematic wave, calculated as actual infil - potential infil [m]
//*fact,                       //!< actual infiltration rate [m/s]
//*fpot,                       //!< potential infiltration rate [m/s]
//*InfilVolKinWave,            //!< volume infiltrated in the kin wave (slope and channel) in this timestep [m^3]
*InfilVol = nullptr,                   //!< volume of water infiltrated in this timestep [m^3]
*ChannelInfilVol = nullptr,                   //!< volume of water infiltrated in this timestep [m^3]

*InfilVolCum = nullptr,                //!< cumulative infiltration volume for mass balance and map report [m^3]
*InfilmmCum = nullptr,                 //!< cumulative infiltration volume for map report and drawing [mm]
*InfilVolFlood = nullptr,

*Lw = nullptr,
*Lwmm = nullptr,

*ThetaS1 = nullptr,                    //!< porosity soil layer 1 [-]
*ThetaI1 = nullptr,                    //!< initial moisture content soil layer 1 [-]
*ThetaI1a = nullptr,                    //!< initial moisture content soil layer 1 [-]
*Psi1 = nullptr,                       //!< intial suction head wetting front soil layer 1 (input map is in cm) [m]
*ThetaR1 = nullptr,
*ThetaFC1 = nullptr,
*Ksat1 = nullptr,                      //!< saturated hydraulic conductivity soil layer 1 (input is in mm/h) [m/s]
*SoilDepth1 = nullptr,                 //!< depth to end soil layer 1 (input is in mm) [m]
*SoilDepth1init = nullptr,                 //!< depth to end soil layer 1 (input is in mm) [m]

*ThetaS2 = nullptr,                    //!< porosity soil layer 2 [-]
*ThetaI2 = nullptr,                    //!< initial moisture content soil layer 2 [-]
*ThetaI2a = nullptr,                    //!< initial moisture content soil layer 2 [-]
*ThetaR2 = nullptr,
*ThetaFC2 = nullptr,
*Psi2 = nullptr,                       //!< intial suction head wetting front soil layer 2 (input map is in cm) [m]
*Ksat2 = nullptr,                      //!< saturated hydraulic conductivity soil layer 2 (input is in mm/h) [m/s]
*SoilDepth2 = nullptr,                 //!< depth to end soil layer 2 (input is in mm) [m]
*SoilDepth2init = nullptr,                 //!< depth to end soil layer 2 (input is in mm) [m]

*ThetaS3 = nullptr,                    //!< porosity soil layer 1 [-]
*ThetaI3 = nullptr,                    //!< initial moisture content soil layer 1 [-]
*ThetaI3a = nullptr,                    //!< initial moisture content soil layer 1 [-]
*Psi3 = nullptr,                       //!< intial suction head wetting front soil layer 1 (input map is in cm) [m]
*ThetaR3 = nullptr,
*ThetaFC3 = nullptr,
*Ksat3 = nullptr,                      //!< saturated hydraulic conductivity soil layer 1 (input is in mm/h) [m/s]
*SoilDepth3 = nullptr,                 //!< depth to end soil layer 1 (input is in mm) [m]
*SoilDepth3init = nullptr,                 //!< depth to end soil layer 1 (input is in mm) [m]

*lambda1 = nullptr,
*lambda2 = nullptr,
*lambda3 = nullptr,
*vgalpha1 = nullptr,
*vgalpha2 = nullptr,
*vgalpha3 = nullptr,
*vgn1 = nullptr,
*vgn2 = nullptr,
*vgn3 = nullptr,
*psi1ae = nullptr,
*psi2ae = nullptr,
*psi3ae = nullptr,

*KsatCrust = nullptr,                  //!< saturated hydraulic conductivity crusted soil surface (input is in mm/h) [m/s]
*PoreCrust = nullptr,                //!< saturated hydraulic conductivity compacted soil surface (input is in mm/h) [m/s]
*KsatCompact = nullptr,                //!< saturated hydraulic conductivity compacted soil surface (input is in mm/h) [m/s]
*PoreCompact = nullptr,                //!< saturated hydraulic conductivity compacted soil surface (input is in mm/h) [m/s]
*KsatGrass = nullptr,                  //!< saturated hydraulic conductivity grass strip (input is in mm/h) [m/s]
*PoreGrass = nullptr,                  //!< Porosity grass strip (input in cm3/cm3)
*CohGrass = nullptr,                   //!< Cohesion grass strip (input in kPa)
*Ksateff = nullptr,                    //!< effective saturated hydraulic conductivity (input is in mm/h) [m/s]
*Poreeff = nullptr,
*Thetaeff = nullptr,
*chanmask3 = nullptr,

*Perc = nullptr,
*PercmmCum = nullptr,
*GrassFraction = nullptr,              //!< fraction of grasstrip in a cell [-]
*SedimentFilter = nullptr,             //!< sediment deposited in the sediment trap in kg/m2
*SedMaxVolume = nullptr,               //!< maxvol of sediment in that can be trapped in m3
*GrassWidthDX = nullptr,               //!< width of grasstrip in [m]

//swatre
*OMcorr = nullptr,
*DensFact = nullptr,
*ProfileID = nullptr,                  //!< SWATRE profile unit number map
*ProfileIDCrust = nullptr,             //!< SWATRE profile unit number map for crusted areas
*ProfileIDCompact = nullptr,           //!< SWATRE profile unit number map for compacted areas
*ProfileIDGrass = nullptr,             //!< SWATRE profile unit number map for grass strips
*SwatreOutput = nullptr,               //!< SWATRE cells flagged for output
//*inith,                      //!< SWATRE inithead in -cm

*LDDChannel = nullptr,                 //!<
*LDDbaseflow = nullptr,
*ChannelWidthO = nullptr,               //!<
*ChannelWidth = nullptr,               //!<
*ChannelDepth = nullptr,               //!<
*ChannelSide = nullptr,                //!<
*ChannelQSide = nullptr,                //!<
//*ChannelQb,                   //!<
*ChannelQ = nullptr,                   //!<
*ChannelQn = nullptr,                  //!<
*ChannelQntot = nullptr,
*ChannelQs = nullptr,                  //!<
*ChannelQsn = nullptr,                 //!<
*ChannelQBLs = nullptr,                  //!<
*ChannelQBLsn = nullptr,                 //!<
*ChannelQSSs = nullptr,                  //!<
*ChannelQSSsn = nullptr,                 //!<
*ChannelGrad = nullptr,                //!<
*ChannelV = nullptr,                   //!<
*ChannelN = nullptr,                   //!<
*ChannelWH = nullptr,                  //!<
*ChannelPerimeter = nullptr,
*ChannelWidthB = nullptr,
//*ChannelCos,
//*ChannelWHExtended,                  //!<
//*ChannelVolExtended,                  //!<
*ChannelWaterVol = nullptr,            //!<
//*Channelq,                   //!<
*ChannelAlpha = nullptr,               //!<
*ChannelDX = nullptr,                  //!<
*ChannelKsat = nullptr,                //!<
*ChannelInfM3 = nullptr,                //!<

*ChannelAdj = nullptr,                //!<
*CHAdjDX = nullptr,                //!<
*BaseflowL = nullptr,

*cosGrad = nullptr,
*tanGrad = nullptr,
*BulkDensity = nullptr,
*AngleFriction = nullptr,
*FSlope = nullptr,

// channel erosion
//*ChannelPerimeter,           //!<
*ChannelDetFlow = nullptr,             //!<
*ChannelDep = nullptr,                 //!<
//*ChannelSed,                 //!<
*ChannelBLSed = nullptr,                 //!<
*ChannelSSSed = nullptr,                 //!<
*ChannelBLTC = nullptr,                 //!<
*ChannelSSTC = nullptr,                 //!<
*ChannelBLDepth = nullptr,                 //!<
*ChannelSSDepth = nullptr,                 //!<
*ChannelConc = nullptr,                //!<
*ChannelBLConc = nullptr,                //!<
*ChannelSSConc = nullptr,                //!<
*ChannelTC = nullptr,                  //!<
*ChannelCohesion = nullptr,            //!<
*ChannelY = nullptr,                   //!<
*ChannelPAngle = nullptr,               //!<
*ChannelQsr = nullptr,

//baseflow
*BaseFlowDischarges = nullptr,
*BaseFlowInitialVolume = nullptr,
*BaseFlowInflow = nullptr,

// flood maps
*floodHmxMax = nullptr,                    //!<
*floodTime = nullptr,                    //!<
*floodTimeStart = nullptr,                //!<
*floodVMax = nullptr,                    //!<
*floodVHMax = nullptr,                    //!<
*maxChannelflow = nullptr,                    //!<
*maxChannelWH = nullptr,                    //!<
*hmx = nullptr,                        //!<
*hmxWH = nullptr,                        //!<
*hmxrunoff = nullptr,
*hmxInit = nullptr,                    //!<
*FloodDomain = nullptr,                //!<
*Buffers = nullptr,                    //!<
*GridRetention = nullptr,                    //!<
*GridRetentionAct = nullptr,
*ChanRetention = nullptr,                    //!<
*ChanRetentionAct = nullptr,
*ChannelDiameter = nullptr,                //!<
*ChannelCulvert = nullptr,                //!<
*ChannelMaxQ = nullptr,                //!<
*ChannelMaxAlpha = nullptr,                //!<
*ChannelMaxArea = nullptr,
*FloodWaterVol = nullptr,                //!<
*RunoffWaterVol = nullptr,                //!<

//*FloodZonePotential,                //!<
*FloodDT = nullptr,
*Uflood = nullptr,*Vflood = nullptr,
*hs = nullptr, //*vs, *us,
*gflowx = nullptr,
*gflowy = nullptr,
*hllx12_0 = nullptr,
*hlly12_0 = nullptr,
*hllx21_1 = nullptr,
*hllx21_2 = nullptr,
*hlly21_1 = nullptr,
*hlly21_2 = nullptr,


//FULLSWOF2D with Sediment
*BLDepthFlood = nullptr,
*SSDepthFlood = nullptr,
*BLDetFlood = nullptr,
*BLTCFlood = nullptr,
*SSTCFlood = nullptr,
*SSDetFlood = nullptr,
*DepFlood = nullptr,
*BLCFlood = nullptr,
*BLFlood = nullptr,
*SSCFlood = nullptr,
*SSFlood = nullptr,

*LDDTile = nullptr,                    //!< LDD network of tile drains, must be connected to outlet
*TileDrainSoil = nullptr,              //!< drain volume from layer
*TileDiameter = nullptr,                  //!< total width of drains in cell (m)
*TileArea = nullptr,                  //!< total width of drains in cell (m)
*TileWidth = nullptr,                  //!< total width of drains in cell (m)
*TileHeight = nullptr,                 //!< height of drain (m)
*TileDepth = nullptr,                  //!< depth of tiles in soil below surface (m)
//*TileInlet,               //!< sinkhole on surface connecting to tiledrains (m2)
*TileQ = nullptr,                      //!< water flux in drains m3/s
*TileMaxQ = nullptr,                      //!< water flux in drains m3/s
*TileQn = nullptr,                     //!< new water flux in drains m3/s
*TileGrad = nullptr,                   //!< gradient of the tiledrain system
*TileN = nullptr,                      //!< mannings inside the tiledrains
*TileWaterVol = nullptr,               //!< water volume in the tiledrains (m3)
*TileWaterVolSoil = nullptr,           //!< water volume in the tiledrains from the soil only, used for mass bal corection (m3)
*RunoffVolinToTile = nullptr,          //!< can be used for shortcut of surface pits to tile system
*TileAlpha = nullptr,                  //!< alpha in tile drain, in A = alpha*Q^beta
*TileMaxAlpha = nullptr,                      //!< water flux in drains m3/s

*TotalChanDetMap = nullptr,                //!<
*TotalChanDepMap = nullptr,                //!<
*TotalSoillossMap = nullptr,           //!<
*TotalSed = nullptr,                   //!<
*TotalConc = nullptr,                  //!<

*tm = nullptr,                         //!< Auxilary map
*tma = nullptr,                        //!< Auxilary map
*tmb = nullptr,                        //!< Auxilary map
*tmc = nullptr,                        //!< Auxilary map
*tmd = nullptr,                        //!< Auxilary map
*tmshow = nullptr,
//display combinations
*COMBO_V = nullptr,
*COMBO_SS = nullptr,
*COMBO_BL = nullptr,
*COMBO_TC = nullptr,
*ChannelDepthExtended = nullptr,
*ChannelWidthExtended = nullptr,
*ChannelNeighborsExtended = nullptr,
*ChannelSourceXExtended = nullptr,
*ChannelSourceYExtended = nullptr,
*ChannelMaskExtended = nullptr,
*ChannelBoundaryExtended = nullptr,
*ChannelBoundaryLExtended = nullptr,
*ChannelBoundaryRExtended = nullptr,

*FlowBarrier = nullptr,                //!< Flow barriers type
*FlowBarrierN = nullptr,               //!< Flow barriers height North of cell
*FlowBarrierW = nullptr,               //!< Flow barriers height West of cell
*FlowBarrierS = nullptr,               //!< Flow barriers height South of cell
*FlowBarrierE = nullptr,               //!< Flow barriers height East of cell
*FlowBarrierNT = nullptr,              //!< Flow barriers end timing North of cell
*FlowBarrierWT = nullptr,              //!< Flow barriers end timing West of cell
*FlowBarrierST = nullptr,              //!< Flow barriers end timing South of cell
*FlowBarrierET = nullptr               //!< Flow barriers end timing East of cell

;

cTRGBMap * RGB_Image = nullptr;
