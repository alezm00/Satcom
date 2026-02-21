class CfgPatches {
    class azm_satcom {
        author = "Alezm";
        name = "[AZM-9GU] SatCom for ACRE2";
        url = "";
        units[] = {};
        weapons[] = {"ACRE_GEN_SatCom"};
        requiredVersion = 1.0;
        requiredAddons[] = {"CBA_MAIN","ace_main","acre_main"};
        skipWhenMissingDependencies = 1;
        version = 1.0;
        authors[] = {"Alezm"};
    };
};
class CfgEditorCategories {
	class azm_satcom // Category class, you point to it in editorCategory property
	{
		displayName = "[AZM-9GU] SatCom for ACRE2"; // Name visible in the list
	};
};



#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgAcreComponents.hpp"

