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
  ll n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector tb(26, vector<ll>(s.size() * 3 + 1, 0));
  rep(i, s.size() * 3) {
    rep(j, 26) {
      tb.at(j).at(i + 1) = tb.at(j).at(i);
      if (j + 'a' == s.at(i % s.size())) tb.at(j).at(i + 1)++;
    }
  }

  ll mxsz = s.size() * n;
  ll ok = 0, ng = mxsz / t.size() + 1;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    auto fc = [&] {
      ll nowIdx = 0;
      for (auto c : t) {
        int ci = c - 'a';
        // cerr << ci << " ";
        ll rt = tb.at(ci).at(s.size());
        if (rt == 0) return false;
        ll add = max(0LL, (mid - rt) / rt);
        // cerr << mid << " " << c << " " << ci << " " << rt << " " << add << "
        // ";
        if (add > LLONG_MAX / (ll)s.size() ||
            nowIdx + add * (ll)s.size() >= mxsz)
          return false;
        ll z = mid - add * rt;
        add *= s.size();
        // cerr << add;
        if (z != 0) {
          ll l = nowIdx % s.size(), r = s.size() * 3 + 1;
          ll pl = l;
          while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (tb.at(ci).at(mid) - tb.at(ci).at(l) < z)
              l = mid;
            else
              r = mid;
          }
          // cerr << " | " << r << " " << pl << " " << (r - pl);
          add += (r - pl);
        }
        // cerr << " " << nowIdx;
        nowIdx += add;
        // cerr << " " << nowIdx << endl;
        if (nowIdx >= mxsz) return false;
      }
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