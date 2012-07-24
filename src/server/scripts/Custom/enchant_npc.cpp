#include "ScriptPCH.h"

class enchant_npc : public CreatureScript {
public: enchant_npc() : CreatureScript("enchant_npc") {}

uint8 slotid; uint32 enchid; uint32 reqil; uint32 twoha; uint32 slty;

bool OnGossipHello(Player *player, Creature * creature) {
	MainMenu(player, creature);
    return true; }

void MainMenu(Player *player, Creature *creature) {
		slotid = 0; enchid = 0; reqil = 0; twoha = 0; slty = 0; Item *item;
        player->ADD_GOSSIP_ITEM(0, "Dos", GOSSIP_SENDER_MAIN, 14);
        player->ADD_GOSSIP_ITEM(0, "Torse", GOSSIP_SENDER_MAIN, 4);
        player->ADD_GOSSIP_ITEM(0, "Poignets", GOSSIP_SENDER_MAIN, 8);
        player->ADD_GOSSIP_ITEM(0, "Mains", GOSSIP_SENDER_MAIN, 9);
        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6); if(item)
        player->ADD_GOSSIP_ITEM(0, "Jambes : Renfort d'armure épais", GOSSIP_SENDER_MAIN, 6);
        player->ADD_GOSSIP_ITEM(0, "Pieds", GOSSIP_SENDER_MAIN, 7);
        player->ADD_GOSSIP_ITEM(0, "Main droite", GOSSIP_SENDER_MAIN, 15);		
        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16); if(item) {
		if(item->GetTemplate()->SubClass == 6)	player->ADD_GOSSIP_ITEM(0, "Bouclier", GOSSIP_SENDER_MAIN, 18);
        else { if(item->GetTemplate()->Class != 4) player->ADD_GOSSIP_ITEM(0, "Main gauche", GOSSIP_SENDER_MAIN, 16); } }
        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17); if(item) {
		if((item->GetTemplate()->SubClass == 2) || (item->GetTemplate()->SubClass == 3) || (item->GetTemplate()->SubClass == 18))
			player->ADD_GOSSIP_ITEM(0, "A distance : lunette mortelle", GOSSIP_SENDER_MAIN, 17); }
		player->SEND_GOSSIP_MENU(20003, creature->GetGUID()); }

void Ench(Player *player, Creature *creature, Item *item) {
	item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slotid );
	
	if(!item) {
		creature->MonsterWhisper("Vous devez vous équiper de l'objet.", player->GetGUID());
		MainMenu(player, creature);
        return; }
    if (reqil == 1 && item->GetTemplate()->ItemLevel <= 34) {
		creature->MonsterWhisper("L'objet n'est pas d'un niveau suffisant.", player->GetGUID());
		MainMenu(player, creature);
        return; }
    if (twoha == 1 && item->GetTemplate()->InventoryType != 17) {
		creature->MonsterWhisper("Cette enchantement requiert une arme à deux mains.", player->GetGUID());
		MainMenu(player, creature);
        return; }
	if (slotid == 16) {
	if ((item->GetTemplate()->Class == 4) && (item->GetTemplate()->SubClass != 6)) {
		creature->MonsterWhisper("Je n'enchante pas ce genre d'objets.", player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
        return; }
	if(item->GetTemplate()->SubClass == 6 && slty == 1) {
		creature->MonsterWhisper("Un enchantement d'arme ne va pas sur un bouclier.", player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
		return; }
	if(item->GetTemplate()->SubClass != 6 && slty == 0) {
		creature->MonsterWhisper("Un enchantement de bouclier ne va pas sur ce type d'arme.", player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
		return; } }
	SpellItemEnchantmentEntry const* enchant_id = sSpellItemEnchantmentStore.LookupEntry(enchid);
	if (!enchant_id) {
		creature->MonsterWhisper("L'enchantement sélectionné n'est pas un enchantement, prévenez un administrateur.", player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
        return; }
	if (slotid != 0) {
	player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, false);
	item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchid, 0, 0);
	player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, true); }
	else {
	player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 100);
	player->SEND_GOSSIP_MENU(1000011, creature->GetGUID()); 
	return; }
	MainMenu(player, creature); }

