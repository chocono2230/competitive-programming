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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  map<int, int> mp;
  const int INF = 1001001001;
  set<pair<int, int>> se;
  se.insert({-1, -1});
  se.insert({INF, INF});
  auto add = [&](int in) {
    mp[in]++;
    if (mp[in] != 1) return;
    auto itr = se.lower_bound({in, 0});
    if (itr->first == in + 1) {
      auto p = *itr;
      se.erase(itr);
      p.first = in;
      se.insert(p);
      itr = se.lower_bound({in, 0});
      itr--;
      if (itr->second == in) {
        int t = itr->first;
        se.erase(itr);
        itr = se.lower_bound({in, 0});
        auto q = *itr;
        q.first = t;
        se.erase(itr);
        se.insert(q);
      }
    } else {
      itr--;
      if (itr->second == in) {
        auto p = *itr;
        p.second = in + 1;
        se.erase(itr);
        se.insert(p);
      } else {
        se.insert({in, in + 1});
      }
    }
  };
  auto del = [&](int in) {
    mp[in]--;
    if (mp[in] >= 1) return;
    auto itr = se.upper_bound({in, INF + 2});
    itr--;
    auto p = *itr;
    if (p.first == in) {
      se.erase(p);
      p.first++;
      if (p.first != p.second) {
        se.insert(p);
      }
      return;
    }
    if (p.second == in + 1) {
      se.erase(p);
      p.second--;
      if (p.first != p.second) {
        se.insert(p);
      }
      return;
    }
    auto nxl = p;
    nxl.second = in;
    auto nxr = p;
    nxr.first = in + 1;
    se.erase(itr);
    se.insert(nxl);
    se.insert(nxr);
  };
  rep(i, n) { add(a.at(i)); }

  rep(_i, q) {
    int i, x;
    cin >> i >> x;
    i--;
    del(a.at(i));
    a.at(i) = x;
    add(a.at(i));

    auto itr = se.begin();
    itr++;
    // rep(i, n) cerr << a.at(i) << " ";
    // cerr << endl;
    // for (auto p : se) cerr << p.first << ":" << p.second << "  ";
    // cerr << endl;
    // cerr << itr->first << " " << itr->second << endl;
    if (itr->first != 0)
      cout << 0 << endl;
    else
      cout << itr->second << endl;
  }
  return 0;
}