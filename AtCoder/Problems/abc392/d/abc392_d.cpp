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
  vector a(n, vector<int>(100001, 0));
  vector<int> ss(n, 0);
  rep(i, n) {
    int sz;
    cin >> sz;
    ss.at(i) = sz;
    rep(j, sz) {
      int in;
      cin >> in;
      a.at(i).at(in)++;
    }
  }
  vector memo(n, vector(n, vector<int>(0)));
  rep(i, 100001) {
    vector<int> t;
    rep(j, n) {
      if (a.at(j).at(i) != 0) t.push_back(j);
    }
    rep(j, t.size()) rep2(k, j + 1, t.size()) {
      memo.at(t.at(j)).at(t.at(k)).push_back(i);
    }
  }

  frac ans(0, 1);
  rep(i, n) rep2(j, i + 1, n) {
    frac add(0, (ll)ss.at(i) * ss.at(j));
    for (auto now : memo.at(i).at(j)) {
      add.top += (ll)a.at(i).at(now) * a.at(j).at(now);
    }
    if (ans < add) ans = add;
  }
  cout << fixed << setprecision(10) << (double)ans.top / ans.btm << endl;
  return 0;
}