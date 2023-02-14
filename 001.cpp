#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

ll l, n ,k;
ll v[1 << 18];

bool solve(int mid)
{
    ll tmp = 0;
    ll cnt = 0;

    for(int i=0;i<=n;i++){
        if(tmp + v[i] < mid){
            tmp += v[i];
        }else{
            tmp = 0;
            cnt ++;
        }
    }
    if(tmp < mid){
        cnt --;
    }

    if(cnt >= k){
        return true;
    }else{
        return false;
    }
}

int main()
{a
    //入力
    cin >> n >> l >> k;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    //左端からの長さではなくそれぞれの長さに
    v[n] = l - v[n-1];
    for(int i=n-1;i>0;i--){
        v[i] -= v[i-1];
    }

    //二分探索
    int ok = 0; //解が存在する値
    int ng = l + 1; //解が存在しない値
    while(abs(ok-ng) > 1){
        int mid = (ok + ng) / 2;
        //solve関数を定義
        if(solve(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    //出力
    cout << ok << endl;

    return 0;
}