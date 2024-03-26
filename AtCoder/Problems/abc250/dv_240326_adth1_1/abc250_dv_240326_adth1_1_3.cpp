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
  auto ppv = make_prime_bool_vec(1000005);
  vector<ll> pv;
  rep(i, ppv.size()) {
    if (!ppv.at(i)) continue;
    if ((ll)i * i * i > n) break;
    pv.push_back(i);
  }
  ll ans = 0;
  rep(i, pv.size()) {
    ll q = pv.at(i);
    ll qq = q * q * q;
    int ok = -1, ng = i;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      ll m = pv.at(mid);
      if (m > LLONG_MAX / qq || qq * m > n)
        ng = mid;
      else
        ok = mid;
    }
    ans += ok + 1;
  }
  cout << ans << endl;
  return 0;
}