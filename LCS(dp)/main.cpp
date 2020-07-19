#include <iostream>
#include <string>
#include <vector>
using namespace std;
int lcs(string a,string b,int n,int m){
    vector <vector<int> > v(n+1,vector<int>(m+1,0));
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (i==0 or j==0){
                v[i][j]=0;
            }
            else if (a[i-1]==b[j-1]){
                v[i][j]=1+v[i-1][j-1];
            }
            else{
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    return v[n][m];

    /* RECURSION
    if (n==0 or m==0){
        return 0;
    }
    if (a[n-1]==b[m-1]){
        return 1+lcs(a,b,n-1,m-1);
    }
    else{
        return max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
    }*/
}
int main()
{
    string a;
    string b;
    cin >>a;
    cin >>b;
    cout <<lcs(a,b,a.size(),b.size());
    return 0;
}
