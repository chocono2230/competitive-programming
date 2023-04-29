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

vector<ll> make_prime_vec(int lim) {
  vector<ll> ps;
  vector<bool> chk(lim + 1, true);
  chk.at(0) = chk.at(1) = false;
  rep2(i, 2, chk.size()) {
    if (chk.at(i) == false) continue;
    ps.push_back(i);
    for (int j = i + i; j < chk.size(); j += i) chk.at(j) = false;
  }
  return ps;
}

int main() {
  ll n;
  cin >> n;
  auto pv = make_prime_vec(1000005);
  ll ans = 0;
  rep(ci, pv.size()) {
    ll c = pv.at(ci);
    if (c * c > n) break;
    rep(ai, ci) {
      ll a = pv.at(ai);
      if (c * c > LLONG_MAX / a || c * c * a > LLONG_MAX / a) break;
      if (c * c * a * a > n) break;
      ll ok = ai, ng = ci;
      while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll b = pv.at(mid);
        ll ml = c * c * a * a;
        if (ml > LLONG_MAX / b || ml * b > n)
          ng = mid;
        else
          ok = mid;
      }
      // if (ok - ai > 0) {
      //   cerr << a << " " << pv.at(ok) << " " << c << " " << ok - ai << endl;
      // }
      ans += ok - ai;
    }
  }
  cout << ans << endl;
  return 0;
}