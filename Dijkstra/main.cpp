#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000+1
vector < pair < int , int > > v [SIZE];   // each vertex has all the connected vertices with the edges weights
int dist [SIZE];
bool vis [SIZE];
priority_queue< pair < int , int >, vector< pair < int , int > >, greater< pair < int , int > > > s;

void dijkstra(){
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[1] = 0;                                                // multiset do the job as a min-priority queue
    s.push({0 , 1});                          // insert the source node with distance = 0
    while(!s.empty()){
        pair <int , int> p = s.top();        // pop the vertex with the minimum distance
        s.pop();
        int x = p.second; int wei = p.first;
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
        vis[x] = true;
        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].second; int w = v[x][i].first;
            if(vis[e]==false && dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;             // insert the next vertex with the updated distance
                s.push({dist[e],e});
            }
        }
    }
}
    void initialize(int n) {
        for(int i = 0;i <=n;++i)
         {
            vis[i] = false;
            dist[i]=1e9;
         }
    }
    int main() {
        std::ios::sync_with_stdio(false); //I/O faster use'\n' in place of endl
        cin.tie(NULL);
        int n, e, x, y, w;
        cin >> n;                       //Number of nodes
        cin >> e;                       //Number of edges
        for(int i = 0;i <e;++i) {
         cin >> x >> y>>w;
     //Undirected Graph
         v[x].push_back(make_pair(w,y));                   //Edge from vertex x to vertex y
        }
        initialize(n);// set the vertices distances as infinity//Initialize all nodes as not visited
        dijkstra();
        cout<<dist[1]<<' '<<dist[2]<<' '<<dist[3]<<' '<<dist[4];
        return 0;
}
/*
4 5
1 2 2
2 3 2
3 4 2
1 4 6
2 4 1

output:0 2 4 3
*/
