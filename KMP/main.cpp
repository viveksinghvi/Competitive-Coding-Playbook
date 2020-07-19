#include <bits/stdc++.h>
using namespace std;
int arr[100];
void pre(string pat){
    int len=0;
    arr[0]=0;
    int i=1;
    while(i<pat.length()){
        if(pat[i]==pat[len]){
            len++;
            arr[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=arr[len-1];
            }
            else{
                arr[i]=0;
                i++;
            }
        }

    }
}
int KMP(string txt,string pat){
    pre(pat);
    int i,j;
    i=0;j=0;
    while(i<txt.length()){
        if(pat[j]==txt[i]){
            j++;
            i++;
        }
        if(j==pat.length()){
            cout<<"Found at "<<i-j<<'\n';
            j=arr[j-1];
        }
        else if(i<txt.length() && pat[j]!=txt[i]){
                if(j!=0){
                    j=arr[j-1];
                }
                else {
                    i++;
                }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string txt="AABAACAADAABAABA",pat="AABA";
    KMP(txt,pat);
    return 0;
}
