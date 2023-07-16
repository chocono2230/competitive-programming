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
  vector<tuple<int, int, bool>> xy(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xy.at(i) = {y, x, false};
  }
  string s;
  cin >> s;
  rep(i, n) {
    if (s.at(i) == 'L') get<2>(xy.at(i)) = true;
  }
  sort(ALL(xy));
  int bx = -1;
  bool f = false;
  for (auto [x, y, t] : xy) {
    if (x != bx) f = false;
    if (t) {
      if (f) {
        cout << "Yes" << endl;
        return 0;
      }
    } else {
      f = true;
    }
    bx = x;
  }
  cout << "No" << endl;
  return 0;
}