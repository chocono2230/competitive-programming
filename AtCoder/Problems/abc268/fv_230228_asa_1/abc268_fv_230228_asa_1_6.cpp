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

struct frac {
  ll top = 0, btm = 1;
  frac(ll top, ll btm) : top(top), btm(btm) {}
  frac() {}
  friend bool operator<(const frac &l, const frac &r) {
    return l.top * r.btm < r.top * l.btm;
  }
  friend bool operator==(const frac &l, const frac &r) {
    return l.top * r.btm == r.top * l.btm;
  }
};

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<pair<frac, int>> v(n);
  rep(i, n) {
    int p = 0, q = 0;
    for (auto c : s.at(i)) {
      if (c == 'X')
        q++;
      else
        p += c - '0';
    }
    v.at(i) = {frac(p, q), i};
  }
  sort(ALL(v));
  string aa;
  rep(i, n) {
    auto [a, idx] = v.at(i);
    aa += s.at(idx);
  }
  // cerr << aa << endl;
  ll ans = 0, sum = 0;
  rrep(i, aa.size()) {
    auto c = aa.at(i);
    if (c == 'X')
      ans += sum;
    else
      sum += c - '0';
  }
  cout << ans << endl;
  return 0;
}