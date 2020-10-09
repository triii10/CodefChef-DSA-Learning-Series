#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in(argv[1]);
    string s;

    int n, e;
    in>>s;
    n = stoi(s);
    in>>s;
    e = stoi(s);

    vector<vector<int>> adj(n);
    for(int i = 0;i < e;i++) {
        string x, y;
        in>>x>>y;
        adj[stoi(x)].push_back(stoi(y));
        adj[stoi(y)].push_back(stoi(x));
    }

    for(int i = 0;i < n;i++)
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    int start;
    in>>s;
    start = stoi(s);

    in.close();

    stack<int> st;
    int timer = 0;
    vector<int> in_time(n), out_time(n), color(n);

    st.push(start);
    in_time[start] = timer++;
    color[start] = 1;

    while(!st.empty()) {
        int v = st.top();
        st.pop();
        cout<<v<<" ";
        for(int u : adj[v]) {
            if(!color[u]) {
                in_time[u] = timer;
                st.push(u);
                color[u] = 1;
            }
        }
        out_time[v] = timer++;
        color[v] = 2;
    }
    return 0;
}
