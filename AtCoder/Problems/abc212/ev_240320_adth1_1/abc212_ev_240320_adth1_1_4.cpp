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

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  vector<mint> base(n, 0);
  auto dp = base;
  dp.at(0) = 1;
  rep(_i, k) {
    auto nxdp = base;
    mint sum = reduce(ALL(dp));
    rep(i, n) {
      nxdp.at(i) = sum - dp.at(i);
      for (auto nx : gr.at(i)) {
        nxdp.at(i) -= dp.at(nx);
      }
    }
    swap(dp, nxdp);
  }
  cout << dp.at(0).val() << endl;
  return 0;
}