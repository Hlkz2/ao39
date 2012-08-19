#include "ScriptPCH.h"

int* rie; std::string* ris; uint32 count; uint32 retour = 100; uint32 item_id = 0;

class rand_item2 : public CreatureScript {
	public: rand_item2() : CreatureScript("rand_item2") {}

int32 Choix(int32 item_id, int choix) {
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);
    if (!itemProto) return 0;
    if ((!itemProto->RandomProperty) && (!itemProto->RandomSuffix)) return 0;
    if ((itemProto->RandomProperty) && (itemProto->RandomSuffix)) return 0;
    if (itemProto->RandomProperty) {
        uint32 randomPropId = choix;
        ItemRandomPropertiesEntry const* random_id = sItemRandomPropertiesStore.LookupEntry(randomPropId);
        if (!random_id) return 0;
        return random_id->ID; }
    else {
        uint32 randomPropId = choix;
        ItemRandomSuffixEntry const* random_id = sItemRandomSuffixStore.LookupEntry(randomPropId);
        if (!random_id) return 0;
        return -int32(random_id->ID); } }

void AddItemChoix(Player *player, uint32 item_id, int choix) {
    uint32 noSpaceForCount = 0;
    ItemPosCountVec dest;
    InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item_id, 1, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)
    if (dest.empty()) {
        ChatHandler(player).PSendSysMessage("Vous n'avez plus de place.");
        return; }
		Item* item = player->StoreNewItem(dest, item_id, true, Choix(item_id, choix));
		if (item) player->SendNewItem(item, 1, true, false);
    return; }

void MainMenu(Player *player, Creature *creature) {
	player->ADD_GOSSIP_ITEM(6, "Rare...", GOSSIP_SENDER_MAIN, 150);
	player->ADD_GOSSIP_ITEM(6, "Marchandises utiles...", GOSSIP_SENDER_MAIN, 300);
	player->ADD_GOSSIP_ITEM(6, "Hors set...", GOSSIP_SENDER_MAIN, 200);
	player->ADD_GOSSIP_ITEM(6, "Régalien / Sombrebrume...", GOSSIP_SENDER_MAIN, 250);
	player->ADD_GOSSIP_ITEM(6, "Royal / Lunaire...", GOSSIP_SENDER_MAIN, 400);
	player->ADD_GOSSIP_ITEM(6, "Brigade / Capitaine...", GOSSIP_SENDER_MAIN, 550);
	player->ADD_GOSSIP_ITEM(6, "Chevaucheur / Forestier...", GOSSIP_SENDER_MAIN, 600);
	player->ADD_GOSSIP_ITEM(6, "Sorcier...", GOSSIP_SENDER_MAIN, 700);
	player->ADD_GOSSIP_ITEM(6, "Pisteur / Imposant...", GOSSIP_SENDER_MAIN, 800);
	player->ADD_GOSSIP_ITEM(6, "Ancien / De maille d'os...", GOSSIP_SENDER_MAIN, 900);
	player->ADD_GOSSIP_ITEM(6, "Veneur...", GOSSIP_SENDER_MAIN, 950);
	player->SEND_GOSSIP_MENU(1000023, creature->GetGUID()); }
	
bool OnGossipHello(Player *player, Creature * creature) { MainMenu(player, creature); return true; }
	
