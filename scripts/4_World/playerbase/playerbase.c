modded class PlayerBase extends ManBase
{

    const string SNIFF_LOUD     = "LoudSniffing_SoundSet";
    const string SNIFF_SHORT    = "QuietSniffing_SoundSet";

    EffectSound fa_Sniff;

//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
//      Visual Effects
//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
	void DrinkEffectsTriggered() {
		if(GetGame().IsClient())
		{
			CameraEffects.changeRadBlurXEffect(29);
			CameraEffects.changeRadBlurYEffect(44);
			CameraEffects.changeVignette(55);
			CameraEffects.changeHue(38);
	  	}
		
		PlaySoundSet(fa_Sniff, SNIFF_LOUD, 0.0, 0.0);

        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DrinkEffectsTriggeredOff, 160*1000, false);
	};


    void DrinkEffectsTriggeredOff()
    {
        if(GetGame().IsClient())
        {
			CameraEffects.ResetSome();
        }
		
	  PlaySoundSet(fa_Sniff, SNIFF_SHORT, 0.0, 0.0);	
    };

}