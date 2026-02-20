class TerjeConsumableEffects
{	
	const string COLOR_RED = "<color rgba='198,59,64,255'>";
	const string COLOR_YELLOW = "<color rgba='255,215,0,255'>";
	const string COLOR_GREEN = "<color rgba='97,215,124,255'>";
	const string COLOR_BLUE = "<color rgba='0,148,255,255'>";
	const string COLOR_END = "</color>";
	const string NEXT_LINE = "<br/>";
	
	void TerjeSkillModification(int inLevel, PlayerBase player, string perkName, out int outLevel)
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
		int medMaxTimeSec = GetTerjeGameConfig().ConfigGetInt( classname + " med" + configname + "MaxTimeSec" );
		if ( medMaxTimeSec <= 0) return 1800;
		
		return medMaxTimeSec;
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
	
	void TerjeApplyNegativeEffects(string classname, PlayerBase player, float amount)
	{
		
	}
	
	string Describe(EntityAI entity, string classname)
	{
		string result = "";
		
		array<ref TerjeSkillCfg> skills();
		GetTerjeSkillsRegistry().GetSkills(skills);
		foreach (ref TerjeSkillCfg skill : skills)
		{
			float skillIncrement = GetTerjeGameConfig().ConfigGetFloat( classname + " " + skill.GetId() + "SkillIncrement" );
			if (skillIncrement != 0)
			{
				result += skill.GetDisplayName() + " " + StatValue(skillIncrement, "EXP");
			}
		}
		if (TerjeDescribePositiveEffects(classname) != "")
		{
			if (result != "") result += NEXT_LINE;
			
			result += "<b>" + COLOR_GREEN + "#STR_TERJECORE_EFFECT_POSITIVE" + COLOR_END + "</b>" + NEXT_LINE;
			result += TerjeDescribePositiveEffects(classname);
		}
		if (TerjeDescribeNegativeEffects(classname) != "")
		{
			if (result != "") result += NEXT_LINE;
			
			result += "<b>" + COLOR_YELLOW + "#STR_TERJECORE_EFFECT_NEGATIVE" + COLOR_END + "</b>" + NEXT_LINE;
			result += TerjeDescribeNegativeEffects(classname);
		}
		if (TerjeDescribeVanillaEffects(entity, classname) != "")
		{
			if (result != "") result += NEXT_LINE;
			
			result += TerjeDescribeVanillaEffects(entity, classname);
		}
		
		return result;
	}
	
	private string TerjeDescribeVanillaEffects(EntityAI entity, string classname)
	{
		string result = "";
		ItemBase item = ItemBase.Cast(entity);
		float vanillaStat;
		
		vanillaStat = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddHealth" );
		if (vanillaStat != 0)
		{
			result += StatValue(vanillaStat, "#STR_TERJECORE_EFFECT_HEALTH");
		}
		
		vanillaStat = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddBlood" );
		if (vanillaStat != 0)
		{
			result += StatValue(vanillaStat, "#STR_TERJECORE_EFFECT_BLOOD");
		}
		
		vanillaStat = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddShock" );
		if (vanillaStat != 0)
		{
			result += StatValue(vanillaStat, "#STR_TERJECORE_EFFECT_SHOCK");
		}
		
		vanillaStat = GetTerjeGameConfig().ConfigGetFloat( classname + " Nutrition energy" );
		if (vanillaStat == 0 && item != null && item.GetFoodStage())
		{
			vanillaStat = FoodStage.GetEnergy(item.GetFoodStage());
		}
		if (vanillaStat == 0)
		{
			vanillaStat = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddEnergy" );
		}
		if (vanillaStat != 0)
		{
			result += "#STR_TERJECORE_EFFECT_ENERGY " + StatValue(vanillaStat, "cal");
		}
		
		vanillaStat = GetTerjeGameConfig().ConfigGetFloat( classname + " Nutrition water" );
		if (vanillaStat == 0 && item != null && item.GetFoodStage())
		{
			vanillaStat = FoodStage.GetWater(item.GetFoodStage());
		}
		if (vanillaStat == 0)
		{
			vanillaStat = GetTerjeGameConfig().ConfigGetFloat( classname + " terjeAddWater" );
		}
		if (vanillaStat != 0)
		{
			result += "#STR_TERJECORE_EFFECT_WATER " + StatValue(vanillaStat, "ml");
		}
		
		return result;
	}
	
	private string TerjeDescribePositiveEffects(string classname)
	{
		string result = "";
		return result;
	}
	
	private string TerjeDescribeNegativeEffects(string classname)
	{
		string result = "";
		return result;
	}
	
	private string TerjeGetEffectString_Level(string medication, string effect, string classname)
	{
		int medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " med" + medication + "Level" );
		float medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " med" + medication + "TimeSec" );
		if (medLevel > 0 && medTimeSec > 0)
		{
			return "   " + LevelValue(medLevel, 0) + effect + " " + TimeValue(medTimeSec);
		}
		
		return "";
	}
	
	private string TerjeGetEffectString_DamageLevel(string medication, string effect, string classname)
	{
		int medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " med" + medication + "Set" );
		if (medLevel > 0)
		{
			return "   " + LevelValue(medLevel, 1) + effect + " " + NEXT_LINE;
		}
		
		return "";
	}
	
	private string TerjeGetEffectString_Time(string medication, string effect, string classname)
	{
		float medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " med" + medication + "TimeSec" );
		if (medTimeSec > 0)
		{
			if (medication == "ImmunityGain") 
			{
				float medValue = GetTerjeGameConfig().ConfigGetInt( classname + " med" + medication + "Value" );
				TerjeLog_Info("medImmunityGainValue=" + medValue + "; medImmunityGainTimeSec=" + medTimeSec);
			}
			return "   " + effect + " " + TimeValue(medTimeSec);
		}
		
		return "";
	}
	
	private string TerjeGetEffectString_DamageTime(string medication, string effect, string classname)
	{
		float medTimeSec = GetTerjeGameConfig().ConfigGetFloat(classname + " med" + medication + "DamageTimeSec");
		if (medTimeSec > 0)
		{
			return "   " + effect + " " + TimeValue(medTimeSec);
		}
		
		return "";
	}
	
	private string TerjeGetEffectString_Increment(string medication, string effect, string classname)
	{
		float medValue = GetTerjeGameConfig().ConfigGetFloat(classname + " med" + medication + "Increment");
		if (medValue > 0)
		{
			return "   " + effect + " " + NEXT_LINE;
		}
		
		return "";
	}
	
	private string TerjeGetEffectString_Percent(string medication, string effect, string classname)
	{
		float medValue = GetTerjeGameConfig().ConfigGetFloat(classname + " " + medication + "Increment");
		if (medValue > 0)
		{
			return "   " + PercentValue(medValue, 1) + effect + " " + NEXT_LINE;
		}
		
		return "";
	}
	
	private string TerjeGetEffectString_Contussion(string medication, string effect, string classname)
	{
		float medValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medContussion" + medication);
		if (medValue > 0)
		{
			return "   " + effect + " " + NEXT_LINE;
		}
		
		return "";
	}
	
	private string TimeValue(float value)
	{
		return "(" + (int)(value) + " sec)" + NEXT_LINE;
	}
	
	private string LevelValue(float value, bool badEffect)
	{
		string color = COLOR_GREEN;
		if (badEffect)
		{
			color = COLOR_RED;
		}
		return "#STR_TERJECORE_EFFECT_LEVEL_0 " + color + (int)(value) + COLOR_END + "#STR_TERJECORE_EFFECT_LEVEL_1 ";
	}
	
	private string PercentValue(float value, bool badEffect)
	{
		string sign = "-";
		string color = COLOR_GREEN;
		if (badEffect)
		{
			sign = "+";
			color = COLOR_RED;
		}
		return color + sign + (int)(value * 100) + " %" + COLOR_END + " ";
	}
	
	private string StatValue(float value, string stat)
	{
		string sign = "";
		string color = COLOR_RED;
		if (value > 0 )
		{
			sign = "+";
			if (stat == "EXP") color = COLOR_BLUE;
			else color = COLOR_GREEN;
		}
		return color + sign + (int)(value) + COLOR_END + " " + stat + NEXT_LINE;
	}
}
