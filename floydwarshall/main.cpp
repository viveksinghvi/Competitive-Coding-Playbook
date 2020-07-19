#define SIZE 110
#include<bits/stdc++.h>

using namespace std;
long long b[SIZE][SIZE];
#include <iostream>
#include <conio.h>
using namespace std;
void floyds(int n)
{
    int i, j, k;
    for (k = 0; k <n; k++)
    {
        for (i = 0; i <n; i++)
        {
            for (j = 0; j <n; j++)
            {
                if ((b[i][k] + b[k][j] < b[i][j]))
                {
                    b[i][j] = b[i][k] + b[k][j];
                }
            }
        }
    }
    /*
    for each k in V(G)
     if adj[k][k] < 0
          error "Graph contains a negative-weight cycle"
    */
}
void initialize(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j)b[i][j]=0;
            else b[i][j]=1000000000000;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false); //I/O faster use'\n' in place of endl
    cin.tie(NULL);
    int n, e, x, y, w;
    cin >> n;                       //Number of nodes
    cin >> e;
    initialize(n);                       //Number of edges
    for(int i = 0;i <e;++i) {
        cin >> x >> y>> w;
        b[x][y]=w;
    }
    floyds(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
/*
4 5
0 1 2
1 2 2
2 3 2
0 3 6
1 3 1
*/
