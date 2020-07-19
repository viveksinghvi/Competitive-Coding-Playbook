#include <bits/stdc++.h>
using namespace std;

    vector <int> adj[10];
    bool vis[10];

    void dfs(int s) {
        stack<int> st;
        st.push(s);
        while(!st.empty()){
            s=st.top();
            st.pop();
            if(!vis[s]){
                vis[s]=true;
                cout<<s<<' ';
                for(int i = 0;i < adj[s].size();++i)    {
                if(vis[adj[s][i]] == false)
                     st.push(adj[s][i]);
                }
            }
        }
    }

    void initialize(int n) {
        for(int i = 0;i <=n;++i)
         vis[i] = false;
    }

/*
6
4
1 2
2 3
1 3
4 5
*/
//gives node connected components
    int main() {
        std::ios::sync_with_stdio(false); //I/O faster use'\n' in place of endl
        cin.tie(NULL);
        int n, e, x, y, connectedComponents = 0;
        cin >> n;                       //Number of nodes
        cin >> e;                       //Number of edges
        for(int i = 0;i <e;++i) {
         cin >> x >> y;
     //Undirected Graph
         adj[x].push_back(y);                   //Edge from vertex x to vertex y
         adj[y].push_back(x);                   //Edge from vertex y to vertex x
        }

        initialize(n);                           //Initialize all nodes as not visited

        for(int i = 1;i <= n;++i) {
         if(vis[i] == false)     {
             dfs(i);
             connectedComponents++;
         }
        }
        cout << "Number of connected components: " << connectedComponents << endl;
        return 0;
    }
/*
6
4
1 2
2 3
1 3
4 5
*/
