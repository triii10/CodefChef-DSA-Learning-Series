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

class Graph {
    /**
     * * Class containing the basic graph operations
     * */

    typedef struct bfs {
        vector<bool> used;
        vector<int> d, p;
        queue<int> q;
    } bfs; 

    int n;
    vector<vector<int>> adj;
    bfs *bfs_paths;

    public:
    Graph(int n, vector<vector<int>> pairs) {
        /**
         * @param n -> number of vertices
         * @param paris -> vector of source and destination pairs
         * */
        Graph::n = n;
        Graph::adj = vector<vector<int>>(n);
        for(vector<int> p: pairs) {
            // if(p.empty())
            //     continue;
            int v = p[0];
            int u = p[1];
            Graph::adj[v].push_back(u);
        }
    }

    void perform_bfs(int s) {
        /**
         * @param s -> source vertex
         * * This function performs BFS on the graph stored in the adjacency list
         * */
        queue<int> q;
        bfs_paths = new bfs;
        bfs_paths->used = vector<bool>(Graph::n, false);
        bfs_paths->d = vector<int>(Graph::n);
        bfs_paths->p = vector<int>(Graph::n);
        q.push(s);
        bfs_paths->q.push(s);
        bfs_paths->used[s] = true;
        bfs_paths->p[s] = -1;

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int u : adj[v]) {
                if(!bfs_paths->used[u]) {
                    bfs_paths->used[u] = true;
                    q.push(u);
                    bfs_paths->q.push(u);
                    bfs_paths->d[u] = bfs_paths->d[v]+1;
                    bfs_paths->p[u] = v;
                }
            }
        }
    }

    queue<int> get_bfs_queue(){
        /**
         * * Returns a queue containing the BFS traversal
         * */
        try {
            if(bfs_paths->q.empty())
                throw "Queue contains no vertices";
            return bfs_paths->q;
        } catch(string e) {
            cout<<e<<'\n';
        }
        return {};
    }


    vector<int> get_bfs_path(int dest) {
        /**
         * @param dest -> destination node to find the shortest path
         * * Returns a vector of the shortest path containing the vertices to traverse
         * */
        try {
            if(!bfs_paths->used[dest]) 
                throw "No path found";
            else {
                vector<int> path;
                for(int v = dest;v != -1; v = bfs_paths->p[v])
                    path.push_back(v);
                reverse(path.begin(), path.end());
                return path;
            }
        } catch(string e) {
            cout<<e<<'\n';
        }
        return {};
    }
};

int main(int argc, char *argv[])
{
    // <-- Fast I/O -->
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // <-- Multiple test cases -->
    // cin>>t;
    while (t--) {
        int n, m, k;
        cin>>n>>m>>k;

        vector<vector<int>> pairs;
        int i;
        forl(i, 0, m) {
            int x, y;
            cin>>x>>y;
            pairs.push_back({x, y});
        }
        Graph g(n, pairs);
        vector<vector<int>> triplets;
        forl(i, 0, k) {
            int a, b, c;
            cin>>a>>b>>c;
            triplets.push_back({a, b, c});
        }

        
        cout<<'\n';
    }
    return 0;
}