modded class PluginManager
{
	override void Init()
	{
		RegisterPlugin("PluginTerjeParty", true, true);
		super.Init();
	}
}