#include <bits/stdc++.h>

using namespace std;
/* https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/#read */
/*take input in 1 based index and tree is also 1 index based*/
#define SIZE 10000
vector<int> tree(SIZE);

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx ,int val,int MaxVal){
    while (idx <= MaxVal){
        tree[idx]+= val;
        idx += (idx & -idx);
    }
}
int readSingle(int idx){
    int sum = tree[idx]; // sum will be decreased
    if (idx > 0){ // special case
        int z = idx - (idx & -idx); // make z first
        idx--; // idx is no important any more, so instead y, you can use idx
        while (idx != z){ // at some iteration idx (y) will become z
            sum -= tree[idx];
    // substruct tree frequency which is between y and "the same path"
            idx -= (idx & -idx);
        }
    }
    return sum;
}
void scale(int c,int MaxVal){
    for (int i = 1 ; i <= MaxVal ; i++)
        tree[i] = tree[i] / c;
}
// if in tree exists more than one index with a same
// cumulative frequency, this procedure will return
// some of them (we do not know which one)

// bitMask - initialy, it is the greatest bit of MaxVal
// bitMask store interval which should be searched
int find(int cumFre,int bitMask,int MaxVal){//WRONGGG RESULTTSSSCC
    int idx = 0; // this var is result of function

    while ((bitMask != 0) && (idx < MaxVal)){ // nobody likes overflow :)
        int tIdx = idx + bitMask; // we make midpoint of interval
        if (cumFre == tree[tIdx]) // if it is equal, we just return idx
            return tIdx;
        else if (cumFre > tree[tIdx]){ //if want gretest valu instead then >=
                // if tree frequency "can fit" into cumFre,
                // then include it
            idx = tIdx; // update index
            cumFre -= tree[tIdx]; // set frequency for next loop
        }
        bitMask >>= 1; // half current interval
    }
    if (cumFre != 0) // maybe given cumulative frequency doesn't exist
        return -1;
    else
        return idx;
}


int main()
{
    int n=5;
    vector<int> v(n+1);
    //input 1 based index
    for(int i=1;i<=n;i++){
        v[i]=i;
        update(i,v[i],n);
    }
    for(int i=1;i<=n;i++){
        cout<<tree[i]<<' ';
    }
    /*adds 1 to index 1
        thus add desired-v[i]
    */
    update(1,1,n);
    cout<<'\n';
    for(int i=1;i<=n;i++){
        cout<<tree[i]<<' ';
    }
    cout<<'\n';
    cout <<read(5)<<' ';
    /*for reading form l to r inclusive
            read(r)-read(l-1)
    */
    cout<<'\n';
    cout<<readSingle(2);
    int bitMask=4;//for 5
    cout<<'\n'<<find(11,bitMask,n);
    return 0;
}
