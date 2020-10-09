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

bool check_border(int r, int c, pair<int, int> p) {
    if(p.first == 0 || p.second == 0 || p.first == r-1 || p.second == c-1)
        return false;
    return true;
}

bool check_neighbours(pair<int, int> p, vector<vector<int>> matrix, int r, int c) {
    int current = matrix[p.first][p.second];
    int up = matrix[p.first-1][p.second];
    int down = matrix[p.first+1][p.second];
    int left = matrix[p.first][p.second-1];
    int right = matrix[p.first][p.second+1];
    if(check_border(r, c, {p.first-1, p.second}) && check_border(r, c, {p.first+1, p.second}) && check_border(r, c, {p.first, p.second-1}) && check_border(r, c, {p.first, p.second+1}))
        if(current < up && current < down && current < left && current < right)
            return true;
        return false;
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
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix;
        map<int, vector<pair<int,int>>> position;
        int i, j;
        forl(i, 0, r) {
            vector<int> row;
            forl(j, 0, c) {
                int input;
                cin>>input;
                row.push_back(input);
                position[input].push_back({i, j});
            }
            matrix.push_back(row);
        }

        int water = 0;
        for(auto height = position.begin(); height != position.end();height++) {
            for(auto point : height->second) {
                if(check_border(r, c, point) && check_neighbours(point, matrix, r, c)) {
                    water++;
                    position[height->first+1].push_back(point);
                    matrix[point.first][point.second]++;
                }
            }
        }
        cout<<water<<'\n';
        cout<<'\n';
    }
    return 0;
}