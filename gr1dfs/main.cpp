#include <iostream>
#include <bits/stdc++.h>
using namespace std;


    vector <int> v[100000+1];
    bool vis[100000+5];
    int maxi=0,temp=0;
    int dfs(int s) {
        vis[s] = true;
        temp=temp+v[s].size();
        for(int i = 0;i < v[s].size();++i)    {
         if(vis[v[s][i]] == false)
             dfs(v[s][i]);
        }
        return temp;
    }

    void initialize() {
        for(int i = 0;i < 100000+5;++i)
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
        int n, e, x, y, connectedComponents = 0;
        cin >> n;                       //Number of n
        cin >> e;                       //Number of e
        for(int i = 0;i < e;++i) {
         cin >> x >> y;
     //Undirected Graph
         v[x].push_back(y);                   //Edge from vertex x to vertex y
         v[y].push_back(x);                   //Edge from vertex y to vertex x
        }

        initialize();                           //Initialize all n as not vis

        for(int i = 1;i <= n;++i) {
         if(vis[i] == false)     {
             temp=0;
             dfs(i);
             if (temp>maxi)
                maxi=temp;
             connectedComponents++;
         }
        }
        cout << maxi/2;
        return 0;
    }
