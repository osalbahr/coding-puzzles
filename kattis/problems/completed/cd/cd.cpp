#include <iostream>
#include <unordered_set>

using namespace std;

using ll = long long;

static bool solve()
{
	int n, m;
	cin >> n >> m;
	if (n == 0)
		return false;

	unordered_set<ll> jack;
	while (n--) {
		ll i;
		cin >> i;
		jack.insert(i);
	}

	int ans = 0;
	while (m--) {
		ll i;
		cin >> i;
		ans += jack.count(i);
	}

	cout << ans << endl;

	return true;
}

int main()
{
	while (solve())
		;
}
