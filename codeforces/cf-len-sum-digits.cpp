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

int dp1[4001][4001], dp2[4001][4001];


int minNumber(int pos, int m, int s, int num)
{
	if (pos == m+1 && s == 0)
	{
		return num;
	}

	if (pos > m || s < 0)
		return INT_MAX;

	if (dp1[pos][s] != -1)
		return dp1[pos][s];

	int start = (pos == 1) ? 1 : 0;

	int ans = INT_MAX;
	for (int i = start; i <= 9; i++)
	{
		ans = min(ans, minNumber(pos + 1, m, s - i, num * 10 + i));
	}

	return dp1[pos][s] = ans;
}



int maxNumber(int pos, int m, int s, int num)
{
	if (pos == m+1 && s == 0)
	{
		return num;
	}

	if (pos > m || s < 0)
		return INT_MIN;

	if (dp2[pos][s] != -1)
		return dp2[pos][s];

	int start = (pos == 1) ? 1 : 0;

	int ans = INT_MIN;
	for (int i = start; i <= 9; i++)
	{
		ans = max(ans, maxNumber(pos + 1, m, s - i, num * 10 + i));
	}

	return dp2[pos][s] =  ans;
}

int main()
{
	fastio;
	int m, s;
	cin >> m >> s;

	int minNum = INT_MAX, maxNum = INT_MIN;

	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));

	minNum = minNumber(1, m, s, 0);
	maxNum = maxNumber(1, m, s, 0);

	if (minNum == INT_MAX)
		cout << "-1 -1";
	else
		cout << minNum << " " << maxNum;

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