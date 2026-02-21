
// [_player, 'ACRE_VHF30108SPIKE', false] call acre_gen_SatCom_sys_gsa_fnc_deploy
// item ACRE_GEN_SatCom
acre_gen_SatCom_sys_gsa_fnc_deploy = {
    params ["_unit"];

    private _gsaItem = "ACRE_GEN_SatCom";
    private _gsa = "ACRE_GEN_SatComItem";
    // private _canDeploy = false;

    // switch (_gsaItem) do {
    //     case "ACRE_VHF30108": {
    //         _gsa = "vhf30108Item";
    //         _canDeploy = true;
    //     };
    //     case "ACRE_VHF30108SPIKE" : {
    //         _gsa = "vhf30108spike";
    //         _canDeploy = true;
    //     };
    // };

    // if (_canDeploy) then {

    _unit removeItem _gsaItem;

    if (stance _unit == "STAND") then {
        [_unit, "AmovPercMstpSrasWrflDnon_diary"] call ace_common_fnc_doAnimation;
    };

    [{
        params ["_unit", "_gsa"];

        private _direction = getDir _unit;
        private _zOffset = 0.0;
        private _position = getPosASL _unit vectorAdd [2 * sin _direction, 2 * cos _direction, 0];

        private _vectorUp = [0, 0, 1];
        private _intersections = lineIntersectsSurfaces [
            _position vectorAdd [0, 0, 1.5],
            _position vectorDiff [0, 0, 1.5],
            _unit, objNull, true, 1, "GEOM", "FIRE"
        ];

        if !(_intersections isEqualTo []) then {
            (_intersections select 0) params ["_touchingPoint", "_surfaceNormal"];
            _position = _touchingPoint vectorAdd [0, 0, _zOffset];
            _vectorUp = _surfaceNormal;
        };

        private _gsaUnit = _gsa createVehicle [0, 0, 0];
        _gsaUnit setDir _direction;
        _gsaUnit setPosASL _position;
        _gsaUnit setVectorUp _vectorUp;
    }, [_unit, _gsa], 1] call CBA_fnc_waitAndExecute;


    // };
};



acre_gen_SatCom_sys_gsa_fnc_pickUp = {
    params ["_unit", "_gsa"];

    private _radioId = _gsa getVariable ["acre_sys_gsa_connectedRadio", ""];

    if (_radioId != "") then {
        [_unit, _gsa] call acre_sys_gsa_fnc_disconnect;
    };


    private _classname = typeOf _gsa;
    private _item = "";
    private _canDelete = false;

    if (_classname == "ACRE_GEN_SatComItem") then {
        _item = "ACRE_GEN_SatCom";
        if (_unit canAdd _item) then {
            _canDelete = true;
        };
    };

    if (_canDelete) then {

        if (stance _unit == "STAND") then {
            [_unit, "AmovPercMstpSrasWrflDnon_diary"] call ace_common_fnc_doAnimation;
        };

        [{
            params ["_unit", "_item", "_gsa"];

            _unit addItem _item;
            deleteVehicle _gsa;
        }, [_unit, _item, _gsa], 1] call CBA_fnc_waitAndExecute;
    } else {
        [["\a3\Ui_f\data\GUI\Cfg\CommunicationMenu\call_ca.paa"], [localize "STR_acre_sys_gsa_inventoryFull"]] call CBA_fnc_notify;
    };



};
