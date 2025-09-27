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
using mint = modint;

int main() {
  int t, m;
  cin >> t >> m;
  modint::set_mod(m);
  int sz = 5005;
  vector cb(sz, vector<mint>(sz, 0));
  cb.at(0).at(0) = 1;
  rep(i, sz - 1) rep(j, i + 1) {
    cb.at(i + 1).at(j) += cb.at(i).at(j);
    cb.at(i + 1).at(j + 1) += cb.at(i).at(j);
  }

  while (t--) {
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n) cin >> c.at(i);
    int sum = reduce(ALL(c));
    mint ans = 1;
    rep(i, n) {
      ans *= cb.at(sum).at(c.at(i));
      sum -= c.at(i);
    }
    cout << ans.val() << endl;
  }
  return 0;
}