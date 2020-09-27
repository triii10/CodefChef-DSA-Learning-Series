#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t = 1;
    // cin>>t;
    while(t--) {
        int N, X, Y;
        cin>>N>>X>>Y;

        pair<int, int> contest[N];

        for(int i = 0;i < N;i++) {
            int S, E;
            cin>>S>>E;

            contest[i].first = S;
            contest[i].second = E;
        }

        vector<int> W, V;

        for(int i = 0;i < X;i++) {
            int v;
            cin>>v;
            V.push_back(v);
        }
        for(int i = 0;i < Y;i++) {
            int w;
            cin>>w;
            W.push_back(w);
        }

        sort(V.begin(), V.end());

        int min_time = INT_MAX;

        for(int i = 0;i < N;i++) {
            int x = X-1, y = 0;
            while(x >= 0 && V[x] > contest[i].first)
                x--;

            while(y < Y && W[y] < contest[i].second)
                y++;
            // cout<<x<<" "<<y<<endl;
            min_time = min(min_time, W[y] - V[x] + 1);
        }
        cout<<min_time<<endl;
    }
    return 0;
}