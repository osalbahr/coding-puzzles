#include <iostream>
#include <vector>
#include <set>

#define REPORT(X) cout << #X << " = " << (X) << endl

using namespace std;

int main()
{
	int w, p;
	cin >> w >> p;

	vector<int> l(p + 2);
	l[0] = 0;
	for (size_t i = 1; i <= p; i++) {
		cin >> l[i];
	}
	l[l.size() - 1] = w;

	set<int> widths;
	for (size_t i = 0; i < l.size(); i++) {
		for (size_t j = i + 1; j < l.size(); j++) {
			widths.insert( l[j] - l[i] );
		}
	}

	for (auto n : widths) {
		cout << n << " ";
	}
	cout << endl;
}
