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

const ll INF = 1e18;
void dijkstra(vector<vector<pair<int, int>>> &gr, vector<ll> &d, int st, ll a,
              ll b, ll c) {
  int n = d.size();
  int nh = n / 2;
  vector<bool> chk(n, false);
  rep(i, d.size()) d.at(i) = INF;
  priority_queue<pair<ll, int>> q;
  q.push({0, st});
  while (!q.empty()) {
    auto [cost, now] = q.top();
    q.pop();
    if (chk.at(now) == true) continue;
    cost *= -1;
    d.at(now) = cost;
    chk.at(now) = true;
    int grn = now;
    if (grn >= nh) grn -= nh;
    for (auto [nx, nxcost] : gr.at(grn)) {
      ll nxd = nxcost * b + c;
      ll nxx = nx + nh;
      if (!(chk.at(nxx) == true || d.at(nxx) <= (cost + nxd))) {
        q.push({-1 * (cost + nxd), nxx});
        d.at(nxx) = cost + nxd;
      }
      if (now >= nh) continue;
      nxd = nxcost * a;
      nxx = nx;
      if (!(chk.at(nxx) == true || d.at(nxx) <= (cost + nxd))) {
        q.push({-1 * (cost + nxd), nxx});
        d.at(nxx) = cost + nxd;
      }
    }
  }
}

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector gr(n, vector<pair<int, int>>());
  rep(i, n) rep(j, n) {
    int in;
    cin >> in;
    if (i == j) continue;
    gr.at(i).push_back({j, in});
  }
  vector<ll> d(2 * n, INF);
  dijkstra(gr, d, 0, a, b, c);
  ll ans = min(d.at(n - 1), d.at(n * 2 - 1));
  cout << ans << endl;
  return 0;
}