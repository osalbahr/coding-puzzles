#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

using ll = long long;

static int median(int a, int b, int c)
{
	vector<int> v = {a, b, c};
	sort(v.begin(), v.end());
	return v[1];
}

static ll sumEven(const vector<int>& a)
{
	ll ret = 0;
	for (const auto n : a)
		if (n % 2 == 0)
			ret += n;

	return ret;
}

static string case7(const vector<int>& a)
{
	set<int> seen;
	size_t i = 0;
	while (i >= 0 && i < a.size()) {
		if (i == a.size() - 1) {
			return "Done";
		}
		if (! seen.insert(i).second) {
			return "Cyclic";
		}
		i = a[i];
	}
	return "Out";
}

int main()
{
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		cin >> a[i];
	}

	switch (t) {
	case 1:
		cout << 7 << endl;
		break;
	case 2:
		if (a[0] > a[1]) {
			cout << "Bigger" << endl;
		} else if (a[0] == a[1]) {
			cout << "Equal" << endl;
		} else {
			cout << "Smaller" << endl;
		}
		break;
	case 3:
		cout << median(a[0], a[1], a[2]) << endl;
		break;
	case 4:
		cout << accumulate(a.begin(), a.end(), 0LL) << endl;
		break;
	case 5:
		cout << sumEven(a) << endl;
		break;
	case 6:
		for (auto& n : a) {
			char ch = 'a' + n % 26;
			cout << ch;
		}
		cout << endl;
		break;
	case 7:
		cout << case7(a) << endl;
		break;
	default:
		cerr << "Error: invalid t = " << t << endl;
		exit(1);
	}
}
