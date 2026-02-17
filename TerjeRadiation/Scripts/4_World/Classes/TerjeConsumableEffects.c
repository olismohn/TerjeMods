modded class TerjeConsumableEffects
{
	override void TerjeApplyPositiveEffects(string classname, PlayerBase player, float amount, float perkPharmacMod)
	{
		super.TerjeApplyPositiveEffects(classname, player, amount, perkPharmacMod);
		
		int medLevel;
		float medValue;
		float medTimeSec;
		
		int medActiveLevel;
		float medActiveValue;
		float medActiveTimeSec;
		
		int MaxTimeSec;
		float ActiveTimeSec;
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medAntiradLevel" );
		if (medLevel > 0)
		{
			medActiveLevel = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetAntirad(medActiveLevel, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntiradTimer" );
			if (medLevel >= medActiveLevel && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medAntirad");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetAntirad(medLevel, Math.Min(MaxTimeSec, ActiveTimeSec));
			}
		}
	}
	
	override void TerjeApplyNegativeEffects(string classname, PlayerBase player, float amount)
	{
		super.TerjeApplyNegativeEffects(classname, player, amount);
		
		float medDmgValue;
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medRadiationIncrement" );
		if (medDmgValue != 0)
		{
			player.GetTerjeStats().SetRadiationValue(player.GetTerjeStats().GetRadiationValue() + (medDmgValue * amount));
		}
	}
	
	override string Describe(EntityAI entity, string classname)
	{
		string result = super.Describe(entity, classname);
		int medLevel;
		float medValue;
		float medTimeSec;
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntiradTimer" );
		medValue = GetTerjeGameConfig().ConfigGetInt( classname + " medAntiradLevel" );
		if (medValue > 0 && medTimeSec > 0)
		{
			result += "#STR_TERJERAD_EFFECT_RADPROTECT " + COLOR_GREEN + medValue + TimeValue(medTimeSec);			
		}
		
		float medDmgValue;
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medRadiationIncrement" );
		if (medDmgValue > 0)
		{
			result += "#STR_TERJERAD_EFFECT_RADIATION " + COLOR_GREEN + PercentValue("-", medDmgValue);
		}
		else if (medDmgValue < 0)
		{
			result += "#STR_TERJERAD_EFFECT_RADIATION " + COLOR_RED + PercentValue("+", medDmgValue);
		}
		
		return result;
	}
}
