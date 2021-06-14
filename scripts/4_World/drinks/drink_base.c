class Drink_Base extends Bottle_Base
{
    //
    //
    protected bool isFullyMixed;
    protected ref MixersManager mixers_manager;
    
    
    //
    //Constructor
    void Drink_Base()
    {
        mixers_manager = new MixersManager(this);
    };
    
    
    
    //
    //Sets whether or not this drink cant mix anymore.
    void SetisFullyMixed(bool setter)
    {
        isFullyMixed = setter;
    };
    
    //Returns true if drink is full.
    bool GetisFullyMixed()
    {
        return isFullyMixed;
    };
    
    //Returns the Manager between Mixer and Drink 
    MixersManager GetMixersManager()
    {
        return mixers_manager;
    };
    
    //Returns int amount of Mixers added to the drink.
    int GetNumberOfMixers()
    {
        int ret = mixers_manager.GetActiveMixerCount();
        return ret;
    };

    /*
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
    //  
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
    */
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
    };

    //overridden SetActions function
    override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDrinkMixed);
	};


};


class BlurSoda extends Drink_Base{};
class CompletelyPoison extends Drink_Base{};
class WarpedWaters extends Drink_Base{};