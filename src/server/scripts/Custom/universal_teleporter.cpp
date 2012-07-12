#include "ScriptPCH.h"
#include "Config.h"

class universal_teleporter : public CreatureScript {
public: universal_teleporter(): CreatureScript("universal_teleporter") {}

void MainMenu(Player *pPlayer, Creature *pCreature) {
	pPlayer->ADD_GOSSIP_ITEM(9, "[Duel] Ahn Qiraj", GOSSIP_SENDER_MAIN, 16);
	pPlayer->ADD_GOSSIP_ITEM(6, "Dalaran (acces au monde...)", GOSSIP_SENDER_MAIN, 14);
	pPlayer->SEND_GOSSIP_MENU(1000006, pCreature->GetGUID()); }
		

bool OnGossipHello(Player* pPlayer, Creature* pCreature) {
	MainMenu(pPlayer, pCreature);
       return true; }


bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction) {
		
	if (pPlayer->isInCombat()) {
		pCreature->MonsterWhisper("Vous etes en combat.", pPlayer->GetGUID());
		pPlayer->CLOSE_GOSSIP_MENU();
		return true; }
		
	pPlayer->PlayerTalkClass->ClearMenus();

switch (uiAction) {

	case 1:
	MainMenu(pPlayer, pCreature);
	break;
		
	case 14: {
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 5819.49f, 642.93f, 647.9f, 0.1f);
		break; }
	case 16: {
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(531, -8512.5f, 2016.02f, 104.6f, 3.6f);
		break; }

	} return true;
} };

void AddSc_Script_UTeleporter() { new universal_teleporter(); }