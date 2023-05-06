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
  m = n - 1 + m;
  vector<vector<int>> gr(n, vector<int>());
  vector<int> indeg(n, 0);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    indeg.at(b)++;
  }
  int st = 0;
  rep(i, n) {
    if (indeg.at(i) == 0) st = i;
  }
  queue<pair<int, int>> q;
  q.push({st, -1});
  vector<int> ans(n, -2);
  while (!q.empty()) {
    auto [now, p] = q.front();
    q.pop();
    ans.at(now) = p;
    for (auto nx : gr.at(now)) {
      indeg.at(nx)--;
      if (indeg.at(nx) == 0) {
        q.push({nx, now});
      }
    }
  }
  for (auto o : ans) {
    cout << o + 1 << endl;
  }
  return 0;
}