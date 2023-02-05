class CfgPatches
{
    class CS_PelicanCase
    {
		units[]=
        {
			"pelican_case"
        };
        requiredAddons[] = {"DZ_Data"};
    };
};
class CfgMods
{
	class CS_PelicanCase
	{	
		dir = "PelicanCase";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "PelicanCase Module";
		author = "CanadianSniper Papa Bert";
		authorID = "2039448058";
		version = "1.0";
		extra = 0;
		
		type = "mod";
		dependencies[]=
		{
			"Game",
			"World"
		};
		
		class defs
		{
			class gameScriptModule
            {
                value = "";
                files[] = {"PelicanCase/Scripts/3_Game"};
			};

            class worldScriptModule
            {
                value = "";
                files[] = {"PelicanCase/Scripts/4_World"};
			};
		};
	};
};

class cfgWeapons
{
	class RifleCore;
	class Rifle_Base : RifleCore
	{
		inventorySlot[]+=
		{
			"Shoulder1"
		};
	};
};

class CfgVehicles
{
	class cs_openable_placeable;	
	class pelican_case : cs_openable_placeable {
		scope = 2;
		storageCategory = 1;
		displayName = "Rifle Case";
		descriptionShort="Holds Items";
		model = "PelicanCase\pelican_case.p3d";
		weight=40000;
		physLayer="item_large";
		simulation="inventoryItem";
		rotationFlags = 1;
		canBeDigged=0;
		itemBehaviour=0;
		itemSize[]={6,6};
		itemsCargoSize[] = {8,8};
		attachments[]=
			{
				"Shoulder1",
				"cs_magazine1",
				"cs_magazine2",
				"cs_magazine3",
				"cs_magazine4"
			};
			

		hiddenSelections[] = {
			"Door1",
			"pelican_bottom"
		};
		hiddenSelectionsTextures[] = {
			"PelicanCase\Tex\blackcamo\black_top.paa",
			"PelicanCase\Tex\blackcamo\black_bottom.paa"
		};
		class Cargo
			{
				itemsCargoSize[] = {0,0};
				openable=0;
				allowOwnedCargoManipulation=1;
			};
		class DamageSystem
			{
				class GlobalHealth
				{
					class Health
					{
						hitpoints=100000000000;
					};
				};
			};
		class GUIInventoryAttachmentsProps
			{
				class magslots
				{
					name="Magazines";
					description="";
					attachmentSlots[]=
					{
						"cs_magazine1",
						"cs_magazine2",
						"cs_magazine3",
						"cs_magazine4"
					};
					icon="hips";
				};
				class rifleslots
				{
					name="Rifle";
					description="";
					attachmentSlots[]=
					{
						"Shoulder1"
					};
					icon="hips";
				};
			};
	};
	class pelican_jungle : pelican_case {
		displayName = "Rilfe Case (Jungle)";
		hiddenSelectionsTextures[] = {
			"PelicanCase\Tex\junglecamo\jungle_top.paa",
			"PelicanCase\Tex\junglecamo\jungle_bottom.paa"
		};
	};
	class pelican_urban : pelican_case {
		displayName = "Rilfe Case (Urban)";
		hiddenSelectionsTextures[] = {
			"PelicanCase\Tex\urbancamo\urban_top.paa",
			"PelicanCase\Tex\urbancamo\urban_bottom.paa"
		};
	};
	class pelican_desert : pelican_case {
		displayName = "Rilfe Case (Desert)";
		hiddenSelectionsTextures[] = {
			"PelicanCase\Tex\desertcamo\desert_top.paa",
			"PelicanCase\Tex\desertcamo\desert_bottom.paa"
		};
	};
	class pelican_wilderness : pelican_case {
		displayName = "Rilfe Case (Wilderness)";
		hiddenSelectionsTextures[] = {
			"PelicanCase\Tex\wildernesscamo\wilderness_top.paa",
			"PelicanCase\Tex\wildernesscamo\wilderness_bottom.paa"
		};
	};
};

class cfgMagazines
{
	class DefaultMagazine;
	class Magazine_Base
	{
		inventorySlot[] = {
			"cs_magazine1",
			"cs_magazine2",
			"cs_magazine3",
			"cs_magazine4"
		};
	};
};

class CfgSlots
{
    class Slot_cs_magazine1
    {
        name="cs_magazine1";
        displayName="cs_magazine1";
        ghostIcon="magazine2";
        selection="cs_magazine1";
    };
    class Slot_cs_magazine2
    {
        name="cs_magazine2";
        displayName="cs_magazine2";
        ghostIcon="magazine2";
        selection="cs_magazine2";
    };
    class Slot_cs_magazine3
    {
        name="cs_magazine3";
        displayName="cs_magazine3";
        ghostIcon="magazine2";
        selection="cs_magazine3";
    };
    class Slot_cs_magazine4
    {
        name="cs_magazine4";
        displayName="cs_magazine4";
        ghostIcon="magazine2";
        selection="cs_magazine4";
    };
	class Slot_Gun1
	{
		name="Shoulder1";
		displayName="Shoulder1";
		ghostIcon="hips";
		selection="Shoulder1";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyShoulder1: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Shoulder1"
		};
		model="\PelicanCase\Proxy\Shoulder1.p3d";
	};
	class Proxycs_magazine1: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"cs_magazine1"
		};
		model="\PelicanCase\Proxy\cs_magazine1.p3d";
	};
	class Proxycs_magazine2: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"cs_magazine2"
		};
		model="\PelicanCase\Proxy\cs_magazine2.p3d";
	};
	class Proxycs_magazine3: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"cs_magazine3"
		};
		model="\PelicanCase\Proxy\cs_magazine3.p3d";
	};
	class Proxycs_magazine4: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"cs_magazine4"
		};
		model="\PelicanCase\Proxy\cs_magazine4.p3d";
	};
};
