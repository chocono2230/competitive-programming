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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(m);
  rep(i, m) cin >> b.at(i);
  sort(ALL(b));
  const int INF = 1001001001;
  int ans = INF;
  for (auto now : a) {
    auto itr = lower_bound(ALL(b), now);
    if (itr != b.end()) {
      ans = min(ans, abs(*itr - now));
    }
    if (itr != b.begin()) {
      itr--;
      ans = min(ans, abs(*itr - now));
    }
  }
  cout << ans << endl;
  return 0;
}