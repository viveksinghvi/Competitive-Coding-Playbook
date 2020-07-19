#include<bits/stdc++.h>
using namespace std;
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define ll long long
/*
vector<int>  v={1,2,3};
int comp(){
    int s=0,a=1;
    for(int i=0;i<v.size();i++){
        s+=a*v[i];
        a*=2;
    }
    return s;
}
void per(){
    sort(v.begin(),v.end());
    do{
        cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<'\n';
        cout<<comp()<<'\n';
    }while(next_permutation(v.begin(),v.end()));
}
void subset(){
    int n=v.size();
    vector<int> temp;
    for(int i=0;i<(1<<n);i++){
        temp.clear();
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                temp.push_back(v[j]);
            }
        }
        for(int j=0;j<temp.size();j++){
            cout<<temp[j]<<' ';
        }
        cout<<'\n';
    }
}*/
void sol(vector<int> &v){
    /*
    string s="";
    int j=0;
    for(int i=0;i<q;i++){
        if(j<sc[0] && v[j]==i){
            s+=in[0][i];
            j++;
        }
        else{
            if(in[0][i]=='T')
                s+="F";
            else
                s+="T";
        }

    }
    //cout<<s;
    int temp=0;
    for(int i=0;i<q;i++){
        if(my[i]==s[i]){
            temp++;
        }
    }
    ans=max(ans,temp);
*/
}
void gen(int i,vector<int> &c, vector<vector<int> > &res,int k ,int n){
    if(i>=n){
        return;
    }
    gen(i+1,c,res,k,n);
    c.push_back(i);
    if(c.size()==k){
        res.push_back(c);
        sol(c);
    }
    else gen(i+1,c,res,k,n);
    c.pop_back();
    return ;
}
vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > res;
    vector<int> current;
    gen(0,current,res,k,n);
    //sort(res.begin(),res.end());
    return res;
}
string dict[1005];
int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(NULL);
    //per();
    //subset();
    /*
    vector<vector<int> > r=combine(10,3);
    for(int i=0;i<r.size();i++){
        for(int j=0;j<r[i].size();j++){
            cout<<r[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    ll t,ans=0;
    cin>>t;
    int T=t;
    while(t--){
        ll l,n,a,b,c,d;
        string s1,s2;
        cin>>l;
        for(int i=0;i<l;i++){
            cin>>dict[i];
        }
        cin>>s1>>s2>>n>>a>>b>>c>>d;
        s1=s1+s2;
        int y=s1[0],z=s2[0];;
        for(int i=2;i<n;i++){
            int x=(a*z+b*y+c)%d;
            s1+=(char)(x%26)+'a';
            y=z;
            z=x;
        }
        //cout<<s1;
        ans=0;

        for(int i=0;i<l;i++){
            string tt=dict[i].substr(1,dict[i].length()-2);
            sort(tt.begin(),tt.end());
            dict[i]=dict[i][0]+tt+dict[i][dict[i].length()-1];
            //cout<<dict[i]<<' ';
        }

        for(int i=0;i<l;i++){
            for(int j=0;j<=n-dict[i].length();j++){
                if(dict[i][0]==s1[j] && dict[i][dict[i].length()-1]==s1[j+dict[i].length()-1]){
                    //cout<<i<<' '<<j<<'\n';
                    string tt=s1.substr(j+1,dict[i].length()-2);
                    sort(tt.begin(),tt.end());
                    if(dict[i].substr(1,dict[i].length()-2)==tt){
                            ans++;
                            break;
                    }
                }
            }
        }
        cout<<"Case #"<<T-t<<": "<<ans<<'\n';
    }
    return 0;
}
