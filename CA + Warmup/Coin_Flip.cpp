#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while(t--) {
        int g;
        cin>>g;
        while(g--) {
            int i, n, g;
            cin>>i>>n>>g;
            
            int res = (i == g) ? n/2 : n/2 + ((n % 2) ? 1 : 0);

            cout<<res<<endl;
        }
    }
    return 0;
}