bool OnGossipSelect(Player *player, Creature * creature, uint32 sender, uint32 action) {
    player->PlayerTalkClass->ClearMenus();

		switch (action) {
	
	case 100: MainMenu(player, creature); break;

	case 101: player->CLOSE_GOSSIP_MENU(); break;
		
    case 150:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Garde-bras de Revelosh.", GOSSIP_SENDER_MAIN, 152);
        player->ADD_GOSSIP_ITEM(6, "Spallières de Revelosh.", GOSSIP_SENDER_MAIN, 153);
        player->ADD_GOSSIP_ITEM(6, "Gants de Revelosh.", GOSSIP_SENDER_MAIN, 154);
        player->ADD_GOSSIP_ITEM(6, "Poignets déterrés.", GOSSIP_SENDER_MAIN, 155);
        player->ADD_GOSSIP_ITEM(6, "Chevalière d'aigue marine.", GOSSIP_SENDER_MAIN, 156);
        player->ADD_GOSSIP_ITEM(6, "Brassards d'Ironaya.", GOSSIP_SENDER_MAIN, 157);
        player->ADD_GOSSIP_ITEM(6, "Lentille verte.", GOSSIP_SENDER_MAIN, 158);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 152: item_id = 9388; goto l276276; break;
	    case 153: item_id = 9389; goto l276276; break;
	    case 154: item_id = 9390; goto l276276; break;
	    case 155: item_id = 9428; goto l276276; break;
	    case 156: item_id = 20964; goto l276276; break;
	    case 157: item_id = 9409; goto l276276; break;
	    case 158: item_id = 10504; goto l276276; break;

    case 200:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Cape de tulle.", GOSSIP_SENDER_MAIN, 202);
        player->ADD_GOSSIP_ITEM(6, "Cape de champion.", GOSSIP_SENDER_MAIN, 203);
        player->ADD_GOSSIP_ITEM(6, "Cape de cabaliste.", GOSSIP_SENDER_MAIN, 204);
        player->ADD_GOSSIP_ITEM(6, "Cape tissee de sang.", GOSSIP_SENDER_MAIN, 205);
        player->ADD_GOSSIP_ITEM(6, "Brassards tisses de sang.", GOSSIP_SENDER_MAIN, 206);
        player->ADD_GOSSIP_ITEM(6, "Chapeau de noctambule.", GOSSIP_SENDER_MAIN, 207);
        player->ADD_GOSSIP_ITEM(6, "Targe inebranlable.", GOSSIP_SENDER_MAIN, 208);
        player->ADD_GOSSIP_ITEM(6, "Carabine de precision.", GOSSIP_SENDER_MAIN, 209);
        player->ADD_GOSSIP_ITEM(6, "Baguette de braise.", GOSSIP_SENDER_MAIN, 210);
        player->ADD_GOSSIP_ITEM(6, "Kriss sacrificiel.", GOSSIP_SENDER_MAIN, 211);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 202: item_id = 7524; goto l276276; break;
	    case 203: item_id = 7544; goto l276276; break;
	    case 204: item_id = 7533; goto l276276; break;
	    case 205: item_id = 14261; goto l276276; break;
	    case 206: item_id = 14260; goto l276276; break;
	    case 207: item_id = 15156; goto l276276; break;
	    case 208: item_id = 15592; goto l276276; break;
	    case 209: item_id = 3430; goto l276276; break;
	    case 210: item_id = 5215; goto l276276; break;
	    case 211: item_id = 3187; goto l276276; break;

    case 250:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Jambières Régaliennes", GOSSIP_SENDER_MAIN, 252);
        player->ADD_GOSSIP_ITEM(6, "Chapeau de sorcier Régalien.", GOSSIP_SENDER_MAIN, 253);
        player->ADD_GOSSIP_ITEM(6, "Gants Régaliens.", GOSSIP_SENDER_MAIN, 254);
        player->ADD_GOSSIP_ITEM(6, "Bottes Régaliennes.", GOSSIP_SENDER_MAIN, 255);
        player->ADD_GOSSIP_ITEM(6, "Mantelet Régalien.", GOSSIP_SENDER_MAIN, 256);
        player->ADD_GOSSIP_ITEM(6, "Cape Régalienne.", GOSSIP_SENDER_MAIN, 257);
        player->ADD_GOSSIP_ITEM(6, "Crispins Régaliens.", GOSSIP_SENDER_MAIN, 258);
        player->ADD_GOSSIP_ITEM(6, "Echarpe Régalienne.", GOSSIP_SENDER_MAIN, 259);
        player->ADD_GOSSIP_ITEM(6, "Etoile Régalienne.", GOSSIP_SENDER_MAIN, 260);
        player->ADD_GOSSIP_ITEM(6, "Chapeau de sorcier de Sombrebrume.", GOSSIP_SENDER_MAIN, 261);
        player->ADD_GOSSIP_ITEM(6, "Pantalon de Sombrebrume.", GOSSIP_SENDER_MAIN, 262);
        player->ADD_GOSSIP_ITEM(6, "Mantelet de Sombrebrume.", GOSSIP_SENDER_MAIN, 263);
        player->ADD_GOSSIP_ITEM(6, "Bottes de Sombrebrume.", GOSSIP_SENDER_MAIN, 264);
        player->ADD_GOSSIP_ITEM(6, "Garde-mains de Sombrebrume.", GOSSIP_SENDER_MAIN, 265);
        player->ADD_GOSSIP_ITEM(6, "Ceinturon de Sombrebrume.", GOSSIP_SENDER_MAIN, 266);
        player->ADD_GOSSIP_ITEM(6, "Poignets de Sombrebrume.", GOSSIP_SENDER_MAIN, 267);
        player->ADD_GOSSIP_ITEM(6, "Cape de Sombrebrume.", GOSSIP_SENDER_MAIN, 268);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 252: item_id = 7469; goto l276276; break;
		case 253: item_id = 7470; goto l276276; break;
	    case 254: item_id = 7471; goto l276276; break;
	    case 255: item_id = 7472; goto l276276; break;
	    case 256: item_id = 7473; goto l276276; break;
	    case 257: item_id = 7474; goto l276276; break;
	    case 258: item_id = 7475; goto l276276; break;
	    case 259: item_id = 7476; goto l276276; break;
	    case 260: item_id = 7555; goto l276276; break;
	    case 261: item_id = 14246; goto l276276; break;
	    case 262: item_id = 14242; goto l276276; break;
	    case 263: item_id = 14243; goto l276276; break;
	    case 264: item_id = 14238; goto l276276; break;
	    case 265: item_id = 14241; goto l276276; break;
	    case 266: item_id = 14245; goto l276276; break;
	    case 267: item_id = 14240; goto l276276; break;
	    case 268: item_id = 14239; goto l276276; break;

    case 300:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Collier tumultueux.", GOSSIP_SENDER_MAIN, 306);
        player->ADD_GOSSIP_ITEM(6, "Anneau tumultueux.", GOSSIP_SENDER_MAIN, 310);
        player->ADD_GOSSIP_ITEM(6, "Cape tumultueuse.", GOSSIP_SENDER_MAIN, 302);
        player->ADD_GOSSIP_ITEM(6, "Protege-mains denombres.", GOSSIP_SENDER_MAIN, 304);
        player->ADD_GOSSIP_ITEM(6, "Protege-épaules denombres.", GOSSIP_SENDER_MAIN, 308);
        player->ADD_GOSSIP_ITEM(6, "Foulard denombre.", GOSSIP_SENDER_MAIN, 311);
        player->ADD_GOSSIP_ITEM(6, "Garde-mains vigoureux.", GOSSIP_SENDER_MAIN, 303);
        player->ADD_GOSSIP_ITEM(6, "Spalières vigoureuses.", GOSSIP_SENDER_MAIN, 307);
        player->ADD_GOSSIP_ITEM(6, "Ceinture vigoureuse.", GOSSIP_SENDER_MAIN, 312);
        player->ADD_GOSSIP_ITEM(6, "Manicles liees a la terre.", GOSSIP_SENDER_MAIN, 305);
        player->ADD_GOSSIP_ITEM(6, "Garde-épaules lies a la terre.", GOSSIP_SENDER_MAIN, 309);
        player->ADD_GOSSIP_ITEM(6, "Ceinturon lies a la terre.", GOSSIP_SENDER_MAIN, 313);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 302: item_id = 51994; goto l276276; break;
	    case 303: item_id = 51965; goto l276276; break;
	    case 304: item_id = 51973; goto l276276; break;
	    case 305: item_id = 51980; goto l276276; break;
	    case 306: item_id = 51996; goto l276276; break;
	    case 307: item_id = 51966; goto l276276; break;
	    case 308: item_id = 51974; goto l276276; break;
		case 309: item_id = 51976; goto l276276; break;
	    case 310: item_id = 51992; goto l276276; break;
	    case 311: item_id = 51968; goto l276276; break;
	    case 312: item_id = 51964; goto l276276; break;
	    case 313: item_id = 51978; goto l276276; break;

    case 400:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Echarpe royale.", GOSSIP_SENDER_MAIN, 402);
        player->ADD_GOSSIP_ITEM(6, "Bottes royales.", GOSSIP_SENDER_MAIN, 403);
        player->ADD_GOSSIP_ITEM(6, "Cape royale.", GOSSIP_SENDER_MAIN, 404);
        player->ADD_GOSSIP_ITEM(6, "Poignets royaux.", GOSSIP_SENDER_MAIN, 405);
        player->ADD_GOSSIP_ITEM(6, "Gants royaux.", GOSSIP_SENDER_MAIN, 406);
        player->ADD_GOSSIP_ITEM(6, "Mantelet lunaire.", GOSSIP_SENDER_MAIN, 407);
        player->ADD_GOSSIP_ITEM(6, "Protege-mains lunaires.", GOSSIP_SENDER_MAIN, 408);
        player->ADD_GOSSIP_ITEM(6, "Mules lunaires.", GOSSIP_SENDER_MAIN, 409);
        player->ADD_GOSSIP_ITEM(6, "Manchettes lunaires.", GOSSIP_SENDER_MAIN, 410);
        player->ADD_GOSSIP_ITEM(6, "Ceinture lunaire.", GOSSIP_SENDER_MAIN, 411);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 402: item_id = 9906; goto l276276; break;
	    case 403: item_id = 9907; goto l276276; break;
	    case 404: item_id = 9908; goto l276276; break;
	    case 405: item_id = 9909; goto l276276; break;
	    case 406: item_id = 9910; goto l276276; break;
	    case 407: item_id = 14247; goto l276276; break;
	    case 408: item_id = 14253; goto l276276; break;
	    case 409: item_id = 14250; goto l276276; break;
	    case 410: item_id = 14248; goto l276276; break;
	    case 411: item_id = 14255; goto l276276; break;

    case 550:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Cuirasse de capitaine.", GOSSIP_SENDER_MAIN, 552);
        player->ADD_GOSSIP_ITEM(6, "Jambières de capitaine.", GOSSIP_SENDER_MAIN, 553);
        player->ADD_GOSSIP_ITEM(6, "Diademe de capitaine.", GOSSIP_SENDER_MAIN, 554);
        player->ADD_GOSSIP_ITEM(6, "Gantelets de capitaine.", GOSSIP_SENDER_MAIN, 555);
        player->ADD_GOSSIP_ITEM(6, "Bottes de capitaine.", GOSSIP_SENDER_MAIN, 556);
        player->ADD_GOSSIP_ITEM(6, "Garde-épaules de capitaine.", GOSSIP_SENDER_MAIN, 557);
        player->ADD_GOSSIP_ITEM(6, "Cape de capitaine.", GOSSIP_SENDER_MAIN, 558);
        player->ADD_GOSSIP_ITEM(6, "Brassards de capitaine.", GOSSIP_SENDER_MAIN, 559);
        player->ADD_GOSSIP_ITEM(6, "Sangle de capitaine.", GOSSIP_SENDER_MAIN, 560);
        player->ADD_GOSSIP_ITEM(6, "Targe de capitaine.", GOSSIP_SENDER_MAIN, 561);
        player->ADD_GOSSIP_ITEM(6, "Diademe de la brigade.", GOSSIP_SENDER_MAIN, 562);
        player->ADD_GOSSIP_ITEM(6, "Espauliers de la brigade.", GOSSIP_SENDER_MAIN, 563);
        player->ADD_GOSSIP_ITEM(6, "Bottes de la brigade.", GOSSIP_SENDER_MAIN, 564);
        player->ADD_GOSSIP_ITEM(6, "Gantelets de la brigade.", GOSSIP_SENDER_MAIN, 565);
        player->ADD_GOSSIP_ITEM(6, "Ceinturon de la brigade.", GOSSIP_SENDER_MAIN, 566);
        player->ADD_GOSSIP_ITEM(6, "Brassards de la brigade.", GOSSIP_SENDER_MAIN, 567);
        player->ADD_GOSSIP_ITEM(6, "Cape de la brigade.", GOSSIP_SENDER_MAIN, 568);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 552: item_id = 7486; goto l276276; break;
	    case 553: item_id = 7487; goto l276276; break;
	    case 554: item_id = 7488; goto l276276; break;
	    case 555: item_id = 7489; goto l276276; break;
		case 556: item_id = 7490; goto l276276; break;
	    case 557: item_id = 7491; goto l276276; break;
	    case 558: item_id = 7492; goto l276276; break;
	    case 559: item_id = 7493; goto l276276; break;
	    case 560: item_id = 7494; goto l276276; break;
	    case 561: item_id = 7495; goto l276276; break;
	    case 562: item_id = 9932; goto l276276; break;
	    case 563: item_id = 9934; goto l276276; break;
	    case 564: item_id = 9926; goto l276276; break;
	    case 565: item_id = 9930; goto l276276; break;
	    case 566: item_id = 9931; goto l276276; break;
	    case 567: item_id = 9927; goto l276276; break;
	    case 568: item_id = 9929; goto l276276; break;

    case 600:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Ceinture de chevaucheur de loup.", GOSSIP_SENDER_MAIN, 602);
        player->ADD_GOSSIP_ITEM(6, "Bottes de chevaucheur de loup.", GOSSIP_SENDER_MAIN, 603);
        player->ADD_GOSSIP_ITEM(6, "Cape de chevaucheur de loup.", GOSSIP_SENDER_MAIN, 604);
        player->ADD_GOSSIP_ITEM(6, "Gants de chevaucheur de loup.", GOSSIP_SENDER_MAIN, 605);
        player->ADD_GOSSIP_ITEM(6, "Jambières de chevaucheur de loup.", GOSSIP_SENDER_MAIN, 606);
        player->ADD_GOSSIP_ITEM(6, "Protege-épaules de chevaucheur...", GOSSIP_SENDER_MAIN, 607);
        player->ADD_GOSSIP_ITEM(6, "Protege-poignets de chevaucheur...", GOSSIP_SENDER_MAIN, 608);
        player->ADD_GOSSIP_ITEM(6, "Jambières de forestier.", GOSSIP_SENDER_MAIN, 609);
        player->ADD_GOSSIP_ITEM(6, "Casque de forestier.", GOSSIP_SENDER_MAIN, 610);
        player->ADD_GOSSIP_ITEM(6, "Bottes de forestier.", GOSSIP_SENDER_MAIN, 611);
        player->ADD_GOSSIP_ITEM(6, "Epaulieres de forestier.", GOSSIP_SENDER_MAIN, 612);
        player->ADD_GOSSIP_ITEM(6, "Gants de forestier.", GOSSIP_SENDER_MAIN, 613);
        player->ADD_GOSSIP_ITEM(6, "Garde-poignets de forestier.", GOSSIP_SENDER_MAIN, 614);
        player->ADD_GOSSIP_ITEM(6, "Corde de forestier.", GOSSIP_SENDER_MAIN, 615);
        player->ADD_GOSSIP_ITEM(6, "Cape de forestier.", GOSSIP_SENDER_MAIN, 616);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
	break;
	    case 602: item_id = 15369; goto l276276; break;
	    case 603: item_id = 15370; goto l276276; break;
	    case 604: item_id = 15371; goto l276276; break;
		case 605: item_id = 15372; goto l276276; break;
	    case 606: item_id = 15374; goto l276276; break;
	    case 607: item_id = 15375; goto l276276; break;
	    case 608: item_id = 15377; goto l276276; break;		
	    case 609: item_id = 7478; goto l276276; break;
	    case 610: item_id = 7479; goto l276276; break;
	    case 611: item_id = 7481; goto l276276; break;
	    case 612: item_id = 7482; goto l276276; break;
	    case 613: item_id = 7480; goto l276276; break;
	    case 614: item_id = 7484; goto l276276; break;
	    case 615: item_id = 7485; goto l276276; break;
	    case 616: item_id = 7483; goto l276276; break;

    case 700:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Drapé de sorcier.", GOSSIP_SENDER_MAIN, 702);
        player->ADD_GOSSIP_ITEM(6, "Sphere de sorcier.", GOSSIP_SENDER_MAIN, 703);
        player->ADD_GOSSIP_ITEM(6, "Robe de sorcier.", GOSSIP_SENDER_MAIN, 704);
        player->ADD_GOSSIP_ITEM(6, "Pantalon de sorcier.", GOSSIP_SENDER_MAIN, 705);
        player->ADD_GOSSIP_ITEM(6, "Chapeau de sorcier.", GOSSIP_SENDER_MAIN, 706);
        player->ADD_GOSSIP_ITEM(6, "Mantelet de sorcier.", GOSSIP_SENDER_MAIN, 707);
        player->ADD_GOSSIP_ITEM(6, "Mules de sorcier.", GOSSIP_SENDER_MAIN, 708);
        player->ADD_GOSSIP_ITEM(6, "Gants de sorcier.", GOSSIP_SENDER_MAIN, 709);
        player->ADD_GOSSIP_ITEM(6, "Echarpe de sorcier.", GOSSIP_SENDER_MAIN, 710);
        player->ADD_GOSSIP_ITEM(6, "Bracelets de sorcier.", GOSSIP_SENDER_MAIN, 711);
        player->ADD_GOSSIP_ITEM(6, "Cape de sorcier.", GOSSIP_SENDER_MAIN, 712);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 702: item_id = 9874; goto l276276; break;
	    case 703: item_id = 9882; goto l276276; break;
	    case 704: item_id = 9884; goto l276276; break;
	    case 705: item_id = 9883; goto l276276; break;
	    case 706: item_id = 9878; goto l276276; break;
	    case 707: item_id = 9881; goto l276276; break;
	    case 708: item_id = 9876; goto l276276; break;
	    case 709: item_id = 9880; goto l276276; break;
	    case 710: item_id = 9875; goto l276276; break;
	    case 711: item_id = 9879; goto l276276; break;
	    case 712: item_id = 9877; goto l276276; break;

    case 800:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Ceinture de pisteur.", GOSSIP_SENDER_MAIN, 802);
        player->ADD_GOSSIP_ITEM(6, "Bottes de pisteur.", GOSSIP_SENDER_MAIN, 803);
        player->ADD_GOSSIP_ITEM(6, "Gants de pisteur.", GOSSIP_SENDER_MAIN, 804);
        player->ADD_GOSSIP_ITEM(6, "Garde-poignets de pisteur.", GOSSIP_SENDER_MAIN, 805);
        player->ADD_GOSSIP_ITEM(6, "Cape de pisteur.", GOSSIP_SENDER_MAIN, 806);
        player->ADD_GOSSIP_ITEM(6, "Epaulieres imposantes.", GOSSIP_SENDER_MAIN, 807);
        player->ADD_GOSSIP_ITEM(6, "Ceinture imposante.", GOSSIP_SENDER_MAIN, 808);
        player->ADD_GOSSIP_ITEM(6, "Brassards imposants.", GOSSIP_SENDER_MAIN, 809);
        player->ADD_GOSSIP_ITEM(6, "Cape imposante.", GOSSIP_SENDER_MAIN, 810);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 802: item_id = 9916; goto l276276; break;
	    case 803: item_id = 9917; goto l276276; break;
	    case 804: item_id = 9920; goto l276276; break;
	    case 805: item_id = 9925; goto l276276; break;
	    case 806: item_id = 9919; goto l276276; break;
	    case 807: item_id = 15169; goto l276276; break;
	    case 808: item_id = 15161; goto l276276; break;
	    case 809: item_id = 15163; goto l276276; break;
	    case 810: item_id = 15165; goto l276276; break;

    case 900:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Grêves anciennes.", GOSSIP_SENDER_MAIN, 902);
        player->ADD_GOSSIP_ITEM(6, "Garde-jambes des anciens.", GOSSIP_SENDER_MAIN, 903);
        player->ADD_GOSSIP_ITEM(6, "Espauliers des anciens.", GOSSIP_SENDER_MAIN, 904);
        player->ADD_GOSSIP_ITEM(6, "Protege-bras anciens.", GOSSIP_SENDER_MAIN, 905);
        player->ADD_GOSSIP_ITEM(6, "Gantelets anciens.", GOSSIP_SENDER_MAIN, 906);
        player->ADD_GOSSIP_ITEM(6, "Cape ancienne.", GOSSIP_SENDER_MAIN, 907);
        player->ADD_GOSSIP_ITEM(6, "Ceinture ancienne.", GOSSIP_SENDER_MAIN, 908);
        player->ADD_GOSSIP_ITEM(6, "Gantelets de la maille d'os.", GOSSIP_SENDER_MAIN, 909);
        player->ADD_GOSSIP_ITEM(6, "Brassards de la maille d'os.", GOSSIP_SENDER_MAIN, 910);
        player->ADD_GOSSIP_ITEM(6, "Cape de la maille d'os.", GOSSIP_SENDER_MAIN, 911);
        player->ADD_GOSSIP_ITEM(6, "Ceinture de la maille d'os.", GOSSIP_SENDER_MAIN, 912);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 902: item_id = 15599; goto l276276; break;
	    case 903: item_id = 15607; goto l276276; break;
	    case 904: item_id = 15608; goto l276276; break;
	    case 905: item_id = 15600; goto l276276; break;
	    case 906: item_id = 15605; goto l276276; break;
	    case 907: item_id = 15603; goto l276276; break;
	    case 908: item_id = 15606; goto l276276; break;
	    case 909: item_id = 15612; goto l276276; break;
	    case 910: item_id = 15610; goto l276276; break;
	    case 911: item_id = 15611; goto l276276; break;
	    case 912: item_id = 15613; goto l276276; break;

    case 950:
        retour = action;
        player->ADD_GOSSIP_ITEM(6, "Bottes de veneur.", GOSSIP_SENDER_MAIN, 952);
        player->ADD_GOSSIP_ITEM(6, "Poignets de veneur.", GOSSIP_SENDER_MAIN, 953);
        player->ADD_GOSSIP_ITEM(6, "Armure de veneur.", GOSSIP_SENDER_MAIN, 954);
        player->ADD_GOSSIP_ITEM(6, "Bandeau de veneur.", GOSSIP_SENDER_MAIN, 955);
        player->ADD_GOSSIP_ITEM(6, "Cape de veneur.", GOSSIP_SENDER_MAIN, 956);
        player->ADD_GOSSIP_ITEM(6, "Ceinture de veneur.", GOSSIP_SENDER_MAIN, 957);
        player->ADD_GOSSIP_ITEM(6, "Gants de veneur.", GOSSIP_SENDER_MAIN, 958);
        player->ADD_GOSSIP_ITEM(6, "Jambières de veneur.", GOSSIP_SENDER_MAIN, 959);
        player->ADD_GOSSIP_ITEM(6, "Epaulieres de veneur.", GOSSIP_SENDER_MAIN, 960);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 952: item_id = 9885; goto l276276; break;
		case 953: item_id = 9886; goto l276276; break;
	    case 954: item_id = 9887; goto l276276; break;
	    case 955: item_id = 9889; goto l276276; break;
	    case 956: item_id = 9890; goto l276276; break;
	    case 957: item_id = 9891; goto l276276; break;
	    case 958: item_id = 9892; goto l276276; break;
	    case 959: item_id = 9893; goto l276276; break;
	    case 960: item_id = 9894; goto l276276; break;

l276276:
		case 9999:
			rie = RandItemEnch(item_id);
			if (rie[0] == 0) return true;
			ris = RandItemSuffix(item_id);

			lmenu:
			player->PlayerTalkClass->ClearMenus();
			for (count=0; count<=30; count++) {
			if (rie[count] && (rie[count] != 0)) {
				player->ADD_GOSSIP_ITEM(6, " " + ris[count], GOSSIP_SENDER_MAIN, 10001+count); } }
			player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, retour);
			player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
			break;

		case 10001: case 10002: case 10003: case 10004: case 10005: case 10006: case 10007: case 10008: case 10009: case 10010:
		case 10011: case 10012: case 10013: case 10014: case 10015: case 10016: case 10017: case 10018: case 10019: case 10020:
		case 10021: case 10022: case 10023: case 10024: case 10025: case 10026: case 10027: case 10028: case 10029: case 10030:

			AddItemChoix(player, item_id, rie[action-10001]);
			goto lmenu; break;
		}
	return true; }
};

void AddSc_rand_item2() {
	new rand_item2(); }