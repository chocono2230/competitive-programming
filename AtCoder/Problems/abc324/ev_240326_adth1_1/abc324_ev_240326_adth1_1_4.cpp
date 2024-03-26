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
  string t;
  cin >> t;
  auto rt = t;
  reverse(ALL(rt));
  vector<int> pv, sv;
  rep(i, n) {
    string s;
    cin >> s;
    auto fc = [&](string &t) {
      int idx = 0;
      for (auto c : s) {
        if (idx == t.size()) return idx;
        if (c == t.at(idx)) idx++;
      }
      return idx;
    };
    pv.push_back(fc(t));
    reverse(ALL(s));
    sv.push_back(fc(rt));
  }
  sort(ALL(pv));
  sort(ALL(sv), greater<int>());
  ll ans = 0;
  int si = 0;
  for (auto p : pv) {
    while (si != sv.size()) {
      if (sv.at(si) + p >= t.size())
        si++;
      else
        break;
    }
    ans += si;
  }
  cout << ans << endl;
  return 0;
}