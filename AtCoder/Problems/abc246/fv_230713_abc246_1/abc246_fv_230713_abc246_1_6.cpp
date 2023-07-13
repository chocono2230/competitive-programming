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
  int n, l;
  cin >> n >> l;
  vector s(n, vector<bool>(26, false));
  rep(i, n) {
    string in;
    cin >> in;
    for (auto c : in) {
      s.at(i).at(c - 'a') = true;
    }
  }
  vector<mint> pw(30, 1);
  rep(i, 30) pw.at(i) = mint(i).pow(l);
  mint ans = 0;
  rep2(bit, 1, 1 << n) {
    vector<int> v;
    rep(i, n) {
      if ((bit & (1 << i)) != 0) v.push_back(i);
    }
    int co = 0;
    rep(i, 26) {
      bool f = false;
      for (auto now : v) {
        if (!s.at(now).at(i)) f = true;
      }
      if (!f) co++;
    }
    mint add = pw.at(co);
    if (v.size() % 2 == 0)
      ans -= add;
    else
      ans += add;
  }
  cout << ans.val() << endl;
  return 0;
}