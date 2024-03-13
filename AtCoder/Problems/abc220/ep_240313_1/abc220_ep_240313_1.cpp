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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n, d;
  cin >> n >> d;

  vector<mint> pw(1, 1);
  rep(i, max(n, d) + 5) pw.push_back(pw.back() * 2);
  mint now = 0, ans = 0, base = 0;
  bool f = false;
  rrep(lv, n) {
    int mxd = n - lv - 1;
    if (mxd * 2 < d) continue;
    mint add = 0;
    if (mxd >= d) {
      add = now * 2 + pw.at(d + 1);
    } else {
      if (!f) {
        int ld = mxd;
        int rd = d - ld;
        base = pw.at(ld - 1) * pw.at(rd - 1);
        now += base;
        if (d % 2 == 1) {
          now += base;
        }
        f = true;
      } else {
        now += base * 2;
      }
      add = now * 2;
    }
    // cerr << lv << " " << mxd << " " << add.val() << " " << now.val() << " "
    //      << pw.at(lv).val() << endl;
    ans += add * pw.at(lv);
  }
  cout << ans.val() << endl;
  return 0;
}