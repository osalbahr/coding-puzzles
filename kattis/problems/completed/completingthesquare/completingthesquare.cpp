#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define x first
#define y second

using namespace std;

int main()
{
  vector<pair<int,int>> v(3);
  for (int i = 0; i < 3; i++)
    cin >> v[i].x >> v[i].y;

  int maxDiff = -1;
  int iStart = -1;
  for (int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    int dx = v[i].x - v[j].x;
    int dy = v[i].y - v[j].y;
    int diff = dx * dx + dy * dy;
    if (diff > maxDiff) {
      maxDiff = diff;
      iStart = i;
    }
  }

  const auto& p1 = v[iStart];
  const auto& p2 = v[(iStart + 1) % 3];
  const auto& p3 = v[(iStart + 2) % 3];

  double midX = (p1.x + p2.x) / 2.0;
  double midY = (p1.y + p2.y) / 2.0;

  double newX = 2 * midX - p3.x;
  double newY = 2 * midY - p3.y;

  cout << round(newX) << " " << round(newY) << endl;
}
