#pragma once

#include <functional>

class Player;
class BlockPos;
class Vec3;
class ItemInstance;

class GameMode {
	public:
		virtual void useItemOn(Player&, ItemInstance&, const BlockPos&, signed char, const Vec3&);
};
