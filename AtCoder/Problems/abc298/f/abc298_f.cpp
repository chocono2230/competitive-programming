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
  vector<tuple<int, int, int>> rcx(n);
  map<int, int> mp;
  rep(i, n) {
    int r, c, x;
    cin >> r >> c >> x;
    rcx.at(i) = {r, c, x};
    mp[r] = -1;
    mp[c] = -1;
  }
  int sz = 0;
  for (auto &p : mp) p.second = sz++;
  vector<pair<ll, int>> h(sz, {0, 0}), w(sz, {0, 0});
  rep(i, sz) h.at(i).second = i, w.at(i).second = i;
  map<pair<int, int>, int> tx;
  rep(i, n) {
    auto [rp, cp, x] = rcx.at(i);
    int r = mp[rp], c = mp[cp];
    h.at(r).first += x;
    w.at(c).first += x;
    tx[{r, c}] = x;
  }
  ll ans = 0;
  for (auto [p, x] : tx) {
    auto [r, c] = p;
    ll add = h.at(r).first + w.at(c).first;
    add -= x;
    ans = max(ans, add);
  }
  sort(ALL(h));
  sort(ALL(w));
  priority_queue<tuple<ll, int, int>> q;
  ll zz = h.back().first + w.back().first;
  q.push({zz, h.size() - 1, w.size() - 1});
  set<pair<int, int>> se;
  se.insert({h.size() - 1, w.size() - 1});
  while (!q.empty()) {
    auto [add, i, j] = q.top();
    int ii = h.at(i).second, jj = w.at(j).second;
    q.pop();
    if (tx.find({ii, jj}) == tx.end()) {
      ans = max(ans, add);
      break;
    }
    if (i != 0 && se.find({i - 1, j}) == se.end()) {
      ll nx = h.at(i - 1).first + w.at(j).first;
      q.push({nx, i - 1, j});
      se.insert({i - 1, j});
    }
    if (j != 0 && se.find({i, j - 1}) == se.end()) {
      ll nx = h.at(i).first + w.at(j - 1).first;
      q.push({nx, i, j - 1});
      se.insert({i, j - 1});
    }
  }
  cout << ans << endl;
  return 0;
}