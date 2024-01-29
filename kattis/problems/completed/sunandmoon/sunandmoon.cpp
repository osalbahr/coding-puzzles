#include <iostream>

using namespace std;

int main()
{
	int ds, ys,
		dm, ym;
	
	cin >> ds >> ys >> dm >> ym;
	
	int nextSun = ys - ds;
	int nextMoon = ym - dm;

	while (nextSun != nextMoon) {
		if (nextSun < nextMoon) {
			nextSun += ys;
		} else {
			nextMoon += ym;
		}
	}

	cout << nextSun << endl;
}
