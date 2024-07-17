 //#----------------------------------------> بسم الله <------------------------------------------------#//


#include <iostream>
using namespace std;
#include<deque>
#include<cmath>
#include<vector>
#include<set>
#include<unordered_map>
#include <iomanip> 
#include<map>
#include<algorithm>

vector<int>coins;
int coinToChange;
vector<vector<int>>dp;
int FindMin(int index, int sum)
{
    if (dp[index][sum] != -1)
        return dp[index][sum];
    if (sum > coinToChange)
        return  dp[index][sum]=(coinToChange +1); // (coinChange+1) is the value it impossible to return because
                                                  // the worst cases is to get teh coin from ones only.
    if (sum == coinToChange) 
        return dp[index][sum]=0;
    if (index >= coins.size())
        return dp[index][sum]=(coinToChange + 1);

    //choice1 : leave it and go to next one
    int choice1 = FindMin(index + 1, sum);
    //choice2 : take it and go to same one
    int choice2 = 1 + FindMin(index, sum + coins[index]);
    //choice 3 : take it and go to next one
    int choice3 = 1 + FindMin(index + 1, sum + coins[index]);
    return dp[index][sum]=min({ choice1,choice2,choice3});
}
int main() {
    cout << "please enter the number of coins : ";
    int size;
    cin >> size;
    cout << "please enter theses coins and make the first value = 1 : \n";
    coins.resize(size);
    for (int& i : coins)
        cin >> i;
    cout << "please enter the Coin To Change : ";
    cin >> coinToChange;
    dp.resize(size + 1, vector<int>(coinToChange + 200 ,-1));
    cout << "Minium of coins to change this Coin = ";
    cout<<FindMin(0, 0);
}
