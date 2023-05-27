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
  ll h;
  cin >> n >> h;
  vector<pair<int, int>> td(n);
  rep(i, n) {
    int t, d;
    cin >> t >> d;
    td.at(i) = {t, d};
  }
  vector<pair<int, int>> tmxv(n);
  rep(i, n) { tmxv.at(i) = td.at(i); }
  sort(ALL(tmxv));
  reverse(ALL(tmxv));

  ll ok = 1e18 + 5, ng = 0;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    // cerr << ok << " " << ng << endl;
    auto fc = [&]() -> bool {
      ll sh = h;
      priority_queue<tuple<ll, ll, ll>> q;
      rep(i, n) {
        auto [t, d] = td.at(i);
        q.push({(ll)d * t, d, t});
      }
      ll tmx = 0;
      int tvidx = 0;
      for (ll time = 0; time < mid;) {
        while (tvidx < tmxv.size()) {
          auto [t, d] = tmxv.at(tvidx);
          if (time + t >= mid) {
            tmx = max(tmx, (ll)d);
          } else {
            break;
          }
          tvidx++;
        }
        ll qadd = 0, qmul = 1;
        while (!q.empty()) {
          auto [ss, d, t] = q.top();
          if (time + t > mid) {
            q.pop();
          } else {
            qadd = ss;
            qmul = mid - time - t + 1;
            break;
          }
        }
        if (tmx == 0) {
          if (qadd > LLONG_MAX / qmul) return true;
          sh -= qadd * qmul;
          time += qmul;
        } else {
          ll z = mid - time;
          if (z > LLONG_MAX / z) return true;
          ll d = z * (z + 1) / 2;
          if (tmx > LLONG_MAX / d) return true;
          ll tadd = tmx * d;
          if (sh - tadd <= 0) return true;
          if (qadd == 0) return false;

          if (qadd > LLONG_MAX / qmul) return true;
          sh -= qadd * qmul;
          time += qmul;
        }
        if (sh <= 0) return true;
      }
      return false;
    };
    if (fc())
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}