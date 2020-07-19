#include <iostream>
#include <vector>
using namespace std;
int knapsack(int t,int w[],int v[],int n){
    vector <vector <int> > a(n+1,vector <int>(t+1,0));
    for (int i=0;i<=n;i++){
        for (int j=0;j<=t;j++){
            if (i==0 or j==0){
                a[i][j]=0;
            }
            else if (w[i-1]<=j){
                a[i][j]=max(v[i-1]+a[i-1][j-w[i-1]],a[i-1][j]);
            }
            else{
                a[i][j]=a[i-1][j];
            }
        }
    }
    return a[n][t];
}
int main()
{
    int val[] = {60, 100, 10};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = 3;
    cout <<knapsack(W, wt, val, n);
    return 0;
}
