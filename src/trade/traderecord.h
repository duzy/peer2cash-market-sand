// Copyright (c) 2017 Duzy Chan <http://duzy.info>                           -*- c++ -*-
//
#ifndef BITCOIN_ZMQ_TRADE_RECORD_H
#define BITCOIN_ZMQ_TRADE_RECORD_H
#include "amount.h"
#include "uint256.h"

class CWallet;
class CWalletTx;

class TradeStatus
{
public:
  TradeStatus() {
  }

  enum Status {
    Confirmed,          /**< Have 6 or more confirmations (normal tx) or fully mature (mined tx) **/
    /// Normal (sent/received) transactions
    OpenUntilDate,      /**< Transaction not yet final, waiting for date */
    OpenUntilBlock,     /**< Transaction not yet final, waiting for block */
    Offline,            /**< Not sent to any other nodes **/
    Unconfirmed,        /**< Not yet mined into a block **/
    Confirming,         /**< Confirmed, but waiting for the recommended number of confirmations **/
    Conflicted,         /**< Conflicts with other transaction or mempool **/
    Abandoned,          /**< Abandoned from the wallet **/
  };
};

class TradeRecord
{
public:
  enum Type {
    NormalTx,
    BuyOffer,
    SellOffer,
  };

  static const int RequiredNumConfirmations = 3; // 3~6
  
  TradeRecord() : type(NormalTx) {
  }

  Type type;
  uint256 hash;
  //qint64 time;
  CAmount debit;
  CAmount credit;
  std::string address;

  /** Status: can change with block chain update */
  TradeStatus status;

  /** Return the output index of the subtransaction  */
  int getOutputIndex() const;

  /** Update status from core wallet tx.
   */
  void updateStatus(const CWalletTx &wtx);

  /** Return whether a status update is needed.
   */
  bool statusUpdateNeeded();
};

#endif//BITCOIN_ZMQ_TRADE_RECORD_H
