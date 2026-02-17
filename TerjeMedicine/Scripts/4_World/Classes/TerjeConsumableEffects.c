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
		
		//----------- Levels
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medPainkillerLevel" );
		if (medLevel > 0)
		{
			TerjeSkillModification(medLevel, "anestlog", out medLevel);
			
			medActiveLevel = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetPainkiller(medActiveLevel, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medPainkillerTimeSec" );
			if (medLevel >= medActiveLevel && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medPainkiller");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetPainkiller(medLevel, Math.Min(MaxTimeSec, ActiveTimeSec));
			}
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medAntibioticLevel" );
		if (medLevel > 0)
		{
			TerjeSkillModification(medLevel, "expantib", out medLevel);
			
			medActiveLevel = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetAntibiotic(medActiveLevel, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntibioticsTimeSec" );
			if (medLevel >= medActiveLevel && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medAntibiotics");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetAntibiotic(medLevel, Math.Min(MaxTimeSec, ActiveTimeSec));
			}
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medRabiesAntibioticLevel" );
		if (medLevel > 0)
		{
			TerjeSkillModification(medLevel, "expantib", out medLevel);
			
			medActiveLevel = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetRabiesCure(medActiveLevel, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medRabiesAntibioticTimeSec" );
			if (medLevel >= medActiveLevel && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medRabiesAntibiotic");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetRabiesCure(medLevel, Math.Min(MaxTimeSec, ActiveTimeSec));
			}
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medAntipoisonLevel" );
		if (medLevel > 0)
		{
			medActiveLevel = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetAntipoison(medActiveLevel, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntipoisonTimeSec" );
			if (medLevel >= medActiveLevel && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medAntipoison");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetAntipoison(medLevel, Math.Min(MaxTimeSec, ActiveTimeSec));
			}
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medAntibiohazardLevel" );
		if (medLevel > 0)
		{
			medActiveLevel = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetAntibiohazard(medActiveLevel, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntibiohazardTimeSec" );
			if (medLevel >= medActiveLevel && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medAntibiohazard");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetAntibiohazard(medLevel, Math.Min(MaxTimeSec, ActiveTimeSec));
			}
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medAntidepresantLevel" );
		if (medLevel > 0)
		{
			medActiveLevel = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetAntidepresant(medActiveLevel, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntidepresantTimer" );
			if (medLevel >= medActiveLevel && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medAntidepresant");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetAntidepresant(medLevel, Math.Min(MaxTimeSec, ActiveTimeSec));
			}
		}
		
		//----------- Values
		medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medBloodHemostaticValue" );
		if (medValue > 0)
		{
			medActiveLevel = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetHemostatic(medActiveLevel, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medBloodHemostaticTimeSec" );
			if (medValue >= medActiveLevel && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medBloodHemostatic");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetHemostatic(medValue, Math.Min(MaxTimeSec, ActiveTimeSec));
			}
		}
		
		medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medBloodRegenValue" );
		if (medValue > 0)
		{
			medActiveLevel = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetBloodRegen(medActiveLevel, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medBloodRegenTimeSec" );
			if (medValue >= medActiveLevel && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medBloodRegen");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetBloodRegen(medValue, Math.Min(MaxTimeSec, ActiveTimeSec));
			}	
		}
		
		medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medImmunityGainForce" );
		if (medValue > 0)
		{
			medActiveValue = 0;
			medActiveTimeSec = 0;
			player.GetTerjeStats().GetImmunityGainValue(medActiveValue, medActiveTimeSec);
			
			medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medImmunityGainTimeSec" );
			if (medValue >= medActiveValue && medTimeSec > 0)
			{
				MaxTimeSec = TerjeGetMaxTimeSec(classname, "medImmunityGain");
				ActiveTimeSec = TerjeGetActiveTimeSec(medActiveTimeSec, medTimeSec, amount, perkPharmacMod);
				player.GetTerjeStats().SetImmunityGainValue(medValue, Math.Min(MaxTimeSec, ActiveTimeSec));
			}
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medMindDegradationTime" );
		if (medTimeSec > 0)
		{
			medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medMindDegradationForce" );
			if (medValue > 0)
			{
				player.GetTerjeStats().AddMindDegradation(medValue, medTimeSec * amount);
			}
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medSleepingIncrementTimeSec" );
		if (medTimeSec > 0)
		{
			medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medSleepingIncrementValue" );
			if (medValue > 0)
			{
				player.GetTerjeStats().AddSleepingIncrement(medValue, medTimeSec * amount);
			}
			else if (medValue < 0)
			{
				player.GetTerjeStats().AddSleepingDecrement(Math.AbsFloat(medValue), medTimeSec * amount);
			}
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medHealthgainTimeSec" );
		if (medTimeSec > 0)
		{
			MaxTimeSec = TerjeGetMaxTimeSec(classname, "medHealthgain");
			ActiveTimeSec = TerjeGetActiveTimeSec(player.GetTerjeStats().GetHealthExtraRegenTimer(), medTimeSec, amount, perkPharmacMod);
			player.GetTerjeStats().SetHealthExtraRegenTimer(Math.Min(MaxTimeSec, ActiveTimeSec));
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medZAntidotTimeSec" );
		if (medTimeSec > 0)
		{
			MaxTimeSec = TerjeGetMaxTimeSec(classname, "medZAntidot");
			ActiveTimeSec = TerjeGetActiveTimeSec(player.GetTerjeStats().GetZAntidotValue(), medTimeSec, amount, perkPharmacMod);
			player.GetTerjeStats().SetZAntidotValue(Math.Min(MaxTimeSec, ActiveTimeSec));
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntisepsisTimeSec" );
		if (medTimeSec > 0)
		{
			MaxTimeSec = TerjeGetMaxTimeSec(classname, "medAntisepsis");
			ActiveTimeSec = TerjeGetActiveTimeSec(player.GetTerjeStats().GetAntisepsisValue(), medTimeSec, amount, perkPharmacMod);
			player.GetTerjeStats().SetAntisepsisValue(Math.Min(MaxTimeSec, ActiveTimeSec));
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medConcussionHealTimeSec" );
		if (medTimeSec > 0)
		{
			MaxTimeSec = TerjeGetMaxTimeSec(classname, "medConcussionHeal");
			ActiveTimeSec = TerjeGetActiveTimeSec(player.GetTerjeStats().GetContusionHealValue(), medTimeSec, amount, perkPharmacMod);
			player.GetTerjeStats().SetContusionHealValue(Math.Min(MaxTimeSec, ActiveTimeSec));
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medHematomaHealTimeSec" );
		if (medTimeSec > 0)
		{
			MaxTimeSec = TerjeGetMaxTimeSec(classname, "medHematomaHeal");
			ActiveTimeSec = TerjeGetActiveTimeSec(player.GetTerjeStats().GetSalveValue(), medTimeSec, amount, perkPharmacMod);
			player.GetTerjeStats().SetSalveValue(Math.Min(MaxTimeSec, ActiveTimeSec));
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAdrenalinTimeSec" );
		if (medTimeSec > 0)
		{
			MaxTimeSec = TerjeGetMaxTimeSec(classname, "medAdrenalin");
			ActiveTimeSec = TerjeGetActiveTimeSec(player.GetTerjeStats().GetAdrenalinValue(), medTimeSec, amount, perkPharmacMod);
			player.GetTerjeStats().SetAdrenalinValue(Math.Min(MaxTimeSec, ActiveTimeSec));
			
			player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStaminaMax());
		}
	}
	
	override void TerjeApplyVacineEffects(string classname, PlayerBase player, float amount, float perkPharmacMod)
	{
		super.TerjeApplyVacineEffects(classname, player, amount, perkPharmacMod);
		
		float medVacineTime;
		
		medVacineTime = GetTerjeGameConfig().ConfigGetFloat( classname + " medInfluenzaVacineTime" );
		if (medVacineTime > 0)
		{
			player.GetTerjeStats().SetInfluenzaVacineValue(medVacineTime * amount * perkPharmacMod);
		}
		
		medVacineTime = GetTerjeGameConfig().ConfigGetFloat( classname + " medZVirusVacineTime" );
		if (medVacineTime > 0)
		{
			player.GetTerjeStats().SetZVirusVacineValue(medVacineTime * amount * perkPharmacMod);
		}
		
		medVacineTime = GetTerjeGameConfig().ConfigGetFloat( classname + " medRabiesVacineTime" );
		if (medVacineTime > 0)
		{
			player.GetTerjeStats().SetRabiesVacineValue(medVacineTime * amount * perkPharmacMod);
		}
	}
	
	override void TerjeApplyNegativeEffects(string classname, PlayerBase player, float amount)
	{
		super.TerjeApplyNegativeEffects(classname, player, amount);
		
		float medDmgValue;
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medContussionLight");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetContusionValue(TerjeMedicineConstants.CONTUSION_LIGHT);
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medContussionHeavy");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetContusionValue(TerjeMedicineConstants.CONTUSION_HEAVY);
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat( classname + " overdosedIncrement" );
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetOverdoseValue(player.GetTerjeStats().GetOverdoseValue() + (medDmgValue * amount));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat( classname + " biohazardIncrement" );
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetBiohazardValue(player.GetTerjeStats().GetBiohazardValue() + (medDmgValue * amount));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medHematomasIncrement");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetHematomas(player.GetTerjeStats().GetHematomas() + (medDmgValue * amount));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medFoodPoisonIncrement");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetPoisonValue(player.GetTerjeStats().GetPoisonValue() + (medDmgValue * amount));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medChemicalPoisonIncrement");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetBiohazardValue(player.GetTerjeStats().GetBiohazardValue() + (medDmgValue * amount));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medInfuenzaInfectionIncrement");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetInfluenzaValue(player.GetTerjeStats().GetInfluenzaValue() + (medDmgValue * amount));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medZombieVirusIncrement");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetZVirusValue(player.GetTerjeStats().GetZVirusValue() + (medDmgValue * amount));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medSepsisInfectionIncrement");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetSepsisValue(player.GetTerjeStats().GetSepsisValue() + (medDmgValue * amount));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medRabiesVirusIncrement");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetRabiesValue(player.GetTerjeStats().GetRabiesValue() + (medDmgValue * amount));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medPsiDamageValue");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().AddMindDegradation(medDmgValue, GetTerjeGameConfig().ConfigGetFloat(classname + " medPsiDamageTime"));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medSleepDamageValue");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().AddSleepingDecrement(medDmgValue, GetTerjeGameConfig().ConfigGetFloat(classname + " medSleepDamageTime"));
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medPainSet");
		if (medDmgValue > 0)
		{
			player.GetTerjeStats().SetPainValue(medDmgValue);
		}
	}
	
	override string Describe(EntityAI entity, string classname)
	{
		string result = super.Describe(entity, classname);
		
		result += TerjeDescribePositiveEffects(string classname);
		result += TerjeDescribeVacineEffects(string classname);
		result += TerjeDescribeNegativeEffects(string classname);
		
		return result;
	}
	
	string TerjeDescribePositiveEffects(string classname)
	{
		string result;
		int medLevel;
		float medValue;
		float medTimeSec;
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medPainkillerLevel" );
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medPainkillerTimeSec" );
		if (medLevel > 0 && medTimeSec > 0)
		{
			result += "#STR_TERJEMED_EFFECT_PAINKILLER " + COLOR_GREEN + medLevel + TimeValue(medTimeSec);
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medAntibioticLevel" );
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntibioticsTimeSec" );
		if (medLevel > 0 && medTimeSec > 0)
		{
			result += "#STR_TERJEMED_EFFECT_ANTIBIOTIC " + COLOR_GREEN + medLevel + TimeValue(medTimeSec);			
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medRabiesAntibioticLevel" );
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medRabiesAntibioticTimeSec" );
		if (medLevel > 0 && medTimeSec > 0)
		{
			result += "#STR_TERJEMED_EFFECT_RABIESCURE " + COLOR_GREEN + medLevel + TimeValue(medTimeSec);			
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medAntipoisonLevel" );
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntipoisonTimeSec" );
		if (medLevel > 0 && medTimeSec > 0)
		{
			result += "#STR_TERJEMED_EFFECT_ANTIPOISON " + COLOR_GREEN + medLevel + TimeValue(medTimeSec);
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medAntibiohazardLevel" );
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntibiohazardTimeSec" );
		if (medLevel > 0 && medTimeSec > 0)
		{
			result += "#STR_TERJEMED_EFFECT_ANTIBIOHAZARD " + COLOR_GREEN + medLevel + TimeValue(medTimeSec);
		}
		
		medLevel = GetTerjeGameConfig().ConfigGetInt( classname + " medAntidepresantLevel" );
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntidepresantTimer" );
		if (medLevel > 0 && medTimeSec > 0)
		{
			result += "#STR_TERJEMED_EFFECT_ANTIDEPRESANT " + COLOR_GREEN + medLevel + TimeValue(medTimeSec);			
		}
		
		medValue = GetTerjeGameConfig().ConfigGetInt( classname + " medBloodHemostaticValue" );
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medBloodHemostaticTimeSec" );
		if (medValue > 0 && medTimeSec > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_HEMOSTATIC " + TimeValue(medTimeSec);
		}
		
		medValue = GetTerjeGameConfig().ConfigGetInt( classname + " medBloodRegenValue" );
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medBloodRegenTimeSec" );
		if (medValue > 0 && medTimeSec > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_BLOODREGEN " + TimeValue(medTimeSec);
		}
		
		medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medImmunityGainForce" );
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medImmunityGainTimeSec" );
		TerjeLog_Info("medImmunityGainForce=" + medValue + "; medImmunityGainTimeSec=" + medTimeSec);
		if (medValue > 0 && medTimeSec > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_IMMUNGAIN " + TimeValue(medTimeSec);
		}
		//---- medMindDegradationTime
		//---- medSleepingIncrementTimeSec
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medHealthgainTimeSec" );
		if (medTimeSec > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_HEALTHREGEN " + TimeValue(medTimeSec);
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medZAntidotTimeSec" );
		if (medTimeSec > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_ZANTIDOT " + TimeValue(medTimeSec);
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAntisepsisTimeSec" );
		if (medTimeSec > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_ANTISEPSIS " + TimeValue(medTimeSec);
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medConcussionHealTimeSec" );
		if (medTimeSec > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_CONTUSIONCURE " + TimeValue(medTimeSec);
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetInt( classname + " medHematomaHealTimeSec" );
		if (medTimeSec > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_HEMATOMA " + TimeValue(medTimeSec);
		}
		
		medTimeSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medAdrenalinTimeSec" );
		if (medTimeSec > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_ADRENALIN " + TimeValue(medTimeSec);
		}
		
		return result;
	}
	
	string TerjeDescribeVacineEffects(string classname)
	{
		string result;
		float medVacineTime;
		
		medVacineTime = GetTerjeGameConfig().ConfigGetFloat( classname + " medInfluenzaVacineTime" );
		if (medVacineTime > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_INFVACINE " + TimeValue(medVacineTime);
		}
		
		medVacineTime = GetTerjeGameConfig().ConfigGetFloat( classname + " medZVirusVacineTime" );
		if (medVacineTime > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_ZEDVACINE " + TimeValue(medVacineTime);
		}
		
		medVacineTime = GetTerjeGameConfig().ConfigGetFloat( classname + " medRabiesVacineTime" );
		if (medVacineTime > 0)
		{
			result += COLOR_YELLOW + "#STR_TERJEMED_EFFECT_RABIESVACCINE " + TimeValue(medVacineTime);
		}
		
		return result;
	}
	
	string TerjeDescribeNegativeEffects(string classname)
	{
		string result;
		float medDmgValue;
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat( classname + " overdosedIncrement" );
		if (medDmgValue > 0)
		{
			result += "#STR_TERJEMED_EFFECT_OVERDOSE " + COLOR_RED + PercentValue("+", medDmgValue);
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat( classname + " biohazardIncrement" );
		if (medDmgValue > 0)
		{
			result += "#STR_TERJEMED_EFFECT_BIOHAZARD " + COLOR_RED + PercentValue("+", medDmgValue);
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medHematomasIncrement");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_HEMATOMA " + NoValue();
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medContussionLight");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_CONTLIGHT " + NoValue();
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medContussionHeavy");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_CONTHEAVY " + NoValue();
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medFoodPoisonIncrement");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_FOODPOISON " + NoValue();
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medChemicalPoisonIncrement");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_CHEMPOISON " + NoValue();
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medInfuenzaInfectionIncrement");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_INFLUENZA " + NoValue();
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medZombieVirusIncrement");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_ZOMBIE " + NoValue();
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medSepsisInfectionIncrement");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_SEPSIS " + NoValue();
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medRabiesVirusIncrement");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_RABIES " + NoValue();
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medPsiDamageTime");
		if (medDmgValue > 0)
		{
			result += "#STR_TERJEMED_EFFECT_DMG_PSI " + COLOR_RED + TimeValue(medDmgValue);	
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medSleepDamageTime");
		if (medDmgValue > 0)
		{
			result += "#STR_TERJEMED_EFFECT_DMG_SLEEP " + COLOR_RED + TimeValue(medDmgValue);	
		}
		
		medDmgValue = GetTerjeGameConfig().ConfigGetFloat(classname + " medPainSet");
		if (medDmgValue > 0)
		{
			result += COLOR_RED + "#STR_TERJEMED_EFFECT_DMG_PAIN " + LevelValue(medDmgValue);
		}
		
		return result;
	}
}
