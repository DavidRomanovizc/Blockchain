
#include "../include/TransactionData.h"

#include <utility>


TransactionData::TransactionData(double amount, std::string senderKey, std::string receiverKey, time_t time_stamp)
        : amount(amount),
          senderKey(std::move(senderKey)),
          receiverKey(std::move(receiverKey)),
          time_stamp(time_stamp) {

}
