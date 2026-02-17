class TerjeConsumableEffects
{	
	const string COLOR_RED = "<color rgba='198,59,64,255'>";
	const string COLOR_YELLOW = "<color rgba='255,215,0,255'>";
	const string COLOR_GREEN = "<color rgba='97,215,124,255'>";
	const string COLOR_BLUE = "<color rgba='0,148,255,255'>";
	const string COLOR_END = "</color>";
	const string NEXT_LINE = "<br/>";
	
	private string TimeValue(float value)
	{
		return COLOR_END + "(" + (int)(value) + " sec)" + NEXT_LINE;
	}
	private string LevelValue(float value)
	{
		return COLOR_END + "(" + (int)(value) + " lvl)" + NEXT_LINE;
	}
	private string HPValue(string sign, float value)
	{
		return sign + (int)(value) + " HP" + COLOR_END + NEXT_LINE;
	}
	private string PercentValue(string sign, float value)
	{
		return sign + (int)(value * 100) + " %" + COLOR_END + NEXT_LINE;
	}
	private string EXPValue(string sign, float value)
	{
		return sign + (int)(value) + " EXP" + COLOR_END + NEXT_LINE;
	}
	private string calValue(string sign, float value)
	{
		return sign + (int)(value) + " cal" + COLOR_END + NEXT_LINE;
	}
	private string mlValue(string sign, float value)
	{
		return sign + (int)(value) + " ml" + COLOR_END + NEXT_LINE;
	}
	private string NoValue()
	{
		return COLOR_END + NEXT_LINE;
	}
	
	void TerjeSkillModification(int inLevel, string perkName, out int outLevel)
	{
		outLevel = inLevel;
		if (player.GetTerjeSkills())
		{
			if (inLevel < 3 && player.GetTerjeSkills().GetPerkLevel("med", perkName) > 0)
			{
				outLevel += 1;
			}
		}
	}
	
	int TerjeGetMaxTimeSec(string classname, string configname)
	{
		int MaxTimeSec = GetTerjeGameConfig().ConfigGetInt( classname + " " + configname + "MaxTimeSec" )
		if ( MaxTimeSec <= 0) return 1800;
		
		return MaxTimeSec;
	}
	
	float TerjeGetActiveTimeSec(float activeTime, float activeTimeSec, float amount, float perkPharmacMod)
	{
		return activeTime + (activeTimeSec * amount * perkPharmacMod);
	}
	
	void Apply(EntityAI entity, string classname, PlayerBase player, float amount)
	{
		PlayerBase operator = null;
		if (entity)
		{
			operator = PlayerBase.Cast(entity.GetHierarchyRootPlayer());
		}
		
		array<ref TerjeSkillCfg> skills();
		GetTerjeSkillsRegistry().GetSkills(skills);
		foreach (ref TerjeSkillCfg skill : skills)
		{
			float skillIncrement;
			if (operator && operator.GetTerjeSkills())
			{
				skillIncrement = GetTerjeGameConfig().ConfigGetFloat( classname + " " + skill.GetId() + "SkillExpAddToSelf" );
				if (skillIncrement >= 1)
				{
					operator.GetTerjeSkills().AddSkillExperience(skill.GetId(), (int)skillIncrement);
				}
			}
			
			if (player && player.GetTerjeSkills())
			{
				skillIncrement = GetTerjeGameConfig().ConfigGetFloat( classname + " " + skill.GetId() + "SkillExpAddToTarget" );
				if (skillIncrement >= 1)
				{
					player.GetTerjeSkills().AddSkillExperience(skill.GetId(), (int)skillIncrement);
				}
			}
		}

		if (player)
		{
			float perkPharmacMod = 1.0;
			if (player.GetTerjeSkills())
			{
				float perkPharmac;
				if (player.GetTerjeSkills().GetPerkValue("med", "pharmac", perkPharmac))
				{
					perkPharmacMod += perkPharmac;
				}
			}
			TerjeApplyVanillaEffects(classname, player, amount);
			TerjeApplyPositiveEffects(classname, player, amount, perkPharmacMod);
			TerjeApplyVacineEffects(classname, player, amount, perkPharmacMod);
			TerjeApplyNegativeEffects(classname, player, amount);
		}
	}
	
	void TerjeApplyVanillaEffects(string classname, PlayerBase player, float amount)
	{
		float effectValue;
		
		effectValue = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddHealth" );
		if (effectValue != 0)
		{
			if (effectValue > 0) player.GetTerjeHealth().AddHealth(effectValue * amount);
			else player.GetTerjeHealth().DecreaseHealth(effectValue * amount * -1, TerjeDamageSource.CONSUMABLE_EFFECT);
		}
		
		effectValue = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddBlood" );
		if (effectValue != 0)
		{
			if (effectValue > 0) player.GetTerjeHealth().AddBlood(effectValue * amount);
			else player.GetTerjeHealth().DecreaseBlood(effectValue * amount * -1, TerjeDamageSource.CONSUMABLE_EFFECT);
		}
		
		effectValue = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddShock" );
		if (effectValue != 0)
		{
			if (effectValue > 0) player.GetTerjeHealth().AddShock(effectValue * amount);
			else player.GetTerjeHealth().DecreaseShock(effectValue * amount * -1, TerjeDamageSource.CONSUMABLE_EFFECT);
		}
		
		effectValue = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddWater" );
		if (effectValue != 0) player.GetStatWater().Add(effectValue * amount);
		
		effectValue = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddEnergy" );
		if (effectValue != 0) player.GetStatEnergy().Add(effectValue * amount);
	}
	
	void TerjeApplyPositiveEffects(string classname, PlayerBase player, float amount, float perkPharmacMod)
	{
		
	}
	
	void TerjeApplyVacineEffects(string classname, PlayerBase player, float amount, float perkPharmacMod)
	{
		
	}
	
	void TerjeApplyNegativeEffects(string classname, PlayerBase player, float amount)
	{
		
	}
	
	string Describe(EntityAI entity, string classname)
	{
		string result = "";
		ItemBase item = ItemBase.Cast(entity);
		
		array<ref TerjeSkillCfg> skills();
		GetTerjeSkillsRegistry().GetSkills(skills);
		foreach (ref TerjeSkillCfg skill : skills)
		{
			float skillIncrement = GetTerjeGameConfig().ConfigGetFloat( classname + " " + skill.GetId() + "SkillIncrement" );
			if (skillIncrement >= 1)
			{
				result += skill.GetDisplayName() + " " + COLOR_BLUE + EXPValue("+", skillIncrement);
			}
		}
		
		float healthDmg = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddHealth" );
		if (healthDmg > 0)
		{
			result += "#STR_TERJECORE_EFFECT_HEALTH " + COLOR_GREEN + HPValue("+", healthDmg);
		}
		else if (healthDmg < 0)
		{
			result += "#STR_TERJECORE_EFFECT_HEALTH " + COLOR_RED + HPValue("-", healthDmg);
		}
		
		float bloodDmg = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddBlood" );
		if (bloodDmg > 0)
		{
			result += "#STR_TERJECORE_EFFECT_BLOOD " + COLOR_GREEN + HPValue("+", bloodDmg);
		}
		else if (bloodDmg < 0)
		{
			result += "#STR_TERJECORE_EFFECT_BLOOD " + COLOR_RED + HPValue("-", bloodDmg);
		}
		
		float shockDmg = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddShock" );
		if (shockDmg > 0)
		{
			result += "#STR_TERJECORE_EFFECT_SHOCK " + COLOR_GREEN + HPValue("+", shockDmg);
		}
		else if (shockDmg < 0)
		{
			result += "#STR_TERJECORE_EFFECT_SHOCK " + COLOR_RED + HPValue("-", shockDmg);
		}
		
		float nutritionEnergy = GetTerjeGameConfig().ConfigGetFloat( classname + " Nutrition energy" );
		if (nutritionEnergy == 0 && item != null && item.GetFoodStage())
		{
			nutritionEnergy = FoodStage.GetEnergy(item.GetFoodStage());
		}
		
		if (nutritionEnergy == 0)
		{
			nutritionEnergy = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddEnergy" );
		}
		
		if (nutritionEnergy > 0)
		{
			result += "#STR_TERJECORE_EFFECT_ENERGY " + COLOR_GREEN + calValue("+", nutritionEnergy);
		}
		else if (nutritionEnergy < 0)
		{
			result += "#STR_TERJECORE_EFFECT_ENERGY " + COLOR_RED + calValue("-", nutritionEnergy);
		}
		
		float nutritionWater = GetTerjeGameConfig().ConfigGetFloat( classname + " Nutrition water" );
		if (nutritionWater == 0 && item != null && item.GetFoodStage())
		{
			nutritionWater = FoodStage.GetWater(item.GetFoodStage());
		}
		
		if (nutritionWater == 0)
		{
			nutritionWater = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddWater" );
		}
		
		if (nutritionWater > 0)
		{
			result += "#STR_TERJECORE_EFFECT_WATER " + COLOR_GREEN + mlValue("+", nutritionWater);
		}
		else if (nutritionWater < 0)
		{
			result += "#STR_TERJECORE_EFFECT_WATER " + COLOR_RED + mlValue("-", nutritionWater);
		}
		
		return result;
	}
}
