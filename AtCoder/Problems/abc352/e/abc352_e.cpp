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
  vector<pair<int, vector<int>>> ca;
  rep(i, m) {
    int k, c;
    cin >> k >> c;
    vector<int> a(k);
    rep(i, k) {
      cin >> a.at(i);
      a.at(i)--;
    }
    ca.push_back({c, a});
  }
  sort(ALL(ca));

  ll ans = 0;
  dsu uf(n);
  for (auto &[c, a] : ca) {
    rep(i, a.size() - 1) {
      int p = a.at(i);
      int q = a.at(i + 1);
      if (uf.same(p, q)) continue;
      ans += c;
      uf.merge(p, q);
    }
  }
  if (uf.groups().size() != 1) ans = -1;
  cout << ans << endl;
  return 0;
}