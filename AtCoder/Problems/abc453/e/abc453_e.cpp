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
  int n;
  cin >> n;
  vector<pair<int, int>> lr(n);
  vector event(n + 1, vector<pair<int, int>>());
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    l--;
    lr.at(i) = {l, r};
    event.at(l).push_back({1, i});
    event.at(r).push_back({2, i});
  }
  combination cb(n + 5);
  vector tb(2, vector<bool>(n, false));
  set<int> se;
  rep(i, n) se.insert(i);
  int ps = 0, qs = 0;
  mint ans = 0;
  rep(i, n) {
    auto fc = [&](int &ps, int &qs, int v, int ei, int addmode) {
      for (auto [mode, idx] : event.at(ei)) {
        if (mode == addmode) {
          se.erase(idx);
          tb.at(v).at(idx) = true;
          if (tb.at(1 - v).at(idx) == false)
            ps++;
          else
            qs--;
        } else {
          tb.at(v).at(idx) = false;
          if (tb.at(1 - v).at(idx) == false) {
            ps--;
            se.insert(idx);
          } else {
            qs++;
          }
        }
      }
    };
    fc(ps, qs, 0, i, 1);
    fc(qs, ps, 1, n - i - 1, 2);
    if (!se.empty()) continue;
    if (ps > (i + 1) || qs > (n - i - 1)) continue;
    int d = n - ps - qs;
    int e = (i + 1) - ps;
    ans += cb(d, e);
  }
  cout << ans.val() << endl;
  return 0;
}