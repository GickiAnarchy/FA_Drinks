class CfgPatches
{
    class FA_Drinks
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = 
        {
            "DZ_Data",
            "DZ_Scripts"
        };
    };
};

class CfgMods
{
	class FA_Drinks
	{
	    dir = "FA_Drinks";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "FA_Drinks";
		credits = "Code: GickiAnarchy";
		author = "GickiAnarchy";
		version = "1.0";
		type = "mod";
		dependencies[] = {"Game","World"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"FA_Drinks/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"FA_Drinks/scripts/4_World"};
			};
		};
	};
};

class CfgSoundShaders
{
    class Custom_SoundShader_Base
    {
        range = 30;
    };

    class LoudSniffing_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
        	{
        		"FA_Drinks\sounds\human\longsniff.ogg", 
        		1
        	}
        };
        volume = 1;
    };

    class QuietSniffing_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
        	{
        		"FA_Drinks\sounds\human\shortsniff.ogg", 
        		1
        	}
        };
        volume = 1;
    };

    class ScaryLaugh_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "FA_Drinks\sounds\scary\scary_laugh.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class ScaryFootsteps_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "FA_Drinks\sounds\scary\scary_footsteps.ogg", 
                1
            }
        };
        volume = 0.1;
    };

};

class CfgSoundSets
{
    class Custom_SoundSet_Base
    {
        sound3DProcessingType = "character3DProcessingType";
        volumeCurve = "characterAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
    };

    class LoudSniffing_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "LoudSniffing_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 1;
    };

    class QuietSniffing_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "QuietSniffing_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 1;
    };

    class ScaryLaugh_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "ScaryLaugh_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.4;
    };

    class ScaryFootsteps_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "ScaryFootsteps_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.6;
    };

};