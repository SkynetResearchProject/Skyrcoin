// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2020 The PIVX developers
// Copyright (c) 2021 The DECENOMY Core Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "chainparamsseeds.h"
#include "consensus/merkle.h"
#include "util.h"
#include "utilstrencodings.h"

#include <boost/assign/list_of.hpp>

#include <assert.h>

#define DISABLED 0x7FFFFFFE;

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock.SetNull();
    genesis.nVersion = nVersion;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of the genesis coinbase cannot
 * be spent as it did not originally exist in the database.
 *
 * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
 *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
 *   vMerkleTree: e0028e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    //const char* pszTimestamp = "Uniswap flips Bitcoin on daily revenue... and it’s more impressive than you think, 12/05/2021, COINTELEGRAPH";
    //const CScript genesisOutputScript = CScript() << ParseHex("04f8e575ae6a7fcf97b4cb8b213a74b550ccbdb4cabff3d0bfe9ec15f5b863be758acb3aead94933428425dd5e934dced26f022c0b33682b4ebf5fdce242bbe0f6") << OP_CHECKSIG;
	
    const char* pszTimestamp = "New blockchain is presented for swap. Timestamp. 2022-01-31.17:27:08 GMT";
    const CScript genesisOutputScript = CScript() << ParseHex("04cc00d92924dcaf49e3bc507535a60b4596b0f589d32a7b49868754a812653c8abcdeadcb907bff04dd8e4f690f98b98f0c9df02cee2e1f35342ca6fa791efa61") << OP_CHECKSIG;
	
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}


static CBlock CreateGenesisBlocktest(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "New blockchain is presented for swap. Timestamp. 2022-01-24.03:51:03 GMT";
    const CScript genesisOutputScript = CScript() << ParseHex("04cc00d92924dcaf49e3bc507535a60b4596b0f589d32a7b49868754a812653c8abcdeadcb907bff04dd8e4f690f98b98f0c9df02cee2e1f35342ca6fa791efa61") << OP_CHECKSIG;
	
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}


static CBlock CreateGenesisBlockreg(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "New blockchain is presented for swap. Timestamp. 2022-01-24.03:51:03 GMT";
    const CScript genesisOutputScript = CScript() << ParseHex("04cc00d92924dcaf49e3bc507535a60b4596b0f589d32a7b49868754a812653c8abcdeadcb907bff04dd8e4f690f98b98f0c9df02cee2e1f35342ca6fa791efa61") << OP_CHECKSIG;
	
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}


/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
	(0, uint256S("0x0000067136024464e0622d0ffdac12d98e14a36e78ad27323c3f5c2c98854a75"))     // Genesis
    //(10, uint256S("00000369ae74370c0132b5ccd379b60967478378af8647751ea4d3a784c3683f"))
; 

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1643673600, // * UNIX timestamp of last checkpoint block  01/02/2022 00:00:00
    1,          // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the UpdateTip debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
    (0, uint256S("0x0"));

static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1642996263,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of
    (0, uint256S("0x0"));

static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1642996263,
    0,
    100};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";

	/*
	// >>>>>  wrang calculation
        // // This is used inorder to mine the genesis block. Once found, we can use the nonce and block hash found to create a valid genesis block
        // /////////////////////////////////////////////////////////////////
	 
         uint32_t nGenesisTime = 1620820532;

         arith_uint256 test;
         bool fNegative;
         bool fOverflow;
         test.SetCompact(0x1e0ffff0, &fNegative, &fOverflow);
         std::cout << "Test threshold: " << test.GetHex() << "\n\n";

         int genesisNonce = 0;
         uint256 TempHashHolding = uint256S("0x0000000000000000000000000000000000000000000000000000000000000000");

         uint256 BestBlockHash = uint256S("0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
	
         for (int i=0;i<40000000;i++) {
             genesis = CreateGenesisBlock(nGenesisTime, i, 0x1e0ffff0, 1, 0 * COIN);
             genesis.hashPrevBlock = TempHashHolding;
             consensus.hashGenesisBlock = genesis.GetHash();

             arith_uint256 BestBlockHashArith = UintToArith256(BestBlockHash);
             if (UintToArith256(consensus.hashGenesisBlock) < BestBlockHashArith) {
                 BestBlockHash = consensus.hashGenesisBlock;
                 std::cout << BestBlockHash.GetHex() << " Nonce: " << i << "\n";
                 std::cout << "   PrevBlockHash: " << genesis.hashPrevBlock.GetHex() << "\n";
             }

             TempHashHolding = consensus.hashGenesisBlock;

             if (BestBlockHashArith < test) {
                 genesisNonce = i - 1;
                 break;
             }
             std::cout << consensus.hashGenesisBlock.GetHex() << "\n";
         }
         std::cout << "\n";
         std::cout << "\n";
         std::cout << "\n";

         std::cout << "hashGenesisBlock to 0x" << BestBlockHash.GetHex() << std::endl;
         std::cout << "Genesis Nonce to " << genesisNonce << std::endl;
         std::cout << "Genesis Merkle 0x" << genesis.hashMerkleRoot.GetHex() << std::endl;
	 //*/
         //exit(0);

         /////////////////////////////////////////////////////////////////// 580458  my=122968




