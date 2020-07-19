#include <iostream>

using namespace std;
int fun(int n)
{
    if (n==1){
        return 0;
    }
    else {
        int r=n;
        if(n%2==0)
        {
            r=min(r,1+fun(n/2));
        }
        if(n%3==0)
        {
            r=min(r,1+fun(n/3));
        }
        r=min(r,1+fun(n-1));
        return r;
    }
}
int main()
{
    int a;
    cin >>a;
    cout << fun(a);
    return 0;
}
