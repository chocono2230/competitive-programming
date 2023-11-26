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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  IntervalPair ip;
  map<int, int> mp;
  auto add = [&](int x) {
    mp[x]++;
    if (mp[x] != 1) return;
    ip.insert(x, x + 1);
  };
  auto del = [&](int x) {
    mp[x]--;
    if (mp[x] != 0) return;
    ip.remove(x, x + 1);
  };
  rep(i, n) { add(a.at(i)); }

  rep(_i, q) {
    int i, x;
    cin >> i >> x;
    i--;
    del(a.at(i));
    a.at(i) = x;
    add(a.at(i));
    cout << ip.mex(0) << endl;
  }
  return 0;
}