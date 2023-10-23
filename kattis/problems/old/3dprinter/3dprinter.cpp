#include <iostream>
#include <vector>
#include <set>
#include <map>

#include <cstdio>

#define REPORT(X) cout << __LINE__ << " " << #X << " = " << X << endl

using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int printers = 1;
  for (int days = 1;; days++, printers *= 2)
    if (printers >= n)
      { cout << days << endl; break; }
}

  
