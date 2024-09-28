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
  int n, w;
  cin >> n >> w;
  vector wv(3001, vector<ll>());
  rep(i, n) {
    int w, v;
    cin >> w >> v;
    wv.at(w).push_back(v);
  }
  vector wx(3001, vector<ll>());
  rep2(i, 1, 3001) {
    wx.at(i).push_back(0);
    if (wv.at(i).empty()) continue;
    priority_queue<tuple<ll, int, int>> q;
    rep(j, wv.at(i).size()) { q.push({wv.at(i).at(j) - 1, j, 1}); }
    rep2(j, 1, (3000 + i - 1) / i + 1) {
      auto [x, y, z] = q.top();
      q.pop();
      wx.at(i).push_back(wx.at(i).back() + x);
      q.push({wv.at(i).at(y) + z * z - ((z + 1) * (z + 1)), y, z + 1});
    }
  }
  const ll INF = 1e18;
  vector dp(3001, vector<ll>(w + 1, -INF));
  dp.at(0).at(0) = 0;
  ll ans = 0;
  rep2(i, 1, 3001) {
    rep(j, w + 1) {
      rep(p, 3005) {
        int bj = j - p * i;
        if (bj < 0) break;
        if (wv.at(i).empty() && p == 1) break;
        ll add = wx.at(i).at(p);
        dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(bj) + add);
      }
      ans = max(ans, dp.at(i).at(j));
    }
  }
  cout << ans << endl;
  return 0;
}