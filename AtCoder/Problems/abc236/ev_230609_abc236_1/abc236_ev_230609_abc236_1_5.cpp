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
  auto f1 = [&]() -> void {
    double ok = 0, ng = 1e9 + 5;
    rep(_i, 100) {
      double mid = (ok + ng) / 2;
      auto fc = [&]() -> bool {
        const double INF = 1e18;
        vector dp(n + 1, vector<double>(2, -INF));
        dp.front().front() = 0;
        rep(i, n) {
          int ni = i + 1;
          double now = a.at(i) - mid;
          dp.at(ni).at(0) = max(dp.at(ni).at(0), dp.at(i).at(0) + now);
          dp.at(ni).at(0) = max(dp.at(ni).at(0), dp.at(i).at(1) + now);
          dp.at(ni).at(1) = max(dp.at(ni).at(1), dp.at(i).at(0));
        }
        return dp.back().front() >= 0 || dp.back().back() >= 0;
      };
      if (fc())
        ok = mid;
      else
        ng = mid;
    }
    cout << fixed << setprecision(5) << ok << endl;
  };
  f1();
  auto f2 = [&]() -> void {
    int ok = 0, ng = 1e9 + 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      auto fc = [&]() -> bool {
        const int INF = 1001001001;
        vector dp(n + 1, vector<int>(2, -INF));
        dp.front().front() = 0;
        rep(i, n) {
          int ni = i + 1;
          int now = (a.at(i) - mid >= 0 ? 1 : -1);
          dp.at(ni).at(0) = max(dp.at(ni).at(0), dp.at(i).at(0) + now);
          dp.at(ni).at(0) = max(dp.at(ni).at(0), dp.at(i).at(1) + now);
          dp.at(ni).at(1) = max(dp.at(ni).at(1), dp.at(i).at(0));
        }
        return dp.back().front() > 0 || dp.back().back() > 0;
      };
      if (fc())
        ok = mid;
      else
        ng = mid;
    }
    cout << ok << endl;
  };
  f2();
  return 0;
}