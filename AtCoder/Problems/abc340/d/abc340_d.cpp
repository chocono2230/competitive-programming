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
void dijkstra(vector<vector<pair<int, int>>> &gr, vector<ll> &d, int st) {
  int n = d.size();
  vector<bool> chk(n, false);
  rep(i, d.size()) d.at(i) = INF;
  priority_queue<pair<ll, int>> q;
  q.push({0, st});
  int co = 0;
  while (!q.empty()) {
    auto [cost, now] = q.top();
    q.pop();
    if (chk.at(now) == true) continue;
    cost *= -1;
    d.at(now) = cost;
    chk.at(now) = true;
    co++;
    if (co == n) break;
    for (auto [nx, nxcost] : gr.at(now)) {
      if (chk.at(nx) == true || d.at(nx) <= (cost + nxcost)) continue;
      q.push({-1 * (cost + nxcost), nx});
      d.at(nx) = cost + nxcost;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector gr(n, vector<pair<int, int>>());
  rep(i, n - 1) {
    int a, b, x;
    cin >> a >> b >> x;
    gr.at(i).push_back({i + 1, a});
    gr.at(i).push_back({x - 1, b});
  }
  vector<ll> d(n, INF);
  dijkstra(gr, d, 0);
  cout << d.at(n - 1) << endl;
  return 0;
}