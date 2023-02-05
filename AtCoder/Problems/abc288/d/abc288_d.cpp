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

int op(int l, int r) { return max(l, r); }
int e() { return 0; }

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector vk(k, vector<ll>(n + 1, 0));
  rep(p, k) {
    rep(i, n) {
      vk.at(p).at(i + 1) = vk.at(p).at(i);
      if (i % k == p) vk.at(p).at(i + 1) += a.at(i);
    }
  }
  // rep(z, k) {
  //   rep(i, n + 1) cerr << vk.at(z).at(i) << " ";
  //   cerr << endl;
  // }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    vector<ll> ans(k, 0);
    bool f = false;
    int p = r % k;
    rep2(z, 0, k) {
      // cerr << r - k + 1 << endl;
      ll now = vk.at(p).at(r - k + 1) - vk.at(p).at(l);
      // cerr << p << " " << now << endl;
      if (r % k == p) {
        // cerr << "X" << endl;
        rep2(i, 1, k) ans.at(i) -= now;
      } else {
        int idx = r % k - p - 1;
        if (idx < 0) idx += k;
        ans.at(k - 1 - idx) += now;
      }
      p--;
      if (p < 0) p = k - 1;
      // cerr << "T";
      // rep(i, k) cerr << ans.at(i) << " ";
      // cerr << endl;
    }
    int idx = r - 1;
    // rep(i, k) cerr << ans.at(i) << " ";
    // cerr << endl;
    p = k - 1;
    // cerr << "----" << endl;
    rrep2(i, 1, k) {
      // cerr << p << " " << idx << " " << ans.at(p) << " " << a.at(idx) <<
      // endl;
      if (a.at(idx--) != -ans.at(p)) f = true;
      p--;
      if (p < 0) p = k - 1;
    }
    if (!f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}