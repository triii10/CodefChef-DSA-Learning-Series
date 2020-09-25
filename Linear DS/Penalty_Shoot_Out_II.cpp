#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        string shootout;
        cin>>shootout;

        int min_s = 2*n;

        vector<int>scored(2, 0), possible(2, n);
        for(int i = 0;i < (2*n);i++) {
            scored[i%2] += (shootout[i] - '0');
            possible[i%2]--;

            if(((scored[i%2] + possible[i%2]) < (scored[(i+1)%2])) || ((scored[(i+1)%2] + possible[(i+1)%2]) < (scored[i%2]))){
                min_s = i+1;
                break;
            }
        }

        cout<<min_s<<endl;
    }
    return 0;
}