#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t, sum = 0, max_depth = 0, depth_pos = 0,  seq_length = 0, seq_pos = 0, depth = 0, seq = 0;
    cin>>t;
    for(int i = 1;i <= t;i++) {
        int n;
        cin>>n;

        int inc = (n == 1 ? 1 : -1);

        sum += inc;
        seq++;

        if(sum > depth) {
            depth = sum;
            depth_pos = i;
        }

        if(sum == 0) {
            if(depth > max_depth) {
                max_depth = depth;
            }

            if(seq > seq_length) {
                seq_length = seq;
                seq_pos = i - seq + 1;
            }
            seq = 0;
        }
    }
    cout<<max_depth<<" "<<depth_pos<<" "<<seq_length<<" "<<seq_pos<<endl;
    return 0;
}