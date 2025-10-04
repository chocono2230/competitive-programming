#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto fc = [&](char ta) {
      vector<int> v(n, 0), rv(n, 0);
      rep(i, n) v.at(i) = (s.at(i) == ta ? 1 : 0);
      rep(i, n) rv.at(i) = (s.at(i) != ta ? 1 : 0);
      vector<ll> sv(n + 1, 0);
      rep(i, n) sv.at(i + 1) = sv.at(i) + v.at(i);
      vector<ll> srv(n + 1, 0);
      rep(i, n) srv.at(i + 1) = srv.at(i) + rv.at(i);
      int l = 0, r = 0;
      ll res = 1e18;
      while (l != n) {
        if (v.at(l) != 1) {
          l++;
          continue;
        }
        r = l + 1;
        while (r != n && v.at(r) != 0) r++;
        ll ans = 0;
        ans += srv.at(l);
        ans += sv.at(l) * 2;
        ans += srv.at(n) - srv.at(r);
        ans += (sv.at(n) - sv.at(r)) * 2;
        res = min(res, ans);
        l = r;
      }
      return res;
    };
    cout << min(fc('0'), fc('1')) << endl;
  }
  return 0;
}