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
  ll n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  auto ts = s;
  ll ans = 0;

  auto fc = [&]() -> void {
    vector<pair<bool, int>> v;
    v.push_back({s.front() == 'o', 0});
    rep(i, s.size()) {
      if ((s.at(i) == 'o') != v.back().first) v.push_back({s.at(i) == 'o', 0});
      v.back().second++;
    }
    int xco = 0;
    rep(i, v.size()) {
      if (!v.at(i).first) xco += v.at(i).second;
    }
    if (m != 1) s += s;
    vector<int> memo(s.size());
    int l = 0, u = 0, kk = k % xco;
    if (kk == 0) kk = xco;
    rep(r, s.size()) {
      if (s.at(r) == 'x') {
        while (u == kk) {
          if (s.at(l) == 'x') u--;
          l++;
        }
        u++;
      }
      memo.at(r) = r - l + 1;
      // cerr << r << " " << l << " " << r - l + 1 << endl;
      ans = max(ans, (ll)r - l + 1);
    }
    rep(i, memo.size()) cerr << i << " " << memo.at(i) << endl;
    cerr << endl;
    if (xco > k || m == 1) {
      if (xco * m == k) ans = n * m;
      return;
    }
    rep2(i, n, s.size()) {
      ll add = k / xco * n + memo.at(i);
      if (add) ans = max(ans, add);
    }
    if (xco * m == k) ans = n * m;
    return;
  };
  fc();
  reverse(ALL(ts));
  s = ts;
  fc();
  cout << ans << endl;
  return 0;
}