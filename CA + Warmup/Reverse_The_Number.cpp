#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  // Code goes here
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        int rev = 0;
        while(n){
            rev = (rev*10) + (n%10);
            n /= 10;
        }

        cout<<rev<<endl;

    }
    
    return 0;
}