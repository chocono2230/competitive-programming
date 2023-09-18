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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  rep(i, n) cin >> d.at(i);
  dsu uf(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (uf.same(a, b) || d.at(a) == 0 || d.at(b) == 0) {
      cout << -1 << endl;
      return 0;
    }
    uf.merge(a, b);
    d.at(a)--;
    d.at(b)--;
  }
  auto grps = uf.groups();
  vector zz(grps.size(), vector<int>());
  rep(idx, grps.size()) {
    for (auto now : grps.at(idx)) {
      rep(i, d.at(now)) zz.at(idx).push_back(now);
    }
  }
  sort(ALL(zz),
       [](const auto &l, const auto &r) { return l.size() > r.size(); });
  vector<pair<int, int>> ans;
  int ridx = 1;
  rep(i, zz.size()) {
    for (auto p : zz.at(i)) {
      if (ridx <= i || ridx == zz.size() || zz.at(ridx).size() == 0) {
        cout << -1 << endl;
        return 0;
      }
      ans.push_back({p, zz.at(ridx).back()});
      zz.at(ridx).pop_back();
      ridx++;
    }
  }
  if (ans.size() != n - m - 1) {
    cout << -1 << endl;
    return 0;
  }
  for (auto [p, q] : ans) cout << p + 1 << " " << q + 1 << endl;
  return 0;
}