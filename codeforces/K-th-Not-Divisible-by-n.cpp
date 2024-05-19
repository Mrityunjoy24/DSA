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

    cin >> t;

    wh(t)
    {
        int n, k, ans = 0;
        cin >> n >> k;

        long long int l = 0, h = min((long long int)n * k, 2000000000LL);

        while (l <= h)
        {
            long long int mid = (l + h) / 2; //3 , 1
            int num = mid - (mid / n); // 3 - 3/3 , 1 - 1/3

            if (num >= k)
            {
                ans = mid;
                h = mid - 1; //h=2
            }
            else
            {
                l = mid + 1; // l = 2
            }
        }

        c(ans);
        // pn;
    }

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