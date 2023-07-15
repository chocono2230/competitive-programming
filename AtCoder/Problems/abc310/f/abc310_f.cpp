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

void dfs(vector<int> now, set<vector<int>> &p, int lv, int sum) {
  if (lv == 10) {
    if (sum != 10) return;
    p.insert(now);
    return;
  }
  rep2(z, 1, 10) {
    if (sum + z > 10) break;
    auto nx = now;
    nx.push_back(z);
    sort(ALL(nx));
    if (sum + z == 10) {
      p.insert(nx);
      continue;
    }
    dfs(nx, p, lv + 1, sum + z);
  }
}

int main() {
  set<vector<int>> p;
  dfs({}, p, 0, 0);
  cout << p.size() << endl;
  for (auto v : p) {
    for (auto i : v) cerr << i << " ";
    cerr << endl;
  }
  // int n;
  // cin >> n;
  // vector<int> a(n);
  // rep(i, n) cin >> a.at(i);
  // vector dp(n + 1, vector<mint>(12, 0));
  // mint sum = 1;
  // rep(i, n) sum *= a.at(i);
  // dp.front().front() = 1;
  // rep(i, n) {
  //   int ni = i + 1;
  //   rep(j, 12) { dp.at(ni).at(j) += dp.at(i).at(j) * a.at(i); }
  //   rep2(add, 1, min(10, a.at(i)) + 1) {
  //     rep(j, 12) {
  //       int nj = min(11, j + add);
  //       dp.at(ni).at(nj) += dp.at(i).at(j);
  //     }
  //     if (a.at(i) > 10) {
  //       int z = a.at(i) - 10;
  //       rep(j, 12) {
  //         int nj = 11;
  //         dp.at(ni).at(nj) += dp.at(i).at(j) * z;
  //       }
  //     }
  //   }
  // }
  return 0;
}