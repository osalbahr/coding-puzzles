#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> s(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> s[i] >> b[i];
	
	int globalMin = 1000000000;
	int totalSour = 1, totalBitter = 0;
	for (int i = 1; i < pow(2, n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				totalSour *= s[j];
				totalBitter += b[j];
			}
		}
		globalMin = min(globalMin, abs(totalSour - totalBitter));
		totalSour = 1;
		totalBitter = 0;
	}

	cout << globalMin << endl;
}
