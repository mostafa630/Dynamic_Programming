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

int c1 = 564546, c2 = 564546, c3 = 564546;  //any big value
int FindMin()
{
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coinToChange; j >= 0; j--)
        {
            if (j == coinToChange)
                dp[i][j] = 0;
            else
            {
                if(i-1>=0)
                    c1 = dp[i - 1][j];
                if( j + coins[i] <=coinToChange && i>=0)
                    c2 = 1+dp[i][j + coins[i]];
                if( j + coins[i] <= coinToChange && i-1>=0)
                    c3 = 1+dp[i - 1][j +coins[i]];

                dp[i][j] = min({ c1 , c2 , c3});
            }
        }
    }
    return dp[coins.size()-1][0];
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
    dp.resize(size + 5, vector<int>(coinToChange + 200 ,5443));
    cout << "Minium of coins to change this Coin = ";

    cout << FindMin() << endl;
    
}
