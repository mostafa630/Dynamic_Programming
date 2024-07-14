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
float dp[6][4];
int H = 4;
int N = 3;

void study()
{
    for (int i = 0; i <= H; i++)// i--> H
    {
        for (int j = 0; j <= N-1; j++) // j-->N
        {
            if (j == 0) // there exist one subject to study in i hours
            {
                dp[i][j] = probs[i][j];
            }
            else if (i == 0) // there exist only 0 hours to study j subjects
            {
                float t = 1;
                for (int cnt = 0; cnt <= j; cnt++)
                {
                    t *= probs[i][cnt];
                }
                dp[i][j] = t;
            }
            else
            {
                float minFailureProb = INT_MAX;
                for (int cnt = 0; cnt <= i; cnt++)   
                {
                    float FailureProb = probs[cnt][j] * dp[i - cnt][j - 1];
                    minFailureProb = min(minFailureProb, FailureProb);
                }
                dp[i][j] = minFailureProb;
            }
        }
    }

}
int main() {
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> probs[i][j]; 
        }
    }
    study();
    cout<<dp[H][N-1]<<endl; // it contains the minium probability of failure.
}
