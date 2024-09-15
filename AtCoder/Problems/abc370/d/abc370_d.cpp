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

struct IntervalPair {
  const ll INF = 8e18;
  set<pair<ll, ll>> se;
  IntervalPair() {
    se.insert({-INF, -INF});
    se.insert({INF, INF});
  }
  void insert(ll l, ll r) {
    assert(l < r);
    auto itr = se.lower_bound({l, -INF});
    if (r < itr->first) {
      itr--;
      if (l <= itr->second) {
        auto p = *itr;
        p.second = r;
        se.erase(itr);
        se.insert(p);
      } else {
        se.insert({l, r});
      }
      return;
    }
    auto p = *itr;
    se.erase(itr);
    p.first = l;
    se.insert(p);
    itr = se.lower_bound({l, -INF});
    itr--;
    if (l <= itr->second) {
      ll nl = itr->first;
      se.erase(itr);
      itr = se.lower_bound({l, -INF});
      auto q = *itr;
      q.first = nl;
      se.erase(itr);
      se.insert(q);
    }
  }
  bool remove(int l, int r) {
    assert(l < r);
    auto itr = se.upper_bound({l, INF});
    itr--;
    if (itr->second > r) {
      auto p = *itr;
      auto p1 = p, p2 = p;
      p1.second = l;
      p2.first = r;
      se.erase(itr);
      if (p1.first < p1.second) se.insert(p1);
      if (p2.first < p2.second) se.insert(p2);
      return true;
    }
    if (itr->second > l) {
      auto p = *itr;
      p.second = l;
      se.erase(itr);
      if (p.first < p.second) se.insert(p);
      return true;
    }
    itr = se.upper_bound({l, INF});
    if (itr->first < r) {
      auto p = *itr;
      p.first = r;
      se.erase(itr);
      if (p.first < p.second) se.insert(p);
      return true;
    }
    return false;
  }
  ll mex(ll start) {
    auto itr = se.upper_bound({start, INF});
    itr--;
    if (itr->second < start) return start;
    return itr->second;
  }
};

int main() {
  int h, w, q;
  cin >> h >> w >> q;
  vector<IntervalPair> vh(400005), vw(400005);
  vector<IntervalPair> rvh(400005), rvw(400005);
  auto fc = [&](int pi, int pj) {
    // cerr << "X" << pi << " " << pj << endl;
    vh.at(pi).insert(pj, pj + 1);
    vw.at(pj).insert(pi, pi + 1);
    rvh.at(pi).insert(pj * -1, pj * -1 + 1);
    rvw.at(pj).insert(pi * -1, pi * -1 + 1);
  };
  ll bk = 0;
  while (q--) {
    // cerr << q << " :" << bk << endl;
    int i, j;
    cin >> i >> j;
    int vhmex = vh.at(i).mex(j);
    if (vhmex == j) {
      fc(i, j);
      bk++;
      // cerr << "T" << endl;
      continue;
    }
    if (vhmex != w + 1) {
      bk++;
      fc(i, vhmex);
    }
    int vwmex = vw.at(j).mex(i);
    if (vwmex != h + 1) {
      bk++;
      fc(vwmex, j);
    }
    int rvhmex = rvh.at(i).mex(j * -1);
    // cerr << i << " " << j << " " << rvhmex << endl;
    if (rvhmex != 0) {
      bk++;
      fc(i, rvhmex * -1);
    }
    int rvwmex = rvw.at(j).mex(i * -1);
    // cerr << i << " " << j << " " << rvwmex << endl;
    if (rvwmex != 0) {
      bk++;
      fc(rvwmex * -1, j);
    }
  }
  ll ans = (ll)h * w - bk;
  cout << ans << endl;
  return 0;
}