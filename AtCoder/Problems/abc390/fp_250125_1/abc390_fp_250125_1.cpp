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
  vector v(n + 2, vector<int>());
  rep(i, n) {
    int in;
    cin >> in;
    v.at(in).push_back(i);
  }
  rep(i, n + 2) { v.at(i).push_back(n); }
  ll ans = 0;
  rep(i, n + 2) {
    rep(j, v.at(i).size() - 1) {
      int now = v.at(i).at(j);
      int l = 0, r = v.at(i).at(j + 1);
      auto itr = lower_bound(ALL(v.at(i + 1)), now);
      r = min(r, *itr);
      if (itr != v.at(i + 1).begin()) {
        itr--;
        l = *itr + 1;
      }
      ans += (ll)(r - now) * (now - l + 1);
    }
  }
  cout << ans << endl;
  return 0;
}