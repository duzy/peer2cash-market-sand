// Copyright (c) 2017 Duzy Chan <http://duzy.info>
//
#include "traderecord.h"

#include "base58.h"
#include "consensus/consensus.h"
#include "validation.h"
#include "timedata.h"
#include "wallet/wallet.h"

int TradeRecord::getOutputIndex() const
{
  return 0;
}

void TradeRecord::updateStatus(const CWalletTx &wtx)
{
}

bool TradeRecord::statusUpdateNeeded()
{
  return false;
}
