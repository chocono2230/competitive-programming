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
  int x, y;
  cin >> x >> y;
  bool ans = false;
  if (x == 1) {
    if (y == 2) ans = true;
  }
  if (x == 2) {
    if (y == 3) ans = true;
  }
  if (x == 4) {
    if (y == 5) ans = true;
  }
  if (x == 5) {
    if (y == 6) ans = true;
  }
  if (x == 7) {
    if (y == 8) ans = true;
  }
  if (x == 8) {
    if (y == 9) ans = true;
  }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}