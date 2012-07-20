#include "ScriptPCH.h"

class rand_item : public CreatureScript {
	public: rand_item() : CreatureScript("rand_item"){}

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
	player->ADD_GOSSIP_ITEM(0, "Da test", GOSSIP_SENDER_MAIN, 1000);
	player->SEND_GOSSIP_MENU(1000009, creature->GetGUID()); }
	
bool OnGossipHello(Player *player, Creature * creature) { MainMenu(player, creature); return true; }
	
bool OnGossipSelect(Player *player, Creature * creature, uint32 sender, uint32 action) {

    player->PlayerTalkClass->ClearMenus();
		switch (action){
	
	case 100: MainMenu(player, creature); break;

	case 101: player->CLOSE_GOSSIP_MENU(); break;


/////////////////////// BLUE /////////////////////////////

l150 :
    case 150:
        player->ADD_GOSSIP_ITEM(6, "Garde-bras de Revelosh.", GOSSIP_SENDER_MAIN, 152);
        player->ADD_GOSSIP_ITEM(6, "Spalières de Revelosh.", GOSSIP_SENDER_MAIN, 153);
        player->ADD_GOSSIP_ITEM(6, "Gants de Revelosh.", GOSSIP_SENDER_MAIN, 154);
        player->ADD_GOSSIP_ITEM(6, "Poignets déterrés.", GOSSIP_SENDER_MAIN, 155);
        player->ADD_GOSSIP_ITEM(6, "Chevalière d'aigue marine.", GOSSIP_SENDER_MAIN, 156);
        player->ADD_GOSSIP_ITEM(6, "Brassards d'Ironaya.", GOSSIP_SENDER_MAIN, 157);
        player->ADD_GOSSIP_ITEM(6, "Lentille verte.", GOSSIP_SENDER_MAIN, 158);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 152: player->AddItem(9388, 1); goto l150; break;
	    case 153: player->AddItem(9389, 1); goto l150; break;
	    case 154: player->AddItem(9390, 1); goto l150; break;
	    case 155: player->AddItem(9428, 1); goto l150; break;
	    case 156: player->AddItem(20964, 1); goto l150; break;
	    case 157: player->AddItem(9409, 1); goto l150; break;
	    case 158: player->AddItem(10504, 1); goto l150; break;

/////////////////////// HS /////////////////////////////

l200 :
    case 200:
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 202: player->AddItem(7524, 1); goto l200; break;
	    case 203: player->AddItem(7544, 1); goto l200; break;
	    case 204: player->AddItem(7533, 1); goto l200; break;
	    case 205: player->AddItem(14261, 1); goto l200; break;
	    case 206: player->AddItem(14260, 1); goto l200; break;
	    case 207: player->AddItem(15156, 1); goto l200; break;
	    case 208: player->AddItem(15592, 1); goto l200; break;
	    case 209: player->AddItem(3430, 1); goto l200; break;
	    case 210: player->AddItem(5215, 1); goto l200; break;
	    case 211: player->AddItem(3187, 1); goto l200; break;
		
/////////////////////// RégaliEN/SOMBREBRUME /////////////////////////////

l250 :
    case 250:
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 252: player->AddItem(7469, 1); goto l250; break;
		case 253: player->AddItem(7470, 1); goto l250; break;
	    case 254: player->AddItem(7471, 1); goto l250; break;
	    case 255: player->AddItem(7472, 1); goto l250; break;
	    case 256: player->AddItem(7473, 1); goto l250; break;
	    case 257: player->AddItem(7474, 1); goto l250; break;
	    case 258: player->AddItem(7475, 1); goto l250; break;
	    case 259: player->AddItem(7476, 1); goto l250; break;
	    case 260: player->AddItem(7555, 1); goto l250; break;
	    case 261: player->AddItem(14246, 1); goto l250; break;
	    case 262: player->AddItem(14242, 1); goto l250; break;
	    case 263: player->AddItem(14243, 1); goto l250; break;
	    case 264: player->AddItem(14238, 1); goto l250; break;
	    case 265: player->AddItem(14241, 1); goto l250; break;
	    case 266: player->AddItem(14245, 1); goto l250; break;
	    case 267: player->AddItem(14240, 1); goto l250; break;
	    case 268: player->AddItem(14239, 1); goto l250; break;

/////////////////////// DJ ALEA /////////////////////////////

l300 :
    case 300:
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 302: player->AddItem(51994, 1); goto l300; break;
	    case 303: player->AddItem(51965, 1); goto l300; break;
	    case 304: player->AddItem(51973, 1); goto l300; break;
	    case 305: player->AddItem(51980, 1); goto l300; break;
	    case 306: player->AddItem(51996, 1); goto l300; break;
	    case 307: player->AddItem(51966, 1); goto l300; break;
	    case 308: player->AddItem(51974, 1); goto l300; break;
		case 309: player->AddItem(51976, 1); goto l300; break;
	    case 310: player->AddItem(51992, 1); goto l300; break;
	    case 311: player->AddItem(51968, 1); goto l300; break;
	    case 312: player->AddItem(51964, 1); goto l300; break;
	    case 313: player->AddItem(51978, 1); goto l300; break;
		
/////////////////////// ROYAL/LUNAIRE /////////////////////////////

l400 :
    case 400:
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 402: player->AddItem(9906, 1); goto l400; break;
	    case 403: player->AddItem(9907, 1); goto l400; break;
	    case 404: player->AddItem(9908, 1); goto l400; break;
	    case 405: player->AddItem(9909, 1); goto l400; break;
	    case 406: player->AddItem(9910, 1); goto l400; break;
	    case 407: player->AddItem(14247, 1); goto l400; break;
	    case 408: player->AddItem(14253, 1); goto l400; break;
	    case 409: player->AddItem(14250, 1); goto l400; break;
	    case 410: player->AddItem(14248, 1); goto l400; break;
	    case 411: player->AddItem(14255, 1); goto l400; break;

/////////////////////// BRIGADE CAPITAINE /////////////////////////////

l500 :
    case 550:
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 552: player->AddItem(7486, 1); goto l500; break;
	    case 553: player->AddItem(7487, 1); goto l500; break;
	    case 554: player->AddItem(7488, 1); goto l500; break;
	    case 555: player->AddItem(7489, 1); goto l500; break;
		case 556: player->AddItem(7490, 1); goto l500; break;
	    case 557: player->AddItem(7491, 1); goto l500; break;
	    case 558: player->AddItem(7492, 1); goto l500; break;
	    case 559: player->AddItem(7493, 1); goto l500; break;
	    case 560: player->AddItem(7494, 1); goto l500; break;
	    case 561: player->AddItem(7495, 1); goto l500; break;
	    case 562: player->AddItem(9932, 1); goto l500; break;
	    case 563: player->AddItem(9934, 1); goto l500; break;
	    case 564: player->AddItem(9926, 1); goto l500; break;
	    case 565: player->AddItem(9930, 1); goto l500; break;
	    case 566: player->AddItem(9931, 1); goto l500; break;
	    case 567: player->AddItem(9927, 1); goto l500; break;
	    case 568: player->AddItem(9929, 1); goto l500; break;

/////////////////////// CHEVAUCHEUR/FORESTIER /////////////////////////////

l600 :
    case 600:
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
	break;
	    case 602: player->AddItem(15369, 1); goto l600; break;
	    case 603: player->AddItem(15370, 1); goto l600; break;
	    case 604: player->AddItem(15371, 1); goto l600; break;
		case 605: player->AddItem(15372, 1); goto l600; break;
	    case 606: player->AddItem(15374, 1); goto l600; break;
	    case 607: player->AddItem(15375, 1); goto l600; break;
	    case 608: player->AddItem(15377, 1); goto l600; break;		
	    case 609: player->AddItem(7478, 1); goto l600; break;
	    case 610: player->AddItem(7479, 1); goto l600; break;
	    case 611: player->AddItem(7481, 1); goto l600; break;
	    case 612: player->AddItem(7482, 1); goto l600; break;
	    case 613: player->AddItem(7480, 1); goto l600; break;
	    case 614: player->AddItem(7484, 1); goto l600; break;
	    case 615: player->AddItem(7485, 1); goto l600; break;
	    case 616: player->AddItem(7483, 1); goto l600; break;

/////////////////////// SORCIER /////////////////////////////

l700 :
    case 700:
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 702: player->AddItem(9874, 1); goto l700; break;
	    case 703: player->AddItem(9882, 1); goto l700; break;
	    case 704: player->AddItem(9884, 1); goto l700; break;
	    case 705: player->AddItem(9883, 1); goto l700; break;
	    case 706: player->AddItem(9878, 1); goto l700; break;
	    case 707: player->AddItem(9881, 1); goto l700; break;
	    case 708: player->AddItem(9876, 1); goto l700; break;
	    case 709: player->AddItem(9880, 1); goto l700; break;
	    case 710: player->AddItem(9875, 1); goto l700; break;
	    case 711: player->AddItem(9879, 1); goto l700; break;
	    case 712: player->AddItem(9877, 1); goto l700; break;

/////////////////////// PISTEUR / IMPOSANT /////////////////////////////

l800 :
    case 800:
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 802: player->AddItem(9916, 1); goto l800; break;
	    case 803: player->AddItem(9917, 1); goto l800; break;
	    case 804: player->AddItem(9920, 1); goto l800; break;
	    case 805: player->AddItem(9925, 1); goto l800; break;
	    case 806: player->AddItem(9919, 1); goto l800; break;
	    case 807: player->AddItem(15169, 1); goto l800; break;
	    case 808: player->AddItem(15161, 1); goto l800; break;
	    case 809: player->AddItem(15163, 1); goto l800; break;
	    case 810: player->AddItem(15165, 1); goto l800; break;

/////////////////////// ANCIEN/MAILLE /////////////////////////////

l900 :
    case 900:
        player->ADD_GOSSIP_ITEM(6, "Greves anciennes.", GOSSIP_SENDER_MAIN, 902);
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 902: player->AddItem(15599, 1); goto l900; break;
	    case 903: player->AddItem(15607, 1); goto l900; break;
	    case 904: player->AddItem(15608, 1); goto l900; break;
	    case 905: player->AddItem(15600, 1); goto l900; break;
	    case 906: player->AddItem(15605, 1); goto l900; break;
	    case 907: player->AddItem(15603, 1); goto l900; break;
	    case 908: player->AddItem(15606, 1); goto l900; break;
	    case 909: player->AddItem(15612, 1); goto l900; break;
	    case 910: player->AddItem(15610, 1); goto l900; break;
	    case 911: player->AddItem(15611, 1); goto l900; break;
	    case 912: player->AddItem(15613, 1); goto l900; break;

/////////////////////// Veneur /////////////////////////////
l950 :
    case 950:
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
        player->SEND_GOSSIP_MENU(1000009, creature->GetGUID());
		break;
	    case 952: player->AddItem(9885, 1); goto l950; break;
		case 953: player->AddItem(9886, 1); goto l950; break;
	    case 954: player->AddItem(9887, 1); goto l950; break;
	    case 955: player->AddItem(9889, 1); goto l950; break;
	    case 956: player->AddItem(9890, 1);	goto l950; break;
	    case 957: player->AddItem(9891, 1); goto l950; break;
	    case 958: player->AddItem(9892, 1); goto l950; break;
	    case 959: player->AddItem(9893, 1); goto l950; break;
	    case 960: player->AddItem(9894, 1); goto l950; break;
		}
	return true; }
};

void AddSc_rand_item() {
	new rand_item(); }