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

void dijkstra(vector<vector<pair<int, int>>> &gr,
              vector<vector<pair<ll, int>>> &d, vector<bool> &b,
              vector<int> &a) {
  int n = d.size();
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>,
                 greater<tuple<ll, int, int>>>
      q;
  rep(i, n) {
    if (b.at(i)) {
      q.push({0, i, a.at(i)});
    }
  }
  while (!q.empty()) {
    auto [cost, now, aa] = q.top();
    q.pop();
    if (d.at(now).size() == 2) continue;
    if (d.at(now).size() == 1 && d.at(now).at(0).second == aa) continue;
    d.at(now).push_back({cost, aa});
    for (auto [nx, nxcost] : gr.at(now)) {
      q.push({cost + nxcost, nx, aa});
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  int k, l;
  cin >> k >> l;
  vector<int> a(n);
  vector<bool> b(n, false);
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
  }
  rep(i, l) {
    int in;
    cin >> in;
    in--;
    b.at(in) = true;
  }

  vector gr(n, vector<pair<int, int>>());
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    gr.at(a).push_back({b, c});
    gr.at(b).push_back({a, c});
  }
  vector d(n, vector<pair<ll, int>>());
  dijkstra(gr, d, b, a);
  rep(i, n) {
    if (i != 0) cout << " ";
    if (d.at(i).empty() ||
        (d.at(i).size() == 1 && d.at(i).front().second == a.at(i))) {
      cout << -1;
      continue;
    }
    ll ans = d.at(i).front().first;
    if (d.at(i).front().second == a.at(i)) ans = d.at(i).back().first;
    cout << ans;
  }
  cout << endl;
  return 0;
}