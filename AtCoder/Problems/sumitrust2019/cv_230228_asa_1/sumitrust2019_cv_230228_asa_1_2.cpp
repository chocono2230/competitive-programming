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
  int x;
  cin >> x;
  vector<bool> dp(x + 1, false);
  dp.front() = true;
  rep(i, dp.size()) {
    rep(nx, 6) {
      int ni = i + 100 + nx;
      if (ni >= dp.size()) continue;
      dp.at(ni) = dp.at(i) | dp.at(ni);
    }
  }
  if (dp.back())
    cout << 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}