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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<mint> dp(n, 0);
  dp.front() = 1;
  int sr = sqrt(n) + 2;
  vector memo(sr, vector<mint>(sr, 0));
  auto fc = [&](int st, int d) {
    for (int i = st + d; i < n; i += d) {
      dp.at(i) += dp.at(st);
    }
  };
  if (a.at(0) < sr) {
    memo.at(a.at(0)).at(0) = 1;
  } else {
    fc(0, a.at(0));
  }
  rep2(i, 1, n) {
    rep2(k, 1, sr) {
      int m = i % k;
      dp.at(i) += memo.at(k).at(m);
    }
    if (a.at(i) < sr) {
      memo.at(a.at(i)).at(i % a.at(i)) += dp.at(i);
    } else {
      fc(i, a.at(i));
    }
  }
  mint ans = reduce(ALL(dp));
  cout << ans.val() << endl;
  return 0;
}