#include "ScriptPCH.h"
#include "Config.h"

class universal_teleporter : public CreatureScript {
	public: universal_teleporter() : CreatureScript("universal_teleporter") {}

void MainMenu(Player *player, Creature *creature) {

	std::ostringstream ostr;
	ostr << "[FFA] " << ConfigMgr::GetStringDefault("u_t_s", "");
	
	if (player->GetTeam() == ALLIANCE) {
		player->ADD_GOSSIP_ITEM(6, "[Shop] Karazhan", GOSSIP_SENDER_MAIN, 10);
		player->ADD_GOSSIP_ITEM(9, "[PvP sauvage] Cratère d'Azshara", GOSSIP_SENDER_MAIN, 12); }
	if (player->GetTeam() == HORDE) {
		player->ADD_GOSSIP_ITEM(6, "[Shop] Karazhan", GOSSIP_SENDER_MAIN, 11);
		player->ADD_GOSSIP_ITEM(9, "[PvP sauvage] Cratère d'Azshara", GOSSIP_SENDER_MAIN, 13); }
	player->ADD_GOSSIP_ITEM(9, "[Duel] Ahn Qiraj", GOSSIP_SENDER_MAIN, 16);
	player->ADD_GOSSIP_ITEM(9, ostr.str().c_str(), GOSSIP_SENDER_MAIN, 20);
	player->ADD_GOSSIP_ITEM(6, "Dalaran (accès au monde...)", GOSSIP_SENDER_MAIN, 14);
	player->SEND_GOSSIP_MENU(1, creature->GetGUID()); }
	
bool OnGossipHello(Player* player, Creature* creature) {
	MainMenu(player, creature);
	return true; }

bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction) {

	uint32 u_t_m = ConfigMgr::GetIntDefault("u_t_m", NULL);
	float u_t_x = ConfigMgr::GetFloatDefault("u_t_x", NULL);
	float u_t_y = ConfigMgr::GetFloatDefault("u_t_y", NULL);
	float u_t_z = ConfigMgr::GetFloatDefault("u_t_z", NULL);
	float u_t_o = ConfigMgr::GetFloatDefault("u_t_o", NULL);

	if (player->isInCombat() && player->GetMapId() != 531 && player->GetMapId() != 532) {
		creature->MonsterWhisper("Vous êtes en combat.", player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
		return true; }

	player->PlayerTalkClass->ClearMenus();

		switch (uiAction) {

	case 1: MainMenu(player, creature); break;

	case 10: {
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(532, -10945.8f, -2103.85f, 92.8f, 0.9f);
		break; }
	case 11: {
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(532, -11233.4f, -1697.76f, 179.3f, 0.6f);
		break; }
		
	case 12: {
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(37, -120.103f, -52.833f, 268.7f, 0.1f);
		break; }

	case 13: {
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(37, 362.67f, 97.629f, 247.5f, 3.1f);
		break; }

	case 14: {
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(571, 5819.49f, 642.93f, 647.9f, 0.1f);
		break; }

	case 16: {
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(531, -8512.5f, 2016.02f, 104.6f, 3.6f);
		break; }
	
	case 20: {
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(u_t_m, u_t_x, u_t_y, u_t_z, u_t_o);
		break; }
		
		}
    return true; }
};

void AddSc_universal_teleporter() {
	new universal_teleporter(); }