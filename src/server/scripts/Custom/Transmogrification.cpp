/* v3.4 By Rochet2, custom by rph276

TODO:
Make DB saving even better (Deleting)? What about coding?
Fix the cost formula

TODO in the distant future:
Are the qualities right? Blizzard might have changed the quality requirements.
What can and cant be used as source or target..?

Cant transmogrify:
rediculus _items // Foereaper: would be fun to stab people with a fish
-- Cant think of any good way to handle this easily */

#include "ScriptPCH.h"

class NPC_Transmogrify : public CreatureScript {
public: NPC_Transmogrify() : CreatureScript("NPC_Transmogrify") {}

bool OnGossipHello(Player* player, Creature* creature) {
	WorldSession* session = player->GetSession();
	for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_TABARD; slot++) {// EQUIPMENT_SLOT_END
        if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot)) {
	    if (newItem->HasGoodFakeQuality()) {
			if (slot == 0 || slot == 2 || slot == 4 || slot == 6 || slot == 9) {
			if (const char* slotName = GetSlotName(slot, session))
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, slotName, EQUIPMENT_SLOT_END, slot); } } } }
//      player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, session->GetTrinityString(LANG_OPTION_REMOVE_ALL), EQUIPMENT_SLOT_END+2, 0, session->GetTrinityString(LANG_POPUP_REMOVE_ALL), 0, false);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, session->GetTrinityString(LANG_OPTION_UPDATE_MENU), EQUIPMENT_SLOT_END+1, 0);
        player->SEND_GOSSIP_MENU(1000022, creature->GetGUID());
        return true; }

bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 uiAction) {
	WorldSession* session = player->GetSession();
	player->PlayerTalkClass->ClearMenus();
			switch(sender) {
        case EQUIPMENT_SLOT_END: { // Show items you can use
			if (Item* oldItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, uiAction)) {
				uint32 lowGUID = player->GetGUIDLow();
				_items[lowGUID].clear();
				uint32 limit = 0;

				for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++) {
					if (limit > 30) break;
					if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i)) {
						if((newItem->GetTemplate()->ItemLevel == 60) && (newItem->GetTemplate()->RequiredLevel == 40)) {
							uint32 display = newItem->GetTemplate()->DisplayInfoID;
							if (player->SuitableForTransmogrification(oldItem, newItem) == ERR_FAKE_OK) {
								if (_items[lowGUID].find(display) == _items[lowGUID].end()) {
									limit++;
									_items[lowGUID][display] = newItem;
								    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, GetItemName(newItem, session), uiAction, display, session->GetTrinityString(LANG_POPUP_TRANSMOGRIFY)+GetItemName(newItem, session), 0, false);
								} } } } }

				for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++) {
			        if (Bag* bag = player->GetBagByPos(i))  {
	                for (uint32 j = 0; j < bag->GetBagSize(); j++) {
						if (limit > 30) break;
						if (Item* newItem = player->GetItemByPos(i, j)) {
							if((newItem->GetTemplate()->ItemLevel == 60) && (newItem->GetTemplate()->RequiredLevel == 40)) {
								uint32 display = newItem->GetTemplate()->DisplayInfoID;
								if (player->SuitableForTransmogrification(oldItem, newItem) == ERR_FAKE_OK) {
									if (_items[lowGUID].find(display) == _items[lowGUID].end()) {
										limit++;
										_items[lowGUID][display] = newItem;
										player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, GetItemName(newItem, session), uiAction, display, session->GetTrinityString(LANG_POPUP_TRANSMOGRIFY)+GetItemName(newItem, session), 0, false);
									} } } } } } }

                    char popup[250];
                    snprintf(popup, 250, session->GetTrinityString(LANG_POPUP_REMOVE_ONE), GetSlotName(uiAction, session));
					player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, session->GetTrinityString(LANG_OPTION_REMOVE_ONE), EQUIPMENT_SLOT_END+3, uiAction, popup, 0, false);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, session->GetTrinityString(LANG_OPTION_BACK), EQUIPMENT_SLOT_END+1, 0);
                    player->SEND_GOSSIP_MENU(1000022, creature->GetGUID());
                }
				else OnGossipHello(player, creature); }
			break;

	case EQUIPMENT_SLOT_END+1: OnGossipHello(player, creature); break;

	case EQUIPMENT_SLOT_END+2: { // Remove Transmogrifications
			bool removed = false;
			for (uint8 Slot = EQUIPMENT_SLOT_START; Slot < EQUIPMENT_SLOT_END; Slot++) {
		        if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, Slot)) {
	                if (newItem->DeleteFakeEntry() && !removed)
                        removed = true; } }
			if (removed) {
				session->SendAreaTriggerMessage(session->GetTrinityString(LANG_REM_TRANSMOGRIFICATIONS_ITEMS));
				player->PlayDirectSound(3337); }
			else session->SendNotification(session->GetTrinityString(LANG_ERR_NO_TRANSMOGRIFICATIONS));
			OnGossipHello(player, creature);
		} break;

        case EQUIPMENT_SLOT_END+3: { // Remove Transmogrification from single item
                if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, uiAction))
                {
                    if (newItem->DeleteFakeEntry()) {
                        session->SendAreaTriggerMessage(session->GetTrinityString(LANG_REM_TRANSMOGRIFICATION_ITEM));
                        player->PlayDirectSound(3337); }
                    else session->SendNotification(session->GetTrinityString(LANG_ERR_NO_TRANSMOGRIFICATION), GetSlotName(uiAction, session));
                }
                OnGossipSelect(player, creature, EQUIPMENT_SLOT_END, uiAction);
            } break;

        default: { // Transmogrify
			uint32 lowGUID = player->GetGUIDLow();
			if (Item* oldItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, sender)) {
				if (_items[lowGUID].find(uiAction) != _items[lowGUID].end() && _items[lowGUID][uiAction]->IsInWorld()) {
					Item* newItem = _items[lowGUID][uiAction];
					if (newItem->GetOwnerGUID() == player->GetGUIDLow() && (newItem->IsInBag() || newItem->GetBagSlot() == INVENTORY_SLOT_BAG_0) && player->SuitableForTransmogrification(oldItem, newItem) == ERR_FAKE_OK) {
                            oldItem->SetFakeEntry(newItem->GetEntry());
							player->DestroyItemCount(newItem->GetTemplate()->ItemId, 1, true, false);
                            player->PlayDirectSound(3337);
                            session->SendAreaTriggerMessage(session->GetTrinityString(LANG_ITEM_TRANSMOGRIFIED)); }
					else session->SendNotification(session->GetTrinityString(LANG_ERR_NO_ITEM_SUITABLE)); }
				else session->SendNotification(session->GetTrinityString(LANG_ERR_NO_ITEM_EXISTS)); }
			else session->SendNotification(session->GetTrinityString(LANG_ERR_EQUIP_SLOT_EMPTY));
			_items[lowGUID].clear();
			OnGossipSelect(player, creature, EQUIPMENT_SLOT_END, sender); } break;
				}
        return true; }

