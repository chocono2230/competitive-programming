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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int m;
  cin >> m;
  vector flg(100005, false);
  rep(i, m) {
    int in;
    cin >> in;
    flg.at(in) = true;
  }
  int x;
  cin >> x;
  vector dp(x + 1, false);
  dp.front() = true;
  rep(i, x + 1) {
    if (!dp.at(i)) continue;
    for (auto add : a) {
      int ni = i + add;
      if (ni >= x + 1 || flg.at(ni)) continue;
      dp.at(ni) = true;
    }
  }
  if (dp.back())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}