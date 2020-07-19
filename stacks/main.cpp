#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack<char> s;
    string a;
    cin >>a;
    int t=0;
    char c;
    for(int i=0;i<a.size();i++){
        c=a[i];
        if (c=='{' || c=='['||c=='('){
            s.push(c);
        }
        else {
            if (s.empty()){
                cout <<"invalid";
                return 0;
            }
            if (c=='}'){
                if (s.top()=='{'){
                    s.pop();
                }
                else {
                    cout <<"invalid";
                    return 0;
                }
            }
            if (c==')'){
                if (s.top()=='('){
                    s.pop();
                }
                else {
                    cout <<"invalid";
                    return 0;
                }
            }
            if (c==']'){
                if (s.top()=='['){
                    s.pop();
                }
                else {
                    cout <<"invalid";
                    return 0;
                }
            }

        }
    }
    if (s.empty()){
        cout <<"valid";
        return 0;
        }
    cout <<"invalid";
    return 0;
}
