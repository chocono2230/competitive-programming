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
  vector<int> p(n);
  rep(i, n) cin >> p.at(i);
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  vector<int> d(n, -1);
  vector<bool> chk(n, false);
  priority_queue<tuple<int, int, int>> q;
  q.push({-p.at(0), 0, 0});
  while (!q.empty()) {
    auto [type, cost, now] = q.top();
    q.pop();
    if (chk.at(now)) continue;
    chk.at(now) = true;
    d.at(now) = cost;
    for (auto nx : gr.at(now)) {
      if (p.at(now) > p.at(nx)) continue;
      int add = 0;
      if (p.at(now) < p.at(nx)) add++;
      if (d.at(nx) > d.at(now) + add) continue;
      d.at(nx) = d.at(now) + add;
      q.push({-p.at(nx), d.at(now) + add, nx});
    }
  }
  int ans = d.back();
  if (ans == -1)
    ans = 0;
  else
    ans++;
  cout << ans << endl;

  return 0;
}