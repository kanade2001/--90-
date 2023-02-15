#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<pair<ll, ll>> P;

double getangle(pair<ll, ll> A, pair<ll, ll> B)
{
    double dx = (double)(A.first - B.first);
    double dy = (double)(A.second - B.second);
    return atan2(dy, dx) * 180.0 / acos(-1) + 180.0;
}

double solve(pair<ll, ll> B)
{
    vector<double> v;
    for(auto &A : P){
        if(A == B) continue;
        v.push_back(getangle(A, B));
    }

    sort(v.begin(),v.end());

    double tmp = 0;

    for(auto &A : v){
        double target = A + 180.0;
        if(target > 360.0) target -= 360.0; 
        int i = lower_bound(v.begin(), v.end(), target) - v.begin();
        double a = 180.0 - abs(target - v[i]);
        double b = 180.0 - abs(target - v[(i - 1)%v.size()]);
        tmp = max(tmp, max(a, b));
    }

    return tmp;
}

int main()
{
    cin >> N;
    P.resize(N);
    for(auto &i : P){
        cin >> i.first >> i.second;
    }

    double ans = 0;

    for(auto &i : P){
        ans = max(ans, solve(i));
    }

    cout << setprecision(20) << ans << endl;

    return 0;
}