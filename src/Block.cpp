#include "../include/Block.h"


Block::Block(int idx, TransactionData d, size_t prevHash) {
    index = idx;
    data = std::move(d);
    previousHash = prevHash;
    blockHash = generatedHash();
}

int Block::getIndex() const {
    return index;
}

size_t Block::generatedHash() const {
    // creating string of transaction data
    std::string toHashS = std::to_string(data.amount) + data.receiverKey + std::to_string(data.time_stamp);

    // combine two hashes
    std::hash<std::string> tDataHash; // hashes transaction data string
    std::hash<std::string> prevHash; // re-hashes previous hash for combination

    // combine hashes and get size_t for block hash
    return tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1);
}

size_t Block::getHash() const {
    return blockHash;
}

size_t Block::getPreviousHash() const {
    return previousHash;
}

bool Block::isHashValid() {
    return generatedHash() == getHash();
}


