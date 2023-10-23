#include <iostream>
#include <vector>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>

#define REPORT(X) cout << __LINE__ << " " << #X << " = " << X << endl

using namespace std;

int main()
{
  string str;
  cin >> str;
  cout << hex << strtol(str.c_str(), nullptr, 8) << endl;
}
