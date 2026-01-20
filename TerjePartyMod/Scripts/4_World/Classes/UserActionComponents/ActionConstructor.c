modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		
		actions.Insert(ActionSendInvite);
		actions.Insert(ActionAcceptInvite);
		actions.Insert(ActionRemoveFromFriends);
	}
};