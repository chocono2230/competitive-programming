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
  vector<pair<ll, int>> a(n, {0, -1});
  rep(i, n) cin >> a.at(i).first;
  int q;
  cin >> q;
  int key = -1, tt = -2;
  rep(p, q) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      cin >> key;
      tt = p;
    }
    if (mode == 2) {
      int idx, add;
      cin >> idx >> add;
      idx--;
      auto [x, y] = a.at(idx);
      if (y > tt) {
        a.at(idx).first += add;
      } else {
        a.at(idx).first = key + add;
      }
      a.at(idx).second = p;
    }
    if (mode == 3) {
      int idx;
      cin >> idx;
      idx--;
      auto [x, y] = a.at(idx);
      ll ans = x;
      if (y < tt) {
        ans = key;
      }
      a.at(idx).first = ans;
      a.at(idx).second = p;
      cout << ans << endl;
    }
  }
  return 0;
}