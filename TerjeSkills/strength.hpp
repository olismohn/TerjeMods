class Strength: SkillsBase
{
	id="strng";
	enabled=1;
	displayName="#STR_TERJESKILL_STRENGTH_NAME";
	description="#STR_TERJESKILL_STRENGTH_DESC";
	icon="set:TerjeSkills_icon image:ts_strength";
	class Modifiers
	{
		class MaxWeightModifier
		{
			id="maxweightmod";
			enabled=1;
			text="#STR_TERJESKILL_STRENGTH_MOD0";
			value=0.02;
		};
	};
	class Perks
	{
		class HeavyWeight
		{
			id="hvweight";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_HEAVYWEIGHT";
			description="#STR_TERJEPERK_STRNG_HEAVYWEIGHT_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_heavyweight";
			enabledIcon="set:TerjePerk_icon image:tp_heavyweight";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={0.1,0.25,0.5,0.75,1.0};
		};
		class Jumper
		{
			id="jumper";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_JUMPER";
			description="#STR_TERJEPERK_STRNG_JUMPER_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_jumper";
			enabledIcon="set:TerjePerk_icon image:tp_jumper";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.2,-0.4,-0.6,-0.8};
		};
		class MasterOfDefence
		{
			id="mrdefence";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_MRPROTECTION";
			description="#STR_TERJEPERK_STRNG_MRPROTECTION_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_masterdefense";
			enabledIcon="set:TerjePerk_icon image:tp_masterdefense";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.15,-0.25,-0.5,-0.8};
		};
		class MasterOfEvasion
		{
			id="mrevasion";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_MREVASION";
			description="#STR_TERJEPERK_STRNG_MREVASION_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_masterevasion";
			enabledIcon="set:TerjePerk_icon image:tp_masterevasion";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={0.1,0.25,0.5,0.75,1.0};
		};
		class LightAttacksSpeed
		{
			id="lattkspeed";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_GUSTYSQUALL";
			description="#STR_TERJEPERK_STRNG_GUSTYSQUALL_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_gustysquall";
			enabledIcon="set:TerjePerk_icon image:tp_gustysquall";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.15,-0.25,-0.5,-0.8};
		};
		class LightAttacksForce
		{
			id="lattkforce";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_CRUSHINGSQUALL";
			description="#STR_TERJEPERK_STRNG_CRUSHINGSQUALL_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_crushingsquall";
			enabledIcon="set:TerjePerk_icon image:tp_crushingsquall";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={0.10,0.25,0.5,0.75,1.0};
		};
		class HeavyAttacksSpeed
		{
			id="hattkspeed";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_HEAVYONSLAUGHT";
			description="#STR_TERJEPERK_STRNG_HEAVYONSLAUGHT_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_heavyonslaught";
			enabledIcon="set:TerjePerk_icon image:tp_heavyonslaught";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.15,-0.25,-0.5,-0.8};
		};
		class HeavyAttacksForce
		{
			id="hattkforce";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_DESTRUCTONSLAUGHT";
			description="#STR_TERJEPERK_STRNG_DESTRUCTONSLAUGHT_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_destronslaught";
			enabledIcon="set:TerjePerk_icon image:tp_destronslaught";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={0.10,0.25,0.5,0.75,1.0};
		};
		class LightweightArmor
		{
			id="ltarmor";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_LIGHTARMOR";
			description="#STR_TERJEPERK_STRNG_LIGHTARMOR_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_lightarmor";
			enabledIcon="set:TerjePerk_icon image:tp_lightarmor";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.25,-0.5,-0.75,-1.0};
		};
		class StrongHands
		{
			id="strhands";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_STRONGHANDS";
			description="#STR_TERJEPERK_STRNG_STRONGHANDS_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_stronghands";
			enabledIcon="set:TerjePerk_icon image:tp_stronghands";
			requiredSkillLevels[]={1};
			requiredPerkPoints[]={1};
			values[]={0.0};
		};
		class MasterStroke
		{
			id="mrstroke";
			enabled=1;
			displayName="#STR_TERJEPERK_STRNG_MASTERSTROKE";
			description="#STR_TERJEPERK_STRNG_MASTERSTROKE_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_masterstroke";
			enabledIcon="set:TerjePerk_icon image:tp_masterstroke";
			requiredSkillLevels[]={35};
			requiredPerkPoints[]={1};
			values[]={0.0};
		};
	};
};
