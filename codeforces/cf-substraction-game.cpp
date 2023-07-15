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

int main()
{
    fastio;
    int t;

    cin >> t;

    wh(t)
    {
        int a, b;
        cin >> a >> b;
        int ans = -1;

        if (a == 1)
        {
            if (b == 2)
                ans = 3;
            else
                ans = 2;
        }
        else
        {
            ans = a - 1;
        }

        cout << ans << endl;
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