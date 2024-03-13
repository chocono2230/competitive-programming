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
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  vector<bool> d(n, false);
  vector<pair<int, int>> de, be;
  auto dfs = [&](const auto &self, int now) -> void {
    d.at(now) = true;
    for (auto nx : gr.at(now)) {
      if (d.at(nx)) continue;
      de.push_back({now, nx});
      self(self, nx);
    }
  };
  dfs(dfs, 0);
  rep(i, n) d.at(i) = false;
  d.front() = true;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto nx : gr.at(now)) {
      if (d.at(nx)) continue;
      d.at(nx) = true;
      be.push_back({now, nx});
      q.push(nx);
    }
  }
  for (auto [a, b] : de) cout << a + 1 << " " << b + 1 << endl;
  for (auto [a, b] : be) cout << a + 1 << " " << b + 1 << endl;
  return 0;
}