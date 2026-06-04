/********************************************************************************
** Form generated from reading UI file 'lisemqt.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISEMQT_H
#define UI_LISEMQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lisemqtClass
{
public:
    QAction *action_Open_runfile;
    QAction *action_Save_runfuile;
    QWidget *centralwidget;
    QGridLayout *gridLayout_83;
    QTabWidget *tabWidget;
    QWidget *tab_input;
    QGridLayout *gridLayout_23;
    QGroupBox *groupBoxOutput;
    QGridLayout *gridLayout_64;
    QGroupBox *outputGraphsTables;
    QGridLayout *gridLayout_34;
    QLabel *label_22;
    QLineEdit *E_MainTotals;
    QLabel *label_110;
    QLineEdit *E_SeriesTotals;
    QLabel *label_20;
    QLineEdit *E_PointResults;
    QCheckBox *checksatImage;
    QLineEdit *E_satImageName;
    QToolButton *toolButton_satImageName;
    QLabel *label_128;
    QGroupBox *groupBoxunits;
    QGridLayout *gridLayout_55;
    QSpinBox *E_DigitsOut;
    QFrame *frame;
    QGridLayout *gridLayout_42;
    QRadioButton *checkUnits_ls;
    QRadioButton *checkUnits_m3s;
    QFrame *frame_2;
    QGridLayout *gridLayout_32;
    QRadioButton *checkUnits_tonha;
    QRadioButton *checkUnits_kgcell;
    QRadioButton *checkUnits_kgm2;
    QLabel *label_125;
    QLabel *label_12;
    QCheckBox *checkWritePCRaster;
    QLabel *label_81;
    QDoubleSpinBox *E_floodMinHeight;
    QLabel *label_198;
    QSpacerItem *horizontalSpacer_6;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_39;
    QTabWidget *tabWidget_OutputMaps;
    QWidget *tab;
    QGridLayout *gridLayout_25;
    QCheckBox *checkEndRunReport;
    QLabel *label_131;
    QGroupBox *outputMapsSediment;
    QGridLayout *gridLayout_4;
    QLabel *label_19;
    QLineEdit *E_ChanDetachmentMap;
    QLabel *label_17;
    QLineEdit *E_SoillossMap;
    QLineEdit *E_DetachmentMap;
    QLineEdit *E_DepositionMap;
    QLabel *label_180;
    QLabel *label_18;
    QLineEdit *E_ChanDepositionMap;
    QLabel *label_179;
    QCheckBox *checkFormatGtiff;
    QGroupBox *outputMapsFlood;
    QGridLayout *gridLayout_74;
    QLabel *label_120;
    QLabel *label_122;
    QLabel *label_112;
    QLineEdit *E_stormDrainVolMap;
    QLineEdit *E_FloodStats;
    QLineEdit *E_ChannelQtotm3Map;
    QLabel *label_111;
    QLineEdit *E_ChannelMaxWH;
    QLineEdit *E_FloodTimeMap;
    QLineEdit *E_FloodFEW;
    QLabel *label_119;
    QLabel *label_79;
    QLineEdit *E_stormDrainMap;
    QLabel *label_93;
    QLineEdit *E_ChannelMaxQ;
    QLabel *label_103;
    QGroupBox *outputMapsWater;
    QGridLayout *gridLayout_73;
    QLabel *label_114;
    QLineEdit *E_InfiltrationMap;
    QLabel *label_74;
    QLabel *label_138;
    QLineEdit *E_RainfallMap;
    QLineEdit *E_RunoffMap;
    QLabel *label_116;
    QLabel *label_117;
    QLineEdit *E_WHmaxMap;
    QLineEdit *E_FloodmaxVMap;
    QLabel *label_115;
    QLabel *label_136;
    QLineEdit *E_FloodmaxVHMap;
    QLineEdit *E_InterceptionMap;
    QSpacerItem *verticalSpacer_10;
    QWidget *tab_4;
    QGridLayout *gridLayout_36;
    QFrame *mapsout;
    QGridLayout *gridLayout_63;
    QGroupBox *groupWatermapseriesout;
    QGridLayout *gridLayout_61;
    QCheckBox *checkBox_OutSurfStor;
    QCheckBox *checkBox_OutTiledrain;
    QCheckBox *checkBox_OutWH;
    QCheckBox *checkBox_OutInf;
    QCheckBox *checkBox_OutTheta;
    QCheckBox *checkBox_OutV;
    QCheckBox *checkBox_OutInterception;
    QCheckBox *checkBox_OutTileVol;
    QCheckBox *checkBox_OutRunoff;
    QCheckBox *checkBox_OutGW;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupSedMapseriesout;
    QGridLayout *gridLayout_35;
    QCheckBox *checkBox_OutDet;
    QCheckBox *checkBox_OutDep;
    QCheckBox *checkBox_OutSL;
    QCheckBox *checkBox_OutConc;
    QCheckBox *checkBox_OutTC;
    QCheckBox *checkBox_OutSed;
    QCheckBox *checkBox_OutSedSS;
    QCheckBox *checkBox_OutSedBL;
    QCheckBox *checkWritePCRnames;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_9;
    QGridLayout *gridLayout_33;
    QLabel *label_80;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *printinterval;
    QCheckBox *checkReportMapsEnd;
    QGroupBox *groupBoxInput;
    QGridLayout *gridLayout_37;
    QGroupBox *groupBoxTime;
    QGridLayout *gridLayout_43;
    QLineEdit *E_Timestep;
    QLabel *label_6;
    QLineEdit *E_EndTimeDay;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *E_BeginTimeDay;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_54;
    QTabWidget *tabWidgetOptions;
    QWidget *tab_general;
    QGridLayout *gridLayout_38;
    QGroupBox *groupBox_8;
    QFormLayout *formLayout;
    QCheckBox *checkDoErosion;
    QGroupBox *groupSurfaceflow;
    QGridLayout *gridLayout_8;
    QComboBox *E_OFWaveType;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_80;
    QCheckBox *checkInfiltration;
    QGroupBox *groupChannels;
    QGridLayout *gridLayout_17;
    QCheckBox *checkIncludeChannel;
    QCheckBox *checkGWflow;
    QLabel *label_55;
    QToolButton *toolButton_resetOptions;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupInfrastructrure;
    QGridLayout *gridLayout_51;
    QCheckBox *checkInfrastructure;
    QCheckBox *checkConservation;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton_helpOptions;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_81;
    QCheckBox *checkRainfall;
    QCheckBox *checkET;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_71;
    QCheckBox *checkInterception;
    QWidget *tab_meteo;
    QGridLayout *gridLayout_77;
    QLabel *label_49;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupET;
    QGridLayout *gridLayout_60;
    QLabel *label_5;
    QDoubleSpinBox *E_biasCorrectionET;
    QSpinBox *E_dayoftheYear;
    QLabel *label_57;
    QCheckBox *checkDailyET;
    QLabel *label_63;
    QDoubleSpinBox *E_rainfallETA_threshold;
    QLineEdit *E_latitude;
    QLabel *label_126;
    QGridLayout *gridLayout_47;
    QRadioButton *radioETfile;
    QLineEdit *E_ETName;
    QToolButton *toolButton_ETName;
    QToolButton *toolButton_ETShow;
    QRadioButton *radioETSatfile;
    QLineEdit *E_ETsatName;
    QToolButton *toolButton_ETsatName;
    QToolButton *toolButton_ETmapShow;
    QLineEdit *E_longtimestep;
    QLabel *label_118;
    QToolButton *toolButton_helpRainfall;
    QGroupBox *groupRainfall;
    QGridLayout *gridLayout_50;
    QCheckBox *checkEventBased;
    QLabel *label_98;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioRainFile;
    QLineEdit *E_RainfallName;
    QToolButton *toolButton_RainfallName;
    QToolButton *toolButton_RainfallShow;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_149;
    QCheckBox *checkIDinterpolation;
    QDoubleSpinBox *E_IDIfactor;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *radioRainSatFile;
    QLineEdit *E_RainsatName;
    QToolButton *toolButton_rainsatName;
    QToolButton *toolButton_RainmapShow;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_121;
    QDoubleSpinBox *E_biasCorrectionP;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QToolButton *toolButton_resetRainfall;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tab_interc;
    QGridLayout *gridLayout_58;
    QGroupBox *groupInterception;
    QGridLayout *gridLayout_5;
    QCheckBox *checkIncludeLitter;
    QLabel *label_133;
    QGroupBox *groupCanopyStrorage;
    QGridLayout *gridLayout_28;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QFrame *line_2;
    QRadioButton *radioButton_9;
    QDoubleSpinBox *E_LitterSmax;
    QToolButton *toolButton_resetInterception;
    QToolButton *toolButton_helpInterception;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_infil;
    QGridLayout *gridLayout_57;
    QToolButton *toolButton_helpInfiltration;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupInfiltration;
    QGridLayout *gridLayout_52;
    QGroupBox *groupBox_InfilOptions;
    QGridLayout *gridLayout_2;
    QCheckBox *checkInfilImpermeable;
    QSpinBox *spinSoilLayers;
    QCheckBox *checkDynamicCrusting;
    QCheckBox *checkIncludeTiledrains;
    QCheckBox *checkInfilCompact;
    QLabel *label_153;
    QCheckBox *checkInfilCrust;
    QGroupBox *groupBox_SwatreOptions;
    QGridLayout *gridLayout;
    QLabel *label_159;
    QCheckBox *checkInfilHinit;
    QCheckBox *checkSwatreOutput;
    QDoubleSpinBox *E_SWATREDtsec;
    QDoubleSpinBox *spinHinit;
    QCheckBox *checkSwatreDry;
    QLabel *label_86;
    QLineEdit *E_SwatreTableName;
    QToolButton *toolButton_SwatreTableDir;
    QSpacerItem *horizontalSpacer_10;
    QToolButton *toolButton_SwatreTableName;
    QLabel *label_13;
    QLineEdit *E_SwatreTableDir;
    QToolButton *toolButton_SwatreTableShow;
    QSpinBox *spinSwatrePrecision;
    QLabel *label_144;
    QComboBox *E_InfiltrationMethod;
    QToolButton *toolButton_resetInfiltration;
    QSpacerItem *horizontalSpacer_11;
    QWidget *tab_flooding;
    QGridLayout *gridLayout_40;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_27;
    QGroupBox *groupFloodParams;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *E_courantFactor;
    QLabel *label_197;
    QDoubleSpinBox *E_TimestepMinFlood;
    QLabel *label_84;
    QCheckBox *checkMUSCL;
    QSpinBox *E_FlowBoundary;
    QLabel *label_96;
    QGroupBox *groupWaveUser;
    QGridLayout *gridLayout_72;
    QToolButton *toolButton_WaveInName;
    QLineEdit *E_WaveInName;
    QLabel *label_148;
    QToolButton *toolButton_WaveShow;
    QCheckBox *checkFloodInitial;
    QCheckBox *checkWaterUserIn;
    QToolButton *toolButton_resetFlow;
    QLabel *label_88;
    QToolButton *toolButton_helpFlow;
    QWidget *tab_Channel;
    QGridLayout *gridLayout_67;
    QToolButton *toolButton_resetChannel;
    QGroupBox *groupBaseflowParams;
    QGridLayout *gridLayout_66;
    QLabel *label_127;
    QLabel *label_155;
    QWidget *widget_GWparams;
    QGridLayout *gridLayout_eros;
    QLabel *label_102;
    QDoubleSpinBox *GW_threshold;
    QLabel *label_108;
    QDoubleSpinBox *GW_deep;
    QDoubleSpinBox *GW_flow;
    QLabel *label_97;
    QLabel *label_77;
    QDoubleSpinBox *GW_recharge;
    QLabel *label_83;
    QLabel *label_106;
    QWidget *GW_widget;
    QGridLayout *gridLayout_24;
    QRadioButton *checkGWflowLDD;
    QRadioButton *checkGWflowSWAT;
    QRadioButton *checkGWflowexplicit;
    QSpacerItem *horizontalSpacer_28;
    QLabel *label_156;
    QGroupBox *groupChannelParams;
    QGridLayout *gridLayout_78;
    QToolButton *toolButton_DischargeShow;
    QCheckBox *checkChannelCulverts;
    QLineEdit *E_DischargeInName;
    QDoubleSpinBox *E_CalibrateChTor;
    QCheckBox *checkDischargeUser;
    QToolButton *toolButton_DischargeName;
    QLabel *label_87;
    QComboBox *E_BaseflowMethod;
    QSpacerItem *verticalSpacer_16;
    QToolButton *toolButton_helpChannel;
    QWidget *tab_Infra;
    QGridLayout *gridLayout_79;
    QToolButton *toolButton_helpInfra;
    QToolButton *toolButton_resetInfra;
    QGroupBox *groupMitigationWater;
    QGridLayout *gridLayout_70;
    QCheckBox *checkFlowBarriers;
    QDoubleSpinBox *E_GrassStripN;
    QLineEdit *line_FlowBarriers;
    QCheckBox *checkGridRentention;
    QCheckBox *checkBuffers;
    QLabel *label_15;
    QCheckBox *checkInfilGrass;
    QGroupBox *groupConservationSed;
    QGridLayout *gridLayout_11;
    QCheckBox *checkSedtrap;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_191;
    QLabel *label_104;
    QDoubleSpinBox *E_SedTrapN;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_189;
    QLabel *label_33;
    QDoubleSpinBox *E_BulkDens;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_12;
    QWidget *widgetInfra;
    QGridLayout *gridLayout_84;
    QFrame *tilebox;
    QGridLayout *gridLayout_22;
    QCheckBox *checkDrainNoOutflow;
    QRadioButton *checkStormDrainCirc;
    QRadioButton *checkStormDrainRect;
    QLabel *label_147;
    QDoubleSpinBox *E_TileInletSize;
    QSpinBox *E_TileInletDistance;
    QLabel *label_14;
    QCheckBox *checkStormDrains;
    QLabel *label_166;
    QCheckBox *checkRoadsystem;
    QCheckBox *checkHouses;
    QGridLayout *gridLayout_30;
    QCheckBox *checkAddBuildingDEM;
    QDoubleSpinBox *E_buildingHeight;
    QCheckBox *checkRaindrum;
    QLabel *label_78;
    QLabel *label_145;
    QDoubleSpinBox *E_AddBuildingFraction;
    QLabel *label_140;
    QCheckBox *checkHardsurface;
    QLabel *label_89;
    QSpacerItem *horizontalSpacer_9;
    QWidget *tab_erosion;
    QGridLayout *gridLayout_82;
    QSpacerItem *verticalSpacer_18;
    QToolButton *toolButton_resetErosion;
    QWidget *widgetErosion;
    QGridLayout *gridLayout_41;
    QLabel *label_143;
    QGroupBox *groupSed;
    QGridLayout *gridLayout_21;
    QCheckBox *checkDiffusion;
    QLabel *label_91;
    QLabel *label_109;
    QComboBox *E_EfficiencyDET;
    QComboBox *E_SSMethod;
    QGroupBox *groupKinEnergy;
    QGridLayout *gridLayout_44;
    QDoubleSpinBox *spinKEparameterC1;
    QDoubleSpinBox *spinKEparameterB1;
    QDoubleSpinBox *spinKEparameterA3;
    QLabel *label_67;
    QLabel *label_65;
    QLabel *label_66;
    QLabel *label_72;
    QLabel *label_71;
    QLabel *label_58;
    QLabel *label_73;
    QRadioButton *radioButtonKE1;
    QDoubleSpinBox *spinKEparameterB3;
    QDoubleSpinBox *spinKEparameterB2;
    QLabel *label_70;
    QDoubleSpinBox *spinKEparameterA2;
    QRadioButton *radioButtonKE2;
    QDoubleSpinBox *spinKEparameterA1;
    QRadioButton *radioButtonKE3;
    QSpinBox *E_splashEquation;
    QLabel *label_141;
    QLabel *label_142;
    QDoubleSpinBox *E_SplashDelibery;
    QLabel *label_9;
    QLabel *label_10;
    QGroupBox *groupSedCH;
    QGridLayout *gridLayout_26;
    QDoubleSpinBox *E_EfficiencyDirect;
    QLabel *label_4;
    QLabel *label_11;
    QCheckBox *checkDiffusionCH;
    QComboBox *E_EfficiencyDETCH;
    QCheckBox *checkSed2Phase;
    QDoubleSpinBox *E_TurbulenceFactor;
    QLabel *label_157;
    QLabel *label_165;
    QComboBox *E_RSSMethod;
    QComboBox *E_RBLMethod;
    QComboBox *E_settlingVelocity;
    QSpacerItem *verticalSpacer_11;
    QSpacerItem *horizontalSpacer_12;
    QToolButton *toolButton_helpErosion;
    QWidget *tab_calib;
    QGridLayout *gridLayout_20;
    QLabel *label_59;
    QToolButton *toolButton_resetCalibration;
    QToolButton *toolButton_helpCalibration;
    QSpacerItem *horizontalSpacer_20;
    QGroupBox *groupCalFlow;
    QGridLayout *gridLayout_29;
    QDoubleSpinBox *E_CalibrateChN;
    QDoubleSpinBox *E_CalibrateWave;
    QLabel *label_150;
    QDoubleSpinBox *E_CalibrateN;
    QLabel *label_134;
    QDoubleSpinBox *E_CalibrateCulvert;
    QDoubleSpinBox *E_CalibrateChKsat;
    QLabel *label_calchn;
    QLabel *label_calchks;
    QLabel *label_calN;
    QLabel *label_62;
    QGroupBox *groupCalErosion;
    QGridLayout *gridLayout_69;
    QDoubleSpinBox *E_CalibrateD50;
    QDoubleSpinBox *E_CalibrateCOH;
    QLabel *label_calchcoh;
    QLabel *label_cald50;
    QLabel *label_calcoh;
    QDoubleSpinBox *E_CalibrateD90;
    QDoubleSpinBox *E_CalibrateCHCOH;
    QLabel *label_69;
    QLabel *label_calas;
    QDoubleSpinBox *E_CalibrateAS;
    QSpacerItem *verticalSpacer_14;
    QLabel *label_68;
    QGroupBox *groupCalHydrology;
    QGridLayout *gridLayout_19;
    QDoubleSpinBox *E_CalibrateSmax;
    QDoubleSpinBox *E_CalibrateKsat;
    QDoubleSpinBox *E_CalibrateTheta;
    QLabel *label_146;
    QDoubleSpinBox *E_CalibrateRR;
    QDoubleSpinBox *E_CalibratePsi;
    QLabel *label_calKsat2;
    QLabel *label_76;
    QLabel *label_calKsat;
    QLabel *label_calth;
    QLabel *label_calpsi;
    QDoubleSpinBox *E_CalibrateKsat2;
    QDoubleSpinBox *E_CalibrateKsat3;
    QLabel *label_calKsat3;
    QWidget *tab_advanced;
    QGridLayout *gridLayout_76;
    QCheckBox *checkAdvancedOptions;
    QFrame *groupAdvanced;
    QGridLayout *gridLayout_68;
    QGroupBox *groupAdvRichards;
    QGridLayout *gridLayout_65;
    QComboBox *comboBox_Kmean;
    QLabel *label_158;
    QCheckBox *checkPsiUser;
    QDoubleSpinBox *spinTileSuction;
    QLabel *label_164;
    QCheckBox *checkMB_WH;
    QCheckBox *checkInfilOMcorrection;
    QCheckBox *checkInfilDensfactor;
    QToolButton *toolButton_version;
    QSpacerItem *horizontalSpacer_22;
    QToolButton *toolButton_helpAdvanced;
    QGroupBox *groupAdvKinwave;
    QGridLayout *gridLayout_48;
    QCheckBox *checkPerimeterKW;
    QGroupBox *groupAdvChannel;
    QGridLayout *gridLayout_6;
    QCheckBox *checkChanMaxVelocity;
    QCheckBox *checkChannel2DflowConnect;
    QDoubleSpinBox *E_chanMaxVelocity;
    QToolButton *toolButton_resetAdvanced;
    QSpacerItem *horizontalSpacer_16;
    QGroupBox *groupAdvSWOF;
    QGridLayout *gridLayout_53;
    QSpinBox *E_FloodMaxIter;
    QLabel *label_199;
    QCheckBox *check2DDiagonalFlow;
    QCheckBox *checkCorrectDem;
    QDoubleSpinBox *E_pitValue;
    QLabel *label_123;
    QSpinBox *E_FloodReconstruction;
    QCheckBox *checkTimeavgV;
    QLabel *label_135;
    QCheckBox *checkErosionLoop;
    QLabel *label_161;
    QLineEdit *E_minWHVSWOF;
    QSpinBox *nrUserCores;
    QSpacerItem *horizontalSpacer_19;
    QCheckBox *checkNewversionGITHUB;
    QLabel *label_56;
    QSpacerItem *verticalSpacer_13;
    QWidget *tab_spare;
    QDoubleSpinBox *E_courantFactorSed;
    QRadioButton *checkGWflowSWOF;
    QComboBox *E_BLMethod;
    QDoubleSpinBox *E_CalibrateCHSV;
    QDoubleSpinBox *E_CalibrateSD1;
    QLineEdit *E_BulkDens2;
    QLabel *label;
    QSpinBox *E_FloodFluxLimiter;
    QLabel *label_130;
    QGroupBox *groupBox_RichardsOptions;
    QGridLayout *gridLayout_75;
    QLabel *label_152;
    QSpinBox *spinNodes2;
    QLabel *label_154;
    QSpinBox *spinNodes3;
    QLabel *label_151;
    QSpinBox *spinNodes1;
    QSpinBox *spinSoilPhysics;
    QLabel *label_132;
    QCheckBox *checkChannelWFinflow;
    QLabel *label_139;
    QLabel *label_100;
    QLabel *label_85;
    QCheckBox *checkNoSedBoundary;
    QFrame *radioGroupSnowmelt;
    QGridLayout *gridLayout_49;
    QToolButton *toolButton_SnowmeltmapShow;
    QToolButton *toolButton_SnowmeltName;
    QRadioButton *radioButton_10;
    QRadioButton *radioButton;
    QLineEdit *E_SnowmeltSatName;
    QToolButton *toolButton_SnowmeltSatName;
    QLineEdit *E_SnowmeltName;
    QToolButton *toolButton_SnowmeltShow;
    QDoubleSpinBox *E_DepositedCohesion;
    QLabel *label_101;
    QDoubleSpinBox *E_SigmaDiffusion;
    QCheckBox *checkSnowmelt;
    QLabel *label_160;
    QLabel *label_129;
    QLabel *label_61;
    QDoubleSpinBox *E_CalibrateSD2;
    QDoubleSpinBox *GW_slope;
    QCheckBox *checkKETimebased;
    QCheckBox *checkLinkedList;
    QDoubleSpinBox *E_ChannelKinWaveDt;
    QCheckBox *checkKinWaveChannel;
    QCheckBox *checkStationaryBaseflow;
    QCheckBox *checkChannelInfil;
    QGroupBox *groupBox_dbase;
    QGridLayout *gridLayout_7;
    QLabel *label_1;
    QToolButton *toolButton_fileOpen;
    QToolButton *toolButton_MapDir;
    QToolButton *toolButton_ResultDir;
    QLabel *label_2;
    QToolButton *toolButton_deleteRun;
    QLineEdit *E_MapDir;
    QComboBox *E_runFileList;
    QLabel *label_3;
    QToolButton *toolButton_ShowRunfile;
    QLineEdit *E_ResultDir;
    QCheckBox *checkAddDatetime;
    QWidget *tab_maps;
    QGridLayout *gridLayout_12;
    QLabel *label_47;
    QGroupBox *groupBox_InputMaps;
    QGridLayout *gridLayout_10;
    QCheckBox *checkExpandActive;
    QTreeView *treeView;
    QWidget *tab_simulation;
    QGridLayout *gridLayout_27;
    QFrame *frameSImInfo;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupTime;
    QGridLayout *gridLayout_13;
    QLabel *label_endtime;
    QLabel *label_area;
    QLabel *label_time;
    QLabel *label_29;
    QLabel *label_dx;
    QLabel *label_46;
    QLabel *label_38;
    QLabel *label_48;
    QTabWidget *tabWidget_totout;
    QWidget *tab_water;
    QGridLayout *gridLayout_59;
    QWidget *watergrouptotals;
    QGridLayout *gridLayout_15;
    QLabel *label_35;
    QLabel *label_64;
    QLabel *label_32;
    QLabel *label_raintot;
    QLabel *label_40;
    QLabel *label_watervoltot;
    QLabel *label_34;
    QLabel *label_interctot;
    QLabel *label_107;
    QLabel *label_floodVolmm;
    QLabel *label_36;
    QLabel *label_infiltot;
    QLabel *label_95;
    QLabel *label_watervolchannel;
    QLabel *label_37;
    QLabel *label_surfstor;
    QLabel *label_42;
    QLabel *label_qtot;
    QLabel *label_124;
    QLabel *label_ETatot;
    QLabel *label_99;
    QLabel *label_stormdraintot;
    QWidget *tab_sed;
    QGridLayout *gridLayout_62;
    QWidget *sedgrouptotals;
    QGridLayout *gridLayout_9;
    QLabel *label_soilloss;
    QLabel *label_depch;
    QLabel *label_flowdet;
    QLabel *label_21;
    QLabel *label_sedvol;
    QLabel *label_23;
    QLabel *label_splashdet;
    QLabel *label_dep;
    QLabel *label_soillosskgha;
    QLabel *label_25;
    QLabel *label_39;
    QLabel *label_41;
    QLabel *label_43;
    QLabel *label_51;
    QLabel *label_sedvolch;
    QLabel *label_31;
    QLabel *label_50;
    QLabel *label_27;
    QLabel *label_detch;
    QLabel *label_28;
    QLabel *label_60;
    QLabel *label_SDR;
    QGroupBox *outletgroup;
    QGridLayout *gridLayout_14;
    QLabel *label_qpeaksub;
    QLabel *label_soillosssub;
    QLabel *label_54;
    QLabel *label_82;
    QLabel *label_26;
    QLabel *label_24;
    QLabel *label_dischargesub;
    QLabel *label_qtotm3sub;
    QLabel *label_qpeaktime;
    QLabel *label_ppeaktime;
    QLabel *label_94;
    QLabel *label_53;
    QLabel *label_QPfrac;
    QLabel *label_52;
    QLabel *label_Qssub;
    QLabel *label_105;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_drawMap;
    QGridLayout *gridLayout_16;
    QSlider *transparency;
    QLabel *label_162;
    QDoubleSpinBox *ComboMinSpinBox;
    QDoubleSpinBox *ComboMaxSpinBox;
    QLabel *label_163;
    QComboBox *DisplayComboBox;
    QCheckBox *checkBoxComboMaps2;
    QHBoxLayout *horizontalLayout;
    QSlider *transparencyHardSurface;
    QCheckBox *checkMapBuildings;
    QSlider *transparencyRoad;
    QCheckBox *checkMapRoads;
    QCheckBox *checkMapHardSurface;
    QSlider *transparencyMap;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_92;
    QLabel *label_90;
    QSpinBox *nrcontourlevels;
    QCheckBox *checkBoxComboMaps;
    QDoubleSpinBox *ComboMaxSpinBox2;
    QComboBox *DisplayComboBox2;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkMapChannels;
    QLabel *label_137;
    QSpinBox *spinChannelSize;
    QLabel *label_113;
    QSpinBox *spinCulvertSize;
    QSpacerItem *horizontalSpacer_24;
    QCheckBox *checkMapImage;
    QDoubleSpinBox *ComboMinSpinBox2;
    QGroupBox *groupBox_info;
    QGridLayout *gridLayout_31;
    QLabel *label_MBs;
    QLabel *label_hydroCount;
    QLabel *label_30;
    QLabel *label_runtime;
    QLabel *label_MB;
    QLabel *label_endruntime;
    QLabel *label_debug;
    QLabel *label_75;
    QLabel *label_45;
    QLabel *label_44;
    QSpinBox *spinBoxPointtoShow;
    QFrame *frameDisplay2D;
    QGridLayout *gridLayout_46;
    QProgressBar *progressBar;
    QTabWidget *tabWidget_out;
    QWidget *tab_1;
    QGridLayout *gridLayout_18;
    QVBoxLayout *layout_Plot;
    QWidget *tab_2;
    QGridLayout *gridLayout_45;
    QVBoxLayout *maplayout;
    QToolBar *toolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar_2;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *lisemqtClass)
    {
        if (lisemqtClass->objectName().isEmpty())
            lisemqtClass->setObjectName("lisemqtClass");
        lisemqtClass->setEnabled(true);
        lisemqtClass->resize(1814, 984);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lisemqtClass->sizePolicy().hasHeightForWidth());
        lisemqtClass->setSizePolicy(sizePolicy);
        QPalette palette;
        lisemqtClass->setPalette(palette);
        QFont font;
        font.setBold(false);
        lisemqtClass->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../resources/openLisemN.png"), QSize(), QIcon::Normal, QIcon::Off);
        lisemqtClass->setWindowIcon(icon);
        lisemqtClass->setIconSize(QSize(32, 323));
        lisemqtClass->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        action_Open_runfile = new QAction(lisemqtClass);
        action_Open_runfile->setObjectName("action_Open_runfile");
        action_Save_runfuile = new QAction(lisemqtClass);
        action_Save_runfuile->setObjectName("action_Save_runfuile");
        centralwidget = new QWidget(lisemqtClass);
        centralwidget->setObjectName("centralwidget");
        gridLayout_83 = new QGridLayout(centralwidget);
        gridLayout_83->setObjectName("gridLayout_83");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        tabWidget->setFont(font1);
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tab_input = new QWidget();
        tab_input->setObjectName("tab_input");
        gridLayout_23 = new QGridLayout(tab_input);
        gridLayout_23->setObjectName("gridLayout_23");
        groupBoxOutput = new QGroupBox(tab_input);
        groupBoxOutput->setObjectName("groupBoxOutput");
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBoxOutput->sizePolicy().hasHeightForWidth());
        groupBoxOutput->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        groupBoxOutput->setFont(font2);
        gridLayout_64 = new QGridLayout(groupBoxOutput);
        gridLayout_64->setObjectName("gridLayout_64");
        outputGraphsTables = new QGroupBox(groupBoxOutput);
        outputGraphsTables->setObjectName("outputGraphsTables");
        sizePolicy.setHeightForWidth(outputGraphsTables->sizePolicy().hasHeightForWidth());
        outputGraphsTables->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        outputGraphsTables->setFont(font3);
        gridLayout_34 = new QGridLayout(outputGraphsTables);
        gridLayout_34->setObjectName("gridLayout_34");
        gridLayout_34->setHorizontalSpacing(7);
        gridLayout_34->setVerticalSpacing(3);
        gridLayout_34->setContentsMargins(7, 2, 7, 3);
        label_22 = new QLabel(outputGraphsTables);
        label_22->setObjectName("label_22");
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);
        label_22->setFont(font1);
        label_22->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_22->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_34->addWidget(label_22, 0, 0, 1, 1);

        E_MainTotals = new QLineEdit(outputGraphsTables);
        E_MainTotals->setObjectName("E_MainTotals");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(E_MainTotals->sizePolicy().hasHeightForWidth());
        E_MainTotals->setSizePolicy(sizePolicy2);
        E_MainTotals->setFont(font1);

        gridLayout_34->addWidget(E_MainTotals, 0, 1, 1, 1);

        label_110 = new QLabel(outputGraphsTables);
        label_110->setObjectName("label_110");
        sizePolicy.setHeightForWidth(label_110->sizePolicy().hasHeightForWidth());
        label_110->setSizePolicy(sizePolicy);
        label_110->setFont(font1);
        label_110->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_34->addWidget(label_110, 1, 0, 1, 1);

        E_SeriesTotals = new QLineEdit(outputGraphsTables);
        E_SeriesTotals->setObjectName("E_SeriesTotals");
        E_SeriesTotals->setFont(font1);

        gridLayout_34->addWidget(E_SeriesTotals, 1, 1, 1, 1);

        label_20 = new QLabel(outputGraphsTables);
        label_20->setObjectName("label_20");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy3);
        label_20->setFont(font1);
        label_20->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_20->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_34->addWidget(label_20, 2, 0, 1, 1);

        E_PointResults = new QLineEdit(outputGraphsTables);
        E_PointResults->setObjectName("E_PointResults");
        sizePolicy2.setHeightForWidth(E_PointResults->sizePolicy().hasHeightForWidth());
        E_PointResults->setSizePolicy(sizePolicy2);
        E_PointResults->setFont(font1);

        gridLayout_34->addWidget(E_PointResults, 2, 1, 1, 1);

        checksatImage = new QCheckBox(outputGraphsTables);
        checksatImage->setObjectName("checksatImage");
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(checksatImage->sizePolicy().hasHeightForWidth());
        checksatImage->setSizePolicy(sizePolicy4);
        checksatImage->setFont(font1);

        gridLayout_34->addWidget(checksatImage, 3, 0, 1, 1);

        E_satImageName = new QLineEdit(outputGraphsTables);
        E_satImageName->setObjectName("E_satImageName");
        E_satImageName->setEnabled(false);
        E_satImageName->setFont(font1);

        gridLayout_34->addWidget(E_satImageName, 3, 1, 1, 1);

        toolButton_satImageName = new QToolButton(outputGraphsTables);
        toolButton_satImageName->setObjectName("toolButton_satImageName");
        toolButton_satImageName->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/2X/Folder-Open-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_satImageName->setIcon(icon1);

        gridLayout_34->addWidget(toolButton_satImageName, 3, 2, 1, 1);


        gridLayout_64->addWidget(outputGraphsTables, 0, 0, 1, 1);

        label_128 = new QLabel(groupBoxOutput);
        label_128->setObjectName("label_128");
        sizePolicy2.setHeightForWidth(label_128->sizePolicy().hasHeightForWidth());
        label_128->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(true);
        label_128->setFont(font4);

        gridLayout_64->addWidget(label_128, 3, 0, 1, 1);

        groupBoxunits = new QGroupBox(groupBoxOutput);
        groupBoxunits->setObjectName("groupBoxunits");
        groupBoxunits->setFont(font3);
        gridLayout_55 = new QGridLayout(groupBoxunits);
        gridLayout_55->setObjectName("gridLayout_55");
        gridLayout_55->setVerticalSpacing(3);
        gridLayout_55->setContentsMargins(7, 3, 7, 3);
        E_DigitsOut = new QSpinBox(groupBoxunits);
        E_DigitsOut->setObjectName("E_DigitsOut");
        sizePolicy4.setHeightForWidth(E_DigitsOut->sizePolicy().hasHeightForWidth());
        E_DigitsOut->setSizePolicy(sizePolicy4);
        E_DigitsOut->setFont(font1);
        E_DigitsOut->setMinimum(1);
        E_DigitsOut->setMaximum(12);
        E_DigitsOut->setValue(3);

        gridLayout_55->addWidget(E_DigitsOut, 1, 1, 1, 1);

        frame = new QFrame(groupBoxunits);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_42 = new QGridLayout(frame);
        gridLayout_42->setObjectName("gridLayout_42");
        gridLayout_42->setHorizontalSpacing(8);
        gridLayout_42->setVerticalSpacing(1);
        gridLayout_42->setContentsMargins(8, 1, 8, 1);
        checkUnits_ls = new QRadioButton(frame);
        checkUnits_ls->setObjectName("checkUnits_ls");
        checkUnits_ls->setFont(font1);
        checkUnits_ls->setChecked(true);

        gridLayout_42->addWidget(checkUnits_ls, 0, 0, 1, 1);

        checkUnits_m3s = new QRadioButton(frame);
        checkUnits_m3s->setObjectName("checkUnits_m3s");
        checkUnits_m3s->setFont(font1);

        gridLayout_42->addWidget(checkUnits_m3s, 0, 1, 1, 1);


        gridLayout_55->addWidget(frame, 1, 3, 1, 1);

        frame_2 = new QFrame(groupBoxunits);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_32 = new QGridLayout(frame_2);
        gridLayout_32->setObjectName("gridLayout_32");
        gridLayout_32->setHorizontalSpacing(8);
        gridLayout_32->setVerticalSpacing(1);
        gridLayout_32->setContentsMargins(8, 1, 8, 1);
        checkUnits_tonha = new QRadioButton(frame_2);
        buttonGroup = new QButtonGroup(lisemqtClass);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(checkUnits_tonha);
        checkUnits_tonha->setObjectName("checkUnits_tonha");
        checkUnits_tonha->setFont(font1);
        checkUnits_tonha->setChecked(false);

        gridLayout_32->addWidget(checkUnits_tonha, 0, 0, 1, 1);

        checkUnits_kgcell = new QRadioButton(frame_2);
        buttonGroup->addButton(checkUnits_kgcell);
        checkUnits_kgcell->setObjectName("checkUnits_kgcell");
        checkUnits_kgcell->setFont(font1);

        gridLayout_32->addWidget(checkUnits_kgcell, 0, 2, 1, 1);

        checkUnits_kgm2 = new QRadioButton(frame_2);
        buttonGroup->addButton(checkUnits_kgm2);
        checkUnits_kgm2->setObjectName("checkUnits_kgm2");
        checkUnits_kgm2->setFont(font1);

        gridLayout_32->addWidget(checkUnits_kgm2, 0, 1, 1, 1);


        gridLayout_55->addWidget(frame_2, 1, 5, 1, 2);

        label_125 = new QLabel(groupBoxunits);
        label_125->setObjectName("label_125");
        sizePolicy3.setHeightForWidth(label_125->sizePolicy().hasHeightForWidth());
        label_125->setSizePolicy(sizePolicy3);
        label_125->setFont(font1);
        label_125->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_55->addWidget(label_125, 1, 4, 1, 1);

        label_12 = new QLabel(groupBoxunits);
        label_12->setObjectName("label_12");
        sizePolicy3.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy3);
        label_12->setFont(font1);

        gridLayout_55->addWidget(label_12, 1, 2, 1, 1);

        checkWritePCRaster = new QCheckBox(groupBoxunits);
        checkWritePCRaster->setObjectName("checkWritePCRaster");
        sizePolicy2.setHeightForWidth(checkWritePCRaster->sizePolicy().hasHeightForWidth());
        checkWritePCRaster->setSizePolicy(sizePolicy2);
        checkWritePCRaster->setFont(font1);
        checkWritePCRaster->setChecked(true);

        gridLayout_55->addWidget(checkWritePCRaster, 0, 0, 1, 7);

        label_81 = new QLabel(groupBoxunits);
        label_81->setObjectName("label_81");
        sizePolicy3.setHeightForWidth(label_81->sizePolicy().hasHeightForWidth());
        label_81->setSizePolicy(sizePolicy3);
        label_81->setFont(font1);
        label_81->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_55->addWidget(label_81, 1, 0, 1, 1);

        E_floodMinHeight = new QDoubleSpinBox(groupBoxunits);
        E_floodMinHeight->setObjectName("E_floodMinHeight");
        E_floodMinHeight->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_floodMinHeight->sizePolicy().hasHeightForWidth());
        E_floodMinHeight->setSizePolicy(sizePolicy4);
        QFont font5;
        font5.setPointSize(8);
        font5.setBold(false);
        font5.setUnderline(false);
        font5.setKerning(true);
        E_floodMinHeight->setFont(font5);
        E_floodMinHeight->setDecimals(2);
        E_floodMinHeight->setMaximum(1.000000000000000);
        E_floodMinHeight->setSingleStep(0.010000000000000);
        E_floodMinHeight->setValue(0.050000000000000);

        gridLayout_55->addWidget(E_floodMinHeight, 2, 4, 1, 1);

        label_198 = new QLabel(groupBoxunits);
        label_198->setObjectName("label_198");
        label_198->setEnabled(true);
        sizePolicy2.setHeightForWidth(label_198->sizePolicy().hasHeightForWidth());
        label_198->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setPointSize(8);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setUnderline(false);
        font6.setKerning(true);
        label_198->setFont(font6);
        label_198->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_55->addWidget(label_198, 2, 0, 1, 4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_55->addItem(horizontalSpacer_6, 1, 7, 1, 1);


        gridLayout_64->addWidget(groupBoxunits, 1, 0, 1, 1);

        scrollArea_2 = new QScrollArea(groupBoxOutput);
        scrollArea_2->setObjectName("scrollArea_2");
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy5);
        scrollArea_2->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 835, 547));
        gridLayout_39 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_39->setObjectName("gridLayout_39");
        tabWidget_OutputMaps = new QTabWidget(scrollAreaWidgetContents_2);
        tabWidget_OutputMaps->setObjectName("tabWidget_OutputMaps");
        tabWidget_OutputMaps->setEnabled(true);
        sizePolicy.setHeightForWidth(tabWidget_OutputMaps->sizePolicy().hasHeightForWidth());
        tabWidget_OutputMaps->setSizePolicy(sizePolicy);
        tabWidget_OutputMaps->setFont(font1);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_25 = new QGridLayout(tab);
        gridLayout_25->setObjectName("gridLayout_25");
        checkEndRunReport = new QCheckBox(tab);
        checkEndRunReport->setObjectName("checkEndRunReport");
        sizePolicy4.setHeightForWidth(checkEndRunReport->sizePolicy().hasHeightForWidth());
        checkEndRunReport->setSizePolicy(sizePolicy4);
        checkEndRunReport->setFont(font1);

        gridLayout_25->addWidget(checkEndRunReport, 0, 1, 1, 1);

        label_131 = new QLabel(tab);
        label_131->setObjectName("label_131");
        sizePolicy4.setHeightForWidth(label_131->sizePolicy().hasHeightForWidth());
        label_131->setSizePolicy(sizePolicy4);
        label_131->setFrameShape(QFrame::Shape::Box);
        label_131->setFrameShadow(QFrame::Shadow::Plain);
        label_131->setPixmap(QPixmap(QString::fromUtf8(":/ITC logo.png")));
        label_131->setScaledContents(false);
        label_131->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_25->addWidget(label_131, 2, 1, 1, 1);

        outputMapsSediment = new QGroupBox(tab);
        outputMapsSediment->setObjectName("outputMapsSediment");
        sizePolicy2.setHeightForWidth(outputMapsSediment->sizePolicy().hasHeightForWidth());
        outputMapsSediment->setSizePolicy(sizePolicy2);
        outputMapsSediment->setFont(font3);
        gridLayout_4 = new QGridLayout(outputMapsSediment);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setHorizontalSpacing(7);
        gridLayout_4->setVerticalSpacing(3);
        gridLayout_4->setContentsMargins(7, 4, 7, 3);
        label_19 = new QLabel(outputMapsSediment);
        label_19->setObjectName("label_19");
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setFont(font1);
        label_19->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_19->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(label_19, 2, 0, 1, 1);

        E_ChanDetachmentMap = new QLineEdit(outputMapsSediment);
        E_ChanDetachmentMap->setObjectName("E_ChanDetachmentMap");
        E_ChanDetachmentMap->setFont(font1);

        gridLayout_4->addWidget(E_ChanDetachmentMap, 3, 1, 1, 1);

        label_17 = new QLabel(outputMapsSediment);
        label_17->setObjectName("label_17");
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setFont(font1);
        label_17->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_17->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(label_17, 0, 0, 1, 1);

        E_SoillossMap = new QLineEdit(outputMapsSediment);
        E_SoillossMap->setObjectName("E_SoillossMap");
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(E_SoillossMap->sizePolicy().hasHeightForWidth());
        E_SoillossMap->setSizePolicy(sizePolicy6);
        QPalette palette1;
        E_SoillossMap->setPalette(palette1);
        E_SoillossMap->setFont(font1);

        gridLayout_4->addWidget(E_SoillossMap, 2, 1, 1, 1);

        E_DetachmentMap = new QLineEdit(outputMapsSediment);
        E_DetachmentMap->setObjectName("E_DetachmentMap");
        sizePolicy6.setHeightForWidth(E_DetachmentMap->sizePolicy().hasHeightForWidth());
        E_DetachmentMap->setSizePolicy(sizePolicy6);
        QPalette palette2;
        E_DetachmentMap->setPalette(palette2);
        E_DetachmentMap->setFont(font1);

        gridLayout_4->addWidget(E_DetachmentMap, 0, 1, 1, 1);

        E_DepositionMap = new QLineEdit(outputMapsSediment);
        E_DepositionMap->setObjectName("E_DepositionMap");
        sizePolicy6.setHeightForWidth(E_DepositionMap->sizePolicy().hasHeightForWidth());
        E_DepositionMap->setSizePolicy(sizePolicy6);
        QPalette palette3;
        E_DepositionMap->setPalette(palette3);
        E_DepositionMap->setFont(font1);

        gridLayout_4->addWidget(E_DepositionMap, 1, 1, 1, 1);

        label_180 = new QLabel(outputMapsSediment);
        label_180->setObjectName("label_180");
        label_180->setFont(font1);
        label_180->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(label_180, 4, 0, 1, 1);

        label_18 = new QLabel(outputMapsSediment);
        label_18->setObjectName("label_18");
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setFont(font1);
        label_18->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_18->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(label_18, 1, 0, 1, 1);

        E_ChanDepositionMap = new QLineEdit(outputMapsSediment);
        E_ChanDepositionMap->setObjectName("E_ChanDepositionMap");
        E_ChanDepositionMap->setFont(font1);

        gridLayout_4->addWidget(E_ChanDepositionMap, 4, 1, 1, 1);

        label_179 = new QLabel(outputMapsSediment);
        label_179->setObjectName("label_179");
        label_179->setFont(font1);
        label_179->setTextFormat(Qt::TextFormat::PlainText);
        label_179->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(label_179, 3, 0, 1, 1);


        gridLayout_25->addWidget(outputMapsSediment, 2, 0, 1, 1);

        checkFormatGtiff = new QCheckBox(tab);
        checkFormatGtiff->setObjectName("checkFormatGtiff");
        sizePolicy4.setHeightForWidth(checkFormatGtiff->sizePolicy().hasHeightForWidth());
        checkFormatGtiff->setSizePolicy(sizePolicy4);
        checkFormatGtiff->setFont(font1);

        gridLayout_25->addWidget(checkFormatGtiff, 0, 0, 1, 1);

        outputMapsFlood = new QGroupBox(tab);
        outputMapsFlood->setObjectName("outputMapsFlood");
        sizePolicy2.setHeightForWidth(outputMapsFlood->sizePolicy().hasHeightForWidth());
        outputMapsFlood->setSizePolicy(sizePolicy2);
        outputMapsFlood->setFont(font3);
        gridLayout_74 = new QGridLayout(outputMapsFlood);
        gridLayout_74->setObjectName("gridLayout_74");
        gridLayout_74->setHorizontalSpacing(7);
        gridLayout_74->setVerticalSpacing(3);
        gridLayout_74->setContentsMargins(7, 4, 7, 3);
        label_120 = new QLabel(outputMapsFlood);
        label_120->setObjectName("label_120");
        label_120->setFont(font1);
        label_120->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_74->addWidget(label_120, 1, 0, 1, 1);

        label_122 = new QLabel(outputMapsFlood);
        label_122->setObjectName("label_122");
        label_122->setFont(font1);
        label_122->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_74->addWidget(label_122, 0, 0, 1, 1);

        label_112 = new QLabel(outputMapsFlood);
        label_112->setObjectName("label_112");
        label_112->setFont(font1);
        label_112->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_74->addWidget(label_112, 9, 0, 1, 1);

        E_stormDrainVolMap = new QLineEdit(outputMapsFlood);
        E_stormDrainVolMap->setObjectName("E_stormDrainVolMap");
        sizePolicy6.setHeightForWidth(E_stormDrainVolMap->sizePolicy().hasHeightForWidth());
        E_stormDrainVolMap->setSizePolicy(sizePolicy6);
        E_stormDrainVolMap->setFont(font1);

        gridLayout_74->addWidget(E_stormDrainVolMap, 8, 1, 1, 1);

        E_FloodStats = new QLineEdit(outputMapsFlood);
        E_FloodStats->setObjectName("E_FloodStats");
        E_FloodStats->setEnabled(true);
        sizePolicy6.setHeightForWidth(E_FloodStats->sizePolicy().hasHeightForWidth());
        E_FloodStats->setSizePolicy(sizePolicy6);
        E_FloodStats->setFont(font1);

        gridLayout_74->addWidget(E_FloodStats, 9, 1, 1, 1);

        E_ChannelQtotm3Map = new QLineEdit(outputMapsFlood);
        E_ChannelQtotm3Map->setObjectName("E_ChannelQtotm3Map");
        E_ChannelQtotm3Map->setEnabled(true);
        sizePolicy6.setHeightForWidth(E_ChannelQtotm3Map->sizePolicy().hasHeightForWidth());
        E_ChannelQtotm3Map->setSizePolicy(sizePolicy6);
        E_ChannelQtotm3Map->setFont(font1);

        gridLayout_74->addWidget(E_ChannelQtotm3Map, 0, 1, 1, 1);

        label_111 = new QLabel(outputMapsFlood);
        label_111->setObjectName("label_111");
        label_111->setFont(font1);
        label_111->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_74->addWidget(label_111, 3, 0, 1, 1);

        E_ChannelMaxWH = new QLineEdit(outputMapsFlood);
        E_ChannelMaxWH->setObjectName("E_ChannelMaxWH");
        E_ChannelMaxWH->setEnabled(true);
        sizePolicy6.setHeightForWidth(E_ChannelMaxWH->sizePolicy().hasHeightForWidth());
        E_ChannelMaxWH->setSizePolicy(sizePolicy6);
        E_ChannelMaxWH->setFont(font1);

        gridLayout_74->addWidget(E_ChannelMaxWH, 1, 1, 1, 1);

        E_FloodTimeMap = new QLineEdit(outputMapsFlood);
        E_FloodTimeMap->setObjectName("E_FloodTimeMap");
        E_FloodTimeMap->setEnabled(true);
        sizePolicy6.setHeightForWidth(E_FloodTimeMap->sizePolicy().hasHeightForWidth());
        E_FloodTimeMap->setSizePolicy(sizePolicy6);
        E_FloodTimeMap->setFont(font1);

        gridLayout_74->addWidget(E_FloodTimeMap, 3, 1, 1, 1);

        E_FloodFEW = new QLineEdit(outputMapsFlood);
        E_FloodFEW->setObjectName("E_FloodFEW");
        E_FloodFEW->setEnabled(true);
        sizePolicy6.setHeightForWidth(E_FloodFEW->sizePolicy().hasHeightForWidth());
        E_FloodFEW->setSizePolicy(sizePolicy6);
        E_FloodFEW->setFont(font1);

        gridLayout_74->addWidget(E_FloodFEW, 4, 1, 1, 1);

        label_119 = new QLabel(outputMapsFlood);
        label_119->setObjectName("label_119");
        label_119->setFont(font1);
        label_119->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_74->addWidget(label_119, 2, 0, 1, 1);

        label_79 = new QLabel(outputMapsFlood);
        label_79->setObjectName("label_79");
        label_79->setFont(font1);
        label_79->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_74->addWidget(label_79, 7, 0, 1, 1);

        E_stormDrainMap = new QLineEdit(outputMapsFlood);
        E_stormDrainMap->setObjectName("E_stormDrainMap");
        sizePolicy6.setHeightForWidth(E_stormDrainMap->sizePolicy().hasHeightForWidth());
        E_stormDrainMap->setSizePolicy(sizePolicy6);
        E_stormDrainMap->setFont(font1);

        gridLayout_74->addWidget(E_stormDrainMap, 7, 1, 1, 1);

        label_93 = new QLabel(outputMapsFlood);
        label_93->setObjectName("label_93");
        label_93->setFont(font1);
        label_93->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_74->addWidget(label_93, 4, 0, 1, 1);

        E_ChannelMaxQ = new QLineEdit(outputMapsFlood);
        E_ChannelMaxQ->setObjectName("E_ChannelMaxQ");
        E_ChannelMaxQ->setEnabled(true);
        sizePolicy6.setHeightForWidth(E_ChannelMaxQ->sizePolicy().hasHeightForWidth());
        E_ChannelMaxQ->setSizePolicy(sizePolicy6);
        E_ChannelMaxQ->setFont(font1);

        gridLayout_74->addWidget(E_ChannelMaxQ, 2, 1, 1, 1);

        label_103 = new QLabel(outputMapsFlood);
        label_103->setObjectName("label_103");
        label_103->setFont(font1);
        label_103->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_74->addWidget(label_103, 8, 0, 1, 1);


        gridLayout_25->addWidget(outputMapsFlood, 1, 1, 1, 1);

        outputMapsWater = new QGroupBox(tab);
        outputMapsWater->setObjectName("outputMapsWater");
        sizePolicy.setHeightForWidth(outputMapsWater->sizePolicy().hasHeightForWidth());
        outputMapsWater->setSizePolicy(sizePolicy);
        outputMapsWater->setFont(font3);
        gridLayout_73 = new QGridLayout(outputMapsWater);
        gridLayout_73->setObjectName("gridLayout_73");
        gridLayout_73->setHorizontalSpacing(7);
        gridLayout_73->setVerticalSpacing(3);
        gridLayout_73->setContentsMargins(7, 3, 7, 3);
        label_114 = new QLabel(outputMapsWater);
        label_114->setObjectName("label_114");
        label_114->setFont(font1);
        label_114->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_73->addWidget(label_114, 1, 0, 1, 1);

        E_InfiltrationMap = new QLineEdit(outputMapsWater);
        E_InfiltrationMap->setObjectName("E_InfiltrationMap");
        sizePolicy6.setHeightForWidth(E_InfiltrationMap->sizePolicy().hasHeightForWidth());
        E_InfiltrationMap->setSizePolicy(sizePolicy6);
        E_InfiltrationMap->setFont(font1);

        gridLayout_73->addWidget(E_InfiltrationMap, 3, 1, 1, 1);

        label_74 = new QLabel(outputMapsWater);
        label_74->setObjectName("label_74");
        label_74->setFont(font1);

        gridLayout_73->addWidget(label_74, 8, 0, 1, 1);

        label_138 = new QLabel(outputMapsWater);
        label_138->setObjectName("label_138");
        label_138->setFont(font1);
        label_138->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_73->addWidget(label_138, 6, 0, 1, 1);

        E_RainfallMap = new QLineEdit(outputMapsWater);
        E_RainfallMap->setObjectName("E_RainfallMap");
        E_RainfallMap->setEnabled(true);
        sizePolicy6.setHeightForWidth(E_RainfallMap->sizePolicy().hasHeightForWidth());
        E_RainfallMap->setSizePolicy(sizePolicy6);
        E_RainfallMap->setFont(font1);

        gridLayout_73->addWidget(E_RainfallMap, 1, 1, 1, 1);

        E_RunoffMap = new QLineEdit(outputMapsWater);
        E_RunoffMap->setObjectName("E_RunoffMap");
        sizePolicy6.setHeightForWidth(E_RunoffMap->sizePolicy().hasHeightForWidth());
        E_RunoffMap->setSizePolicy(sizePolicy6);
        E_RunoffMap->setFont(font1);

        gridLayout_73->addWidget(E_RunoffMap, 4, 1, 1, 1);

        label_116 = new QLabel(outputMapsWater);
        label_116->setObjectName("label_116");
        label_116->setFont(font1);
        label_116->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_73->addWidget(label_116, 3, 0, 1, 1);

        label_117 = new QLabel(outputMapsWater);
        label_117->setObjectName("label_117");
        label_117->setFont(font1);
        label_117->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_73->addWidget(label_117, 4, 0, 1, 1);

        E_WHmaxMap = new QLineEdit(outputMapsWater);
        E_WHmaxMap->setObjectName("E_WHmaxMap");
        sizePolicy6.setHeightForWidth(E_WHmaxMap->sizePolicy().hasHeightForWidth());
        E_WHmaxMap->setSizePolicy(sizePolicy6);
        E_WHmaxMap->setFont(font1);

        gridLayout_73->addWidget(E_WHmaxMap, 6, 1, 1, 1);

        E_FloodmaxVMap = new QLineEdit(outputMapsWater);
        E_FloodmaxVMap->setObjectName("E_FloodmaxVMap");
        E_FloodmaxVMap->setEnabled(true);
        sizePolicy6.setHeightForWidth(E_FloodmaxVMap->sizePolicy().hasHeightForWidth());
        E_FloodmaxVMap->setSizePolicy(sizePolicy6);
        E_FloodmaxVMap->setFont(font1);

        gridLayout_73->addWidget(E_FloodmaxVMap, 7, 1, 1, 1);

        label_115 = new QLabel(outputMapsWater);
        label_115->setObjectName("label_115");
        label_115->setFont(font1);
        label_115->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_73->addWidget(label_115, 2, 0, 1, 1);

        label_136 = new QLabel(outputMapsWater);
        label_136->setObjectName("label_136");
        label_136->setFont(font1);
        label_136->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_73->addWidget(label_136, 7, 0, 1, 1);

        E_FloodmaxVHMap = new QLineEdit(outputMapsWater);
        E_FloodmaxVHMap->setObjectName("E_FloodmaxVHMap");
        sizePolicy6.setHeightForWidth(E_FloodmaxVHMap->sizePolicy().hasHeightForWidth());
        E_FloodmaxVHMap->setSizePolicy(sizePolicy6);
        E_FloodmaxVHMap->setFont(font1);

        gridLayout_73->addWidget(E_FloodmaxVHMap, 8, 1, 1, 1);

        E_InterceptionMap = new QLineEdit(outputMapsWater);
        E_InterceptionMap->setObjectName("E_InterceptionMap");
        sizePolicy6.setHeightForWidth(E_InterceptionMap->sizePolicy().hasHeightForWidth());
        E_InterceptionMap->setSizePolicy(sizePolicy6);
        E_InterceptionMap->setFont(font1);

        gridLayout_73->addWidget(E_InterceptionMap, 2, 1, 1, 1);


        gridLayout_25->addWidget(outputMapsWater, 1, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_25->addItem(verticalSpacer_10, 3, 0, 1, 1);

        tabWidget_OutputMaps->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout_36 = new QGridLayout(tab_4);
        gridLayout_36->setObjectName("gridLayout_36");
        mapsout = new QFrame(tab_4);
        mapsout->setObjectName("mapsout");
        gridLayout_63 = new QGridLayout(mapsout);
        gridLayout_63->setObjectName("gridLayout_63");
        gridLayout_63->setHorizontalSpacing(8);
        gridLayout_63->setVerticalSpacing(4);
        gridLayout_63->setContentsMargins(0, 0, 0, 0);
        groupWatermapseriesout = new QGroupBox(mapsout);
        groupWatermapseriesout->setObjectName("groupWatermapseriesout");
        groupWatermapseriesout->setFont(font3);
        gridLayout_61 = new QGridLayout(groupWatermapseriesout);
        gridLayout_61->setObjectName("gridLayout_61");
        checkBox_OutSurfStor = new QCheckBox(groupWatermapseriesout);
        checkBox_OutSurfStor->setObjectName("checkBox_OutSurfStor");
        sizePolicy2.setHeightForWidth(checkBox_OutSurfStor->sizePolicy().hasHeightForWidth());
        checkBox_OutSurfStor->setSizePolicy(sizePolicy2);
        checkBox_OutSurfStor->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutSurfStor, 0, 0, 1, 1);

        checkBox_OutTiledrain = new QCheckBox(groupWatermapseriesout);
        checkBox_OutTiledrain->setObjectName("checkBox_OutTiledrain");
        checkBox_OutTiledrain->setEnabled(true);
        sizePolicy2.setHeightForWidth(checkBox_OutTiledrain->sizePolicy().hasHeightForWidth());
        checkBox_OutTiledrain->setSizePolicy(sizePolicy2);
        checkBox_OutTiledrain->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutTiledrain, 6, 0, 1, 1);

        checkBox_OutWH = new QCheckBox(groupWatermapseriesout);
        checkBox_OutWH->setObjectName("checkBox_OutWH");
        sizePolicy2.setHeightForWidth(checkBox_OutWH->sizePolicy().hasHeightForWidth());
        checkBox_OutWH->setSizePolicy(sizePolicy2);
        checkBox_OutWH->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutWH, 4, 0, 1, 1);

        checkBox_OutInf = new QCheckBox(groupWatermapseriesout);
        checkBox_OutInf->setObjectName("checkBox_OutInf");
        sizePolicy2.setHeightForWidth(checkBox_OutInf->sizePolicy().hasHeightForWidth());
        checkBox_OutInf->setSizePolicy(sizePolicy2);
        checkBox_OutInf->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutInf, 2, 0, 1, 1);

        checkBox_OutTheta = new QCheckBox(groupWatermapseriesout);
        checkBox_OutTheta->setObjectName("checkBox_OutTheta");
        checkBox_OutTheta->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutTheta, 8, 0, 1, 1);

        checkBox_OutV = new QCheckBox(groupWatermapseriesout);
        checkBox_OutV->setObjectName("checkBox_OutV");
        sizePolicy2.setHeightForWidth(checkBox_OutV->sizePolicy().hasHeightForWidth());
        checkBox_OutV->setSizePolicy(sizePolicy2);
        checkBox_OutV->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutV, 5, 0, 1, 1);

        checkBox_OutInterception = new QCheckBox(groupWatermapseriesout);
        checkBox_OutInterception->setObjectName("checkBox_OutInterception");
        checkBox_OutInterception->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutInterception, 1, 0, 1, 1);

        checkBox_OutTileVol = new QCheckBox(groupWatermapseriesout);
        checkBox_OutTileVol->setObjectName("checkBox_OutTileVol");
        checkBox_OutTileVol->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutTileVol, 7, 0, 1, 1);

        checkBox_OutRunoff = new QCheckBox(groupWatermapseriesout);
        checkBox_OutRunoff->setObjectName("checkBox_OutRunoff");
        sizePolicy2.setHeightForWidth(checkBox_OutRunoff->sizePolicy().hasHeightForWidth());
        checkBox_OutRunoff->setSizePolicy(sizePolicy2);
        checkBox_OutRunoff->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutRunoff, 3, 0, 1, 1);

        checkBox_OutGW = new QCheckBox(groupWatermapseriesout);
        checkBox_OutGW->setObjectName("checkBox_OutGW");
        checkBox_OutGW->setFont(font1);

        gridLayout_61->addWidget(checkBox_OutGW, 9, 0, 1, 1);


        gridLayout_63->addWidget(groupWatermapseriesout, 2, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_63->addItem(horizontalSpacer_8, 0, 1, 1, 1);

        groupSedMapseriesout = new QGroupBox(mapsout);
        groupSedMapseriesout->setObjectName("groupSedMapseriesout");
        groupSedMapseriesout->setFont(font3);
        gridLayout_35 = new QGridLayout(groupSedMapseriesout);
        gridLayout_35->setObjectName("gridLayout_35");
        checkBox_OutDet = new QCheckBox(groupSedMapseriesout);
        checkBox_OutDet->setObjectName("checkBox_OutDet");
        sizePolicy2.setHeightForWidth(checkBox_OutDet->sizePolicy().hasHeightForWidth());
        checkBox_OutDet->setSizePolicy(sizePolicy2);
        checkBox_OutDet->setFont(font1);

        gridLayout_35->addWidget(checkBox_OutDet, 0, 0, 1, 1);

        checkBox_OutDep = new QCheckBox(groupSedMapseriesout);
        checkBox_OutDep->setObjectName("checkBox_OutDep");
        sizePolicy2.setHeightForWidth(checkBox_OutDep->sizePolicy().hasHeightForWidth());
        checkBox_OutDep->setSizePolicy(sizePolicy2);
        checkBox_OutDep->setFont(font1);

        gridLayout_35->addWidget(checkBox_OutDep, 1, 0, 1, 1);

        checkBox_OutSL = new QCheckBox(groupSedMapseriesout);
        checkBox_OutSL->setObjectName("checkBox_OutSL");
        checkBox_OutSL->setFont(font1);

        gridLayout_35->addWidget(checkBox_OutSL, 2, 0, 1, 1);

        checkBox_OutConc = new QCheckBox(groupSedMapseriesout);
        checkBox_OutConc->setObjectName("checkBox_OutConc");
        sizePolicy2.setHeightForWidth(checkBox_OutConc->sizePolicy().hasHeightForWidth());
        checkBox_OutConc->setSizePolicy(sizePolicy2);
        checkBox_OutConc->setFont(font1);

        gridLayout_35->addWidget(checkBox_OutConc, 3, 0, 1, 1);

        checkBox_OutTC = new QCheckBox(groupSedMapseriesout);
        checkBox_OutTC->setObjectName("checkBox_OutTC");
        sizePolicy2.setHeightForWidth(checkBox_OutTC->sizePolicy().hasHeightForWidth());
        checkBox_OutTC->setSizePolicy(sizePolicy2);
        checkBox_OutTC->setFont(font1);

        gridLayout_35->addWidget(checkBox_OutTC, 4, 0, 1, 1);

        checkBox_OutSed = new QCheckBox(groupSedMapseriesout);
        checkBox_OutSed->setObjectName("checkBox_OutSed");
        checkBox_OutSed->setFont(font1);

        gridLayout_35->addWidget(checkBox_OutSed, 5, 0, 1, 1);

        checkBox_OutSedSS = new QCheckBox(groupSedMapseriesout);
        checkBox_OutSedSS->setObjectName("checkBox_OutSedSS");
        checkBox_OutSedSS->setFont(font1);

        gridLayout_35->addWidget(checkBox_OutSedSS, 6, 0, 1, 1);

        checkBox_OutSedBL = new QCheckBox(groupSedMapseriesout);
        checkBox_OutSedBL->setObjectName("checkBox_OutSedBL");
        checkBox_OutSedBL->setFont(font1);

        gridLayout_35->addWidget(checkBox_OutSedBL, 7, 0, 1, 1);


        gridLayout_63->addWidget(groupSedMapseriesout, 2, 1, 1, 1);

        checkWritePCRnames = new QCheckBox(mapsout);
        checkWritePCRnames->setObjectName("checkWritePCRnames");
        checkWritePCRnames->setFont(font1);

        gridLayout_63->addWidget(checkWritePCRnames, 1, 0, 1, 2);


        gridLayout_36->addWidget(mapsout, 0, 0, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_36->addItem(horizontalSpacer_14, 0, 1, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_36->addItem(verticalSpacer_9, 1, 0, 1, 1);

        tabWidget_OutputMaps->addTab(tab_4, QString());

        gridLayout_39->addWidget(tabWidget_OutputMaps, 1, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_64->addWidget(scrollArea_2, 5, 0, 1, 1);

        gridLayout_33 = new QGridLayout();
        gridLayout_33->setObjectName("gridLayout_33");
        label_80 = new QLabel(groupBoxOutput);
        label_80->setObjectName("label_80");
        sizePolicy4.setHeightForWidth(label_80->sizePolicy().hasHeightForWidth());
        label_80->setSizePolicy(sizePolicy4);
        label_80->setFont(font1);
        label_80->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_33->addWidget(label_80, 0, 1, 1, 1);

        label_16 = new QLabel(groupBoxOutput);
        label_16->setObjectName("label_16");
        sizePolicy4.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy4);
        label_16->setFont(font1);

        gridLayout_33->addWidget(label_16, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_33->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        printinterval = new QSpinBox(groupBoxOutput);
        printinterval->setObjectName("printinterval");
        sizePolicy4.setHeightForWidth(printinterval->sizePolicy().hasHeightForWidth());
        printinterval->setSizePolicy(sizePolicy4);
        printinterval->setFont(font1);
        printinterval->setMinimum(1);
        printinterval->setMaximum(999);

        gridLayout_33->addWidget(printinterval, 0, 2, 1, 1);

        checkReportMapsEnd = new QCheckBox(groupBoxOutput);
        checkReportMapsEnd->setObjectName("checkReportMapsEnd");
        checkReportMapsEnd->setFont(font1);

        gridLayout_33->addWidget(checkReportMapsEnd, 0, 4, 1, 1);


        gridLayout_64->addLayout(gridLayout_33, 4, 0, 1, 1);


        gridLayout_23->addWidget(groupBoxOutput, 0, 1, 1, 1);

        groupBoxInput = new QGroupBox(tab_input);
        groupBoxInput->setObjectName("groupBoxInput");
        sizePolicy1.setHeightForWidth(groupBoxInput->sizePolicy().hasHeightForWidth());
        groupBoxInput->setSizePolicy(sizePolicy1);
        QPalette palette4;
        groupBoxInput->setPalette(palette4);
        groupBoxInput->setFont(font2);
        gridLayout_37 = new QGridLayout(groupBoxInput);
        gridLayout_37->setObjectName("gridLayout_37");
        gridLayout_37->setHorizontalSpacing(8);
        gridLayout_37->setVerticalSpacing(4);
        gridLayout_37->setContentsMargins(8, 4, 8, 4);
        groupBoxTime = new QGroupBox(groupBoxInput);
        groupBoxTime->setObjectName("groupBoxTime");
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupBoxTime->sizePolicy().hasHeightForWidth());
        groupBoxTime->setSizePolicy(sizePolicy7);
        groupBoxTime->setFont(font3);
        gridLayout_43 = new QGridLayout(groupBoxTime);
        gridLayout_43->setObjectName("gridLayout_43");
        E_Timestep = new QLineEdit(groupBoxTime);
        E_Timestep->setObjectName("E_Timestep");
        sizePolicy4.setHeightForWidth(E_Timestep->sizePolicy().hasHeightForWidth());
        E_Timestep->setSizePolicy(sizePolicy4);
        E_Timestep->setFont(font1);
        E_Timestep->setMaxLength(32767);
        E_Timestep->setCursorPosition(4);
        E_Timestep->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_43->addWidget(E_Timestep, 0, 1, 1, 1);

        label_6 = new QLabel(groupBoxTime);
        label_6->setObjectName("label_6");
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_43->addWidget(label_6, 0, 2, 1, 1);

        E_EndTimeDay = new QLineEdit(groupBoxTime);
        E_EndTimeDay->setObjectName("E_EndTimeDay");
        sizePolicy4.setHeightForWidth(E_EndTimeDay->sizePolicy().hasHeightForWidth());
        E_EndTimeDay->setSizePolicy(sizePolicy4);
        E_EndTimeDay->setFont(font1);
        E_EndTimeDay->setCursorPosition(6);
        E_EndTimeDay->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_43->addWidget(E_EndTimeDay, 0, 5, 1, 1);

        label_8 = new QLabel(groupBoxTime);
        label_8->setObjectName("label_8");
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_43->addWidget(label_8, 0, 0, 1, 1);

        label_7 = new QLabel(groupBoxTime);
        label_7->setObjectName("label_7");
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_43->addWidget(label_7, 0, 4, 1, 1);

        E_BeginTimeDay = new QLineEdit(groupBoxTime);
        E_BeginTimeDay->setObjectName("E_BeginTimeDay");
        sizePolicy4.setHeightForWidth(E_BeginTimeDay->sizePolicy().hasHeightForWidth());
        E_BeginTimeDay->setSizePolicy(sizePolicy4);
        E_BeginTimeDay->setFont(font1);
        E_BeginTimeDay->setMaxLength(32767);
        E_BeginTimeDay->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_43->addWidget(E_BeginTimeDay, 0, 3, 1, 1);


        gridLayout_37->addWidget(groupBoxTime, 3, 0, 1, 1);

        scrollArea = new QScrollArea(groupBoxInput);
        scrollArea->setObjectName("scrollArea");
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1013, 819));
        gridLayout_54 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_54->setObjectName("gridLayout_54");
        tabWidgetOptions = new QTabWidget(scrollAreaWidgetContents);
        tabWidgetOptions->setObjectName("tabWidgetOptions");
        tabWidgetOptions->setEnabled(true);
        sizePolicy6.setHeightForWidth(tabWidgetOptions->sizePolicy().hasHeightForWidth());
        tabWidgetOptions->setSizePolicy(sizePolicy6);
        tabWidgetOptions->setFont(font5);
        tabWidgetOptions->setAutoFillBackground(true);
        tabWidgetOptions->setTabPosition(QTabWidget::TabPosition::West);
        tabWidgetOptions->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidgetOptions->setIconSize(QSize(32, 42));
        tab_general = new QWidget();
        tab_general->setObjectName("tab_general");
        gridLayout_38 = new QGridLayout(tab_general);
        gridLayout_38->setObjectName("gridLayout_38");
        groupBox_8 = new QGroupBox(tab_general);
        groupBox_8->setObjectName("groupBox_8");
        sizePolicy6.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy6);
        QFont font7;
        font7.setPointSize(8);
        font7.setBold(true);
        font7.setUnderline(false);
        font7.setKerning(true);
        groupBox_8->setFont(font7);
        groupBox_8->setCheckable(false);
        formLayout = new QFormLayout(groupBox_8);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(8);
        formLayout->setVerticalSpacing(4);
        formLayout->setContentsMargins(8, 4, 8, 4);
        checkDoErosion = new QCheckBox(groupBox_8);
        checkDoErosion->setObjectName("checkDoErosion");
        sizePolicy2.setHeightForWidth(checkDoErosion->sizePolicy().hasHeightForWidth());
        checkDoErosion->setSizePolicy(sizePolicy2);
        checkDoErosion->setFont(font5);

        formLayout->setWidget(0, QFormLayout::SpanningRole, checkDoErosion);


        gridLayout_38->addWidget(groupBox_8, 7, 0, 1, 2);

        groupSurfaceflow = new QGroupBox(tab_general);
        groupSurfaceflow->setObjectName("groupSurfaceflow");
        sizePolicy6.setHeightForWidth(groupSurfaceflow->sizePolicy().hasHeightForWidth());
        groupSurfaceflow->setSizePolicy(sizePolicy6);
        groupSurfaceflow->setFont(font7);
        gridLayout_8 = new QGridLayout(groupSurfaceflow);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setHorizontalSpacing(8);
        gridLayout_8->setVerticalSpacing(4);
        gridLayout_8->setContentsMargins(8, 4, 8, 4);
        E_OFWaveType = new QComboBox(groupSurfaceflow);
        E_OFWaveType->addItem(QString());
        E_OFWaveType->addItem(QString());
        E_OFWaveType->addItem(QString());
        E_OFWaveType->setObjectName("E_OFWaveType");
        E_OFWaveType->setFont(font5);
        E_OFWaveType->setMaxVisibleItems(3);

        gridLayout_8->addWidget(E_OFWaveType, 0, 0, 1, 1);


        gridLayout_38->addWidget(groupSurfaceflow, 5, 0, 1, 2);

        groupBox = new QGroupBox(tab_general);
        groupBox->setObjectName("groupBox");
        sizePolicy6.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy6);
        groupBox->setFont(font7);
        gridLayout_80 = new QGridLayout(groupBox);
        gridLayout_80->setObjectName("gridLayout_80");
        gridLayout_80->setHorizontalSpacing(8);
        gridLayout_80->setVerticalSpacing(4);
        gridLayout_80->setContentsMargins(8, 4, 8, 4);
        checkInfiltration = new QCheckBox(groupBox);
        checkInfiltration->setObjectName("checkInfiltration");
        checkInfiltration->setFont(font5);

        gridLayout_80->addWidget(checkInfiltration, 0, 0, 1, 1);


        gridLayout_38->addWidget(groupBox, 4, 0, 1, 2);

        groupChannels = new QGroupBox(tab_general);
        groupChannels->setObjectName("groupChannels");
        sizePolicy6.setHeightForWidth(groupChannels->sizePolicy().hasHeightForWidth());
        groupChannels->setSizePolicy(sizePolicy6);
        groupChannels->setFont(font7);
        groupChannels->setCheckable(false);
        gridLayout_17 = new QGridLayout(groupChannels);
        gridLayout_17->setObjectName("gridLayout_17");
        gridLayout_17->setHorizontalSpacing(8);
        gridLayout_17->setVerticalSpacing(4);
        gridLayout_17->setContentsMargins(8, 4, 8, 4);
        checkIncludeChannel = new QCheckBox(groupChannels);
        checkIncludeChannel->setObjectName("checkIncludeChannel");
        sizePolicy2.setHeightForWidth(checkIncludeChannel->sizePolicy().hasHeightForWidth());
        checkIncludeChannel->setSizePolicy(sizePolicy2);
        checkIncludeChannel->setFont(font5);
        checkIncludeChannel->setChecked(true);

        gridLayout_17->addWidget(checkIncludeChannel, 0, 0, 1, 4);

        checkGWflow = new QCheckBox(groupChannels);
        checkGWflow->setObjectName("checkGWflow");
        sizePolicy2.setHeightForWidth(checkGWflow->sizePolicy().hasHeightForWidth());
        checkGWflow->setSizePolicy(sizePolicy2);
        checkGWflow->setFont(font5);

        gridLayout_17->addWidget(checkGWflow, 1, 0, 1, 1);


        gridLayout_38->addWidget(groupChannels, 6, 0, 1, 2);

        label_55 = new QLabel(tab_general);
        label_55->setObjectName("label_55");
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_55->sizePolicy().hasHeightForWidth());
        label_55->setSizePolicy(sizePolicy8);
        QFont font8;
        font8.setPointSize(9);
        font8.setBold(true);
        font8.setUnderline(false);
        font8.setKerning(true);
        label_55->setFont(font8);

        gridLayout_38->addWidget(label_55, 0, 0, 1, 1);

        toolButton_resetOptions = new QToolButton(tab_general);
        toolButton_resetOptions->setObjectName("toolButton_resetOptions");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/2X/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_resetOptions->setIcon(icon2);

        gridLayout_38->addWidget(toolButton_resetOptions, 0, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_38->addItem(verticalSpacer_4, 9, 1, 1, 1);

        groupInfrastructrure = new QGroupBox(tab_general);
        groupInfrastructrure->setObjectName("groupInfrastructrure");
        sizePolicy6.setHeightForWidth(groupInfrastructrure->sizePolicy().hasHeightForWidth());
        groupInfrastructrure->setSizePolicy(sizePolicy6);
        groupInfrastructrure->setFont(font7);
        gridLayout_51 = new QGridLayout(groupInfrastructrure);
        gridLayout_51->setObjectName("gridLayout_51");
        gridLayout_51->setHorizontalSpacing(8);
        gridLayout_51->setVerticalSpacing(4);
        gridLayout_51->setContentsMargins(8, 4, 8, 4);
        checkInfrastructure = new QCheckBox(groupInfrastructrure);
        checkInfrastructure->setObjectName("checkInfrastructure");
        checkInfrastructure->setFont(font5);

        gridLayout_51->addWidget(checkInfrastructure, 0, 0, 1, 1);

        checkConservation = new QCheckBox(groupInfrastructrure);
        checkConservation->setObjectName("checkConservation");
        checkConservation->setFont(font5);

        gridLayout_51->addWidget(checkConservation, 1, 0, 1, 1);


        gridLayout_38->addWidget(groupInfrastructrure, 8, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_38->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        toolButton_helpOptions = new QToolButton(tab_general);
        toolButton_helpOptions->setObjectName("toolButton_helpOptions");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/2X/question-mark-button2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_helpOptions->setIcon(icon3);
        toolButton_helpOptions->setCheckable(false);
        toolButton_helpOptions->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        toolButton_helpOptions->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        toolButton_helpOptions->setArrowType(Qt::ArrowType::NoArrow);

        gridLayout_38->addWidget(toolButton_helpOptions, 0, 3, 1, 1);

        groupBox_2 = new QGroupBox(tab_general);
        groupBox_2->setObjectName("groupBox_2");
        sizePolicy6.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy6);
        groupBox_2->setFont(font7);
        gridLayout_81 = new QGridLayout(groupBox_2);
        gridLayout_81->setObjectName("gridLayout_81");
        gridLayout_81->setHorizontalSpacing(8);
        gridLayout_81->setVerticalSpacing(4);
        gridLayout_81->setContentsMargins(8, 4, 8, 4);
        checkRainfall = new QCheckBox(groupBox_2);
        checkRainfall->setObjectName("checkRainfall");
        checkRainfall->setFont(font5);

        gridLayout_81->addWidget(checkRainfall, 0, 0, 1, 1);

        checkET = new QCheckBox(groupBox_2);
        checkET->setObjectName("checkET");
        checkET->setFont(font5);

        gridLayout_81->addWidget(checkET, 1, 0, 1, 1);


        gridLayout_38->addWidget(groupBox_2, 2, 0, 1, 2);

        groupBox_3 = new QGroupBox(tab_general);
        groupBox_3->setObjectName("groupBox_3");
        sizePolicy6.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy6);
        groupBox_3->setFont(font7);
        gridLayout_71 = new QGridLayout(groupBox_3);
        gridLayout_71->setObjectName("gridLayout_71");
        gridLayout_71->setHorizontalSpacing(8);
        gridLayout_71->setVerticalSpacing(4);
        gridLayout_71->setContentsMargins(8, 4, 8, 4);
        checkInterception = new QCheckBox(groupBox_3);
        checkInterception->setObjectName("checkInterception");
        checkInterception->setFont(font5);

        gridLayout_71->addWidget(checkInterception, 0, 0, 1, 1);


        gridLayout_38->addWidget(groupBox_3, 3, 0, 1, 2);

        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/settings2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_general, icon4, QString());
        tab_meteo = new QWidget();
        tab_meteo->setObjectName("tab_meteo");
        gridLayout_77 = new QGridLayout(tab_meteo);
        gridLayout_77->setObjectName("gridLayout_77");
        label_49 = new QLabel(tab_meteo);
        label_49->setObjectName("label_49");
        label_49->setFont(font8);

        gridLayout_77->addWidget(label_49, 0, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_77->addItem(verticalSpacer_6, 5, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_77->addItem(verticalSpacer_5, 4, 0, 1, 1);

        groupET = new QGroupBox(tab_meteo);
        groupET->setObjectName("groupET");
        groupET->setEnabled(true);
        sizePolicy2.setHeightForWidth(groupET->sizePolicy().hasHeightForWidth());
        groupET->setSizePolicy(sizePolicy2);
        groupET->setFont(font7);
        groupET->setCheckable(false);
        groupET->setChecked(false);
        gridLayout_60 = new QGridLayout(groupET);
        gridLayout_60->setObjectName("gridLayout_60");
        gridLayout_60->setHorizontalSpacing(8);
        gridLayout_60->setVerticalSpacing(4);
        gridLayout_60->setContentsMargins(8, 4, 8, 4);
        label_5 = new QLabel(groupET);
        label_5->setObjectName("label_5");
        label_5->setEnabled(true);
        label_5->setFont(font5);

        gridLayout_60->addWidget(label_5, 3, 0, 1, 2);

        E_biasCorrectionET = new QDoubleSpinBox(groupET);
        E_biasCorrectionET->setObjectName("E_biasCorrectionET");
        E_biasCorrectionET->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_biasCorrectionET->sizePolicy().hasHeightForWidth());
        E_biasCorrectionET->setSizePolicy(sizePolicy4);
        E_biasCorrectionET->setFont(font5);
        E_biasCorrectionET->setSingleStep(0.010000000000000);
        E_biasCorrectionET->setValue(1.000000000000000);

        gridLayout_60->addWidget(E_biasCorrectionET, 1, 1, 1, 1);

        E_dayoftheYear = new QSpinBox(groupET);
        E_dayoftheYear->setObjectName("E_dayoftheYear");
        sizePolicy4.setHeightForWidth(E_dayoftheYear->sizePolicy().hasHeightForWidth());
        E_dayoftheYear->setSizePolicy(sizePolicy4);
        E_dayoftheYear->setFont(font5);
        E_dayoftheYear->setMinimum(1);
        E_dayoftheYear->setMaximum(366);
        E_dayoftheYear->setValue(1);

        gridLayout_60->addWidget(E_dayoftheYear, 4, 2, 1, 1);

        label_57 = new QLabel(groupET);
        label_57->setObjectName("label_57");
        label_57->setEnabled(true);
        sizePolicy3.setHeightForWidth(label_57->sizePolicy().hasHeightForWidth());
        label_57->setSizePolicy(sizePolicy3);
        label_57->setFont(font5);

        gridLayout_60->addWidget(label_57, 6, 0, 1, 3);

        checkDailyET = new QCheckBox(groupET);
        checkDailyET->setObjectName("checkDailyET");
        checkDailyET->setEnabled(true);
        sizePolicy4.setHeightForWidth(checkDailyET->sizePolicy().hasHeightForWidth());
        checkDailyET->setSizePolicy(sizePolicy4);
        checkDailyET->setFont(font5);
        checkDailyET->setChecked(true);

        gridLayout_60->addWidget(checkDailyET, 2, 0, 1, 4);

        label_63 = new QLabel(groupET);
        label_63->setObjectName("label_63");
        label_63->setFont(font5);

        gridLayout_60->addWidget(label_63, 4, 0, 1, 1);

        E_rainfallETA_threshold = new QDoubleSpinBox(groupET);
        E_rainfallETA_threshold->setObjectName("E_rainfallETA_threshold");
        E_rainfallETA_threshold->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_rainfallETA_threshold->sizePolicy().hasHeightForWidth());
        E_rainfallETA_threshold->setSizePolicy(sizePolicy4);
        E_rainfallETA_threshold->setFont(font5);
        E_rainfallETA_threshold->setDecimals(1);
        E_rainfallETA_threshold->setMinimum(0.000000000000000);
        E_rainfallETA_threshold->setMaximum(10.000000000000000);
        E_rainfallETA_threshold->setSingleStep(0.100000000000000);
        E_rainfallETA_threshold->setValue(1.000000000000000);

        gridLayout_60->addWidget(E_rainfallETA_threshold, 6, 3, 1, 1);

        E_latitude = new QLineEdit(groupET);
        E_latitude->setObjectName("E_latitude");
        E_latitude->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_latitude->sizePolicy().hasHeightForWidth());
        E_latitude->setSizePolicy(sizePolicy4);
        E_latitude->setFont(font5);

        gridLayout_60->addWidget(E_latitude, 3, 2, 1, 1);

        label_126 = new QLabel(groupET);
        label_126->setObjectName("label_126");
        label_126->setEnabled(true);
        sizePolicy3.setHeightForWidth(label_126->sizePolicy().hasHeightForWidth());
        label_126->setSizePolicy(sizePolicy3);
        label_126->setFont(font5);
        label_126->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_60->addWidget(label_126, 1, 0, 1, 1);

        gridLayout_47 = new QGridLayout();
        gridLayout_47->setSpacing(0);
        gridLayout_47->setObjectName("gridLayout_47");
        radioETfile = new QRadioButton(groupET);
        radioETfile->setObjectName("radioETfile");
        radioETfile->setEnabled(true);
        sizePolicy4.setHeightForWidth(radioETfile->sizePolicy().hasHeightForWidth());
        radioETfile->setSizePolicy(sizePolicy4);
        radioETfile->setFont(font5);
        radioETfile->setChecked(true);

        gridLayout_47->addWidget(radioETfile, 0, 0, 1, 1);

        E_ETName = new QLineEdit(groupET);
        E_ETName->setObjectName("E_ETName");
        E_ETName->setEnabled(true);
        sizePolicy2.setHeightForWidth(E_ETName->sizePolicy().hasHeightForWidth());
        E_ETName->setSizePolicy(sizePolicy2);
        E_ETName->setFont(font5);

        gridLayout_47->addWidget(E_ETName, 0, 1, 1, 1);

        toolButton_ETName = new QToolButton(groupET);
        toolButton_ETName->setObjectName("toolButton_ETName");
        toolButton_ETName->setEnabled(true);
        toolButton_ETName->setFont(font5);
        toolButton_ETName->setIcon(icon1);

        gridLayout_47->addWidget(toolButton_ETName, 0, 2, 1, 1);

        toolButton_ETShow = new QToolButton(groupET);
        toolButton_ETShow->setObjectName("toolButton_ETShow");
        toolButton_ETShow->setEnabled(true);
        toolButton_ETShow->setFont(font5);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/2X/onewfile2X.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ETShow->setIcon(icon5);

        gridLayout_47->addWidget(toolButton_ETShow, 0, 3, 1, 1);

        radioETSatfile = new QRadioButton(groupET);
        radioETSatfile->setObjectName("radioETSatfile");
        radioETSatfile->setEnabled(true);
        sizePolicy4.setHeightForWidth(radioETSatfile->sizePolicy().hasHeightForWidth());
        radioETSatfile->setSizePolicy(sizePolicy4);
        radioETSatfile->setFont(font5);

        gridLayout_47->addWidget(radioETSatfile, 1, 0, 1, 1);

        E_ETsatName = new QLineEdit(groupET);
        E_ETsatName->setObjectName("E_ETsatName");
        E_ETsatName->setEnabled(false);
        sizePolicy2.setHeightForWidth(E_ETsatName->sizePolicy().hasHeightForWidth());
        E_ETsatName->setSizePolicy(sizePolicy2);
        E_ETsatName->setFont(font5);

        gridLayout_47->addWidget(E_ETsatName, 1, 1, 1, 1);

        toolButton_ETsatName = new QToolButton(groupET);
        toolButton_ETsatName->setObjectName("toolButton_ETsatName");
        toolButton_ETsatName->setEnabled(false);
        toolButton_ETsatName->setIcon(icon1);

        gridLayout_47->addWidget(toolButton_ETsatName, 1, 2, 1, 1);

        toolButton_ETmapShow = new QToolButton(groupET);
        toolButton_ETmapShow->setObjectName("toolButton_ETmapShow");
        toolButton_ETmapShow->setEnabled(false);
        toolButton_ETmapShow->setIcon(icon5);

        gridLayout_47->addWidget(toolButton_ETmapShow, 1, 3, 1, 1);


        gridLayout_60->addLayout(gridLayout_47, 0, 0, 1, 4);

        E_longtimestep = new QLineEdit(groupET);
        E_longtimestep->setObjectName("E_longtimestep");
        sizePolicy4.setHeightForWidth(E_longtimestep->sizePolicy().hasHeightForWidth());
        E_longtimestep->setSizePolicy(sizePolicy4);
        E_longtimestep->setFont(font5);

        gridLayout_60->addWidget(E_longtimestep, 5, 2, 1, 1);

        label_118 = new QLabel(groupET);
        label_118->setObjectName("label_118");
        label_118->setFont(font5);

        gridLayout_60->addWidget(label_118, 5, 0, 1, 1);


        gridLayout_77->addWidget(groupET, 3, 0, 1, 1);

        toolButton_helpRainfall = new QToolButton(tab_meteo);
        toolButton_helpRainfall->setObjectName("toolButton_helpRainfall");
        toolButton_helpRainfall->setIcon(icon3);

        gridLayout_77->addWidget(toolButton_helpRainfall, 0, 3, 1, 1);

        groupRainfall = new QGroupBox(tab_meteo);
        groupRainfall->setObjectName("groupRainfall");
        groupRainfall->setEnabled(true);
        sizePolicy2.setHeightForWidth(groupRainfall->sizePolicy().hasHeightForWidth());
        groupRainfall->setSizePolicy(sizePolicy2);
        groupRainfall->setFont(font7);
        groupRainfall->setCheckable(false);
        gridLayout_50 = new QGridLayout(groupRainfall);
        gridLayout_50->setObjectName("gridLayout_50");
        gridLayout_50->setHorizontalSpacing(8);
        gridLayout_50->setVerticalSpacing(4);
        gridLayout_50->setContentsMargins(8, 4, 8, 4);
        checkEventBased = new QCheckBox(groupRainfall);
        checkEventBased->setObjectName("checkEventBased");
        sizePolicy2.setHeightForWidth(checkEventBased->sizePolicy().hasHeightForWidth());
        checkEventBased->setSizePolicy(sizePolicy2);
        checkEventBased->setFont(font5);
        checkEventBased->setChecked(false);

        gridLayout_50->addWidget(checkEventBased, 3, 1, 1, 1);

        label_98 = new QLabel(groupRainfall);
        label_98->setObjectName("label_98");
        sizePolicy3.setHeightForWidth(label_98->sizePolicy().hasHeightForWidth());
        label_98->setSizePolicy(sizePolicy3);

        gridLayout_50->addWidget(label_98, 3, 0, 1, 1);

        frame_3 = new QFrame(groupRainfall);
        frame_3->setObjectName("frame_3");
        frame_3->setFont(font5);
        frame_3->setFrameShape(QFrame::Shape::HLine);
        frame_3->setFrameShadow(QFrame::Shadow::Sunken);
        frame_3->setLineWidth(1);

        gridLayout_50->addWidget(frame_3, 4, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        radioRainFile = new QRadioButton(groupRainfall);
        radioRainFile->setObjectName("radioRainFile");
        sizePolicy4.setHeightForWidth(radioRainFile->sizePolicy().hasHeightForWidth());
        radioRainFile->setSizePolicy(sizePolicy4);
        radioRainFile->setFont(font5);
        radioRainFile->setChecked(true);

        horizontalLayout_3->addWidget(radioRainFile);

        E_RainfallName = new QLineEdit(groupRainfall);
        E_RainfallName->setObjectName("E_RainfallName");
        sizePolicy2.setHeightForWidth(E_RainfallName->sizePolicy().hasHeightForWidth());
        E_RainfallName->setSizePolicy(sizePolicy2);
        E_RainfallName->setFont(font5);

        horizontalLayout_3->addWidget(E_RainfallName);

        toolButton_RainfallName = new QToolButton(groupRainfall);
        toolButton_RainfallName->setObjectName("toolButton_RainfallName");
        toolButton_RainfallName->setEnabled(true);
        sizePolicy4.setHeightForWidth(toolButton_RainfallName->sizePolicy().hasHeightForWidth());
        toolButton_RainfallName->setSizePolicy(sizePolicy4);
        toolButton_RainfallName->setIcon(icon1);
        toolButton_RainfallName->setAutoRaise(false);

        horizontalLayout_3->addWidget(toolButton_RainfallName);

        toolButton_RainfallShow = new QToolButton(groupRainfall);
        toolButton_RainfallShow->setObjectName("toolButton_RainfallShow");
        toolButton_RainfallShow->setEnabled(true);
        sizePolicy4.setHeightForWidth(toolButton_RainfallShow->sizePolicy().hasHeightForWidth());
        toolButton_RainfallShow->setSizePolicy(sizePolicy4);
        toolButton_RainfallShow->setIcon(icon5);
        toolButton_RainfallShow->setAutoRaise(false);

        horizontalLayout_3->addWidget(toolButton_RainfallShow);


        gridLayout_50->addLayout(horizontalLayout_3, 0, 0, 1, 2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_149 = new QLabel(groupRainfall);
        label_149->setObjectName("label_149");
        sizePolicy3.setHeightForWidth(label_149->sizePolicy().hasHeightForWidth());
        label_149->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(label_149);

        checkIDinterpolation = new QCheckBox(groupRainfall);
        checkIDinterpolation->setObjectName("checkIDinterpolation");
        checkIDinterpolation->setFont(font5);
        checkIDinterpolation->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        horizontalLayout_9->addWidget(checkIDinterpolation);

        E_IDIfactor = new QDoubleSpinBox(groupRainfall);
        E_IDIfactor->setObjectName("E_IDIfactor");
        sizePolicy4.setHeightForWidth(E_IDIfactor->sizePolicy().hasHeightForWidth());
        E_IDIfactor->setSizePolicy(sizePolicy4);
        E_IDIfactor->setFont(font5);
        E_IDIfactor->setDecimals(1);
        E_IDIfactor->setMaximum(9.000000000000000);
        E_IDIfactor->setSingleStep(0.100000000000000);
        E_IDIfactor->setValue(1.000000000000000);

        horizontalLayout_9->addWidget(E_IDIfactor);


        gridLayout_50->addLayout(horizontalLayout_9, 1, 0, 1, 2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        radioRainSatFile = new QRadioButton(groupRainfall);
        radioRainSatFile->setObjectName("radioRainSatFile");
        sizePolicy4.setHeightForWidth(radioRainSatFile->sizePolicy().hasHeightForWidth());
        radioRainSatFile->setSizePolicy(sizePolicy4);
        radioRainSatFile->setFont(font5);

        horizontalLayout_8->addWidget(radioRainSatFile);

        E_RainsatName = new QLineEdit(groupRainfall);
        E_RainsatName->setObjectName("E_RainsatName");
        E_RainsatName->setEnabled(false);
        sizePolicy2.setHeightForWidth(E_RainsatName->sizePolicy().hasHeightForWidth());
        E_RainsatName->setSizePolicy(sizePolicy2);
        E_RainsatName->setFont(font5);

        horizontalLayout_8->addWidget(E_RainsatName);

        toolButton_rainsatName = new QToolButton(groupRainfall);
        toolButton_rainsatName->setObjectName("toolButton_rainsatName");
        toolButton_rainsatName->setEnabled(false);
        toolButton_rainsatName->setFont(font5);
        toolButton_rainsatName->setIcon(icon1);

        horizontalLayout_8->addWidget(toolButton_rainsatName);

        toolButton_RainmapShow = new QToolButton(groupRainfall);
        toolButton_RainmapShow->setObjectName("toolButton_RainmapShow");
        toolButton_RainmapShow->setEnabled(false);
        toolButton_RainmapShow->setIcon(icon5);

        horizontalLayout_8->addWidget(toolButton_RainmapShow);


        gridLayout_50->addLayout(horizontalLayout_8, 5, 0, 1, 2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_121 = new QLabel(groupRainfall);
        label_121->setObjectName("label_121");
        label_121->setEnabled(true);
        sizePolicy3.setHeightForWidth(label_121->sizePolicy().hasHeightForWidth());
        label_121->setSizePolicy(sizePolicy3);
        label_121->setFont(font5);
        label_121->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_7->addWidget(label_121);

        E_biasCorrectionP = new QDoubleSpinBox(groupRainfall);
        E_biasCorrectionP->setObjectName("E_biasCorrectionP");
        E_biasCorrectionP->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_biasCorrectionP->sizePolicy().hasHeightForWidth());
        E_biasCorrectionP->setSizePolicy(sizePolicy4);
        E_biasCorrectionP->setFont(font5);
        E_biasCorrectionP->setMinimum(0.010000000000000);
        E_biasCorrectionP->setSingleStep(0.010000000000000);
        E_biasCorrectionP->setValue(1.000000000000000);

        horizontalLayout_7->addWidget(E_biasCorrectionP);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        gridLayout_50->addLayout(horizontalLayout_7, 6, 0, 1, 2);


        gridLayout_77->addWidget(groupRainfall, 1, 0, 2, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_77->addItem(verticalSpacer_7, 2, 2, 4, 1);

        toolButton_resetRainfall = new QToolButton(tab_meteo);
        toolButton_resetRainfall->setObjectName("toolButton_resetRainfall");
        toolButton_resetRainfall->setIcon(icon2);

        gridLayout_77->addWidget(toolButton_resetRainfall, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_77->addItem(horizontalSpacer_4, 1, 4, 1, 1);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/rain.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_meteo, icon6, QString());
        tab_interc = new QWidget();
        tab_interc->setObjectName("tab_interc");
        gridLayout_58 = new QGridLayout(tab_interc);
        gridLayout_58->setObjectName("gridLayout_58");
        groupInterception = new QGroupBox(tab_interc);
        groupInterception->setObjectName("groupInterception");
        sizePolicy2.setHeightForWidth(groupInterception->sizePolicy().hasHeightForWidth());
        groupInterception->setSizePolicy(sizePolicy2);
        groupInterception->setFont(font8);
        groupInterception->setCheckable(false);
        gridLayout_5 = new QGridLayout(groupInterception);
        gridLayout_5->setObjectName("gridLayout_5");
        checkIncludeLitter = new QCheckBox(groupInterception);
        checkIncludeLitter->setObjectName("checkIncludeLitter");
        sizePolicy4.setHeightForWidth(checkIncludeLitter->sizePolicy().hasHeightForWidth());
        checkIncludeLitter->setSizePolicy(sizePolicy4);
        checkIncludeLitter->setFont(font5);

        gridLayout_5->addWidget(checkIncludeLitter, 1, 0, 1, 1);

        label_133 = new QLabel(groupInterception);
        label_133->setObjectName("label_133");
        sizePolicy3.setHeightForWidth(label_133->sizePolicy().hasHeightForWidth());
        label_133->setSizePolicy(sizePolicy3);
        label_133->setFont(font5);

        gridLayout_5->addWidget(label_133, 1, 2, 1, 1);

        groupCanopyStrorage = new QGroupBox(groupInterception);
        groupCanopyStrorage->setObjectName("groupCanopyStrorage");
        groupCanopyStrorage->setFont(font7);
        groupCanopyStrorage->setFlat(false);
        groupCanopyStrorage->setCheckable(false);
        gridLayout_28 = new QGridLayout(groupCanopyStrorage);
        gridLayout_28->setObjectName("gridLayout_28");
        gridLayout_28->setHorizontalSpacing(8);
        gridLayout_28->setVerticalSpacing(4);
        gridLayout_28->setContentsMargins(8, 4, 8, 4);
        radioButton_1 = new QRadioButton(groupCanopyStrorage);
        radioButton_1->setObjectName("radioButton_1");
        radioButton_1->setFont(font5);
        radioButton_1->setChecked(false);

        gridLayout_28->addWidget(radioButton_1, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupCanopyStrorage);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setFont(font5);

        gridLayout_28->addWidget(radioButton_2, 1, 0, 1, 1);

        radioButton_3 = new QRadioButton(groupCanopyStrorage);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setFont(font5);

        gridLayout_28->addWidget(radioButton_3, 2, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupCanopyStrorage);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setFont(font5);

        gridLayout_28->addWidget(radioButton_4, 3, 0, 1, 1);

        radioButton_5 = new QRadioButton(groupCanopyStrorage);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setFont(font5);

        gridLayout_28->addWidget(radioButton_5, 4, 0, 1, 1);

        radioButton_6 = new QRadioButton(groupCanopyStrorage);
        radioButton_6->setObjectName("radioButton_6");
        radioButton_6->setFont(font5);

        gridLayout_28->addWidget(radioButton_6, 5, 0, 1, 1);

        radioButton_7 = new QRadioButton(groupCanopyStrorage);
        radioButton_7->setObjectName("radioButton_7");
        radioButton_7->setFont(font5);

        gridLayout_28->addWidget(radioButton_7, 6, 0, 1, 1);

        radioButton_8 = new QRadioButton(groupCanopyStrorage);
        radioButton_8->setObjectName("radioButton_8");
        radioButton_8->setFont(font5);

        gridLayout_28->addWidget(radioButton_8, 7, 0, 1, 1);

        line_2 = new QFrame(groupCanopyStrorage);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_28->addWidget(line_2, 8, 0, 1, 1);

        radioButton_9 = new QRadioButton(groupCanopyStrorage);
        radioButton_9->setObjectName("radioButton_9");
        radioButton_9->setFont(font5);
        radioButton_9->setChecked(true);

        gridLayout_28->addWidget(radioButton_9, 9, 0, 1, 1);


        gridLayout_5->addWidget(groupCanopyStrorage, 2, 0, 1, 3);

        E_LitterSmax = new QDoubleSpinBox(groupInterception);
        E_LitterSmax->setObjectName("E_LitterSmax");
        sizePolicy4.setHeightForWidth(E_LitterSmax->sizePolicy().hasHeightForWidth());
        E_LitterSmax->setSizePolicy(sizePolicy4);
        E_LitterSmax->setFont(font5);
        E_LitterSmax->setDecimals(1);
        E_LitterSmax->setSingleStep(0.100000000000000);
        E_LitterSmax->setValue(1.000000000000000);

        gridLayout_5->addWidget(E_LitterSmax, 1, 1, 1, 1);


        gridLayout_58->addWidget(groupInterception, 0, 0, 2, 1);

        toolButton_resetInterception = new QToolButton(tab_interc);
        toolButton_resetInterception->setObjectName("toolButton_resetInterception");
        toolButton_resetInterception->setIcon(icon2);

        gridLayout_58->addWidget(toolButton_resetInterception, 0, 2, 1, 1);

        toolButton_helpInterception = new QToolButton(tab_interc);
        toolButton_helpInterception->setObjectName("toolButton_helpInterception");
        toolButton_helpInterception->setIcon(icon3);

        gridLayout_58->addWidget(toolButton_helpInterception, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_58->addItem(verticalSpacer, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_58->addItem(horizontalSpacer, 0, 4, 1, 1);

        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Plant-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_interc, icon7, QString());
        tab_infil = new QWidget();
        tab_infil->setObjectName("tab_infil");
        gridLayout_57 = new QGridLayout(tab_infil);
        gridLayout_57->setObjectName("gridLayout_57");
        toolButton_helpInfiltration = new QToolButton(tab_infil);
        toolButton_helpInfiltration->setObjectName("toolButton_helpInfiltration");
        toolButton_helpInfiltration->setIcon(icon3);

        gridLayout_57->addWidget(toolButton_helpInfiltration, 0, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(543, 166, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_57->addItem(verticalSpacer_3, 2, 0, 1, 1);

        groupInfiltration = new QGroupBox(tab_infil);
        groupInfiltration->setObjectName("groupInfiltration");
        sizePolicy2.setHeightForWidth(groupInfiltration->sizePolicy().hasHeightForWidth());
        groupInfiltration->setSizePolicy(sizePolicy2);
        groupInfiltration->setFont(font8);
        groupInfiltration->setCheckable(false);
        gridLayout_52 = new QGridLayout(groupInfiltration);
        gridLayout_52->setObjectName("gridLayout_52");
        groupBox_InfilOptions = new QGroupBox(groupInfiltration);
        groupBox_InfilOptions->setObjectName("groupBox_InfilOptions");
        sizePolicy2.setHeightForWidth(groupBox_InfilOptions->sizePolicy().hasHeightForWidth());
        groupBox_InfilOptions->setSizePolicy(sizePolicy2);
        groupBox_InfilOptions->setFont(font7);
        gridLayout_2 = new QGridLayout(groupBox_InfilOptions);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(8);
        gridLayout_2->setVerticalSpacing(4);
        gridLayout_2->setContentsMargins(8, 4, 8, 4);
        checkInfilImpermeable = new QCheckBox(groupBox_InfilOptions);
        checkInfilImpermeable->setObjectName("checkInfilImpermeable");
        sizePolicy2.setHeightForWidth(checkInfilImpermeable->sizePolicy().hasHeightForWidth());
        checkInfilImpermeable->setSizePolicy(sizePolicy2);
        checkInfilImpermeable->setFont(font5);

        gridLayout_2->addWidget(checkInfilImpermeable, 0, 0, 1, 4);

        spinSoilLayers = new QSpinBox(groupBox_InfilOptions);
        spinSoilLayers->setObjectName("spinSoilLayers");
        sizePolicy4.setHeightForWidth(spinSoilLayers->sizePolicy().hasHeightForWidth());
        spinSoilLayers->setSizePolicy(sizePolicy4);
        spinSoilLayers->setFont(font5);
        spinSoilLayers->setMinimum(1);
        spinSoilLayers->setMaximum(3);
        spinSoilLayers->setSingleStep(1);
        spinSoilLayers->setValue(2);

        gridLayout_2->addWidget(spinSoilLayers, 9, 0, 1, 1);

        checkDynamicCrusting = new QCheckBox(groupBox_InfilOptions);
        checkDynamicCrusting->setObjectName("checkDynamicCrusting");
        checkDynamicCrusting->setEnabled(false);
        checkDynamicCrusting->setFont(font5);

        gridLayout_2->addWidget(checkDynamicCrusting, 6, 2, 1, 2);

        checkIncludeTiledrains = new QCheckBox(groupBox_InfilOptions);
        checkIncludeTiledrains->setObjectName("checkIncludeTiledrains");
        checkIncludeTiledrains->setEnabled(true);
        sizePolicy2.setHeightForWidth(checkIncludeTiledrains->sizePolicy().hasHeightForWidth());
        checkIncludeTiledrains->setSizePolicy(sizePolicy2);
        checkIncludeTiledrains->setFont(font5);

        gridLayout_2->addWidget(checkIncludeTiledrains, 2, 0, 1, 4);

        checkInfilCompact = new QCheckBox(groupBox_InfilOptions);
        checkInfilCompact->setObjectName("checkInfilCompact");
        sizePolicy2.setHeightForWidth(checkInfilCompact->sizePolicy().hasHeightForWidth());
        checkInfilCompact->setSizePolicy(sizePolicy2);
        checkInfilCompact->setFont(font5);

        gridLayout_2->addWidget(checkInfilCompact, 4, 0, 1, 4);

        label_153 = new QLabel(groupBox_InfilOptions);
        label_153->setObjectName("label_153");
        sizePolicy3.setHeightForWidth(label_153->sizePolicy().hasHeightForWidth());
        label_153->setSizePolicy(sizePolicy3);
        label_153->setFont(font5);

        gridLayout_2->addWidget(label_153, 9, 1, 1, 3);

        checkInfilCrust = new QCheckBox(groupBox_InfilOptions);
        checkInfilCrust->setObjectName("checkInfilCrust");
        sizePolicy2.setHeightForWidth(checkInfilCrust->sizePolicy().hasHeightForWidth());
        checkInfilCrust->setSizePolicy(sizePolicy2);
        checkInfilCrust->setFont(font5);

        gridLayout_2->addWidget(checkInfilCrust, 6, 0, 1, 2);


        gridLayout_52->addWidget(groupBox_InfilOptions, 1, 0, 1, 1);

        groupBox_SwatreOptions = new QGroupBox(groupInfiltration);
        groupBox_SwatreOptions->setObjectName("groupBox_SwatreOptions");
        groupBox_SwatreOptions->setEnabled(true);
        sizePolicy2.setHeightForWidth(groupBox_SwatreOptions->sizePolicy().hasHeightForWidth());
        groupBox_SwatreOptions->setSizePolicy(sizePolicy2);
        groupBox_SwatreOptions->setFont(font7);
        gridLayout = new QGridLayout(groupBox_SwatreOptions);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(8);
        gridLayout->setVerticalSpacing(4);
        gridLayout->setContentsMargins(8, 4, 8, 4);
        label_159 = new QLabel(groupBox_SwatreOptions);
        label_159->setObjectName("label_159");
        sizePolicy2.setHeightForWidth(label_159->sizePolicy().hasHeightForWidth());
        label_159->setSizePolicy(sizePolicy2);
        label_159->setFont(font5);

        gridLayout->addWidget(label_159, 4, 0, 1, 2);

        checkInfilHinit = new QCheckBox(groupBox_SwatreOptions);
        checkInfilHinit->setObjectName("checkInfilHinit");
        checkInfilHinit->setFont(font5);

        gridLayout->addWidget(checkInfilHinit, 2, 0, 1, 2);

        checkSwatreOutput = new QCheckBox(groupBox_SwatreOptions);
        checkSwatreOutput->setObjectName("checkSwatreOutput");
        checkSwatreOutput->setFont(font5);

        gridLayout->addWidget(checkSwatreOutput, 1, 0, 1, 6);

        E_SWATREDtsec = new QDoubleSpinBox(groupBox_SwatreOptions);
        E_SWATREDtsec->setObjectName("E_SWATREDtsec");
        sizePolicy4.setHeightForWidth(E_SWATREDtsec->sizePolicy().hasHeightForWidth());
        E_SWATREDtsec->setSizePolicy(sizePolicy4);
        E_SWATREDtsec->setFont(font5);
        E_SWATREDtsec->setDecimals(1);
        E_SWATREDtsec->setMinimum(1.000000000000000);
        E_SWATREDtsec->setMaximum(600.000000000000000);
        E_SWATREDtsec->setSingleStep(0.100000000000000);
        E_SWATREDtsec->setValue(2.000000000000000);

        gridLayout->addWidget(E_SWATREDtsec, 4, 2, 1, 1);

        spinHinit = new QDoubleSpinBox(groupBox_SwatreOptions);
        spinHinit->setObjectName("spinHinit");
        sizePolicy4.setHeightForWidth(spinHinit->sizePolicy().hasHeightForWidth());
        spinHinit->setSizePolicy(sizePolicy4);
        spinHinit->setFont(font5);
        spinHinit->setDecimals(1);
        spinHinit->setMinimum(-20000.000000000000000);
        spinHinit->setMaximum(0.000000000000000);
        spinHinit->setSingleStep(0.100000000000000);
        spinHinit->setValue(-100.000000000000000);

        gridLayout->addWidget(spinHinit, 2, 2, 1, 1);

        checkSwatreDry = new QCheckBox(groupBox_SwatreOptions);
        checkSwatreDry->setObjectName("checkSwatreDry");
        checkSwatreDry->setFont(font5);

        gridLayout->addWidget(checkSwatreDry, 3, 0, 1, 6);

        label_86 = new QLabel(groupBox_SwatreOptions);
        label_86->setObjectName("label_86");
        label_86->setFont(font5);

        gridLayout->addWidget(label_86, 7, 0, 1, 1);

        E_SwatreTableName = new QLineEdit(groupBox_SwatreOptions);
        E_SwatreTableName->setObjectName("E_SwatreTableName");
        E_SwatreTableName->setFont(font5);

        gridLayout->addWidget(E_SwatreTableName, 7, 1, 1, 2);

        toolButton_SwatreTableDir = new QToolButton(groupBox_SwatreOptions);
        toolButton_SwatreTableDir->setObjectName("toolButton_SwatreTableDir");
        toolButton_SwatreTableDir->setEnabled(true);
        toolButton_SwatreTableDir->setIcon(icon1);

        gridLayout->addWidget(toolButton_SwatreTableDir, 8, 3, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 7, 5, 1, 1);

        toolButton_SwatreTableName = new QToolButton(groupBox_SwatreOptions);
        toolButton_SwatreTableName->setObjectName("toolButton_SwatreTableName");
        toolButton_SwatreTableName->setIcon(icon1);

        gridLayout->addWidget(toolButton_SwatreTableName, 7, 3, 1, 1);

        label_13 = new QLabel(groupBox_SwatreOptions);
        label_13->setObjectName("label_13");
        label_13->setEnabled(true);
        label_13->setFont(font5);
        label_13->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_13, 8, 0, 1, 1);

        E_SwatreTableDir = new QLineEdit(groupBox_SwatreOptions);
        E_SwatreTableDir->setObjectName("E_SwatreTableDir");
        E_SwatreTableDir->setEnabled(true);
        E_SwatreTableDir->setFont(font5);

        gridLayout->addWidget(E_SwatreTableDir, 8, 1, 1, 2);

        toolButton_SwatreTableShow = new QToolButton(groupBox_SwatreOptions);
        toolButton_SwatreTableShow->setObjectName("toolButton_SwatreTableShow");
        toolButton_SwatreTableShow->setEnabled(true);
        toolButton_SwatreTableShow->setIcon(icon5);

        gridLayout->addWidget(toolButton_SwatreTableShow, 7, 4, 1, 1);

        spinSwatrePrecision = new QSpinBox(groupBox_SwatreOptions);
        spinSwatrePrecision->setObjectName("spinSwatrePrecision");
        sizePolicy4.setHeightForWidth(spinSwatrePrecision->sizePolicy().hasHeightForWidth());
        spinSwatrePrecision->setSizePolicy(sizePolicy4);
        spinSwatrePrecision->setFont(font5);
        spinSwatrePrecision->setMinimum(3);
        spinSwatrePrecision->setMaximum(15);
        spinSwatrePrecision->setValue(6);

        gridLayout->addWidget(spinSwatrePrecision, 5, 2, 1, 1);

        label_144 = new QLabel(groupBox_SwatreOptions);
        label_144->setObjectName("label_144");
        sizePolicy3.setHeightForWidth(label_144->sizePolicy().hasHeightForWidth());
        label_144->setSizePolicy(sizePolicy3);
        label_144->setFont(font5);

        gridLayout->addWidget(label_144, 5, 0, 1, 2);


        gridLayout_52->addWidget(groupBox_SwatreOptions, 3, 0, 1, 1);

        E_InfiltrationMethod = new QComboBox(groupInfiltration);
        E_InfiltrationMethod->setObjectName("E_InfiltrationMethod");
        sizePolicy6.setHeightForWidth(E_InfiltrationMethod->sizePolicy().hasHeightForWidth());
        E_InfiltrationMethod->setSizePolicy(sizePolicy6);
        E_InfiltrationMethod->setFont(font5);

        gridLayout_52->addWidget(E_InfiltrationMethod, 0, 0, 1, 1);


        gridLayout_57->addWidget(groupInfiltration, 0, 0, 2, 1);

        toolButton_resetInfiltration = new QToolButton(tab_infil);
        toolButton_resetInfiltration->setObjectName("toolButton_resetInfiltration");
        toolButton_resetInfiltration->setIcon(icon2);

        gridLayout_57->addWidget(toolButton_resetInfiltration, 0, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_57->addItem(horizontalSpacer_11, 0, 5, 1, 1);

        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/soil5.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_infil, icon8, QString());
        tab_flooding = new QWidget();
        tab_flooding->setObjectName("tab_flooding");
        gridLayout_40 = new QGridLayout(tab_flooding);
        gridLayout_40->setObjectName("gridLayout_40");
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_40->addItem(verticalSpacer_8, 4, 0, 1, 2);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_40->addItem(horizontalSpacer_27, 0, 9, 3, 1);

        groupFloodParams = new QGroupBox(tab_flooding);
        groupFloodParams->setObjectName("groupFloodParams");
        groupFloodParams->setEnabled(true);
        sizePolicy2.setHeightForWidth(groupFloodParams->sizePolicy().hasHeightForWidth());
        groupFloodParams->setSizePolicy(sizePolicy2);
        QPalette palette5;
        groupFloodParams->setPalette(palette5);
        groupFloodParams->setFont(font7);
        gridLayout_3 = new QGridLayout(groupFloodParams);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setHorizontalSpacing(8);
        gridLayout_3->setVerticalSpacing(4);
        gridLayout_3->setContentsMargins(8, 4, 8, 4);
        E_courantFactor = new QDoubleSpinBox(groupFloodParams);
        E_courantFactor->setObjectName("E_courantFactor");
        E_courantFactor->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_courantFactor->sizePolicy().hasHeightForWidth());
        E_courantFactor->setSizePolicy(sizePolicy4);
        E_courantFactor->setFont(font5);
        E_courantFactor->setMinimum(0.010000000000000);
        E_courantFactor->setMaximum(1.000000000000000);
        E_courantFactor->setSingleStep(0.010000000000000);
        E_courantFactor->setValue(0.200000000000000);

        gridLayout_3->addWidget(E_courantFactor, 1, 3, 1, 1);

        label_197 = new QLabel(groupFloodParams);
        label_197->setObjectName("label_197");
        sizePolicy4.setHeightForWidth(label_197->sizePolicy().hasHeightForWidth());
        label_197->setSizePolicy(sizePolicy4);
        label_197->setFont(font5);
        label_197->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(label_197, 1, 4, 1, 1);

        E_TimestepMinFlood = new QDoubleSpinBox(groupFloodParams);
        E_TimestepMinFlood->setObjectName("E_TimestepMinFlood");
        sizePolicy4.setHeightForWidth(E_TimestepMinFlood->sizePolicy().hasHeightForWidth());
        E_TimestepMinFlood->setSizePolicy(sizePolicy4);
        E_TimestepMinFlood->setFont(font5);
        E_TimestepMinFlood->setDecimals(2);
        E_TimestepMinFlood->setMinimum(0.010000000000000);
        E_TimestepMinFlood->setMaximum(1000.000000000000000);
        E_TimestepMinFlood->setSingleStep(0.001000000000000);
        E_TimestepMinFlood->setValue(0.200000000000000);

        gridLayout_3->addWidget(E_TimestepMinFlood, 1, 5, 1, 1);

        label_84 = new QLabel(groupFloodParams);
        label_84->setObjectName("label_84");
        label_84->setEnabled(true);
        sizePolicy2.setHeightForWidth(label_84->sizePolicy().hasHeightForWidth());
        label_84->setSizePolicy(sizePolicy2);
        label_84->setFont(font5);
        label_84->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_84->setWordWrap(true);

        gridLayout_3->addWidget(label_84, 0, 1, 1, 7);

        checkMUSCL = new QCheckBox(groupFloodParams);
        checkMUSCL->setObjectName("checkMUSCL");
        sizePolicy4.setHeightForWidth(checkMUSCL->sizePolicy().hasHeightForWidth());
        checkMUSCL->setSizePolicy(sizePolicy4);
        checkMUSCL->setFont(font5);
        checkMUSCL->setChecked(true);

        gridLayout_3->addWidget(checkMUSCL, 3, 0, 1, 8);

        E_FlowBoundary = new QSpinBox(groupFloodParams);
        E_FlowBoundary->setObjectName("E_FlowBoundary");
        E_FlowBoundary->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_FlowBoundary->sizePolicy().hasHeightForWidth());
        E_FlowBoundary->setSizePolicy(sizePolicy4);
        E_FlowBoundary->setFont(font5);
        E_FlowBoundary->setMaximum(2);
        E_FlowBoundary->setSingleStep(1);
        E_FlowBoundary->setValue(1);

        gridLayout_3->addWidget(E_FlowBoundary, 0, 0, 1, 1);

        label_96 = new QLabel(groupFloodParams);
        label_96->setObjectName("label_96");
        sizePolicy4.setHeightForWidth(label_96->sizePolicy().hasHeightForWidth());
        label_96->setSizePolicy(sizePolicy4);
        label_96->setFont(font5);
        label_96->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(label_96, 1, 0, 1, 3);


        gridLayout_40->addWidget(groupFloodParams, 1, 0, 1, 5);

        groupWaveUser = new QGroupBox(tab_flooding);
        groupWaveUser->setObjectName("groupWaveUser");
        groupWaveUser->setEnabled(true);
        sizePolicy2.setHeightForWidth(groupWaveUser->sizePolicy().hasHeightForWidth());
        groupWaveUser->setSizePolicy(sizePolicy2);
        groupWaveUser->setFont(font7);
        groupWaveUser->setCheckable(false);
        gridLayout_72 = new QGridLayout(groupWaveUser);
        gridLayout_72->setObjectName("gridLayout_72");
        gridLayout_72->setHorizontalSpacing(8);
        gridLayout_72->setVerticalSpacing(4);
        gridLayout_72->setContentsMargins(8, 4, 8, 8);
        toolButton_WaveInName = new QToolButton(groupWaveUser);
        toolButton_WaveInName->setObjectName("toolButton_WaveInName");
        toolButton_WaveInName->setEnabled(false);
        toolButton_WaveInName->setFont(font5);
        toolButton_WaveInName->setIcon(icon1);

        gridLayout_72->addWidget(toolButton_WaveInName, 2, 2, 1, 1);

        E_WaveInName = new QLineEdit(groupWaveUser);
        E_WaveInName->setObjectName("E_WaveInName");
        E_WaveInName->setEnabled(false);
        E_WaveInName->setFont(font5);

        gridLayout_72->addWidget(E_WaveInName, 2, 1, 1, 1);

        label_148 = new QLabel(groupWaveUser);
        label_148->setObjectName("label_148");
        label_148->setEnabled(false);
        sizePolicy2.setHeightForWidth(label_148->sizePolicy().hasHeightForWidth());
        label_148->setSizePolicy(sizePolicy2);
        label_148->setFont(font5);

        gridLayout_72->addWidget(label_148, 3, 0, 1, 2);

        toolButton_WaveShow = new QToolButton(groupWaveUser);
        toolButton_WaveShow->setObjectName("toolButton_WaveShow");
        toolButton_WaveShow->setEnabled(false);
        toolButton_WaveShow->setFont(font5);
        toolButton_WaveShow->setIcon(icon5);

        gridLayout_72->addWidget(toolButton_WaveShow, 2, 3, 1, 1);

        checkFloodInitial = new QCheckBox(groupWaveUser);
        checkFloodInitial->setObjectName("checkFloodInitial");
        checkFloodInitial->setFont(font5);

        gridLayout_72->addWidget(checkFloodInitial, 0, 0, 1, 2);

        checkWaterUserIn = new QCheckBox(groupWaveUser);
        checkWaterUserIn->setObjectName("checkWaterUserIn");
        checkWaterUserIn->setFont(font5);

        gridLayout_72->addWidget(checkWaterUserIn, 2, 0, 1, 1);


        gridLayout_40->addWidget(groupWaveUser, 2, 0, 1, 5);

        toolButton_resetFlow = new QToolButton(tab_flooding);
        toolButton_resetFlow->setObjectName("toolButton_resetFlow");
        toolButton_resetFlow->setToolTipDuration(-5);
        toolButton_resetFlow->setIcon(icon2);

        gridLayout_40->addWidget(toolButton_resetFlow, 0, 7, 1, 1);

        label_88 = new QLabel(tab_flooding);
        label_88->setObjectName("label_88");
        sizePolicy2.setHeightForWidth(label_88->sizePolicy().hasHeightForWidth());
        label_88->setSizePolicy(sizePolicy2);
        label_88->setFont(font8);

        gridLayout_40->addWidget(label_88, 0, 0, 1, 1);

        toolButton_helpFlow = new QToolButton(tab_flooding);
        toolButton_helpFlow->setObjectName("toolButton_helpFlow");
        toolButton_helpFlow->setIcon(icon3);

        gridLayout_40->addWidget(toolButton_helpFlow, 0, 8, 1, 1);

        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/water2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_flooding, icon9, QString());
        tab_Channel = new QWidget();
        tab_Channel->setObjectName("tab_Channel");
        gridLayout_67 = new QGridLayout(tab_Channel);
        gridLayout_67->setObjectName("gridLayout_67");
        toolButton_resetChannel = new QToolButton(tab_Channel);
        toolButton_resetChannel->setObjectName("toolButton_resetChannel");
        toolButton_resetChannel->setIcon(icon2);

        gridLayout_67->addWidget(toolButton_resetChannel, 0, 2, 1, 1);

        groupBaseflowParams = new QGroupBox(tab_Channel);
        groupBaseflowParams->setObjectName("groupBaseflowParams");
        sizePolicy2.setHeightForWidth(groupBaseflowParams->sizePolicy().hasHeightForWidth());
        groupBaseflowParams->setSizePolicy(sizePolicy2);
        groupBaseflowParams->setFont(font7);
        gridLayout_66 = new QGridLayout(groupBaseflowParams);
        gridLayout_66->setObjectName("gridLayout_66");
        gridLayout_66->setHorizontalSpacing(8);
        gridLayout_66->setVerticalSpacing(4);
        gridLayout_66->setContentsMargins(8, 4, 8, 4);
        label_127 = new QLabel(groupBaseflowParams);
        label_127->setObjectName("label_127");
        label_127->setFont(font5);

        gridLayout_66->addWidget(label_127, 2, 0, 1, 1);

        label_155 = new QLabel(groupBaseflowParams);
        label_155->setObjectName("label_155");
        label_155->setFont(font5);

        gridLayout_66->addWidget(label_155, 0, 0, 1, 1);

        widget_GWparams = new QWidget(groupBaseflowParams);
        widget_GWparams->setObjectName("widget_GWparams");
        widget_GWparams->setEnabled(true);
        gridLayout_eros = new QGridLayout(widget_GWparams);
        gridLayout_eros->setObjectName("gridLayout_eros");
        gridLayout_eros->setHorizontalSpacing(8);
        gridLayout_eros->setVerticalSpacing(4);
        gridLayout_eros->setContentsMargins(8, 4, 8, 4);
        label_102 = new QLabel(widget_GWparams);
        label_102->setObjectName("label_102");
        label_102->setEnabled(true);
        sizePolicy4.setHeightForWidth(label_102->sizePolicy().hasHeightForWidth());
        label_102->setSizePolicy(sizePolicy4);
        label_102->setFont(font5);

        gridLayout_eros->addWidget(label_102, 5, 0, 1, 1);

        GW_threshold = new QDoubleSpinBox(widget_GWparams);
        GW_threshold->setObjectName("GW_threshold");
        GW_threshold->setEnabled(true);
        sizePolicy4.setHeightForWidth(GW_threshold->sizePolicy().hasHeightForWidth());
        GW_threshold->setSizePolicy(sizePolicy4);
        GW_threshold->setFont(font5);
        GW_threshold->setMaximum(10.000000000000000);
        GW_threshold->setSingleStep(0.010000000000000);
        GW_threshold->setValue(0.200000000000000);

        gridLayout_eros->addWidget(GW_threshold, 4, 1, 1, 1);

        label_108 = new QLabel(widget_GWparams);
        label_108->setObjectName("label_108");
        label_108->setEnabled(true);
        label_108->setFont(font5);

        gridLayout_eros->addWidget(label_108, 4, 0, 1, 1);

        GW_deep = new QDoubleSpinBox(widget_GWparams);
        GW_deep->setObjectName("GW_deep");
        GW_deep->setEnabled(true);
        sizePolicy4.setHeightForWidth(GW_deep->sizePolicy().hasHeightForWidth());
        GW_deep->setSizePolicy(sizePolicy4);
        GW_deep->setFont(font5);
        GW_deep->setDecimals(2);
        GW_deep->setMinimum(0.000000000000000);
        GW_deep->setMaximum(99.000000000000000);
        GW_deep->setSingleStep(0.010000000000000);
        GW_deep->setValue(0.000000000000000);

        gridLayout_eros->addWidget(GW_deep, 5, 1, 1, 1);

        GW_flow = new QDoubleSpinBox(widget_GWparams);
        GW_flow->setObjectName("GW_flow");
        GW_flow->setEnabled(true);
        sizePolicy4.setHeightForWidth(GW_flow->sizePolicy().hasHeightForWidth());
        GW_flow->setSizePolicy(sizePolicy4);
        GW_flow->setFont(font5);
        GW_flow->setMinimum(0.000000000000000);
        GW_flow->setSingleStep(0.010000000000000);
        GW_flow->setValue(1.000000000000000);

        gridLayout_eros->addWidget(GW_flow, 3, 1, 1, 1);

        label_97 = new QLabel(widget_GWparams);
        label_97->setObjectName("label_97");
        label_97->setEnabled(true);
        sizePolicy3.setHeightForWidth(label_97->sizePolicy().hasHeightForWidth());
        label_97->setSizePolicy(sizePolicy3);
        label_97->setFont(font5);

        gridLayout_eros->addWidget(label_97, 2, 2, 1, 1);

        label_77 = new QLabel(widget_GWparams);
        label_77->setObjectName("label_77");
        label_77->setEnabled(true);
        label_77->setFont(font5);

        gridLayout_eros->addWidget(label_77, 2, 0, 1, 1);

        GW_recharge = new QDoubleSpinBox(widget_GWparams);
        GW_recharge->setObjectName("GW_recharge");
        GW_recharge->setEnabled(true);
        sizePolicy4.setHeightForWidth(GW_recharge->sizePolicy().hasHeightForWidth());
        GW_recharge->setSizePolicy(sizePolicy4);
        GW_recharge->setFont(font5);
        GW_recharge->setMinimum(0.000000000000000);
        GW_recharge->setSingleStep(0.010000000000000);
        GW_recharge->setValue(1.000000000000000);

        gridLayout_eros->addWidget(GW_recharge, 2, 1, 1, 1);

        label_83 = new QLabel(widget_GWparams);
        label_83->setObjectName("label_83");
        label_83->setEnabled(true);
        label_83->setFont(font5);

        gridLayout_eros->addWidget(label_83, 3, 0, 1, 1);

        label_106 = new QLabel(widget_GWparams);
        label_106->setObjectName("label_106");
        label_106->setEnabled(true);
        label_106->setFont(font5);

        gridLayout_eros->addWidget(label_106, 3, 2, 1, 1);


        gridLayout_66->addWidget(widget_GWparams, 3, 0, 1, 1);

        GW_widget = new QWidget(groupBaseflowParams);
        GW_widget->setObjectName("GW_widget");
        gridLayout_24 = new QGridLayout(GW_widget);
        gridLayout_24->setObjectName("gridLayout_24");
        gridLayout_24->setHorizontalSpacing(8);
        gridLayout_24->setVerticalSpacing(4);
        gridLayout_24->setContentsMargins(16, 4, 8, 4);
        checkGWflowLDD = new QRadioButton(GW_widget);
        checkGWflowLDD->setObjectName("checkGWflowLDD");
        checkGWflowLDD->setEnabled(true);
        sizePolicy2.setHeightForWidth(checkGWflowLDD->sizePolicy().hasHeightForWidth());
        checkGWflowLDD->setSizePolicy(sizePolicy2);
        checkGWflowLDD->setFont(font5);
        checkGWflowLDD->setChecked(false);

        gridLayout_24->addWidget(checkGWflowLDD, 3, 0, 1, 1);

        checkGWflowSWAT = new QRadioButton(GW_widget);
        checkGWflowSWAT->setObjectName("checkGWflowSWAT");
        sizePolicy4.setHeightForWidth(checkGWflowSWAT->sizePolicy().hasHeightForWidth());
        checkGWflowSWAT->setSizePolicy(sizePolicy4);
        checkGWflowSWAT->setFont(font5);

        gridLayout_24->addWidget(checkGWflowSWAT, 7, 0, 1, 1);

        checkGWflowexplicit = new QRadioButton(GW_widget);
        checkGWflowexplicit->setObjectName("checkGWflowexplicit");
        checkGWflowexplicit->setEnabled(true);
        sizePolicy2.setHeightForWidth(checkGWflowexplicit->sizePolicy().hasHeightForWidth());
        checkGWflowexplicit->setSizePolicy(sizePolicy2);
        checkGWflowexplicit->setFont(font5);
        checkGWflowexplicit->setChecked(true);

        gridLayout_24->addWidget(checkGWflowexplicit, 1, 0, 1, 1);


        gridLayout_66->addWidget(GW_widget, 1, 0, 1, 1);


        gridLayout_67->addWidget(groupBaseflowParams, 3, 0, 1, 1);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_67->addItem(horizontalSpacer_28, 0, 4, 1, 1);

        label_156 = new QLabel(tab_Channel);
        label_156->setObjectName("label_156");
        label_156->setFont(font8);

        gridLayout_67->addWidget(label_156, 0, 0, 1, 1);

        groupChannelParams = new QGroupBox(tab_Channel);
        groupChannelParams->setObjectName("groupChannelParams");
        sizePolicy2.setHeightForWidth(groupChannelParams->sizePolicy().hasHeightForWidth());
        groupChannelParams->setSizePolicy(sizePolicy2);
        groupChannelParams->setFont(font7);
        gridLayout_78 = new QGridLayout(groupChannelParams);
        gridLayout_78->setObjectName("gridLayout_78");
        gridLayout_78->setHorizontalSpacing(8);
        gridLayout_78->setVerticalSpacing(4);
        gridLayout_78->setContentsMargins(8, 4, 8, 4);
        toolButton_DischargeShow = new QToolButton(groupChannelParams);
        toolButton_DischargeShow->setObjectName("toolButton_DischargeShow");
        toolButton_DischargeShow->setEnabled(false);
        toolButton_DischargeShow->setIcon(icon5);

        gridLayout_78->addWidget(toolButton_DischargeShow, 7, 6, 1, 1);

        checkChannelCulverts = new QCheckBox(groupChannelParams);
        checkChannelCulverts->setObjectName("checkChannelCulverts");
        checkChannelCulverts->setEnabled(true);
        sizePolicy2.setHeightForWidth(checkChannelCulverts->sizePolicy().hasHeightForWidth());
        checkChannelCulverts->setSizePolicy(sizePolicy2);
        checkChannelCulverts->setFont(font5);

        gridLayout_78->addWidget(checkChannelCulverts, 0, 0, 1, 7);

        E_DischargeInName = new QLineEdit(groupChannelParams);
        E_DischargeInName->setObjectName("E_DischargeInName");
        E_DischargeInName->setEnabled(false);
        sizePolicy2.setHeightForWidth(E_DischargeInName->sizePolicy().hasHeightForWidth());
        E_DischargeInName->setSizePolicy(sizePolicy2);
        E_DischargeInName->setFont(font5);

        gridLayout_78->addWidget(E_DischargeInName, 7, 2, 1, 3);

        E_CalibrateChTor = new QDoubleSpinBox(groupChannelParams);
        E_CalibrateChTor->setObjectName("E_CalibrateChTor");
        sizePolicy4.setHeightForWidth(E_CalibrateChTor->sizePolicy().hasHeightForWidth());
        E_CalibrateChTor->setSizePolicy(sizePolicy4);
        E_CalibrateChTor->setFont(font5);
        E_CalibrateChTor->setMinimum(1.000000000000000);
        E_CalibrateChTor->setMaximum(10.000000000000000);
        E_CalibrateChTor->setSingleStep(0.010000000000000);
        E_CalibrateChTor->setValue(1.000000000000000);

        gridLayout_78->addWidget(E_CalibrateChTor, 6, 1, 1, 3);

        checkDischargeUser = new QCheckBox(groupChannelParams);
        checkDischargeUser->setObjectName("checkDischargeUser");
        checkDischargeUser->setEnabled(true);
        sizePolicy4.setHeightForWidth(checkDischargeUser->sizePolicy().hasHeightForWidth());
        checkDischargeUser->setSizePolicy(sizePolicy4);
        QFont font9;
        font9.setPointSize(8);
        font9.setBold(false);
        font9.setUnderline(false);
        font9.setKerning(false);
        checkDischargeUser->setFont(font9);

        gridLayout_78->addWidget(checkDischargeUser, 7, 0, 1, 2);

        toolButton_DischargeName = new QToolButton(groupChannelParams);
        toolButton_DischargeName->setObjectName("toolButton_DischargeName");
        toolButton_DischargeName->setEnabled(false);
        toolButton_DischargeName->setIcon(icon1);

        gridLayout_78->addWidget(toolButton_DischargeName, 7, 5, 1, 1);

        label_87 = new QLabel(groupChannelParams);
        label_87->setObjectName("label_87");
        sizePolicy3.setHeightForWidth(label_87->sizePolicy().hasHeightForWidth());
        label_87->setSizePolicy(sizePolicy3);
        label_87->setFont(font5);

        gridLayout_78->addWidget(label_87, 6, 0, 1, 1);

        E_BaseflowMethod = new QComboBox(groupChannelParams);
        E_BaseflowMethod->addItem(QString());
        E_BaseflowMethod->addItem(QString());
        E_BaseflowMethod->addItem(QString());
        E_BaseflowMethod->addItem(QString());
        E_BaseflowMethod->setObjectName("E_BaseflowMethod");
        sizePolicy4.setHeightForWidth(E_BaseflowMethod->sizePolicy().hasHeightForWidth());
        E_BaseflowMethod->setSizePolicy(sizePolicy4);
        E_BaseflowMethod->setFont(font5);

        gridLayout_78->addWidget(E_BaseflowMethod, 1, 0, 1, 7);


        gridLayout_67->addWidget(groupChannelParams, 1, 0, 1, 1);

        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_67->addItem(verticalSpacer_16, 4, 0, 1, 1);

        toolButton_helpChannel = new QToolButton(tab_Channel);
        toolButton_helpChannel->setObjectName("toolButton_helpChannel");
        toolButton_helpChannel->setIcon(icon3);

        gridLayout_67->addWidget(toolButton_helpChannel, 0, 3, 1, 1);

        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/river4.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_Channel, icon10, QString());
        tab_Infra = new QWidget();
        tab_Infra->setObjectName("tab_Infra");
        gridLayout_79 = new QGridLayout(tab_Infra);
        gridLayout_79->setObjectName("gridLayout_79");
        toolButton_helpInfra = new QToolButton(tab_Infra);
        toolButton_helpInfra->setObjectName("toolButton_helpInfra");
        toolButton_helpInfra->setIcon(icon3);

        gridLayout_79->addWidget(toolButton_helpInfra, 0, 2, 1, 1);

        toolButton_resetInfra = new QToolButton(tab_Infra);
        toolButton_resetInfra->setObjectName("toolButton_resetInfra");
        toolButton_resetInfra->setIcon(icon2);

        gridLayout_79->addWidget(toolButton_resetInfra, 0, 1, 1, 1);

        groupMitigationWater = new QGroupBox(tab_Infra);
        groupMitigationWater->setObjectName("groupMitigationWater");
        groupMitigationWater->setEnabled(true);
        sizePolicy2.setHeightForWidth(groupMitigationWater->sizePolicy().hasHeightForWidth());
        groupMitigationWater->setSizePolicy(sizePolicy2);
        groupMitigationWater->setFont(font7);
        gridLayout_70 = new QGridLayout(groupMitigationWater);
        gridLayout_70->setObjectName("gridLayout_70");
        gridLayout_70->setHorizontalSpacing(8);
        gridLayout_70->setVerticalSpacing(4);
        gridLayout_70->setContentsMargins(8, 4, 8, 4);
        checkFlowBarriers = new QCheckBox(groupMitigationWater);
        checkFlowBarriers->setObjectName("checkFlowBarriers");
        checkFlowBarriers->setEnabled(true);
        sizePolicy2.setHeightForWidth(checkFlowBarriers->sizePolicy().hasHeightForWidth());
        checkFlowBarriers->setSizePolicy(sizePolicy2);
        checkFlowBarriers->setFont(font5);

        gridLayout_70->addWidget(checkFlowBarriers, 1, 0, 1, 1);

        E_GrassStripN = new QDoubleSpinBox(groupMitigationWater);
        E_GrassStripN->setObjectName("E_GrassStripN");
        E_GrassStripN->setEnabled(false);
        sizePolicy4.setHeightForWidth(E_GrassStripN->sizePolicy().hasHeightForWidth());
        E_GrassStripN->setSizePolicy(sizePolicy4);
        E_GrassStripN->setFont(font5);
        E_GrassStripN->setMinimum(0.010000000000000);
        E_GrassStripN->setMaximum(10.000000000000000);
        E_GrassStripN->setSingleStep(0.010000000000000);
        E_GrassStripN->setValue(0.200000000000000);

        gridLayout_70->addWidget(E_GrassStripN, 6, 1, 1, 1);

        line_FlowBarriers = new QLineEdit(groupMitigationWater);
        line_FlowBarriers->setObjectName("line_FlowBarriers");
        line_FlowBarriers->setEnabled(false);
        sizePolicy4.setHeightForWidth(line_FlowBarriers->sizePolicy().hasHeightForWidth());
        line_FlowBarriers->setSizePolicy(sizePolicy4);
        line_FlowBarriers->setFont(font5);

        gridLayout_70->addWidget(line_FlowBarriers, 1, 1, 1, 2);

        checkGridRentention = new QCheckBox(groupMitigationWater);
        checkGridRentention->setObjectName("checkGridRentention");
        checkGridRentention->setEnabled(true);
        checkGridRentention->setFont(font5);

        gridLayout_70->addWidget(checkGridRentention, 3, 0, 1, 3);

        checkBuffers = new QCheckBox(groupMitigationWater);
        checkBuffers->setObjectName("checkBuffers");
        checkBuffers->setFont(font5);

        gridLayout_70->addWidget(checkBuffers, 0, 0, 1, 3);

        label_15 = new QLabel(groupMitigationWater);
        label_15->setObjectName("label_15");
        label_15->setEnabled(false);
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy9);
        QPalette palette6;
        label_15->setPalette(palette6);
        label_15->setFont(font5);
        label_15->setTextFormat(Qt::TextFormat::PlainText);
        label_15->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_70->addWidget(label_15, 6, 0, 1, 1);

        checkInfilGrass = new QCheckBox(groupMitigationWater);
        checkInfilGrass->setObjectName("checkInfilGrass");
        checkInfilGrass->setEnabled(true);
        sizePolicy4.setHeightForWidth(checkInfilGrass->sizePolicy().hasHeightForWidth());
        checkInfilGrass->setSizePolicy(sizePolicy4);
        QPalette palette7;
        checkInfilGrass->setPalette(palette7);
        checkInfilGrass->setFont(font5);

        gridLayout_70->addWidget(checkInfilGrass, 4, 0, 1, 3);


        gridLayout_79->addWidget(groupMitigationWater, 2, 0, 1, 1);

        groupConservationSed = new QGroupBox(tab_Infra);
        groupConservationSed->setObjectName("groupConservationSed");
        groupConservationSed->setEnabled(true);
        sizePolicy2.setHeightForWidth(groupConservationSed->sizePolicy().hasHeightForWidth());
        groupConservationSed->setSizePolicy(sizePolicy2);
        groupConservationSed->setFont(font7);
        gridLayout_11 = new QGridLayout(groupConservationSed);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setHorizontalSpacing(8);
        gridLayout_11->setVerticalSpacing(4);
        gridLayout_11->setContentsMargins(8, 4, 8, 4);
        checkSedtrap = new QCheckBox(groupConservationSed);
        checkSedtrap->setObjectName("checkSedtrap");
        sizePolicy4.setHeightForWidth(checkSedtrap->sizePolicy().hasHeightForWidth());
        checkSedtrap->setSizePolicy(sizePolicy4);
        QPalette palette8;
        checkSedtrap->setPalette(palette8);
        checkSedtrap->setFont(font5);

        gridLayout_11->addWidget(checkSedtrap, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_191 = new QLabel(groupConservationSed);
        label_191->setObjectName("label_191");
        label_191->setEnabled(false);
        sizePolicy4.setHeightForWidth(label_191->sizePolicy().hasHeightForWidth());
        label_191->setSizePolicy(sizePolicy4);
        label_191->setFont(font5);
        label_191->setTextFormat(Qt::TextFormat::RichText);

        horizontalLayout_4->addWidget(label_191);

        label_104 = new QLabel(groupConservationSed);
        label_104->setObjectName("label_104");
        label_104->setEnabled(true);
        sizePolicy3.setHeightForWidth(label_104->sizePolicy().hasHeightForWidth());
        label_104->setSizePolicy(sizePolicy3);
        label_104->setFont(font5);

        horizontalLayout_4->addWidget(label_104);

        E_SedTrapN = new QDoubleSpinBox(groupConservationSed);
        E_SedTrapN->setObjectName("E_SedTrapN");
        E_SedTrapN->setEnabled(true);
        E_SedTrapN->setFont(font5);
        E_SedTrapN->setMinimum(0.010000000000000);
        E_SedTrapN->setSingleStep(0.010000000000000);
        E_SedTrapN->setValue(0.800000000000000);

        horizontalLayout_4->addWidget(E_SedTrapN);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_17);


        gridLayout_11->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_189 = new QLabel(groupConservationSed);
        label_189->setObjectName("label_189");
        label_189->setEnabled(false);
        sizePolicy4.setHeightForWidth(label_189->sizePolicy().hasHeightForWidth());
        label_189->setSizePolicy(sizePolicy4);
        label_189->setFont(font5);
        label_189->setTextFormat(Qt::TextFormat::RichText);

        horizontalLayout_2->addWidget(label_189);

        label_33 = new QLabel(groupConservationSed);
        label_33->setObjectName("label_33");
        label_33->setEnabled(true);
        sizePolicy9.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy9);
        QPalette palette9;
        label_33->setPalette(palette9);
        label_33->setFont(font5);
        label_33->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_33);

        E_BulkDens = new QDoubleSpinBox(groupConservationSed);
        E_BulkDens->setObjectName("E_BulkDens");
        E_BulkDens->setEnabled(true);
        E_BulkDens->setFont(font5);
        E_BulkDens->setDecimals(1);
        E_BulkDens->setMinimum(800.000000000000000);
        E_BulkDens->setMaximum(2650.000000000000000);
        E_BulkDens->setSingleStep(0.100000000000000);
        E_BulkDens->setValue(1500.000000000000000);

        horizontalLayout_2->addWidget(E_BulkDens);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_18);


        gridLayout_11->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        gridLayout_79->addWidget(groupConservationSed, 3, 0, 1, 1);

        verticalSpacer_12 = new QSpacerItem(908, 200, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_79->addItem(verticalSpacer_12, 4, 0, 1, 3);

        widgetInfra = new QWidget(tab_Infra);
        widgetInfra->setObjectName("widgetInfra");
        sizePolicy2.setHeightForWidth(widgetInfra->sizePolicy().hasHeightForWidth());
        widgetInfra->setSizePolicy(sizePolicy2);
        gridLayout_84 = new QGridLayout(widgetInfra);
        gridLayout_84->setObjectName("gridLayout_84");
        gridLayout_84->setHorizontalSpacing(0);
        gridLayout_84->setVerticalSpacing(4);
        gridLayout_84->setContentsMargins(0, 4, 8, 4);
        tilebox = new QFrame(widgetInfra);
        tilebox->setObjectName("tilebox");
        sizePolicy4.setHeightForWidth(tilebox->sizePolicy().hasHeightForWidth());
        tilebox->setSizePolicy(sizePolicy4);
        gridLayout_22 = new QGridLayout(tilebox);
        gridLayout_22->setObjectName("gridLayout_22");
        gridLayout_22->setHorizontalSpacing(0);
        gridLayout_22->setVerticalSpacing(4);
        gridLayout_22->setContentsMargins(0, 0, 8, 4);
        checkDrainNoOutflow = new QCheckBox(tilebox);
        checkDrainNoOutflow->setObjectName("checkDrainNoOutflow");
        sizePolicy2.setHeightForWidth(checkDrainNoOutflow->sizePolicy().hasHeightForWidth());
        checkDrainNoOutflow->setSizePolicy(sizePolicy2);

        gridLayout_22->addWidget(checkDrainNoOutflow, 3, 1, 1, 1);

        checkStormDrainCirc = new QRadioButton(tilebox);
        checkStormDrainCirc->setObjectName("checkStormDrainCirc");
        sizePolicy4.setHeightForWidth(checkStormDrainCirc->sizePolicy().hasHeightForWidth());
        checkStormDrainCirc->setSizePolicy(sizePolicy4);
        checkStormDrainCirc->setFont(font5);
        checkStormDrainCirc->setChecked(true);

        gridLayout_22->addWidget(checkStormDrainCirc, 0, 4, 1, 1);

        checkStormDrainRect = new QRadioButton(tilebox);
        checkStormDrainRect->setObjectName("checkStormDrainRect");
        checkStormDrainRect->setEnabled(true);
        checkStormDrainRect->setFont(font5);
        checkStormDrainRect->setChecked(false);

        gridLayout_22->addWidget(checkStormDrainRect, 0, 5, 1, 1);

        label_147 = new QLabel(tilebox);
        label_147->setObjectName("label_147");

        gridLayout_22->addWidget(label_147, 2, 5, 1, 1);

        E_TileInletSize = new QDoubleSpinBox(tilebox);
        E_TileInletSize->setObjectName("E_TileInletSize");
        E_TileInletSize->setDecimals(3);
        E_TileInletSize->setMinimum(0.001000000000000);
        E_TileInletSize->setMaximum(1.000000000000000);
        E_TileInletSize->setSingleStep(0.001000000000000);
        E_TileInletSize->setValue(0.020000000000000);

        gridLayout_22->addWidget(E_TileInletSize, 2, 6, 1, 1);

        E_TileInletDistance = new QSpinBox(tilebox);
        E_TileInletDistance->setObjectName("E_TileInletDistance");
        E_TileInletDistance->setValue(20);

        gridLayout_22->addWidget(E_TileInletDistance, 2, 4, 1, 1);

        label_14 = new QLabel(tilebox);
        label_14->setObjectName("label_14");
        sizePolicy3.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy3);

        gridLayout_22->addWidget(label_14, 3, 0, 1, 1);

        checkStormDrains = new QCheckBox(tilebox);
        checkStormDrains->setObjectName("checkStormDrains");
        sizePolicy4.setHeightForWidth(checkStormDrains->sizePolicy().hasHeightForWidth());
        checkStormDrains->setSizePolicy(sizePolicy4);
        checkStormDrains->setFont(font5);

        gridLayout_22->addWidget(checkStormDrains, 0, 0, 1, 4);

        label_166 = new QLabel(tilebox);
        label_166->setObjectName("label_166");

        gridLayout_22->addWidget(label_166, 2, 0, 1, 4);


        gridLayout_84->addWidget(tilebox, 4, 0, 1, 1);

        checkRoadsystem = new QCheckBox(widgetInfra);
        checkRoadsystem->setObjectName("checkRoadsystem");
        sizePolicy4.setHeightForWidth(checkRoadsystem->sizePolicy().hasHeightForWidth());
        checkRoadsystem->setSizePolicy(sizePolicy4);
        checkRoadsystem->setFont(font5);
        checkRoadsystem->setChecked(false);

        gridLayout_84->addWidget(checkRoadsystem, 2, 0, 1, 1);

        checkHouses = new QCheckBox(widgetInfra);
        checkHouses->setObjectName("checkHouses");
        sizePolicy4.setHeightForWidth(checkHouses->sizePolicy().hasHeightForWidth());
        checkHouses->setSizePolicy(sizePolicy4);
        checkHouses->setFont(font5);

        gridLayout_84->addWidget(checkHouses, 0, 0, 1, 1);

        gridLayout_30 = new QGridLayout();
        gridLayout_30->setObjectName("gridLayout_30");
        checkAddBuildingDEM = new QCheckBox(widgetInfra);
        checkAddBuildingDEM->setObjectName("checkAddBuildingDEM");
        sizePolicy4.setHeightForWidth(checkAddBuildingDEM->sizePolicy().hasHeightForWidth());
        checkAddBuildingDEM->setSizePolicy(sizePolicy4);
        checkAddBuildingDEM->setFont(font5);

        gridLayout_30->addWidget(checkAddBuildingDEM, 0, 2, 2, 1);

        E_buildingHeight = new QDoubleSpinBox(widgetInfra);
        E_buildingHeight->setObjectName("E_buildingHeight");
        E_buildingHeight->setEnabled(false);
        sizePolicy4.setHeightForWidth(E_buildingHeight->sizePolicy().hasHeightForWidth());
        E_buildingHeight->setSizePolicy(sizePolicy4);
        E_buildingHeight->setFont(font5);
        E_buildingHeight->setMinimum(0.010000000000000);
        E_buildingHeight->setSingleStep(0.010000000000000);
        E_buildingHeight->setValue(1.000000000000000);

        gridLayout_30->addWidget(E_buildingHeight, 0, 5, 2, 1);

        checkRaindrum = new QCheckBox(widgetInfra);
        checkRaindrum->setObjectName("checkRaindrum");
        checkRaindrum->setEnabled(true);
        sizePolicy2.setHeightForWidth(checkRaindrum->sizePolicy().hasHeightForWidth());
        checkRaindrum->setSizePolicy(sizePolicy2);
        checkRaindrum->setFont(font5);

        gridLayout_30->addWidget(checkRaindrum, 2, 2, 1, 1);

        label_78 = new QLabel(widgetInfra);
        label_78->setObjectName("label_78");
        sizePolicy3.setHeightForWidth(label_78->sizePolicy().hasHeightForWidth());
        label_78->setSizePolicy(sizePolicy3);
        label_78->setFont(font7);

        gridLayout_30->addWidget(label_78, 2, 0, 1, 2);

        label_145 = new QLabel(widgetInfra);
        label_145->setObjectName("label_145");
        sizePolicy3.setHeightForWidth(label_145->sizePolicy().hasHeightForWidth());
        label_145->setSizePolicy(sizePolicy3);
        label_145->setFont(font7);
        label_145->setTextFormat(Qt::TextFormat::PlainText);

        gridLayout_30->addWidget(label_145, 0, 0, 2, 2);

        E_AddBuildingFraction = new QDoubleSpinBox(widgetInfra);
        E_AddBuildingFraction->setObjectName("E_AddBuildingFraction");
        E_AddBuildingFraction->setEnabled(false);
        sizePolicy4.setHeightForWidth(E_AddBuildingFraction->sizePolicy().hasHeightForWidth());
        E_AddBuildingFraction->setSizePolicy(sizePolicy4);
        E_AddBuildingFraction->setFont(font5);
        E_AddBuildingFraction->setMaximum(1.000000000000000);
        E_AddBuildingFraction->setSingleStep(0.010000000000000);
        E_AddBuildingFraction->setValue(0.300000000000000);

        gridLayout_30->addWidget(E_AddBuildingFraction, 0, 3, 2, 1);

        label_140 = new QLabel(widgetInfra);
        label_140->setObjectName("label_140");
        label_140->setEnabled(false);
        label_140->setFont(font5);
        label_140->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_30->addWidget(label_140, 0, 4, 2, 1);


        gridLayout_84->addLayout(gridLayout_30, 1, 0, 1, 1);

        checkHardsurface = new QCheckBox(widgetInfra);
        checkHardsurface->setObjectName("checkHardsurface");
        checkHardsurface->setEnabled(true);
        sizePolicy2.setHeightForWidth(checkHardsurface->sizePolicy().hasHeightForWidth());
        checkHardsurface->setSizePolicy(sizePolicy2);
        checkHardsurface->setFont(font5);

        gridLayout_84->addWidget(checkHardsurface, 3, 0, 1, 1);


        gridLayout_79->addWidget(widgetInfra, 1, 0, 1, 1);

        label_89 = new QLabel(tab_Infra);
        label_89->setObjectName("label_89");
        label_89->setFont(font8);

        gridLayout_79->addWidget(label_89, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_79->addItem(horizontalSpacer_9, 2, 2, 1, 1);

        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/house.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_Infra, icon11, QString());
        tab_erosion = new QWidget();
        tab_erosion->setObjectName("tab_erosion");
        gridLayout_82 = new QGridLayout(tab_erosion);
        gridLayout_82->setObjectName("gridLayout_82");
        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_82->addItem(verticalSpacer_18, 3, 0, 1, 1);

        toolButton_resetErosion = new QToolButton(tab_erosion);
        toolButton_resetErosion->setObjectName("toolButton_resetErosion");
        toolButton_resetErosion->setIcon(icon2);

        gridLayout_82->addWidget(toolButton_resetErosion, 1, 2, 1, 1);

        widgetErosion = new QWidget(tab_erosion);
        widgetErosion->setObjectName("widgetErosion");
        gridLayout_41 = new QGridLayout(widgetErosion);
        gridLayout_41->setObjectName("gridLayout_41");
        gridLayout_41->setHorizontalSpacing(8);
        gridLayout_41->setVerticalSpacing(4);
        gridLayout_41->setContentsMargins(8, 4, 8, 4);
        label_143 = new QLabel(widgetErosion);
        label_143->setObjectName("label_143");
        sizePolicy3.setHeightForWidth(label_143->sizePolicy().hasHeightForWidth());
        label_143->setSizePolicy(sizePolicy3);
        label_143->setFont(font6);

        gridLayout_41->addWidget(label_143, 3, 0, 1, 1);

        groupSed = new QGroupBox(widgetErosion);
        groupSed->setObjectName("groupSed");
        groupSed->setEnabled(true);
        sizePolicy.setHeightForWidth(groupSed->sizePolicy().hasHeightForWidth());
        groupSed->setSizePolicy(sizePolicy);
        QFont font10;
        font10.setPointSize(8);
        font10.setBold(true);
        font10.setItalic(false);
        font10.setUnderline(false);
        font10.setKerning(true);
        groupSed->setFont(font10);
        groupSed->setCheckable(false);
        groupSed->setChecked(false);
        gridLayout_21 = new QGridLayout(groupSed);
        gridLayout_21->setObjectName("gridLayout_21");
        gridLayout_21->setHorizontalSpacing(8);
        gridLayout_21->setVerticalSpacing(4);
        gridLayout_21->setContentsMargins(8, 4, 8, 4);
        checkDiffusion = new QCheckBox(groupSed);
        checkDiffusion->setObjectName("checkDiffusion");
        sizePolicy2.setHeightForWidth(checkDiffusion->sizePolicy().hasHeightForWidth());
        checkDiffusion->setSizePolicy(sizePolicy2);
        checkDiffusion->setFont(font6);
        checkDiffusion->setChecked(false);

        gridLayout_21->addWidget(checkDiffusion, 5, 0, 1, 4);

        label_91 = new QLabel(groupSed);
        label_91->setObjectName("label_91");
        label_91->setFont(font6);

        gridLayout_21->addWidget(label_91, 0, 0, 1, 1);

        label_109 = new QLabel(groupSed);
        label_109->setObjectName("label_109");
        label_109->setFont(font6);

        gridLayout_21->addWidget(label_109, 2, 0, 1, 1);

        E_EfficiencyDET = new QComboBox(groupSed);
        E_EfficiencyDET->addItem(QString());
        E_EfficiencyDET->addItem(QString());
        E_EfficiencyDET->addItem(QString());
        E_EfficiencyDET->setObjectName("E_EfficiencyDET");
        E_EfficiencyDET->setFont(font6);
        E_EfficiencyDET->setMaxVisibleItems(3);

        gridLayout_21->addWidget(E_EfficiencyDET, 0, 1, 1, 3);

        E_SSMethod = new QComboBox(groupSed);
        E_SSMethod->addItem(QString());
        E_SSMethod->addItem(QString());
        E_SSMethod->setObjectName("E_SSMethod");
        E_SSMethod->setFont(font6);
        E_SSMethod->setMaxVisibleItems(4);

        gridLayout_21->addWidget(E_SSMethod, 2, 1, 1, 3);


        gridLayout_41->addWidget(groupSed, 4, 0, 1, 3);

        groupKinEnergy = new QGroupBox(widgetErosion);
        groupKinEnergy->setObjectName("groupKinEnergy");
        sizePolicy.setHeightForWidth(groupKinEnergy->sizePolicy().hasHeightForWidth());
        groupKinEnergy->setSizePolicy(sizePolicy);
        groupKinEnergy->setFont(font7);
        gridLayout_44 = new QGridLayout(groupKinEnergy);
        gridLayout_44->setObjectName("gridLayout_44");
        gridLayout_44->setHorizontalSpacing(8);
        gridLayout_44->setVerticalSpacing(4);
        gridLayout_44->setContentsMargins(8, 4, 8, 4);
        spinKEparameterC1 = new QDoubleSpinBox(groupKinEnergy);
        spinKEparameterC1->setObjectName("spinKEparameterC1");
        sizePolicy4.setHeightForWidth(spinKEparameterC1->sizePolicy().hasHeightForWidth());
        spinKEparameterC1->setSizePolicy(sizePolicy4);
        spinKEparameterC1->setFont(font5);
        spinKEparameterC1->setDecimals(3);
        spinKEparameterC1->setSingleStep(0.001000000000000);
        spinKEparameterC1->setValue(0.042000000000000);

        gridLayout_44->addWidget(spinKEparameterC1, 2, 8, 1, 1);

        spinKEparameterB1 = new QDoubleSpinBox(groupKinEnergy);
        spinKEparameterB1->setObjectName("spinKEparameterB1");
        sizePolicy4.setHeightForWidth(spinKEparameterB1->sizePolicy().hasHeightForWidth());
        spinKEparameterB1->setSizePolicy(sizePolicy4);
        spinKEparameterB1->setFont(font5);
        spinKEparameterB1->setDecimals(3);
        spinKEparameterB1->setSingleStep(0.001000000000000);
        spinKEparameterB1->setValue(0.520000000000000);

        gridLayout_44->addWidget(spinKEparameterB1, 2, 6, 1, 1);

        spinKEparameterA3 = new QDoubleSpinBox(groupKinEnergy);
        spinKEparameterA3->setObjectName("spinKEparameterA3");
        spinKEparameterA3->setEnabled(true);
        sizePolicy4.setHeightForWidth(spinKEparameterA3->sizePolicy().hasHeightForWidth());
        spinKEparameterA3->setSizePolicy(sizePolicy4);
        spinKEparameterA3->setFont(font5);
        spinKEparameterA3->setDecimals(3);
        spinKEparameterA3->setValue(7.600000000000000);

        gridLayout_44->addWidget(spinKEparameterA3, 4, 4, 1, 1);

        label_67 = new QLabel(groupKinEnergy);
        label_67->setObjectName("label_67");
        sizePolicy.setHeightForWidth(label_67->sizePolicy().hasHeightForWidth());
        label_67->setSizePolicy(sizePolicy);
        QPalette palette10;
        label_67->setPalette(palette10);
        label_67->setFont(font5);
        label_67->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_44->addWidget(label_67, 2, 7, 1, 1);

        label_65 = new QLabel(groupKinEnergy);
        label_65->setObjectName("label_65");
        sizePolicy.setHeightForWidth(label_65->sizePolicy().hasHeightForWidth());
        label_65->setSizePolicy(sizePolicy);
        QPalette palette11;
        label_65->setPalette(palette11);
        label_65->setFont(font5);
        label_65->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_44->addWidget(label_65, 2, 3, 1, 1);

        label_66 = new QLabel(groupKinEnergy);
        label_66->setObjectName("label_66");
        sizePolicy.setHeightForWidth(label_66->sizePolicy().hasHeightForWidth());
        label_66->setSizePolicy(sizePolicy);
        QPalette palette12;
        label_66->setPalette(palette12);
        label_66->setFont(font5);
        label_66->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_44->addWidget(label_66, 2, 5, 1, 1);

        label_72 = new QLabel(groupKinEnergy);
        label_72->setObjectName("label_72");
        label_72->setEnabled(true);
        sizePolicy.setHeightForWidth(label_72->sizePolicy().hasHeightForWidth());
        label_72->setSizePolicy(sizePolicy);
        QPalette palette13;
        label_72->setPalette(palette13);
        label_72->setFont(font5);
        label_72->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_44->addWidget(label_72, 4, 5, 1, 1);

        label_71 = new QLabel(groupKinEnergy);
        label_71->setObjectName("label_71");
        label_71->setEnabled(true);
        sizePolicy.setHeightForWidth(label_71->sizePolicy().hasHeightForWidth());
        label_71->setSizePolicy(sizePolicy);
        QPalette palette14;
        label_71->setPalette(palette14);
        label_71->setFont(font5);
        label_71->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_44->addWidget(label_71, 3, 5, 1, 1);

        label_58 = new QLabel(groupKinEnergy);
        label_58->setObjectName("label_58");
        QPalette palette15;
        label_58->setPalette(palette15);
        label_58->setFont(font5);
        label_58->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_44->addWidget(label_58, 5, 0, 1, 4);

        label_73 = new QLabel(groupKinEnergy);
        label_73->setObjectName("label_73");
        label_73->setEnabled(true);
        sizePolicy.setHeightForWidth(label_73->sizePolicy().hasHeightForWidth());
        label_73->setSizePolicy(sizePolicy);
        QPalette palette16;
        label_73->setPalette(palette16);
        label_73->setFont(font5);
        label_73->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_44->addWidget(label_73, 4, 3, 1, 1);

        radioButtonKE1 = new QRadioButton(groupKinEnergy);
        radioButtonKE1->setObjectName("radioButtonKE1");
        QPalette palette17;
        radioButtonKE1->setPalette(palette17);
        radioButtonKE1->setFont(font5);
        radioButtonKE1->setChecked(true);

        gridLayout_44->addWidget(radioButtonKE1, 2, 0, 1, 3);

        spinKEparameterB3 = new QDoubleSpinBox(groupKinEnergy);
        spinKEparameterB3->setObjectName("spinKEparameterB3");
        spinKEparameterB3->setEnabled(true);
        sizePolicy4.setHeightForWidth(spinKEparameterB3->sizePolicy().hasHeightForWidth());
        spinKEparameterB3->setSizePolicy(sizePolicy4);
        spinKEparameterB3->setFont(font5);
        spinKEparameterB3->setDecimals(3);
        spinKEparameterB3->setValue(0.220000000000000);

        gridLayout_44->addWidget(spinKEparameterB3, 4, 6, 1, 1);

        spinKEparameterB2 = new QDoubleSpinBox(groupKinEnergy);
        spinKEparameterB2->setObjectName("spinKEparameterB2");
        spinKEparameterB2->setEnabled(true);
        sizePolicy4.setHeightForWidth(spinKEparameterB2->sizePolicy().hasHeightForWidth());
        spinKEparameterB2->setSizePolicy(sizePolicy4);
        spinKEparameterB2->setFont(font5);
        spinKEparameterB2->setDecimals(3);
        spinKEparameterB2->setValue(8.440000000000000);

        gridLayout_44->addWidget(spinKEparameterB2, 3, 6, 1, 5);

        label_70 = new QLabel(groupKinEnergy);
        label_70->setObjectName("label_70");
        label_70->setEnabled(true);
        sizePolicy.setHeightForWidth(label_70->sizePolicy().hasHeightForWidth());
        label_70->setSizePolicy(sizePolicy);
        QPalette palette18;
        label_70->setPalette(palette18);
        label_70->setFont(font5);
        label_70->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_44->addWidget(label_70, 3, 3, 1, 1);

        spinKEparameterA2 = new QDoubleSpinBox(groupKinEnergy);
        spinKEparameterA2->setObjectName("spinKEparameterA2");
        spinKEparameterA2->setEnabled(true);
        sizePolicy4.setHeightForWidth(spinKEparameterA2->sizePolicy().hasHeightForWidth());
        spinKEparameterA2->setSizePolicy(sizePolicy4);
        spinKEparameterA2->setFont(font5);
        spinKEparameterA2->setDecimals(3);
        spinKEparameterA2->setValue(8.949999999999999);

        gridLayout_44->addWidget(spinKEparameterA2, 3, 4, 1, 1);

        radioButtonKE2 = new QRadioButton(groupKinEnergy);
        radioButtonKE2->setObjectName("radioButtonKE2");
        QPalette palette19;
        radioButtonKE2->setPalette(palette19);
        radioButtonKE2->setFont(font5);

        gridLayout_44->addWidget(radioButtonKE2, 3, 0, 1, 1);

        spinKEparameterA1 = new QDoubleSpinBox(groupKinEnergy);
        spinKEparameterA1->setObjectName("spinKEparameterA1");
        sizePolicy4.setHeightForWidth(spinKEparameterA1->sizePolicy().hasHeightForWidth());
        spinKEparameterA1->setSizePolicy(sizePolicy4);
        spinKEparameterA1->setFont(font5);
        spinKEparameterA1->setDecimals(3);
        spinKEparameterA1->setSingleStep(0.001000000000000);
        spinKEparameterA1->setValue(28.300000000000001);

        gridLayout_44->addWidget(spinKEparameterA1, 2, 4, 1, 1);

        radioButtonKE3 = new QRadioButton(groupKinEnergy);
        radioButtonKE3->setObjectName("radioButtonKE3");
        QPalette palette20;
        radioButtonKE3->setPalette(palette20);
        radioButtonKE3->setFont(font5);

        gridLayout_44->addWidget(radioButtonKE3, 4, 0, 1, 1);

        E_splashEquation = new QSpinBox(groupKinEnergy);
        E_splashEquation->setObjectName("E_splashEquation");
        sizePolicy4.setHeightForWidth(E_splashEquation->sizePolicy().hasHeightForWidth());
        E_splashEquation->setSizePolicy(sizePolicy4);
        E_splashEquation->setFont(font5);
        E_splashEquation->setMinimum(1);
        E_splashEquation->setMaximum(2);

        gridLayout_44->addWidget(E_splashEquation, 6, 4, 1, 1);

        label_141 = new QLabel(groupKinEnergy);
        label_141->setObjectName("label_141");
        label_141->setFont(font5);
        label_141->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_44->addWidget(label_141, 6, 0, 1, 4);

        label_142 = new QLabel(groupKinEnergy);
        label_142->setObjectName("label_142");
        label_142->setFont(font5);

        gridLayout_44->addWidget(label_142, 6, 5, 1, 6);

        E_SplashDelibery = new QDoubleSpinBox(groupKinEnergy);
        E_SplashDelibery->setObjectName("E_SplashDelibery");
        sizePolicy4.setHeightForWidth(E_SplashDelibery->sizePolicy().hasHeightForWidth());
        E_SplashDelibery->setSizePolicy(sizePolicy4);
        E_SplashDelibery->setFont(font5);
        E_SplashDelibery->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        E_SplashDelibery->setDecimals(2);
        E_SplashDelibery->setMinimum(0.000000000000000);
        E_SplashDelibery->setMaximum(1.000000000000000);
        E_SplashDelibery->setSingleStep(0.010000000000000);
        E_SplashDelibery->setValue(0.100000000000000);

        gridLayout_44->addWidget(E_SplashDelibery, 5, 4, 1, 2);


        gridLayout_41->addWidget(groupKinEnergy, 1, 0, 1, 3);

        label_9 = new QLabel(widgetErosion);
        label_9->setObjectName("label_9");
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setFont(font8);

        gridLayout_41->addWidget(label_9, 0, 0, 1, 3);

        label_10 = new QLabel(widgetErosion);
        label_10->setObjectName("label_10");
        label_10->setFont(font8);

        gridLayout_41->addWidget(label_10, 2, 0, 1, 3);

        groupSedCH = new QGroupBox(widgetErosion);
        groupSedCH->setObjectName("groupSedCH");
        groupSedCH->setFont(font7);
        gridLayout_26 = new QGridLayout(groupSedCH);
        gridLayout_26->setObjectName("gridLayout_26");
        gridLayout_26->setHorizontalSpacing(8);
        gridLayout_26->setVerticalSpacing(4);
        gridLayout_26->setContentsMargins(8, 4, 8, 4);
        E_EfficiencyDirect = new QDoubleSpinBox(groupSedCH);
        E_EfficiencyDirect->setObjectName("E_EfficiencyDirect");
        E_EfficiencyDirect->setEnabled(false);
        sizePolicy4.setHeightForWidth(E_EfficiencyDirect->sizePolicy().hasHeightForWidth());
        E_EfficiencyDirect->setSizePolicy(sizePolicy4);
        E_EfficiencyDirect->setFont(font5);
        E_EfficiencyDirect->setDecimals(3);
        E_EfficiencyDirect->setMinimum(0.000000000000000);
        E_EfficiencyDirect->setMaximum(10.000000000000000);
        E_EfficiencyDirect->setSingleStep(0.001000000000000);
        E_EfficiencyDirect->setValue(1.000000000000000);

        gridLayout_26->addWidget(E_EfficiencyDirect, 0, 3, 1, 1);

        label_4 = new QLabel(groupSedCH);
        label_4->setObjectName("label_4");
        label_4->setFont(font5);

        gridLayout_26->addWidget(label_4, 3, 0, 1, 1);

        label_11 = new QLabel(groupSedCH);
        label_11->setObjectName("label_11");
        label_11->setFont(font5);

        gridLayout_26->addWidget(label_11, 0, 0, 1, 1);

        checkDiffusionCH = new QCheckBox(groupSedCH);
        checkDiffusionCH->setObjectName("checkDiffusionCH");
        sizePolicy2.setHeightForWidth(checkDiffusionCH->sizePolicy().hasHeightForWidth());
        checkDiffusionCH->setSizePolicy(sizePolicy2);
        checkDiffusionCH->setFont(font5);

        gridLayout_26->addWidget(checkDiffusionCH, 5, 0, 1, 4);

        E_EfficiencyDETCH = new QComboBox(groupSedCH);
        E_EfficiencyDETCH->addItem(QString());
        E_EfficiencyDETCH->addItem(QString());
        E_EfficiencyDETCH->addItem(QString());
        E_EfficiencyDETCH->addItem(QString());
        E_EfficiencyDETCH->setObjectName("E_EfficiencyDETCH");
        E_EfficiencyDETCH->setFont(font5);
        E_EfficiencyDETCH->setMaxVisibleItems(3);

        gridLayout_26->addWidget(E_EfficiencyDETCH, 0, 1, 1, 2);

        checkSed2Phase = new QCheckBox(groupSedCH);
        checkSed2Phase->setObjectName("checkSed2Phase");
        checkSed2Phase->setEnabled(true);
        sizePolicy3.setHeightForWidth(checkSed2Phase->sizePolicy().hasHeightForWidth());
        checkSed2Phase->setSizePolicy(sizePolicy3);
        checkSed2Phase->setFont(font6);
        checkSed2Phase->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        checkSed2Phase->setChecked(false);

        gridLayout_26->addWidget(checkSed2Phase, 6, 0, 1, 1);

        E_TurbulenceFactor = new QDoubleSpinBox(groupSedCH);
        E_TurbulenceFactor->setObjectName("E_TurbulenceFactor");
        sizePolicy4.setHeightForWidth(E_TurbulenceFactor->sizePolicy().hasHeightForWidth());
        E_TurbulenceFactor->setSizePolicy(sizePolicy4);
        E_TurbulenceFactor->setFont(font5);
        E_TurbulenceFactor->setMaximum(1.000000000000000);
        E_TurbulenceFactor->setSingleStep(0.010000000000000);
        E_TurbulenceFactor->setValue(1.000000000000000);

        gridLayout_26->addWidget(E_TurbulenceFactor, 4, 1, 1, 1);

        label_157 = new QLabel(groupSedCH);
        label_157->setObjectName("label_157");
        label_157->setFont(font5);

        gridLayout_26->addWidget(label_157, 4, 0, 1, 1);

        label_165 = new QLabel(groupSedCH);
        label_165->setObjectName("label_165");
        label_165->setFont(font5);

        gridLayout_26->addWidget(label_165, 4, 2, 1, 2);

        E_RSSMethod = new QComboBox(groupSedCH);
        E_RSSMethod->addItem(QString());
        E_RSSMethod->addItem(QString());
        E_RSSMethod->addItem(QString());
        E_RSSMethod->addItem(QString());
        E_RSSMethod->setObjectName("E_RSSMethod");
        E_RSSMethod->setFont(font5);
        E_RSSMethod->setMaxVisibleItems(4);

        gridLayout_26->addWidget(E_RSSMethod, 3, 1, 1, 2);

        E_RBLMethod = new QComboBox(groupSedCH);
        E_RBLMethod->addItem(QString());
        E_RBLMethod->addItem(QString());
        E_RBLMethod->addItem(QString());
        E_RBLMethod->setObjectName("E_RBLMethod");
        E_RBLMethod->setEnabled(false);
        E_RBLMethod->setFont(font5);
        E_RBLMethod->setMaxVisibleItems(3);

        gridLayout_26->addWidget(E_RBLMethod, 6, 1, 1, 2);


        gridLayout_41->addWidget(groupSedCH, 5, 0, 1, 3);

        E_settlingVelocity = new QComboBox(widgetErosion);
        E_settlingVelocity->addItem(QString());
        E_settlingVelocity->addItem(QString());
        E_settlingVelocity->setObjectName("E_settlingVelocity");
        sizePolicy4.setHeightForWidth(E_settlingVelocity->sizePolicy().hasHeightForWidth());
        E_settlingVelocity->setSizePolicy(sizePolicy4);
        E_settlingVelocity->setFont(font6);

        gridLayout_41->addWidget(E_settlingVelocity, 3, 1, 1, 1);


        gridLayout_82->addWidget(widgetErosion, 0, 0, 3, 1);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_82->addItem(verticalSpacer_11, 2, 2, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_82->addItem(horizontalSpacer_12, 1, 4, 1, 1);

        toolButton_helpErosion = new QToolButton(tab_erosion);
        toolButton_helpErosion->setObjectName("toolButton_helpErosion");
        toolButton_helpErosion->setIcon(icon3);

        gridLayout_82->addWidget(toolButton_helpErosion, 1, 3, 1, 1);

        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/eros1bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_erosion, icon12, QString());
        tab_calib = new QWidget();
        tab_calib->setObjectName("tab_calib");
        gridLayout_20 = new QGridLayout(tab_calib);
        gridLayout_20->setObjectName("gridLayout_20");
        label_59 = new QLabel(tab_calib);
        label_59->setObjectName("label_59");
        sizePolicy8.setHeightForWidth(label_59->sizePolicy().hasHeightForWidth());
        label_59->setSizePolicy(sizePolicy8);
        label_59->setFont(font8);

        gridLayout_20->addWidget(label_59, 0, 0, 1, 1);

        toolButton_resetCalibration = new QToolButton(tab_calib);
        toolButton_resetCalibration->setObjectName("toolButton_resetCalibration");
        toolButton_resetCalibration->setIcon(icon2);

        gridLayout_20->addWidget(toolButton_resetCalibration, 0, 1, 1, 1);

        toolButton_helpCalibration = new QToolButton(tab_calib);
        toolButton_helpCalibration->setObjectName("toolButton_helpCalibration");
        toolButton_helpCalibration->setIcon(icon3);

        gridLayout_20->addWidget(toolButton_helpCalibration, 0, 2, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_20->addItem(horizontalSpacer_20, 2, 3, 1, 1);

        groupCalFlow = new QGroupBox(tab_calib);
        groupCalFlow->setObjectName("groupCalFlow");
        sizePolicy7.setHeightForWidth(groupCalFlow->sizePolicy().hasHeightForWidth());
        groupCalFlow->setSizePolicy(sizePolicy7);
        groupCalFlow->setFont(font7);
        gridLayout_29 = new QGridLayout(groupCalFlow);
        gridLayout_29->setObjectName("gridLayout_29");
        gridLayout_29->setHorizontalSpacing(8);
        gridLayout_29->setVerticalSpacing(2);
        gridLayout_29->setContentsMargins(8, 4, 8, 4);
        E_CalibrateChN = new QDoubleSpinBox(groupCalFlow);
        E_CalibrateChN->setObjectName("E_CalibrateChN");
        sizePolicy4.setHeightForWidth(E_CalibrateChN->sizePolicy().hasHeightForWidth());
        E_CalibrateChN->setSizePolicy(sizePolicy4);
        E_CalibrateChN->setFont(font5);
        E_CalibrateChN->setMinimum(0.010000000000000);
        E_CalibrateChN->setMaximum(99.989999999999995);
        E_CalibrateChN->setSingleStep(0.010000000000000);
        E_CalibrateChN->setValue(1.000000000000000);

        gridLayout_29->addWidget(E_CalibrateChN, 4, 4, 1, 1);

        E_CalibrateWave = new QDoubleSpinBox(groupCalFlow);
        E_CalibrateWave->setObjectName("E_CalibrateWave");
        E_CalibrateWave->setFont(font5);
        E_CalibrateWave->setMinimum(0.010000000000000);
        E_CalibrateWave->setMaximum(99.000000000000000);
        E_CalibrateWave->setSingleStep(0.010000000000000);
        E_CalibrateWave->setValue(1.000000000000000);

        gridLayout_29->addWidget(E_CalibrateWave, 6, 4, 1, 1);

        label_150 = new QLabel(groupCalFlow);
        label_150->setObjectName("label_150");
        label_150->setFont(font5);

        gridLayout_29->addWidget(label_150, 6, 1, 1, 1);

        E_CalibrateN = new QDoubleSpinBox(groupCalFlow);
        E_CalibrateN->setObjectName("E_CalibrateN");
        sizePolicy4.setHeightForWidth(E_CalibrateN->sizePolicy().hasHeightForWidth());
        E_CalibrateN->setSizePolicy(sizePolicy4);
        E_CalibrateN->setFont(font5);
        E_CalibrateN->setMinimum(0.010000000000000);
        E_CalibrateN->setMaximum(99.989999999999995);
        E_CalibrateN->setSingleStep(0.010000000000000);
        E_CalibrateN->setValue(1.000000000000000);

        gridLayout_29->addWidget(E_CalibrateN, 3, 4, 1, 1);

        label_134 = new QLabel(groupCalFlow);
        label_134->setObjectName("label_134");
        label_134->setFont(font5);

        gridLayout_29->addWidget(label_134, 6, 3, 1, 1);

        E_CalibrateCulvert = new QDoubleSpinBox(groupCalFlow);
        E_CalibrateCulvert->setObjectName("E_CalibrateCulvert");
        E_CalibrateCulvert->setFont(font5);
        E_CalibrateCulvert->setMinimum(0.010000000000000);
        E_CalibrateCulvert->setSingleStep(0.010000000000000);
        E_CalibrateCulvert->setValue(1.000000000000000);

        gridLayout_29->addWidget(E_CalibrateCulvert, 8, 4, 1, 1);

        E_CalibrateChKsat = new QDoubleSpinBox(groupCalFlow);
        E_CalibrateChKsat->setObjectName("E_CalibrateChKsat");
        sizePolicy4.setHeightForWidth(E_CalibrateChKsat->sizePolicy().hasHeightForWidth());
        E_CalibrateChKsat->setSizePolicy(sizePolicy4);
        E_CalibrateChKsat->setFont(font5);
        E_CalibrateChKsat->setDecimals(2);
        E_CalibrateChKsat->setMinimum(0.010000000000000);
        E_CalibrateChKsat->setMaximum(99.989999999999995);
        E_CalibrateChKsat->setSingleStep(0.010000000000000);
        E_CalibrateChKsat->setValue(1.000000000000000);

        gridLayout_29->addWidget(E_CalibrateChKsat, 5, 4, 1, 1);

        label_calchn = new QLabel(groupCalFlow);
        label_calchn->setObjectName("label_calchn");
        sizePolicy2.setHeightForWidth(label_calchn->sizePolicy().hasHeightForWidth());
        label_calchn->setSizePolicy(sizePolicy2);
        label_calchn->setFont(font5);
#if QT_CONFIG(tooltip)
        label_calchn->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        label_calchn->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_29->addWidget(label_calchn, 4, 1, 1, 1);

        label_calchks = new QLabel(groupCalFlow);
        label_calchks->setObjectName("label_calchks");
        sizePolicy2.setHeightForWidth(label_calchks->sizePolicy().hasHeightForWidth());
        label_calchks->setSizePolicy(sizePolicy2);
        label_calchks->setFont(font5);
#if QT_CONFIG(tooltip)
        label_calchks->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        label_calchks->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_29->addWidget(label_calchks, 5, 1, 1, 1);

        label_calN = new QLabel(groupCalFlow);
        label_calN->setObjectName("label_calN");
        sizePolicy2.setHeightForWidth(label_calN->sizePolicy().hasHeightForWidth());
        label_calN->setSizePolicy(sizePolicy2);
        label_calN->setFont(font5);
#if QT_CONFIG(tooltip)
        label_calN->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        label_calN->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_29->addWidget(label_calN, 3, 1, 1, 1);

        label_62 = new QLabel(groupCalFlow);
        label_62->setObjectName("label_62");
        label_62->setFont(font5);

        gridLayout_29->addWidget(label_62, 8, 1, 1, 1);


        gridLayout_20->addWidget(groupCalFlow, 3, 0, 1, 1);

        groupCalErosion = new QGroupBox(tab_calib);
        groupCalErosion->setObjectName("groupCalErosion");
        sizePolicy6.setHeightForWidth(groupCalErosion->sizePolicy().hasHeightForWidth());
        groupCalErosion->setSizePolicy(sizePolicy6);
        groupCalErosion->setFont(font7);
        gridLayout_69 = new QGridLayout(groupCalErosion);
        gridLayout_69->setObjectName("gridLayout_69");
        gridLayout_69->setHorizontalSpacing(8);
        gridLayout_69->setVerticalSpacing(2);
        gridLayout_69->setContentsMargins(8, 4, 8, 4);
        E_CalibrateD50 = new QDoubleSpinBox(groupCalErosion);
        E_CalibrateD50->setObjectName("E_CalibrateD50");
        sizePolicy4.setHeightForWidth(E_CalibrateD50->sizePolicy().hasHeightForWidth());
        E_CalibrateD50->setSizePolicy(sizePolicy4);
        E_CalibrateD50->setFont(font5);
        E_CalibrateD50->setMinimum(0.010000000000000);
        E_CalibrateD50->setMaximum(99.989999999999995);
        E_CalibrateD50->setSingleStep(0.010000000000000);
        E_CalibrateD50->setValue(1.000000000000000);

        gridLayout_69->addWidget(E_CalibrateD50, 2, 1, 1, 1);

        E_CalibrateCOH = new QDoubleSpinBox(groupCalErosion);
        E_CalibrateCOH->setObjectName("E_CalibrateCOH");
        E_CalibrateCOH->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_CalibrateCOH->sizePolicy().hasHeightForWidth());
        E_CalibrateCOH->setSizePolicy(sizePolicy4);
        E_CalibrateCOH->setFont(font5);
        E_CalibrateCOH->setMinimum(-1.000000000000000);
        E_CalibrateCOH->setSingleStep(0.010000000000000);
        E_CalibrateCOH->setValue(1.000000000000000);

        gridLayout_69->addWidget(E_CalibrateCOH, 1, 1, 1, 1);

        label_calchcoh = new QLabel(groupCalErosion);
        label_calchcoh->setObjectName("label_calchcoh");
        sizePolicy4.setHeightForWidth(label_calchcoh->sizePolicy().hasHeightForWidth());
        label_calchcoh->setSizePolicy(sizePolicy4);
        label_calchcoh->setFont(font5);
#if QT_CONFIG(tooltip)
        label_calchcoh->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)

        gridLayout_69->addWidget(label_calchcoh, 4, 0, 1, 1);

        label_cald50 = new QLabel(groupCalErosion);
        label_cald50->setObjectName("label_cald50");
        sizePolicy3.setHeightForWidth(label_cald50->sizePolicy().hasHeightForWidth());
        label_cald50->setSizePolicy(sizePolicy3);
        label_cald50->setFont(font5);

        gridLayout_69->addWidget(label_cald50, 2, 0, 1, 1);

        label_calcoh = new QLabel(groupCalErosion);
        label_calcoh->setObjectName("label_calcoh");
        label_calcoh->setEnabled(true);
        sizePolicy4.setHeightForWidth(label_calcoh->sizePolicy().hasHeightForWidth());
        label_calcoh->setSizePolicy(sizePolicy4);
        label_calcoh->setFont(font5);
#if QT_CONFIG(tooltip)
        label_calcoh->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)

        gridLayout_69->addWidget(label_calcoh, 1, 0, 1, 1);

        E_CalibrateD90 = new QDoubleSpinBox(groupCalErosion);
        E_CalibrateD90->setObjectName("E_CalibrateD90");
        sizePolicy4.setHeightForWidth(E_CalibrateD90->sizePolicy().hasHeightForWidth());
        E_CalibrateD90->setSizePolicy(sizePolicy4);
        E_CalibrateD90->setFont(font5);
        E_CalibrateD90->setMinimum(0.010000000000000);
        E_CalibrateD90->setValue(1.000000000000000);

        gridLayout_69->addWidget(E_CalibrateD90, 3, 1, 1, 1);

        E_CalibrateCHCOH = new QDoubleSpinBox(groupCalErosion);
        E_CalibrateCHCOH->setObjectName("E_CalibrateCHCOH");
        sizePolicy4.setHeightForWidth(E_CalibrateCHCOH->sizePolicy().hasHeightForWidth());
        E_CalibrateCHCOH->setSizePolicy(sizePolicy4);
        E_CalibrateCHCOH->setFont(font5);
        E_CalibrateCHCOH->setMinimum(-1.000000000000000);
        E_CalibrateCHCOH->setSingleStep(0.010000000000000);
        E_CalibrateCHCOH->setValue(1.000000000000000);

        gridLayout_69->addWidget(E_CalibrateCHCOH, 4, 1, 1, 1);

        label_69 = new QLabel(groupCalErosion);
        label_69->setObjectName("label_69");
        sizePolicy3.setHeightForWidth(label_69->sizePolicy().hasHeightForWidth());
        label_69->setSizePolicy(sizePolicy3);
        label_69->setFont(font5);

        gridLayout_69->addWidget(label_69, 3, 0, 1, 1);

        label_calas = new QLabel(groupCalErosion);
        label_calas->setObjectName("label_calas");
        label_calas->setEnabled(true);
        sizePolicy4.setHeightForWidth(label_calas->sizePolicy().hasHeightForWidth());
        label_calas->setSizePolicy(sizePolicy4);
        label_calas->setFont(font5);
#if QT_CONFIG(tooltip)
        label_calas->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)

        gridLayout_69->addWidget(label_calas, 0, 0, 1, 1);

        E_CalibrateAS = new QDoubleSpinBox(groupCalErosion);
        E_CalibrateAS->setObjectName("E_CalibrateAS");
        E_CalibrateAS->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_CalibrateAS->sizePolicy().hasHeightForWidth());
        E_CalibrateAS->setSizePolicy(sizePolicy4);
        E_CalibrateAS->setFont(font5);
        E_CalibrateAS->setMinimum(0.010000000000000);
        E_CalibrateAS->setSingleStep(0.010000000000000);
        E_CalibrateAS->setValue(1.000000000000000);

        gridLayout_69->addWidget(E_CalibrateAS, 0, 1, 1, 1);


        gridLayout_20->addWidget(groupCalErosion, 4, 0, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_20->addItem(verticalSpacer_14, 5, 0, 1, 1);

        label_68 = new QLabel(tab_calib);
        label_68->setObjectName("label_68");
        sizePolicy1.setHeightForWidth(label_68->sizePolicy().hasHeightForWidth());
        label_68->setSizePolicy(sizePolicy1);
        QFont font11;
        font11.setPointSize(8);
        font11.setBold(false);
        font11.setItalic(true);
        font11.setUnderline(false);
        font11.setKerning(true);
        label_68->setFont(font11);

        gridLayout_20->addWidget(label_68, 1, 0, 1, 1);

        groupCalHydrology = new QGroupBox(tab_calib);
        groupCalHydrology->setObjectName("groupCalHydrology");
        sizePolicy6.setHeightForWidth(groupCalHydrology->sizePolicy().hasHeightForWidth());
        groupCalHydrology->setSizePolicy(sizePolicy6);
        groupCalHydrology->setFont(font7);
        gridLayout_19 = new QGridLayout(groupCalHydrology);
        gridLayout_19->setObjectName("gridLayout_19");
        gridLayout_19->setHorizontalSpacing(8);
        gridLayout_19->setVerticalSpacing(2);
        gridLayout_19->setContentsMargins(8, 4, 8, 4);
        E_CalibrateSmax = new QDoubleSpinBox(groupCalHydrology);
        E_CalibrateSmax->setObjectName("E_CalibrateSmax");
        sizePolicy4.setHeightForWidth(E_CalibrateSmax->sizePolicy().hasHeightForWidth());
        E_CalibrateSmax->setSizePolicy(sizePolicy4);
        E_CalibrateSmax->setFont(font5);
        E_CalibrateSmax->setMinimum(0.000000000000000);
        E_CalibrateSmax->setSingleStep(0.010000000000000);
        E_CalibrateSmax->setValue(1.000000000000000);

        gridLayout_19->addWidget(E_CalibrateSmax, 0, 1, 1, 1);

        E_CalibrateKsat = new QDoubleSpinBox(groupCalHydrology);
        E_CalibrateKsat->setObjectName("E_CalibrateKsat");
        sizePolicy4.setHeightForWidth(E_CalibrateKsat->sizePolicy().hasHeightForWidth());
        E_CalibrateKsat->setSizePolicy(sizePolicy4);
        E_CalibrateKsat->setFont(font5);
        E_CalibrateKsat->setMinimum(0.010000000000000);
        E_CalibrateKsat->setMaximum(99.989999999999995);
        E_CalibrateKsat->setSingleStep(0.010000000000000);
        E_CalibrateKsat->setValue(1.000000000000000);

        gridLayout_19->addWidget(E_CalibrateKsat, 2, 1, 1, 1);

        E_CalibrateTheta = new QDoubleSpinBox(groupCalHydrology);
        E_CalibrateTheta->setObjectName("E_CalibrateTheta");
        sizePolicy4.setHeightForWidth(E_CalibrateTheta->sizePolicy().hasHeightForWidth());
        E_CalibrateTheta->setSizePolicy(sizePolicy4);
        E_CalibrateTheta->setFont(font5);
        E_CalibrateTheta->setDecimals(2);
        E_CalibrateTheta->setMinimum(0.010000000000000);
        E_CalibrateTheta->setMaximum(99.989999999999995);
        E_CalibrateTheta->setSingleStep(0.010000000000000);
        E_CalibrateTheta->setValue(1.000000000000000);

        gridLayout_19->addWidget(E_CalibrateTheta, 5, 1, 1, 1);

        label_146 = new QLabel(groupCalHydrology);
        label_146->setObjectName("label_146");
        label_146->setFont(font5);

        gridLayout_19->addWidget(label_146, 1, 0, 1, 1);

        E_CalibrateRR = new QDoubleSpinBox(groupCalHydrology);
        E_CalibrateRR->setObjectName("E_CalibrateRR");
        sizePolicy4.setHeightForWidth(E_CalibrateRR->sizePolicy().hasHeightForWidth());
        E_CalibrateRR->setSizePolicy(sizePolicy4);
        E_CalibrateRR->setFont(font5);
        E_CalibrateRR->setSingleStep(0.010000000000000);
        E_CalibrateRR->setValue(1.000000000000000);

        gridLayout_19->addWidget(E_CalibrateRR, 1, 1, 1, 1);

        E_CalibratePsi = new QDoubleSpinBox(groupCalHydrology);
        E_CalibratePsi->setObjectName("E_CalibratePsi");
        sizePolicy4.setHeightForWidth(E_CalibratePsi->sizePolicy().hasHeightForWidth());
        E_CalibratePsi->setSizePolicy(sizePolicy4);
        E_CalibratePsi->setFont(font5);
        E_CalibratePsi->setDecimals(2);
        E_CalibratePsi->setMinimum(0.010000000000000);
        E_CalibratePsi->setMaximum(99.000000000000000);
        E_CalibratePsi->setSingleStep(0.010000000000000);
        E_CalibratePsi->setValue(1.000000000000000);

        gridLayout_19->addWidget(E_CalibratePsi, 6, 1, 1, 1);

        label_calKsat2 = new QLabel(groupCalHydrology);
        label_calKsat2->setObjectName("label_calKsat2");
        label_calKsat2->setFont(font5);

        gridLayout_19->addWidget(label_calKsat2, 3, 0, 1, 1);

        label_76 = new QLabel(groupCalHydrology);
        label_76->setObjectName("label_76");
        label_76->setFont(font5);

        gridLayout_19->addWidget(label_76, 0, 0, 1, 1);

        label_calKsat = new QLabel(groupCalHydrology);
        label_calKsat->setObjectName("label_calKsat");
        sizePolicy2.setHeightForWidth(label_calKsat->sizePolicy().hasHeightForWidth());
        label_calKsat->setSizePolicy(sizePolicy2);
        label_calKsat->setFont(font5);
#if QT_CONFIG(tooltip)
        label_calKsat->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        label_calKsat->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_19->addWidget(label_calKsat, 2, 0, 1, 1);

        label_calth = new QLabel(groupCalHydrology);
        label_calth->setObjectName("label_calth");
        sizePolicy2.setHeightForWidth(label_calth->sizePolicy().hasHeightForWidth());
        label_calth->setSizePolicy(sizePolicy2);
        label_calth->setFont(font5);
#if QT_CONFIG(tooltip)
        label_calth->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        label_calth->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_19->addWidget(label_calth, 5, 0, 1, 1);

        label_calpsi = new QLabel(groupCalHydrology);
        label_calpsi->setObjectName("label_calpsi");
        sizePolicy2.setHeightForWidth(label_calpsi->sizePolicy().hasHeightForWidth());
        label_calpsi->setSizePolicy(sizePolicy2);
        label_calpsi->setFont(font5);
#if QT_CONFIG(tooltip)
        label_calpsi->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        label_calpsi->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_19->addWidget(label_calpsi, 6, 0, 1, 1);

        E_CalibrateKsat2 = new QDoubleSpinBox(groupCalHydrology);
        E_CalibrateKsat2->setObjectName("E_CalibrateKsat2");
        sizePolicy4.setHeightForWidth(E_CalibrateKsat2->sizePolicy().hasHeightForWidth());
        E_CalibrateKsat2->setSizePolicy(sizePolicy4);
        E_CalibrateKsat2->setFont(font5);
        E_CalibrateKsat2->setMinimum(0.010000000000000);
        E_CalibrateKsat2->setSingleStep(0.010000000000000);
        E_CalibrateKsat2->setValue(1.000000000000000);

        gridLayout_19->addWidget(E_CalibrateKsat2, 3, 1, 1, 1);

        E_CalibrateKsat3 = new QDoubleSpinBox(groupCalHydrology);
        E_CalibrateKsat3->setObjectName("E_CalibrateKsat3");
        E_CalibrateKsat3->setFont(font5);
        E_CalibrateKsat3->setMinimum(0.010000000000000);
        E_CalibrateKsat3->setSingleStep(0.010000000000000);
        E_CalibrateKsat3->setValue(1.000000000000000);

        gridLayout_19->addWidget(E_CalibrateKsat3, 4, 1, 1, 1);

        label_calKsat3 = new QLabel(groupCalHydrology);
        label_calKsat3->setObjectName("label_calKsat3");
        label_calKsat3->setFont(font5);

        gridLayout_19->addWidget(label_calKsat3, 4, 0, 1, 1);


        gridLayout_20->addWidget(groupCalHydrology, 2, 0, 1, 1);

        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/advanced.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_calib, icon13, QString());
        tab_advanced = new QWidget();
        tab_advanced->setObjectName("tab_advanced");
        gridLayout_76 = new QGridLayout(tab_advanced);
        gridLayout_76->setObjectName("gridLayout_76");
        checkAdvancedOptions = new QCheckBox(tab_advanced);
        checkAdvancedOptions->setObjectName("checkAdvancedOptions");
        checkAdvancedOptions->setEnabled(true);
        sizePolicy4.setHeightForWidth(checkAdvancedOptions->sizePolicy().hasHeightForWidth());
        checkAdvancedOptions->setSizePolicy(sizePolicy4);
        checkAdvancedOptions->setFont(font7);
        checkAdvancedOptions->setChecked(false);

        gridLayout_76->addWidget(checkAdvancedOptions, 0, 0, 1, 1);

        groupAdvanced = new QFrame(tab_advanced);
        groupAdvanced->setObjectName("groupAdvanced");
        gridLayout_68 = new QGridLayout(groupAdvanced);
        gridLayout_68->setObjectName("gridLayout_68");
        groupAdvRichards = new QGroupBox(groupAdvanced);
        groupAdvRichards->setObjectName("groupAdvRichards");
        sizePolicy2.setHeightForWidth(groupAdvRichards->sizePolicy().hasHeightForWidth());
        groupAdvRichards->setSizePolicy(sizePolicy2);
        groupAdvRichards->setFont(font7);
        gridLayout_65 = new QGridLayout(groupAdvRichards);
        gridLayout_65->setObjectName("gridLayout_65");
        gridLayout_65->setHorizontalSpacing(8);
        gridLayout_65->setVerticalSpacing(4);
        gridLayout_65->setContentsMargins(8, 4, 8, 4);
        comboBox_Kmean = new QComboBox(groupAdvRichards);
        comboBox_Kmean->addItem(QString());
        comboBox_Kmean->addItem(QString());
        comboBox_Kmean->addItem(QString());
        comboBox_Kmean->addItem(QString());
        comboBox_Kmean->setObjectName("comboBox_Kmean");
        sizePolicy7.setHeightForWidth(comboBox_Kmean->sizePolicy().hasHeightForWidth());
        comboBox_Kmean->setSizePolicy(sizePolicy7);
        comboBox_Kmean->setFont(font5);

        gridLayout_65->addWidget(comboBox_Kmean, 2, 0, 1, 1);

        label_158 = new QLabel(groupAdvRichards);
        label_158->setObjectName("label_158");
        label_158->setFont(font5);

        gridLayout_65->addWidget(label_158, 2, 1, 1, 2);

        checkPsiUser = new QCheckBox(groupAdvRichards);
        checkPsiUser->setObjectName("checkPsiUser");
        sizePolicy4.setHeightForWidth(checkPsiUser->sizePolicy().hasHeightForWidth());
        checkPsiUser->setSizePolicy(sizePolicy4);
        checkPsiUser->setFont(font5);

        gridLayout_65->addWidget(checkPsiUser, 1, 0, 1, 3);

        spinTileSuction = new QDoubleSpinBox(groupAdvRichards);
        spinTileSuction->setObjectName("spinTileSuction");
        sizePolicy4.setHeightForWidth(spinTileSuction->sizePolicy().hasHeightForWidth());
        spinTileSuction->setSizePolicy(sizePolicy4);
        spinTileSuction->setFont(font5);
        spinTileSuction->setDecimals(1);
        spinTileSuction->setMinimum(-100.000000000000000);
        spinTileSuction->setMaximum(0.000000000000000);
        spinTileSuction->setSingleStep(0.100000000000000);
        spinTileSuction->setValue(-10.000000000000000);

        gridLayout_65->addWidget(spinTileSuction, 3, 2, 1, 1);

        label_164 = new QLabel(groupAdvRichards);
        label_164->setObjectName("label_164");
        label_164->setFont(font5);

        gridLayout_65->addWidget(label_164, 3, 0, 1, 2);

        checkMB_WH = new QCheckBox(groupAdvRichards);
        checkMB_WH->setObjectName("checkMB_WH");
        checkMB_WH->setFont(font5);

        gridLayout_65->addWidget(checkMB_WH, 0, 0, 1, 3);

        checkInfilOMcorrection = new QCheckBox(groupAdvRichards);
        checkInfilOMcorrection->setObjectName("checkInfilOMcorrection");
        checkInfilOMcorrection->setFont(font5);

        gridLayout_65->addWidget(checkInfilOMcorrection, 5, 0, 1, 3);

        checkInfilDensfactor = new QCheckBox(groupAdvRichards);
        checkInfilDensfactor->setObjectName("checkInfilDensfactor");
        checkInfilDensfactor->setFont(font5);

        gridLayout_65->addWidget(checkInfilDensfactor, 4, 0, 1, 3);


        gridLayout_68->addWidget(groupAdvRichards, 3, 0, 1, 3);

        toolButton_version = new QToolButton(groupAdvanced);
        toolButton_version->setObjectName("toolButton_version");

        gridLayout_68->addWidget(toolButton_version, 1, 0, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_68->addItem(horizontalSpacer_22, 5, 5, 1, 1);

        toolButton_helpAdvanced = new QToolButton(groupAdvanced);
        toolButton_helpAdvanced->setObjectName("toolButton_helpAdvanced");
        toolButton_helpAdvanced->setIcon(icon3);

        gridLayout_68->addWidget(toolButton_helpAdvanced, 0, 4, 1, 1);

        groupAdvKinwave = new QGroupBox(groupAdvanced);
        groupAdvKinwave->setObjectName("groupAdvKinwave");
        sizePolicy2.setHeightForWidth(groupAdvKinwave->sizePolicy().hasHeightForWidth());
        groupAdvKinwave->setSizePolicy(sizePolicy2);
        groupAdvKinwave->setFont(font7);
        gridLayout_48 = new QGridLayout(groupAdvKinwave);
        gridLayout_48->setObjectName("gridLayout_48");
        gridLayout_48->setHorizontalSpacing(8);
        gridLayout_48->setVerticalSpacing(4);
        gridLayout_48->setContentsMargins(8, 4, 8, 4);
        checkPerimeterKW = new QCheckBox(groupAdvKinwave);
        checkPerimeterKW->setObjectName("checkPerimeterKW");
        checkPerimeterKW->setFont(font5);

        gridLayout_48->addWidget(checkPerimeterKW, 1, 0, 1, 1);


        gridLayout_68->addWidget(groupAdvKinwave, 4, 0, 1, 3);

        groupAdvChannel = new QGroupBox(groupAdvanced);
        groupAdvChannel->setObjectName("groupAdvChannel");
        sizePolicy.setHeightForWidth(groupAdvChannel->sizePolicy().hasHeightForWidth());
        groupAdvChannel->setSizePolicy(sizePolicy);
        groupAdvChannel->setFont(font7);
        gridLayout_6 = new QGridLayout(groupAdvChannel);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setHorizontalSpacing(8);
        gridLayout_6->setVerticalSpacing(4);
        gridLayout_6->setContentsMargins(8, 4, 8, 4);
        checkChanMaxVelocity = new QCheckBox(groupAdvChannel);
        checkChanMaxVelocity->setObjectName("checkChanMaxVelocity");
        sizePolicy4.setHeightForWidth(checkChanMaxVelocity->sizePolicy().hasHeightForWidth());
        checkChanMaxVelocity->setSizePolicy(sizePolicy4);
        checkChanMaxVelocity->setFont(font5);

        gridLayout_6->addWidget(checkChanMaxVelocity, 4, 0, 1, 1);

        checkChannel2DflowConnect = new QCheckBox(groupAdvChannel);
        checkChannel2DflowConnect->setObjectName("checkChannel2DflowConnect");
        checkChannel2DflowConnect->setFont(font5);
        checkChannel2DflowConnect->setChecked(true);

        gridLayout_6->addWidget(checkChannel2DflowConnect, 1, 0, 1, 3);

        E_chanMaxVelocity = new QDoubleSpinBox(groupAdvChannel);
        E_chanMaxVelocity->setObjectName("E_chanMaxVelocity");
        E_chanMaxVelocity->setFont(font5);
        E_chanMaxVelocity->setDecimals(1);
        E_chanMaxVelocity->setMinimum(0.100000000000000);
        E_chanMaxVelocity->setMaximum(99.000000000000000);
        E_chanMaxVelocity->setSingleStep(0.100000000000000);
        E_chanMaxVelocity->setValue(10.000000000000000);

        gridLayout_6->addWidget(E_chanMaxVelocity, 4, 1, 1, 1);


        gridLayout_68->addWidget(groupAdvChannel, 7, 0, 1, 3);

        toolButton_resetAdvanced = new QToolButton(groupAdvanced);
        toolButton_resetAdvanced->setObjectName("toolButton_resetAdvanced");
        toolButton_resetAdvanced->setIcon(icon2);

        gridLayout_68->addWidget(toolButton_resetAdvanced, 0, 3, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_68->addItem(horizontalSpacer_16, 7, 5, 1, 1);

        groupAdvSWOF = new QGroupBox(groupAdvanced);
        groupAdvSWOF->setObjectName("groupAdvSWOF");
        groupAdvSWOF->setEnabled(true);
        sizePolicy.setHeightForWidth(groupAdvSWOF->sizePolicy().hasHeightForWidth());
        groupAdvSWOF->setSizePolicy(sizePolicy);
        groupAdvSWOF->setFont(font7);
        gridLayout_53 = new QGridLayout(groupAdvSWOF);
        gridLayout_53->setObjectName("gridLayout_53");
        gridLayout_53->setHorizontalSpacing(8);
        gridLayout_53->setVerticalSpacing(4);
        gridLayout_53->setContentsMargins(8, 4, 8, 4);
        E_FloodMaxIter = new QSpinBox(groupAdvSWOF);
        E_FloodMaxIter->setObjectName("E_FloodMaxIter");
        E_FloodMaxIter->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_FloodMaxIter->sizePolicy().hasHeightForWidth());
        E_FloodMaxIter->setSizePolicy(sizePolicy4);
        E_FloodMaxIter->setFont(font5);
        E_FloodMaxIter->setMinimum(10);
        E_FloodMaxIter->setMaximum(999);
        E_FloodMaxIter->setValue(200);

        gridLayout_53->addWidget(E_FloodMaxIter, 2, 0, 1, 1);

        label_199 = new QLabel(groupAdvSWOF);
        label_199->setObjectName("label_199");
        label_199->setEnabled(true);
        sizePolicy2.setHeightForWidth(label_199->sizePolicy().hasHeightForWidth());
        label_199->setSizePolicy(sizePolicy2);
        label_199->setFont(font5);
        label_199->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_53->addWidget(label_199, 2, 1, 1, 4);

        check2DDiagonalFlow = new QCheckBox(groupAdvSWOF);
        check2DDiagonalFlow->setObjectName("check2DDiagonalFlow");
        sizePolicy4.setHeightForWidth(check2DDiagonalFlow->sizePolicy().hasHeightForWidth());
        check2DDiagonalFlow->setSizePolicy(sizePolicy4);
        check2DDiagonalFlow->setFont(font5);
        check2DDiagonalFlow->setChecked(false);

        gridLayout_53->addWidget(check2DDiagonalFlow, 6, 0, 1, 3);

        checkCorrectDem = new QCheckBox(groupAdvSWOF);
        checkCorrectDem->setObjectName("checkCorrectDem");
        sizePolicy7.setHeightForWidth(checkCorrectDem->sizePolicy().hasHeightForWidth());
        checkCorrectDem->setSizePolicy(sizePolicy7);
        checkCorrectDem->setFont(font5);

        gridLayout_53->addWidget(checkCorrectDem, 8, 0, 1, 5);

        E_pitValue = new QDoubleSpinBox(groupAdvSWOF);
        E_pitValue->setObjectName("E_pitValue");
        sizePolicy4.setHeightForWidth(E_pitValue->sizePolicy().hasHeightForWidth());
        E_pitValue->setSizePolicy(sizePolicy4);
        E_pitValue->setFont(font5);
        E_pitValue->setDecimals(2);
        E_pitValue->setMinimum(0.010000000000000);
        E_pitValue->setMaximum(100.000000000000000);
        E_pitValue->setSingleStep(0.010000000000000);
        E_pitValue->setValue(0.100000000000000);

        gridLayout_53->addWidget(E_pitValue, 6, 3, 1, 1);

        label_123 = new QLabel(groupAdvSWOF);
        label_123->setObjectName("label_123");
        label_123->setEnabled(true);
        label_123->setFont(font5);
        label_123->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_53->addWidget(label_123, 0, 1, 1, 4);

        E_FloodReconstruction = new QSpinBox(groupAdvSWOF);
        E_FloodReconstruction->setObjectName("E_FloodReconstruction");
        E_FloodReconstruction->setEnabled(true);
        sizePolicy4.setHeightForWidth(E_FloodReconstruction->sizePolicy().hasHeightForWidth());
        E_FloodReconstruction->setSizePolicy(sizePolicy4);
        E_FloodReconstruction->setFont(font5);
        E_FloodReconstruction->setMinimum(1);
        E_FloodReconstruction->setMaximum(3);
        E_FloodReconstruction->setValue(3);

        gridLayout_53->addWidget(E_FloodReconstruction, 0, 0, 1, 1);

        checkTimeavgV = new QCheckBox(groupAdvSWOF);
        checkTimeavgV->setObjectName("checkTimeavgV");
        sizePolicy2.setHeightForWidth(checkTimeavgV->sizePolicy().hasHeightForWidth());
        checkTimeavgV->setSizePolicy(sizePolicy2);
        checkTimeavgV->setFont(font5);
        checkTimeavgV->setChecked(true);

        gridLayout_53->addWidget(checkTimeavgV, 4, 0, 1, 5);

        label_135 = new QLabel(groupAdvSWOF);
        label_135->setObjectName("label_135");
        sizePolicy2.setHeightForWidth(label_135->sizePolicy().hasHeightForWidth());
        label_135->setSizePolicy(sizePolicy2);
        label_135->setFont(font5);
        label_135->setWordWrap(true);

        gridLayout_53->addWidget(label_135, 6, 4, 1, 1);

        checkErosionLoop = new QCheckBox(groupAdvSWOF);
        checkErosionLoop->setObjectName("checkErosionLoop");
        sizePolicy2.setHeightForWidth(checkErosionLoop->sizePolicy().hasHeightForWidth());
        checkErosionLoop->setSizePolicy(sizePolicy2);
        checkErosionLoop->setFont(font5);
        checkErosionLoop->setChecked(true);

        gridLayout_53->addWidget(checkErosionLoop, 5, 0, 1, 5);

        label_161 = new QLabel(groupAdvSWOF);
        label_161->setObjectName("label_161");
        label_161->setFont(font5);

        gridLayout_53->addWidget(label_161, 3, 0, 1, 4);

        E_minWHVSWOF = new QLineEdit(groupAdvSWOF);
        E_minWHVSWOF->setObjectName("E_minWHVSWOF");
        sizePolicy4.setHeightForWidth(E_minWHVSWOF->sizePolicy().hasHeightForWidth());
        E_minWHVSWOF->setSizePolicy(sizePolicy4);
        E_minWHVSWOF->setFont(font5);

        gridLayout_53->addWidget(E_minWHVSWOF, 3, 4, 1, 1);


        gridLayout_68->addWidget(groupAdvSWOF, 5, 0, 1, 3);

        nrUserCores = new QSpinBox(groupAdvanced);
        nrUserCores->setObjectName("nrUserCores");
        sizePolicy4.setHeightForWidth(nrUserCores->sizePolicy().hasHeightForWidth());
        nrUserCores->setSizePolicy(sizePolicy4);
        nrUserCores->setFont(font5);
        nrUserCores->setMaximum(8);
        nrUserCores->setValue(0);
        nrUserCores->setDisplayIntegerBase(10);

        gridLayout_68->addWidget(nrUserCores, 0, 0, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_68->addItem(horizontalSpacer_19, 0, 5, 1, 1);

        checkNewversionGITHUB = new QCheckBox(groupAdvanced);
        checkNewversionGITHUB->setObjectName("checkNewversionGITHUB");

        gridLayout_68->addWidget(checkNewversionGITHUB, 1, 1, 1, 2);

        label_56 = new QLabel(groupAdvanced);
        label_56->setObjectName("label_56");
        label_56->setFont(font5);

        gridLayout_68->addWidget(label_56, 0, 1, 1, 2);


        gridLayout_76->addWidget(groupAdvanced, 1, 0, 1, 1);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_76->addItem(verticalSpacer_13, 2, 0, 1, 1);

        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/settings1.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetOptions->addTab(tab_advanced, icon14, QString());
        tab_spare = new QWidget();
        tab_spare->setObjectName("tab_spare");
        E_courantFactorSed = new QDoubleSpinBox(tab_spare);
        E_courantFactorSed->setObjectName("E_courantFactorSed");
        E_courantFactorSed->setEnabled(false);
        E_courantFactorSed->setGeometry(QRect(390, 360, 52, 26));
        sizePolicy4.setHeightForWidth(E_courantFactorSed->sizePolicy().hasHeightForWidth());
        E_courantFactorSed->setSizePolicy(sizePolicy4);
        E_courantFactorSed->setFont(font5);
        E_courantFactorSed->setMinimum(0.010000000000000);
        E_courantFactorSed->setMaximum(1.000000000000000);
        E_courantFactorSed->setSingleStep(0.010000000000000);
        E_courantFactorSed->setValue(0.100000000000000);
        checkGWflowSWOF = new QRadioButton(tab_spare);
        checkGWflowSWOF->setObjectName("checkGWflowSWOF");
        checkGWflowSWOF->setGeometry(QRect(11, 151, 264, 23));
        sizePolicy4.setHeightForWidth(checkGWflowSWOF->sizePolicy().hasHeightForWidth());
        checkGWflowSWOF->setSizePolicy(sizePolicy4);
        checkGWflowSWOF->setFont(font5);
        E_BLMethod = new QComboBox(tab_spare);
        E_BLMethod->addItem(QString());
        E_BLMethod->addItem(QString());
        E_BLMethod->addItem(QString());
        E_BLMethod->addItem(QString());
        E_BLMethod->setObjectName("E_BLMethod");
        E_BLMethod->setGeometry(QRect(11, 290, 179, 25));
        sizePolicy4.setHeightForWidth(E_BLMethod->sizePolicy().hasHeightForWidth());
        E_BLMethod->setSizePolicy(sizePolicy4);
        E_BLMethod->setFont(font6);
        E_BLMethod->setMaxVisibleItems(4);
        E_CalibrateCHSV = new QDoubleSpinBox(tab_spare);
        E_CalibrateCHSV->setObjectName("E_CalibrateCHSV");
        E_CalibrateCHSV->setGeometry(QRect(190, 690, 59, 26));
        sizePolicy4.setHeightForWidth(E_CalibrateCHSV->sizePolicy().hasHeightForWidth());
        E_CalibrateCHSV->setSizePolicy(sizePolicy4);
        E_CalibrateCHSV->setFont(font6);
        E_CalibrateCHSV->setMinimum(0.010000000000000);
        E_CalibrateCHSV->setMaximum(99.000000000000000);
        E_CalibrateCHSV->setSingleStep(0.010000000000000);
        E_CalibrateCHSV->setValue(1.000000000000000);
        E_CalibrateSD1 = new QDoubleSpinBox(tab_spare);
        E_CalibrateSD1->setObjectName("E_CalibrateSD1");
        E_CalibrateSD1->setGeometry(QRect(350, 690, 59, 26));
        sizePolicy4.setHeightForWidth(E_CalibrateSD1->sizePolicy().hasHeightForWidth());
        E_CalibrateSD1->setSizePolicy(sizePolicy4);
        E_CalibrateSD1->setFont(font5);
        E_CalibrateSD1->setMinimum(0.000000000000000);
        E_CalibrateSD1->setMaximum(10.000000000000000);
        E_CalibrateSD1->setSingleStep(0.010000000000000);
        E_CalibrateSD1->setValue(1.000000000000000);
        E_BulkDens2 = new QLineEdit(tab_spare);
        E_BulkDens2->setObjectName("E_BulkDens2");
        E_BulkDens2->setEnabled(false);
        E_BulkDens2->setGeometry(QRect(11, 400, 108, 25));
        sizePolicy4.setHeightForWidth(E_BulkDens2->sizePolicy().hasHeightForWidth());
        E_BulkDens2->setSizePolicy(sizePolicy4);
        E_BulkDens2->setFont(font5);
        label = new QLabel(tab_spare);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 700, 71, 17));
        label->setFont(font5);
        E_FloodFluxLimiter = new QSpinBox(tab_spare);
        E_FloodFluxLimiter->setObjectName("E_FloodFluxLimiter");
        E_FloodFluxLimiter->setEnabled(true);
        E_FloodFluxLimiter->setGeometry(QRect(11, 114, 35, 26));
        sizePolicy4.setHeightForWidth(E_FloodFluxLimiter->sizePolicy().hasHeightForWidth());
        E_FloodFluxLimiter->setSizePolicy(sizePolicy4);
        QPalette palette21;
        E_FloodFluxLimiter->setPalette(palette21);
        E_FloodFluxLimiter->setFont(font5);
        E_FloodFluxLimiter->setMinimum(1);
        E_FloodFluxLimiter->setMaximum(3);
        E_FloodFluxLimiter->setValue(1);
        label_130 = new QLabel(tab_spare);
        label_130->setObjectName("label_130");
        label_130->setEnabled(false);
        label_130->setGeometry(QRect(11, 507, 216, 17));
        sizePolicy3.setHeightForWidth(label_130->sizePolicy().hasHeightForWidth());
        label_130->setSizePolicy(sizePolicy3);
        label_130->setFont(font5);
        label_130->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        groupBox_RichardsOptions = new QGroupBox(tab_spare);
        groupBox_RichardsOptions->setObjectName("groupBox_RichardsOptions");
        groupBox_RichardsOptions->setGeometry(QRect(11, 436, 508, 60));
        sizePolicy4.setHeightForWidth(groupBox_RichardsOptions->sizePolicy().hasHeightForWidth());
        groupBox_RichardsOptions->setSizePolicy(sizePolicy4);
        groupBox_RichardsOptions->setFont(font7);
        gridLayout_75 = new QGridLayout(groupBox_RichardsOptions);
        gridLayout_75->setObjectName("gridLayout_75");
        gridLayout_75->setHorizontalSpacing(8);
        gridLayout_75->setVerticalSpacing(4);
        gridLayout_75->setContentsMargins(8, 4, 8, 4);
        label_152 = new QLabel(groupBox_RichardsOptions);
        label_152->setObjectName("label_152");
        sizePolicy.setHeightForWidth(label_152->sizePolicy().hasHeightForWidth());
        label_152->setSizePolicy(sizePolicy);
        label_152->setFont(font5);
        label_152->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_75->addWidget(label_152, 1, 0, 1, 1);

        spinNodes2 = new QSpinBox(groupBox_RichardsOptions);
        spinNodes2->setObjectName("spinNodes2");
        sizePolicy4.setHeightForWidth(spinNodes2->sizePolicy().hasHeightForWidth());
        spinNodes2->setSizePolicy(sizePolicy4);
        spinNodes2->setFont(font5);
        spinNodes2->setMinimum(2);
        spinNodes2->setValue(3);

        gridLayout_75->addWidget(spinNodes2, 1, 3, 1, 1);

        label_154 = new QLabel(groupBox_RichardsOptions);
        label_154->setObjectName("label_154");
        label_154->setFont(font5);

        gridLayout_75->addWidget(label_154, 1, 4, 1, 1);

        spinNodes3 = new QSpinBox(groupBox_RichardsOptions);
        spinNodes3->setObjectName("spinNodes3");
        spinNodes3->setFont(font5);
        spinNodes3->setMinimum(2);
        spinNodes3->setValue(3);

        gridLayout_75->addWidget(spinNodes3, 1, 5, 1, 1);

        label_151 = new QLabel(groupBox_RichardsOptions);
        label_151->setObjectName("label_151");
        label_151->setFont(font5);
        label_151->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_75->addWidget(label_151, 1, 2, 1, 1);

        spinNodes1 = new QSpinBox(groupBox_RichardsOptions);
        spinNodes1->setObjectName("spinNodes1");
        sizePolicy4.setHeightForWidth(spinNodes1->sizePolicy().hasHeightForWidth());
        spinNodes1->setSizePolicy(sizePolicy4);
        spinNodes1->setFont(font5);
        spinNodes1->setMinimum(2);
        spinNodes1->setValue(3);

        gridLayout_75->addWidget(spinNodes1, 1, 1, 1, 1);

        spinSoilPhysics = new QSpinBox(tab_spare);
        spinSoilPhysics->setObjectName("spinSoilPhysics");
        spinSoilPhysics->setGeometry(QRect(11, 253, 35, 26));
        sizePolicy4.setHeightForWidth(spinSoilPhysics->sizePolicy().hasHeightForWidth());
        spinSoilPhysics->setSizePolicy(sizePolicy4);
        spinSoilPhysics->setFont(font5);
        spinSoilPhysics->setMinimum(1);
        spinSoilPhysics->setMaximum(2);
        label_132 = new QLabel(tab_spare);
        label_132->setObjectName("label_132");
        label_132->setGeometry(QRect(11, 367, 357, 17));
        sizePolicy4.setHeightForWidth(label_132->sizePolicy().hasHeightForWidth());
        label_132->setSizePolicy(sizePolicy4);
        label_132->setFont(font5);
        label_132->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        checkChannelWFinflow = new QCheckBox(tab_spare);
        checkChannelWFinflow->setObjectName("checkChannelWFinflow");
        checkChannelWFinflow->setGeometry(QRect(11, 80, 374, 23));
        sizePolicy4.setHeightForWidth(checkChannelWFinflow->sizePolicy().hasHeightForWidth());
        checkChannelWFinflow->setSizePolicy(sizePolicy4);
        checkChannelWFinflow->setFont(font5);
        label_139 = new QLabel(tab_spare);
        label_139->setObjectName("label_139");
        label_139->setGeometry(QRect(11, 696, 156, 17));
        sizePolicy3.setHeightForWidth(label_139->sizePolicy().hasHeightForWidth());
        label_139->setSizePolicy(sizePolicy3);
        label_139->setFont(font5);
        label_100 = new QLabel(tab_spare);
        label_100->setObjectName("label_100");
        label_100->setEnabled(true);
        label_100->setGeometry(QRect(60, 120, 352, 17));
        sizePolicy2.setHeightForWidth(label_100->sizePolicy().hasHeightForWidth());
        label_100->setSizePolicy(sizePolicy2);
        label_100->setFont(font6);
        label_100->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_85 = new QLabel(tab_spare);
        label_85->setObjectName("label_85");
        label_85->setGeometry(QRect(11, 544, 338, 17));
        sizePolicy3.setHeightForWidth(label_85->sizePolicy().hasHeightForWidth());
        label_85->setSizePolicy(sizePolicy3);
        label_85->setFont(font5);
        checkNoSedBoundary = new QCheckBox(tab_spare);
        checkNoSedBoundary->setObjectName("checkNoSedBoundary");
        checkNoSedBoundary->setGeometry(QRect(11, 219, 309, 23));
        sizePolicy2.setHeightForWidth(checkNoSedBoundary->sizePolicy().hasHeightForWidth());
        checkNoSedBoundary->setSizePolicy(sizePolicy2);
        checkNoSedBoundary->setFont(font5);
        radioGroupSnowmelt = new QFrame(tab_spare);
        radioGroupSnowmelt->setObjectName("radioGroupSnowmelt");
        radioGroupSnowmelt->setEnabled(false);
        radioGroupSnowmelt->setGeometry(QRect(11, 615, 364, 70));
        sizePolicy4.setHeightForWidth(radioGroupSnowmelt->sizePolicy().hasHeightForWidth());
        radioGroupSnowmelt->setSizePolicy(sizePolicy4);
        radioGroupSnowmelt->setFrameShape(QFrame::Shape::Box);
        radioGroupSnowmelt->setFrameShadow(QFrame::Shadow::Sunken);
        gridLayout_49 = new QGridLayout(radioGroupSnowmelt);
        gridLayout_49->setObjectName("gridLayout_49");
        gridLayout_49->setHorizontalSpacing(8);
        gridLayout_49->setVerticalSpacing(4);
        gridLayout_49->setContentsMargins(8, 4, 8, 4);
        toolButton_SnowmeltmapShow = new QToolButton(radioGroupSnowmelt);
        toolButton_SnowmeltmapShow->setObjectName("toolButton_SnowmeltmapShow");
        toolButton_SnowmeltmapShow->setIcon(icon5);

        gridLayout_49->addWidget(toolButton_SnowmeltmapShow, 2, 3, 1, 1);

        toolButton_SnowmeltName = new QToolButton(radioGroupSnowmelt);
        toolButton_SnowmeltName->setObjectName("toolButton_SnowmeltName");
        toolButton_SnowmeltName->setIcon(icon1);

        gridLayout_49->addWidget(toolButton_SnowmeltName, 1, 2, 1, 1);

        radioButton_10 = new QRadioButton(radioGroupSnowmelt);
        radioButton_10->setObjectName("radioButton_10");
        radioButton_10->setFont(font5);

        gridLayout_49->addWidget(radioButton_10, 2, 0, 1, 1);

        radioButton = new QRadioButton(radioGroupSnowmelt);
        radioButton->setObjectName("radioButton");
        radioButton->setFont(font5);
        radioButton->setChecked(true);

        gridLayout_49->addWidget(radioButton, 1, 0, 1, 1);

        E_SnowmeltSatName = new QLineEdit(radioGroupSnowmelt);
        E_SnowmeltSatName->setObjectName("E_SnowmeltSatName");
        sizePolicy4.setHeightForWidth(E_SnowmeltSatName->sizePolicy().hasHeightForWidth());
        E_SnowmeltSatName->setSizePolicy(sizePolicy4);
        E_SnowmeltSatName->setFont(font5);

        gridLayout_49->addWidget(E_SnowmeltSatName, 2, 1, 1, 1);

        toolButton_SnowmeltSatName = new QToolButton(radioGroupSnowmelt);
        toolButton_SnowmeltSatName->setObjectName("toolButton_SnowmeltSatName");
        toolButton_SnowmeltSatName->setIcon(icon1);

        gridLayout_49->addWidget(toolButton_SnowmeltSatName, 2, 2, 1, 1);

        E_SnowmeltName = new QLineEdit(radioGroupSnowmelt);
        E_SnowmeltName->setObjectName("E_SnowmeltName");
        sizePolicy4.setHeightForWidth(E_SnowmeltName->sizePolicy().hasHeightForWidth());
        E_SnowmeltName->setSizePolicy(sizePolicy4);
        E_SnowmeltName->setFont(font5);

        gridLayout_49->addWidget(E_SnowmeltName, 1, 1, 1, 1);

        toolButton_SnowmeltShow = new QToolButton(radioGroupSnowmelt);
        toolButton_SnowmeltShow->setObjectName("toolButton_SnowmeltShow");
        toolButton_SnowmeltShow->setIcon(icon5);

        gridLayout_49->addWidget(toolButton_SnowmeltShow, 1, 3, 1, 1);

        E_DepositedCohesion = new QDoubleSpinBox(tab_spare);
        E_DepositedCohesion->setObjectName("E_DepositedCohesion");
        E_DepositedCohesion->setEnabled(false);
        E_DepositedCohesion->setGeometry(QRect(250, 500, 66, 26));
        sizePolicy4.setHeightForWidth(E_DepositedCohesion->sizePolicy().hasHeightForWidth());
        E_DepositedCohesion->setSizePolicy(sizePolicy4);
        E_DepositedCohesion->setFont(font5);
        E_DepositedCohesion->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        E_DepositedCohesion->setDecimals(2);
        E_DepositedCohesion->setMinimum(0.010000000000000);
        E_DepositedCohesion->setMaximum(100.000000000000000);
        E_DepositedCohesion->setSingleStep(0.010000000000000);
        E_DepositedCohesion->setValue(0.500000000000000);
        label_101 = new QLabel(tab_spare);
        label_101->setObjectName("label_101");
        label_101->setEnabled(false);
        label_101->setGeometry(QRect(11, 330, 200, 17));
        sizePolicy4.setHeightForWidth(label_101->sizePolicy().hasHeightForWidth());
        label_101->setSizePolicy(sizePolicy4);
        label_101->setFont(font6);
        E_SigmaDiffusion = new QDoubleSpinBox(tab_spare);
        E_SigmaDiffusion->setObjectName("E_SigmaDiffusion");
        E_SigmaDiffusion->setEnabled(false);
        E_SigmaDiffusion->setGeometry(QRect(390, 320, 52, 26));
        sizePolicy4.setHeightForWidth(E_SigmaDiffusion->sizePolicy().hasHeightForWidth());
        E_SigmaDiffusion->setSizePolicy(sizePolicy4);
        E_SigmaDiffusion->setFont(font6);
        E_SigmaDiffusion->setMinimum(0.200000000000000);
        E_SigmaDiffusion->setMaximum(1.000000000000000);
        E_SigmaDiffusion->setSingleStep(0.050000000000000);
        E_SigmaDiffusion->setValue(0.500000000000000);
        checkSnowmelt = new QCheckBox(tab_spare);
        checkSnowmelt->setObjectName("checkSnowmelt");
        checkSnowmelt->setEnabled(false);
        checkSnowmelt->setGeometry(QRect(11, 581, 85, 23));
        sizePolicy4.setHeightForWidth(checkSnowmelt->sizePolicy().hasHeightForWidth());
        checkSnowmelt->setSizePolicy(sizePolicy4);
        checkSnowmelt->setFont(font5);
        label_160 = new QLabel(tab_spare);
        label_160->setObjectName("label_160");
        label_160->setGeometry(QRect(60, 250, 394, 17));
        label_160->setFont(font5);
        label_129 = new QLabel(tab_spare);
        label_129->setObjectName("label_129");
        label_129->setGeometry(QRect(11, 15, 393, 17));
        sizePolicy4.setHeightForWidth(label_129->sizePolicy().hasHeightForWidth());
        label_129->setSizePolicy(sizePolicy4);
        label_129->setFont(font7);
        label_61 = new QLabel(tab_spare);
        label_61->setObjectName("label_61");
        label_61->setGeometry(QRect(430, 700, 71, 17));
        label_61->setFont(font5);
        E_CalibrateSD2 = new QDoubleSpinBox(tab_spare);
        E_CalibrateSD2->setObjectName("E_CalibrateSD2");
        E_CalibrateSD2->setGeometry(QRect(510, 690, 59, 26));
        sizePolicy4.setHeightForWidth(E_CalibrateSD2->sizePolicy().hasHeightForWidth());
        E_CalibrateSD2->setSizePolicy(sizePolicy4);
        E_CalibrateSD2->setFont(font5);
        E_CalibrateSD2->setMinimum(0.000000000000000);
        E_CalibrateSD2->setMaximum(10.000000000000000);
        E_CalibrateSD2->setSingleStep(0.010000000000000);
        E_CalibrateSD2->setValue(1.000000000000000);
        GW_slope = new QDoubleSpinBox(tab_spare);
        GW_slope->setObjectName("GW_slope");
        GW_slope->setGeometry(QRect(370, 540, 59, 26));
        sizePolicy4.setHeightForWidth(GW_slope->sizePolicy().hasHeightForWidth());
        GW_slope->setSizePolicy(sizePolicy4);
        GW_slope->setFont(font5);
        GW_slope->setMinimum(0.100000000000000);
        GW_slope->setMaximum(10.000000000000000);
        GW_slope->setSingleStep(0.100000000000000);
        GW_slope->setValue(1.000000000000000);
        checkKETimebased = new QCheckBox(tab_spare);
        checkKETimebased->setObjectName("checkKETimebased");
        checkKETimebased->setEnabled(true);
        checkKETimebased->setGeometry(QRect(11, 185, 94, 23));
        sizePolicy4.setHeightForWidth(checkKETimebased->sizePolicy().hasHeightForWidth());
        checkKETimebased->setSizePolicy(sizePolicy4);
        QPalette palette22;
        checkKETimebased->setPalette(palette22);
        checkKETimebased->setFont(font5);
        checkLinkedList = new QCheckBox(tab_spare);
        checkLinkedList->setObjectName("checkLinkedList");
        checkLinkedList->setEnabled(true);
        checkLinkedList->setGeometry(QRect(120, 180, 1792, 23));
        sizePolicy2.setHeightForWidth(checkLinkedList->sizePolicy().hasHeightForWidth());
        checkLinkedList->setSizePolicy(sizePolicy2);
        checkLinkedList->setFont(font5);
        checkLinkedList->setChecked(false);
        E_ChannelKinWaveDt = new QDoubleSpinBox(tab_spare);
        E_ChannelKinWaveDt->setObjectName("E_ChannelKinWaveDt");
        E_ChannelKinWaveDt->setEnabled(false);
        E_ChannelKinWaveDt->setGeometry(QRect(280, 290, 61, 26));
        sizePolicy4.setHeightForWidth(E_ChannelKinWaveDt->sizePolicy().hasHeightForWidth());
        E_ChannelKinWaveDt->setSizePolicy(sizePolicy4);
        E_ChannelKinWaveDt->setFont(font5);
        E_ChannelKinWaveDt->setDecimals(0);
        E_ChannelKinWaveDt->setMinimum(10.000000000000000);
        E_ChannelKinWaveDt->setMaximum(120.000000000000000);
        E_ChannelKinWaveDt->setSingleStep(10.000000000000000);
        E_ChannelKinWaveDt->setValue(60.000000000000000);
        checkKinWaveChannel = new QCheckBox(tab_spare);
        checkKinWaveChannel->setObjectName("checkKinWaveChannel");
        checkKinWaveChannel->setEnabled(true);
        checkKinWaveChannel->setGeometry(QRect(350, 290, 204, 23));
        sizePolicy4.setHeightForWidth(checkKinWaveChannel->sizePolicy().hasHeightForWidth());
        checkKinWaveChannel->setSizePolicy(sizePolicy4);
        checkKinWaveChannel->setFont(font5);
        checkKinWaveChannel->setChecked(false);
        checkStationaryBaseflow = new QCheckBox(tab_spare);
        checkStationaryBaseflow->setObjectName("checkStationaryBaseflow");
        checkStationaryBaseflow->setGeometry(QRect(10, 50, 1792, 22));
        checkStationaryBaseflow->setFont(font5);
        checkChannelInfil = new QCheckBox(tab_spare);
        checkChannelInfil->setObjectName("checkChannelInfil");
        checkChannelInfil->setEnabled(true);
        checkChannelInfil->setGeometry(QRect(120, 100, 1792, 22));
        sizePolicy2.setHeightForWidth(checkChannelInfil->sizePolicy().hasHeightForWidth());
        checkChannelInfil->setSizePolicy(sizePolicy2);
        checkChannelInfil->setFont(font5);
        tabWidgetOptions->addTab(tab_spare, QString());

        gridLayout_54->addWidget(tabWidgetOptions, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_37->addWidget(scrollArea, 15, 0, 1, 1);

        groupBox_dbase = new QGroupBox(groupBoxInput);
        groupBox_dbase->setObjectName("groupBox_dbase");
        sizePolicy2.setHeightForWidth(groupBox_dbase->sizePolicy().hasHeightForWidth());
        groupBox_dbase->setSizePolicy(sizePolicy2);
        groupBox_dbase->setFont(font3);
        gridLayout_7 = new QGridLayout(groupBox_dbase);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setHorizontalSpacing(4);
        gridLayout_7->setVerticalSpacing(2);
        gridLayout_7->setContentsMargins(4, 2, 4, 4);
        label_1 = new QLabel(groupBox_dbase);
        label_1->setObjectName("label_1");
        sizePolicy3.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy3);
        label_1->setFont(font1);
        label_1->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_1->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(label_1, 0, 0, 1, 1);

        toolButton_fileOpen = new QToolButton(groupBox_dbase);
        toolButton_fileOpen->setObjectName("toolButton_fileOpen");
        toolButton_fileOpen->setEnabled(true);
        sizePolicy4.setHeightForWidth(toolButton_fileOpen->sizePolicy().hasHeightForWidth());
        toolButton_fileOpen->setSizePolicy(sizePolicy4);
        toolButton_fileOpen->setIcon(icon1);
        toolButton_fileOpen->setAutoRaise(false);

        gridLayout_7->addWidget(toolButton_fileOpen, 0, 3, 1, 1);

        toolButton_MapDir = new QToolButton(groupBox_dbase);
        toolButton_MapDir->setObjectName("toolButton_MapDir");
        sizePolicy4.setHeightForWidth(toolButton_MapDir->sizePolicy().hasHeightForWidth());
        toolButton_MapDir->setSizePolicy(sizePolicy4);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/2X/Folder-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_MapDir->setIcon(icon15);
        toolButton_MapDir->setAutoRaise(false);

        gridLayout_7->addWidget(toolButton_MapDir, 1, 3, 1, 1);

        toolButton_ResultDir = new QToolButton(groupBox_dbase);
        toolButton_ResultDir->setObjectName("toolButton_ResultDir");
        sizePolicy4.setHeightForWidth(toolButton_ResultDir->sizePolicy().hasHeightForWidth());
        toolButton_ResultDir->setSizePolicy(sizePolicy4);
        toolButton_ResultDir->setIcon(icon15);

        gridLayout_7->addWidget(toolButton_ResultDir, 3, 3, 1, 1);

        label_2 = new QLabel(groupBox_dbase);
        label_2->setObjectName("label_2");
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(label_2, 1, 0, 2, 1);

        toolButton_deleteRun = new QToolButton(groupBox_dbase);
        toolButton_deleteRun->setObjectName("toolButton_deleteRun");
        sizePolicy4.setHeightForWidth(toolButton_deleteRun->sizePolicy().hasHeightForWidth());
        toolButton_deleteRun->setSizePolicy(sizePolicy4);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/2X/File-Delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_deleteRun->setIcon(icon16);
        toolButton_deleteRun->setAutoRaise(false);

        gridLayout_7->addWidget(toolButton_deleteRun, 0, 5, 1, 1);

        E_MapDir = new QLineEdit(groupBox_dbase);
        E_MapDir->setObjectName("E_MapDir");
        sizePolicy2.setHeightForWidth(E_MapDir->sizePolicy().hasHeightForWidth());
        E_MapDir->setSizePolicy(sizePolicy2);
        E_MapDir->setFont(font1);

        gridLayout_7->addWidget(E_MapDir, 1, 1, 2, 2);

        E_runFileList = new QComboBox(groupBox_dbase);
        E_runFileList->setObjectName("E_runFileList");
        sizePolicy2.setHeightForWidth(E_runFileList->sizePolicy().hasHeightForWidth());
        E_runFileList->setSizePolicy(sizePolicy2);
        E_runFileList->setFont(font1);
        E_runFileList->setEditable(true);
        E_runFileList->setDuplicatesEnabled(false);

        gridLayout_7->addWidget(E_runFileList, 0, 1, 1, 2);

        label_3 = new QLabel(groupBox_dbase);
        label_3->setObjectName("label_3");
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(label_3, 3, 0, 1, 1);

        toolButton_ShowRunfile = new QToolButton(groupBox_dbase);
        toolButton_ShowRunfile->setObjectName("toolButton_ShowRunfile");
        toolButton_ShowRunfile->setEnabled(true);
        sizePolicy4.setHeightForWidth(toolButton_ShowRunfile->sizePolicy().hasHeightForWidth());
        toolButton_ShowRunfile->setSizePolicy(sizePolicy4);
        toolButton_ShowRunfile->setIcon(icon5);
        toolButton_ShowRunfile->setAutoRaise(false);

        gridLayout_7->addWidget(toolButton_ShowRunfile, 0, 4, 1, 1);

        E_ResultDir = new QLineEdit(groupBox_dbase);
        E_ResultDir->setObjectName("E_ResultDir");
        sizePolicy2.setHeightForWidth(E_ResultDir->sizePolicy().hasHeightForWidth());
        E_ResultDir->setSizePolicy(sizePolicy2);
        E_ResultDir->setFont(font1);

        gridLayout_7->addWidget(E_ResultDir, 3, 1, 1, 2);

        checkAddDatetime = new QCheckBox(groupBox_dbase);
        checkAddDatetime->setObjectName("checkAddDatetime");
        checkAddDatetime->setFont(font1);

        gridLayout_7->addWidget(checkAddDatetime, 3, 4, 1, 2);


        gridLayout_37->addWidget(groupBox_dbase, 0, 0, 1, 1);


        gridLayout_23->addWidget(groupBoxInput, 0, 0, 1, 1);

        tabWidget->addTab(tab_input, QString());
        tab_maps = new QWidget();
        tab_maps->setObjectName("tab_maps");
        gridLayout_12 = new QGridLayout(tab_maps);
        gridLayout_12->setObjectName("gridLayout_12");
        label_47 = new QLabel(tab_maps);
        label_47->setObjectName("label_47");

        gridLayout_12->addWidget(label_47, 0, 0, 1, 1);

        groupBox_InputMaps = new QGroupBox(tab_maps);
        groupBox_InputMaps->setObjectName("groupBox_InputMaps");
        QSizePolicy sizePolicy10(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(groupBox_InputMaps->sizePolicy().hasHeightForWidth());
        groupBox_InputMaps->setSizePolicy(sizePolicy10);
        gridLayout_10 = new QGridLayout(groupBox_InputMaps);
        gridLayout_10->setObjectName("gridLayout_10");
        checkExpandActive = new QCheckBox(groupBox_InputMaps);
        checkExpandActive->setObjectName("checkExpandActive");

        gridLayout_10->addWidget(checkExpandActive, 1, 1, 1, 1);

        treeView = new QTreeView(groupBox_InputMaps);
        treeView->setObjectName("treeView");
        QSizePolicy sizePolicy11(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy11);
        treeView->setFrameShape(QFrame::Shape::StyledPanel);
        treeView->setFrameShadow(QFrame::Shadow::Sunken);
        treeView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);

        gridLayout_10->addWidget(treeView, 0, 1, 1, 1);


        gridLayout_12->addWidget(groupBox_InputMaps, 1, 0, 1, 1);

        tabWidget->addTab(tab_maps, QString());
        tab_simulation = new QWidget();
        tab_simulation->setObjectName("tab_simulation");
        gridLayout_27 = new QGridLayout(tab_simulation);
        gridLayout_27->setObjectName("gridLayout_27");
        frameSImInfo = new QFrame(tab_simulation);
        frameSImInfo->setObjectName("frameSImInfo");
        sizePolicy3.setHeightForWidth(frameSImInfo->sizePolicy().hasHeightForWidth());
        frameSImInfo->setSizePolicy(sizePolicy3);
        verticalLayout_2 = new QVBoxLayout(frameSImInfo);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(8, 8, 8, 8);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        groupTime = new QGroupBox(frameSImInfo);
        groupTime->setObjectName("groupTime");
        sizePolicy2.setHeightForWidth(groupTime->sizePolicy().hasHeightForWidth());
        groupTime->setSizePolicy(sizePolicy2);
        groupTime->setFont(font3);
        gridLayout_13 = new QGridLayout(groupTime);
        gridLayout_13->setObjectName("gridLayout_13");
        gridLayout_13->setHorizontalSpacing(4);
        gridLayout_13->setVerticalSpacing(2);
        gridLayout_13->setContentsMargins(0, 4, 0, 2);
        label_endtime = new QLabel(groupTime);
        label_endtime->setObjectName("label_endtime");
        sizePolicy2.setHeightForWidth(label_endtime->sizePolicy().hasHeightForWidth());
        label_endtime->setSizePolicy(sizePolicy2);
        label_endtime->setFont(font1);
        label_endtime->setFrameShape(QFrame::Shape::StyledPanel);
        label_endtime->setFrameShadow(QFrame::Shadow::Plain);
        label_endtime->setLineWidth(1);
        label_endtime->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_13->addWidget(label_endtime, 0, 3, 1, 1);

        label_area = new QLabel(groupTime);
        label_area->setObjectName("label_area");
        sizePolicy2.setHeightForWidth(label_area->sizePolicy().hasHeightForWidth());
        label_area->setSizePolicy(sizePolicy2);
        label_area->setFont(font1);
        label_area->setFrameShape(QFrame::Shape::StyledPanel);
        label_area->setFrameShadow(QFrame::Shadow::Plain);
        label_area->setLineWidth(1);
        label_area->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_13->addWidget(label_area, 2, 3, 1, 1);

        label_time = new QLabel(groupTime);
        label_time->setObjectName("label_time");
        sizePolicy2.setHeightForWidth(label_time->sizePolicy().hasHeightForWidth());
        label_time->setSizePolicy(sizePolicy2);
        label_time->setFont(font1);
        label_time->setFrameShape(QFrame::Shape::StyledPanel);
        label_time->setFrameShadow(QFrame::Shadow::Plain);
        label_time->setLineWidth(1);
        label_time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_13->addWidget(label_time, 0, 1, 1, 1);

        label_29 = new QLabel(groupTime);
        label_29->setObjectName("label_29");
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setFont(font1);
        label_29->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_13->addWidget(label_29, 0, 0, 1, 1);

        label_dx = new QLabel(groupTime);
        label_dx->setObjectName("label_dx");
        sizePolicy2.setHeightForWidth(label_dx->sizePolicy().hasHeightForWidth());
        label_dx->setSizePolicy(sizePolicy2);
        label_dx->setFont(font1);
        label_dx->setFrameShape(QFrame::Shape::StyledPanel);
        label_dx->setFrameShadow(QFrame::Shadow::Plain);
        label_dx->setLineWidth(1);
        label_dx->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_13->addWidget(label_dx, 2, 1, 1, 1);

        label_46 = new QLabel(groupTime);
        label_46->setObjectName("label_46");
        sizePolicy.setHeightForWidth(label_46->sizePolicy().hasHeightForWidth());
        label_46->setSizePolicy(sizePolicy);
        label_46->setFont(font1);
        label_46->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_13->addWidget(label_46, 2, 0, 1, 1);

        label_38 = new QLabel(groupTime);
        label_38->setObjectName("label_38");
        sizePolicy.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy);
        label_38->setFont(font1);
        label_38->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_13->addWidget(label_38, 0, 2, 1, 1);

        label_48 = new QLabel(groupTime);
        label_48->setObjectName("label_48");
        sizePolicy.setHeightForWidth(label_48->sizePolicy().hasHeightForWidth());
        label_48->setSizePolicy(sizePolicy);
        label_48->setFont(font1);
        label_48->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_13->addWidget(label_48, 2, 2, 1, 1);


        verticalLayout->addWidget(groupTime);

        tabWidget_totout = new QTabWidget(frameSImInfo);
        tabWidget_totout->setObjectName("tabWidget_totout");
        QSizePolicy sizePolicy12(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(tabWidget_totout->sizePolicy().hasHeightForWidth());
        tabWidget_totout->setSizePolicy(sizePolicy12);
        tabWidget_totout->setFont(font3);
        tab_water = new QWidget();
        tab_water->setObjectName("tab_water");
        gridLayout_59 = new QGridLayout(tab_water);
        gridLayout_59->setObjectName("gridLayout_59");
        watergrouptotals = new QWidget(tab_water);
        watergrouptotals->setObjectName("watergrouptotals");
        sizePolicy.setHeightForWidth(watergrouptotals->sizePolicy().hasHeightForWidth());
        watergrouptotals->setSizePolicy(sizePolicy);
        watergrouptotals->setFont(font3);
        gridLayout_15 = new QGridLayout(watergrouptotals);
        gridLayout_15->setSpacing(4);
        gridLayout_15->setObjectName("gridLayout_15");
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        label_35 = new QLabel(watergrouptotals);
        label_35->setObjectName("label_35");
        sizePolicy2.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy2);
        label_35->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_35, 0, 0, 1, 1);

        label_64 = new QLabel(watergrouptotals);
        label_64->setObjectName("label_64");
        sizePolicy2.setHeightForWidth(label_64->sizePolicy().hasHeightForWidth());
        label_64->setSizePolicy(sizePolicy2);
        label_64->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_64, 0, 2, 1, 1);

        label_32 = new QLabel(watergrouptotals);
        label_32->setObjectName("label_32");
        sizePolicy2.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy2);
        label_32->setFont(font1);
        label_32->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_32, 1, 0, 1, 1);

        label_raintot = new QLabel(watergrouptotals);
        label_raintot->setObjectName("label_raintot");
        sizePolicy7.setHeightForWidth(label_raintot->sizePolicy().hasHeightForWidth());
        label_raintot->setSizePolicy(sizePolicy7);
        label_raintot->setFont(font1);
        label_raintot->setAutoFillBackground(false);
        label_raintot->setFrameShape(QFrame::Shape::StyledPanel);
        label_raintot->setFrameShadow(QFrame::Shadow::Plain);
        label_raintot->setLineWidth(1);
        label_raintot->setMidLineWidth(0);
        label_raintot->setScaledContents(false);
        label_raintot->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_raintot->setMargin(0);

        gridLayout_15->addWidget(label_raintot, 1, 1, 1, 1);

        label_40 = new QLabel(watergrouptotals);
        label_40->setObjectName("label_40");
        sizePolicy2.setHeightForWidth(label_40->sizePolicy().hasHeightForWidth());
        label_40->setSizePolicy(sizePolicy2);
        label_40->setFont(font1);
        label_40->setFrameShape(QFrame::Shape::NoFrame);
        label_40->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_40, 1, 2, 1, 1);

        label_watervoltot = new QLabel(watergrouptotals);
        label_watervoltot->setObjectName("label_watervoltot");
        sizePolicy7.setHeightForWidth(label_watervoltot->sizePolicy().hasHeightForWidth());
        label_watervoltot->setSizePolicy(sizePolicy7);
        label_watervoltot->setFont(font1);
        label_watervoltot->setFrameShape(QFrame::Shape::StyledPanel);
        label_watervoltot->setFrameShadow(QFrame::Shadow::Plain);
        label_watervoltot->setLineWidth(1);
        label_watervoltot->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_watervoltot->setMargin(0);

        gridLayout_15->addWidget(label_watervoltot, 1, 3, 1, 1);

        label_34 = new QLabel(watergrouptotals);
        label_34->setObjectName("label_34");
        sizePolicy2.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy2);
        label_34->setFont(font1);
        label_34->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_34, 2, 0, 1, 1);

        label_interctot = new QLabel(watergrouptotals);
        label_interctot->setObjectName("label_interctot");
        sizePolicy7.setHeightForWidth(label_interctot->sizePolicy().hasHeightForWidth());
        label_interctot->setSizePolicy(sizePolicy7);
        label_interctot->setFont(font1);
        label_interctot->setFrameShape(QFrame::Shape::StyledPanel);
        label_interctot->setFrameShadow(QFrame::Shadow::Plain);
        label_interctot->setLineWidth(1);
        label_interctot->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_interctot->setMargin(0);

        gridLayout_15->addWidget(label_interctot, 2, 1, 1, 1);

        label_107 = new QLabel(watergrouptotals);
        label_107->setObjectName("label_107");
        label_107->setEnabled(true);
        sizePolicy2.setHeightForWidth(label_107->sizePolicy().hasHeightForWidth());
        label_107->setSizePolicy(sizePolicy2);
        label_107->setFont(font1);
        label_107->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_107, 2, 2, 1, 1);

        label_floodVolmm = new QLabel(watergrouptotals);
        label_floodVolmm->setObjectName("label_floodVolmm");
        label_floodVolmm->setEnabled(true);
        sizePolicy7.setHeightForWidth(label_floodVolmm->sizePolicy().hasHeightForWidth());
        label_floodVolmm->setSizePolicy(sizePolicy7);
        label_floodVolmm->setFont(font1);
        label_floodVolmm->setFrameShape(QFrame::Shape::StyledPanel);
        label_floodVolmm->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_floodVolmm, 2, 3, 1, 1);

        label_36 = new QLabel(watergrouptotals);
        label_36->setObjectName("label_36");
        sizePolicy2.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy2);
        label_36->setFont(font1);
        label_36->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_36, 3, 0, 1, 1);

        label_infiltot = new QLabel(watergrouptotals);
        label_infiltot->setObjectName("label_infiltot");
        sizePolicy7.setHeightForWidth(label_infiltot->sizePolicy().hasHeightForWidth());
        label_infiltot->setSizePolicy(sizePolicy7);
        label_infiltot->setFont(font1);
        label_infiltot->setFrameShape(QFrame::Shape::StyledPanel);
        label_infiltot->setFrameShadow(QFrame::Shadow::Plain);
        label_infiltot->setLineWidth(1);
        label_infiltot->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_infiltot->setMargin(0);

        gridLayout_15->addWidget(label_infiltot, 3, 1, 1, 1);

        label_95 = new QLabel(watergrouptotals);
        label_95->setObjectName("label_95");
        sizePolicy2.setHeightForWidth(label_95->sizePolicy().hasHeightForWidth());
        label_95->setSizePolicy(sizePolicy2);
        label_95->setFont(font1);
        label_95->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_95, 3, 2, 1, 1);

        label_watervolchannel = new QLabel(watergrouptotals);
        label_watervolchannel->setObjectName("label_watervolchannel");
        label_watervolchannel->setEnabled(true);
        sizePolicy7.setHeightForWidth(label_watervolchannel->sizePolicy().hasHeightForWidth());
        label_watervolchannel->setSizePolicy(sizePolicy7);
        label_watervolchannel->setFont(font1);
        label_watervolchannel->setFrameShape(QFrame::Shape::StyledPanel);
        label_watervolchannel->setFrameShadow(QFrame::Shadow::Plain);
        label_watervolchannel->setLineWidth(1);
        label_watervolchannel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_watervolchannel->setMargin(0);

        gridLayout_15->addWidget(label_watervolchannel, 3, 3, 1, 1);

        label_37 = new QLabel(watergrouptotals);
        label_37->setObjectName("label_37");
        sizePolicy2.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy2);
        label_37->setFont(font1);
        label_37->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_37, 4, 0, 1, 1);

        label_surfstor = new QLabel(watergrouptotals);
        label_surfstor->setObjectName("label_surfstor");
        sizePolicy7.setHeightForWidth(label_surfstor->sizePolicy().hasHeightForWidth());
        label_surfstor->setSizePolicy(sizePolicy7);
        label_surfstor->setFont(font1);
        label_surfstor->setFrameShape(QFrame::Shape::StyledPanel);
        label_surfstor->setFrameShadow(QFrame::Shadow::Plain);
        label_surfstor->setLineWidth(1);
        label_surfstor->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_surfstor->setMargin(0);

        gridLayout_15->addWidget(label_surfstor, 4, 1, 1, 1);

        label_42 = new QLabel(watergrouptotals);
        label_42->setObjectName("label_42");
        sizePolicy2.setHeightForWidth(label_42->sizePolicy().hasHeightForWidth());
        label_42->setSizePolicy(sizePolicy2);
        label_42->setFont(font1);
        label_42->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_42, 4, 2, 1, 1);

        label_qtot = new QLabel(watergrouptotals);
        label_qtot->setObjectName("label_qtot");
        sizePolicy7.setHeightForWidth(label_qtot->sizePolicy().hasHeightForWidth());
        label_qtot->setSizePolicy(sizePolicy7);
        label_qtot->setFont(font1);
        label_qtot->setFrameShape(QFrame::Shape::StyledPanel);
        label_qtot->setFrameShadow(QFrame::Shadow::Plain);
        label_qtot->setLineWidth(1);
        label_qtot->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_qtot->setMargin(0);

        gridLayout_15->addWidget(label_qtot, 4, 3, 1, 1);

        label_124 = new QLabel(watergrouptotals);
        label_124->setObjectName("label_124");
        sizePolicy2.setHeightForWidth(label_124->sizePolicy().hasHeightForWidth());
        label_124->setSizePolicy(sizePolicy2);
        label_124->setFont(font1);
        label_124->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_124, 5, 0, 1, 1);

        label_ETatot = new QLabel(watergrouptotals);
        label_ETatot->setObjectName("label_ETatot");
        sizePolicy7.setHeightForWidth(label_ETatot->sizePolicy().hasHeightForWidth());
        label_ETatot->setSizePolicy(sizePolicy7);
        label_ETatot->setFont(font1);
        label_ETatot->setFrameShape(QFrame::Shape::StyledPanel);
        label_ETatot->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_ETatot, 5, 1, 1, 1);

        label_99 = new QLabel(watergrouptotals);
        label_99->setObjectName("label_99");
        sizePolicy2.setHeightForWidth(label_99->sizePolicy().hasHeightForWidth());
        label_99->setSizePolicy(sizePolicy2);
        label_99->setFont(font1);
        label_99->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_99, 5, 2, 1, 1);

        label_stormdraintot = new QLabel(watergrouptotals);
        label_stormdraintot->setObjectName("label_stormdraintot");
        sizePolicy7.setHeightForWidth(label_stormdraintot->sizePolicy().hasHeightForWidth());
        label_stormdraintot->setSizePolicy(sizePolicy7);
        label_stormdraintot->setFont(font1);
        label_stormdraintot->setFrameShape(QFrame::Shape::StyledPanel);
        label_stormdraintot->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_15->addWidget(label_stormdraintot, 5, 3, 1, 1);


        gridLayout_59->addWidget(watergrouptotals, 0, 0, 1, 1);

        tabWidget_totout->addTab(tab_water, QString());
        tab_sed = new QWidget();
        tab_sed->setObjectName("tab_sed");
        gridLayout_62 = new QGridLayout(tab_sed);
        gridLayout_62->setObjectName("gridLayout_62");
        sedgrouptotals = new QWidget(tab_sed);
        sedgrouptotals->setObjectName("sedgrouptotals");
        sizePolicy.setHeightForWidth(sedgrouptotals->sizePolicy().hasHeightForWidth());
        sedgrouptotals->setSizePolicy(sizePolicy);
        sedgrouptotals->setFont(font3);
        gridLayout_9 = new QGridLayout(sedgrouptotals);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setHorizontalSpacing(4);
        gridLayout_9->setVerticalSpacing(2);
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_soilloss = new QLabel(sedgrouptotals);
        label_soilloss->setObjectName("label_soilloss");
        sizePolicy7.setHeightForWidth(label_soilloss->sizePolicy().hasHeightForWidth());
        label_soilloss->setSizePolicy(sizePolicy7);
        label_soilloss->setFont(font1);
        label_soilloss->setFrameShape(QFrame::Shape::StyledPanel);
        label_soilloss->setFrameShadow(QFrame::Shadow::Plain);
        label_soilloss->setLineWidth(1);
        label_soilloss->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_soilloss, 6, 1, 1, 1);

        label_depch = new QLabel(sedgrouptotals);
        label_depch->setObjectName("label_depch");
        sizePolicy7.setHeightForWidth(label_depch->sizePolicy().hasHeightForWidth());
        label_depch->setSizePolicy(sizePolicy7);
        label_depch->setFont(font1);
        label_depch->setFrameShape(QFrame::Shape::StyledPanel);
        label_depch->setFrameShadow(QFrame::Shadow::Plain);
        label_depch->setLineWidth(1);
        label_depch->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_depch, 2, 3, 1, 1);

        label_flowdet = new QLabel(sedgrouptotals);
        label_flowdet->setObjectName("label_flowdet");
        sizePolicy7.setHeightForWidth(label_flowdet->sizePolicy().hasHeightForWidth());
        label_flowdet->setSizePolicy(sizePolicy7);
        label_flowdet->setFont(font1);
        label_flowdet->setFrameShape(QFrame::Shape::StyledPanel);
        label_flowdet->setFrameShadow(QFrame::Shadow::Plain);
        label_flowdet->setLineWidth(1);
        label_flowdet->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_flowdet, 2, 1, 1, 1);

        label_21 = new QLabel(sedgrouptotals);
        label_21->setObjectName("label_21");
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);
        label_21->setFont(font1);
        label_21->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_21, 1, 0, 1, 1);

        label_sedvol = new QLabel(sedgrouptotals);
        label_sedvol->setObjectName("label_sedvol");
        sizePolicy7.setHeightForWidth(label_sedvol->sizePolicy().hasHeightForWidth());
        label_sedvol->setSizePolicy(sizePolicy7);
        label_sedvol->setFont(font1);
        label_sedvol->setFrameShape(QFrame::Shape::StyledPanel);
        label_sedvol->setFrameShadow(QFrame::Shadow::Plain);
        label_sedvol->setLineWidth(1);
        label_sedvol->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_sedvol, 4, 1, 1, 1);

        label_23 = new QLabel(sedgrouptotals);
        label_23->setObjectName("label_23");
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);
        label_23->setFont(font1);
        label_23->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_23, 2, 0, 1, 1);

        label_splashdet = new QLabel(sedgrouptotals);
        label_splashdet->setObjectName("label_splashdet");
        sizePolicy7.setHeightForWidth(label_splashdet->sizePolicy().hasHeightForWidth());
        label_splashdet->setSizePolicy(sizePolicy7);
        label_splashdet->setFont(font1);
        label_splashdet->setFrameShape(QFrame::Shape::StyledPanel);
        label_splashdet->setFrameShadow(QFrame::Shadow::Plain);
        label_splashdet->setLineWidth(1);
        label_splashdet->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_splashdet, 1, 1, 1, 1);

        label_dep = new QLabel(sedgrouptotals);
        label_dep->setObjectName("label_dep");
        sizePolicy7.setHeightForWidth(label_dep->sizePolicy().hasHeightForWidth());
        label_dep->setSizePolicy(sizePolicy7);
        label_dep->setFont(font1);
        label_dep->setFrameShape(QFrame::Shape::StyledPanel);
        label_dep->setFrameShadow(QFrame::Shadow::Plain);
        label_dep->setLineWidth(1);
        label_dep->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_dep, 3, 1, 1, 1);

        label_soillosskgha = new QLabel(sedgrouptotals);
        label_soillosskgha->setObjectName("label_soillosskgha");
        sizePolicy7.setHeightForWidth(label_soillosskgha->sizePolicy().hasHeightForWidth());
        label_soillosskgha->setSizePolicy(sizePolicy7);
        label_soillosskgha->setFont(font1);
        label_soillosskgha->setFrameShape(QFrame::Shape::StyledPanel);
        label_soillosskgha->setFrameShadow(QFrame::Shadow::Plain);
        label_soillosskgha->setLineWidth(1);
        label_soillosskgha->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_soillosskgha, 6, 3, 1, 1);

        label_25 = new QLabel(sedgrouptotals);
        label_25->setObjectName("label_25");
        sizePolicy2.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy2);
        label_25->setFont(font1);
        label_25->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_25, 4, 0, 1, 1);

        label_39 = new QLabel(sedgrouptotals);
        label_39->setObjectName("label_39");
        sizePolicy2.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy2);
        label_39->setFont(font1);
        label_39->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_39, 3, 2, 1, 1);

        label_41 = new QLabel(sedgrouptotals);
        label_41->setObjectName("label_41");
        sizePolicy2.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy2);
        label_41->setFont(font1);
        label_41->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_41, 1, 2, 1, 1);

        label_43 = new QLabel(sedgrouptotals);
        label_43->setObjectName("label_43");
        sizePolicy2.setHeightForWidth(label_43->sizePolicy().hasHeightForWidth());
        label_43->setSizePolicy(sizePolicy2);
        label_43->setFont(font1);
        label_43->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_43, 2, 2, 1, 1);

        label_51 = new QLabel(sedgrouptotals);
        label_51->setObjectName("label_51");
        sizePolicy2.setHeightForWidth(label_51->sizePolicy().hasHeightForWidth());
        label_51->setSizePolicy(sizePolicy2);
        label_51->setFont(font3);
        label_51->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_51, 0, 0, 1, 1);

        label_sedvolch = new QLabel(sedgrouptotals);
        label_sedvolch->setObjectName("label_sedvolch");
        sizePolicy7.setHeightForWidth(label_sedvolch->sizePolicy().hasHeightForWidth());
        label_sedvolch->setSizePolicy(sizePolicy7);
        label_sedvolch->setFont(font1);
        label_sedvolch->setFrameShape(QFrame::Shape::StyledPanel);
        label_sedvolch->setFrameShadow(QFrame::Shadow::Plain);
        label_sedvolch->setLineWidth(1);
        label_sedvolch->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_sedvolch, 3, 3, 1, 1);

        label_31 = new QLabel(sedgrouptotals);
        label_31->setObjectName("label_31");
        sizePolicy2.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy2);
        label_31->setFont(font1);
        label_31->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_31, 6, 2, 1, 1);

        label_50 = new QLabel(sedgrouptotals);
        label_50->setObjectName("label_50");
        sizePolicy2.setHeightForWidth(label_50->sizePolicy().hasHeightForWidth());
        label_50->setSizePolicy(sizePolicy2);
        label_50->setFont(font3);
        label_50->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_50, 0, 2, 1, 1);

        label_27 = new QLabel(sedgrouptotals);
        label_27->setObjectName("label_27");
        sizePolicy2.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy2);
        label_27->setFont(font1);
        label_27->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_27, 3, 0, 1, 1);

        label_detch = new QLabel(sedgrouptotals);
        label_detch->setObjectName("label_detch");
        sizePolicy7.setHeightForWidth(label_detch->sizePolicy().hasHeightForWidth());
        label_detch->setSizePolicy(sizePolicy7);
        label_detch->setFont(font1);
        label_detch->setFrameShape(QFrame::Shape::StyledPanel);
        label_detch->setFrameShadow(QFrame::Shadow::Plain);
        label_detch->setLineWidth(1);
        label_detch->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_detch, 1, 3, 1, 1);

        label_28 = new QLabel(sedgrouptotals);
        label_28->setObjectName("label_28");
        sizePolicy2.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy2);
        label_28->setFont(font1);
        label_28->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_28, 6, 0, 1, 1);

        label_60 = new QLabel(sedgrouptotals);
        label_60->setObjectName("label_60");
        sizePolicy2.setHeightForWidth(label_60->sizePolicy().hasHeightForWidth());
        label_60->setSizePolicy(sizePolicy2);
        QFont font12;
        font12.setPointSize(8);
        font12.setBold(false);
        font12.setItalic(false);
        label_60->setFont(font12);
        label_60->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_60, 4, 2, 1, 1);

        label_SDR = new QLabel(sedgrouptotals);
        label_SDR->setObjectName("label_SDR");
        sizePolicy7.setHeightForWidth(label_SDR->sizePolicy().hasHeightForWidth());
        label_SDR->setSizePolicy(sizePolicy7);
        label_SDR->setFont(font1);
        label_SDR->setFrameShape(QFrame::Shape::StyledPanel);
        label_SDR->setFrameShadow(QFrame::Shadow::Plain);
        label_SDR->setLineWidth(1);
        label_SDR->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_9->addWidget(label_SDR, 4, 3, 1, 1);


        gridLayout_62->addWidget(sedgrouptotals, 0, 0, 1, 1);

        tabWidget_totout->addTab(tab_sed, QString());

        verticalLayout->addWidget(tabWidget_totout);

        outletgroup = new QGroupBox(frameSImInfo);
        outletgroup->setObjectName("outletgroup");
        sizePolicy2.setHeightForWidth(outletgroup->sizePolicy().hasHeightForWidth());
        outletgroup->setSizePolicy(sizePolicy2);
        outletgroup->setFont(font3);
        gridLayout_14 = new QGridLayout(outletgroup);
        gridLayout_14->setObjectName("gridLayout_14");
        gridLayout_14->setHorizontalSpacing(4);
        gridLayout_14->setVerticalSpacing(2);
        gridLayout_14->setContentsMargins(0, 4, 0, 2);
        label_qpeaksub = new QLabel(outletgroup);
        label_qpeaksub->setObjectName("label_qpeaksub");
        sizePolicy7.setHeightForWidth(label_qpeaksub->sizePolicy().hasHeightForWidth());
        label_qpeaksub->setSizePolicy(sizePolicy7);
        label_qpeaksub->setFont(font1);
        label_qpeaksub->setFrameShape(QFrame::Shape::StyledPanel);
        label_qpeaksub->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_qpeaksub, 0, 5, 1, 1);

        label_soillosssub = new QLabel(outletgroup);
        label_soillosssub->setObjectName("label_soillosssub");
        sizePolicy7.setHeightForWidth(label_soillosssub->sizePolicy().hasHeightForWidth());
        label_soillosssub->setSizePolicy(sizePolicy7);
        label_soillosssub->setFont(font1);
        label_soillosssub->setFrameShape(QFrame::Shape::StyledPanel);
        label_soillosssub->setFrameShadow(QFrame::Shadow::Plain);
        label_soillosssub->setLineWidth(1);
        label_soillosssub->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_soillosssub, 2, 2, 1, 1);

        label_54 = new QLabel(outletgroup);
        label_54->setObjectName("label_54");
        label_54->setFont(font1);
        label_54->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_54, 1, 0, 1, 1);

        label_82 = new QLabel(outletgroup);
        label_82->setObjectName("label_82");
        sizePolicy.setHeightForWidth(label_82->sizePolicy().hasHeightForWidth());
        label_82->setSizePolicy(sizePolicy);
        label_82->setFont(font1);
        label_82->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_82, 0, 4, 1, 1);

        label_26 = new QLabel(outletgroup);
        label_26->setObjectName("label_26");
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setFont(font1);
        label_26->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_26, 0, 0, 1, 1);

        label_24 = new QLabel(outletgroup);
        label_24->setObjectName("label_24");
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);
        label_24->setFont(font1);
        label_24->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_24->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_24, 2, 4, 1, 1);

        label_dischargesub = new QLabel(outletgroup);
        label_dischargesub->setObjectName("label_dischargesub");
        sizePolicy7.setHeightForWidth(label_dischargesub->sizePolicy().hasHeightForWidth());
        label_dischargesub->setSizePolicy(sizePolicy7);
        label_dischargesub->setFont(font1);
        label_dischargesub->setFrameShape(QFrame::Shape::StyledPanel);
        label_dischargesub->setFrameShadow(QFrame::Shadow::Plain);
        label_dischargesub->setLineWidth(1);
        label_dischargesub->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_dischargesub, 1, 2, 1, 1);

        label_qtotm3sub = new QLabel(outletgroup);
        label_qtotm3sub->setObjectName("label_qtotm3sub");
        sizePolicy7.setHeightForWidth(label_qtotm3sub->sizePolicy().hasHeightForWidth());
        label_qtotm3sub->setSizePolicy(sizePolicy7);
        label_qtotm3sub->setFont(font1);
        label_qtotm3sub->setFrameShape(QFrame::Shape::StyledPanel);
        label_qtotm3sub->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_qtotm3sub, 0, 2, 1, 1);

        label_qpeaktime = new QLabel(outletgroup);
        label_qpeaktime->setObjectName("label_qpeaktime");
        sizePolicy7.setHeightForWidth(label_qpeaktime->sizePolicy().hasHeightForWidth());
        label_qpeaktime->setSizePolicy(sizePolicy7);
        label_qpeaktime->setFont(font1);
        label_qpeaktime->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_qpeaktime->setFrameShape(QFrame::Shape::StyledPanel);
        label_qpeaktime->setFrameShadow(QFrame::Shadow::Plain);
        label_qpeaktime->setLineWidth(1);
        label_qpeaktime->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_qpeaktime, 2, 5, 1, 1);

        label_ppeaktime = new QLabel(outletgroup);
        label_ppeaktime->setObjectName("label_ppeaktime");
        sizePolicy7.setHeightForWidth(label_ppeaktime->sizePolicy().hasHeightForWidth());
        label_ppeaktime->setSizePolicy(sizePolicy7);
        label_ppeaktime->setFont(font1);
        label_ppeaktime->setFrameShape(QFrame::Shape::StyledPanel);
        label_ppeaktime->setFrameShadow(QFrame::Shadow::Plain);
        label_ppeaktime->setLineWidth(1);
        label_ppeaktime->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_ppeaktime, 1, 5, 1, 1);

        label_94 = new QLabel(outletgroup);
        label_94->setObjectName("label_94");
        label_94->setFont(font1);
        label_94->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_94, 2, 0, 1, 1);

        label_53 = new QLabel(outletgroup);
        label_53->setObjectName("label_53");
        label_53->setFont(font1);
        label_53->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_53, 1, 4, 1, 1);

        label_QPfrac = new QLabel(outletgroup);
        label_QPfrac->setObjectName("label_QPfrac");
        sizePolicy7.setHeightForWidth(label_QPfrac->sizePolicy().hasHeightForWidth());
        label_QPfrac->setSizePolicy(sizePolicy7);
        label_QPfrac->setFont(font1);
        label_QPfrac->setFrameShape(QFrame::Shape::StyledPanel);
        label_QPfrac->setFrameShadow(QFrame::Shadow::Plain);
        label_QPfrac->setLineWidth(1);
        label_QPfrac->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_QPfrac, 3, 5, 1, 1);

        label_52 = new QLabel(outletgroup);
        label_52->setObjectName("label_52");
        sizePolicy2.setHeightForWidth(label_52->sizePolicy().hasHeightForWidth());
        label_52->setSizePolicy(sizePolicy2);
        label_52->setFont(font12);
        label_52->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_52, 3, 4, 1, 1);

        label_Qssub = new QLabel(outletgroup);
        label_Qssub->setObjectName("label_Qssub");
        sizePolicy7.setHeightForWidth(label_Qssub->sizePolicy().hasHeightForWidth());
        label_Qssub->setSizePolicy(sizePolicy7);
        label_Qssub->setFont(font1);
        label_Qssub->setFrameShape(QFrame::Shape::StyledPanel);
        label_Qssub->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_Qssub, 3, 2, 1, 1);

        label_105 = new QLabel(outletgroup);
        label_105->setObjectName("label_105");
        label_105->setFont(font1);
        label_105->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_14->addWidget(label_105, 3, 0, 1, 1);


        verticalLayout->addWidget(outletgroup);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);

        groupBox_drawMap = new QGroupBox(frameSImInfo);
        groupBox_drawMap->setObjectName("groupBox_drawMap");
        groupBox_drawMap->setEnabled(true);
        sizePolicy7.setHeightForWidth(groupBox_drawMap->sizePolicy().hasHeightForWidth());
        groupBox_drawMap->setSizePolicy(sizePolicy7);
        groupBox_drawMap->setFont(font3);
        gridLayout_16 = new QGridLayout(groupBox_drawMap);
        gridLayout_16->setObjectName("gridLayout_16");
        gridLayout_16->setHorizontalSpacing(4);
        gridLayout_16->setVerticalSpacing(2);
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        transparency = new QSlider(groupBox_drawMap);
        transparency->setObjectName("transparency");
        sizePolicy2.setHeightForWidth(transparency->sizePolicy().hasHeightForWidth());
        transparency->setSizePolicy(sizePolicy2);
        transparency->setMinimum(1);
        transparency->setMaximum(256);
        transparency->setValue(200);
        transparency->setSliderPosition(200);
        transparency->setOrientation(Qt::Orientation::Horizontal);
        transparency->setInvertedAppearance(false);
        transparency->setInvertedControls(false);
        transparency->setTickPosition(QSlider::TickPosition::NoTicks);
        transparency->setTickInterval(30);

        gridLayout_16->addWidget(transparency, 2, 0, 1, 2);

        label_162 = new QLabel(groupBox_drawMap);
        label_162->setObjectName("label_162");
        sizePolicy.setHeightForWidth(label_162->sizePolicy().hasHeightForWidth());
        label_162->setSizePolicy(sizePolicy);
        label_162->setFont(font1);

        gridLayout_16->addWidget(label_162, 4, 2, 1, 1);

        ComboMinSpinBox = new QDoubleSpinBox(groupBox_drawMap);
        ComboMinSpinBox->setObjectName("ComboMinSpinBox");
        sizePolicy2.setHeightForWidth(ComboMinSpinBox->sizePolicy().hasHeightForWidth());
        ComboMinSpinBox->setSizePolicy(sizePolicy2);
        ComboMinSpinBox->setFont(font1);
        ComboMinSpinBox->setDecimals(3);
        ComboMinSpinBox->setMinimum(0.000000000000000);
        ComboMinSpinBox->setMaximum(999999.000000000000000);

        gridLayout_16->addWidget(ComboMinSpinBox, 5, 2, 1, 1);

        ComboMaxSpinBox = new QDoubleSpinBox(groupBox_drawMap);
        ComboMaxSpinBox->setObjectName("ComboMaxSpinBox");
        sizePolicy2.setHeightForWidth(ComboMaxSpinBox->sizePolicy().hasHeightForWidth());
        ComboMaxSpinBox->setSizePolicy(sizePolicy2);
        ComboMaxSpinBox->setFont(font1);
        ComboMaxSpinBox->setDecimals(3);
        ComboMaxSpinBox->setMinimum(0.000000000000000);
        ComboMaxSpinBox->setMaximum(99999999.000000000000000);

        gridLayout_16->addWidget(ComboMaxSpinBox, 5, 3, 1, 1);

        label_163 = new QLabel(groupBox_drawMap);
        label_163->setObjectName("label_163");
        sizePolicy3.setHeightForWidth(label_163->sizePolicy().hasHeightForWidth());
        label_163->setSizePolicy(sizePolicy3);
        label_163->setFont(font1);

        gridLayout_16->addWidget(label_163, 4, 3, 1, 1);

        DisplayComboBox = new QComboBox(groupBox_drawMap);
        DisplayComboBox->setObjectName("DisplayComboBox");
        sizePolicy2.setHeightForWidth(DisplayComboBox->sizePolicy().hasHeightForWidth());
        DisplayComboBox->setSizePolicy(sizePolicy2);
        DisplayComboBox->setFont(font1);

        gridLayout_16->addWidget(DisplayComboBox, 5, 1, 1, 1);

        checkBoxComboMaps2 = new QCheckBox(groupBox_drawMap);
        checkBoxComboMaps2->setObjectName("checkBoxComboMaps2");
        checkBoxComboMaps2->setEnabled(false);
        sizePolicy4.setHeightForWidth(checkBoxComboMaps2->sizePolicy().hasHeightForWidth());
        checkBoxComboMaps2->setSizePolicy(sizePolicy4);

        gridLayout_16->addWidget(checkBoxComboMaps2, 6, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        transparencyHardSurface = new QSlider(groupBox_drawMap);
        transparencyHardSurface->setObjectName("transparencyHardSurface");
        transparencyHardSurface->setEnabled(false);
        transparencyHardSurface->setMaximum(256);
        transparencyHardSurface->setValue(200);
        transparencyHardSurface->setSliderPosition(200);
        transparencyHardSurface->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(transparencyHardSurface);

        checkMapBuildings = new QCheckBox(groupBox_drawMap);
        checkMapBuildings->setObjectName("checkMapBuildings");
        sizePolicy4.setHeightForWidth(checkMapBuildings->sizePolicy().hasHeightForWidth());
        checkMapBuildings->setSizePolicy(sizePolicy4);
        checkMapBuildings->setFont(font1);

        horizontalLayout->addWidget(checkMapBuildings);

        transparencyRoad = new QSlider(groupBox_drawMap);
        transparencyRoad->setObjectName("transparencyRoad");
        transparencyRoad->setMinimum(1);
        transparencyRoad->setMaximum(256);
        transparencyRoad->setPageStep(10);
        transparencyRoad->setValue(200);
        transparencyRoad->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(transparencyRoad);

        checkMapRoads = new QCheckBox(groupBox_drawMap);
        checkMapRoads->setObjectName("checkMapRoads");
        sizePolicy4.setHeightForWidth(checkMapRoads->sizePolicy().hasHeightForWidth());
        checkMapRoads->setSizePolicy(sizePolicy4);
        checkMapRoads->setFont(font1);

        horizontalLayout->addWidget(checkMapRoads);

        checkMapHardSurface = new QCheckBox(groupBox_drawMap);
        checkMapHardSurface->setObjectName("checkMapHardSurface");
        checkMapHardSurface->setFont(font1);

        horizontalLayout->addWidget(checkMapHardSurface);


        gridLayout_16->addLayout(horizontalLayout, 0, 0, 1, 4);

        transparencyMap = new QSlider(groupBox_drawMap);
        transparencyMap->setObjectName("transparencyMap");
        sizePolicy2.setHeightForWidth(transparencyMap->sizePolicy().hasHeightForWidth());
        transparencyMap->setSizePolicy(sizePolicy2);
        transparencyMap->setMaximum(256);
        transparencyMap->setValue(200);
        transparencyMap->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_16->addWidget(transparencyMap, 4, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_92 = new QLabel(groupBox_drawMap);
        label_92->setObjectName("label_92");
        sizePolicy4.setHeightForWidth(label_92->sizePolicy().hasHeightForWidth());
        label_92->setSizePolicy(sizePolicy4);
        label_92->setFont(font1);
        label_92->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_5->addWidget(label_92);

        label_90 = new QLabel(groupBox_drawMap);
        label_90->setObjectName("label_90");
        label_90->setFont(font1);
        label_90->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_5->addWidget(label_90);

        nrcontourlevels = new QSpinBox(groupBox_drawMap);
        nrcontourlevels->setObjectName("nrcontourlevels");
        sizePolicy4.setHeightForWidth(nrcontourlevels->sizePolicy().hasHeightForWidth());
        nrcontourlevels->setSizePolicy(sizePolicy4);
        nrcontourlevels->setFont(font1);
        nrcontourlevels->setMinimum(0);
        nrcontourlevels->setMaximum(64);
        nrcontourlevels->setSingleStep(2);
        nrcontourlevels->setValue(0);

        horizontalLayout_5->addWidget(nrcontourlevels);


        gridLayout_16->addLayout(horizontalLayout_5, 2, 2, 1, 2);

        checkBoxComboMaps = new QCheckBox(groupBox_drawMap);
        checkBoxComboMaps->setObjectName("checkBoxComboMaps");
        sizePolicy4.setHeightForWidth(checkBoxComboMaps->sizePolicy().hasHeightForWidth());
        checkBoxComboMaps->setSizePolicy(sizePolicy4);
        checkBoxComboMaps->setChecked(true);

        gridLayout_16->addWidget(checkBoxComboMaps, 5, 0, 1, 1);

        ComboMaxSpinBox2 = new QDoubleSpinBox(groupBox_drawMap);
        ComboMaxSpinBox2->setObjectName("ComboMaxSpinBox2");
        ComboMaxSpinBox2->setEnabled(false);
        sizePolicy2.setHeightForWidth(ComboMaxSpinBox2->sizePolicy().hasHeightForWidth());
        ComboMaxSpinBox2->setSizePolicy(sizePolicy2);
        ComboMaxSpinBox2->setFont(font1);
        ComboMaxSpinBox2->setDecimals(3);
        ComboMaxSpinBox2->setMinimum(0.000000000000000);
        ComboMaxSpinBox2->setMaximum(999999.000000000000000);

        gridLayout_16->addWidget(ComboMaxSpinBox2, 6, 3, 1, 1);

        DisplayComboBox2 = new QComboBox(groupBox_drawMap);
        DisplayComboBox2->setObjectName("DisplayComboBox2");
        DisplayComboBox2->setEnabled(false);
        sizePolicy2.setHeightForWidth(DisplayComboBox2->sizePolicy().hasHeightForWidth());
        DisplayComboBox2->setSizePolicy(sizePolicy2);
        DisplayComboBox2->setFont(font1);

        gridLayout_16->addWidget(DisplayComboBox2, 6, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        checkMapChannels = new QCheckBox(groupBox_drawMap);
        checkMapChannels->setObjectName("checkMapChannels");
        checkMapChannels->setEnabled(true);
        sizePolicy4.setHeightForWidth(checkMapChannels->sizePolicy().hasHeightForWidth());
        checkMapChannels->setSizePolicy(sizePolicy4);
        checkMapChannels->setFont(font1);
        checkMapChannels->setChecked(true);

        horizontalLayout_6->addWidget(checkMapChannels);

        label_137 = new QLabel(groupBox_drawMap);
        label_137->setObjectName("label_137");
        sizePolicy3.setHeightForWidth(label_137->sizePolicy().hasHeightForWidth());
        label_137->setSizePolicy(sizePolicy3);
        label_137->setFont(font1);

        horizontalLayout_6->addWidget(label_137);

        spinChannelSize = new QSpinBox(groupBox_drawMap);
        spinChannelSize->setObjectName("spinChannelSize");
        sizePolicy4.setHeightForWidth(spinChannelSize->sizePolicy().hasHeightForWidth());
        spinChannelSize->setSizePolicy(sizePolicy4);
        spinChannelSize->setFont(font1);
        spinChannelSize->setMinimum(1);
        spinChannelSize->setMaximum(9);

        horizontalLayout_6->addWidget(spinChannelSize);

        label_113 = new QLabel(groupBox_drawMap);
        label_113->setObjectName("label_113");
        label_113->setEnabled(true);
        sizePolicy3.setHeightForWidth(label_113->sizePolicy().hasHeightForWidth());
        label_113->setSizePolicy(sizePolicy3);
        label_113->setFont(font1);
        label_113->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_6->addWidget(label_113);

        spinCulvertSize = new QSpinBox(groupBox_drawMap);
        spinCulvertSize->setObjectName("spinCulvertSize");
        spinCulvertSize->setEnabled(true);
        sizePolicy4.setHeightForWidth(spinCulvertSize->sizePolicy().hasHeightForWidth());
        spinCulvertSize->setSizePolicy(sizePolicy4);
        spinCulvertSize->setFont(font1);
        spinCulvertSize->setMinimum(2);
        spinCulvertSize->setValue(5);

        horizontalLayout_6->addWidget(spinCulvertSize);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_24);

        checkMapImage = new QCheckBox(groupBox_drawMap);
        checkMapImage->setObjectName("checkMapImage");
        sizePolicy4.setHeightForWidth(checkMapImage->sizePolicy().hasHeightForWidth());
        checkMapImage->setSizePolicy(sizePolicy4);
        checkMapImage->setFont(font1);

        horizontalLayout_6->addWidget(checkMapImage);


        gridLayout_16->addLayout(horizontalLayout_6, 1, 0, 1, 4);

        ComboMinSpinBox2 = new QDoubleSpinBox(groupBox_drawMap);
        ComboMinSpinBox2->setObjectName("ComboMinSpinBox2");
        ComboMinSpinBox2->setEnabled(false);
        sizePolicy2.setHeightForWidth(ComboMinSpinBox2->sizePolicy().hasHeightForWidth());
        ComboMinSpinBox2->setSizePolicy(sizePolicy2);
        ComboMinSpinBox2->setFont(font1);
        ComboMinSpinBox2->setDecimals(3);
        ComboMinSpinBox2->setMinimum(-999999.000000000000000);
        ComboMinSpinBox2->setMaximum(999999.000000000000000);

        gridLayout_16->addWidget(ComboMinSpinBox2, 6, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox_drawMap);

        groupBox_info = new QGroupBox(frameSImInfo);
        groupBox_info->setObjectName("groupBox_info");
        sizePolicy2.setHeightForWidth(groupBox_info->sizePolicy().hasHeightForWidth());
        groupBox_info->setSizePolicy(sizePolicy2);
        groupBox_info->setFont(font3);
        gridLayout_31 = new QGridLayout(groupBox_info);
        gridLayout_31->setObjectName("gridLayout_31");
        gridLayout_31->setHorizontalSpacing(4);
        gridLayout_31->setVerticalSpacing(2);
        gridLayout_31->setContentsMargins(0, 0, 0, 0);
        label_MBs = new QLabel(groupBox_info);
        label_MBs->setObjectName("label_MBs");
        sizePolicy2.setHeightForWidth(label_MBs->sizePolicy().hasHeightForWidth());
        label_MBs->setSizePolicy(sizePolicy2);
        QPalette palette23;
        QBrush brush(QColor(58, 58, 58, 255));
        brush.setStyle(Qt::SolidPattern);
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(122, 122, 122, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_MBs->setPalette(palette23);
        label_MBs->setFont(font1);
        label_MBs->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_31->addWidget(label_MBs, 2, 5, 1, 1);

        label_hydroCount = new QLabel(groupBox_info);
        label_hydroCount->setObjectName("label_hydroCount");
        sizePolicy2.setHeightForWidth(label_hydroCount->sizePolicy().hasHeightForWidth());
        label_hydroCount->setSizePolicy(sizePolicy2);
        label_hydroCount->setFont(font1);
        label_hydroCount->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_31->addWidget(label_hydroCount, 0, 1, 1, 2);

        label_30 = new QLabel(groupBox_info);
        label_30->setObjectName("label_30");
        sizePolicy2.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy2);
        label_30->setFont(font1);
        label_30->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_31->addWidget(label_30, 1, 1, 1, 2);

        label_runtime = new QLabel(groupBox_info);
        label_runtime->setObjectName("label_runtime");
        sizePolicy2.setHeightForWidth(label_runtime->sizePolicy().hasHeightForWidth());
        label_runtime->setSizePolicy(sizePolicy2);
        label_runtime->setFont(font1);
        label_runtime->setFrameShape(QFrame::Shape::StyledPanel);
        label_runtime->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_31->addWidget(label_runtime, 1, 3, 1, 1);

        label_MB = new QLabel(groupBox_info);
        label_MB->setObjectName("label_MB");
        sizePolicy2.setHeightForWidth(label_MB->sizePolicy().hasHeightForWidth());
        label_MB->setSizePolicy(sizePolicy2);
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_MB->setPalette(palette24);
        label_MB->setFont(font1);
        label_MB->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_31->addWidget(label_MB, 2, 3, 1, 1);

        label_endruntime = new QLabel(groupBox_info);
        label_endruntime->setObjectName("label_endruntime");
        sizePolicy2.setHeightForWidth(label_endruntime->sizePolicy().hasHeightForWidth());
        label_endruntime->setSizePolicy(sizePolicy2);
        label_endruntime->setFont(font1);
        label_endruntime->setFrameShape(QFrame::Shape::StyledPanel);
        label_endruntime->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_31->addWidget(label_endruntime, 1, 5, 1, 1);

        label_debug = new QLabel(groupBox_info);
        label_debug->setObjectName("label_debug");
        sizePolicy.setHeightForWidth(label_debug->sizePolicy().hasHeightForWidth());
        label_debug->setSizePolicy(sizePolicy);
        label_debug->setFont(font1);
        label_debug->setFrameShape(QFrame::Shape::StyledPanel);
        label_debug->setFrameShadow(QFrame::Shadow::Plain);
        label_debug->setLineWidth(0);
        label_debug->setWordWrap(true);

        gridLayout_31->addWidget(label_debug, 5, 1, 1, 5);

        label_75 = new QLabel(groupBox_info);
        label_75->setObjectName("label_75");
        sizePolicy2.setHeightForWidth(label_75->sizePolicy().hasHeightForWidth());
        label_75->setSizePolicy(sizePolicy2);
        label_75->setFont(font1);
        label_75->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_31->addWidget(label_75, 1, 4, 1, 1);

        label_45 = new QLabel(groupBox_info);
        label_45->setObjectName("label_45");
        sizePolicy2.setHeightForWidth(label_45->sizePolicy().hasHeightForWidth());
        label_45->setSizePolicy(sizePolicy2);
        label_45->setFont(font1);
        label_45->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_31->addWidget(label_45, 2, 4, 1, 1);

        label_44 = new QLabel(groupBox_info);
        label_44->setObjectName("label_44");
        sizePolicy2.setHeightForWidth(label_44->sizePolicy().hasHeightForWidth());
        label_44->setSizePolicy(sizePolicy2);
        label_44->setFont(font1);
        label_44->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_31->addWidget(label_44, 2, 1, 1, 2);

        spinBoxPointtoShow = new QSpinBox(groupBox_info);
        spinBoxPointtoShow->setObjectName("spinBoxPointtoShow");
        sizePolicy2.setHeightForWidth(spinBoxPointtoShow->sizePolicy().hasHeightForWidth());
        spinBoxPointtoShow->setSizePolicy(sizePolicy2);
        spinBoxPointtoShow->setFont(font1);
        spinBoxPointtoShow->setAcceptDrops(false);
        spinBoxPointtoShow->setAccelerated(true);
        spinBoxPointtoShow->setMaximum(999);
        spinBoxPointtoShow->setValue(1);

        gridLayout_31->addWidget(spinBoxPointtoShow, 0, 3, 1, 1);


        verticalLayout_2->addWidget(groupBox_info);


        gridLayout_27->addWidget(frameSImInfo, 0, 0, 1, 1);

        frameDisplay2D = new QFrame(tab_simulation);
        frameDisplay2D->setObjectName("frameDisplay2D");
        frameDisplay2D->setFrameShape(QFrame::Shape::NoFrame);
        gridLayout_46 = new QGridLayout(frameDisplay2D);
        gridLayout_46->setSpacing(2);
        gridLayout_46->setObjectName("gridLayout_46");
        gridLayout_46->setContentsMargins(2, 2, 2, 2);
        progressBar = new QProgressBar(frameDisplay2D);
        progressBar->setObjectName("progressBar");
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setFont(font1);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_46->addWidget(progressBar, 2, 0, 1, 1);

        tabWidget_out = new QTabWidget(frameDisplay2D);
        tabWidget_out->setObjectName("tabWidget_out");
        sizePolicy.setHeightForWidth(tabWidget_out->sizePolicy().hasHeightForWidth());
        tabWidget_out->setSizePolicy(sizePolicy);
        tabWidget_out->setTabPosition(QTabWidget::TabPosition::West);
        tabWidget_out->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget_out->setIconSize(QSize(32, 32));
        tabWidget_out->setUsesScrollButtons(true);
        tab_1 = new QWidget();
        tab_1->setObjectName("tab_1");
        gridLayout_18 = new QGridLayout(tab_1);
        gridLayout_18->setObjectName("gridLayout_18");
        layout_Plot = new QVBoxLayout();
        layout_Plot->setObjectName("layout_Plot");

        gridLayout_18->addLayout(layout_Plot, 0, 0, 1, 1);

        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/2X/chart-line-stacked-iconBW2X.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_out->addTab(tab_1, icon17, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_45 = new QGridLayout(tab_2);
        gridLayout_45->setObjectName("gridLayout_45");
        maplayout = new QVBoxLayout();
        maplayout->setObjectName("maplayout");

        gridLayout_45->addLayout(maplayout, 0, 0, 1, 1);

        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/2X/map2X.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_out->addTab(tab_2, icon18, QString());

        gridLayout_46->addWidget(tabWidget_out, 1, 0, 1, 1);


        gridLayout_27->addWidget(frameDisplay2D, 0, 1, 1, 1);

        tabWidget->addTab(tab_simulation, QString());

        gridLayout_83->addWidget(tabWidget, 0, 0, 1, 1);

        lisemqtClass->setCentralWidget(centralwidget);
        toolBar = new QToolBar(lisemqtClass);
        toolBar->setObjectName("toolBar");
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(18, 18));
        toolBar->setFloatable(false);
        lisemqtClass->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(lisemqtClass);
        statusBar->setObjectName("statusBar");
        lisemqtClass->setStatusBar(statusBar);
        toolBar_2 = new QToolBar(lisemqtClass);
        toolBar_2->setObjectName("toolBar_2");
        sizePolicy8.setHeightForWidth(toolBar_2->sizePolicy().hasHeightForWidth());
        toolBar_2->setSizePolicy(sizePolicy8);
        toolBar_2->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        toolBar_2->setAutoFillBackground(false);
        toolBar_2->setMovable(false);
        toolBar_2->setIconSize(QSize(18, 18));
        toolBar_2->setFloatable(false);
        lisemqtClass->addToolBar(Qt::TopToolBarArea, toolBar_2);

        toolBar->addSeparator();

        retranslateUi(lisemqtClass);
        QObject::connect(checksatImage, &QCheckBox::toggled, E_satImageName, &QLineEdit::setEnabled);
        QObject::connect(radioRainFile, &QRadioButton::toggled, E_RainfallName, &QLineEdit::setEnabled);
        QObject::connect(checkAddBuildingDEM, &QCheckBox::toggled, E_AddBuildingFraction, &QDoubleSpinBox::setEnabled);
        QObject::connect(checkIncludeChannel, &QCheckBox::toggled, checkChannelInfil, &QCheckBox::setEnabled);
        QObject::connect(radioRainFile, &QRadioButton::toggled, toolButton_RainfallName, &QToolButton::setEnabled);
        QObject::connect(radioETSatfile, &QRadioButton::toggled, toolButton_ETsatName, &QToolButton::setEnabled);
        QObject::connect(checkSnowmelt, &QCheckBox::toggled, radioGroupSnowmelt, &QFrame::setEnabled);
        QObject::connect(checkDischargeUser, &QCheckBox::toggled, E_DischargeInName, &QLineEdit::setEnabled);
        QObject::connect(checkDischargeUser, &QCheckBox::toggled, toolButton_DischargeShow, &QToolButton::setEnabled);
        QObject::connect(checkAdvancedOptions, &QCheckBox::toggled, groupAdvanced, &QFrame::setVisible);
        QObject::connect(checkFlowBarriers, &QCheckBox::toggled, line_FlowBarriers, &QLineEdit::setEnabled);
        QObject::connect(radioRainSatFile, &QRadioButton::toggled, E_RainsatName, &QLineEdit::setEnabled);
        QObject::connect(checkAddBuildingDEM, &QCheckBox::toggled, label_140, &QLabel::setEnabled);
        QObject::connect(radioRainSatFile, &QRadioButton::toggled, toolButton_rainsatName, &QToolButton::setEnabled);
        QObject::connect(radioRainFile, &QRadioButton::toggled, toolButton_RainfallShow, &QToolButton::setEnabled);
        QObject::connect(checkMUSCL, &QCheckBox::toggled, E_FloodFluxLimiter, &QSpinBox::setEnabled);
        QObject::connect(checkDischargeUser, &QCheckBox::toggled, toolButton_DischargeName, &QToolButton::setEnabled);
        QObject::connect(radioETfile, &QRadioButton::toggled, E_ETName, &QLineEdit::setEnabled);
        QObject::connect(checkAddBuildingDEM, &QCheckBox::toggled, E_buildingHeight, &QDoubleSpinBox::setEnabled);
        QObject::connect(checkMUSCL, &QCheckBox::toggled, label_100, &QLabel::setEnabled);
        QObject::connect(checkGWflow, &QCheckBox::toggled, GW_widget, &QWidget::setEnabled);
        QObject::connect(checkIncludeChannel, &QCheckBox::toggled, toolButton_DischargeName, &QToolButton::setEnabled);
        QObject::connect(checkIncludeChannel, &QCheckBox::toggled, E_DischargeInName, &QLineEdit::setEnabled);
        QObject::connect(radioETfile, &QRadioButton::toggled, toolButton_ETName, &QToolButton::setEnabled);
        QObject::connect(radioETfile, &QRadioButton::toggled, toolButton_ETShow, &QToolButton::setEnabled);
        QObject::connect(radioRainSatFile, &QRadioButton::toggled, toolButton_RainmapShow, &QToolButton::setEnabled);
        QObject::connect(checkIncludeChannel, &QCheckBox::toggled, checkDischargeUser, &QCheckBox::setEnabled);
        QObject::connect(radioETSatfile, &QRadioButton::toggled, toolButton_ETmapShow, &QToolButton::setEnabled);
        QObject::connect(checkIncludeChannel, &QCheckBox::toggled, checkChannelCulverts, &QCheckBox::setEnabled);
        QObject::connect(radioRainFile, &QRadioButton::toggled, checkIDinterpolation, &QCheckBox::setEnabled);
        QObject::connect(radioETSatfile, &QRadioButton::toggled, E_ETsatName, &QLineEdit::setEnabled);
        QObject::connect(checkWaterUserIn, &QCheckBox::toggled, E_WaveInName, &QLineEdit::setEnabled);
        QObject::connect(checkWaterUserIn, &QCheckBox::toggled, toolButton_WaveInName, &QToolButton::setEnabled);
        QObject::connect(checkWaterUserIn, &QCheckBox::toggled, toolButton_WaveShow, &QToolButton::setEnabled);
        QObject::connect(checkWaterUserIn, &QCheckBox::toggled, label_148, &QLabel::setEnabled);
        QObject::connect(radioRainSatFile, &QRadioButton::toggled, label_121, &QLabel::setEnabled);
        QObject::connect(radioRainSatFile, &QRadioButton::toggled, E_biasCorrectionP, &QDoubleSpinBox::setEnabled);
        QObject::connect(radioRainFile, &QRadioButton::toggled, checkEventBased, &QCheckBox::setEnabled);
        QObject::connect(checkInfilGrass, &QCheckBox::toggled, label_15, &QLabel::setEnabled);
        QObject::connect(checkInfilGrass, &QCheckBox::toggled, E_GrassStripN, &QDoubleSpinBox::setEnabled);
        QObject::connect(checkHouses, &QCheckBox::toggled, checkRaindrum, &QCheckBox::setEnabled);
        QObject::connect(checkHouses, &QCheckBox::toggled, checkAddBuildingDEM, &QCheckBox::setEnabled);
        QObject::connect(checkInfilCrust, &QCheckBox::toggled, checkDynamicCrusting, &QCheckBox::setEnabled);
        QObject::connect(checkDailyET, &QCheckBox::toggled, label_5, &QLabel::setEnabled);
        QObject::connect(checkDailyET, &QCheckBox::toggled, E_latitude, &QLineEdit::setEnabled);
        QObject::connect(checkRoadsystem, &QCheckBox::toggled, tilebox, &QFrame::setEnabled);

        tabWidget->setCurrentIndex(0);
        tabWidget_OutputMaps->setCurrentIndex(1);
        tabWidgetOptions->setCurrentIndex(9);
        E_OFWaveType->setCurrentIndex(2);
        E_InfiltrationMethod->setCurrentIndex(-1);
        E_SSMethod->setCurrentIndex(0);
        E_RSSMethod->setCurrentIndex(1);
        E_RBLMethod->setCurrentIndex(0);
        E_BLMethod->setCurrentIndex(1);
        tabWidget_totout->setCurrentIndex(0);
        tabWidget_out->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(lisemqtClass);
    } // setupUi

    void retranslateUi(QMainWindow *lisemqtClass)
    {
        lisemqtClass->setWindowTitle(QCoreApplication::translate("lisemqtClass", "MainWindow", nullptr));
        action_Open_runfile->setText(QCoreApplication::translate("lisemqtClass", "&Open runfile", nullptr));
        action_Save_runfuile->setText(QCoreApplication::translate("lisemqtClass", "&Save runfuile", nullptr));
        groupBoxOutput->setTitle(QCoreApplication::translate("lisemqtClass", "OUTPUT", nullptr));
        outputGraphsTables->setTitle(QCoreApplication::translate("lisemqtClass", "Graphs and tabels", nullptr));
        label_22->setText(QCoreApplication::translate("lisemqtClass", "Catchment and outlet totals: ", nullptr));
#if QT_CONFIG(tooltip)
        E_MainTotals->setToolTip(QCoreApplication::translate("lisemqtClass", "Text file with totals at the outlet", nullptr));
#endif // QT_CONFIG(tooltip)
        label_110->setText(QCoreApplication::translate("lisemqtClass", "Totals per timestep:", nullptr));
        label_20->setText(QCoreApplication::translate("lisemqtClass", "Sample point Hydrographs: ", nullptr));
#if QT_CONFIG(tooltip)
        E_PointResults->setToolTip(QCoreApplication::translate("lisemqtClass", "Text file(s) with hydrographs and sedigraphs", nullptr));
#endif // QT_CONFIG(tooltip)
        checksatImage->setText(QCoreApplication::translate("lisemqtClass", "Background satellite image:", nullptr));
        toolButton_satImageName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_128->setText(QCoreApplication::translate("lisemqtClass", "Maps and map series", nullptr));
        groupBoxunits->setTitle(QCoreApplication::translate("lisemqtClass", "Units and format", nullptr));
        checkUnits_ls->setText(QCoreApplication::translate("lisemqtClass", "l/s", nullptr));
        checkUnits_m3s->setText(QCoreApplication::translate("lisemqtClass", "m3/s", nullptr));
        checkUnits_tonha->setText(QCoreApplication::translate("lisemqtClass", "ton/ha", nullptr));
        checkUnits_kgcell->setText(QCoreApplication::translate("lisemqtClass", "kg/cell", nullptr));
        checkUnits_kgm2->setText(QCoreApplication::translate("lisemqtClass", "kg/m2", nullptr));
        label_125->setText(QCoreApplication::translate("lisemqtClass", "Erosion units:", nullptr));
        label_12->setText(QCoreApplication::translate("lisemqtClass", "flow Units:", nullptr));
        checkWritePCRaster->setText(QCoreApplication::translate("lisemqtClass", "Comma Delimited output (v) or PCRaster timeseries ( )", nullptr));
        label_81->setText(QCoreApplication::translate("lisemqtClass", "Digits in output and display", nullptr));
#if QT_CONFIG(tooltip)
        label_198->setToolTip(QCoreApplication::translate("lisemqtClass", "<html><head/><body><p><span style=\" font-weight:600;\">Minimum flood water height</span><br/>When using 2D dynamic wave, flood ad runoff are not distinguished, all is 2D flow. The minimum value of 0.05 m is set to distinguish artificially between hazardous flood and overland flow. This is only for the display and output maps, it does not affect the simuation itself. It does affect the reported flood start time and flood duration maps.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_198->setText(QCoreApplication::translate("lisemqtClass", "Reported flood threshold (m): flow height reported as flood when heigher than", nullptr));
        checkEndRunReport->setText(QCoreApplication::translate("lisemqtClass", "Write only at the end of the run (faster)", nullptr));
        label_131->setText(QString());
        outputMapsSediment->setTitle(QCoreApplication::translate("lisemqtClass", "Sediment maps", nullptr));
        label_19->setText(QCoreApplication::translate("lisemqtClass", "Soilloss Map", nullptr));
        label_17->setText(QCoreApplication::translate("lisemqtClass", "Detachment", nullptr));
        label_180->setText(QCoreApplication::translate("lisemqtClass", "Channel deposition", nullptr));
        label_18->setText(QCoreApplication::translate("lisemqtClass", "Deposition", nullptr));
        label_179->setText(QCoreApplication::translate("lisemqtClass", "Channel detachment", nullptr));
        checkFormatGtiff->setText(QCoreApplication::translate("lisemqtClass", "Write maps as GTiff (no projection information)", nullptr));
        outputMapsFlood->setTitle(QCoreApplication::translate("lisemqtClass", "Flow maps", nullptr));
        label_120->setText(QCoreApplication::translate("lisemqtClass", "Max channel water level (m)", nullptr));
        label_122->setText(QCoreApplication::translate("lisemqtClass", "Cumulative channel discharge (m3)", nullptr));
        label_112->setText(QCoreApplication::translate("lisemqtClass", "Flooded building stats", nullptr));
        label_111->setText(QCoreApplication::translate("lisemqtClass", "Flood duration (min)", nullptr));
        label_119->setText(QCoreApplication::translate("lisemqtClass", "Max discharge (m3/s)", nullptr));
        label_79->setText(QCoreApplication::translate("lisemqtClass", "Max storm drain discharge (m3/s)", nullptr));
        label_93->setText(QCoreApplication::translate("lisemqtClass", "Flood start (min)", nullptr));
        label_103->setText(QCoreApplication::translate("lisemqtClass", "Storm drain volume (m3)", nullptr));
        outputMapsWater->setTitle(QCoreApplication::translate("lisemqtClass", "Hydrology maps", nullptr));
        label_114->setText(QCoreApplication::translate("lisemqtClass", "Rainfall (mm)", nullptr));
        label_74->setText(QCoreApplication::translate("lisemqtClass", "Max momentum VH (m2/s)", nullptr));
        label_138->setText(QCoreApplication::translate("lisemqtClass", "Max Water level  (m)", nullptr));
        label_116->setText(QCoreApplication::translate("lisemqtClass", "Infiltration (mm)", nullptr));
        label_117->setText(QCoreApplication::translate("lisemqtClass", "Overland flow (m3)", nullptr));
        label_115->setText(QCoreApplication::translate("lisemqtClass", "Interception (mm)", nullptr));
        label_136->setText(QCoreApplication::translate("lisemqtClass", "Max velocity (m/s)", nullptr));
        tabWidget_OutputMaps->setTabText(tabWidget_OutputMaps->indexOf(tab), QCoreApplication::translate("lisemqtClass", "Spatial Totals", nullptr));
        groupWatermapseriesout->setTitle(QCoreApplication::translate("lisemqtClass", "Water", nullptr));
        checkBox_OutSurfStor->setText(QCoreApplication::translate("lisemqtClass", "sstor - surface storage (mm)", nullptr));
        checkBox_OutTiledrain->setText(QCoreApplication::translate("lisemqtClass", "tileq - tile drainage (units)", nullptr));
        checkBox_OutWH->setText(QCoreApplication::translate("lisemqtClass", "wh - surface water depth (m)                ", nullptr));
        checkBox_OutInf->setText(QCoreApplication::translate("lisemqtClass", "inf - cumulative infiltration (mm)", nullptr));
        checkBox_OutTheta->setText(QCoreApplication::translate("lisemqtClass", "theta - moisture content layers 1 && 2 (-)", nullptr));
        checkBox_OutV->setText(QCoreApplication::translate("lisemqtClass", "v - surface velocity  (m/s)", nullptr));
        checkBox_OutInterception->setText(QCoreApplication::translate("lisemqtClass", "Int - Interception (mm)", nullptr));
        checkBox_OutTileVol->setText(QCoreApplication::translate("lisemqtClass", "tilev - tile volume (m3)", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_OutRunoff->setToolTip(QCoreApplication::translate("lisemqtClass", "mapseries saved as is \"ro\"", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox_OutRunoff->setText(QCoreApplication::translate("lisemqtClass", "ro - runoff + channel discharge (units)", nullptr));
        checkBox_OutGW->setText(QCoreApplication::translate("lisemqtClass", "WHh - Groundwater level (m)", nullptr));
        groupSedMapseriesout->setTitle(QCoreApplication::translate("lisemqtClass", "Sediment", nullptr));
        checkBox_OutDet->setText(QCoreApplication::translate("lisemqtClass", "det - detachment (units)", nullptr));
        checkBox_OutDep->setText(QCoreApplication::translate("lisemqtClass", "dep - deposition (units)", nullptr));
        checkBox_OutSL->setText(QCoreApplication::translate("lisemqtClass", "sloss - soilloss (units)", nullptr));
        checkBox_OutConc->setText(QCoreApplication::translate("lisemqtClass", "conc - sediment concentration (g/l)", nullptr));
        checkBox_OutTC->setText(QCoreApplication::translate("lisemqtClass", "tc - transport capacity (kg/m3)", nullptr));
        checkBox_OutSed->setText(QCoreApplication::translate("lisemqtClass", "sed - Sediment in flow (units)", nullptr));
        checkBox_OutSedSS->setText(QCoreApplication::translate("lisemqtClass", "SS - Suspended in flow (units)", nullptr));
        checkBox_OutSedBL->setText(QCoreApplication::translate("lisemqtClass", "BL - Bedload in flow (units)", nullptr));
        checkWritePCRnames->setText(QCoreApplication::translate("lisemqtClass", "Mapseries as PCRaster filenames (.001, .002)", nullptr));
        tabWidget_OutputMaps->setTabText(tabWidget_OutputMaps->indexOf(tab_4), QCoreApplication::translate("lisemqtClass", "Time series", nullptr));
        label_80->setText(QCoreApplication::translate("lisemqtClass", "Report maps and mapseries every:", nullptr));
        label_16->setText(QCoreApplication::translate("lisemqtClass", "timesteps, or ", nullptr));
        checkReportMapsEnd->setText(QCoreApplication::translate("lisemqtClass", "report maps only at the end", nullptr));
        groupBoxInput->setTitle(QCoreApplication::translate("lisemqtClass", "INPUT", nullptr));
        groupBoxTime->setTitle(QCoreApplication::translate("lisemqtClass", "Simulation times", nullptr));
        E_Timestep->setInputMask(QString());
        E_Timestep->setText(QCoreApplication::translate("lisemqtClass", "10.0", nullptr));
        label_6->setText(QCoreApplication::translate("lisemqtClass", "Begin time (day:min)", nullptr));
        E_EndTimeDay->setInputMask(QString());
        E_EndTimeDay->setText(QCoreApplication::translate("lisemqtClass", "1:0200", nullptr));
        label_8->setText(QCoreApplication::translate("lisemqtClass", "Timestep (sec)", nullptr));
        label_7->setText(QCoreApplication::translate("lisemqtClass", "End time (day:min)", nullptr));
        E_BeginTimeDay->setInputMask(QString());
        E_BeginTimeDay->setText(QCoreApplication::translate("lisemqtClass", "1:0000", nullptr));
#if QT_CONFIG(tooltip)
        tabWidgetOptions->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupBox_8->setTitle(QCoreApplication::translate("lisemqtClass", "Erosion processes", nullptr));
        checkDoErosion->setText(QCoreApplication::translate("lisemqtClass", "Include detachment, transport and deposition in all flows", nullptr));
        groupSurfaceflow->setTitle(QCoreApplication::translate("lisemqtClass", "Surface flow", nullptr));
        E_OFWaveType->setItemText(0, QCoreApplication::translate("lisemqtClass", "Kinematic Wave (using LDD)", nullptr));
        E_OFWaveType->setItemText(1, QCoreApplication::translate("lisemqtClass", "Kinematic Wave with channel flooding", nullptr));
        E_OFWaveType->setItemText(2, QCoreApplication::translate("lisemqtClass", "Dynamic Wave (using DEM)", nullptr));

        E_OFWaveType->setCurrentText(QCoreApplication::translate("lisemqtClass", "Dynamic Wave (using DEM)", nullptr));
        groupBox->setTitle(QCoreApplication::translate("lisemqtClass", "Infiltration", nullptr));
        checkInfiltration->setText(QCoreApplication::translate("lisemqtClass", "Include infiltration", nullptr));
        groupChannels->setTitle(QCoreApplication::translate("lisemqtClass", "Channels and groundwater flow", nullptr));
        checkIncludeChannel->setText(QCoreApplication::translate("lisemqtClass", "Include channels/rivers", nullptr));
        checkGWflow->setText(QCoreApplication::translate("lisemqtClass", "Include groundwater flow", nullptr));
        label_55->setText(QCoreApplication::translate("lisemqtClass", "General process options", nullptr));
        toolButton_resetOptions->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        groupInfrastructrure->setTitle(QCoreApplication::translate("lisemqtClass", "Infrastructure", nullptr));
        checkInfrastructure->setText(QCoreApplication::translate("lisemqtClass", "Include buildings, roads and hard surfaces", nullptr));
        checkConservation->setText(QCoreApplication::translate("lisemqtClass", "Include conservation/mitigation measures", nullptr));
        toolButton_helpOptions->setText(QString());
#if QT_CONFIG(shortcut)
        toolButton_helpOptions->setShortcut(QCoreApplication::translate("lisemqtClass", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_2->setTitle(QCoreApplication::translate("lisemqtClass", "Meteo", nullptr));
        checkRainfall->setText(QCoreApplication::translate("lisemqtClass", "Include Rainfall", nullptr));
        checkET->setText(QCoreApplication::translate("lisemqtClass", "Include Evapotranspiration", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("lisemqtClass", "Interception", nullptr));
        checkInterception->setText(QCoreApplication::translate("lisemqtClass", "Include Interception", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_general), QString());
        label_49->setText(QCoreApplication::translate("lisemqtClass", "Meteorological input", nullptr));
        groupET->setTitle(QCoreApplication::translate("lisemqtClass", "Evapotranspiration", nullptr));
        label_5->setText(QCoreApplication::translate("lisemqtClass", " - Latitude area for day length (Degrees):", nullptr));
        label_57->setText(QCoreApplication::translate("lisemqtClass", "Evapotranspiration stops when rainfall is more than (mm/h):", nullptr));
        checkDailyET->setText(QCoreApplication::translate("lisemqtClass", "ET is in mm/day: use Sine distribution to distrribute ET between sunrise and sunset", nullptr));
        label_63->setText(QCoreApplication::translate("lisemqtClass", " - Starting day for the ET data (1-366):", nullptr));
        E_latitude->setText(QCoreApplication::translate("lisemqtClass", "52.22", nullptr));
        label_126->setText(QCoreApplication::translate("lisemqtClass", "Correction factor", nullptr));
        radioETfile->setText(QCoreApplication::translate("lisemqtClass", "ET station file", nullptr));
        toolButton_ETName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_ETShow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        radioETSatfile->setText(QCoreApplication::translate("lisemqtClass", "ET map file list", nullptr));
        toolButton_ETsatName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_ETmapShow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        E_longtimestep->setText(QCoreApplication::translate("lisemqtClass", "300", nullptr));
        label_118->setText(QCoreApplication::translate("lisemqtClass", " - long timstep between rainfall (sec):", nullptr));
        toolButton_helpRainfall->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        groupRainfall->setTitle(QCoreApplication::translate("lisemqtClass", "Rainfall", nullptr));
        checkEventBased->setText(QCoreApplication::translate("lisemqtClass", "Event based (day nr in time indication is ignored)", nullptr));
        label_98->setText(QCoreApplication::translate("lisemqtClass", " - ", nullptr));
        radioRainFile->setText(QCoreApplication::translate("lisemqtClass", "Raingauge station file", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_RainfallName->setToolTip(QCoreApplication::translate("lisemqtClass", "Select a rainfall file", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_RainfallName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_RainfallShow->setToolTip(QCoreApplication::translate("lisemqtClass", "Show current rainfall file", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_RainfallShow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_149->setText(QCoreApplication::translate("lisemqtClass", " - ", nullptr));
        checkIDinterpolation->setText(QCoreApplication::translate("lisemqtClass", "Inverse distance interpolation stations (gaugeID.map); weight:", nullptr));
        radioRainSatFile->setText(QCoreApplication::translate("lisemqtClass", "Rainfall map file list", nullptr));
        toolButton_rainsatName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_RainmapShow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_121->setText(QCoreApplication::translate("lisemqtClass", "Bias correction factor", nullptr));
        toolButton_resetRainfall->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_meteo), QString());
        groupInterception->setTitle(QCoreApplication::translate("lisemqtClass", "Interception", nullptr));
        checkIncludeLitter->setText(QCoreApplication::translate("lisemqtClass", "Include Litter interception", nullptr));
        label_133->setText(QCoreApplication::translate("lisemqtClass", "mm litter storage ", nullptr));
        groupCanopyStrorage->setTitle(QCoreApplication::translate("lisemqtClass", "Canopy storage equation", nullptr));
        radioButton_1->setText(QCoreApplication::translate("lisemqtClass", "Crops: Smax = 1.036+0.438*LAI (unknown)", nullptr));
        radioButton_2->setText(QCoreApplication::translate("lisemqtClass", "Pine: Smax = 0.233*LAI (n=12,R2=0.88)", nullptr));
        radioButton_3->setText(QCoreApplication::translate("lisemqtClass", "Douglas Fir: Smax = 0.317*LAI (n=4, R2=0.83)", nullptr));
        radioButton_4->setText(QCoreApplication::translate("lisemqtClass", "Olive: Smax = 1.460*LAI^0.56 (n=5, R2=0.87)", nullptr));
        radioButton_5->setText(QCoreApplication::translate("lisemqtClass", "Eucalypt: Smax = 0.092*LAI^1.04 (n=8, R2=0.51)", nullptr));
        radioButton_6->setText(QCoreApplication::translate("lisemqtClass", "Broadleaved forest: Smax = 0.286*LAI (n=5, R2=0.60)", nullptr));
        radioButton_7->setText(QCoreApplication::translate("lisemqtClass", "Bracken: Smax = 0.171*LAI (n=8, R2=0.98)", nullptr));
        radioButton_8->setText(QCoreApplication::translate("lisemqtClass", "Grass: Smax = 0.590*LAI^0.88 (n=6, R2=0.82)", nullptr));
        radioButton_9->setText(QCoreApplication::translate("lisemqtClass", "User defined Smax (provide smax.map)", nullptr));
        toolButton_resetInterception->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_helpInterception->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_interc), QString());
        toolButton_helpInfiltration->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        groupInfiltration->setTitle(QCoreApplication::translate("lisemqtClass", "Infiltration", nullptr));
        groupBox_InfilOptions->setTitle(QCoreApplication::translate("lisemqtClass", "General options", nullptr));
        checkInfilImpermeable->setText(QCoreApplication::translate("lisemqtClass", "Impermeable lower soil boundary (1) or free drainage (0)", nullptr));
        checkDynamicCrusting->setText(QCoreApplication::translate("lisemqtClass", "Dynamic crusting based on cumulative rainfall", nullptr));
        checkIncludeTiledrains->setText(QCoreApplication::translate("lisemqtClass", "Include tile drain system", nullptr));
        checkInfilCompact->setText(QCoreApplication::translate("lisemqtClass", "Top layer compaction", nullptr));
        label_153->setText(QCoreApplication::translate("lisemqtClass", "Nr. of input soil layers (1,2 or 3) for Green and Ampt", nullptr));
        checkInfilCrust->setText(QCoreApplication::translate("lisemqtClass", "Top layer crusting (static)", nullptr));
        groupBox_SwatreOptions->setTitle(QCoreApplication::translate("lisemqtClass", "Swatre options", nullptr));
        label_159->setText(QCoreApplication::translate("lisemqtClass", "minimum internal timestep SWATRE (sec)", nullptr));
        checkInfilHinit->setText(QCoreApplication::translate("lisemqtClass", "Homogeneous initial matrix potential (cm)", nullptr));
        checkSwatreOutput->setText(QCoreApplication::translate("lisemqtClass", "save h and theta as a map for each node (.001, .002 etc.; Warning: slow!)", nullptr));
        checkSwatreDry->setText(QCoreApplication::translate("lisemqtClass", "Stop SWATRE for a cell when there is no runoff and no rainfall (faster)", nullptr));
        label_86->setText(QCoreApplication::translate("lisemqtClass", "Profile file (def. profile.inp)", nullptr));
        toolButton_SwatreTableDir->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_SwatreTableName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_13->setText(QCoreApplication::translate("lisemqtClass", "Profile table directory", nullptr));
        toolButton_SwatreTableShow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_144->setText(QCoreApplication::translate("lisemqtClass", "Swatre precision parameter (higher is more precise)", nullptr));
        toolButton_resetInfiltration->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_infil), QString());
        groupFloodParams->setTitle(QCoreApplication::translate("lisemqtClass", "Dynamic wave parameters", nullptr));
#if QT_CONFIG(tooltip)
        E_courantFactor->setToolTip(QCoreApplication::translate("lisemqtClass", "Smaller allows smaller timesteps", nullptr));
#endif // QT_CONFIG(tooltip)
        label_197->setText(QCoreApplication::translate("lisemqtClass", "Minimum timestep (sec): ", nullptr));
        label_84->setText(QCoreApplication::translate("lisemqtClass", "0 - closed boundary except outlets; 1 - open boundary; 2 - user defined map", nullptr));
        checkMUSCL->setText(QCoreApplication::translate("lisemqtClass", "Use MUSCL: better estimation of cell boundary flows (def. on)", nullptr));
        label_96->setText(QCoreApplication::translate("lisemqtClass", "Courant factor: ", nullptr));
        groupWaveUser->setTitle(QCoreApplication::translate("lisemqtClass", "Boundary inflow (sea surge, large flood) or initial water level", nullptr));
        toolButton_WaveInName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_148->setText(QCoreApplication::translate("lisemqtClass", "(needs whboundary.map where water level is forced (values 0,1))", nullptr));
        toolButton_WaveShow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        checkFloodInitial->setText(QCoreApplication::translate("lisemqtClass", "Include an initial water level (WHinit.map)", nullptr));
        checkWaterUserIn->setText(QCoreApplication::translate("lisemqtClass", "Water level change in time", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_resetFlow->setToolTip(QCoreApplication::translate("lisemqtClass", "<html><head/><body><p>Reset to default values.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_resetFlow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_88->setText(QCoreApplication::translate("lisemqtClass", "2D Surface flow", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_helpFlow->setToolTip(QCoreApplication::translate("lisemqtClass", "Help", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_helpFlow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_flooding), QString());
        toolButton_resetChannel->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        groupBaseflowParams->setTitle(QCoreApplication::translate("lisemqtClass", "Groundwater and baseflow to the river channel", nullptr));
        label_127->setText(QCoreApplication::translate("lisemqtClass", "For all GW flow types:", nullptr));
        label_155->setText(QCoreApplication::translate("lisemqtClass", "Type of flow:", nullptr));
        label_102->setText(QCoreApplication::translate("lisemqtClass", " - GW loss to deep percolation (mm/h)", nullptr));
        label_108->setText(QCoreApplication::translate("lisemqtClass", " - GW threshold level for outfow (m)", nullptr));
        label_97->setText(QCoreApplication::translate("lisemqtClass", "Ksat2 mult. factor", nullptr));
        label_77->setText(QCoreApplication::translate("lisemqtClass", " - Calibration factor for recharge soil profile to GW", nullptr));
        label_83->setText(QCoreApplication::translate("lisemqtClass", " - Calibration factor for GW flow towards the channel", nullptr));
        label_106->setText(QCoreApplication::translate("lisemqtClass", "Ksat2 mult. factor", nullptr));
        checkGWflowLDD->setText(QCoreApplication::translate("lisemqtClass", "GW flow accumulated over network (LDDbaseflow)", nullptr));
        checkGWflowSWAT->setText(QCoreApplication::translate("lisemqtClass", "GW flow based on SWAT model (soilwater fraction added directly to channel)", nullptr));
        checkGWflowexplicit->setText(QCoreApplication::translate("lisemqtClass", "Pressure based groundwater flow", nullptr));
        label_156->setText(QCoreApplication::translate("lisemqtClass", "Channel and groundwater options", nullptr));
        groupChannelParams->setTitle(QCoreApplication::translate("lisemqtClass", "Channel", nullptr));
        toolButton_DischargeShow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
#if QT_CONFIG(tooltip)
        checkChannelCulverts->setToolTip(QCoreApplication::translate("lisemqtClass", "map needed: chanmaxq.map", nullptr));
#endif // QT_CONFIG(tooltip)
        checkChannelCulverts->setText(QCoreApplication::translate("lisemqtClass", "Use Culverts in Channels (chanculvert.map)", nullptr));
        checkDischargeUser->setText(QCoreApplication::translate("lisemqtClass", "User defined channel inflow (e.g. dam spill):", nullptr));
        toolButton_DischargeName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_87->setText(QCoreApplication::translate("lisemqtClass", "Channel perimeter totuosity (1=rectangular)", nullptr));
        E_BaseflowMethod->setItemText(0, QCoreApplication::translate("lisemqtClass", "No stationary baseflow or channel infiltration", nullptr));
        E_BaseflowMethod->setItemText(1, QCoreApplication::translate("lisemqtClass", "Channel infiltration (chanksat.map)", nullptr));
        E_BaseflowMethod->setItemText(2, QCoreApplication::translate("lisemqtClass", "Stationary baseflow in all channel cells calculated from outlet points (baseflow.map)", nullptr));
        E_BaseflowMethod->setItemText(3, QCoreApplication::translate("lisemqtClass", "Stationary baseflow user-defined from map (baseflowinitvol.map)", nullptr));

        toolButton_helpChannel->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_Channel), QString());
        toolButton_helpInfra->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_resetInfra->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        groupMitigationWater->setTitle(QCoreApplication::translate("lisemqtClass", "Mitigation measures water", nullptr));
        checkFlowBarriers->setText(QCoreApplication::translate("lisemqtClass", "Include flood walls (flowbarrier.map):", nullptr));
        line_FlowBarriers->setText(QCoreApplication::translate("lisemqtClass", "flowbarriers.txt", nullptr));
        checkGridRentention->setText(QCoreApplication::translate("lisemqtClass", "User defined gridcell retention in m3 (needs gridretention.map)", nullptr));
        checkBuffers->setText(QCoreApplication::translate("lisemqtClass", "Include water/sediment barriers and buffers (buffers.map)", nullptr));
        label_15->setText(QCoreApplication::translate("lisemqtClass", "   - Manning's n grass strip: ", nullptr));
        checkInfilGrass->setText(QCoreApplication::translate("lisemqtClass", "Vegetation strips (needs graswidt.map, ksatgras.map, poregras.map and cohgras.map)", nullptr));
        groupConservationSed->setTitle(QCoreApplication::translate("lisemqtClass", "Conservation measures sediment", nullptr));
        checkSedtrap->setText(QCoreApplication::translate("lisemqtClass", "Sediment traps/fences (needs sedretmax.map, max volume sed. trapped in m3)", nullptr));
        label_191->setText(QCoreApplication::translate("lisemqtClass", "&#8226", nullptr));
        label_104->setText(QCoreApplication::translate("lisemqtClass", "Manning's n sediment trap:", nullptr));
        label_189->setText(QCoreApplication::translate("lisemqtClass", "&#8226", nullptr));
        label_33->setText(QCoreApplication::translate("lisemqtClass", "Bulk density of deposited layer(kg/m3): ", nullptr));
        checkDrainNoOutflow->setText(QCoreApplication::translate("lisemqtClass", "Storrm drain has no outflow", nullptr));
        checkStormDrainCirc->setText(QCoreApplication::translate("lisemqtClass", "Pipe", nullptr));
        checkStormDrainRect->setText(QCoreApplication::translate("lisemqtClass", "Rectangular", nullptr));
        label_147->setText(QCoreApplication::translate("lisemqtClass", "   Size street inlet (m2): ", nullptr));
        label_14->setText(QCoreApplication::translate("lisemqtClass", "-  ", nullptr));
        checkStormDrains->setText(QCoreApplication::translate("lisemqtClass", "Include subsurface storm drains:   ", nullptr));
        label_166->setText(QCoreApplication::translate("lisemqtClass", " -  Distance between street inlets (m): ", nullptr));
        checkRoadsystem->setText(QCoreApplication::translate("lisemqtClass", "Include road system", nullptr));
        checkHouses->setText(QCoreApplication::translate("lisemqtClass", "Include buildings ", nullptr));
        checkAddBuildingDEM->setText(QCoreApplication::translate("lisemqtClass", "Add buildings to DEM if larger than fraction:", nullptr));
        checkRaindrum->setText(QCoreApplication::translate("lisemqtClass", "Include rainwater storage by drums", nullptr));
        label_78->setText(QCoreApplication::translate("lisemqtClass", " - ", nullptr));
        label_145->setText(QCoreApplication::translate("lisemqtClass", " - ", nullptr));
        label_140->setText(QCoreApplication::translate("lisemqtClass", "Building height", nullptr));
        checkHardsurface->setText(QCoreApplication::translate("lisemqtClass", "Include other hard surfaces (runways, parkinglots etc.)", nullptr));
        label_89->setText(QCoreApplication::translate("lisemqtClass", "Buildings, Roads and Conservation Measures", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_Infra), QString());
        toolButton_resetErosion->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_143->setText(QCoreApplication::translate("lisemqtClass", "Settling velocity: ", nullptr));
        groupSed->setTitle(QCoreApplication::translate("lisemqtClass", "Overland flow ", nullptr));
        checkDiffusion->setText(QCoreApplication::translate("lisemqtClass", "Enable diffusive suspended sediment flow", nullptr));
        label_91->setText(QCoreApplication::translate("lisemqtClass", "Detachment efficiency:", nullptr));
        label_109->setText(QCoreApplication::translate("lisemqtClass", "Suspended Sediment Transport:", nullptr));
        E_EfficiencyDET->setItemText(0, QCoreApplication::translate("lisemqtClass", "1 - Y=1/(0.89+0.56*Cohesion)", nullptr));
        E_EfficiencyDET->setItemText(1, QCoreApplication::translate("lisemqtClass", "2 - Y=0.79exp(-0.85*Cohesion)", nullptr));
        E_EfficiencyDET->setItemText(2, QCoreApplication::translate("lisemqtClass", "3 - Y=1/(2.0*Cohesion)", nullptr));

        E_SSMethod->setItemText(0, QCoreApplication::translate("lisemqtClass", "1 - Govers", nullptr));
        E_SSMethod->setItemText(1, QCoreApplication::translate("lisemqtClass", "2- Hairsine and Rose", nullptr));

        groupKinEnergy->setTitle(QCoreApplication::translate("lisemqtClass", "Kinetic energy rainfall", nullptr));
        label_67->setText(QCoreApplication::translate("lisemqtClass", "c ", nullptr));
        label_65->setText(QCoreApplication::translate("lisemqtClass", "a ", nullptr));
        label_66->setText(QCoreApplication::translate("lisemqtClass", "b ", nullptr));
        label_72->setText(QCoreApplication::translate("lisemqtClass", "b ", nullptr));
        label_71->setText(QCoreApplication::translate("lisemqtClass", "b ", nullptr));
        label_58->setText(QCoreApplication::translate("lisemqtClass", "Splash delivery ratio", nullptr));
        label_73->setText(QCoreApplication::translate("lisemqtClass", "a ", nullptr));
        radioButtonKE1->setText(QCoreApplication::translate("lisemqtClass", "KE = a (1 - b exp(-c Iintensity)):", nullptr));
        label_70->setText(QCoreApplication::translate("lisemqtClass", "a ", nullptr));
        radioButtonKE2->setText(QCoreApplication::translate("lisemqtClass", "KE = a + b * log(Intensity):", nullptr));
        spinKEparameterA1->setPrefix(QString());
        spinKEparameterA1->setSuffix(QString());
        radioButtonKE3->setText(QCoreApplication::translate("lisemqtClass", "KE = a * Intensity^b:", nullptr));
        label_141->setText(QCoreApplication::translate("lisemqtClass", "Splash equations of Lisem (1) or Eurosem (2)", nullptr));
        label_142->setText(QCoreApplication::translate("lisemqtClass", "(see help!)", nullptr));
        label_9->setText(QCoreApplication::translate("lisemqtClass", "Splash Detachment", nullptr));
        label_10->setText(QCoreApplication::translate("lisemqtClass", "Flow Detachment and transport", nullptr));
        groupSedCH->setTitle(QCoreApplication::translate("lisemqtClass", "Channel ", nullptr));
        label_4->setText(QCoreApplication::translate("lisemqtClass", "Suspended sediment Transport: ", nullptr));
        label_11->setText(QCoreApplication::translate("lisemqtClass", "Detachment efficiency:", nullptr));
        checkDiffusionCH->setText(QCoreApplication::translate("lisemqtClass", "Enable diffusive suspended sediment flow", nullptr));
        E_EfficiencyDETCH->setItemText(0, QCoreApplication::translate("lisemqtClass", "1 - Y=1/(0.89+0.56*Cohesion)", nullptr));
        E_EfficiencyDETCH->setItemText(1, QCoreApplication::translate("lisemqtClass", "2 - Y=0.79exp(-0.85*Cohesion)", nullptr));
        E_EfficiencyDETCH->setItemText(2, QCoreApplication::translate("lisemqtClass", "3 - Y=1/(2.0*Cohesion)", nullptr));
        E_EfficiencyDETCH->setItemText(3, QCoreApplication::translate("lisemqtClass", "4 - Y = direct factor  ==>", nullptr));

        checkSed2Phase->setText(QCoreApplication::translate("lisemqtClass", "Include bedload transport", nullptr));
        label_157->setText(QCoreApplication::translate("lisemqtClass", "Turbulence factor to limit deposition: ", nullptr));
        label_165->setText(QCoreApplication::translate("lisemqtClass", "(0=no dep.; 1=max dep.)", nullptr));
        E_RSSMethod->setItemText(0, QCoreApplication::translate("lisemqtClass", "1 - Govers", nullptr));
        E_RSSMethod->setItemText(1, QCoreApplication::translate("lisemqtClass", "2 - Van Rijn Simplified", nullptr));
        E_RSSMethod->setItemText(2, QCoreApplication::translate("lisemqtClass", "3 - Van Rijn Full", nullptr));
        E_RSSMethod->setItemText(3, QCoreApplication::translate("lisemqtClass", "4 - Engelund and Hansen", nullptr));

        E_RSSMethod->setCurrentText(QCoreApplication::translate("lisemqtClass", "2 - Van Rijn Simplified", nullptr));
        E_RBLMethod->setItemText(0, QCoreApplication::translate("lisemqtClass", "2 - Van Rijn Simplified", nullptr));
        E_RBLMethod->setItemText(1, QCoreApplication::translate("lisemqtClass", "3 - Van Rijn Full", nullptr));
        E_RBLMethod->setItemText(2, QCoreApplication::translate("lisemqtClass", "4 - Engelund and Hansen", nullptr));

        E_settlingVelocity->setItemText(0, QCoreApplication::translate("lisemqtClass", "1 - Stokes/Zanke (1977)", nullptr));
        E_settlingVelocity->setItemText(1, QCoreApplication::translate("lisemqtClass", "2 - Zhiyao et al, (2008)", nullptr));

        toolButton_helpErosion->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_erosion), QString());
        label_59->setText(QCoreApplication::translate("lisemqtClass", "Calibration", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_resetCalibration->setToolTip(QCoreApplication::translate("lisemqtClass", "Reset all values to 1.0", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_resetCalibration->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_helpCalibration->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        groupCalFlow->setTitle(QCoreApplication::translate("lisemqtClass", "Flow", nullptr));
        label_150->setText(QCoreApplication::translate("lisemqtClass", "Incoming water level (wave) on boundary", nullptr));
        label_134->setText(QString());
        label_calchn->setText(QCoreApplication::translate("lisemqtClass", "Manning N Channel (Channel flow resistance: chanman.map)        ", nullptr));
        label_calchks->setText(QCoreApplication::translate("lisemqtClass", "Ksat Channel (channel bed infil: chanksat.map)", nullptr));
        label_calN->setText(QCoreApplication::translate("lisemqtClass", "Manning N slopes (flow resistance: N.map)", nullptr));
        label_62->setText(QCoreApplication::translate("lisemqtClass", "Culvert diameter ", nullptr));
        groupCalErosion->setTitle(QCoreApplication::translate("lisemqtClass", "Erosion", nullptr));
        label_calchcoh->setText(QCoreApplication::translate("lisemqtClass", "Channel bed Cohesion (channel detachment: chancoh.map)", nullptr));
        label_cald50->setText(QCoreApplication::translate("lisemqtClass", "Median texture D50 (transp.suspended, deposition: d50.map)", nullptr));
        label_calcoh->setText(QCoreApplication::translate("lisemqtClass", "Soil Cohesion (flow detachment: coh.map and cohadd.map)", nullptr));
        label_69->setText(QCoreApplication::translate("lisemqtClass", "Texture 90% quantile D90 ((transp. bedload, deposition: d90.map)", nullptr));
        label_calas->setText(QCoreApplication::translate("lisemqtClass", "Aggregate Stability (splash detachment: aggrstab.map)", nullptr));
        label_68->setText(QCoreApplication::translate("lisemqtClass", "These factors are directly multiplied with the input maps", nullptr));
        groupCalHydrology->setTitle(QCoreApplication::translate("lisemqtClass", "Hydrology", nullptr));
        label_146->setText(QCoreApplication::translate("lisemqtClass", "Surface micro roughness (RR.map)", nullptr));
        label_calKsat2->setText(QCoreApplication::translate("lisemqtClass", "Ksat soil layer 2  (Ksat2.map or 2nd SWATRE horizon)               ", nullptr));
        label_76->setText(QCoreApplication::translate("lisemqtClass", "Interception storage canopy (Smax.map)", nullptr));
        label_calKsat->setText(QCoreApplication::translate("lisemqtClass", "Ksat soil layer 1 (Ksat1.map or 1st SWATRE horizon)", nullptr));
        label_calth->setText(QCoreApplication::translate("lisemqtClass", "Theta (initial moisture: thetai1.map & thetai2.map, not used in SWATRE)", nullptr));
        label_calpsi->setText(QCoreApplication::translate("lisemqtClass", "Matrix potential (wetting front G&A or SWATRE inithead maps)", nullptr));
        label_calKsat3->setText(QCoreApplication::translate("lisemqtClass", "Ksat soil layer 3 (Ksat3.map or 3rd SWATRE horizon)", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_calib), QString());
        checkAdvancedOptions->setText(QCoreApplication::translate("lisemqtClass", "Advanced options", nullptr));
        groupAdvRichards->setTitle(QCoreApplication::translate("lisemqtClass", "Infiltration", nullptr));
        comboBox_Kmean->setItemText(0, QCoreApplication::translate("lisemqtClass", "Arithmetric mean", nullptr));
        comboBox_Kmean->setItemText(1, QCoreApplication::translate("lisemqtClass", "Geometric mean", nullptr));
        comboBox_Kmean->setItemText(2, QCoreApplication::translate("lisemqtClass", "Harmonic mean", nullptr));
        comboBox_Kmean->setItemText(3, QCoreApplication::translate("lisemqtClass", "Use smallest", nullptr));

        label_158->setText(QCoreApplication::translate("lisemqtClass", "of Hydraulic Conductivity K between two nodes", nullptr));
        checkPsiUser->setText(QCoreApplication::translate("lisemqtClass", "Wetting front Psi as input maps (v) or calculated internally ( )", nullptr));
        label_164->setText(QCoreApplication::translate("lisemqtClass", "Above this suction water enters the tiledrain, only SWATRE (cm):", nullptr));
        checkMB_WH->setText(QCoreApplication::translate("lisemqtClass", "Correct mass balance each timestep", nullptr));
        checkInfilOMcorrection->setText(QCoreApplication::translate("lisemqtClass", "Apply Org.Mat. correction to Ksat and Porosity (needs omcorr.map)", nullptr));
        checkInfilDensfactor->setText(QCoreApplication::translate("lisemqtClass", "Apply Density Factor correction to Ksat and Porosity (needs densfact.map)", nullptr));
        toolButton_version->setText(QCoreApplication::translate("lisemqtClass", "New Version", nullptr));
        toolButton_helpAdvanced->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        groupAdvKinwave->setTitle(QCoreApplication::translate("lisemqtClass", "Kinematic Wave", nullptr));
        checkPerimeterKW->setText(QCoreApplication::translate("lisemqtClass", "Perimeter overland flow as width w [ ], or (w+2h) [v] (backward compatibility)", nullptr));
        groupAdvChannel->setTitle(QCoreApplication::translate("lisemqtClass", "Channel flow", nullptr));
        checkChanMaxVelocity->setText(QCoreApplication::translate("lisemqtClass", "Set channel max velocity", nullptr));
        checkChannel2DflowConnect->setText(QCoreApplication::translate("lisemqtClass", "Standard connection to 2D flow ( ) or broad crested weir equations (v)", nullptr));
        toolButton_resetAdvanced->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        groupAdvSWOF->setTitle(QCoreApplication::translate("lisemqtClass", "Numerical parameters for dynamic wave", nullptr));
        label_199->setText(QCoreApplication::translate("lisemqtClass", "<html><head/><body><p>Max iterations (def. 200)</p></body></html>", nullptr));
        check2DDiagonalFlow->setText(QCoreApplication::translate("lisemqtClass", "Enable diagonal flow if pit water level more than", nullptr));
        checkCorrectDem->setText(QCoreApplication::translate("lisemqtClass", "Ignore pits: set pit elevation to lowest surrounding cell (3x3 window)", nullptr));
        label_123->setText(QCoreApplication::translate("lisemqtClass", "Riemann solver: 1-Rusanov; 2-HLL; 3-HLL2; ", nullptr));
#if QT_CONFIG(tooltip)
        E_FloodReconstruction->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        checkTimeavgV->setText(QCoreApplication::translate("lisemqtClass", "Time average velocity in 2D flow (def. on)", nullptr));
        label_135->setText(QCoreApplication::translate("lisemqtClass", " (m)", nullptr));
        checkErosionLoop->setText(QCoreApplication::translate("lisemqtClass", "Do erosion outside the 2D loop", nullptr));
        label_161->setText(QCoreApplication::translate("lisemqtClass", "Minimum threshold for waterheight and velocity calculations: ", nullptr));
        E_minWHVSWOF->setText(QCoreApplication::translate("lisemqtClass", "1e-6", nullptr));
        checkNewversionGITHUB->setText(QCoreApplication::translate("lisemqtClass", "Check for a new version on GITHUB when you start the program", nullptr));
        label_56->setText(QCoreApplication::translate("lisemqtClass", "Nr of CPU cores (0 = all cores; 1 = 1 core etc.)", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_advanced), QString());
        checkGWflowSWOF->setText(QCoreApplication::translate("lisemqtClass", "Pressure based Riemann (experimental!)", nullptr));
        E_BLMethod->setItemText(0, QCoreApplication::translate("lisemqtClass", "1 - Govers", nullptr));
        E_BLMethod->setItemText(1, QCoreApplication::translate("lisemqtClass", "2 - Van Rijn Simplified", nullptr));
        E_BLMethod->setItemText(2, QCoreApplication::translate("lisemqtClass", "3 - Van Rijn Full", nullptr));
        E_BLMethod->setItemText(3, QCoreApplication::translate("lisemqtClass", "4 - Engelund and Hansen", nullptr));

        E_BLMethod->setCurrentText(QCoreApplication::translate("lisemqtClass", "2 - Van Rijn Simplified", nullptr));
        E_BulkDens2->setInputMask(QCoreApplication::translate("lisemqtClass", "9999.9", nullptr));
        E_BulkDens2->setText(QCoreApplication::translate("lisemqtClass", "1500.0", nullptr));
        label->setText(QCoreApplication::translate("lisemqtClass", "Soil Depth 1", nullptr));
#if QT_CONFIG(tooltip)
        E_FloodFluxLimiter->setToolTip(QCoreApplication::translate("lisemqtClass", "Avoiding oscillations in PDE", nullptr));
#endif // QT_CONFIG(tooltip)
        label_130->setText(QCoreApplication::translate("lisemqtClass", "Particle cohesion of deposited layer: ", nullptr));
        groupBox_RichardsOptions->setTitle(QCoreApplication::translate("lisemqtClass", "Richards Finite Element options", nullptr));
        label_152->setText(QCoreApplication::translate("lisemqtClass", "#Nodes in layer 1 ", nullptr));
        label_154->setText(QCoreApplication::translate("lisemqtClass", "#Nodes in layer 3", nullptr));
        label_151->setText(QCoreApplication::translate("lisemqtClass", "#Nodes in layer 2 ", nullptr));
        label_132->setText(QCoreApplication::translate("lisemqtClass", "Courant factor for sediment diffusion in river and flood water", nullptr));
        checkChannelWFinflow->setText(QCoreApplication::translate("lisemqtClass", "Include inflow into channel from saturated soil (Ksat based)", nullptr));
        label_139->setText(QCoreApplication::translate("lisemqtClass", "Settling Velocity calibration", nullptr));
        label_100->setText(QCoreApplication::translate("lisemqtClass", "MUSCL Flux limiter: 1 - Minmod; 2 - van Leer; 3 - van Albeda", nullptr));
        label_85->setText(QCoreApplication::translate("lisemqtClass", "Baseflow: Distance to river contribution coeff. a: ((dx/L)^a)", nullptr));
        checkNoSedBoundary->setText(QCoreApplication::translate("lisemqtClass", "No detachment/deposition at domain boundary", nullptr));
        toolButton_SnowmeltmapShow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_SnowmeltName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        radioButton_10->setText(QCoreApplication::translate("lisemqtClass", "Snowmelt map file list", nullptr));
        radioButton->setText(QCoreApplication::translate("lisemqtClass", "Snowmelt Station file", nullptr));
        toolButton_SnowmeltSatName->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_SnowmeltShow->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_101->setText(QCoreApplication::translate("lisemqtClass", "Turbulent Prandtl-Schmidt number", nullptr));
        checkSnowmelt->setText(QCoreApplication::translate("lisemqtClass", "Snowmelt", nullptr));
        label_160->setText(QCoreApplication::translate("lisemqtClass", "Richards equation soil physics: 1 - Brooks-Corey; 2 - Van Genuchten", nullptr));
        label_129->setText(QCoreApplication::translate("lisemqtClass", "SPARE PAGE, DELETED AT RUNTIME!!! for near obsolete options", nullptr));
        label_61->setText(QCoreApplication::translate("lisemqtClass", "Soil Depth 2", nullptr));
        checkKETimebased->setText(QCoreApplication::translate("lisemqtClass", "time based", nullptr));
        checkLinkedList->setText(QCoreApplication::translate("lisemqtClass", "Use linked list for kinematic flow", nullptr));
        checkKinWaveChannel->setText(QCoreApplication::translate("lisemqtClass", "Loop kin wave on dt = 0.5*dx ", nullptr));
        checkStationaryBaseflow->setText(QCoreApplication::translate("lisemqtClass", "Add stationary baseflow everywhere calculated from outlets (baseflow.map)", nullptr));
        checkChannelInfil->setText(QCoreApplication::translate("lisemqtClass", "Channel infiltration (chanksat.map)", nullptr));
        tabWidgetOptions->setTabText(tabWidgetOptions->indexOf(tab_spare), QCoreApplication::translate("lisemqtClass", "Page", nullptr));
        groupBox_dbase->setTitle(QCoreApplication::translate("lisemqtClass", "Database", nullptr));
        label_1->setText(QCoreApplication::translate("lisemqtClass", "Run file(s) ", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_fileOpen->setToolTip(QCoreApplication::translate("lisemqtClass", "Select run file", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_fileOpen->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_MapDir->setToolTip(QCoreApplication::translate("lisemqtClass", "Select a map directory, this is appended to all maps", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_MapDir->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        toolButton_ResultDir->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
        label_2->setText(QCoreApplication::translate("lisemqtClass", "Map directory ", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_deleteRun->setToolTip(QCoreApplication::translate("lisemqtClass", "Delete current run file from list", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_deleteRun->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
#if QT_CONFIG(tooltip)
        E_MapDir->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        E_MapDir->setText(QString());
        label_3->setText(QCoreApplication::translate("lisemqtClass", "   Result directory ", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_ShowRunfile->setToolTip(QCoreApplication::translate("lisemqtClass", "Show current run file", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_ShowRunfile->setText(QCoreApplication::translate("lisemqtClass", "...", nullptr));
#if QT_CONFIG(tooltip)
        checkAddDatetime->setToolTip(QCoreApplication::translate("lisemqtClass", "<html><head/><body><p>Make a subdirectory under the result directory with a date-time stamp</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkAddDatetime->setText(QCoreApplication::translate("lisemqtClass", "Add time", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_input), QCoreApplication::translate("lisemqtClass", "Input/Output", nullptr));
        label_47->setText(QCoreApplication::translate("lisemqtClass", "Double Click on map name to open file interface, F2 to edit name dircetly ", nullptr));
        groupBox_InputMaps->setTitle(QCoreApplication::translate("lisemqtClass", "Input Maps", nullptr));
        checkExpandActive->setText(QCoreApplication::translate("lisemqtClass", "Expand activated maps categories", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_maps), QCoreApplication::translate("lisemqtClass", "Map dbase", nullptr));
        groupTime->setTitle(QCoreApplication::translate("lisemqtClass", "Size", nullptr));
        label_endtime->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_area->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_time->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_29->setText(QCoreApplication::translate("lisemqtClass", "                     time (min)", nullptr));
        label_dx->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_46->setText(QCoreApplication::translate("lisemqtClass", "Cellsize (m)", nullptr));
        label_38->setText(QCoreApplication::translate("lisemqtClass", "   End time (min)", nullptr));
        label_48->setText(QCoreApplication::translate("lisemqtClass", "Area (km2)", nullptr));
        label_35->setText(QCoreApplication::translate("lisemqtClass", "Hydrology (mm)", nullptr));
        label_64->setText(QCoreApplication::translate("lisemqtClass", "Flow (mm)", nullptr));
        label_32->setText(QCoreApplication::translate("lisemqtClass", "Precipitation", nullptr));
        label_raintot->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_40->setText(QCoreApplication::translate("lisemqtClass", "Runoff", nullptr));
        label_watervoltot->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_34->setText(QCoreApplication::translate("lisemqtClass", "Interception", nullptr));
        label_interctot->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_107->setText(QCoreApplication::translate("lisemqtClass", "Flood", nullptr));
        label_floodVolmm->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_36->setText(QCoreApplication::translate("lisemqtClass", "Infiltration", nullptr));
        label_infiltot->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_95->setText(QCoreApplication::translate("lisemqtClass", "Channels", nullptr));
        label_watervolchannel->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_37->setText(QCoreApplication::translate("lisemqtClass", "Surface Store", nullptr));
        label_surfstor->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_42->setText(QCoreApplication::translate("lisemqtClass", "Discharge", nullptr));
        label_qtot->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_124->setText(QCoreApplication::translate("lisemqtClass", "ETa", nullptr));
        label_ETatot->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_99->setText(QCoreApplication::translate("lisemqtClass", "Baseflow", nullptr));
        label_stormdraintot->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        tabWidget_totout->setTabText(tabWidget_totout->indexOf(tab_water), QCoreApplication::translate("lisemqtClass", "Water", nullptr));
        label_soilloss->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_depch->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_flowdet->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_21->setText(QCoreApplication::translate("lisemqtClass", "Splash", nullptr));
        label_sedvol->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_23->setText(QCoreApplication::translate("lisemqtClass", "Flow detachment", nullptr));
        label_splashdet->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_dep->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_soillosskgha->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_25->setText(QCoreApplication::translate("lisemqtClass", "Sediment in flow", nullptr));
        label_39->setText(QCoreApplication::translate("lisemqtClass", "Sediment in flow", nullptr));
        label_41->setText(QCoreApplication::translate("lisemqtClass", "Detachment", nullptr));
        label_43->setText(QCoreApplication::translate("lisemqtClass", "Deposition", nullptr));
        label_51->setText(QCoreApplication::translate("lisemqtClass", "Surface (ton)", nullptr));
        label_sedvolch->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_31->setText(QCoreApplication::translate("lisemqtClass", "Soil loss (kg/ha)", nullptr));
        label_50->setText(QCoreApplication::translate("lisemqtClass", "Channels (ton)", nullptr));
        label_27->setText(QCoreApplication::translate("lisemqtClass", "Deposition", nullptr));
        label_detch->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_28->setText(QCoreApplication::translate("lisemqtClass", "Total soil loss (ton)", nullptr));
        label_60->setText(QCoreApplication::translate("lisemqtClass", "Sed. Del. Ratio  (%)", nullptr));
        label_SDR->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        tabWidget_totout->setTabText(tabWidget_totout->indexOf(tab_sed), QCoreApplication::translate("lisemqtClass", "Sediment", nullptr));
        outletgroup->setTitle(QCoreApplication::translate("lisemqtClass", "Catchment outlet", nullptr));
        label_qpeaksub->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_soillosssub->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_54->setText(QCoreApplication::translate("lisemqtClass", "Q (l/s)", nullptr));
        label_82->setText(QCoreApplication::translate("lisemqtClass", "Qpeak (l/s)", nullptr));
        label_26->setText(QCoreApplication::translate("lisemqtClass", "Total discharge (m3)", nullptr));
        label_24->setText(QCoreApplication::translate("lisemqtClass", "peak time Q (min)", nullptr));
        label_dischargesub->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_qtotm3sub->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_qpeaktime->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_ppeaktime->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_94->setText(QCoreApplication::translate("lisemqtClass", "Soil loss (ton)", nullptr));
        label_53->setText(QCoreApplication::translate("lisemqtClass", "peak time P (min)", nullptr));
        label_QPfrac->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_52->setText(QCoreApplication::translate("lisemqtClass", "Q/P (%)", nullptr));
        label_Qssub->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_105->setText(QCoreApplication::translate("lisemqtClass", "Sed. Flux (kg/s)", nullptr));
        groupBox_drawMap->setTitle(QCoreApplication::translate("lisemqtClass", "Map Display", nullptr));
#if QT_CONFIG(tooltip)
        transparency->setToolTip(QCoreApplication::translate("lisemqtClass", "Transparency buildings", nullptr));
#endif // QT_CONFIG(tooltip)
        label_162->setText(QCoreApplication::translate("lisemqtClass", "Min", nullptr));
        label_163->setText(QCoreApplication::translate("lisemqtClass", "Max", nullptr));
        checkBoxComboMaps2->setText(QString());
        checkMapBuildings->setText(QCoreApplication::translate("lisemqtClass", "Buildings      ", nullptr));
        checkMapRoads->setText(QCoreApplication::translate("lisemqtClass", "Roads", nullptr));
        checkMapHardSurface->setText(QCoreApplication::translate("lisemqtClass", "Hard.Surf.", nullptr));
        label_92->setText(QCoreApplication::translate("lisemqtClass", "Relief", nullptr));
        label_90->setText(QCoreApplication::translate("lisemqtClass", "Contours", nullptr));
        nrcontourlevels->setSuffix(QString());
        checkBoxComboMaps->setText(QString());
        checkMapChannels->setText(QString());
        label_137->setText(QCoreApplication::translate("lisemqtClass", "Channels", nullptr));
        label_113->setText(QCoreApplication::translate("lisemqtClass", "Outlets", nullptr));
        checkMapImage->setText(QCoreApplication::translate("lisemqtClass", "Image", nullptr));
        groupBox_info->setTitle(QCoreApplication::translate("lisemqtClass", "Info", nullptr));
        label_MBs->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
#if QT_CONFIG(tooltip)
        label_hydroCount->setToolTip(QCoreApplication::translate("lisemqtClass", "0 = sum of all discharge water and sediment leaving the model domain;1-n = hydrographs and sedigraphs at user defined datapoints in outpoint.map", nullptr));
#endif // QT_CONFIG(tooltip)
        label_hydroCount->setText(QCoreApplication::translate("lisemqtClass", "Point (0, 1-n)", nullptr));
        label_30->setText(QCoreApplication::translate("lisemqtClass", "runtime (min)", nullptr));
        label_runtime->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_MB->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_endruntime->setText(QCoreApplication::translate("lisemqtClass", "0", nullptr));
        label_debug->setText(QString());
        label_75->setText(QCoreApplication::translate("lisemqtClass", "end run (min)", nullptr));
        label_45->setText(QCoreApplication::translate("lisemqtClass", "MB Sed (%)", nullptr));
        label_44->setText(QCoreApplication::translate("lisemqtClass", "MB Water(%)", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxPointtoShow->setToolTip(QCoreApplication::translate("lisemqtClass", "<html><head/><body><p>0 = sum of all discharge water and sediment leaving the model domain;1-n = hydrographs and sedigraphs at user defined datapoints in outpoint.map</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        progressBar->setFormat(QCoreApplication::translate("lisemqtClass", "%p% (%v-%m)", nullptr));
        tabWidget_out->setTabText(tabWidget_out->indexOf(tab_1), QString());
        tabWidget_out->setTabText(tabWidget_out->indexOf(tab_2), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_simulation), QCoreApplication::translate("lisemqtClass", "Simulation", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("lisemqtClass", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("lisemqtClass", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lisemqtClass: public Ui_lisemqtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISEMQT_H
