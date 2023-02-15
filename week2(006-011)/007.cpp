#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;

int main()
{
    cin >> N;
    vector<ll> A(N);
    for(auto &i : A){
        cin >> i;
    }
    cin >> Q;
    vector<ll> B(Q);
    for(auto &i : B){
        cin >> i;
    }

    sort(A.begin(),A.end());

    for(auto i : B){
        int ok = 0; //解が存在する値
        int ng = N; //解が存在しない値
        while(abs(ok-ng) > 1){
            int mid = (ok + ng) / 2;
            //solve関数を定義
            if(A[mid] <= i){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        if(ok == N - 1){
            cout << abs(i - A[ok]) << endl;
        }else{
            cout << min(abs(i - A[ok]), A[ok + 1] - i) << endl;
        }
    }
}