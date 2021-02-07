modded class Hologram
{
	override void UpdateHologram( float timeslice )
	{
		super.UpdateHologram(timeslice);
		ItemBase container = m_Parent;
		if(container){
			vector containerPos = GetProjectionEntityPosition( m_Player ) + container.Get_ItemPlacingPos();
			vector containerOrientation = AlignProjectionOnTerrain( timeslice ) + container.Get_ItemPlacingOrientation();
			SetProjectionPosition( containerPos );
			SetProjectionOrientation( containerOrientation );		
			m_Projection.OnHologramBeingPlaced( m_Player );
			return;
		}
	}
	
	EntityAI PlaceEntity( EntityAI entity_for_placing )
	{	
		return super.PlaceEntity(entity_for_placing);
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{			
		ItemBase item_in_hands = m_Parent;

		if (item_in_hands.IsInherited(cs_openable_placeable))
		{
			SetIsColliding(false);
			return;
		}
		super.EvaluateCollision();
	}

		
	override void RefreshVisual()
	{
			super.RefreshVisual();
	}

	override bool IsFloating() 
	{
		if (m_Parent.IsInherited(cs_openable_placeable))
		{
			return true;
		}
		
		return super.IsFloating();
	}

	override void SetProjectionPosition( vector position )
	{	
		if (m_Parent.IsInherited(cs_openable_placeable) && IsFloating())
		{ 
			vector itemPos = SetOnGround( position ) + m_Parent.Get_ItemPlacingPos();
			m_Projection.SetPosition( itemPos );
			return;
		}

		super.SetProjectionPosition(position);
	}
};