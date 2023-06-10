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
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  priority_queue<pair<int, int>> q;
  rep(i, k) {
    int p, h;
    cin >> p >> h;
    p--;
    q.push({h, p});
  }

  vector<int> ans(n, -1);
  while (!q.empty()) {
    auto [c, now] = q.top();
    q.pop();
    if (ans.at(now) >= c) continue;
    ans.at(now) = c;
    if (c == 0) continue;
    for (auto nx : gr.at(now)) {
      q.push({c - 1, nx});
    }
  }

  vector<int> oo;
  rep(i, n) if (ans.at(i) != -1) oo.push_back(i);
  cout << oo.size() << endl;
  rep(i, oo.size()) {
    if (i != 0) cout << " ";
    cout << oo.at(i) + 1;
  }
  cout << endl;
  return 0;
}