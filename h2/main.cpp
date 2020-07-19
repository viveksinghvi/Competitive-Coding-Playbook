#include<bits/stdc++.h>
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())
using namespace std;
 void modify_vector(vector<int>& v) { // Correct
      v[0]++;
 }
int main()
{
    int a[]={1,3,2,0};
    vector<int> v(a,a+4);
    sort(v.begin(),v.end());
    for (int i=0;i<4;i++){
        cout <<v[i]<<' ';
    }
}
    /*
    swap(i,j);
    cout <<i<<' '<<j;
    cout <<min(1,2)<<' ';
    set<int> s;
    s.insert(3);
    s.insert(4);
    if(present(s,3))
        cout <<356;
    s.erase(3);
    if(s.find(3)!=s.end())
        cout <<3l;
    return 0;
}
*/
