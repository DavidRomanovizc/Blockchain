#include "main.h"


int main() {
    // Start
    BlockChain Coin;

    // Data for first block
    time_t dataFirstTime;
    TransactionData dataFirst(1.5, "Joe", "Sally", time(&dataFirstTime));
    Coin.addBlock(dataFirst);

    time_t dataSecondTime;
    TransactionData dataSecond(0.3325, "Markus", "Frank", time(&dataSecondTime));
    Coin.addBlock(dataSecond);

    // Let's see how many coins are in the blockchain!
    Coin.printChain();

    // Check validity
    printf("\nIs chain still valid? %d\n", Coin.isChainValid());

    Block *hackBlock = Coin.getLatestBlock();
    hackBlock->data.amount = 10000;
    hackBlock->data.receiverKey = "Jon";

    // Look data
    Coin.printChain();

    // If is it not valid
    printf("\nIs chain still valid? %d\n", Coin.isChainValid());

    return 0;
}