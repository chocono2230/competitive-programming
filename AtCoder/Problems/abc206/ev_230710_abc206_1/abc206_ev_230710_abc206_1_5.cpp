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

vector<bool> make_prime_bool_vec(int lim) {
  vector<bool> chk(lim + 1, true);
  chk.at(0) = chk.at(1) = false;
  rep2(i, 2, chk.size()) {
    if (chk.at(i) == false) continue;
    for (int j = i + i; j < chk.size(); j += i) chk.at(j) = false;
  }
  return chk;
}

vector<int> eulers_totient_function(int lim) {
  vector<int> res(lim, 0);
  rep(i, res.size()) { res.at(i) = i; }
  auto pv = make_prime_bool_vec(lim);
  rep(i, pv.size()) {
    if (!pv.at(i)) continue;
    int now = i;
    while (now < (int)res.size()) {
      res.at(now) /= i;
      res.at(now) *= (i - 1);
      now += i;
    }
  }
  return res;
}

int main() {
  int l, r;
  cin >> l >> r;
  l--;

  ll ans = 0;
  vector<ll> memo(r + 2, 0);
  rrep2(g, 2, r + 1) {
    ll add = r / g - l / g;
    add *= add;
    for (int now = g + g; now <= r; now += g) {
      add -= memo.at(now);
    }
    memo.at(g) = add;
    if (l <= g - 1) {
      add -= (r / g - l / g) * 2;
      add++;
    }
    ans += add;
  }
  cout << ans << endl;
  return 0;
}