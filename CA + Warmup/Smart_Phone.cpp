#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    long long n, temp;
    cin>>n;
    vector<long long> budgets;
    for(int i = 0;i < n;i++) {
        int budget;
        cin>>budget;
        budgets.push_back(budget);
    }

    sort(budgets.begin(), budgets.end());

    long long res = 0;
    for(int i = 0;i < n;i++) {
        if(res < budgets[i]*(n-i))
            res = budgets[i]*(n-i);
    }

    cout<<res<<endl;
    return 0;
}