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
  vector<pair<ll, ll>> td(n);
  multiset<pair<ll, ll>> se;
  rep(i, n) {
    int t, d;
    cin >> t >> d;
    td.at(i) = {t, d};
    se.insert({d, t});
  }
  sort(ALL(td));

  ll now = 0;
  ll smx = 0;
  const ll INF = 4e18;
  rep(i, n) {
    auto [t, d] = td.at(i);
    auto mxitr = se.end();
    mxitr--;
    ll mx = mxitr->first;
    ll sp = min((smx + mx - 1) / mx - 1, t);
    if (now < sp) {
      ll add = INF;
      ll dd = sp - now;
      if (!(smx > LLONG_MAX / dd)) add = smx * dd;
      if (h - add <= 0) {
        now += (h + smx - 1) / smx;
        h = 0;
        break;
      }
      h -= add;
      now = sp;
    }

    auto f1 = [&](ll t) -> ll {
      ll ok = t, ng = now;
      while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        auto ff = [&]() -> bool {
          if ((mid * (mid + 1) / 2 - now * (now + 1) / 2) > LLONG_MAX / mx)
            return true;
          ll z = (mid * (mid + 1) / 2 - now * (now + 1) / 2) * mx;
          return z >= h;
        };
        if (ff())
          ok = mid;
        else
          ng = mid;
      }
      return ok;
    };
    ll add = INF;
    if (!((t * (t + 1) / 2 - now * (now + 1) / 2) > LLONG_MAX / mx))
      add = (t * (t + 1) / 2 - now * (now + 1) / 2) * mx;

    if (h - add <= 0) {
      now = f1(t);
      h = 0;
      break;
    }
    h -= add;

    se.erase(se.find({d, t}));
    now = t;
    smx = max(smx, t * d);
  }
  // cerr << h << " " << now << endl;
  if (h > 0) {
    now += (h + smx - 1) / smx;
  }
  cout << now << endl;
  return 0;
}