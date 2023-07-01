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
  vector<pair<frac, int>> v;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    v.push_back({frac(a, a + b), -i});
  }
  sort(ALL(v));
  rrep(i, n) {
    if (i != n - 1) cout << " ";
    cout << v.at(i).second * -1 + 1;
  }
  cout << endl;
  return 0;
}