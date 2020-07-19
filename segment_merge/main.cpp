const int maxn = 1e5+10;
vector<int> tree[4*maxn];
int n, m, arr[maxn];
#define all(v) v.begin(), v.end()
void build(int node, int l, int r) {
	if(l == r) {
		tree[node].push_back(arr[l]);
		return;
	}
	int mid = l + r >> 1,
	left = node << 1, right = left|1;

	build(left, l, mid);
	build(right, mid+1, r);

	merge(all(tree[left]), all(tree[right]),
	        back_inserter(tree[node]));
}
int query(int node, int l, int r, int i, int j, int k) {
	if(i > r || l > j) return 0;
	if(i <= l && r <= j) {
		return lower_bound(all(tree[node]), k)
			         - tree[node].begin();
	}
	int mid = l + r >> 1,
		left = node << 1, right = left|1;
	return query(left, l, mid, i, j, k) +
		   query(right, mid+1, r, i, j, k);
}
int main(){
    int n,q,x,y,z;
    cin>>n>>q;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);

}
