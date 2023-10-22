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
  vector<pair<ll, ll>> td(n);
  rep(i, n) {
    ll t, d;
    cin >> t >> d;
    td.at(i) = {t, t + d};
  }
  sort(ALL(td));
  map<ll, vector<int>> out;

  ll now = 0;
  int ans = 0;
  set<pair<ll, int>> se;
  int idx = 0;
  set<ll> ev;
  ev.insert(td.at(0).first);
  while (1) {
    now = *ev.begin();
    ev.erase(now);
    while (idx != n && td.at(idx).first == now) {
      out[td.at(idx).second].push_back(idx);
      se.insert({td.at(idx).second, idx});
      ev.insert(td.at(idx).second);
      idx++;
      if (idx != n && td.at(idx).first != now) {
        ev.insert(td.at(idx).first);
      }
    }
    if (!se.empty()) {
      ans++;
      se.erase(se.begin());
      if (!se.empty()) ev.insert(now + 1);
    }
    if (out.find(now) != out.end()) {
      for (auto idx : out[now]) {
        auto itr = se.find({now, idx});
        if (itr != se.end()) se.erase(itr);
      }
      out.erase(now);
    }
    if (ev.empty()) break;
  }
  cout << ans << endl;
  return 0;
}