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
  int n, m, k;
  cin >> n >> m >> k;
  vector gr(2 * n, vector<int>());
  rep(i, m) {
    int u, v, a;
    cin >> u >> v >> a;
    u--;
    v--;
    if (a == 1) {
      gr.at(u).push_back(v);
      gr.at(v).push_back(u);
    } else {
      gr.at(n + u).push_back(n + v);
      gr.at(n + v).push_back(n + u);
    }
  }
  rep(i, k) {
    int in;
    cin >> in;
    in--;
    gr.at(in).push_back(n + in);
    gr.at(n + in).push_back(in);
  }
  const int INF = 1001001001;
  vector<int> d(2 * n, INF);
  deque<int> q;
  q.push_back(0);
  d.at(0) = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop_front();
    for (auto nx : gr.at(now)) {
      if (d.at(nx) != INF) continue;
      if (nx % n == now % n) {
        d.at(nx) = d.at(now);
        q.push_front(nx);
        continue;
      }
      d.at(nx) = d.at(now) + 1;
      q.push_back(nx);
    }
  }

  ll ans = min(d.at(n - 1), d.at(n * 2 - 1));
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}