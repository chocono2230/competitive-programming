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
  ll k;
  int n, m;
  cin >> n >> m >> k;
  vector<pair<int, int>> ab(n), cd(m);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = {a, b};
  }
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    cd.at(i) = {a, b};
  }

  double ok = 0, ng = 1;
  rep(_i, 100) {
    double mid = (ok + ng) / 2;
    auto fc = [&]() -> bool {
      ll co = 0;
      vector<double> t(m);
      rep(i, m) {
        auto [a, b] = cd.at(i);
        double u = b * mid / (1 - mid);
        t.at(i) = a - u;
      }
      sort(ALL(t));
      for (const auto [a, b] : ab) {
        double u = b * mid / (1 - mid);
        double x = -(a - u);
        int ng = -1, ok = m;
        while (ok - ng > 1) {
          int mi = (ok + ng) / 2;
          if (t.at(mi) < x)
            ng = mi;
          else
            ok = mi;
        }
        co += m - ok;
      }
      // cerr << ok << " " << mid << " " << ng << " " << co << " " << k << " "
      //      << _i << endl;
      return co >= k;
    };
    if (fc())
      ok = mid;
    else
      ng = mid;
    // cerr << ok << " " << mid << " " << ng << endl;
  }
  ok *= 100;
  cout << fixed << setprecision(10) << ok << endl;
  return 0;
}