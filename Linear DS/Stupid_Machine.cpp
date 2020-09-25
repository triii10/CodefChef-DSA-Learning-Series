#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        long long sum = 0;
        int min_till_now = INT_MAX;
        for(int i = 0;i < n;i++) {
            int capacity;
            cin>>capacity;

            min_till_now = min(min_till_now, capacity);

            sum += min_till_now;
        }

        cout<<sum<<endl;
    }
    return 0;
}