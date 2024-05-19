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

int main()
{
    fastio;
    int t;

    cin >> t;

    wh(t)
    {
        int n, ans = -1;
        cin >> n;

        vector<vector<int> > ranks(n + 1, vector<int>(5, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 5; j++)
                cin >> ranks[i][j];
        }

        int superior = 1;
        for (int i = 1; i <= n; i++)
        {
            int p = 0;
            for (int k = 0; k < 5; k++)
            {
                if (ranks[i][k] < ranks[superior][k])
                    p++;
            }

            if (p >= 3)
            {
                superior = i;
            }
        }

        bool ok = true;

        for (int i = 1; i <= n; i++)
        {
            int p = 0;
            for (int k = 0; k < 5; k++)
            {
                if (ranks[i][k] < ranks[superior][k])
                    p++;
            }

            if (p >= 3)
            {
                ok = false;
                break;
            }
        }

        cout << ((ok) ? superior : ans);

        pn;
    }

    return 0;
}

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