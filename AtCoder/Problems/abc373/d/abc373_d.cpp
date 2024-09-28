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
  vector rgr(n, vector<pair<int, int>>());
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    gr.at(u).push_back({v, w});
    rgr.at(v).push_back({u, w});
  }
  vector<ll> ans(n);
  vector<bool> chk(n, false);
  auto fc = [&](int p) {
    queue<int> q;
    q.push(p);
    ans.at(p) = 0;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto [nx, cost] : gr.at(now)) {
        if (chk.at(nx)) continue;
        chk.at(nx) = true;
        ans.at(nx) = ans.at(now) + cost;
        q.push(nx);
      }
      for (auto [nx, cost] : rgr.at(now)) {
        if (chk.at(nx)) continue;
        chk.at(nx) = true;
        ans.at(nx) = ans.at(now) - cost;
        q.push(nx);
      }
    }
  };
  rep(i, n) {
    if (chk.at(i)) continue;
    fc(i);
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}