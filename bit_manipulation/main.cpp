#include <iostream>

using namespace std;

int main()
{
    int N=3;
    int A[]={1,2,3};
    int s=6;
    for(int i = 0;i < (1 << N); ++i)
    {
        int t=0;
        for(int j = 0;j < N;++j)
            if(i & (1 << j))
                t+=A[j];
                //cout << A[j] << ' ';
        if (t==s){
            cout <<"dfs";
        }
        cout << endl;
}
}
