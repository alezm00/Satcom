class CBA_Extended_EventHandlers;

class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class acre_gen_sys_placeSatCom {
                    displayName = "Place SatCom";
                    condition = "[_player, 'ACRE_GEN_SatCom'] call acre_sys_core_fnc_hasItem";
                    statement = "[_player] call acre_gen_SatCom_sys_gsa_fnc_deploy";
                    showDisabled = 0;
                    icon = "\azm_satcom\data\satcom_icon.paa";
                };
            };
        };
    };

    // class House;
    class Land_SatelliteAntenna_01_F;
    class ACRE_GEN_SatComItem: Land_SatelliteAntenna_01_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };

        scope = 2;
        scopeCurator = 2;
        scopeArsenal = 2;
        displayName = "[AZM-9GU] SatCom ACRE";
        model = "\A3\Props_F_Enoch\Military\Camps\SatelliteAntenna_01_F.p3d";
        icon = "iconObject_5x4";
        editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\Land_SatelliteAntenna_01_F.jpg";
        vehicleClass = "Items";

        editorCategory = "azm_satcom"; // Class from CfgEditorCategories. Usually used for props.
        //editorSubcategory = "gen_cat_acre"; // Class from CfgEditorSubcategories. Should be used everywhere.

        class AcreComponents {
            componentName = "ACRE_GEN_km_VHF_TNC";
            mountedAntenna = "";
            mastMount[] = {};
        };


        class ACE_Actions {
            class ACE_MainActions {
                selection = "interaction_point";
                distance  = 5;
                condition = "(true)";

                class ACRE_pickup {
                    selection = "";
                    displayName = "Pick up";
                    distance = 10;
                    condition = "true";
                    statement = "[_player, _target] call acre_gen_SatCom_sys_gsa_fnc_pickUp";
                    showDisabled = 0;
                    exceptions[] = {};
                    priority = 5;
                };

                class ACRE_connect {
                    selection = "";
                    displayName = "Connect";
                    distance = 10;
                    condition = "!([_player, _target] call acre_sys_gsa_fnc_isAntennaConnected) && {[_player, _target] call acre_sys_gsa_fnc_hasCompatibleRadios}";
                    statement = "true";
                    insertChildren = "[_player, _target] call acre_sys_gsa_fnc_connectChildrenActions";
                    showDisabled = 0;
                    exceptions[] = {};
                    priority = 5;
                    icon = "\idi\acre\addons\ace_interact\data\icons\antenna.paa";
                };

                class ACRE_disconnect {
                    selection = "";
                    displayName = "Disconnect";
                    distance = 10;
                    condition = "[_player, _target] call acre_sys_gsa_fnc_isAntennaConnected";
                    statement = "[_player, _target] call acre_sys_gsa_fnc_disconnect";
                    showDisabled = 0;
                    exceptions[] = {};
                    priority = 5;
                    icon = "\idi\acre\addons\ace_interact\data\icons\antenna.paa";
                };
            };
        };
    };
};
