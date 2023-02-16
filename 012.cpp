#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, W;
ll Q;
bool C[2010*2010] = {false};

class UnionFind
{
private:
    vector<int> par; //par[i] : iの親番号
    vector<int> rank;
    vector<int> siz;

    int root(int x){ //rootの取得
        if (par[x] == x){
            return x;
        }else{
            return par[x] = root(par[x]);
        }
    }

public:
    void init(int N)
    {
        par.resize(N+1);
        rank.resize(N+1);
        siz.resize(N+1);
        for(int i=0;i<=N;i++){
            par[i] = i;
            rank[i] = 0;
            siz[i] = 1;
        }
    }

    bool merge(int x, int y){ //xとyの木を結合 結合した=true, 結合済みだった=false
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return false;
        }
        if(rank[x]<rank[y]){
            swap(rx, ry);
        }
        par[ry] = rx;
        if(rank[rx]==rank[ry]){
            rank[rx] ++;
        }
        siz[rx] += siz[ry];
        return true;
    }

    bool issame(int x, int y){ //xとyが同じ木ならtrue
        return root(x) == root(y);
    }

    int size(int x){
        return siz[root(x)];
    }

    void debug(int W = (1<<10))
    {
        cout << "----------debug----------" << endl;
        int cnt = 0;
        for(int i=0;i<par.size();i++){
            cout << setw(2) << setfill('0') << root(i) << ' ';
            cnt ++;
            if(cnt == W){
                cout << endl;
                cnt = 0;
            }
        }
        cout << endl;
        cout << "-------------------------" << endl;
    }
};
UnionFind U;

void q1sub(int p, int q)
{
    if(C[q] == true){
        U.merge(p, q);
    }
}

void q1()
{
    int r, c;
    cin >> r >> c;
    int p = r * (W+2) + c;
    C[p] = true;
    q1sub(p, p + W + 2);
    q1sub(p, p - W - 2);
    q1sub(p, p + 1);
    q1sub(p, p - 1);
}

void q2()
{
    int ra, ca, rb, cb;
    cin >> ra >> ca >> rb >> cb;
    if(C[ra*(W+2)+ca] && C[rb*(W+2)+cb] && U.issame(ra*(W+2)+ca, rb*(W+2)+cb)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main()
{
    cin >> H >> W;
    U.init((H+2)*(W+2));

    cin >> Q;
    for(int i=0;i<Q;i++){
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            q1();
        }else{
            q2();
        }
    }

    return 0;
}