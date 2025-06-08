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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pl = -1, pr = -1;
    string nw;
    rep(i, n - 1) {
      if (s.at(i) <= s.at(i + 1)) continue;
      int r = n;
      rep2(j, i + 1, n) {
        if (s.at(i) < s.at(j)) {
          nw.push_back(s.at(i));
          r = j;
          break;
        }
        nw.push_back(s.at(j));
      }
      pl = i, pr = r;
      if (pr == n) nw.push_back(s.at(i));
      break;
    }
    // cerr << pl << " " << pr << " " << nw << endl;
    rep(i, n) {
      if (i < pl || pr <= i)
        cout << s.at(i);
      else {
        cout << nw;
        i = pr - 1;
      }
    }
    cout << endl;
  }
  return 0;
}