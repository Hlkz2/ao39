#include "ScriptPCH.h"
#include "Chat.h"

int32 Choix(int32 item_id, int choix) {
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);
    if (!itemProto)
        return 0;
    if ((!itemProto->RandomProperty) && (!itemProto->RandomSuffix))
        return 0;
    if ((itemProto->RandomProperty) && (itemProto->RandomSuffix)) {
		sLog->outErrorDb("Item template %u : RandomProperty == %u et RandomSuffix == %u, un des deux champs doit être nul", itemProto->ItemId, itemProto->RandomProperty, itemProto->RandomSuffix);
        return 0; }
    if (itemProto->RandomProperty) {
        uint32 randomPropId = choix;
        ItemRandomPropertiesEntry const* random_id = sItemRandomPropertiesStore.LookupEntry(randomPropId);
        if (!random_id) {
            sLog->outErrorDb("L'id d'enchantement #%u est utilisé mais ne figure pas dans 'ItemRandomProperties.dbc'", randomPropId);
            return 0; }
        return random_id->ID; }
    else {
        uint32 randomPropId = choix;
        ItemRandomSuffixEntry const* random_id = sItemRandomSuffixStore.LookupEntry(randomPropId);
        if (!random_id) {
            sLog->outErrorDb("L'id d'enchantement #%u est utilisé mais ne figure pas dans sItemRandomSuffixStore.", randomPropId);
            return 0;  }
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

class com_rand : public CommandScript {
   public: com_rand() : CommandScript("comrand") { }

static bool HandleComRand(ChatHandler* handler, const char* args) {
	if (!*args) return false;
	
	char* item = strtok((char*)args, " ");
	char* ench = strtok(NULL, " ");
    int32 item_id = (int32)atof(item);
    int ench_id = (int)atof(ench);

	AddItemChoix(handler->GetSession()->GetPlayer(), item_id, ench_id);
	return true; }

ChatCommand* GetCommands() const {
	static ChatCommand ComRand[] = {
		{ "rand",          SEC_ADMINISTRATOR,	false, &HandleComRand,		"", NULL },
		{ NULL,             0,					false, NULL,				"", NULL } };
	return ComRand; }
};

void AddSc_Com_Rand() {
   new com_rand(); }