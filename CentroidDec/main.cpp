#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; si(t); while(t--)
const int N = int(1e5)+10;
const int LOGN = 20;
const int INF = int(1e9);
set<int> g[N];//graph
int par[N];//stores parent of each node :: in decomposed tree
int sub[N];//stores no. of element in subtree of given node in original graph:used for decomposing
int level[N];//stores level of each node :: calculate dist btw nodes
int ans[N];//ans[i] denote the min distance to a red node for the
// centroid "i" in it's corresponding part. Hence initially, let ans[i]=INF, for all i
int DP[LOGN][N];// DP[i,j] stores ancenstor of j who is above i steps::use in lca
int n,m;
/*Using centroid Decomposition of a tree */

/*----------- Pre-Processing ------------*/
void dfs0(int u)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=DP[0][u])
		{
			DP[0][*it]=u;
			level[*it]=level[u]+1;
			dfs0(*it);
		}
}
void preprocess()
{
	level[0]=0;
	DP[0][0]=0;
	dfs0(0);
	for(int i=1;i<LOGN;i++)
		for(int j=0;j<n;j++)
			DP[i][j] = DP[i-1][DP[i-1][j]];
}
int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;i<LOGN;i++)
		if(d&(1<<i))
			b=DP[i][b];
	if(a==b)return a;
	for(int i=LOGN-1;i>=0;i--)
		if(DP[i][a]!=DP[i][b])
			a=DP[i][a],b=DP[i][b];
	return DP[0][a];
}
int dist(int u,int v)
{
	return level[u] + level[v] - 2*level[lca(u,v)];
}
/*-----------------Decomposition Part--------------------------*/
int nn;
void dfs1(int u,int p)
{
	sub[u]=1;
	nn++;
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
		{
			dfs1(*it,u);
			sub[u]+=sub[*it];
		}
}
int dfs2(int u,int p)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p && sub[*it]>nn/2)
			return dfs2(*it,u);
	return u;
}
void decompose(int root,int p)
{
	nn=0;
	dfs1(root,root);
	int centroid = dfs2(root,root);
	if(p==-1)p=centroid;
	par[centroid]=p;
	for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
	{
		g[*it].erase(centroid);
		decompose(*it,centroid);
	}
	g[centroid].clear();
}
/*----------------- Handle the Queries -----------------*/

void update(int u)
{
	int x = u;
	while(1)
	{
		ans[x] = min(ans[x],dist(x,u));
		if(x==par[x])
			break;
		x = par[x];
	}
}
int query(int u)
{
	int x = u;
	int ret=INF;
	while(1)
	{
		ret = min(ret,dist(u,x) + ans[x]);
		if(x==par[x])
			break;
		x = par[x];
	}
	return ret;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[u-1].insert(v-1);
		g[v-1].insert(u-1);
	}
	preprocess();
	decompose(0,-1);
	for(int i=0;i<n;i++)
		ans[i]=INF;
	update(0);//first node is initially painted red
	while(m--)
	{
		int t,v;
		scanf("%d %d",&t,&v);v--;
		if(t==1)
			update(v);
		else
			dout(query(v));
	}
	return 0;
}
/*
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int mx=1e5+10;
vector<int>adj[mx];
int mark[mx],sub[mx];
char ans[mx];
void dfs_size(int a,int par){
	sub[a]=1;
	for(auto u:adj[a]) if(!mark[u] && u!=par) dfs_size(u,a),sub[a]+=sub[u];
}
void cd(int a,char c){
	dfs_size(a,0);
	int med=a,par=0;
	while(1){
		int fou=1;
		for(auto u:adj[med]){ if(!mark[u] && u!=par && sub[u]>sub[a]/2){
				par=med,med=u,fou=0;
				break;
			}
		}
		if(fou) break;
	}
	mark[med]=1;
	ans[med]=c;
	for(auto u:adj[med]) if(!mark[u]) cd(u,c+1);
}
int main(){
	int n,a,b;scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	cd(1,'A');
	for(int i=1;i<=n;i++) printf("%c ",ans[i]);
	return 0;
}
*/
