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
  cin >> n >> m;
  vector<int> l(n);
  rep(i, n) cin >> l.at(i);
  int mx = *max_element(ALL(l));
  ll ng = mx - 1, ok = 1e18;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    auto fc = [&]() -> bool {
      int mc = 1;
      ll now = 0;
      bool f = false;
      for (int add : l) {
        if (!f) {
          now = add;
          f = true;
          continue;
        }
        if (now + add + 1 > mid) {
          mc++;
          if (mc > m) return false;
          now = add;
        } else {
          now += add + 1;
        }
      }
      return true;
    };
    if (fc())
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}