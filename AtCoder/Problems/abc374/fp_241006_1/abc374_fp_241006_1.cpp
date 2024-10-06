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
  int n, k, x;
  cin >> n >> k >> x;
  vector<ll> t(n);
  rep(i, n) cin >> t.at(i);
  map<ll, int> mp;
  map<ll, int> m2i;
  rep(i, n) {
    ll now = t.at(i);
    mp[now]++;
    m2i[now] = -1;
    rep(j, n) {
      now += x;
      mp[now];
      m2i[now] = -1;
    }
  }
  int sz = 0;
  for (auto &p : m2i) p.second = sz++;
  vector<ll> i2m;
  for (auto p : mp) i2m.push_back(p.first);
  const ll INF = 1e18;
  vector dp(sz, vector<ll>(n + 1, INF));
  dp.at(0).at(0) = 0;
  rep(i, sz - 1) {
    rep(j, n + 1) {
      if (dp.at(i).at(j) == INF) continue;
      dp.at(i + 1).at(j) = min(dp.at(i + 1).at(j), dp.at(i).at(j));
      ll nwt = i2m.at(i);
      ll nxt = nwt + x;
      if (m2i.find(nxt) == m2i.end()) continue;
      ll nxi = m2i[nxt];
      ll cost = 0;
      rep(ik, k) {
        if (j + ik + 1 > n || nwt - t.at(j + ik) < 0) break;
        cost += nwt - t.at(j + ik);
        dp.at(nxi).at(j + ik + 1) =
            min(dp.at(nxi).at(j + ik + 1), dp.at(i).at(j) + cost);
      }
    }
  }
  cout << dp.back().back() << endl;
  return 0;
}