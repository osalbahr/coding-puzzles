#include <iostream>
#include <map>
#include <sstream>

#define REPORT(X) cout << #X << " = " << (X) << endl

using namespace std;

map<string, int> name2val;
map<int, string> val2name;

static int getVal(const string& name, bool& valid)
{
	if (!name2val.count(name)) {
		valid = false;
		return 0;
	}

	return name2val.find(name)->second;
}

static void interpret(const string& line)
{
	stringstream ss(line);

	string command;
	ss >> command;

	if (command == "clear") {
		name2val.clear();
		val2name.clear();
		return;
	} else if (command == "def") {
		string name;
		int val;
		ss >> name >> val;
		if (name2val.count(name)) {
			int oldVal = name2val[name];
			val2name.erase(oldVal);
		}
		name2val[name] = val;
		val2name[val] = name;
		return;
	}

	// calc
	bool valid = true;
	int ans = 0;
	string token, op;
	while (ss >> token) {
		if (token == "=") {
			cout << token << " ";
			cout << ( valid && val2name.count(ans) ? val2name[ans] : "unknown" ) << endl;
			break;
		}

		if (token == "+" || token == "-") {
			op = token;
		} else {
			int val = getVal(token, valid);
			if (op == "-") {
				val *= -1;
			}
			ans += val;
		}

		cout << token << " ";
	}

	
}

int main()
{
	string line;
	while ( getline(cin, line) ) {
		interpret(line);
	}
}
