class cs_openable : Container_Base
{
	protected ref OpenableBehaviour m_Openable;
	
	void cs_openable()
	{
		m_Openable = new OpenableBehaviour(false);
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	
	override void EEInit()
	{
		super.EEInit();
        GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);  
	}

	override void Open()
	{
		m_Openable.Open();
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override void Close()
	{
		m_Openable.Close();
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}

	void UpdateVisualState()
    {
        if ( IsOpen() )
        {
            SetAnimationPhase("Door1",1);
        }
        else
        {
            SetAnimationPhase("Door1",0);
        }
    }

    override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }
    override bool CanPutIntoHands( EntityAI parent )
    {
        return false;
    }
	override bool CanReceiveItemIntoCargo(EntityAI cargo)
	{
		return IsOpen();
	}
	
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}

	override bool CanDisplayAttachmentSlot(string slot_name)
	{		
		return true;
	}

	override void SetActions()
	{
		super.SetActions();
        AddAction(ActionCloseRifleCase);
        AddAction(ActionOpenRifleCase);
	}
};

class cs_openable_placeable: cs_openable
{   
	override bool CanPutInCargo( EntityAI parent )
    {
        return !IsOpen();
    }
    
     override bool CanPutIntoHands(EntityAI parent)
	{
		return !IsOpen();
    }

    override bool IsDeployable() 
    {
        return true;
    } 
    
    override void OnInventoryEnter(Man player)
    {
        super.OnInventoryEnter(player);
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);        
    }
    
    override void OnInventoryExit(Man player)
    {
        super.OnInventoryExit(player);
        if(IsOpen())
            GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);        
    }

    override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};