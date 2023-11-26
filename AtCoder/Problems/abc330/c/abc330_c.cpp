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
  ll d;
  cin >> d;
  vector<ll> v;
  ll now = 0;
  for (; now * now <= d; now++) {
    v.push_back(now * now);
  }
  rep(i, 10) {
    v.push_back(now * now);
    now++;
  }
  ll ans = 1e18;
  for (auto l : v) {
    ll p = d - l;
    // cerr << l << " " << p << endl;
    auto itr = lower_bound(ALL(v), p);
    if (itr != v.end()) {
      ans = min(ans, abs(l + *itr - d));
    }
    if (itr != v.begin()) {
      itr--;
      ans = min(ans, abs(l + *itr - d));
    }
  }
  cout << ans << endl;
  // for (auto l : v) {
  //   ll p = d - l;
  //   // cerr << l << " " << p << endl;
  //   auto itr = lower_bound(ALL(v), p);
  //   if (itr != v.end()) {
  //     if (ans == abs(l + *itr - d)) cerr << l << " " << *itr << endl;
  //   }
  //   if (itr != v.begin()) {
  //     itr--;
  //     if (ans == abs(l + *itr - d)) cerr << l << " " << *itr << endl;
  //   }
  // }
  return 0;
}