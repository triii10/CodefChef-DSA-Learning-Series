#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while(t--) {
        int n, u;
        cin>>n>>u;

        vector<int> nums;
        for(int i = 0;i < n;i++) {
            int inp;
            cin>>inp;
            nums.push_back(inp);
        }

        int front = 0, back = 0, nunique = 0, max_len = 0;
        unordered_map<int, int> count;
        while(back < n) {
            if(count[nums[back]] == 0) {
                nunique++;
            }
            count[nums[back]]++;
            
            if(nunique == u) {
                max_len = max(max_len, back-front);
                while(front <= back && --count[nums[front++]] > 0);
                nunique--;
            }
            back++;
        }

        if(u > nunique)
            max_len = max(max_len, back-front);
        cout<<max_len<<endl;
    }
    return 0;
}