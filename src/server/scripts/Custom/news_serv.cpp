#include "ScriptPCH.h"

class news_serv : public CreatureScript {
public: news_serv() : CreatureScript("news_serv")	{}

bool OnGossipHello(Player *player, Creature * creature) {
	MainMenu(player, creature);
    return true; }

void MainMenu(Player *player, Creature *creature) {
	player->ADD_GOSSIP_ITEM(0, "- Les commandes", GOSSIP_SENDER_MAIN, 1);
	player->ADD_GOSSIP_ITEM(0, "- Le PvP sauvage", GOSSIP_SENDER_MAIN, 2);
	player->ADD_GOSSIP_ITEM(0, "- Les zones FFA", GOSSIP_SENDER_MAIN, 5);
	player->ADD_GOSSIP_ITEM(0, "- Le PvE", GOSSIP_SENDER_MAIN, 4);
	player->ADD_GOSSIP_ITEM(0, "- Une ouverture au monde ?", GOSSIP_SENDER_MAIN, 7);
	player->ADD_GOSSIP_ITEM(0, "- Ou sont les maitres de classe ?", GOSSIP_SENDER_MAIN, 3);
	player->ADD_GOSSIP_ITEM(0, "- Quelles recompenses ?", GOSSIP_SENDER_MAIN, 6);
	player->ADD_GOSSIP_ITEM(0, "<Quitter>", GOSSIP_SENDER_MAIN, 10);
	player->SEND_GOSSIP_MENU(1000007, creature->GetGUID()); }

bool OnGossipSelect(Player *player, Creature * creature, uint32 sender, uint32 action) {
    player->PlayerTalkClass->ClearMenus();

switch (action) {

	case 100:	MainMenu(player, creature);	break;
	
	case 1:
    player->ADD_GOSSIP_ITEM(0, "Voici les commandes qui vous sont accessible :", GOSSIP_SENDER_MAIN, 1);
    player->ADD_GOSSIP_ITEM(0, ".talent : equivalent gratuit d'une reinitialisation des talents aupres d'un maitre de classe.", GOSSIP_SENDER_MAIN, 1);
    player->ADD_GOSSIP_ITEM(0, ".arena : fenetre d'inscription en file d'attente d'arene.", GOSSIP_SENDER_MAIN, 1);
    player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 100);
	player->SEND_GOSSIP_MENU(1000007, creature->GetGUID());
	break;
	case 2:
    player->ADD_GOSSIP_ITEM(0, "Actuellement il se deroule au Cratere d'Azshara, le teleporteur au centre de la zone shop peut vous y emmener. Nous prevoyons de le favoriser plus tard au sein meme de Karazhan.", GOSSIP_SENDER_MAIN, 2);
    player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 100);
	player->SEND_GOSSIP_MENU(1000007, creature->GetGUID());
	break;
	case 3:
    player->ADD_GOSSIP_ITEM(0, "Il n'y en a pas. La biblioteque 'Maitre universel' vous ajoutera les rangs superieurs des sorts debloques avec vos talents. Elle pourra aussi vous enseigner la double specialisation des talents. Il est possible de reinitialiser vos talents avec la commande .talent.", GOSSIP_SENDER_MAIN, 3);
    player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 100);
	player->SEND_GOSSIP_MENU(1000007, creature->GetGUID());
	break;
	case 4:
    player->ADD_GOSSIP_ITEM(0, "Les donjons du niveau sont en train d'etre corriges. Le systeme de donjon aleatoire est foncionnel. Plusieurs world boss seront prochainement appeles a survenir au Cratere et a Karazhan, les recompenses seront mises a jour.", GOSSIP_SENDER_MAIN, 4);
    player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 100);
	player->SEND_GOSSIP_MENU(1000007, creature->GetGUID());
	break;
	case 5:
    player->ADD_GOSSIP_ITEM(0, "Plusieurs zones FFA seront accessibles a tour de role. Qu'une seule a la fois. Elles seront ensuite ameliorees, classees, supprimees pour certaines, et de nouvelles arriveront sans doutes plus tard. Tout cela en fonction de vos avis sur le forum)", GOSSIP_SENDER_MAIN, 5);
    player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 100);
	player->SEND_GOSSIP_MENU(1000007, creature->GetGUID());
	break;
	case 6:
    player->ADD_GOSSIP_ITEM(0, "Les recompenses d'honneur, arene, worldboss, FFA, journalieres et boutiques sont et resteront distinctes les unes des autres. (bien qu'elles ne soient pas encore vraiment fixees) Chaque mois les titres pour les premiers aux haut faits, arene et vh seront redistribues. De toutes les recompenses possible, la seule amelioration visible en termes de statistiques sera la vitesse des montures 100%.", GOSSIP_SENDER_MAIN, 6);
    player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 100);
	player->SEND_GOSSIP_MENU(1000007, creature->GetGUID());
	break;
	case 7:
    player->ADD_GOSSIP_ITEM(0, "Vous pouvez en tant que joueur sortir des zones personnalisees pour vous rendre en Azeroth. Cela semblait necessaire, car comment oser priver wow de son univers ? Cependant, en combat, un joueur qui s'y sera aventure n'aura aucun avantage sur les autres.", GOSSIP_SENDER_MAIN, 7);
    player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 100);
	player->SEND_GOSSIP_MENU(1000007, creature->GetGUID());
	break;
	case 10:
	player->CLOSE_GOSSIP_MENU();
	break;
} return true; } };

void AddSc_News_Serv() {
new news_serv(); }