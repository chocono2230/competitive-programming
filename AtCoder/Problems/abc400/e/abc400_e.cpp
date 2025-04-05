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
  auto pr = make_prime_bool_vec(1000005);
  set<ll> v;
  vector<ll> memo;
  ll sz = 1000000000000LL;
  rep2(i, 2, pr.size()) {
    if (!pr.at(i)) continue;
    ll now = (ll)i * i;
    vector<ll> nw;
    while (1) {
      if (now > sz) break;
      nw.push_back(now);
      now *= i;
      if (now > sz) break;
      now *= i;
    }
    for (auto nn : nw) {
      for (auto now : v) {
        if (now * nn > sz) break;
        memo.push_back(now * nn);
      }
    }
    if (nw.size() == 1 && nw.front() > 1000000) continue;
    for (auto nn : nw) v.insert(nn);
    // cerr << i << " " << v.size() << " " << nw.size() << endl;
  }
  sort(ALL(memo));
  cerr << memo.size() << endl;

  int q;
  cin >> q;
  while (q--) {
    ll x;
    cin >> x;
    auto itr = upper_bound(ALL(memo), x);
    itr--;
    cout << *itr << endl;
  }
  return 0;
}