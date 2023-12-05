#include <iostream>
#include <vector>

using namespace std;

int solve(int base, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    int power = 1;
    while (power <= n) {
        for (int i = power; i <= n; i++) {
            dp[i] += dp[i - power];
        }
        power *= base;
    }

    return dp[n];
}

int main()
{
    int p, k, m, n;

    cin >> p;
    while (p--) {
        cin >> k >> m >> n;
        cout << k << " " << solve(m, n) << endl;
    }
}
