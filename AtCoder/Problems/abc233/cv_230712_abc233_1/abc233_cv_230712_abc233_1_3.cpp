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
  ll x;
  cin >> n >> x;
  vector a(n, vector<ll>());
  rep(i, n) {
    int l;
    cin >> l;
    rep(j, l) {
      int in;
      cin >> in;
      a.at(i).push_back(in);
    }
  }
  int ans = 0;
  auto dfs = [&](auto self, int lv, ll now) -> void {
    if (lv == n) {
      if (now == x) ans++;
      return;
    }
    rep(i, a.at(lv).size()) {
      ll mul = a.at(lv).at(i);
      if (now > LLONG_MAX / mul) continue;
      self(self, lv + 1, now * mul);
    }
  };
  dfs(dfs, 0, 1);
  cout << ans << endl;
  return 0;
}