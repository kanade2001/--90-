#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;

int main()
{
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);

    for(auto &i : A){
        cin >> i;
    }
    for(auto &i : B){
        cin >> i;
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    ll ans = 0;

    for(int i=0;i<N;i++){
        ans += abs(A[i] - B[i]);
    }

    cout << ans << endl;

    return 0;
}