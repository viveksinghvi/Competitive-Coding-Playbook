#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct CompareAge {
    bool operator()(int a,int b) {
        // return "true" if "p1" is ordered before "p2", for example:
        return (a>b);
    }
};
bool ope(int a,int b) {
        // return "true" if "p1" is ordered before "p2", for example:
        return (a>b);
    }
int main()
{
    priority_queue<int,vector <int> ,CompareAge >p;

    vector<int > v;
    for (int i=0;i<4;i++){
        v.push_back(i);
        p.push(i);
    }
    while(!p.empty()){
        cout <<p.top();
        p.pop();
    }
    sort(v.begin(),v.end(),ope);
    for (int i=0;i<4;i++){
        cout<<v[i];
    }
}
