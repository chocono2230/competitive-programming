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
  map<pair<ll, int>, vector<pair<int, int>>> event;
  rep(i, m) {
    int t, w, s;
    cin >> t >> w >> s;
    event[{t, 1}].push_back({w, s});
  }
  set<int> se;
  rep(i, n) se.insert(i);
  vector<ll> ans(n, 0);
  while (!event.empty()) {
    auto [p, q] = *event.begin();
    if (p.second == 0) {
      for (auto [idx, zz] : q) {
        se.insert(idx);
      }
      event.erase(event.begin());
      continue;
    }
    for (auto [a, b] : q) {
      if (se.empty()) continue;
      auto itr = se.begin();
      ans.at(*itr) += a;
      event[{p.first + b, 0}].push_back({*itr, 0});
      se.erase(itr);
    }
    event.erase(event.begin());
  }
  for (auto now : ans) cout << now << endl;
  return 0;
}