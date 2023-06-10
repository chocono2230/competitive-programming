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
  int n;
  cin >> n;
  vector<pair<int, int>> v((1 << n) - 1);
  rep(i, (1 << n) - 1) {
    int in;
    cin >> in;
    v.at(i) = {in, i + 1};
  }
  sort(ALL(v));

  vector<bool> use(1 << n, false);
  use.front() = true;
  ll ans = 0;
  for (auto [cost, now] : v) {
    if (use.at(now)) continue;
    ans += cost;
    rep(i, use.size()) {
      if (!use.at(i)) continue;
      use.at(now ^ i) = true;
    }
  }
  cout << ans << endl;
  return 0;
}