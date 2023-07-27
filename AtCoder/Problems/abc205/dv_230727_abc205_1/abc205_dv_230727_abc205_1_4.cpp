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
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  rep(i, q) {
    ll k;
    cin >> k;
    ll ok = 4e18, ng = 0;
    while (ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      auto r = [&]() {
        int co = upper_bound(ALL(a), mid) - a.begin();
        return mid - co >= k;
      }();
      if (r)
        ok = mid;
      else
        ng = mid;
    }
    cout << ok << endl;
  }
  return 0;
}