/*
	//-----------------------------------------------------------------------------------------------------------------
        //// v1 calc
        ////Epoch timestamp: 1643650028
        ////: Mon, 31 Jan 2022 17:27:08 GMT
        genesis = CreateGenesisBlock(1643650028, 540000, 0x1e0ffff0, 1, 0 * COIN);


        // calculate Genesis Block
        // Reset genesis
        consensus.hashGenesisBlock = uint256S("0x");
        std::cout << std::string("Begin calculating Mainnet Genesis Block:\n");
	if (true && (genesis.GetHash() != consensus.hashGenesisBlock)) {
            //LogPrintf("Calculating Mainnet Genesis Block:\n"); //error: segmentation fault error
	    std::cout << std::string("Calculating Mainnet Genesis Block:\n");
            arith_uint256 hashTarget = arith_uint256().SetCompact(genesis.nBits);
            uint256 hash;
            genesis.nNonce = 0;
            // This will figure out a valid hash and Nonce if you're
            // creating a different genesis block:
            // uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
            // hashTarget.SetCompact(genesis.nBits, &fNegative, &fOverflow).getuint256();
            // while (genesis.GetHash() > hashTarget)

            while (UintToArith256(genesis.GetHash()) > hashTarget)
            {
                ++genesis.nNonce;
                if (genesis.nNonce == 0)
                {
                    //LogPrintf("NONCE WRAPPED, incrementing time"); //error: segmentation fault error
                    std::cout << std::string("NONCE WRAPPED, incrementing time:\n");
                    ++genesis.nTime;
                }
                if (genesis.nNonce % 10000 == 0)
                {
                    //LogPrintf("Mainnet: nonce %08u: hash = %s \n", genesis.nNonce, genesis.GetHash().ToString().c_str());
                     std::cout << strNetworkID << " nonce: " << genesis.nNonce << " time: " << genesis.nTime << " hash: " << genesis.GetHash().ToString().c_str() << "\n";
                }
            }

            std::cout << strNetworkID << "---\n";
            std::cout << "  nonce: " << genesis.nNonce <<  "\n";
            std::cout << "   time: " << genesis.nTime << "\n";
            std::cout << "   hash: " << genesis.GetHash().ToString().c_str() << "\n";
            std::cout << "   merklehash: "  << genesis.hashMerkleRoot.ToString().c_str() << "\n";
        }
        std::cout << std::string("Finished calculating Mainnet Genesis Block:\n");

	consensus.hashGenesisBlock = genesis.GetHash();


	//main---
	//nonce: 798999
	//time: 1643650028
	//hash: 0000067136024464e0622d0ffdac12d98e14a36e78ad27323c3f5c2c98854a75
	//merklehash: dc83aa655857885fd62ea0df12b48d65de1b0f88e11764763c157dc94dc7d878
	//-------------------------------------------------------------------------------------------------------------------------
//*/















	// v2 mainnet

        genesis = CreateGenesisBlock(1643650028, 798999, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256S("0x0000067136024464e0622d0ffdac12d98e14a36e78ad27323c3f5c2c98854a75"));
        assert(genesis.hashMerkleRoot == uint256S("0xdc83aa655857885fd62ea0df12b48d65de1b0f88e11764763c157dc94dc7d878"));

        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.powLimit   = ~UINT256_ZERO >> 20;   
        consensus.posLimitV1 = ~UINT256_ZERO >> 24;
        consensus.posLimitV2 = ~UINT256_ZERO >> 20;
        consensus.nBudgetCycleBlocks = 30 * 24 * 60;    // approx. 1 every 30 days
        consensus.nBudgetFeeConfirmations = 7;          // Number of confirmations for the finalization fee
        consensus.nCoinbaseMaturity = 100;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMasternodeCountDrift = 20;           // num of MN we allow the see-saw payments to be off by
        consensus.nMaxMoneyOut = 100000000 * COIN;      // total num
        consensus.nPoolMaxTransactions = 3;
        consensus.nProposalEstablishmentTime = 60 * 60 * 24;    // must be at least a day old to make it into a budget
        consensus.nStakeMinAge = 60 * 60; // 1h
        consensus.nStakeMinDepth = 100;
        consensus.nStakeMinDepthV2 = 600;
        consensus.nTargetTimespan = 40 * 60;
        consensus.nTargetTimespanV2 = 30 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;

        // spork keys addr=BJbx3LbxYCKFfGpSFf7qGyrTAdogWQ9BGi
        consensus.strSporkPubKey = "02082669fd794cdf741372fd3363700f91bba949e9497c1c7a0f974fc8e17ac07c";
        consensus.strSporkPubKeyOld = "02082669fd794cdf741372fd3363700f91bba949e9497c1c7a0f974fc8e17ac07c";
        consensus.nTime_EnforceNewSporkKey = 0;
        consensus.nTime_RejectOldSporkKey = 0;

        // height-based activations
        consensus.height_last_ZC_AccumCheckpoint    = DISABLED;
        consensus.height_last_ZC_WrappedSerials     = DISABLED;
        consensus.height_start_InvalidUTXOsCheck    = DISABLED;
        consensus.height_start_ZC_InvalidSerials    = DISABLED;
        consensus.height_start_ZC_SerialRangeCheck  = DISABLED;
        consensus.height_ZC_RecalcAccumulators      = DISABLED;

        // Zerocoin-related params
        consensus.ZC_Modulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
                "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
                "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
                "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
                "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
                "31438167899885040445364023527381951378636564391212010397122822120720357";
        consensus.ZC_MaxPublicSpendsPerTx = 637;    // Assume about 220 bytes each input
        consensus.ZC_MaxSpendsPerTx = 7;            // Assume about 20kb each input
        consensus.ZC_MinMintConfirmations = 20;
        consensus.ZC_MinMintFee = 1 * CENT;
        consensus.ZC_MinStakeDepth = 200;
        consensus.ZC_TimeStart = 1642996263;        // (GMT): 2022-01-24.03:51:03 GMT
        consensus.ZC_WrappedSerialsSupply = 0;      // zerocoin supply at height_last_ZC_WrappedSerials

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight                  = Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight             = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight                   = 251; //1001;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight                = 1441;
        consensus.vUpgrades[Consensus::UPGRADE_ZC].nActivationHeight                    = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].nActivationHeight                 = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight                 = 1441;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_PUBLIC].nActivationHeight             = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].nActivationHeight                  = 1541;
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].nActivationHeight                  = 1641;
        consensus.vUpgrades[Consensus::UPGRADE_V5_DUMMY].nActivationHeight              = 1741;
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MIN_DEPTH_V2].nActivationHeight    = 5001;

        /*
        consensus.vUpgrades[Consensus::UPGRADE_ZC].hashActivationBlock                  = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].hashActivationBlock               = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].hashActivationBlock               = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_ZC_PUBLIC].hashActivationBlock           = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].hashActivationBlock                = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].hashActivationBlock                = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_V5_DUMMY].hashActivationBlock            = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MIN_DEPTH_V2].hashActivationBlock  = uint256S("0x0");
        */
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x53;  //ok
        pchMessageStart[1] = 0x4b;
        pchMessageStart[2] = 0x59;
        pchMessageStart[3] = 0x52;
        nDefaultPort = PORT_MAINNET;

        vFixedSeeds.clear();
        vSeeds.clear();


        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 25); // byte 37h - префикс перед ripmd160 hash
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 28); // byte76h
        base58Prefixes[STAKING_ADDRESS] = std::vector<unsigned char>(1, 63);// starting with 'S'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 153);    // byte 99h - префикс перед секретной экспонентой приватного ключа
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x2D)(0x02)(0x31)(0x33).convert_to_container<std::vector<unsigned char> >();  // as is
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x25)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x03)(0x48).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));
        //convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main)); // added
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }

};
static CMainParams mainParams;

