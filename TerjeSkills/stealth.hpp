class Stealth: SkillsBase
{
	id="stlth";
	enabled=1;
	displayName="#STR_TERJESKILL_STEALCH_NAME";
	description="#STR_TERJESKILL_STEALCH_DESC";
	icon="set:TerjeSkills_icon image:ts_stealth";
	class Perks
	{
		class QuietStep
		{
			id="qtstep";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_QUIETSTEP";
			description="#STR_TERJEPERK_STLTH_QUIETSTEP_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_quiestep";
			enabledIcon="set:TerjePerk_icon image:tp_quiestep";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.10,-0.25,-0.5,-0.75};
		};
		class ColdBlooded
		{
			id="coldbldd";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_COLDBLOODED";
			description="#STR_TERJEPERK_STLTH_COLDBLOODED_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_coldblooded";
			enabledIcon="set:TerjePerk_icon image:tp_coldblooded";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.25,-0.5,-0.75,-1.0};
		};
		class QuietShooter
		{
			id="qshooter";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_QUIETSHOOTER";
			description="#STR_TERJEPERK_STLTH_QUIETSHOOTER_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_quietshooter";
			enabledIcon="set:TerjePerk_icon image:tp_quietshooter";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.10,-0.25,-0.5,-0.75};
		};
		class FittingEquipment
		{
			id="fitequip";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_FITTINGEQUIP";
			description="#STR_TERJEPERK_STLTH_FITTINGEQUIP_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_fittingequipment";
			enabledIcon="set:TerjePerk_icon image:tp_fittingequipment";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.2,-0.4,-0.6,-0.8};
		};
		class InvisibleMan
		{
			id="invisman";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_INVISIBLEMAN";
			description="#STR_TERJEPERK_STLTH_INVISIBLEMAN_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_invisibleman";
			enabledIcon="set:TerjePerk_icon image:tp_invisibleman";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.10,-0.25,-0.5,-0.75};
		};
		class CatVision
		{
			id="catvis";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_CATVISION";
			description="#STR_TERJEPERK_STLTH_CATVISION_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_catvision";
			enabledIcon="set:TerjePerk_icon image:tp_catvision";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={0.25,0.5,0.75,1.0,1.5};
		};
		class WolfInstinct
		{
			id="wolfinst";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_WOLFINSTINCT";
			description="#STR_TERJEPERK_STLTH_WOLFINSTINCT_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_wolfinstinct";
			enabledIcon="set:TerjePerk_icon image:tp_wolfinstinct";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.2,-0.3,-0.6,-0.9};
		};
		class BearsFriend
		{
			id="bearfrnd";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_FRIENDBEAR";
			description="#STR_TERJEPERK_STLTH_FRIENDBEAR_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_friendbear";
			enabledIcon="set:TerjePerk_icon image:tp_friendbear";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.2,-0.3,-0.6,-0.9};
		};
		class SilentKiller
		{
			id="silentkilr";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_SILENTKILLER";
			description="#STR_TERJEPERK_STLTH_SILENTKILLER_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_silentkiller";
			enabledIcon="set:TerjePerk_icon image:tp_silentkiller";
			requiredSkillLevels[]={1};
			requiredPerkPoints[]={2};
			values[]={0.0};
		};
		class Ninja
		{
			id="ninja";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_NINJA";
			description="#STR_TERJEPERK_STLTH_NINJA_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_ninja";
			enabledIcon="set:TerjePerk_icon image:tp_ninja";
			requiredSkillLevels[]={30};
			requiredPerkPoints[]={3};
			values[]={-0.5};
		};
		class ShadowTracker
		{
			id="shadowtrc";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_SHADOWTRACKER";
			description="#STR_TERJEPERK_STLTH_SHADOWTRACKER_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_shadowtrack";
			enabledIcon="set:TerjePerk_icon image:tp_shadowtrack";
			requiredSkillLevels[]={40};
			requiredPerkPoints[]={3};
			values[]={0.0};
		};
	};
};