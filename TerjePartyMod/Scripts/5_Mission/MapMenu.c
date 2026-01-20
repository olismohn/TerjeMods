modded class MapMenu
{
	override void Update(float timeslice)
	{
		super.Update(timeslice);
		
		MissionGameplay missionGameplay = MissionGameplay.Cast(GetGame().GetMission());
		if (missionGameplay)
		{
			m_MapWidgetInstance.ClearUserMarks();
			missionGameplay.TerjePartyMapWidgetFill(m_MapWidgetInstance, true);
		}
	}
};