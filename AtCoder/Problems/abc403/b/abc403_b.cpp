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
  string t, u;
  cin >> t >> u;
  bool f = false;
  rep(i, t.size()) {
    string tt = t.substr(i, u.size());
    if (tt.size() != u.size()) break;
    bool k = false;
    rep(i, u.size()) { k |= (tt.at(i) != '?' && u.at(i) != tt.at(i)); }
    if (!k) f = true;
  }
  if (f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}