#ifndef BLOCKCHANIN_TRANSACTIONDATA_H
#define BLOCKCHANIN_TRANSACTIONDATA_H

#include <ctime>
#include <vector>
#include <string>
#include <cstddef>
#include <cstdio>


struct TransactionData {
    double amount{};
    std::string senderKey;
    std::string receiverKey;
    time_t time_stamp{};

    TransactionData() = default;

    TransactionData(double amount, std::string senderKey, std::string receiverKey, time_t time_stamp);


};


#endif //BLOCKCHANIN_TRANSACTIONDATA_H