private: std::map<uint64, std::map<uint32, Item*> > _items; // _items[lowGUID][DISPLAY] = item

const char * GetSlotName(uint8 slot, WorldSession* session) {
   switch(slot) {
		case EQUIPMENT_SLOT_HEAD      : return session->GetTrinityString(LANG_SLOT_NAME_HEAD);
	    case EQUIPMENT_SLOT_SHOULDERS : return session->GetTrinityString(LANG_SLOT_NAME_SHOULDERS);
		case EQUIPMENT_SLOT_BODY      : return session->GetTrinityString(LANG_SLOT_NAME_BODY);
        case EQUIPMENT_SLOT_CHEST     : return session->GetTrinityString(LANG_SLOT_NAME_CHEST);
        case EQUIPMENT_SLOT_WAIST     : return session->GetTrinityString(LANG_SLOT_NAME_WAIST);
        case EQUIPMENT_SLOT_LEGS      : return session->GetTrinityString(LANG_SLOT_NAME_LEGS);
        case EQUIPMENT_SLOT_FEET      : return session->GetTrinityString(LANG_SLOT_NAME_FEET);
        case EQUIPMENT_SLOT_WRISTS    : return session->GetTrinityString(LANG_SLOT_NAME_WRISTS);
        case EQUIPMENT_SLOT_HANDS     : return session->GetTrinityString(LANG_SLOT_NAME_HANDS);
        case EQUIPMENT_SLOT_BACK      : return session->GetTrinityString(LANG_SLOT_NAME_BACK);
        case EQUIPMENT_SLOT_MAINHAND  : return session->GetTrinityString(LANG_SLOT_NAME_MAINHAND);
        case EQUIPMENT_SLOT_OFFHAND   : return session->GetTrinityString(LANG_SLOT_NAME_OFFHAND);
        case EQUIPMENT_SLOT_RANGED    : return session->GetTrinityString(LANG_SLOT_NAME_RANGED);
        case EQUIPMENT_SLOT_TABARD    : return session->GetTrinityString(LANG_SLOT_NAME_TABARD);
        default: return NULL; } }

std::string GetItemName(Item* item, WorldSession* session) {
	std::string name = item->GetTemplate()->Name1;
	int loc_idx = session->GetSessionDbLocaleIndex();
	if (loc_idx >= 0)
        if (ItemLocale const* il = sObjectMgr->GetItemLocale(item->GetEntry()))
		    ObjectMgr::GetLocaleString(il->Name, loc_idx, name);
	return name; }

};

void AddSC_NPC_Transmogrify() {
    new NPC_Transmogrify(); }