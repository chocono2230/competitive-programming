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
  pair<int, int> p(-1, -1), q(-1, -1);
  rep(i, n) rep(j, n) {
    if (s.at(i).at(j) == 'P') {
      if (p.first == -1)
        p = {i, j};
      else
        q = {i, j};
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
  auto rfc = [&](int pi, int pj, int qi, int qj, int idx) -> int {
    auto nxp = fc(pi, pj, idx);
    if (nxp.first == pi && nxp.second == pj) return -1;
    auto nxq = fc(qi, qj, idx);
    if (nxq.first == qi && nxq.second == qj) return -1;
    int res = 0;
    int ridx = (idx + 2) % 4;
    nxp = fc(pi, pj, ridx);
    if (nxp.first == pi && nxp.second == pj) res |= 1;
    nxq = fc(qi, qj, ridx);
    if (nxq.first == qi && nxq.second == qj) res |= 2;
    return res;
  };
  const int INF = 1001001001;
  vector dp(n, vector(n, vector(n, vector<int>(n, INF))));
  queue<tuple<int, int, int, int>> que;
  rep(pi, n) rep(pj, n) {
    if (s.at(pi).at(pj) == '#') continue;
    bool f = false;
    rep(k, 4) {
      auto p = fc(pi, pj, k);
      if (p.first == pi && p.second == pj) f = true;
    }
    if (f) {
      dp.at(pi).at(pj).at(pi).at(pj) = 0;
      que.push({pi, pj, pi, pj});
    }
  }
  while (!que.empty()) {
    auto [pi, pj, qi, qj] = que.front();
    que.pop();
    rep(k, 4) {
      auto r = rfc(pi, pj, qi, qj, k);
      if (r == -1) continue;
      auto [npi, npj] = fc(pi, pj, k);
      auto [nqi, nqj] = fc(qi, qj, k);
      if (dp.at(npi).at(npj).at(nqi).at(nqj) == INF) {
        dp.at(npi).at(npj).at(nqi).at(nqj) = dp.at(pi).at(pj).at(qi).at(qj) + 1;
        que.push({npi, npj, nqi, nqj});
      }
      if ((r & 1) != 0) {
        if (dp.at(pi).at(pj).at(nqi).at(nqj) == INF) {
          dp.at(pi).at(pj).at(nqi).at(nqj) = dp.at(pi).at(pj).at(qi).at(qj) + 1;
          que.push({pi, pj, nqi, nqj});
        }
      }
      if ((r & 2) != 0) {
        if (dp.at(npi).at(npj).at(qi).at(qj) == INF) {
          dp.at(npi).at(npj).at(qi).at(qj) = dp.at(pi).at(pj).at(qi).at(qj) + 1;
          que.push({npi, npj, qi, qj});
        }
      }
    }
  }
  int ans = dp.at(p.first).at(p.second).at(q.first).at(q.second);
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}