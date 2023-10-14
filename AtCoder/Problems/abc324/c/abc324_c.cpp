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
  vector<int> ans;
  rep(_i, n) {
    string s;
    cin >> s;
    bool f = false;
    if (s.size() == t.size()) {
      int z = 0;
      rep(i, s.size()) {
        if (s.at(i) != t.at(i)) z++;
      }
      if (z <= 1) f = true;
    } else if (abs((int)s.size() - (int)t.size()) == 1) {
      string p, q;
      if (s.size() < t.size()) {
        p = s;
        q = t;
      } else {
        p = t;
        q = s;
      }
      int flg = 0;
      rep(i, p.size()) {
        if (p.at(i) != q.at(flg + i)) {
          flg++;
          if (flg == 2) {
            break;
          }
          if (p.at(i) != q.at(flg + i)) {
            flg++;
            break;
          }
        }
      }
      if (flg <= 1) f = true;
    }
    if (f) ans.push_back(_i);
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}