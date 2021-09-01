// 6-8.cpp
// Created by 蓝同学 on 2021/8/16.
//
#include <iostream>
using namespace std;
void makechange(int coins[], int differentCoins, int maxChange){
    const int MAX = 100; // max change
    const int MAXCOINS = 10; // different types of coin.
    int coinUsed[MAX+1]; // use which type of coin
    int lastCoin[MAX+1]; //
    int coinNum[MAXCOINS]={0};
    coinUsed[0] = 0; // change 0 cent need 0 coin.
    for (int cents=1; cents<=maxChange; ++cents){ // test all probability of changes
        int minCoins = cents;
        int newCoin = 1;
        for (int j=0; j<differentCoins; ++j){ // test all probability of coins
            if(coins[j]>cents)
                continue;
            if(coinUsed[cents-coins[j]] + 1 < minCoins){
                minCoins = coinUsed[cents - coins[j]] + 1;
                newCoin = coins[j];
            }// end of second if
        } // end of second for
        coinUsed[cents] = minCoins; // record the min number of coins
        lastCoin[cents] = newCoin; // record the last coin used
    }// end of first for
}
int main(){

    return 0;
}

