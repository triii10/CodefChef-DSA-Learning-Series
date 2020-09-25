#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        int count = 0, prev = INT_MAX;

        for(int i = 0;i < n;i++) {
            int speed;
            cin>>speed;

            if(speed <= prev) {
                prev = speed;
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}