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
  vector<int> h(n);
  rep(i, n) cin >> h.at(i);
  vector<ll> hs(n + 1, 0);
  rep(i, n) hs.at(i + 1) = hs.at(i) + h.at(i);

  map<int, int> mp;
  vector<tuple<int, int, int>> sem;
  rep(i, n) {
    int m, s, e;
    cin >> m >> s >> e;
    m--;
    mp[s] = -1;
    mp[e] = -1;
    sem.push_back({s, e, m});
  }
  int sz = 0;
  for (auto &p : mp) p.second = sz++;
  for (auto &t : sem) {
    get<0>(t) = mp[get<0>(t)];
    get<1>(t) = mp[get<1>(t)];
  }
  sort(ALL(sem));
  vector mse(n, vector<pair<int, int>>());
  vector<int> idxs(n, 0);
  for (auto [s, e, m] : sem) {
    mse.at(m).push_back({s, e});
  }
  vector gr(sz + 1, vector<pair<int, ll>>());
  for (auto &v : mse) {
    rep(i, v.size()) {
      int l = v.at(i).first;
      vector<pair<int, int>> z;
      rep2(j, i, v.size()) { z.push_back({v.at(j).second, v.at(j).first}); }
      sort(ALL(z));
      int rlim = 0, co = 1;
      for (auto p : z) {
        if (p.second < rlim) continue;
        rlim = p.first;
        gr.at(l).push_back({p.first, hs.at(co++)});
        // cerr << l << " " << p.first << " " << hs.at(co - 1) << endl;
      }
      // rep2(j, i, v.size()) {
      //   int l = v.at(i).first, r = v.at(j).second;
      //   ll add = hs.at(j - i + 1);
      //   gr.at(l).push_back({r, add});
      //   cerr << l << " " << r << " " << add << endl;
      // }
    }
  }
  vector<ll> dp(sz + 1, 0);
  rep(i, sz) {
    dp.at(i + 1) = max(dp.at(i + 1), dp.at(i));
    for (auto [a, b] : gr.at(i)) {
      dp.at(a) = max(dp.at(a), dp.at(i) + b);
    }
  }
  // for (auto &p : mp) cerr << p.first << ":" << p.second << " ";
  // cerr << endl;
  // rep(i, sz + 1) { cerr << dp.at(i) << " "; }
  // cerr << endl;
  cout << dp.back() << endl;
  return 0;
}