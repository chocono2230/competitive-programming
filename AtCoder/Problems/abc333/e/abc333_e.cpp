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
  vector<pair<int, int>> tx(n);
  rep(i, n) {
    int t, x;
    cin >> t >> x;
    tx.at(i) = {t, x};
  }
  reverse(ALL(tx));
  vector<int> v;
  auto fc = [&]() {
    int res = 0, now = 0;
    vector<int> co(n + 5, 0);
    for (auto [t, x] : tx) {
      if (t == 2) {
        co.at(x)++;
        now++;
        res = max(res, now);
      } else {
        v.push_back(0);
        if (co.at(x) == 0) continue;
        co.at(x)--;
        now--;
        v.back() = 1;
      }
    }
    rep(i, n + 5) {
      if (co.at(i) != 0) return n + 1;
    }
    return res;
  };
  int ans = fc();
  if (ans == n + 1) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  reverse(ALL(v));
  rep(i, v.size()) {
    if (i != 0) cout << " ";
    cout << v.at(i);
  }
  cout << endl;
  return 0;
}