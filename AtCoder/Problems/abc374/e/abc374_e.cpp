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
  int n, x;
  cin >> n >> x;
  using P = pair<ll, ll>;
  vector<pair<P, P>> v(n);
  rep(i, n) {
    int a, p;
    cin >> a >> p;
    int b, q;
    cin >> b >> q;
    v.at(i) = {{a, p}, {b, q}};
  }
  int ok = 0, ng = 1001001001;
  const ll INF = 1e18;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    auto fc = [&]() {
      ll sum = 0;
      rep(i, n) {
        double l = 0, r = 1e7;
        auto &[p, q] = v.at(i);
        rep(_i, 40) {
          double d = (r - l);
          double l1 = l + d / 3;
          double r1 = l + d * 2 / 3;
          auto fc = [&](double x) {
            double ss = p.first * x;
            double cost = p.second * x;
            double z = max(0.0, mid - ss);
            double y = z / q.first;
            cost += q.second * y;
            return cost;
          };
          if (fc(l1) < fc(r1))
            r = r1;
          else
            l = l1;
        }
        int mn = max(0, (int)l - 100);
        int mx = min(10000005, (int)r + 100);
        ll add = INF;
        rep2(i, mn, mx + 1) {
          ll ss = p.first * i;
          ll cost = p.second * i;
          ll z = max(0LL, mid - ss);
          ll y = (z + q.first - 1) / q.first;
          cost += q.second * y;
          add = min(add, cost);
        }
        sum += add;
        if (sum > x) return false;
      }
      // cerr << mid << " " << sum << endl;
      return true;
    };
    if (fc())
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}