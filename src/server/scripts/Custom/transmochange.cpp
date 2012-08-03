#include "ScriptPCH.h"

class transmochange : public CreatureScript {
	public: transmochange() : CreatureScript("transmochange"){}
	

void MainMenu(Player *player, Creature *creature) {
	player->ADD_GOSSIP_ITEM(7, "Cachets hakkari...", GOSSIP_SENDER_MAIN, 3);
	player->ADD_GOSSIP_ITEM(7, "Insignes de justice...", GOSSIP_SENDER_MAIN, 4);
	player->ADD_GOSSIP_ITEM(7, "Marques d'honneur...", GOSSIP_SENDER_MAIN, 5);
	player->ADD_GOSSIP_ITEM(7, "Points d'arène...", GOSSIP_SENDER_MAIN, 6);
	player->ADD_GOSSIP_ITEM(7, "Trophées valereux...", GOSSIP_SENDER_MAIN, 7);
	player->ADD_GOSSIP_ITEM(0, "<Aurevoir>", GOSSIP_SENDER_MAIN, 0);
	player->SEND_GOSSIP_MENU(1000021, creature->GetGUID()); }

bool OnGossipHello(Player *player, Creature * creature) { MainMenu(player, creature); return true; }
	
bool OnGossipSelect(Player *player, Creature * creature, uint32 sender, uint32 action) {
WorldSession* session = player->GetSession();
player->PlayerTalkClass->ClearMenus();

		switch (action){
	
	case 0: player->CLOSE_GOSSIP_MENU(); break;
	
	case 1: MainMenu(player, creature); break;

    case 3:
        player->ADD_GOSSIP_ITEM(1, "Acheter 10 emblèmes pour 1 Cachet hakkari conservé", GOSSIP_SENDER_MAIN, 30);
        player->ADD_GOSSIP_ITEM(1, "Acheter 50 emblèmes pour 5 Cachet hakkari conservé", GOSSIP_SENDER_MAIN, 31);
        player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 1);
        player->SEND_GOSSIP_MENU(1000021, creature->GetGUID());
		break;
	case 30:
		if (player->HasItemCount(39715, 1, 0)) {
			player->DestroyItemCount(39715, 1, true, false);
			player->AddItem(40752, 10);
			session->SendAreaTriggerMessage("Vous avez reçu 10 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 3);
		break;
	case 31:
		if (player->HasItemCount(39715, 5, 0)) {
			player->DestroyItemCount(39715, 5, true, false);
			player->AddItem(40752, 50);
			session->SendAreaTriggerMessage("Vous avez reçu 50 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 3);
		break;
		
    case 4:
        player->ADD_GOSSIP_ITEM(1, "Acheter 5 emblèmes pour 5 insignes", GOSSIP_SENDER_MAIN, 40);
        player->ADD_GOSSIP_ITEM(1, "Acheter 10 emblèmes pour 10 insignes", GOSSIP_SENDER_MAIN, 41);
        player->ADD_GOSSIP_ITEM(1, "Acheter 50 emblèmes pour 50 insignes", GOSSIP_SENDER_MAIN, 42);
        player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 1);
        player->SEND_GOSSIP_MENU(1000021, creature->GetGUID());
		break;
	case 40:
		if (player->HasItemCount(29434, 5, 0)) {
			player->DestroyItemCount(29434, 5, true, false);
			player->AddItem(40752, 5);
			session->SendAreaTriggerMessage("Vous avez reçu 5 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 4);
		break;
	case 41:
		if (player->HasItemCount(29434, 10, 0)) {
			player->DestroyItemCount(29434, 10, true, false);
			player->AddItem(40752, 10);
			session->SendAreaTriggerMessage("Vous avez reçu 10 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 4);
		break;
	case 42:
		if (player->HasItemCount(29434, 50, 0)) {
			player->DestroyItemCount(29434, 50, true, false);
			player->AddItem(40752, 50);
			session->SendAreaTriggerMessage("Vous avez reçu 50 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 4);
		break;
		
    case 5:
        player->ADD_GOSSIP_ITEM(1, "Acheter 5 emblèmes pour 1 marque du Goulet", GOSSIP_SENDER_MAIN, 50);
        player->ADD_GOSSIP_ITEM(1, "Acheter 10 emblèmes pour 2 marque du Goulet", GOSSIP_SENDER_MAIN, 51);
        player->ADD_GOSSIP_ITEM(1, "Acheter 50 emblèmes pour 10 marque du Goulet", GOSSIP_SENDER_MAIN, 52);
        player->ADD_GOSSIP_ITEM(1, "Acheter 5 emblèmes pour 1 marque du Bassin", GOSSIP_SENDER_MAIN, 53);
        player->ADD_GOSSIP_ITEM(1, "Acheter 10 emblèmes pour 2 marque du Bassin", GOSSIP_SENDER_MAIN, 54);
        player->ADD_GOSSIP_ITEM(1, "Acheter 50 emblèmes pour 10 marque du Bassin", GOSSIP_SENDER_MAIN, 55);
        player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 1);
        player->SEND_GOSSIP_MENU(1000021, creature->GetGUID());
		break;
	case 50:
		if (player->HasItemCount(20558, 1, 0)) {
			player->DestroyItemCount(20558, 1, true, false);
			player->AddItem(40752, 5);
			session->SendAreaTriggerMessage("Vous avez reçu 5 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 5);
		break;
	case 51:
		if (player->HasItemCount(20558, 2, 0)) {
			player->DestroyItemCount(20558, 2, true, false);
			player->AddItem(40752, 10);
			session->SendAreaTriggerMessage("Vous avez reçu 10 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 5);
		break;
	case 52:
		if (player->HasItemCount(20558, 10, 0)) {
			player->DestroyItemCount(20558, 10, true, false);
			player->AddItem(40752, 50);
			session->SendAreaTriggerMessage("Vous avez reçu 50 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 5);
		break;
	case 53:
		if (player->HasItemCount(20559, 1, 0)) {
			player->DestroyItemCount(20559, 1, true, false);
			player->AddItem(40752, 5);
			session->SendAreaTriggerMessage("Vous avez reçu 5 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 5);
		break;
	case 54:
		if (player->HasItemCount(20559, 2, 0)) {
			player->DestroyItemCount(20559, 2, true, false);
			player->AddItem(40752, 10);
			session->SendAreaTriggerMessage("Vous avez reçu 10 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 5);
		break;
	case 55:
		if (player->HasItemCount(20559, 10, 0)) {
			player->DestroyItemCount(20559, 10, true, false);
			player->AddItem(40752, 50);
			session->SendAreaTriggerMessage("Vous avez reçu 50 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 5);
		break;
		
    case 6:
        player->ADD_GOSSIP_ITEM(1, "Acheter 5 emblèmes pour 15 points d'arène", GOSSIP_SENDER_MAIN, 60);
        player->ADD_GOSSIP_ITEM(1, "Acheter 10 emblèmes pour 30 points d'arène", GOSSIP_SENDER_MAIN, 61);
        player->ADD_GOSSIP_ITEM(1, "Acheter 50 emblèmes pour 150 points d'arène", GOSSIP_SENDER_MAIN, 62);
        player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 1);
        player->SEND_GOSSIP_MENU(1000021, creature->GetGUID());
		break;
	case 60:
		if (player->GetArenaPoints() >= 15) {
			player->SetArenaPoints(player->GetArenaPoints()-15);
			player->AddItem(40752, 5);
			session->SendAreaTriggerMessage("Vous avez reçu 5 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 6);
		break;
	case 61:
		if (player->GetArenaPoints() >= 30) {
			player->SetArenaPoints(player->GetArenaPoints()-30);
			player->AddItem(40752, 10);
			session->SendAreaTriggerMessage("Vous avez reçu 10 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 6);
		break;
	case 62:
		if (player->GetArenaPoints() >= 150) {
			player->SetArenaPoints(player->GetArenaPoints()-150);
			player->AddItem(40752, 50);
			session->SendAreaTriggerMessage("Vous avez reçu 50 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 6);
		break;
		
    case 7:
        player->ADD_GOSSIP_ITEM(1, "Acheter 10 emblèmes pour 1 trophée valeureux", GOSSIP_SENDER_MAIN, 70);
        player->ADD_GOSSIP_ITEM(1, "Acheter 50 emblèmes pour 5 trophée valeureux", GOSSIP_SENDER_MAIN, 70);
        player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 1);
        player->SEND_GOSSIP_MENU(1000021, creature->GetGUID());
		break;
	case 70:
		if (player->HasItemCount(4193, 1, 0)) {
			player->DestroyItemCount(4193, 1, true, false);
			player->AddItem(40752, 10);
			session->SendAreaTriggerMessage("Vous avez reçu 10 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 7);
		break;
	case 71:
		if (player->HasItemCount(4193, 5, 0)) {
			player->DestroyItemCount(4193, 5, true, false);
			player->AddItem(40752, 50);
			session->SendAreaTriggerMessage("Vous avez reçu 50 emblèmes."); }
		else session->SendNotification("Vous n'avez pas les objets requis.");
		OnGossipSelect(player, creature, sender, 7);
		break;

		}
	return true; }
};

void AddSc_transmochange() {
	new transmochange(); }