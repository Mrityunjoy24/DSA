#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define wh(t) while (t--)
#define ll long long
#define pb push_back
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

// 0 3 5 7 9 14 15
// 0 - 6
int main()
{
    fastio;
    int t;

    long long int n;
    cin >> n;

    vector<int> digits;

    while (n > 0)
    {
        digits.push_back(n % 10);
        n = n / 10;
    }

    int x = digits.size();

    f(i, 0, x - 1)
    {
        if (digits[i] >= 5)
        {
            digits[i] = 9 - digits[i];
        }
    }

    if (digits[x - 1] >= 5 && digits[x - 1] != 9)
    {
        digits[x-1] = 9 - digits[x-1];
    }

    long long int ans = 0;

    fj(j, x, 0)
    {
        ans = ans * 10LL + digits[j];
    }

    c(ans);

    return 0;
}

// 4 12
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

// 10 10 20 30 30
// 20 20 30 10 10
// 30 30 10 20 20

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