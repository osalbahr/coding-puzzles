#include <iostream>
#include <vector>

#define REPORT(X) cout << __LINE__ << " " << #X << " = " << X << endl

using namespace std;

int main()
{
  vector<int> v = { 4, 3, 2, 7, 6, 5, 0, 4, 3, 2, 1 };
  string str;
  cin >> str;
  int total = 0;
  for (int i = 0; i < str.size(); i++)
    total += (str[i] - '0') * v[i];
  cout << !(total % 11) << endl;
}
