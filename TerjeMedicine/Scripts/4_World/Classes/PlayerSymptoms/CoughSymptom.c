modded class CoughSymptom
{
	override bool IsContaminationActive()
	{
		if (m_Player && m_Player.GetTerjeStats() && m_Player.GetTerjeStats().GetBiohazardValue() >= 1)
			return true;
		return false;
	}
}
