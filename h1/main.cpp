#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int a[3][2];
    for (int i=0;i<3;i++){
        cin >>a[i][0]>>a[i][1];
    }
    cout <<3<<'\n';
    int x,y;
    for (int i=0;i<3;i++){
        x=a[(i)%3][0]+a[(i+1)%3][0]-a[(i+2)%3][0];
        y=a[(i)%3][1]+a[(i+1)%3][1]-a[(i+2)%3][1];
        cout <<x<<' '<<y<<'\n';
    }
}
