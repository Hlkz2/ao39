#include "ScriptPCH.h"


class class_master : public CreatureScript
{
    public:
        class_master() : CreatureScript("class_master") { }

        bool OnGossipHello(Player* player, Creature* creature)
        { MainMenu(player, creature);
		return true; }
		
		void MainMenu(Player *player, Creature *creature)
		{
			player->ADD_GOSSIP_ITEM( 3, "Mise a niveau des sorts, stats et competences" , GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM( 2, "Apprentissage de la double specalisation" , GOSSIP_SENDER_MAIN, 2);
			player->ADD_GOSSIP_ITEM( 1, "Vendeur de glyphes" , GOSSIP_SENDER_MAIN, 3);
			player->ADD_GOSSIP_ITEM( 2, "Reinitialisation des talents" , GOSSIP_SENDER_MAIN, 4);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		}

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            if (player->isInCombat())
            {
                player->CLOSE_GOSSIP_MENU();
                creature->MonsterWhisper("Vous etes en combat !", player->GetGUID(), false);
                return false;
            }
		
				switch (action)
	            {
					case 1:
						player->CLOSE_GOSSIP_MENU();
						player->UpdateSkillsToMaxSkillsForLevel();
						if (player->HasSpell(17877)) {
						player->learnSpell(18868, true); } // brulure de l'ombre
						if (player->HasSpell(11366)) {
						player->learnSpell(12523, true); } // explosion pyrotechnique
						if (player->HasSpell(11113)) {
						player->learnSpell(13018, true); } // brulure
						if (player->HasSpell(5570)) {
						player->learnSpell(24974, true); } // essaim d'insecte
						if (player->HasSpell(19434)) {
						player->learnSpell(20901, true); } // visée
						if (player->HasSpell(15407)) {
						player->learnSpell(17312, true); } // fouet mental
						if (player->HasSpell(19236)) {
						player->learnSpell(19240, true); } // prière du désespoir
						creature->CastSpell(player,38588,false);
					break;

					case 2:
						player->CLOSE_GOSSIP_MENU();
						player->CastSpell(player, 63680, true);
						player->CastSpell(player, 63624, true);
					break;
					
					case 3:
						player->GetSession()->SendListInventory(creature->GetGUID());
					break;

	                case 30:
						if(player->getClass() == 1){    player->GetSession()->SendListInventory(999991); } // guerrier
						if(player->getClass() == 2){	player->GetSession()->SendListInventory(999992); } // paladin
						if(player->getClass() == 3){	player->GetSession()->SendListInventory(999993); } // chasseur
						if(player->getClass() == 4){	player->GetSession()->SendListInventory(999994); } // voleur
						if(player->getClass() == 5){	player->GetSession()->SendListInventory(999995); } // prêtre
						if(player->getClass() == 7){	player->GetSession()->SendListInventory(999996); } // chaman
						if(player->getClass() == 8){	player->GetSession()->SendListInventory(999997); } // mage
						if(player->getClass() == 9){	player->GetSession()->SendListInventory(999998); } // démoniste
						if(player->getClass() == 11){	player->GetSession()->SendListInventory(999999); } // druide
                    break;
					
					case 4:
						player->CLOSE_GOSSIP_MENU();
						player->resetTalents(true);
 						player->SendTalentsInfoData(false);
					break;

	            }
        }
};

void AddSc_CustomClass()
{
    new class_master;
}