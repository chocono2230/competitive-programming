#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> lr(n);
  map<int, int> mp;
  rep(i, n) {
    int x, p;
    cin >> x >> p;
    lr.at(i) = {x - p, x + p};
    mp[x - p] = -1;
    mp[x + p] = -1;
  }
  int sz = 0;
  for (auto &p : mp) p.second = sz++;
  dsu uf(sz);
  vector<int> co(sz, 0);
  for (auto &p : lr) {
    p.first = mp[p.first];
    p.second = mp[p.second];
    uf.merge(p.first, p.second);
    co.at(p.first)++;
  }

  auto grp = uf.groups();
  int ans = 0;
  for (auto &v : grp) {
    if (v.size() == 1) continue;
    int p = 0;
    for (auto now : v) {
      p += co.at(now);
    }
    p = min((int)v.size(), p);
    ans += p;
  }
  cout << ans << endl;
  return 0;
}