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
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  pair<int, int> p1(-1, -1), p2;
  rep(i, n) rep(j, n) {
    if (s.at(i).at(j) == 'P') {
      if (p1.first == -1) {
        p1 = {i, j};
      } else {
        p2 = {i, j};
      }
      s.at(i).at(j) = '.';
    }
  }
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  auto fc = [&](int i, int j, int idx) {
    int ni = i + di[idx];
    int nj = j + dj[idx];
    if (ni < 0 || ni == n) ni = i;
    if (nj < 0 || nj == n) nj = j;
    if (s.at(ni).at(nj) == '#') {
      ni = i;
      nj = j;
    }
    return make_pair(ni, nj);
  };
  vector d(n, vector(n, vector(n, vector<int>(n, -1))));
  queue<tuple<int, int, int, int>> q;
  d.at(p1.first).at(p1.second).at(p2.first).at(p2.second) = 0;
  q.push({p1.first, p1.second, p2.first, p2.second});
  const int INF = 1001001001;
  int ans = INF;
  while (!q.empty()) {
    auto [pi, pj, qi, qj] = q.front();
    q.pop();
    if (pi == qi && pj == qj) {
      ans = d.at(pi).at(pj).at(qi).at(qj);
      break;
    }
    rep(k, 4) {
      auto np = fc(pi, pj, k);
      auto nq = fc(qi, qj, k);
      if (d.at(np.first).at(np.second).at(nq.first).at(nq.second) != -1)
        continue;
      d.at(np.first).at(np.second).at(nq.first).at(nq.second) =
          d.at(pi).at(pj).at(qi).at(qj) + 1;
      q.push({np.first, np.second, nq.first, nq.second});
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}