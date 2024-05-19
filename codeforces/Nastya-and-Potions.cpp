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
        int n, k, a;
        cin >> n >> k;
        vector<long long int> costs(n + 1);
        vector<long long int> res(n + 1, 0);
        vector<int> inDegree(n + 1, 0);
        vector<vector<int> > graph(n + 1, vector<int>());

        for (int i = 1; i <= n; i++)
        {
            cin >> costs[i];
        }

        for (int i = 0; i < k; i++)
        {
            cin >> a;
            costs[a] = 0;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            int m, b;
            cin >> m;

            for (int j = 0; j < m; j++)
            {
                cin >> b;
                int u = i, v = b;
                graph[u].push_back(v);
                inDegree[v]++;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> order;
        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();

            order.push_back(u);
            for (int j = 0; j < graph[u].size(); j++)
            {
                int v = graph[u][j];

                inDegree[v]--;

                if (inDegree[v] == 0)
                    q.push(v);
            }
        }

        reverse(order.begin(), order.end());
        res = costs;
        for (int i = 0; i < order.size(); i++)
        {
            long long int sum = 0;
            int u = order[i];

            for (int j = 0; j < graph[u].size(); j++)
            {
                int v = graph[u][j];
                sum += res[v];
            }

            if (graph[u].size() > 0)
            {
                res[u] = min(res[u], sum);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }

        pn;
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