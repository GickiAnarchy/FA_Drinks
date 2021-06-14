class MixersManager 
{   
    //
    //
    static const int MAX_DRINK_MIXERS = 4;

    Drink_Base drink;
    protected ref TClassArray mixersArray;
    
    //
    //
    void MixersManager(Drink_Base drinkbase)
    {
        drink = Drink_Base.Cast(drinkbase);
        mixersArray  = new TClassArray;
    }

    
    //Returns the Drink_Base this class is managing
    Drink_Base GetManagedDrink()
    {
        if (!drink)
        {
            return null:
        }
        return drink;
    }

    //Returns the  number of Mixers in the List/In the drink.
    int GetActiveMixerCount()
    {
        return mixersArray.Count();
    }

    //Function to handle adding a mixer to the manager => to the drink
    static bool AddMixerToDrink(Mix_Base addmix)
    {
        if (GetActiveMixerCount() >= MAX_DRINK_MIXERS)
        {
            return false;
        }
        mixersArray.Insert(addmix);
        Print("Added " + addmix.GetName() + " to mixers manager");
		return true;
        
    }


};

