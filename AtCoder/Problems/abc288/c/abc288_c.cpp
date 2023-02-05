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
  dsu uf(n);
  vector<int> co(n, 0);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.merge(a, b);
    co.at(a)++;
  }
  // rep(i, n) cerr << co.at(i) << " ";
  // cerr << endl;
  auto gp = uf.groups();
  int ans = 0;
  for (auto &v : gp) {
    int cc = 0;
    for (auto now : v) {
      cc += co.at(now);
    }
    // cerr << cc << " " << v.size() << endl;
    ans += cc - (v.size() - 1);
  }
  cout << ans << endl;
  return 0;
}