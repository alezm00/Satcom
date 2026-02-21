class CfgAcreComponents {
    class ACRE_ComponentBase;
    class ACRE_BaseAntenna;
    // class ACRE_BaseAntenna: ACRE_ComponentBase {
    //     type = 1;
    //     simple = 1;
    //     polarization = 0;
    //     heightAG = 1.8288;
    //     orient = 90; // in degrees off of flat plane
    //     name = "Default Antenna";
    //     shortName = "Default";
    //     connector = 1;
    //     height = 1.2; //meters
    //     binaryGainFile = "\idi\acre\addons\sys_antenna\binary\Thales_100cm_Whip_gain.aba";
    //     compatibleRadios[] = {};
    // };


    class ACRE_GEN_km_VHF_TNC: ACRE_BaseAntenna {
        name = "{9GU} SatCom ACRE";
        shortName = "9GU SatCom ACRE";
        connector = 1;
        height = 5000;
        binaryGainFile = "\idi\acre\addons\sys_antenna\binary\groundspike_2430cm_mast_gain.aba";
        compatibleRadios[] = {"ACRE_PRC148", "ACRE_PRC152", "ACRE_PRC117F"};
    };

};
