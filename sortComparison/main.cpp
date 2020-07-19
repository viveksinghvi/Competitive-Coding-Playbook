#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool way (vector<int>a,vector <int>b ){
    if (a[0]==b[0]){
        if (a[2]==b[2]){
            return a[1]<b[1];
        }
        return a[2]<b[2];
    }
    return a[0]<b[0];
}
int main()
{
    int n,time,stile,scost,cost,tile;
    long d;
    cin >>n>>d;
    vector <vector<int> > a(n,vector<int>(3));
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            cin >>a[i][j];
        }
    }
    sort(a.begin(),a.end(),way);
    time=a[0][0];
    stile=a[0][2];
    scost=a[0][1];
    tile=0;
    cost=0;
    for (int i=0;i<n;i++){
        if (a[i][0]>time){
                if (tile+stile*(a[i][0]-time)>=d){
                    cost=cost+scost*((d-tile)/stile ==0?((d-tile)/stile):((d-tile)/stile+1));
                    break;
                }
                else {
                    cost+=scost*(a[i][0]-time);
                }
            if (a[i][2]>stile){
                stile=a[i][2];
                scost=a[i][1];
            }
            time=a[i][0];
        }
    }
    cout<<cost<<endl;
    return 0;
}
