#include <bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false); //I/O faster use'\n' in place of endl
    cin.tie(NULL);
    string s,c,t;
    s="Ravi had,dfg been saying, that he, had been there.";
    //first method for spaves only
    stringstream st(s);
    while(st>>t){
        cout<<t<<'\n';
        c=t;
    }

    //sefcond method
    stringstream stt(s);
    while(getline(stt,t,',')){
        cout<<t<<'\n';
    }

    //multiple tokens
    cout<<"\nMul\n";
    char a[s.length()+1];
    strcpy(a,s.c_str());
    cout<<a;
    cout<<'\n';
    char *temp;
    temp=strtok(a," ,.");
    while(temp!=NULL){
        cout<<string(temp)<<'\n';
        temp=strtok(NULL," ,.");
    }
    /*
    // Input till eof Test in file operations
    int v,tt;
    while (!cin.eof())
    {
        cin >> v >> tt;
        cout << v+tt <<'\n';
    }
    */
    return 0;
}
