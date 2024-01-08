#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

static bool solve()
{
	// Note: only needed once
	vector<char> vowelVec = {'a', 'e', 'i', 'o', 'u', 'y'};
	unordered_set<char> vowels;
	for (auto ch : vowelVec) {
		vowels.insert(ch);
	}

	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}

	int maxCount = -1; 
	string winnerWord = "";

	while (n--) {
		int curCount = 0;

		string word;
		cin >> word;
		for (size_t i = 0; i < word.size() - 1; i++) {
			char ch = word[i];
			if (ch == word[i+1] && vowels.count(ch)) {
				curCount++;
				i++;
			}
		}

		if (curCount > maxCount) {
			maxCount = curCount;
			winnerWord = word;
		}
	}

	cout << winnerWord << endl;
	return true;
}

int main()
{
	

	while (solve())
		;
}
