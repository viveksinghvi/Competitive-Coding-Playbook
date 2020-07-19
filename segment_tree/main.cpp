#include<bits/stdc++.h>
using namespace std;
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define ll long long


struct node{
    int val;
};

//if n, then 4*n memory reqd.
node tree[4*100005];
int lazy[4*100005];//memset it to 0

int A[6];

/*
Results in complete binary trees which has the property
    in N leaf nodes then
    total nodes will be 2*N-1
    src from https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/
    tree array 1 based index
*/

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node].val = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node].val = tree[2*node].val + tree[2*node+1].val;
        }
}
//change to at idx to val
void update(int node, int start, int end, int idx, int val)
{
    /*Replaces A[idx] with val */
    if(start == end)
    {
        // Leaf node
        A[idx] = val;
        tree[node].val = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node].val = tree[2*node].val + tree[2*node+1].val;
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node].val;
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
//add +=val to all index from l to r
void updateRange(int node, int start, int end, int l, int r, int val)
{
    // out of range
    if (start > end or start > r or end < l)
        return;

    // Current node is a leaf node
    if (start == end)
    {
        // Add the difference to current node
        /* l to r increase by val*/
        tree[node].val += val;
        return;
    }

    // If not a leaf node, recur for children.
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);

    // Use the result of children calls to update this node
    tree[node].val = tree[node*2].val + tree[node*2+1].val;
}
/*
      LAZY PROPAGATION

void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node].val += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node].val += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node].val = tree[node*2].val + tree[node*2+1].val;        // Updating root with max value
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node].val += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node].val;
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << "Hello world!" << endl;
    //A={1,2,3,4};
    int n=3;

    //1 based index of input array
    for (int i=1;i<=3;i++){
        A[i]=i;
    }
    build(1,1,3);
    //1 based index of tree array
    for (int i=1;i<=2*n-1;i++){
        cout<<tree[i].val<<' ';
    }
    update(1,1,3,1,2);
    for (int i=1;i<=2*n-1;i++){
        cout<<tree[i].val<<' ';
    }
    cout<<query(1,1,3,1,2);
    return 0;
}
