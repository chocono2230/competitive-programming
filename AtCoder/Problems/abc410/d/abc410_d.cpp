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
  vector gr(n, vector<pair<int, int>>());
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    gr.at(a).push_back({b, c});
  }

  vector dp(n, vector<bool>(1 << 10, false));
  dp.at(0).at(0) = true;
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto [now, bit] = q.front();
    q.pop();
    for (auto [nx, nxbit] : gr.at(now)) {
      int ebit = (bit ^ nxbit);
      if (dp.at(nx).at(ebit)) continue;
      dp.at(nx).at(ebit) = true;
      q.push({nx, ebit});
    }
  }
  const int INF = 1001001001;
  int ans = INF;
  rep(i, dp.back().size()) {
    if (dp.back().at(i)) {
      ans = i;
      break;
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}