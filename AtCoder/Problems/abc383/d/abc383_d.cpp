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

int main() {
  ll n;
  cin >> n;
  auto vv = make_prime_bool_vec(2000005);
  vector<ll> pv;
  rep(i, vv.size()) {
    if (vv.at(i)) pv.push_back(i);
  }
  ll ans = 0;
  rep(i, pv.size()) {
    if (pv.at(i) > n) break;
    ll ps = pv.at(i) * pv.at(i);
    int ok = i, ng = pv.size();
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      auto fc = [&]() {
        ll qs = pv.at(mid) * pv.at(mid);
        if (ps > LLONG_MAX / qs) return false;
        return ps * qs <= n;
      };
      if (fc())
        ok = mid;
      else
        ng = mid;
    }
    // cerr << pv.at(i) << " " << ps << " " << ok << " " << i << endl;
    ans += ok - i;
  }
  for (auto now : pv) {
    ll s = 1;
    rep(i, 8) { s *= now; }
    if (s > n) break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}