/**
 * Testnet (v1)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";





/*
	//-------------------------------------------------------------------------------------------------------------------------
	// v1 calc
	// Mon,24 Jan 2022,  2022-01-24.03:51:03 GMT
        genesis = CreateGenesisBlocktest(1642996263, 540000, 0x1e0ffff0, 1, 0 * COIN);

        // calculate Genesis Block
        // Reset genesis
        consensus.hashGenesisBlock = uint256S("0x");
        std::cout << std::string("Begin calculating Testnnet Genesis Block:\n");
	if (true && (genesis.GetHash() != consensus.hashGenesisBlock)) {
            //LogPrintf("Calculating Mainnet Genesis Block:\n"); //error: segmentation fault error
	    std::cout << std::string("Calculating Testnet Genesis Block:\n");
            arith_uint256 hashTarget = arith_uint256().SetCompact(genesis.nBits);
            uint256 hash;
            genesis.nNonce = 540000; //0;
            // This will figure out a valid hash and Nonce if you're
            // creating a different genesis block:
            // uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
            // hashTarget.SetCompact(genesis.nBits, &fNegative, &fOverflow).getuint256();
            // while (genesis.GetHash() > hashTarget)

            while (UintToArith256(genesis.GetHash()) > hashTarget)
            {
                ++genesis.nNonce;
                if (genesis.nNonce == 0)
                {
                    //LogPrintf("NONCE WRAPPED, incrementing time"); //error: segmentation fault error
                    std::cout << std::string("NONCE WRAPPED, incrementing time:\n");
                    ++genesis.nTime;

                }

                if (genesis.nNonce % 10000 == 0)
                {
                    //LogPrintf("Mainnet: nonce %08u: hash = %s \n", genesis.nNonce, genesis.GetHash().ToString().c_str());
                     std::cout << strNetworkID << " nonce: " << genesis.nNonce << " time: " << genesis.nTime << " hash: " << genesis.GetHash().ToString().c_str() << "\n";
                }
            }


            std::cout << strNetworkID << "---\n";
            std::cout << "  nonce: " << genesis.nNonce <<  "\n";
            std::cout << "   time: " << genesis.nTime << "\n";
            std::cout << "   hash: " << genesis.GetHash().ToString().c_str() << "\n";
            std::cout << "   merklehash: "  << genesis.hashMerkleRoot.ToString().c_str() << "\n";
            
        }
        std::cout << std::string("Finished calculating Mainnet Genesis Block:\n");

	consensus.hashGenesisBlock = genesis.GetHash();

	//Testnet ---0
	// nonce: 958781
	// time: 1642996263
	// hash: 00000018d8b262ec1838bd6208766922f463259d627cb3c8032238c34de052fe
	// merklehash: cb69d3038562ace578527296cdedd1205a4dafd09ffefc30ecc96d3e4576d68e
 

	//-------------------------------------------------------------------------------------------------------------------------

	//*/






	// v2 testnet
	// Mon,24 Jan 2022,  2022-01-24.03:51:03 GMT
        genesis = CreateGenesisBlocktest(1642996263, 958781, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256S("0x00000018d8b262ec1838bd6208766922f463259d627cb3c8032238c34de052fe"));
        assert(genesis.hashMerkleRoot == uint256S("0xcb69d3038562ace578527296cdedd1205a4dafd09ffefc30ecc96d3e4576d68e"));

        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.powLimit   = ~UINT256_ZERO >> 20; // skyrcoin starting difficulty is 1 / 2^12
        consensus.posLimitV1 = ~UINT256_ZERO >> 24;
        consensus.posLimitV2 = ~UINT256_ZERO >> 20;
        consensus.nBudgetCycleBlocks = 144;         // approx 10 cycles per day
        consensus.nBudgetFeeConfirmations = 3;      // (only 8-blocks window for finalization on testnet)
        consensus.nCoinbaseMaturity = 15;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMasternodeCountDrift = 4;        // num of MN we allow the see-saw payments to be off by
        consensus.nMaxMoneyOut = 100000000 * COIN;  // total num
        consensus.nPoolMaxTransactions = 2;
        consensus.nProposalEstablishmentTime = 60 * 5;  // at least 5 min old to make it into a budget
        consensus.nStakeMinAge = 60 * 60;
        consensus.nStakeMinDepth = 100;
        consensus.nStakeMinDepthV2 = 200;
        consensus.nTargetTimespan = 40 * 60;
        consensus.nTargetTimespanV2 = 30 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;

        // spork keys
        // spork keys compressed addr=mxE7sFPJVpwn4ftnE6iCPkJ25S63dgNvox//skyrcoin
        consensus.strSporkPubKey = "04a9543289c134e23cf6e393accf8a93b9d5edaff46ec2ec13f87d32ed9d1e34dbd4179531f0bf916a339a75cb03d556f16320874c89e08504df5eb3f34d91d96f";  //skyrcoin
        consensus.strSporkPubKeyOld = "04a9543289c134e23cf6e393accf8a93b9d5edaff46ec2ec13f87d32ed9d1e34dbd4179531f0bf916a339a75cb03d556f16320874c89e08504df5eb3f34d91d96f";
        consensus.nTime_EnforceNewSporkKey = 0;
        consensus.nTime_RejectOldSporkKey = 0;

        // height based activations
        consensus.height_last_ZC_AccumCheckpoint    = 999999999;
        consensus.height_last_ZC_WrappedSerials     = 999999999;
        consensus.height_start_InvalidUTXOsCheck    = 999999999;
        consensus.height_start_ZC_InvalidSerials    = 999999999;
        consensus.height_start_ZC_SerialRangeCheck  = 999999999;
        consensus.height_ZC_RecalcAccumulators      = 999999999;

        // Zerocoin-related params
        consensus.ZC_Modulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
                "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
                "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
                "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
                "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
                "31438167899885040445364023527381951378636564391212010397122822120720357";
        consensus.ZC_MaxPublicSpendsPerTx = 637;    // Assume about 220 bytes each input
        consensus.ZC_MaxSpendsPerTx = 7;            // Assume about 20kb each input
        consensus.ZC_MinMintConfirmations = 20;
        consensus.ZC_MinMintFee = 1 * CENT;
        consensus.ZC_MinStakeDepth = 200;
        consensus.ZC_TimeStart = 1642996263;
        consensus.ZC_WrappedSerialsSupply = 0;   // WrappedSerials only on main net

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight                  = Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight             = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight                   = 201;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight                = 1441;
        consensus.vUpgrades[Consensus::UPGRADE_ZC].nActivationHeight                    = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].nActivationHeight                 = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight                 = 1441;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_PUBLIC].nActivationHeight             = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].nActivationHeight                  = 1541;
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].nActivationHeight                  = 1641;
        consensus.vUpgrades[Consensus::UPGRADE_V5_DUMMY].nActivationHeight              = 1741;
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MIN_DEPTH_V2].nActivationHeight    = 1841;

        consensus.vUpgrades[Consensus::UPGRADE_ZC].hashActivationBlock                  = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].hashActivationBlock               = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].hashActivationBlock               = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_ZC_PUBLIC].hashActivationBlock           = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].hashActivationBlock                = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].hashActivationBlock                = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_V5_DUMMY].hashActivationBlock            = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MIN_DEPTH_V2].hashActivationBlock  = uint256S("0x0");

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */

        pchMessageStart[0] = 0x54;  //ok
        pchMessageStart[1] = 0x45;
        pchMessageStart[2] = 0x53;
        pchMessageStart[3] = 0x54;
        nDefaultPort = PORT_TESTNET;

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
		
		// Testnet  -ok
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 111);    // Testnet skyrcoin addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);    // Testnet skyrcoin script addresses start with '8' or '9'
	    base58Prefixes[STAKING_ADDRESS] = std::vector<unsigned char>(1, 73);    // starting with 'W'        
	    base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);        // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet skyrcoin BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();  //as is
        // Testnet skyrcoin BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet skyrcoin BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;




