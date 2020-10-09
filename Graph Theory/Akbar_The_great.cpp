/*
--------------------------------
- AUTHOR : Trilok Bhattacharya -
- EMAIL : triii.10@outlook.com -
- DATE : 05 Oct, 2020          -
--------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// <-- Template code for utility -->
#define watch(x) cout << (#x) << " is " << (x) << endl
#define forl(i, b, e) for (i = b; i < e; i++)
#define fore(i, b, e) for (i = b; i <= e; i++)

void input_arr(vector<int> &arr, int n)
{
    int i;
    forl(i, 0, n)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
}

template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    bool first = true;
    os << "[";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::set<T> &v)
{
    bool first = true;
    os << "[";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}

template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::map<T1, T2> &v)
{
    bool first = true;
    os << "[";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}

// <-- Main funtion -->
// This is where the actual program is

// Problem link : https://www.spoj.com/problems/AKBAR/

int main(int argc, char *argv[])
{
    // <-- Fast I/O -->
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // <-- Multiple test cases -->
    cin>>t;
    while (t--) {
        int n, r, m;
        cin>>n>>r>>m;

        vector<int> used(n, 0);

        vector<vector<int>>graph(n, vector<int>());
        int i;
        forl(i, 0, r) {
            int a, b;
            cin>>a>>b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        vector<pair<int, int>> soldiers;
        forl(i, 0, m) {
            int k, s;
            cin>>k>>s;
            soldiers.push_back({k-1, s});
        }
        string status = "Yes";
        forl(i, 0, m) {

            queue<pair<int, int>> q;
            vector<bool> visited(n, false);
            q.push({soldiers[i].first, soldiers[i].second});
            used[soldiers[i].first]++;
            visited[soldiers[i].first] = true;

            while(!q.empty()) {
                pair<int, int> v = q.front();
                q.pop();
                if(used[v.first] > 1) {
                    status = "No";
                    break;
                }
                if(v.second <= 0) {
                    break;
                }
                
                for(int u : graph[v.first]) {
                    // if(!visited[u]) {
                        used[u]++;
                        q.push({u, v.second-1});
                    // }
                }
            }
        }
        // cout<<used;
        // for(int i: used)
        //     if(i < 1) {
        //         status = "No";
        //         break;
        //     }
        cout<<status;
        cout<<'\n';
    }
    return 0;
}