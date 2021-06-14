/* class ActionDrinkMixed: ActionSingleUseBase
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
		return true;
	}

	override void OnExecuteServer( ActionData action_data )
	{
			
	}
	
	override void OnExecuteClient(ActionData action_data)
    {	
    	
	}

	override void OnEndServer( ActionData action_data )
	{
		
	}

};
 */