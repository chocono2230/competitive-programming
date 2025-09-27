#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
template <class T, class U>
inline bool chmin(T &a, const U &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

const ll INF = 1e18;

void dijkstra(vector<vector<int>> &gr, vector<ll> &d, vector<ll> &vw, int st) {
  int n = d.size();
  vector<bool> chk(n, false);
  rep(i, d.size()) d.at(i) = INF;
  vector<ll> ft(n, INF);
  priority_queue<tuple<ll, ll, int>, vector<tuple<ll, ll, int>>,
                 greater<tuple<ll, ll, int>>>
      q;
  q.push({0, 0, st});
  while (!q.empty()) {
    auto [w, cost, now] = q.top();
    q.pop();
    w += vw.at(now);
    chmin(d.at(now), cost);
    chmin(ft.at(now), w);
    for (auto nx : gr.at(now)) {
      if (d.at(nx) <= (cost + w) && ft.at(nx) <= w) continue;
      q.push({w, cost + w, nx});
      chmin(d.at(nx), cost + w);
      chmin(ft.at(nx), w);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> w(n);
  rep(i, n) cin >> w.at(i);
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  vector<ll> ans(n);
  dijkstra(gr, ans, w, 0);
  rep(i, n) { cout << ans.at(i) << endl; }
  return 0;
}