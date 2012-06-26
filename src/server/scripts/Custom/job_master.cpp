#include "ScriptPCH.h"

enum Spells
{
	SPELL_BS					= 9785,
	SPELL_JC					= 28895,
	SPELL_EN					= 13920,
	SPELL_AL					= 11611,
	SPELL_EG					= 12656,
	SPELL_IN					= 45360,
	SPELL_TA					= 12180,
	SPELL_MI					= 10248,
	SPELL_HE					= 11993,
	SPELL_LW					= 10662,
	SPELL_SK					= 10768,

	SKILL_BS					= 164,
	SKILL_JC					= 755,
	SKILL_EN					= 333,
	SKILL_AL					= 171,
	SKILL_EG					= 202,
	SKILL_IN					= 773,
	SKILL_TA					= 197,
	SKILL_MI					= 186,
	SKILL_HE					= 182,
	SKILL_LW					= 165,
	SKILL_SK					= 393
	
};

class job_master : public CreatureScript
{
    public:
        job_master() : CreatureScript("job_master") { }


        bool OnGossipHello(Player* player, Creature* creature)
        {
			player->ADD_GOSSIP_ITEM( 3, "Alchimie." , GOSSIP_SENDER_MAIN, 1000);
			player->ADD_GOSSIP_ITEM( 3, "Forge." , GOSSIP_SENDER_MAIN, 1001);
			player->ADD_GOSSIP_ITEM( 3, "Enchantement." , GOSSIP_SENDER_MAIN, 1002);
			player->ADD_GOSSIP_ITEM( 3, "Ingenierie." , GOSSIP_SENDER_MAIN, 1003);
			player->ADD_GOSSIP_ITEM( 3, "Herborisme." , GOSSIP_SENDER_MAIN, 1004);
			player->ADD_GOSSIP_ITEM( 3, "Calligraphie." , GOSSIP_SENDER_MAIN, 1005);
			player->ADD_GOSSIP_ITEM( 3, "Joaillerie." , GOSSIP_SENDER_MAIN, 1006);
			player->ADD_GOSSIP_ITEM( 3, "Travail du cuir." , GOSSIP_SENDER_MAIN, 1007);
			player->ADD_GOSSIP_ITEM( 3, "Minage" , GOSSIP_SENDER_MAIN, 1008);
			player->ADD_GOSSIP_ITEM( 3, "Depecage." , GOSSIP_SENDER_MAIN, 1009);
			player->ADD_GOSSIP_ITEM( 3, "Couture" , GOSSIP_SENDER_MAIN, 1010);
			player->ADD_GOSSIP_ITEM( 3, "Cuisine." , GOSSIP_SENDER_MAIN, 200);
			player->ADD_GOSSIP_ITEM( 3, "Secourisme" , GOSSIP_SENDER_MAIN, 201);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
		}

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            if (player->isInCombat())
            {
                player->CLOSE_GOSSIP_MENU();
                creature->MonsterWhisper("Vous �tes en combat !", player->GetGUID(), false);
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

			if (player->GetFreePrimaryProfessionPoints() >= 1)
			{
				switch (action)
	            {								
	                case 1000:
	                    player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_AL, false);
						player->UpdateSkill(SKILL_AL, 300);
	                    break;
					case 1001:
	                    player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_BS, false);
						player->UpdateSkill(SKILL_BS, 300);
	                    break;
					case 1002:
						player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_EN, false);
						player->UpdateSkill(SKILL_EN, 300);
						break;
					case 1003:
						player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_EG, false);
						player->UpdateSkill(SKILL_EG, 300);
						break;
					case 1004:
						player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_HE, false);
						player->learnSpell(55501, false);
						player->UpdateSkill(SKILL_HE, 300);
						break;
					case 1005:
						player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_IN, false);
						player->UpdateSkill(SKILL_IN, 300);
						break;
					case 1006:
						player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_JC, false);
						player->UpdateSkill(SKILL_JC, 300);
						break;
					case 1007:
						player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_LW, false);
						player->UpdateSkill(SKILL_LW, 300);
						break;
					case 1008:
						player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_MI, false);
						player->learnSpell(53123, false);
						player->UpdateSkill(SKILL_MI, 300);
						break;
					case 1009:
						player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_SK, false);
						player->learnSpell(53664, false);
						player->UpdateSkill(SKILL_SK, 300);
						break;
					case 1010:
						player->CLOSE_GOSSIP_MENU();
						player->learnSpell(SPELL_TA, false);
						player->UpdateSkill(SKILL_TA, 300);
						break;
	            }
			}
			else
			
				player->CLOSE_GOSSIP_MENU();
				creature->MonsterWhisper("Vous avez deja deux m�tiers !", player->GetGUID(), false);
		
            return true;
        }
};

void AddSc_Custom_Job()
{
    new job_master;
}