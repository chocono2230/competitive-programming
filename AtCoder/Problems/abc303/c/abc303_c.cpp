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
  int h, k;
  cin >> h >> k;
  string s;
  cin >> s;
  set<pair<int, int>> se;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    se.insert({x, y});
  }
  int xi = 0, yi = 0;
  bool ans = false;

  for (auto c : s) {
    if (c == 'R') xi++;
    if (c == 'L') xi--;
    if (c == 'U') yi++;
    if (c == 'D') yi--;
    h--;
    if (h < 0) {
      ans = true;
      break;
    }
    if (se.find({xi, yi}) != se.end() && h < k) {
      h = max(h, k);
      se.erase({xi, yi});
    }
  }
  if (!ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}