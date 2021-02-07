modded class ItemBase
{
	vector Get_ItemPlacingPos()
	{
		return "0 0 0";
	}

	vector Get_ItemPlacingOrientation()
	{
		return "0 0 0";
	}

	bool IsInvEmpty()
	{   
		if (GetNumberOfItems() < 1 &&  GetInventory().AttachmentCount() < 1)
		{
			return true;
		}
		return false;
	}
};