/*
--------------------------------
- AUTHOR : Trilok Bhattacharya -
- EMAIL : triii.10@outlook.com -
- DATE : 05 Oct, 2020          -
--------------------------------
*/

// Reference : https://cp-algorithms.com/graph/breadth-first-search.html

/*
The algorithm takes as input an unweighted graph and the id of the source vertex s. 
The input graph can be directed or undirected, it does not matter to the algorithm.

The algorithm can be understood as a fire spreading on the graph: 
at the zeroth step only the source s is on fire.
At each step, the fire burning at each vertex spreads to all of its neighbors. 
In one iteration of the algorithm, 
the "ring of fire" is expanded in width by one unit (hence the name of the algorithm).

More precisely, the algorithm can be stated as follows: 
    Create a queue q which will contain the vertices to be processed 
    and a Boolean array used[] which indicates for each vertex, 
    if it has been lit (or visited) or not.

Initially, push the source s to the queue and set used[s]=true, 
and for all other vertices v set used[v]=false. 
Then, loop until the queue is empty and in each iteration, 
pop a vertex from the front of the queue. 
Iterate through all the edges going out of this vertex 
and if some of these edges go to vertices that are not already lit, 
set them on fire and place them in the queue.

As a result, when the queue is empty, 
the "ring of fire" contains all vertices reachable from the source s, 
with each vertex reached in the shortest possible way. 
You can also calculate the lengths of the shortest paths 
(which just requires maintaining an array of path lengths d[]) 
as well as save information to restore all of these shortest paths 
(for this, it is necessary to maintain an array of "parents" p[], 
which stores for each vertex the vertex from which we reached it).

*/

#include<bits/stdc++.h>
using namespace std;

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


int main(int argc, char const *argv[])
{
    ifstream in(argv[1], ios::in);

    int n, e;
    string inp;

    in>>inp;
    n = stoi(inp);
    in>>inp;
    e = stoi(inp);

    vector<vector<int>> adj;
    for(int i = 0;i < e;i++) {
        string x, y;
        in>>x;
        in>>y;
        adj.push_back({stoi(x), stoi(y)});
    }
    Graph g(n, adj);
    int s;
    in>>inp;
    s = stoi(inp);
    g.perform_bfs(s);
    queue<int> bfs_queue = g.get_bfs_queue();
    
    cout<<"BFS Queue:"<<'\n';
    while(!bfs_queue.empty()) {
        cout<<bfs_queue.front()<<" ";
        bfs_queue.pop();
    }
    cout<<'\n';
    int dest;
    in>>inp;
    dest = stoi(inp);

    vector<int> path = g.get_bfs_path(dest);
    for(int v: path)
        cout<<v<<' ';
    cout<<'\n';
    in.close();
    return 0;
}