bool OnGossipSelect(Player *player, Creature * creature, uint32 sender, uint32 action) {
    player->PlayerTalkClass->ClearMenus();
	Item  *item;

		switch (action) {
	
	case 100:	MainMenu(player, creature);	break;

// Dos
	case 14:
		slotid = 14;
		player->ADD_GOSSIP_ITEM(3, "70 armure", GOSSIP_SENDER_MAIN, 1412);
		player->ADD_GOSSIP_ITEM(3, "120 armure", GOSSIP_SENDER_MAIN, 1407);
		player->ADD_GOSSIP_ITEM(3, "5 résistances", GOSSIP_SENDER_MAIN, 1413);
		player->ADD_GOSSIP_ITEM(3, "7 résistances", GOSSIP_SENDER_MAIN, 1408);
		player->ADD_GOSSIP_ITEM(3, "12 agilité", GOSSIP_SENDER_MAIN, 1401);
		player->ADD_GOSSIP_ITEM(3, "12 esquive", GOSSIP_SENDER_MAIN, 1406);
		player->ADD_GOSSIP_ITEM(3, "12 défense", GOSSIP_SENDER_MAIN, 1411);
		player->ADD_GOSSIP_ITEM(3, "20 pénétration des sorts", GOSSIP_SENDER_MAIN, 1409);
		player->ADD_GOSSIP_ITEM(3, "10 résistance ombre", GOSSIP_SENDER_MAIN, 1404);
		player->ADD_GOSSIP_ITEM(3, "15 résistance ombre", GOSSIP_SENDER_MAIN, 1403);
		player->ADD_GOSSIP_ITEM(3, "15 résistance feu", GOSSIP_SENDER_MAIN, 1405);
		player->ADD_GOSSIP_ITEM(3, "15 résistance arcane", GOSSIP_SENDER_MAIN, 1410);
		player->ADD_GOSSIP_ITEM(3, "15 résistance nature", GOSSIP_SENDER_MAIN, 1400);
		player->ADD_GOSSIP_ITEM(3, "camouflage", GOSSIP_SENDER_MAIN, 1402);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20004, creature->GetGUID());
		break;
	case 1400:	enchid = 1395;				Ench(player, creature, item);	break;
	case 1401:	enchid = 368;	reqil = 1; 	Ench(player, creature, item);	break;
	case 1402:	enchid = 910;				Ench(player, creature, item);	break;
	case 1403:	enchid = 1441;	reqil = 1;	Ench(player, creature, item);	break;
	case 1404:	enchid = 804;				Ench(player, creature, item);	break;
	case 1405:	enchid = 1349;				Ench(player, creature, item);	break;
	case 1406:	enchid = 2078;				Ench(player, creature, item);	break;
	case 1407:	enchid = 2662;	reqil = 1;	Ench(player, creature, item);	break;
	case 1408:	enchid = 2663;	reqil = 1;	Ench(player, creature, item);	break;
	case 1409:	enchid = 2780;	reqil = 1;	Ench(player, creature, item);	break;
	case 1410:	enchid = 1257;	reqil = 1;	Ench(player, creature, item);	break;
	case 1411:	enchid = 1943;	reqil = 1;	Ench(player, creature, item);	break;
	case 1412:	enchid = 1889;				Ench(player, creature, item);	break;
	case 1413:	enchid = 1888;				Ench(player, creature, item);	break;
		
// Torse
	case 4:
		slotid = 4;
		player->ADD_GOSSIP_ITEM(3, "100 vie", GOSSIP_SENDER_MAIN, 402);
		player->ADD_GOSSIP_ITEM(3, "100 mana", GOSSIP_SENDER_MAIN, 403);
		player->ADD_GOSSIP_ITEM(3, "150 vie", GOSSIP_SENDER_MAIN, 401);
		player->ADD_GOSSIP_ITEM(3, "4 caracteristiques", GOSSIP_SENDER_MAIN, 404);
		player->ADD_GOSSIP_ITEM(3, "6 caracteristiques", GOSSIP_SENDER_MAIN, 400);
		player->ADD_GOSSIP_ITEM(3, "7 mana par 5 secondes", GOSSIP_SENDER_MAIN, 405);
		player->ADD_GOSSIP_ITEM(3, "15 résilience", GOSSIP_SENDER_MAIN, 406);
		player->ADD_GOSSIP_ITEM(3, "15 esprit", GOSSIP_SENDER_MAIN, 407);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20005, creature->GetGUID());
		break;
	case 400:	enchid = 2661;	reqil = 1;	Ench(player, creature, item);	break;
	case 401:	enchid = 2659;	reqil = 1;	Ench(player, creature, item);	break;
	case 402:	enchid = 1892;				Ench(player, creature, item);	break;
	case 403:	enchid = 1893;				Ench(player, creature, item);	break;
	case 404:	enchid = 1891;				Ench(player, creature, item);	break;
	case 405:	enchid = 2852;	reqil = 1;	Ench(player, creature, item);	break;
	case 406:	enchid = 2789;	reqil = 1;	Ench(player, creature, item);	break;
	case 407:	enchid = 1144;	reqil = 1;	Ench(player, creature, item);	break;
  
