#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
string S;

int main()
{
    cin >> N >> K >> S;

    vector<vector<int>> v(N + 1, vector<int>(26, 1<<18));

    for(int i=N-1;i>=0;i--){
        for(int j=0;j<26;j++){
            v[i][j] = v[i+1][j];
            if((char)(j +(int)'a') == S[i]){
                v[i][j] = i;
            }
        }
    }

    string ans;
    for(int i=0;i<N;i++){
        int right = S.size() - (K - ans.size());
        for(int j=0;j<26;j++){
            if(v[i][j] <= right){
                i = v[i][j];
                ans += (char)j + 97;
                break;
            }
        }
        if(ans.size() == K){
            break;
        }
    }

    cout << ans << endl;

    return 0;
}