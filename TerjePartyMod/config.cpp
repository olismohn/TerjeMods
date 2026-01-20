class CfgPatches
{
    class TerjePartyMod
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "JM_CF_Scripts"
        };
    };
};

class CfgMods
{
    class TerjePartyMod
    {
        dir = "TerjePartyMod";
        picture = "";
        action = "";
        hideName = 0;
        hidePicture = 1;
        name = "Terje Party Mod";
        credits = "Terje Bruoygard";
        version = "1.0.0";
        author = "TerjeBruoygard";
        extra = 0;
        type = "mod";
        
        class defs
        {
            class worldScriptModule {
                value = "";
                files[] = {"TerjePartyMod/Scripts/4_World"};
            };

            class missionScriptModule {
                value = "";
                files[] = {"TerjePartyMod/Scripts/5_Mission"};
            };
        };
    };
};