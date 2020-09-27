/*
--------------------------------
- AUTHOR : Trilok Bhattacharya -
- EMAIL : triii.10@outlook.com -
- DATE : 27 Sep, 2020          -
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

int main(int argc, char *argv[])
{
    // <-- Fast I/O -->
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // <-- Multiple test cases -->
    // cin>>t;
    while (t--) {
        int chefs, mails;
        cin>>chefs>>mails;

        int i;
        map<string, string> chef_country;
        map<string, int>chef_count, country_count;
        forl(i, 0, chefs) {
            string chef, country;
            cin>>chef>>country;

            chef_country[chef] = country;
        }

        int max_country_count = 0, max_chef_count = 0;
        string max_chef = "", max_country = "";
        forl(i, 0, mails) {
            string chef;
            cin>>chef;

            chef_count[chef]++;
            country_count[chef_country[chef]]++;

            if(chef_count[chef] >= max_chef_count) {
                if(chef_count[chef] == max_chef_count) {
                    if(chef < max_chef)
                        max_chef = chef;
                }
                else
                    max_chef = chef;
                max_chef_count = chef_count[chef];
            }
            if(country_count[chef_country[chef]] >= max_country_count) {
                if(country_count[chef_country[chef]] == max_country_count) {
                    if(chef_country[chef] < max_country)
                        max_country = chef_country[chef];
                }
                else
                    max_country = chef_country[chef];
                max_country_count = country_count[chef_country[chef]];
            }

        }
        // cout<<chef_count<<endl<<country_count;
        cout<<max_country<<"\n"<<max_chef<<"\n";
    }
    return 0;
}