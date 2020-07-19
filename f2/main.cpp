#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ofstream myfile;
    myfile.open ("example.txt");
    int t,n;
    cin >>t;
    for (int i=1;i<=t;i++){
        cin >>n;
        vector <int> v(n);
        for (int j=0;j<n;j++){
            cin >>v[j];
        }
        sort(v.begin(),v.end());
        int k=0,l=n-1;
        int ans=0;
        int w=0;
        while(1){
            w=49/v[l];
            if(k+w<=l){
                ans++;
                k=k+w;
                l--;
            }
            else
                break;
        }
            myfile <<"Case #"<<i<<": " <<ans << endl;
    }

    return 0;
}
