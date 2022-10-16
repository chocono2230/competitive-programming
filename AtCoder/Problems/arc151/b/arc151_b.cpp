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
using mint = modint998244353;

// void dfs(vector<int> &now, vector<int> &p, int m) {
//   if (now.size() == p.size()) {
//     vector<int> r(now.size());
//     rep(i, now.size()) r.at(i) = now.at(p.at(i));
//     bool f = false;
//     rep(i, now.size()) {
//       if (now.at(i) < r.at(i)) {
//         f = true;
//         break;
//       } else if (now.at(i) > r.at(i))
//         break;
//     }
//     if (f) {
//       for (auto i : now) cout << i << " ";
//       cout << endl;
//     }
//     return;
//   }
//   rep2(i, 1, m + 1) {
//     now.push_back(i);
//     dfs(now, p, m);
//     now.pop_back();
//   }
// }

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n), rp(n);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
    rp.at(p.at(i)) = i;
  }
  // int ans = 0;
  // vector<int> now;
  // dfs(now, p, m);

  dsu uf(n);
  rep(i, n) { uf.merge(i, p.at(i)); }
  auto grp = uf.groups();
  mint ans = 1, flg = 0;
  vector<int> x(n, -1), y(n, -1);
  for (auto &gv : grp) {
    mint add = 1;
    vector<pair<int, int>> v;
    for (auto i : gv) v.push_back({rp.at(i), i});
    sort(ALL(v));
    for (auto [a, b] : v) {
      if (a == b) continue;
      flg = 1;
      if (x.at(a) == -1 && y.at(a) == -1) {
        x.at(a) = y.at(a) = -2;
        x.at(b) = -2;
      } else if (y.at(a) == -1) {
        continue;
      } else if (x.at(a) == -1) {
      }
    }
  }
  return 0;
}