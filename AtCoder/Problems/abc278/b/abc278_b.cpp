#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int h, m;
  cin >> h >> m;
  int now = m + h * 60;
  while (1) {
    int h = now / 60, m = now % 60;
    int a = h % 10, b = m / 10;
    int nh = h / 10 * 10 + b, nm = a * 10 + m % 10;
    if (0 <= nh && nh < 24 && 0 <= nm && nm < 60) {
      cout << h << " " << m << endl;
      break;
    }
    now++;
    if (now == 60 * 24) now = 0;
  }
  return 0;
}