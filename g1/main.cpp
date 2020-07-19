#include<bits/stdc++.h>
using namespace std;
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s="10011";
    int a[7];
    int len=s.length();
    memset(a,0,sizeof(a));
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            a[i]=0;
        }
        else a[i]=1;
    }
    for(int i=len-1;i>=0;i--){
        if(s[i]=='1'){
            if(i-1>=0)a[i-1]+=1;
        }
    }
    for(int i=0;i<len;i++){
        if(a[i]==2){
            a[i]=0;
            a[i+1]-=1;
        }
    }
    for(int i=0;i<len;i++){
        cout<<a[i];
    }
    return 0;
}
