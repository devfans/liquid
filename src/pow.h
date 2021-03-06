// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_POW_H
#define BITCOIN_POW_H

#include "consensus/params.h"
#include "primitives/bitcoin/block.h"

#include <stdint.h>
#include <string>

class CBlockHeader;
class CBlockIndex;
class CProof;
class CScript;
class CWallet;
class uint256;

/** Check whether a block hash satisfies the proof-of-work requirement specified by nBits */
bool CheckBitcoinProof(uint256 hash, unsigned int nBits);
bool CheckProof(const CBlockHeader& block, const Consensus::Params&);
void ResetProof(CBlockHeader& block);
bool CheckChallenge(const CBlockHeader& block, const CBlockIndex& indexLast, const Consensus::Params&);
void ResetChallenge(CBlockHeader& block, const CBlockIndex& indexLast, const Consensus::Params&);

bool MaybeGenerateProof(CBlockHeader* pblock, CWallet* pwallet);
CScript CombineBlockSignatures(const CBlockHeader& header, const CScript& scriptSig1, const CScript& scriptSig2);

#endif // BITCOIN_POW_H
