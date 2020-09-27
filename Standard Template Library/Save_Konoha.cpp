#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t = 1;
    cin>>t;
    while(t--) {
        int n, z;
        cin>>n>>z;
        vector<int> soldiers;

        for(int i = 0;i < n;i++) {
            int power;
            cin>>power;
            soldiers.push_back(power);
        }

        int count = 0;
        make_heap(soldiers.begin(), soldiers.end());

        while(!soldiers.empty() && z > 0) {
            count++;
            int val = soldiers.front();
            pop_heap(soldiers.begin(), soldiers.end());
            soldiers.pop_back();

            
            z -= val;

            val /= 2;
            if(val) {
                soldiers.push_back(val);
                push_heap(soldiers.begin(), soldiers.end());
            }
        }

        if(z > 0) {
            cout<<"Evacuate"<<endl;
        }
        else 
            cout<<count<<endl;
    }
    return 0;
}