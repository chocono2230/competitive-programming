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
  int h, w;
  ll x;
  cin >> h >> w >> x;
  int p, q;
  cin >> p >> q;
  p--;
  q--;
  vector s(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> s.at(i).at(j);
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  vector table(h, vector<int>(w, 0));
  ll now = 0;
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>,
                 greater<tuple<ll, int, int>>>
      qe;
  qe.push({s.at(p).at(q), p, q});
  while (!qe.empty()) {
    auto [ss, i, j] = qe.top();
    qe.pop();
    if (table.at(i).at(j) != 0) continue;
    if (now != 0 && (ss > LLONG_MAX / x || now <= ss * x)) break;
    now += ss;
    table.at(i).at(j) = 1;
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (table.at(ni).at(nj) == 1) continue;
      qe.push({s.at(ni).at(nj), ni, nj});
    }
  }
  cout << now << endl;
  return 0;
}