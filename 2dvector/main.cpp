#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool check(std::vector< vector<int> > &v,int x,int y,int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (i==x or j==y or j+i==x+y or i-j==x-y){
                if (v[i][j]==1)
                    return false;
            }
        }
    }
    return true;
}
bool queen (int q,std::vector< vector<int> > &v,int n){
    if (q==0){
        return true;
    }
    else {
        int i,j;
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                if (check(v,i,j,n)){
                    v[i][j]=1;
                    if (queen(q-1,v,n)){
                        return true;
                    }
                    v[i][j]=0;
                }
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cin >>n;
    vector< vector<int> > v(n, vector<int>(n,0));
    if (queen(n,v,n)){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout <<v[i][j]<<" ";
            }
            cout <<endl;
        }
    }
    return 0;
}
