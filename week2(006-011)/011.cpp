#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<tuple<int, int, ll>> T;

int main()
{
    cin >> N;
    T.resize(N);
    for(int i=0;i<N;i++){
        int d, c;
        ll s;
        cin >> d >> c >> s;
        T[i] = {d, c, s};
    }
    sort(T.begin(),T.end());

    ll dp[5010][5010];
    dp[0][0] = 0;

    for(int i=0;i<N;i++){
        int &d = get<0>(T[i]);
        int &c = get<1>(T[i]);
        ll &s = get<2>(T[i]);

        for(int j=0;j<5001;j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j + c > d) continue;
            dp[i+1][j+c] = max(dp[i+1][j+c], dp[i][j] + s);
        }
        
    }

    ll ans = 0;
    for(int i=0;i<5001;i++){
        ans = max(ans, dp[N][i]);
    }

    cout << ans << endl;

    return 0;
}