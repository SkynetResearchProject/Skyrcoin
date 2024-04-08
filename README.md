# Skynet Research Project Wallet

Forked from peony 4.0.0.1.

## Coin Specs

- PoW Algorithm: X11KVS
- Premine: 15.000.000 SKYR
- Max. Supply: 10.000.000.000 SKYR
- PoW Blocks: 1 - 250
- PoS Blocks: Starting from 251
- MN Blocks: Starting from 5001
- Block Time: 60 Seconds
- Maturity: 100 Confirmations
- Prefix: SKYR addresses start with the capital letter "B" or "C"
- Cold Staker Prefix: addresses start with the capital letter "S"
- Ports: 16888 (p2p) / 16890 (rpc)
- Explorer [explorer.skynet-coin.com]    (http://185.104.248.5 or http://185.104.248.5:3002)
- Website [https://skynet-coin.com]

## Rewards Breakdown

 ------------------------------------------------------------------------------------------------------
|    Block   | Collateral | Block Reward  | MN Reward % | Staking Reward % | MN Reward | Staker Reward |
| ---------- | ---------- | ------------- | ----------- | ---------------- | --------- | ------------- |
|      1     |     \-     | 15,000,000    | \-          | \-               | \-        | \-            |
|      2     |     \-     | 5.0           | \-          | \-               | \-        | \-            |
|    251     | 400,000    | 5.0           | \-          | 100              | \-        | 5.0           |
|    5,001   | 400,000    | 5.0           | 80          | 20               | 4.0       | 1.0           |
|    100,001 | 400,000    | 4.0           | 80          | 20               | 3.2       | 0.8           |
|    200,001 | 400,000    | 3.0           | 80          | 20               | 2.4       | 0.6           |
|    300,001 | 400,000    | 2.0           | 80          | 20               | 1.6       | 0.4           |
|    400,000 | 400,000    | 100.0         | 80          | 20               | 80.0      | 20.0          |
|    400,001 | 400,000    | 2.0           | 80          | 20               | 1.6       | 0.4           |
|    500,000 | 400,000    | 100.0         | 80          | 20               | 80.0      | 20.0          |
|    500,001 | 400,000    | 1.0           | 80          | 20               | 0.8       | 0.2           |
|    600,000 | 400,000    | 100.00        | 80          | 20               | 80.0      | 20.0          |
|    600,001 | 400,000    | 0.5           | 80          | 20               | 0.4       | 0.1           |
|  1,000,001 | 400,000    | 10.0          | 80          | 20               | 8.0       | 2.0           |
|  2,000,001 | 400,000    | 5.0           | 80          | 20               | 4.0       | 1.0           |
|  4,000,001 | 400,000    | 2.5           | 80          | 20               | 2.0       | 0.5           |
|  6,000,001 | 400,000    | 1.25          | 80          | 20               | 1.0       | 0.2           |
|  8,000,001 | 400,000    | 0.63          | 80          | 20               | 0.5       | 0.1           |
| 10,000,001 | 400,000    | 0.32          | 80          | 20               | 0.256     | 0.064         |
---

## Notes

v2.0.0.9-cs mandatory update. It is highly recommended to update your wallet.

It includes the following improvements:
 Added Cold Staking features  (from PIVX v4.3.0, same code from QRAX).

Synchronization will be disabled in wallets version 2.0.0.8 after Cold Staking is enabled and the first CS reward block is created.
For more information see topic <a href="https://forum.pivx.org/threads/a-pivx-cold-staking-how-to.745/">A PIVX Cold Staking How-To</a>
Set staking=1 and coldstaking=1 in file skyrcoin.conf of staker wallet (this needs to be online 24/7). 
Own Staker wallet balance can be zero.
