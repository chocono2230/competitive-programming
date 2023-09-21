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

struct combination {
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  n *= 2;
  vector gr(n + 1, vector<int>());
  vector tb(n, vector<bool>(n, false));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    gr.at(a).push_back(b);
    b--;
    tb.at(a).at(b) = true;
    tb.at(b).at(a) = true;
  }

  vector memo(n + 5, vector<mint>(n + 5, 0));
  vector mchk(n + 5, vector<bool>(n + 5, false));
  combination cb(n + 5);

  auto rc = [&](const auto &self, int l, int r) -> mint {
    if (mchk.at(l).at(r)) return memo.at(l).at(r);
    mchk.at(l).at(r) = true;
    if ((r - l) % 2 != 0 || (r - l) < 0) return memo.at(l).at(r) = 0;
    mint res = 0;
    if (r - l == 0) {
      res = 1;
    } else {
      for (auto nx : gr.at(l)) {
        if (nx > r) {
          continue;
        } else {
          int d = nx - l;
          if (d % 2 != 0) continue;
          res += self(self, l + 1, nx - 1) * self(self, nx, r) *
                 cb((r - l) / 2, d / 2);
        }
      }
    }
    return memo.at(l).at(r) = res;
  };
  cout << rc(rc, 0, n).val() << endl;
  return 0;
}