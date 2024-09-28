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
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  ll z = k - reduce(ALL(a));
  auto sa = a;
  sort(ALL(sa));
  vector<ll> sumsa(n + 1, 0);
  rep(i, n) sumsa.at(i + 1) = sumsa.at(i) + sa.at(i);
  auto dd = [&](int i, ll mid) {
    if (m == n) return true;
    ll now = a.at(i) + mid;
    int upIdx = upper_bound(ALL(sa), now) - sa.begin();
    int p = m - (n - upIdx);
    if (p <= 0) return false;
    ll dnSum = sumsa.at(upIdx) - sumsa.at(upIdx - p);
    if (sa.at(n - m) <= a.at(i)) {
      dnSum = sumsa.at(upIdx) - sumsa.at(upIdx - p - 1) - a.at(i);
    }
    ll dnZ = now * p - dnSum;
    // cerr << "mid:" << mid << " upIdx:" << upIdx << " dnSum:" << dnSum
    //      << " dnZ:" << dnZ << " p:" << p << " dnZ+(p-1):" << dnZ + (p - 1)
    //      << " z-mid:" << z - mid << endl;
    return dnZ + (p - 1) >= z - mid;
  };
  auto fc = [&](int i) {
    ll ng = -1, ok = z + 1;
    while (ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      if (dd(i, mid))
        ok = mid;
      else
        ng = mid;
    }
    if (ok == z + 1) ok = -1;
    return ok;
  };
  vector<ll> ans(n);
  // ans.at(0) = fc(0);
  rep(i, n) { ans.at(i) = fc(i); }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}