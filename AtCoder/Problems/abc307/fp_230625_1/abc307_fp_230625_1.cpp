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
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    gr.at(u).push_back({v, w});
    gr.at(v).push_back({u, w});
  }
  vector<int> ans(n, -2);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      q;
  int ink;
  cin >> ink;
  rep(i, ink) {
    int in;
    cin >> in;
    in--;
    ans.at(in) = -1;
    for (auto [nx, cost] : gr.at(in)) {
      q.push({cost, nx});
    }
  }
  int d;
  cin >> d;
  vector<int> x(d);
  rep(i, d) cin >> x.at(i);
  rep(day, d) {
    int now_x = x.at(day);
    vector<int> nw;
    while (!q.empty()) {
      auto [cost, now] = q.top();
      if (ans.at(now) != -2) {
        q.pop();
        continue;
      }
      if (now_x < cost) break;
      q.pop();
      ans.at(now) = day;
      nw.push_back(now);
      for (auto [nx, nxcost] : gr.at(now)) {
        if (ans.at(nx) != -2) continue;
        q.push({nxcost + cost, nx});
      }
    }
    for (auto now : nw) {
      for (auto [nx, nxcost] : gr.at(now)) {
        if (ans.at(nx) != -2) continue;
        q.push({nxcost, nx});
      }
    }
    // rep(i, n) cerr << ans.at(i) + 1 << " ";
    // cerr << endl;
  }
  for (auto a : ans) cout << a + 1 << endl;
  return 0;
}