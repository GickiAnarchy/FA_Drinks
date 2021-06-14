class ActionDrinkMixed: ActionSingleUseBase
{

    PlayerBase player;

	void ActionDrinkMixed()
	{
		
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "#Consume";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		
		PlayerBase player = action_data.m_Player;
		player.DrinkEffectsTriggered();	
		Drink_Base drink = Drink_Base.Cast(item);
		if (drink.GetNumberOfMixers() > 0)
		{
			return true;
		} else {
			return false;
		}
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Drink_Base drink = Drink_Base.Cast(action_data.m_MainItem);
		if (drink) 
		{
		 	drink.MakeHigh(action_data.m_Player);
		}
		
	}
	


	override void OnEndServer( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		ItemBase item = ItemBase.Cast(action_data.m_MainItem);
		
		if (action_data.m_WasExecuted && item )
		{
           		if (item.HasQuantity())
			{
				item.AddQuantity(-1,true);
			} else
			{
				item.Delete();
			}
		}
	}


	override void OnExecuteClient(ActionData action_data)
    {	
    	PlayerBase player = action_data.m_Player;
		player.DrinkEffectsTriggered();	
	}
};
