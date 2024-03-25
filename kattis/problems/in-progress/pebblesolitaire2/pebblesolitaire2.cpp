#include <iostream>

using namespace std;

#define REPORT(X) cout << #X << " = " << (X) << endl

static int solve(const string& board)
{
	int ans = 0;
	for (char ch : board)
		ans += ch == 'o';

	for (size_t i = 0; i < board.size() - 2; i++) {
		REPORT(i);
		REPORT(board);

		// -oo
		if (board.substr(i, 3) == "-oo") {
			string newboard = board;
			newboard[i] = 'o';
			newboard[i + 2] = '-';
			ans = min(ans, solve(newboard));
		}

		// oo-
		if (board.substr(i, 3) == "oo-") {
			string newboard = board;
			newboard[i] = '-';
			newboard[i + 2] = 'o';
			ans = min(ans, solve(newboard));
		}
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	while (n--) {
		REPORT(n);
		string board;
		cin >> board;
		cout << solve(board) << endl;
	}
}
