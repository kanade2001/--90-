#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

int N;

/*
tree_diamiter: dfsを用いて重み付き木野直径を求める
計算量: O(N)
*/
class Tree_diamiter
{
private:
    struct Edge{
        int to;
        ll cost;
    };
    using Graph = vector<vector<Edge>>;
    Graph G;
    pair<ll, int> dfs(int u, int par) //最遠点間距離と最遠点を求める
    {
        pair<ll, int> ret = make_pair((ll)0, u);
        for(auto e : G[u]){
            if(e.to == par) continue;
            auto next = dfs(e.to, u);
            next.first += e.cost;
            ret = max(ret, next);
        }
        return ret;
    }
public:
    void graph_resize(int size)
    {
        G.resize(size+1);
    }

    void set_edge(int from, int to, ll cost = 1)
    {
        
        G[from].push_back({to, cost});
        G[to].push_back({from, cost});
    }

    ll tree_diamiter()
    {
        pair<ll, int> p = dfs(1, -1);
        pair<ll, int> q = dfs(p.second, -1);
        return q.first;
    }
};

int main()
{
    cin >> N;

    Tree_diamiter A;
    A.graph_resize(N);

    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        A.set_edge(a,b);
    }

    cout << A.tree_diamiter() + 1 << endl;

    return 0;
}