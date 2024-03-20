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
  vector<tuple<int, int, int>> xi(n);
  rep(i, n) {
    int in;
    cin >> in;
    xi.at(i) = {in, i, n};
  }
  vector<tuple<int, int, int>> yi(n);
  rep(i, n) {
    int in;
    cin >> in;
    yi.at(i) = {in, i, n + 1};
  }
  vector<tuple<int, int, int>> zab(m);
  rep(i, m) {
    int a, b, z;
    cin >> a >> b >> z;
    a--;
    b--;
    zab.at(i) = {z, a, b};
  }
  const ll INF = 1e18;
  ll ans = INF;
  rep2(flg, 1, 1 << 3) {
    dsu uf(n + 2);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        q;
    if ((flg & (1 << 0)) != 0) {
      rep(i, n) q.push(xi.at(i));
    }
    if ((flg & (1 << 1)) != 0) {
      rep(i, n) q.push(yi.at(i));
    }
    if ((flg & (1 << 2)) != 0) {
      rep(i, m) q.push(zab.at(i));
    }
    ll add = 0;
    while (!q.empty()) {
      auto [c, a, b] = q.top();
      q.pop();
      if (uf.same(a, b)) continue;
      uf.merge(a, b);
      add += c;
    }
    int z = 1;
    if ((flg & (1 << 0)) == 0) {
      z++;
    }
    if ((flg & (1 << 1)) == 0) {
      z++;
    }
    auto grp = uf.groups();
    if (grp.size() == z) {
      // cerr << flg << " " << add << " " << grp.size() << " " << z << endl;
      ans = min(ans, add);
    }
  }
  cout << ans << endl;
  return 0;
}