// Bras
	case 8:
		slotid = 8;
		player->ADD_GOSSIP_ITEM(3, "12 endurance", GOSSIP_SENDER_MAIN, 805);
		player->ADD_GOSSIP_ITEM(3, "12 intelligence", GOSSIP_SENDER_MAIN, 806);
		player->ADD_GOSSIP_ITEM(3, "12 force", GOSSIP_SENDER_MAIN, 801);
		player->ADD_GOSSIP_ITEM(3, "24 puissance d'attaque", GOSSIP_SENDER_MAIN, 807);
		player->ADD_GOSSIP_ITEM(3, "15 puissance des sorts", GOSSIP_SENDER_MAIN, 800);
		player->ADD_GOSSIP_ITEM(3, "4 caracteristiques", GOSSIP_SENDER_MAIN, 802);
		player->ADD_GOSSIP_ITEM(3, "9 esprit", GOSSIP_SENDER_MAIN, 808);
		player->ADD_GOSSIP_ITEM(3, "12 défense", GOSSIP_SENDER_MAIN, 803);
		player->ADD_GOSSIP_ITEM(3, "8 mana par les 5 secondes", GOSSIP_SENDER_MAIN, 804);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20006, creature->GetGUID());
		break;
	case 800:	enchid = 2319;				Ench(player, creature, item);	break;
	case 801:	enchid = 372;	reqil = 1;	Ench(player, creature, item);	break;
	case 802:	enchid = 1891;	reqil = 1;	Ench(player, creature, item);	break;
	case 803:	enchid = 1943;	reqil = 1;	Ench(player, creature, item);	break;
	case 804:	enchid = 2382;	reqil = 1;	Ench(player, creature, item);	break;
	case 805:	enchid = 371;	reqil = 1;	Ench(player, creature, item);	break;
	case 806:	enchid = 369;	reqil = 1;	Ench(player, creature, item);	break;
	case 807:	enchid = 1593;	reqil = 1;	Ench(player, creature, item);	break;
	case 808:	enchid = 355;				Ench(player, creature, item);	break;