/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";

	// nonce: 958781
	// time: 1642996263
	// hash: 00000018d8b262ec1838bd6208766922f463259d627cb3c8032238c34de052fe
	// merklehash: cb69d3038562ace578527296cdedd1205a4dafd09ffefc30ecc96d3e4576d68e
 

	// v2 regtest
	// Mon,24 Jan 2022,  2022-01-24.03:51:03 GMT
        genesis = CreateGenesisBlockreg(1642996263, 958781, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256S("0x00000018d8b262ec1838bd6208766922f463259d627cb3c8032238c34de052fe"));
        assert(genesis.hashMerkleRoot == uint256S("0xcb69d3038562ace578527296cdedd1205a4dafd09ffefc30ecc96d3e4576d68e"));


        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.powLimit   = ~UINT256_ZERO >> 20; // skyrcoin starting difficulty is 1 / 2^12
        consensus.posLimitV1 = ~UINT256_ZERO >> 24;
        consensus.posLimitV2 = ~UINT256_ZERO >> 20;
        consensus.nBudgetCycleBlocks = 144;         // approx 10 cycles per day
        consensus.nBudgetFeeConfirmations = 3;      // (only 8-blocks window for finalization on regtest)
        consensus.nCoinbaseMaturity = 100;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMasternodeCountDrift = 4;        // num of MN we allow the see-saw payments to be off by
        consensus.nMaxMoneyOut = 100000000 * COIN;  // total num
        consensus.nPoolMaxTransactions = 3;
        consensus.nProposalEstablishmentTime = 60 * 5;  // at least 5 min old to make it into a budget
        consensus.nStakeMinAge = 0;
        consensus.nStakeMinDepth = 2;
        consensus.nTargetTimespan = 40 * 60;
        consensus.nTargetTimespanV2 = 600;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;

        /* Spork Key for RegTest:
        compressed addr=mkKuf6Bb2MSEbzhLaeCxBifVqZeB2bD1M1
        */
        consensus.strSporkPubKey = "04b7e691a9166383a2b92a26b15a9b4a61dd4071ca7d4a0e14d6439b4a147a880bc0cf4e63edffb6dceecd852ce65aa75aa7205f447b74c502adb6b9aa8c279854";
        consensus.strSporkPubKeyOld = "04b7e691a9166383a2b92a26b15a9b4a61dd4071ca7d4a0e14d6439b4a147a880bc0cf4e63edffb6dceecd852ce65aa75aa7205f447b74c502adb6b9aa8c279854";
        consensus.nTime_EnforceNewSporkKey = 0;
        consensus.nTime_RejectOldSporkKey = 0;

        // height based activations
        consensus.height_last_ZC_AccumCheckpoint    = DISABLED;     // no checkpoints on regtest
        consensus.height_last_ZC_WrappedSerials     = DISABLED;
        consensus.height_start_InvalidUTXOsCheck    = DISABLED;
        consensus.height_start_ZC_InvalidSerials    = DISABLED;
        consensus.height_start_ZC_SerialRangeCheck  = DISABLED;
        consensus.height_ZC_RecalcAccumulators      = DISABLED;

        // Zerocoin-related params
        consensus.ZC_Modulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
                "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
                "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
                "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
                "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
                "31438167899885040445364023527381951378636564391212010397122822120720357";
        consensus.ZC_MaxPublicSpendsPerTx = 637;    // Assume about 220 bytes each input
        consensus.ZC_MaxSpendsPerTx = 7;            // Assume about 20kb each input
        consensus.ZC_MinMintConfirmations = 10;
        consensus.ZC_MinMintFee = 1 * CENT;
        consensus.ZC_MinStakeDepth = 10;
        consensus.ZC_TimeStart = 0;                 // not implemented on regtest
        consensus.ZC_WrappedSerialsSupply = 0;

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight                  = Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight             = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight                   = 251;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight                = 1441;
        consensus.vUpgrades[Consensus::UPGRADE_ZC].nActivationHeight                    = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].nActivationHeight                 = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight                 = 1441;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_PUBLIC].nActivationHeight             = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].nActivationHeight                  = 1541;
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].nActivationHeight                  = 1641;
        consensus.vUpgrades[Consensus::UPGRADE_V5_DUMMY].nActivationHeight              = 1741;
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MIN_DEPTH_V2].nActivationHeight    = 5001;

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */

        pchMessageStart[0] = 0x52;
        pchMessageStart[1] = 0x45;
        pchMessageStart[2] = 0x47;
        pchMessageStart[3] = 0x54;
        nDefaultPort = PORT_REGTEST;

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }

    void UpdateNetworkUpgradeParameters(Consensus::UpgradeIndex idx, int nActivationHeight)
    {
        assert(idx > Consensus::BASE_NETWORK && idx < Consensus::MAX_NETWORK_UPGRADES);
        consensus.vUpgrades[idx].nActivationHeight = nActivationHeight;
    }
};
static CRegTestParams regTestParams;

static CChainParams* pCurrentParams = 0;

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}

void UpdateNetworkUpgradeParameters(Consensus::UpgradeIndex idx, int nActivationHeight)
{
    regTestParams.UpdateNetworkUpgradeParameters(idx, nActivationHeight);
}
