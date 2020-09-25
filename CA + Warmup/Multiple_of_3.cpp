#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
// Code goes here
    int t;
    cin>>t;
    while(t--) {
        long long K, d0, d1, sum = 0, digit = 0, len = 0;
        cin>>K>>d0>>d1;

        sum = (d0+d1)%3;
        K -= 2;
        digit = (d0+d1)%10;

        vector<int> graph(10, -1);
        int i = 0;
        while(graph[digit] < 0 && (i++ < K)) {
            sum = (sum+digit)%3;
            int new_digit = (digit*2) % 10;
            graph[digit] = new_digit;
            digit = new_digit;
        }

        if(i < K) {
            
            int start = digit, sum2 = 0;

            do {
                sum2 += digit;
                int new_digit = graph[digit];
                len++;
                digit = new_digit;
            }while(digit != start);

            K -= (i);

            sum2 %= 3;
            
            for(int _ = 0;_ < (K%len);_++) {
                sum += digit;
                digit = graph[digit];
            }

            sum = ( sum + (sum2 * (K/len))%3) % 3;
        }
        
        cout<<(sum ? "NO" : "YES")<<endl;
        
    }
    return 0;
}