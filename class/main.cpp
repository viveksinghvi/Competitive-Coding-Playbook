#include<bits/stdc++.h>
using namespace std;
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define ll long long
int x[32];
int y[32];
int z[32];

class TopXorerEasy{
    public://access modifier
         int maximalRating(int A, int B, int C){
            int t,i;
            t=A;
            i=0;
            while(t){
                x[i]=t%2;
                t=t>>2;
                i++;
            }
            t=B;
            i=0;
            while(t){
                x[i]=t%2;
                t=t>>2;
                i++;
            }
            t=C;
            i=0;
            while(t){
                x[i]=t%2;
                t=t>>2;
                i++;
            }
            int ans=0;
            for(i=30;i>=0;i--){
                if(x[i]==1 && y[i]==1){
                    break;
                }
                else if(z[i]==1 && y[i]==1){
                    break;
                }
                else if(x[i]==1 && z[i]==1){
                    break;
                }
                else{
                    ans=ans+((x[i]^y[i]^z[i])<<i);
                }
            }
            if(i!=-1)
                ans=ans+(1<<i)-1;
            return ans;
        }
};
int main(){
    TopXorerEasy t;
    cout<<t.maximalRating(2,1,0);
}
