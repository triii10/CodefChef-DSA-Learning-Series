#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    unordered_map<string, int> code;
    code["INDIAN"] = 200;
    code["NON_INDIAN"] = 400;
    code["CONTEST_WON"] = 3;
    code["TOP_CONTRIBUTOR"] = 4;
    code["BUG_FOUND"] = 5;
    code["CONTEST_HOSTED"] = 6;

    int t;
    cin>>t;
    while(t--) {
        int laddus = 0;

        string region;
        int activities;

        cin>>activities>>region;

        while(activities--) {
            string activity;
            cin>>activity;
            switch (code[activity])
            {
            case 3:
                int rank;
                cin>>rank;

                laddus += 300 + (rank > 20 ? 0 : 20-rank);
                break;
            
            case 4:
                laddus += 300;
                break;
            
            case 5:
                int severity;
                cin>>severity;
                laddus += severity;
                break;
            
            case 6:
                laddus += 50;
                break;

            default:
                break;
            }
        }

        cout<<laddus/code[region]<<endl;
    }
    return 0;
}