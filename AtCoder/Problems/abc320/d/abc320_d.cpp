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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector gr(n, vector<tuple<int, ll, ll>>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int x, y;
    cin >> x >> y;
    gr.at(a).push_back({b, x, y});
    gr.at(b).push_back({a, -x, -y});
  }
  vector<bool> chk(n, false);
  vector<pair<ll, ll>> d(n, {0, 0});
  queue<int> q;
  q.push(0);
  chk.at(0) = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    auto [x, y] = d.at(now);
    for (auto [nx, dx, dy] : gr.at(now)) {
      if (chk.at(nx)) continue;
      chk.at(nx) = true;
      d.at(nx) = {x + dx, y + dy};
      q.push(nx);
    }
  }
  rep(i, n) {
    auto [x, y] = d.at(i);
    if (chk.at(i))
      cout << x << " " << y << endl;
    else
      cout << "undecidable" << endl;
  }
  return 0;
}