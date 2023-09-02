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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  map<int, vector<int>> mp;
  rep(i, n) { mp[a.at(i)].push_back(i); }
  ll ans = 0;
  for (auto &[idx, v] : mp) {
    int ss = v.size();
    if (ss <= 1) continue;
    rep(i, v.size() - 1) {
      int dd = v.at(i + 1) - v.at(i) - 1;
      ans += (ll)dd * (ll)(i + 1) * (ll)(v.size() - i - 1);
    }
  }

  cout << ans << endl;
  return 0;
}