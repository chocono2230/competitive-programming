#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
template <class T, class U>
inline bool chmax(T& a, const U& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> pv(n);
  rep(i, n) {
    int p, v;
    cin >> p >> v;
    pv.at(i) = {p, v};
  }

  const ll INF = 1e18;
  vector memo(n + 1, vector<int>(m + 1, 0));
  vector<ll> base(m + 1, -INF);
  auto dp = base;
  dp.at(0) = 0;
  rep(i, n) {
    auto nxdp = base;
    auto [p, v] = pv.at(i);
    rep(j, m + 1) {
      if (nxdp.at(j) <= dp.at(j)) {
        if (nxdp.at(j) < dp.at(j)) memo.at(i + 1).at(j) = 0;
        memo.at(i + 1).at(j) += 1;
        nxdp.at(j) = dp.at(j);
      }
      if (j + p <= m) {
        if (nxdp.at(j + p) <= dp.at(j) + v) {
          if (nxdp.at(j + p) < dp.at(j) + v) memo.at(i + 1).at(j + p) = 0;
          memo.at(i + 1).at(j + p) += 2;
          nxdp.at(j + p) = dp.at(j) + v;
        }
      }
    }
    swap(dp, nxdp);
  }

  int mx = -1;
  set<int> mxi;
  rep(i, m + 1) {
    if (dp.at(i) >= mx) {
      if (dp.at(i) > mx) mxi.clear();
      mx = dp.at(i);
      mxi.insert(i);
    }
  }
  string ans(n, 'B');
  rrep2(i, 1, n + 1) {
    set<int> nxmxi;
    bool f1 = false, f2 = false;
    auto [p, v] = pv.at(i - 1);
    for (auto now : mxi) {
      int flg = memo.at(i).at(now);
      if (flg % 2 == 1) {
        nxmxi.insert(now);
        f1 = true;
      }
      if (flg >= 2) {
        nxmxi.insert(now - p);
        f2 = true;
      }
    }
    // cerr << i << " " << f1 << " " << f2 << endl;
    if (!f1)
      ans.at(i - 1) = 'A';
    else if (!f2)
      ans.at(i - 1) = 'C';
    swap(mxi, nxmxi);
  }
  cout << ans << endl;
  return 0;
}