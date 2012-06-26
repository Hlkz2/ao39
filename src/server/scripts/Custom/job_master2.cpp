#include "ScriptPCH.h"

class job_master2 : public CreatureScript
{
    public:
        job_master2() : CreatureScript("job_master2") { }


        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM( 0, "Cuisine." , GOSSIP_SENDER_MAIN, 200);
            player->ADD_GOSSIP_ITEM( 0, "Secourisme." , GOSSIP_SENDER_MAIN, 201);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
		}

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            if (player->isInCombat())
            {
                player->CLOSE_GOSSIP_MENU();
                creature->MonsterWhisper("Vous etes en combat!", player->GetGUID(), false);
                return false;
            }
		
			switch (action)
			{
				case 200:
				player->CLOSE_GOSSIP_MENU();
				player->learnSpell(51296, false);
				player->UpdateSkill(185, 450);
				break;
				case 201:
				player->CLOSE_GOSSIP_MENU();
				player->learnSpell(45542, false);
				player->UpdateSkill(129, 450);
				break;
			}
		}
};

void AddSc_Custom_Job2()
{
    new job_master2;
}