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
int main()
{
    fastio;
    int t;

    // cin >> t;

    // wh(t)
    // {
    int n, l;
    cin >> n >> l;

    vector<int> rank(n);

    for (int i = 0; i < n; i++)
    {
        cin >> rank[i];
    }

    int superior = 1;
    sort(rank.begin(), rank.end());

    int diff = 0;
    for (int i = 1; i < n; i++)
    {
        diff = max(diff, rank[i] - rank[i - 1]);
    }

    diff = max(diff, rank[0] * 2);
    diff = max(diff, (l - rank[n - 1]) * 2);

    double ans = diff / 2.0;
    cout << fixed << setprecision(10) << ans;

    // pn;
    // }

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