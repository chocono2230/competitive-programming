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
  string s;
  cin >> s;
  vector<int> v(n);
  rep(i, n) {
    if (s.at(i) == 'R')
      v.at(i) = 0;
    else if (s.at(i) == 'P')
      v.at(i) = 1;
    else
      v.at(i) = 2;
  }
  const int INF = 1001001001;
  auto fc = [](int x, int y) {
    if ((x + 1) % 3 == y) return -INF;
    if (x == y) return 0;
    return 1;
  };
  vector dp(n, vector<int>(3, -INF));
  rep(s, 3) {
    int r = fc(s, v.at(0));
    dp.at(0).at(s) = r;
  }
  rep2(i, 1, n) {
    rep(j, 3) {
      int r = fc(j, v.at(i));
      rep(k, 3) {
        if (k == j) continue;
        dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(k) + r);
      }
    }
  }
  cout << *max_element(ALL(dp.back())) << endl;
  return 0;
}