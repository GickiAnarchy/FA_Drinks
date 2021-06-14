class Drink_Base extends Bottle_Base
{
    //
    //
  
    
    
    //
    //Constructor
    void Drink_Base()
    {
        
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


class BlurSoda: Drink_Base{};
class CompletelyPoison: Drink_Base{};
class WarpedWaters: Drink_Base{};