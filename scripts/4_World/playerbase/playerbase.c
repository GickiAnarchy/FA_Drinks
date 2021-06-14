modded class PlayerBase extends ManBase
{
    //  //  //  //  //  //  //  //  //  //  //  //  
    //Mixers                                    //
    //  //  //  //  //  //  //  //  //  //  //  //

    //the amount of high the player will consume.
    //  x1 = <=25
    //  x2 = <=50 
    //  x3 = <=75
    //  x4 = <=100
    int highAmount;
	



    const string SNIFF_LOUD     = "LoudSniffing_SoundSet";
    const string SNIFF_SHORT    = "QuietSniffing_SoundSet";

    EffectSound fa_Sniff;


	void DrinkEffectsTriggered() {
		if(GetGame().IsClient())
		{
			CameraEffects.changeRadBlurXEffect(29);
			CameraEffects.changeRadBlurYEffect(44);
			CameraEffects.changeVignette(55);
			CameraEffects.changeHue(38);
	  	}
		
		PlaySoundSet(fa_Sniff, SNIFF_LOUD, 0.0, 0.0);
		
		//NEED TO LOOK AT IN WORKBENCH
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DrinkEffectsTriggeredOff, 160*1000, false);
	}

    void DrinkEffectsTriggeredOff()
    {
        if(GetGame().IsClient())
        {
			CameraEffects.ResetSome();
        }
		
	  PlaySoundSet(fa_Sniff, SNIFF_SHORT, 0.0, 0.0);	
    }



}