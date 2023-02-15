#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

int N;
string S;

int main()
{
    cin >> N >> S;
    
    string atcoder = "atcoder";
    vector<vector<ll>> dp(N+1, vector<ll>(7,0));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<7;j++){
            dp[i+1][j] = dp[i][j];
            if(j == 0 && S[i] == atcoder[0]){
                dp[i+1][0] ++;
            }else if(S[i] == atcoder[j]){
                dp[i+1][j] += dp[i][j-1];
            }
            dp[i+1][j] %= MOD;
        }
    }
    
    cout << dp[N][6] << endl;

    return 0;
}