// Mains
	case 9:
		slotid = 9;
		player->ADD_GOSSIP_ITEM(3, "15 force", GOSSIP_SENDER_MAIN, 904);
		player->ADD_GOSSIP_ITEM(3, "15 agilité", GOSSIP_SENDER_MAIN, 901);
		player->ADD_GOSSIP_ITEM(3, "15 toucher", GOSSIP_SENDER_MAIN, 903);
		player->ADD_GOSSIP_ITEM(3, "10 critique", GOSSIP_SENDER_MAIN, 902);
		player->ADD_GOSSIP_ITEM(3, "26 puissance d'attaque", GOSSIP_SENDER_MAIN, 905);
		player->ADD_GOSSIP_ITEM(3, "20 puissance des sorts", GOSSIP_SENDER_MAIN, 906);
		player->ADD_GOSSIP_ITEM(3, "10 hâte", GOSSIP_SENDER_MAIN, 907);
		player->ADD_GOSSIP_ITEM(3, "2% vitesse monture", GOSSIP_SENDER_MAIN, 908);
		player->ADD_GOSSIP_ITEM(3, "5 pêche", GOSSIP_SENDER_MAIN, 900);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20007, creature->GetGUID());
		break;
	case 900:	enchid = 846;				Ench(player, creature, item);	break;
	case 901:	enchid = 883;				Ench(player, creature, item);	break;
	case 902:	enchid = 2934;	reqil = 1;	Ench(player, creature, item);	break;
	case 903:	enchid = 2935;	reqil = 1;	Ench(player, creature, item);	break;
	case 904:	enchid = 684;	reqil = 1;	Ench(player, creature, item);	break;
	case 905:	enchid = 1594;	reqil = 1;	Ench(player, creature, item);	break;
	case 906:	enchid = 2323;	reqil = 1;	Ench(player, creature, item);	break;
	case 907:	enchid = 931;				Ench(player, creature, item);	break;
	case 908:	enchid = 930;				Ench(player, creature, item);	break;

// Jambes
	case 6:	slotid = 6;	enchid = 18;	Ench(player, creature, item);	break;

// Bottes
	case 7:
		slotid = 7;
		player->ADD_GOSSIP_ITEM(3, "12 endurance", GOSSIP_SENDER_MAIN, 701);
		player->ADD_GOSSIP_ITEM(3, "12 agilité", GOSSIP_SENDER_MAIN, 704);
		player->ADD_GOSSIP_ITEM(3, "9 endurance + vitesse mineur", GOSSIP_SENDER_MAIN, 703);
		player->ADD_GOSSIP_ITEM(3, "6 agilité + vitesse mineur", GOSSIP_SENDER_MAIN, 705);
		player->ADD_GOSSIP_ITEM(3, "5 vie et mana par 5 secondes", GOSSIP_SENDER_MAIN, 700);
		player->ADD_GOSSIP_ITEM(3, "10 toucher et critique", GOSSIP_SENDER_MAIN, 702);
		player->ADD_GOSSIP_ITEM(3, "5 toucher", GOSSIP_SENDER_MAIN, 706);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20008, creature->GetGUID());
		break;
	case 700:	enchid = 2656;	reqil = 1;	Ench(player, creature, item);	break;
	case 701:	enchid = 371;	reqil = 1;	Ench(player, creature, item);	break;
	case 702:	enchid = 2658;	reqil = 1;	Ench(player, creature, item);	break;
	case 703:	enchid = 2940;	reqil = 1;	Ench(player, creature, item);	break;
	case 704:	enchid = 368;	reqil = 1;	Ench(player, creature, item);	break;
	case 705:	enchid = 2939;	reqil = 1;	Ench(player, creature, item);	break;
	case 706:	enchid = 3858;				Ench(player, creature, item);	break;
		
