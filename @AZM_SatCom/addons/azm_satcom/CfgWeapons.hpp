class CfgWeapons {
    class CBA_MiscItem;
    class CBA_MiscItem_ItemInfo;

    class ACRE_GEN_SatCom: CBA_MiscItem {
        author[] = {"Alezm"};
        scope = 2;
        displayName = "[AZM/9GU] SatCom ACRE";
        descriptionShort = "Satcom Antenna (by Alezm for 9GU)";
        model = "\a3\Props_F_Enoch\Military\Equipment\BatteryPack_01_Closed_F.p3d";
        // model = "\A3\Structures_F\Items\Electronics\SatellitePhone_F.p3d";
        picture = "\gen_acre\data\satcom_icon.paa";

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 25;
        };
    };
};
