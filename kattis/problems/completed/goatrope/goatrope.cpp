#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

#define REPORT(X) cout << #X << " = " << (X) << endl

#define x first
#define y second

void solve()
{
  
}

int main()
{
  int x, y, x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;

  if (x1 < x && x < x2) {
    cout << min( abs(y - y1), abs(y - y2) ) << endl;
    return 0;
  } else if (y1 < y && y < y2) {
    cout << min( abs(x - x1), abs(x - x2) ) << endl;
    return 0;
  }

  vector<pair<int,int>> arr {
    { x1, y1 },
    { x1, y2 },
    { x2, y1 },
    { x2, y2 },
  };

  double ret = 10000*10000;
  for (const auto& p : arr) {
    int dx = x-p.x;
    int dy = y-p.y;
    double dist = sqrt( dx*dx + dy*dy );
    ret = min(ret, dist);
  }
  
  printf("%.5f\n", ret);
}