// Armes
	case 15:	slotid = 15;	goto l16;	break;
	case 16:	slotid = 16;	l16:
	case 153:	slty = 1;
		player->ADD_GOSSIP_ITEM(0, "=> Page 2", GOSSIP_SENDER_MAIN, 154);
		player->ADD_GOSSIP_ITEM(3, "15 force", GOSSIP_SENDER_MAIN, 1502);
		player->ADD_GOSSIP_ITEM(3, "20 force", GOSSIP_SENDER_MAIN, 1508);
		player->ADD_GOSSIP_ITEM(3, "15 agilité", GOSSIP_SENDER_MAIN, 1503);
		player->ADD_GOSSIP_ITEM(3, "20 agilité", GOSSIP_SENDER_MAIN, 1517);
		player->ADD_GOSSIP_ITEM(3, "20 esprit", GOSSIP_SENDER_MAIN, 1504);
		player->ADD_GOSSIP_ITEM(3, "22 intelligence", GOSSIP_SENDER_MAIN, 1505);
		player->ADD_GOSSIP_ITEM(3, "30 intelligence", GOSSIP_SENDER_MAIN, 1507);
		player->ADD_GOSSIP_ITEM(3, "29 puissance des sorts", GOSSIP_SENDER_MAIN, 1516);
		player->ADD_GOSSIP_ITEM(3, "30 puissance des sorts", GOSSIP_SENDER_MAIN, 1501);
		player->ADD_GOSSIP_ITEM(3, "40 puissance des sorts (jaune)", GOSSIP_SENDER_MAIN, 1515);
		player->ADD_GOSSIP_ITEM(3, "40 puissance des sorts (blanc)", GOSSIP_SENDER_MAIN, 1509);
		player->ADD_GOSSIP_ITEM(3, "50 feu et arcanes", GOSSIP_SENDER_MAIN, 1510);
		player->ADD_GOSSIP_ITEM(3, "54 givre et ombre", GOSSIP_SENDER_MAIN, 1511);
		player->ADD_GOSSIP_ITEM(3, "5 dégâts de l'arme", GOSSIP_SENDER_MAIN, 1521);
		player->ADD_GOSSIP_ITEM(3, "7 dégâts de l'arme", GOSSIP_SENDER_MAIN, 1506);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20009, creature->GetGUID());
		break;
	case 154:
		player->ADD_GOSSIP_ITEM(0, "Page 1 <=", GOSSIP_SENDER_MAIN, 153);
		player->ADD_GOSSIP_ITEM(3, "Croisé", GOSSIP_SENDER_MAIN, 1500);
		player->ADD_GOSSIP_ITEM(3, "Vol-de-vie", GOSSIP_SENDER_MAIN, 1518);
		player->ADD_GOSSIP_ITEM(3, "Impie", GOSSIP_SENDER_MAIN, 1519);
		player->ADD_GOSSIP_ITEM(3, "Flamboyante", GOSSIP_SENDER_MAIN, 1520);
		player->ADD_GOSSIP_ITEM(3, "Frisson glacial", GOSSIP_SENDER_MAIN, 1522);
		player->ADD_GOSSIP_ITEM(3, "Tueur de démons", GOSSIP_SENDER_MAIN, 1523);
		player->ADD_GOSSIP_ITEM(3, "Mangouste", GOSSIP_SENDER_MAIN, 1512);
		player->ADD_GOSSIP_ITEM(3, "Eruption de sort", GOSSIP_SENDER_MAIN, 1513);
		player->ADD_GOSSIP_ITEM(3, "Maître de guerre", GOSSIP_SENDER_MAIN, 1514);
		player->ADD_GOSSIP_ITEM(3, "2M - 25 agilité", GOSSIP_SENDER_MAIN, 1524);
		player->ADD_GOSSIP_ITEM(3, "2M - 70 puissance d'attaque", GOSSIP_SENDER_MAIN, 1525);
		player->ADD_GOSSIP_ITEM(3, "2M - 35 agilité", GOSSIP_SENDER_MAIN, 1526);
		player->ADD_GOSSIP_ITEM(3, "2M - 9 dégâts de l'arme", GOSSIP_SENDER_MAIN, 1527);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20009, creature->GetGUID());
		break;
