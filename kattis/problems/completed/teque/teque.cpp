#include <iostream>
#include <deque>
#include <sstream>

#include <cstdio>

#define REPORT(X) cout << #X << " = " << (X) << endl;
#define endl "\n"

using namespace std;

deque<int> l1;
deque<int> l2;

// #define DEBUG

static void printdeque()
{
#ifdef DEBUG
	for (auto n : l1) {
		cout << n << " ";
	}
	cout << "[] ";
	for (auto n : l2) {
		cout << n << " ";
	}
	cout << endl;
#endif
}

static void balance()
{
	auto s1 = l1.size(), s2 = l2.size();

	// l1 can be up to one bigger
	if (s2 > s1) {
		auto it = l2.begin();
		l1.push_back(*it);
		l2.erase(it);
	} else if (s1 > s2 + 1) {
		auto it = --l1.end();
		l2.push_front(*it);
		l1.erase(it);
	}

	printdeque();
}

static void pushBack(int i)
{
	l2.push_back(i);
	balance();
	
}

static void pushMiddle(int i)
{
	l2.push_front(i);
	balance();
}

static void pushFront(int i)
{
	l1.push_front(i);
	balance();
}

static void get(int i) {
	auto it = l1.begin();
	if (i >= l1.size()) {
		i -= l1.size();
		it = l2.begin();
	}
    advance(it, i);
    cout << *it << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	string line;
	getline(cin, line);
	while (getline(cin, line)) {
		stringstream ss(line);

		string cmd;
		int i;
		ss >> cmd >> i;

#ifdef DEBUG
		REPORT(line);
#endif

		if (cmd == "push_back") {
			pushBack(i);
		} else if (cmd == "push_front") {
			pushFront(i);
		} else if (cmd == "push_middle") {
			pushMiddle(i);
		} else if (cmd == "get") {
			get(i);
		} else {
			REPORT(line);
			exit(1);
		}

#ifdef DEBUG
		cout << endl;
#endif

	}
}
