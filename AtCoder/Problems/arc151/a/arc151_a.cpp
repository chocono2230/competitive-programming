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
  string s, t;
  cin >> s >> t;
  vector<int> ans(n, -1);
  int co = 0;
  rep(i, n) {
    if (s.at(i) == t.at(i))
      ans.at(i) = 0;
    else {
      ans.at(i) = 1;
      co++;
    }
  }
  if (co % 2 == 1) {
    cout << -1 << endl;
    return 0;
  }
  int sc = 0, tc = 0, ss = co;
  string out(n, '0');
  rep(i, n) {
    if (ans.at(i) == 0) continue;
    if (tc + ss == co / 2) {
      tc++;
      out.at(i) = t.at(i);
    } else if (sc + ss == co / 2) {
      sc++;
      out.at(i) = s.at(i);
    } else if (s.at(i) == '0') {
      sc++;
    } else {
      tc++;
    }
    ss--;
  }
  cout << out << endl;
  return 0;
}