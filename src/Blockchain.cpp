#include "../include/Blockchain.h"

BlockChain::BlockChain() {
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

std::vector<Block> BlockChain::getChain() {
    return chain;
}

Block BlockChain::createGenesisBlock() {
    std::time_t current;

    TransactionData d(0, "Genesis", "Genesis", time(&current));

    Block genesis(0, d, 0);
    return genesis;
}

Block *BlockChain::getLatestBlock() {
    return &chain.back();
}

void BlockChain::addBlock(TransactionData data) {
    int index = (int) chain.size();
    std::size_t previousHash = (int) chain.size() > 0 ? getLatestBlock()->getHash() : 0;
    Block newBlock(index, std::move(data), previousHash);
    chain.push_back(newBlock);
}

bool BlockChain::isChainValid() {
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it) {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
            return false;

        if (it != chain.begin()) {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getHash())
                return false;
        }
    }
    return true;
}

void BlockChain::printChain() {
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it) {
        Block currentBlock = *it;
        printf("\n\nBlock ===================================");
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nAmount: %f", currentBlock.data.amount);
        printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
        printf("\nReceiverKey: %s", currentBlock.data.receiverKey.c_str());
        printf("\nTimestamp: %ld", currentBlock.data.time_stamp);
        printf("\nHash: %zu", currentBlock.getHash());
        printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
        printf("\nIs Block Valid?: %d", currentBlock.isHashValid());
    }
}


