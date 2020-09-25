#include<bits/stdc++.h>
using namespace std;

int returnDiff(string s, int x, int y, int mid) {
    vector<int> hash1(26, 0), hash2(26, 0);

    for(int i = 0;i < mid;i++) {
        hash1[s[i]-'a']++;
        hash2[s[y+i]-'a']++;
    }

    int count = 0;

    for(int i = 0;i < 26;i++) {
        count += abs(hash1[i]-hash2[i]);
    }

    return count;
}

int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;

        int mid = s.size()/2;
        int res = returnDiff(s, 0, mid + (s.size()%2 ? 1 : 0), mid);
        
        res > 0 ? cout<<"NO" : cout<<"YES";
        cout<<endl;
    }
    
    
    return 0;
}