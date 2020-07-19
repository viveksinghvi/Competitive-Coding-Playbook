#include <bits/stdc++.h>
#define INT_SIZE 32
using namespace std;
#define REP(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)
//program to find min pair xor in array
int a[100];
typedef struct trie{
    int val;
    trie* child[2];
}trie;
trie* getTrie(){
    trie* t=(trie*)malloc(sizeof(trie));
    t->val=0;
    t->child[0]=NULL;
    t->child[1]=NULL;
    return t;
}
void insert(trie* root,int key){
    bool cbit=0;;
    trie *temp=root;
    for(int i=INT_SIZE-1;i>=0;i--){
        cbit=key&(1<<i);
        if(temp->child[cbit]==NULL){
            temp->child[cbit]=getTrie();
        }
        temp=temp->child[cbit];
    }
    temp->val=key;
}
int minCurr(trie* root,int key){
    bool cbit;
    trie *temp=root;
    for(int i=INT_SIZE-1;i>=0;i--){
        cbit=key&(1<<i);
        if(temp->child[cbit]==NULL){
            temp=temp->child[1-cbit];
        }
        else{
            temp=temp->child[cbit];
        }
    }
    return temp->val^key;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    trie* root=getTrie();
    int n;
    int ans=INT_MAX;
    cin>>n;
    REP(i,0,n,1)cin>>a[i];
    insert(root,a[0]);
    REP(i,1,n,1){
        ans=min(ans,minCurr(root,a[i]));
        insert(root,a[i]);
    }
    cout<<ans;
    return 0;
}
/*
3
9 5 3
*/
