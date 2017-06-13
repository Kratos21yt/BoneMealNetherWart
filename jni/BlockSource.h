#pragma once

class BlockPos;
class FullBlock;
class Block;

class BlockSource {
	public:
	void setBlockAndData(int, int, int, FullBlock, int);
	Block* getBlock(BlockPos const&);
	void removeBlock(BlockPos const&);
	int getData(BlockPos const&);
};
