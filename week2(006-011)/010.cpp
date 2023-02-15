#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;
int C;
int P[1<<18][2];

int main()
{
    cin >> N;

    P[0][0] = 0;
    P[0][1] = 0;

    for(int i=1;i<=N;i++){
        int tmp;
        cin >> C >> tmp;
        P[i][0] = P[i-1][0];
        P[i][1] = P[i-1][1];
        P[i][C-1] += tmp;
    }

    cin >> Q;
    for(int i=0;i<Q;i++){
        int L, R;
        cin >> L >> R;
        cout << P[R][0] - P[L-1][0] << ' ' << P[R][1] - P[L-1][1] << endl;
    }

    return 0;
}