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
const ll INF = 8e18;

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
  int n, m;
  cin >> n >> m;
  vector gr(n, map<int, vector<tuple<ll, ll, ll, ll>>>());
  rep(i, m) {
    int l, d, k, c;
    cin >> l >> d >> k >> c;
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(b)[a].push_back({l, d, k, c});
  }
  vector<ll> d(n, -1);
  priority_queue<pair<ll, int>> q;
  q.push({INF, n - 1});
  while (!q.empty()) {
    auto [time, now] = q.top();
    q.pop();
    if (now != n - 1 && d.at(now) >= time) continue;
    d.at(now) = time;
    for (auto nxv : gr.at(now)) {
      int nx = nxv.first;
      ll mx = -1;
      for (auto [l, d, k, c] : nxv.second) {
        if (time < l + c) continue;
        if (time >= l + d * (k - 1) + c) {
          mx = max(mx, l + d * (k - 1));
          continue;
        }
        ll baset = time - (l + c);
        ll co = baset / d;
        assert(co < k);
        ll nw = co * d + l;
        mx = max(mx, nw);
      }
      if (mx == -1) continue;
      q.push({mx, nx});
    }
  }
  rep(i, n - 1) {
    if (d.at(i) != -1)
      cout << d.at(i);
    else
      cout << "Unreachable";
    cout << endl;
  }
  return 0;
}