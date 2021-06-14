class CfgPatches
{
	class _data
	{
		units[] =
		{
			"WarpedWaters", "BlurSoda", "CompletelyPoison", "Drink_Base"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data", "DZ_Gear"
		};
	};
};

class CfgSlots
{
};

class CfgVehicles
{
	class ItemBase;
	class Edible_Base;
	class SodaCan_ColorBase: Edible_Base{};
	class Bottle_Base: Edible_Base{};

	//	//	//	//	//	//	//
	//		B A S E S 		//
	//	//	//	//	//	//	//
	class Drink_Base: Bottle_Base
	{
		scope = 2;
		model="\dz\gear\drinks\SodaCan.p3d";
		hiddenSelectionsTextures[] =
		{
			"\FA_Drinks\data\EmptyCan_co.paa"
		};
		stackedRandom=0;
		itemSize[]={1,2};
		weight=10;
		stackedUnit="";
		varQuantityInit=300;
		varQuantityMin=0;
		varQuantityMax=300;
		hiddenSelections[]=
		{
			"camoGround"
		};
		class Nutrition
		{
			totalVolume=1;
			energy=00;
			water=150;
			nutritionalIndex=1;
			toxicity=0;
		};
	};

	class Mix_Base: ItemBase
	{
		scope = 0;
	};

	//	//	//	//	//	//	//
	//		D R I N K S		//
	//	//	//	//	//	//	//
	class BlurSoda: Drink_Base
	{
		hiddenSelections[]=
		{
			"camoGround"
		};
		hiddenSelectionsTextures[] =
		{
			"\FA_Drinks\data\BlurSoda_co.paa"
		};
	};

	class CompletelyPoison: Drink_Base
	{
		hiddenSelections[]=
		{
			"camoGround"
		};
		hiddenSelectionsTextures[] =
		{
			"\FA_Drinks\data\CompletelyPoison_co.paa"
		};
	};

	class WarpedWaters: Drink_Base
	{
		hiddenSelections[]=
		{
			"camoGround"
		};
		hiddenSelectionsTextures[] =
		{
			"\FA_Drinks\data\WarpedWaters_co.paa"
		};
	};


};

class CfgnonAIVehicles
{
};
