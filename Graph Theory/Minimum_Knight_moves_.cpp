/*
--------------------------------
- AUTHOR : Trilok Bhattacharya -
- EMAIL : triii.10@outlook.com -
- DATE : 06 Oct, 2020          -
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

bool check(int a, int b) {
    return a < 8 && b < 8 && a >= 0 && b >= 0;
}

int main(int argc, char *argv[])
{
    // <-- Fast I/O -->
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // <-- Multiple test cases -->
    cin>>t;
    while (t--) {
        vector<vector<int>> board(8, vector<int>(8, -1));
        string s;
        pair<int, int> start, end;
        cin>>s;
        start.first = s[0] - 'a';
        start.second = s[1] - '1';
        
        cin>>s;
        end.first = s[0] - 'a';
        end.second = s[1] - '1';

        queue<pair<int, int>> q;
        q.push(start);
        board[start.first][start.second]++;

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if(p == end) 
                break;
            
            if(check(p.first-2, p.second+1) && board[p.first-2][p.second+1] < 0) {
                board[p.first-2][p.second+1] = board[p.first][p.second] + 1;
                q.push({p.first-2, p.second+1});
            }
            if(check(p.first-2, p.second-1) && board[p.first-2][p.second-1] < 0) {
                board[p.first-2][p.second-1] = board[p.first][p.second] + 1;
                q.push({p.first-2, p.second-1});
            }
            if(check(p.first+2, p.second+1) && board[p.first+2][p.second+1] < 0) {
                board[p.first+2][p.second+1] = board[p.first][p.second] + 1;
                q.push({p.first+2, p.second+1});
            }
            if(check(p.first+2, p.second-1) && board[p.first+2][p.second-1] < 0) {
                board[p.first+2][p.second-1] = board[p.first][p.second] + 1;
                q.push({p.first+2, p.second-1});
            }
            
            if(check(p.first-1, p.second+2) && board[p.first-1][p.second+2] < 0) {
                board[p.first-1][p.second+2] = board[p.first][p.second] + 1;
                q.push({p.first-1, p.second+2});
            }
            if(check(p.first-1, p.second-2) && board[p.first-1][p.second-2] < 0) {
                board[p.first-1][p.second-2] = board[p.first][p.second] + 1;
                q.push({p.first-1, p.second-2});
            }
            if(check(p.first+1, p.second+2) && board[p.first+1][p.second+2] < 0) {
                board[p.first+1][p.second+2] = board[p.first][p.second] + 1;
                q.push({p.first+1, p.second+2});
            }
            if(check(p.first+1, p.second-2) && board[p.first+1][p.second-2] < 0) {
                board[p.first+1][p.second-2] = board[p.first][p.second] + 1;
                q.push({p.first+1, p.second-2});
            }
        }
        cout<<board[end.first][end.second];
        cout<<'\n';
    }
    return 0;
}