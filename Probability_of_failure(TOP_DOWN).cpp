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

#define ll long long 
  
float probs[5][3] = {0};
float dp[6][4] = {0};
float study(int H  , int N )
{
    if (dp[H][N] != 0) //check if the value os calculated before
        return dp[H][N];
    
    if(N == 0)
    {
        return dp[H][N] = probs[H][N]; // store the value and return it
    }
    else if (H == 0)
    {
        double t = 1;
        for (int i = 0; i <= N ; i++)
        {
            t *= probs[H][i];
        }
        return dp[H][N]= t; // store the value and return it
    }
    float minFailureProb = INT_MAX;
    for (int i = 0; i <= H; i++)
    {
        float failureProb = probs[i][N] * study(H-i , N-1);
        minFailureProb = min(minFailureProb, failureProb);
    } 
    return dp[H][N] = minFailureProb; // store the value and return it.
}

int main() {
    int N = 3, H = 4;
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> probs[i][j];
        }
    }
    cout << study(H, N-1) << endl;
}
