#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
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

struct P {
  frac x;
  int flg = 0;
  P() : x(frac()) {}
  P(ll y, ll x, int flg) : x(frac(y, x)), flg(flg){};
  friend bool operator<(const P &l, const P &r) {
    if (l.flg != r.flg) {
      return l.flg < r.flg;
    }
    return l.x < r.x;
  }
  friend bool operator==(const P &l, const P &r) {
    return l.flg == r.flg && l.x < r.x;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> xy(n);
  vector<P> pv(n);
  map<P, vector<int>> mp;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
    P add;
    if (x > 0 && y <= 0) {
      add = P(-y, x, 0);
    }
    if (y < 0 && x <= 0) {
      add = P(-x, -y, 1);
    }
    if (x < 0 && y >= 0) {
      add = P(y, -x, 2);
    }
    if (y > 0 && x >= 0) {
      add = P(x, y, 3);
    }
    mp[add].push_back(i);
    pv.at(i) = add;
    add.flg += 4;
    mp[add].push_back(i);
  }
  vector<pair<int, int>> co(n, {-1, -1});
  vector<int> vv;
  int sz = 0;
  for (auto p : mp) {
    for (auto i : p.second) {
      if (co.at(i).first == -1)
        co.at(i).first = sz;
      else
        co.at(i).second = sz;
    }
    vv.push_back(p.second.size());
    if (vv.size() != 1) vv.back() += vv.at(vv.size() - 2);
    sz++;
  }
  vector<ll> sums(vv.size() + 1, 0);
  rep(i, vv.size()) sums.at(i + 1) = sums.at(i) + vv.at(i);
  // rep(i, vv.size()) cerr << vv.at(i) << " ";
  // cerr << endl;

  while (q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    auto p = co.at(a);
    auto q = co.at(b);
    // cerr << p.first << " " << q.first << endl;
    int ans = 0;
    // cerr << p.first + 1 << " " << q.first + 1 << endl;
    // cerr << p.second + 1 << " " << q.second + 1 << endl;
    ans = mp[pv.at(a)].size();
    if (p != q) {
      if (p.first < q.first) {
        ans += vv.at(q.first) - vv.at(p.first);
      } else {
        ans += vv.at(q.second) - vv.at(p.first);
      }
    }
    cout << ans << endl;
  }
  return 0;
}