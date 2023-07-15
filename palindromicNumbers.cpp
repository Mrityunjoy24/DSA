#include <bits/stdc++.h>
using namespace std;

// int mod = 1000000007;
int dp[40][2];

bool checkPalindromic(vector<int> &num)
{
    int i = 0, j = num.size() - 1;
    while (i < j)
    {
        if (num[i] != num[j])
            return false;
        i++;
        j--;
    }
    return true;
}

vector<int> convert(long long int n)
{
    vector<int> v;
    while (n)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    return v;
}

long long int digitDp(vector<int> &num, vector<int> &temp, int pos, int f)
{
    if (pos >= num.size())
    {
        if (checkPalindromic(temp))
        {
            // for (int i = 0; i < temp.size(); i++)
            //     cout << temp[i] << " ";

            // cout << endl;
            return 1;
        }
        return 0;
    }

    if (dp[pos][f] != -1)
        return dp[pos][f];

    long long int res = 0;
    int LMT;

    if (f == 0)
        LMT = num[pos];
    else
        LMT = 9;

    for (int i = 0; i <= LMT; i++)
    {
        int nf = f;
        if (f == 0 && i < LMT)
            nf = 1;
        temp.push_back(i);
        res = (res + digitDp(num, temp, pos + 1, nf));
        temp.pop_back();
    }

    dp[pos][f] = res;
    return res;
}

int count(long long int n1, long long int n2)
{
    vector<int> num1 = convert(n1 - 1);
    vector<int> num2 = convert(n2);

    vector<int> temp;

    memset(dp, -1, sizeof(dp));

    int ans2 = digitDp(num2, temp, 0, 0);

    memset(dp, -1, sizeof(dp));
    temp.clear();
    // int ans1 = 0;
    int ans1 = digitDp(num1, temp, 0, 0);
    return ans2 - ans1;
}

int main()
{
    int t;
    cin >> t;
    t = 1;
    while (t--)
    {
        long long int num1, num2;
        cin >> num1 >> num2;
        // num1 = 11;
        // num2 = 200;
        cout << count(num1, num2) << endl;
    }

    return 0;
}