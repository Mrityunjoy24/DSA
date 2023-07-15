#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define wh(t) while (t--)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define f(i, a, n) for (int i = a; i < n; i++)
#define fj(j, n, b) for (ll j = n - 1; j >= b; j--)
#define c(n) cout << n << "\n";
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fg cout << "flag\n";
#define pn cout << "\n";
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) * (b)) / __gcd((a), (b))
// sum of nos in range div by a
#define rangesum(l, r, a) ((r * (r / a + 1)) / 2) - (((l - 1) * ((l - 1) / a + 1)) / 2)

long long int  dp[501][501];
long long int solve(vector<int> &arr, int i, int j)
{
    if (i > j)
        return 0;

    if(i==j)
        return arr[i];

    if (dp[i][j] != -1)
        return dp[i][j];

    long long int ans = LONG_MIN;

    for (int k = i; k <= j; k++)
    {
        long long int temp_ans = solve(arr, i, k - 2) + solve(arr, k + 2, j) + ;
        ans = max(ans, temp_ans);
    }

    return dp[i][j] = ans;
}

int main()
{
    fastio;
    int t;

    cin >> t;

    wh(t)
    {
        int n;
        cin >> n;

        vector<int> nums(n);

        f(i, 0, n)
        {
            cin >> nums[i];
        }

        // nums.push_back(0);     
        nums.push_back(0);            // if i+1 goes out of bound so to avoid this add 1
        nums.insert(nums.begin(), 0); // if i-1 goes out of bound so to avoid this add 1
        // nums.insert(nums.begin(), 0);
        memset(dp, -1, sizeof(dp));
        cout << solve(nums, 2, n+1) << endl;
    }

    return 0;
}

/*

          .=     ,        =.
  _  _   /'/    )\,/,/(_   \ \
   `//-.|  (  ,\\)\//\)\/_  ) |
   //___\   `\\\/\\/\/\\///'  /
,-"~`-._ `"--'_   `"""`  _ \`'"~-,_
\       `-.  '_`.      .'_` \ ,-"~`/
 `.__.-'`/   (-\        /-) |-.__,'
   ||   |     \O)  /^\ (O/  | .        <-  BESSIE THE COW
   `\\  |         /   `\    /
     \\  \       /      `\ /
      `\\ `-.  /' .---.--.\
        `\\/`~(, '()      ('
         /(O) \\   _,.-.,_)
        //  \\ `\'`      /
       / |  ||   `""""~"`
     /'  |__||
           `o
*/