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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  set<int> se;
  vector<int> pos(m, -1);
  rep(i, n) {
    int now = a.at(i) - 1;
    if (pos.at(now) == -1) {
      pos.at(now) = i;
      se.insert(i);
      continue;
    }
    auto itr = se.lower_bound(pos.at(now));
    itr++;
    if (itr == se.end()) continue;
    if (now > a.at(*itr)) {
      se.erase(pos.at(now));
      pos.at(now) = i;
      se.insert(i);
    }
  }
  vector<int> ans;
  for (auto idx : se) {
    ans.push_back(a.at(idx));
  }
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}