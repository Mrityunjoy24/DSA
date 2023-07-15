/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;

// int totalWays(string s, int pos, int k, vector<int> &dp, int mod)
// {

//     if (pos >= s.length())
//     {
//         return 1;
//     }

//     if (dp[pos] != -1)
//         return dp[pos];

//     dp[pos] = 0;

//     string number = "";
//     for (int i = pos; i < s.length(); i++)
//     {
//         number += s[i];
//         long long int num = stol(number);

//         if (num >= 1 && num <= k)
//         {
//             dp[pos] = (dp[pos] + totalWays(s, i + 1, k, dp, mod)) % mod;
//         }
//         else
//             break;
//     }

//     return dp[pos];
// }

int main(int argc, char *a[])
{
    // Write code here
    long long int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<long long int> dp(n + 1, 0);
    int mod = 1000000007;

    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            string number = s.substr(i, j - i + 1);
            long long int num = stol(number);
            
            if (num >= 1 && num <= k)
            {
                dp[i] = (dp[i] + dp[j + 1]) % mod;
            }
            else
                break;
        }
    }

    cout << dp[0];
}