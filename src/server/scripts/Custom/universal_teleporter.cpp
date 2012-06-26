#include "ScriptPCH.h"
#include "Config.h"

class universal_teleporter : public CreatureScript
{
public:
	universal_teleporter()
		: CreatureScript("universal_teleporter")
	{}

	void MainMenu(Player *pPlayer, Creature *pCreature)
	{
		std::ostringstream ostr;
		ostr << "[FFA] " << ConfigMgr::GetStringDefault("u_t_s", "");

		switch (pPlayer->GetTeam()) {
			case ALLIANCE:
				pPlayer->ADD_GOSSIP_ITEM(6, "[Shop] Karazhan", GOSSIP_SENDER_MAIN, 10);
				pPlayer->ADD_GOSSIP_ITEM(9, "[PvP sauvage] Cratere d'Azshara", GOSSIP_SENDER_MAIN, 12);
			break;
			case HORDE:
				pPlayer->ADD_GOSSIP_ITEM(6, "[Shop] Karazhan", GOSSIP_SENDER_MAIN, 11);
				pPlayer->ADD_GOSSIP_ITEM(9, "[PvP sauvage] Cratere d'Azshara", GOSSIP_SENDER_MAIN, 13);
			break; }
				pPlayer->ADD_GOSSIP_ITEM(9, "[Duel] Ahn Qiraj", GOSSIP_SENDER_MAIN, 16);
				pPlayer->ADD_GOSSIP_ITEM(9, ostr.str().c_str(), GOSSIP_SENDER_MAIN, 20);
				pPlayer->ADD_GOSSIP_ITEM(6, "Dalaran (acces au monde...)", GOSSIP_SENDER_MAIN, 14);
		pPlayer->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
	}
		

	bool OnGossipHello(Player* pPlayer, Creature* pCreature) {
		MainMenu(pPlayer, pCreature);
        return true; }


    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
		
		uint32 u_t_m = ConfigMgr::GetIntDefault("u_t_m", NULL);
		float u_t_x = ConfigMgr::GetFloatDefault("u_t_x", NULL);
		float u_t_y = ConfigMgr::GetFloatDefault("u_t_y", NULL);
		float u_t_z = ConfigMgr::GetFloatDefault("u_t_z", NULL);
		float u_t_o = ConfigMgr::GetFloatDefault("u_t_o", NULL);

		if (pPlayer->isInCombat())
		{
			pCreature->MonsterWhisper("Vous etes en combat.", pPlayer->GetGUID());
			pPlayer->CLOSE_GOSSIP_MENU();
			return true;
		}

		pPlayer->PlayerTalkClass->ClearMenus();

		switch (uiAction)
		{
			case 1:
			MainMenu(pPlayer, pCreature);
			break;
			
			case 10: {
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(532, -10945.8f, -2103.85f, 92.8f, 0.9f);
				break; }

			case 11: {
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(532, -11233.4f, -1697.76f, 179.3f, 0.6f);
				break; }
			
			case 12: {
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(37, -120.103f, -52.833f, 268.7f, 0.1f);
				break; }
			
			case 13: {
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(37, 362.67f, 97.629f, 247.5f, 3.1f);
				break; }
			case 14: {
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(571, 5819.49f, 642.93f, 647.9f, 0.1f);
				break; }
			case 15: {
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(0, -4803.11f, -975.12f, 399.1f, 3.3f);
				break; }
			case 16: {
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(531, -8512.5f, 2016.02f, 104.6f, 3.6f);
				break; }

					 
			case 20: {
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(u_t_m, u_t_x, u_t_y, u_t_z, u_t_o);
				break; }
		}

        return true;
	}
};

void AddSc_Script_UTeleporter()
{
	new universal_teleporter();
}