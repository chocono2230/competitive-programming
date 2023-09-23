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
  int n, x;
  cin >> n >> x;
  vector<int> a(n, 0);
  rep(i, n - 1) cin >> a.at(i);
  int ans = -1;
  rep(now, 101) {
    a.back() = now;
    int mn = *min_element(ALL(a));
    int mx = *max_element(ALL(a));
    int p = reduce(ALL(a)) - mn - mx;
    if (p >= x) {
      ans = now;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}