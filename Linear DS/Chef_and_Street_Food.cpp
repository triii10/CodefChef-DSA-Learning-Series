#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<int> s, p, v;
        for(int i = 0;i < n;i++) {
            int a, b, c;
            cin>>a>>b>>c;
            s.push_back(a);
            p.push_back(b);
            v.push_back(c);
        }

        int max_profit = 0;

        for(int i = 0;i < n;i++) {
            max_profit = max(max_profit, v[i]*(p[i]/(s[i]+1)));
        }
        cout<<max_profit<<endl;
    }
    return 0;
}