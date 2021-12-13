#ifndef BLOCKCHANIN_BLOCKCHAIN_H
#define BLOCKCHANIN_BLOCKCHAIN_H

#include "../include/Block.h"
#include "../include/TransactionData.h"

class BlockChain {
private:
    static Block createGenesisBlock();

    std::vector<Block> chain;

public:
    BlockChain();

    std::vector<Block> getChain();

    Block *getLatestBlock();

    void addBlock(TransactionData data);

    bool isChainValid();

    void printChain();
};

#endif //BLOCKCHANIN_BLOCKCHAIN_H
