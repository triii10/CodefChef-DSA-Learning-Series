#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;

        int sum = 0, max_length = 0;
        for(int i = 0;i < s.size();i++) {
            sum += (s[i] == '<' ? 1 : -1);

            if(sum == 0) 
                max_length = i+1;

            if(sum < 0)
                break;
        }

        cout<<max_length<<endl;
    }
    return 0;
}