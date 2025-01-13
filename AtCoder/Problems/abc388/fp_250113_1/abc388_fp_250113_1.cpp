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

int main() {
  ll n;
  int m, a, b;
  cin >> n >> m >> a >> b;
  vector<pair<ll, ll>> lr(m);
  rep(i, m) {
    ll l, r;
    cin >> l >> r;
    lr.at(i) = {l, r};
    if (r - l + 1 >= b) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (a == b) {
    n--;
    bool f = (n % a != 0);
    for (auto [l, r] : lr) {
      l--;
      r--;
      l %= a;
      r %= a;
      f |= ((r < l) || l == 0);
    }
    if (!f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }
  lr.push_back({n + 1, n + 1});
  m++;

  int sz = b * b;
  vector<bool> edge(sz, false);
  rep2(i, a, b + 1) edge.at(i) = true;
  rep(i, edge.size()) {
    if (!edge.at(i)) continue;
    rep2(add, a, b + 1) {
      int ni = i + add;
      if (ni >= (int)edge.size()) continue;
      edge.at(ni) = true;
    }
  }

  vector<bool> dp(1, true);
  vector<ll> num(1, 1);
  rep(idx, m) {
    ll pr = -1000;
    ll nl = 1e18;
    if (idx != 0) pr = lr.at(idx - 1).second;
    if (idx != m - 1) nl = lr.at(idx + 1).first;
    auto [l, r] = lr.at(idx);
    for (ll i = l - b; i < l; i++) {
      if (num.back() >= i || pr >= i) continue;
      dp.push_back(false);
      num.push_back(i);
      rep(add, b) {
        int nidx = num.size() - add - 2;
        if (nidx < 0) break;
        if (!dp.at(nidx)) continue;
        ll nn = num.at(nidx);
        if (idx == 0 || nn > lr.at(idx - 1).second) {
          ll d = i - nn;
          if (d < sz) {
            if (!edge.at(d)) continue;
          }
          dp.back() = true;
          break;
        } else {
          if (nn < i - b || nn > i - a) continue;
          dp.back() = true;
          break;
        }
      }
    }
    for (ll i = r + 1; i <= r + b + 1; i++) {
      if (num.back() >= i || i >= nl) continue;
      dp.push_back(false);
      num.push_back(i);
      rep(add, b) {
        int nidx = num.size() - add - 2;
        if (nidx < 0) break;
        if (!dp.at(nidx)) continue;
        ll nn = num.at(nidx);
        if (nn < i - b || nn > i - a) continue;
        dp.back() = true;
        break;
      }
    }
  }
  bool ans = false;
  rrep(i, dp.size()) {
    if (num.at(i) == n && dp.at(i)) ans = true;
  }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  // rep(i, num.size()) {
  //   cerr << i << " " << num.at(i) << " " << (bool)dp.at(i) << endl;
  // }

  // [&]() {
  //   vector<bool> dp(110, false);
  //   dp.at(1) = true;
  //   rep(i, dp.size()) {
  //     if (!dp.at(i)) continue;
  //     rep2(add, a, b + 1) {
  //       int ni = i + add;
  //       if (ni >= dp.size()) continue;
  //       bool flg = false;
  //       for (auto [l, r] : lr) {
  //         if (l <= ni && ni <= r) flg = true;
  //       }
  //       if (flg) continue;
  //       dp.at(ni) = true;
  //     }
  //   }
  //   rep(i, dp.size()) cerr << i << " " << dp.at(i) << endl;
  // }();
  return 0;
}