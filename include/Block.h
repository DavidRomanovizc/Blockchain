#ifndef BLOCKCHANIN_BLOCK_H
#define BLOCKCHANIN_BLOCK_H

#include "TransactionData.h"

class Block {
private:
    int index;
    size_t blockHash;
    size_t previousHash;

    size_t generatedHash() const;

public:
    Block(int index, TransactionData, size_t prevHash);

    int getIndex() const;

    size_t getHash() const;

    size_t getPreviousHash() const;

    TransactionData data;

    bool isHashValid();

};

#endif //BLOCKCHANIN_BLOCK_H
