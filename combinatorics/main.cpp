#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
ll p[5005][5005];
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false); //I/O faster use'\n' in place of endl
    cin.tie(NULL);
	p[0][0]=1;
	for (int i=1;i<=5000;i++)
	{
		p[i][0]=1;
		for (int j=1;j<=i;j++)
			p[i][j]=(p[i-1][j-1]+p[i-1][j])%mod;
	}
	for(int i=0;i<=6;i++){
        cout<<p[6][i]<<' ';
	}
    return 0;
}
