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

ll mod = 2252048541436975301;

using S = tuple<ll, ll, ll, ll>;

S op(const S l, const S r) {
  auto res = l;
  get<0>(res) += get<0>(r);
  get<1>(res) += get<1>(r);
  get<2>(res) += get<2>(r);
  get<3>(res) += get<3>(r);
  get<0>(res) %= mod;
  get<1>(res) %= mod;
  get<2>(res) %= mod;
  get<3>(res) %= mod;
  return res;
};

S e() { return {0, 0, 0, 0}; }

vector<vector<ll>> hashs(int p) {
  vector res(4, vector<ll>(p, 0));
  random_device rd;
  auto randomNumber = [&]() {
    ll res = abs((ll)rd());
    res %= mod;
    return res;
  };
  rep(i, res.size()) {
    rep(j, p) {
      auto r = randomNumber();
      res.at(i).at(j) = r;
    }
  }
  return res;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
  }
  vector<int> b(n);
  rep(i, n) {
    cin >> b.at(i);
    b.at(i)--;
  }
  vector<int> num;
  auto hv = hashs(200005);
  segtree<S, op, e> as(n), bs(n);
  auto ff = [&](int now) -> S {
    return {hv.at(0).at(now), hv.at(1).at(now), hv.at(2).at(now),
            hv.at(3).at(now)};
  };
  rep(i, n) {
    S aa = ff(a.at(i));
    as.set(i, aa);
    aa = ff(b.at(i));
    bs.set(i, aa);
  }

  while (q--) {
    int l1, r1;
    cin >> l1 >> r1;
    l1--;
    int l2, r2;
    cin >> l2 >> r2;
    l2--;
    if (r1 - l1 != r2 - l2) {
      cout << "No" << endl;
      continue;
    }
    auto p1 = as.prod(l1, r1);
    auto p2 = bs.prod(l2, r2);
    // cerr << get<0>(p1) << " " << get<0>(p2) << endl;
    if (p1 == p2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}