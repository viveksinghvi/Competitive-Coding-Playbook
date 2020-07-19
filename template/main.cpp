#include<bits/stdc++.h>
#define present(container, element) (container.find(element) != container.end())//searches in set/map
#define cpresent(container, element) (find(container.begin(),container.end(),element) != container.end())//searches in vector
#define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)//iterating through STL
using namespace std;
const int INF = 1e9;
int main()
{
    std::ios::sync_with_stdio(false); //I/O faster use'\n' in place of endl
    cin.tie(NULL);
    long t,m,n,q=0;
    cin >>t;
    vector< vector<long> > v(t,vector<long>(2));
    for (long i=0;i<t;i++){
        cin >>v[i][0]>>v[i][1];
        if (v[i][1]>q){
            q=v[i][1];
        }
    }
    vector<long> a(q+1,1);
    for (long i=2;i<=q;i++){
        if (a[i]){
            for(long j=i*i;j<=q;j=j+i){
                a[j]=0;
            }
        }
    }
    for (long i=0;i<t;i++){
        for (long j=v[i][0];j<=v[i][1];j++){
            if (j==1){
                continue;
            }
            if(a[j]){
                cout <<j<<'\n';
            }
        }
        cout <<'\n';
    }

}
