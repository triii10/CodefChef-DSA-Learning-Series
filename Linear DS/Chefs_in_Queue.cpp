#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(int argc, char* argv[]) {
// Code goes here
    long n, k, mul=1;
    cin>>n>>k;

    stack<pair<long, long>> q;
    q.push({0, 0});
    for(long i = 1;i <= n;i++) {
        long inp;
        cin>>inp;

        while(!q.empty() && q.top().first > inp){
            mul = (mul*(i - q.top().second + 1)%MOD);
            q.pop();
        }

        q.push({inp, i});
    }

    cout<<mul<<endl;
    return 0;
}