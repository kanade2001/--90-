#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

int H, W;
ll A[1<<11][1<<11];

int main()
{
    cin >> H >> W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j];
        }
    }

    ll R[1<<11];
    ll C[1<<11];

    for(int i=0;i<H;i++){
        int tmp = 0;
        for(int j=0;j<W;j++){
            tmp += A[i][j];
        }
        R[i] = tmp;
    }
    for(int i=0;i<W;i++){
        int tmp = 0;
        for(int j=0;j<H;j++){
            tmp += A[j][i];
        }
        C[i] = tmp;
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(j>0){
                cout << " ";
            }
            cout << R[i] + C[j] - A[i][j];
        }
        cout << endl;
    }

    return 0;
}