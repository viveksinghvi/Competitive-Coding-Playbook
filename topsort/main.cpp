#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); //I/O faster use'\n' in place of endl
    cin.tie(NULL);
    ll a,b;
    cin>>a>>b;//conv to ll
    int ans=0;
    for(ll i=2;i<=100000;i++){
        ll temp=i;
        int steps=0;
        while(temp<=b){
            if(temp>=a && temp<=b){
                ans=max(ans,steps);
            }
            temp=temp*temp;
            step++;
        }
    }
    cout<<ans;
    return 0;
}
/*
6 6
5 2
5 0
4 0
4 1
2 3
3 1
*/
