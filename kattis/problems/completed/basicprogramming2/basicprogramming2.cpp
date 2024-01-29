#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <map>

using namespace std;

using ll = long long;

static string case1(vector<int>& a)
{
    sort(a.begin(), a.end());
    int left = 0;
    int right = a.size() - 1;

    while (left < right) {
        int sum = a[left] + a[right];
        if (sum == 7777) {
            return "Yes";
        } else if (sum < 7777) {
            left++;
        } else {
            right--;
        }
    }
    return "No";
}

static string case2(const vector<int>& a)
{
	unordered_set<int> s;
	for (auto n : a)
		s.insert(n);
	
	if (a.size() == s.size()) {
		return "Unique";
	} else {
		return "Contains duplicate";
	}
}

static int case3(const vector<int>& a)
{
    unordered_multiset<int> counts;
    int threshold = a.size() / 2;

    for (auto n : a) {
        counts.insert(n);
        if (counts.count(n) > threshold) {
            return n;
        }
    }

	return -1;
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
		cout << case1(a) << endl;
		break;
	case 2:
		cout << case2(a) << endl;
		break;
	case 3:
		cout << case3(a) << endl;
		break;
	case 4:
		sort(a.begin(), a.end());
		if (a.size() % 2) {
			cout << a[n / 2] << endl;
		} else {
			cout << a[n / 2 - 1] << " " << a[n / 2] << endl;
		}
		break;
	case 5:
		sort(a.begin(), a.end());
		for (auto n : a) {
			if (n >= 100 && n <= 999) {
				cout << n << " ";
			}
		}
		cout << endl;
		break;
	default:
		cerr << "Error: invalid t = " << t << endl;
		exit(1);
	}
}
