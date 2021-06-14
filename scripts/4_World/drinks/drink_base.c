class Drink_Base extends Bottle_Base
{
    protected bool alreadyMixed = false;


    //
    //Constructor
    void Drink_Base()
    {
        
    };
    
    //  alreadyMixed encapulation
    void SetAlreadyMixed(bool setter)
    {
        alreadyMixed = setter;
    };

    bool GetAlreadyMixed()
    {
        bool ret = alreadyMixed;
        return ret;
    };
   
    
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
    //  
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
    //Makes the player high on vanilla morphine.
    void MakeHigh(PlayerBase player)
	{
		if( player.GetModifiersManager().IsModifierActive(eModifiers.MDF_MORPHINE ) )//effectively resets the timer
		{
			player.GetModifiersManager().DeactivateModifier( eModifiers.MDF_MORPHINE, false );
		}
		player.GetModifiersManager().ActivateModifier( eModifiers.MDF_MORPHINE );
	}
    
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
    //  
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
    override void OnConsume(float amount, PlayerBase consumer)
    {
        super.OnConsume(amount, consumer);
        if (this.GetType() == "BlurSoda")
        {
            consumer.BlurSodaEffectsTriggered();
        }
        MakeHigh(consumer);
    };

    //overridden SetActions function
    override void SetActions()
	{
		super.SetActions();
		//AddAction(ActionDrinkMixed);
	};


};


