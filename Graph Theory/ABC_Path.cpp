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

bool pos_check(pair<int, int> p, int r, int c, vector<vector<int>>& matrix, int x) {
    return (p.first >= 0 && p.second >= 0 && p.first < r && p.second < c) && (matrix[p.first][p.second] == x+1);
}

int main(int argc, char *argv[])
{
    // <-- Fast I/O -->
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // <-- Multiple test cases -->
    // cin>>t;
    while (1) {
        int r, c;
        cin>>r>>c;
        if(r == 0 && c == 0)
            break;
        vector<vector<int>> matrix;
        vector<pair<int, int>> A;
        int i, j;
        forl(i, 0, r) {
            vector<int> row;
            char input;
            forl(j, 0, c) {
                cin>>input;
                row.push_back(input);
                if(input == 'A')
                    A.push_back({i, j});
            }
            matrix.push_back(row);
        }

        int count = 0;
        for(auto pos : A) {
            stack<pair<int, int>> st;
            st.push(pos);
            while(!st.empty()) {
                pair<int, int> p = st.top();
                int x = matrix[p.first][p.second];
                count = max(count, x-'A'+1);
                st.pop();

                if(pos_check({p.first+1, p.second}, r, c, matrix, x))
                    st.push({p.first+1, p.second});
                if(pos_check({p.first-1, p.second}, r, c, matrix, x))
                    st.push({p.first-1, p.second});
                if(pos_check({p.first+1, p.second+1}, r, c, matrix, x))
                    st.push({p.first+1, p.second+1});
                if(pos_check({p.first-1, p.second-1}, r, c, matrix, x))
                    st.push({p.first-1, p.second-1});

                if(pos_check({p.first, p.second+1}, r, c, matrix, x))
                    st.push({p.first, p.second+1});
                if(pos_check({p.first, p.second-1}, r, c, matrix, x))
                    st.push({p.first, p.second-1});
                if(pos_check({p.first+1, p.second-1}, r, c, matrix, x))
                    st.push({p.first+1, p.second-1});
                if(pos_check({p.first-1, p.second+1}, r, c, matrix, x))
                    st.push({p.first-1, p.second+1});
            }
        }
        cout<<"Case "<<t++<<": "<<count;
        cout<<'\n';
    }
    return 0;
}