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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  ll now = 0;
  set<pair<int, int>> s1, s2;
  vector<ll> ans;
  rep(i, n) {
    // cerr << i << " " << now << endl;
    if (s1.size() < k) {
      s1.insert({a.at(i), i});
      now += a.at(i);
    } else {
      s2.insert({a.at(i), i});
      auto is2 = s2.begin(), is1 = s1.end();
      is1--;
      if (is1->first > is2->first) {
        auto p = *is2, q = *is1;
        s2.erase(is2);
        s1.erase(is1);
        s1.insert(p);
        s2.insert(q);
        now += p.first - q.first;
      }
    }
    if (i >= m - 1) ans.push_back(now);
    if (i - m + 1 >= 0) {
      pair<int, int> tt(a.at(i - m + 1), i - m + 1);
      if (s1.find(tt) != s1.end()) {
        now -= tt.first;
        s1.erase(tt);
        if (!s2.empty()) {
          auto it = s2.begin();
          now += it->first;
          s1.insert(*it);
          s2.erase(it);
        }
      } else {
        s2.erase(tt);
      }
    }
  }
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}