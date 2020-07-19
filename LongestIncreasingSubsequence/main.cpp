#include <iostream>
#include <vector>
using namespace std;
//o n^2
void lcs(vector<int>& d){
    vector<vector <int> > v(d.size());
    v[0].push_back(d[0]);
    for (int i=1;i<d.size();i++){
        for (int j=0;j<i;j++){
            if (d[j]<d[i] and v[i].size()<=v[j].size()){
                v[i]=v[j];
            }
        }
        v[i].push_back(d[i]);
    }
}
int main()
{
    int a[]={3,2,6,4,5,1};
    vector<int> v(a,a+sizeof(a)/sizeof(a[0]));
    lcs(v);
    return 0;
}
//o nlogn for non decresing given below
//to change it to strictly increasing change upper_bound to lower_bound
vector<int> d;
int ans, n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    printf("LIS = %d", d.size());
    return 0;
}
