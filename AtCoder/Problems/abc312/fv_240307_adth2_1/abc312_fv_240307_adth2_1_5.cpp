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
  int n, m;
  cin >> n >> m;
  vector vv(3, vector<int>());
  rep(i, n) {
    int t, x;
    cin >> t >> x;
    vv.at(t).push_back(x);
  }
  rep(i, 3) sort(ALL(vv.at(i)), greater<int>());
  ll ans = 0, now = 0;
  rep(i, m) {
    if (vv.at(0).size() == i) break;
    now += vv.at(0).at(i);
  }
  ans = now;
  int v0 = min((int)vv.at(0).size(), m), v1 = 0;
  rep(v2, vv.at(2).size()) {
    auto sum = [&](int f) { return v0 + v1 + v2 + f; };
    // cerr << v0 << " " << v1 << " " << v2 << endl;
    if (sum(0) == m && v0 == 0) break;
    if (sum(0) == m) {
      now -= vv.at(0).at(v0 - 1);
      v0--;
    }
    int kc = vv.at(2).at(v2);
    while (kc != 0 && v1 < vv.at(1).size()) {
      if (sum(1) == m && v0 == 0) break;
      kc--;
      if (sum(1) == m) {
        now -= vv.at(0).at(v0 - 1);
        v0--;
      }
      now += vv.at(1).at(v1++);
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}