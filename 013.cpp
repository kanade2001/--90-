#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;

class Dijkstra
{
//O(|E|log|V|)
private:
    struct Edge
    {
        long long to;
        long long cost;
    };
    vector<vector<Edge> > Graph;
    vector<long long> dis;
    vector<int> prev;

public:
    void graph_resize(int graph_size)
    {
        Graph.resize(graph_size+1);
    }

    void add_edge(long long from, long long to, long long cost)
    {
        Edge _new = {to, cost};
        Graph[from].push_back(_new);
    }

    void add_edge_undirected(long long a, long long b, long long cost)
    {
        Edge _new;
        _new = {a, cost};
        Graph[b].push_back(_new);
        _new = {b, cost};
        Graph[a].push_back(_new);
    }

    void calc(int start_point)
    {
        dis.resize(Graph.size(), 1LL<<60);
        prev.resize(Graph.size(), -1);
        priority_queue<pair<long,int>, vector<pair<long,int> >, greater<pair<long,int> > > pq;
        dis[start_point] = 0;
        pq.emplace(dis[start_point], start_point);
        while(!pq.empty()){
            pair<long, int> _p = pq.top();
            pq.pop();
            int _v = _p.second;
            if(dis[_v] < _p.first){
                continue;
            }
            for(auto &e : Graph[_v]){
                if(dis[e.to] > dis[_v] + e.cost){
                    dis[e.to] = dis[_v] + e.cost;
                    prev[e.to] = _v;
                    pq.emplace(dis[e.to], e.to);
                }
            }
        }
    }

    long long dist(int point)
    {
        return dis[point];
    }

    vector<int> path(int point)
    {
        vector<int> path;
        for(int cur = point; cur != -1; cur = prev[cur]){
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
Dijkstra Ds;
Dijkstra De;

int main()
{
    cin >> N >> M;

    Ds.graph_resize(N);
    De.graph_resize(N);

    for(int i=0;i<M;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        Ds.add_edge_undirected(a, b, c);
        De.add_edge_undirected(a, b, c);
    }

    Ds.calc(1);
    De.calc(N);

    for(int i=1;i<=N;i++){
        cout << Ds.dist(i) + De.dist(i) << endl;
    }

    return 0;
}