// 1M
	case 1500:	enchid = 1900;				Ench(player, creature, item);	break;
	case 1501:	enchid = 2504;				Ench(player, creature, item);	break;
	case 1502:	enchid = 2563;				Ench(player, creature, item);	break;
	case 1503:	enchid = 2564;				Ench(player, creature, item);	break;
	case 1504:	enchid = 2567;				Ench(player, creature, item);	break;
	case 1505:	enchid = 2568;				Ench(player, creature, item);	break;
	case 1506:	enchid = 120;	reqil = 1;	Ench(player, creature, item);	break;
	case 1507:	enchid = 2666;	reqil = 1;	Ench(player, creature, item);	break;
	case 1508:	enchid = 2668;	reqil = 1;	Ench(player, creature, item);	break;
	case 1509:	enchid = 2669;	reqil = 1;	Ench(player, creature, item);	break;
	case 1510:	enchid = 2671;	reqil = 1;	Ench(player, creature, item);	break;
	case 1511:	enchid = 2672;	reqil = 1;	Ench(player, creature, item);	break;
	case 1512:	enchid = 2673;	reqil = 1;	Ench(player, creature, item);	break;
	case 1513:	enchid = 2674;	reqil = 1;	Ench(player, creature, item);	break;
	case 1514:	enchid = 2675;	reqil = 1;	Ench(player, creature, item);	break;
	case 1515:	enchid = 3846;	reqil = 1;	Ench(player, creature, item);	break;
	case 1516:	enchid = 2505;				Ench(player, creature, item);	break;
	case 1517:	enchid = 3222;	reqil = 1;	Ench(player, creature, item);	break;
	case 1518:	enchid = 1898;				Ench(player, creature, item);	break;
	case 1519:	enchid = 1899;				Ench(player, creature, item);	break;
	case 1520:	enchid = 803;				Ench(player, creature, item);	break;
	case 1521:	enchid = 118;				Ench(player, creature, item);	break;
	case 1522:	enchid = 1894;				Ench(player, creature, item);	break;
	case 1523:	enchid = 912;				Ench(player, creature, item);	break;
// 2M
	case 1524:	enchid = 2646;	twoha = 1;				Ench(player, creature, item);	break;
	case 1525:	enchid = 2667;	twoha = 1;	reqil = 1;	Ench(player, creature, item);	break;
	case 1526:	enchid = 2670;	twoha = 1;	reqil = 1;	Ench(player, creature, item);	break;
	case 1527:	enchid = 1895;	twoha = 1;				Ench(player, creature, item);	break;

// Boucliers
	case 18:
		slotid = 16;
		player->ADD_GOSSIP_ITEM(3, "18 endurance", GOSSIP_SENDER_MAIN, 1803);
		player->ADD_GOSSIP_ITEM(3, "12 inteligence", GOSSIP_SENDER_MAIN, 1804);
		player->ADD_GOSSIP_ITEM(3, "12 résilience", GOSSIP_SENDER_MAIN, 1800);
		player->ADD_GOSSIP_ITEM(3, "36 valeur de blacage", GOSSIP_SENDER_MAIN, 1801);
		player->ADD_GOSSIP_ITEM(3, "15 score de blocage", GOSSIP_SENDER_MAIN, 1802);
		player->ADD_GOSSIP_ITEM(3, "5 à toutes les résistances", GOSSIP_SENDER_MAIN, 1805);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20010, creature->GetGUID());
		break;
	case 1800:	enchid = 3229;	reqil = 1;	Ench(player, creature, item);	break;
	case 1801:	enchid = 2653;	reqil = 1;	Ench(player, creature, item);	break;
	case 1802:	enchid = 1985;	reqil = 1;	Ench(player, creature, item);	break;
	case 1803:	enchid = 1071;	reqil = 1;	Ench(player, creature, item);	break;
	case 1804:	enchid = 2654;	reqil = 1;	Ench(player, creature, item);	break;
	case 1805:	enchid = 1888;	reqil = 1;	Ench(player, creature, item);	break;
		
// Ranged
	case 17:	slotid = 17;	enchid = 663;	Ench(player, creature, item);	break;
	
		}
	return true; }
};

void AddSc_enchant_npc() {
	new enchant_npc(); }