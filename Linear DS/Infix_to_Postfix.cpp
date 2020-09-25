#include<bits/stdc++.h>
using namespace std;

int priority(char c) {
    int order;
    switch (c)
    {
    case '+':
    case '-':
        order = 1;
        break;
    case '*':
    case '/':
        order = 2;
        break;
    case '^':
        order = 3;
        break;
    default:
        order = 0;
        break;
    }

    return order;
}

bool isAlpha(char c) {
    if(c <= 'Z' && c >= 'A')
        return true;
    return false;
}

int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        string infix;
        cin>>infix;
        stack<char> st;

        for(int i = 0;i < n;i++) {
            if(infix[i] == '(')
                st.push('(');
            else if(infix[i] == ')') {
                while(st.top() != '(') {
                    cout<<st.top();
                    st.pop();
                }
                st.pop();
            }

            else if(isAlpha(infix[i]))
                cout<<infix[i];
            
            else {
                while(!st.empty() && (priority(st.top()) >= priority(infix[i]))) {
                    cout<<st.top();
                    st.pop();
                }
                st.push(infix[i]);
            }
        }

        while(!st.empty()) {
            cout<<st.top();
            st.pop();
        }

        cout<<endl;
    }
    return 0;
}