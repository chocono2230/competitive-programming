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
  int n;
  cin >> n;
  vector<pair<int, int>> wx(n);
  rep(i, n) {
    int w, x;
    cin >> w >> x;
    wx.at(i) = {w, x};
  }
  int ans = 0;
  rep(d, 24) {
    int add = 0;
    for (auto [w, x] : wx) {
      int now = (d + x) % 24;
      if (9 <= now && now < 18) add += w;
    }
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}