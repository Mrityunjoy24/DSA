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


int dp[4001];
	
int cutRibbon(int n , int a, int b, int c){
	if(n==0)
		return 0;

	if(n<0)
		return -100000;

	if(dp[n]!=-1)
		return dp[n];

	return dp[n] = max(cutRibbon(n-a,a,b,c),max(cutRibbon(n-b,a,b,c),cutRibbon(n-c,a,b,c)))+1;
}

int main()
{
	fastio;
	int n,a,b,c;
	cin >> n >> a >> b >> c;

	memset(dp, -1, sizeof(dp));

	cout << cutRibbon(n,a,b,c);

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