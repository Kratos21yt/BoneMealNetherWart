#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "GameMode.h"
#include "Player.h"
#include "ItemInstance.h"
#include "BlockSource.h"
#include "BlockPos.h"
#include "FullBlock.h"
#include "Vec3.h"
#include "Block.h"

void (*_useItemOn)(GameMode*, Player&, ItemInstance&, const BlockPos&, signed char, const Vec3&);
void useItemOn(GameMode* self, Player& player, ItemInstance& holdItem, const BlockPos& pos, signed char aux, const Vec3& _vec){
	int data = player.getRegion().getData(pos);
	if(holdItem.getId() == 351 && holdItem.getAuxValue() == 15){
		if(player.getRegion().getBlock(pos) == Block::mBlocks[115]){
			if(player.getRegion().getData(pos) == 3)
				return;
			if(!player.isCreative())
				holdItem.count--;
			player.getRegion().removeBlock(pos);
			player.getRegion().setBlockAndData(pos.x, pos.y, pos.z, {115, data + 1}, 3);
		}
	}
	_useItemOn(self, player, holdItem, pos, aux, _vec);
}

#define hook(a,b,c) MSHookFunction((void*)&a,(void*)&b,(void**)&c);

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	hook(GameMode::useItemOn,useItemOn,_useItemOn);
	return JNI_VERSION_1_2;
}
