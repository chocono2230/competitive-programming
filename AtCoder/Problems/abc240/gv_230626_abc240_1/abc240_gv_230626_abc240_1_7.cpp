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
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  x = abs(x);
  y = abs(y);
  z = abs(z);
  combination cb(1e7 + 5);
  auto fc = [&](int n, int x) -> mint {
    if (n < x || n % 2 != x % 2) return 0;
    return cb(n, (n + x) / 2);
  };
  auto f2 = [&](int n, int x, int y) -> mint {
    int u = x + y, v = x - y;
    return fc(n, u) * fc(n, abs(v));
  };
  mint ans = 0;
  rep2(i, z, n + 1) {
    mint add = fc(i, z) * cb(n, i);
    add *= f2(n - i, x, y);
    ans += add;
  }
  cout << ans.val() << endl;
  return 0;
}