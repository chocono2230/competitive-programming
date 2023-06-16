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

const int MX = 100005;

vector<int> make_prime_vec(int lim) {
  vector<int> ps;
  vector<bool> chk(lim + 1, true);
  chk.at(0) = chk.at(1) = false;
  rep2(i, 2, chk.size()) {
    if (chk.at(i) == false) continue;
    ps.push_back(i);
    for (int j = i + i; j < chk.size(); j += i) chk.at(j) = false;
  }
  return ps;
}

int dfs(vector<vector<int>> &gr, vector<bool> &use, vector<bool> &chk, int now,
        mint &t, mint &tt) {
  chk.at(now) = true;
  int res = 1;
  for (auto nx : gr.at(now)) {
    if (!use.at(nx) || chk.at(nx)) continue;
    int r = dfs(gr, use, chk, nx, t, tt);
    t += r;
    tt += (ll)r * r;
    res += r;
  }
  return res;
}

int main() {
  auto pv = make_prime_vec(MX);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector ms(MX, vector<int>());
  rep(i, n) ms.at(a.at(i)).push_back(i);
  for (auto p : pv) {
    rrep2(i, 1, MX / p + 1) {
      int z = i * p;
      if (z >= MX) continue;
      ms.at(i).insert(ms.at(i).end(), ALL(ms.at(z)));
    }
  }
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  vector<mint> f(MX, 0), g(MX, 0);
  vector<bool> use(n, false);
  vector<bool> chk(n, false);
  rep2(i, 1, MX) {
    for (auto now : ms.at(i)) use.at(now) = true;
    for (auto st : ms.at(i)) {
      if (chk.at(st)) continue;
      mint t = 0, tt = 0;
      int s = dfs(tree, use, chk, st, t, tt);
      f.at(i) += t * s - tt + (ll)s * (s - 1) / 2;
    }
    for (auto now : ms.at(i)) use.at(now) = false;
    for (auto now : ms.at(i)) chk.at(now) = false;
  }
  rrep2(i, 1, MX) {
    g.at(i) = f.at(i);
    int now = i + i;
    while (now < MX) {
      g.at(i) -= g.at(now);
      now += i;
    }
  }
  // rep(i, 31) cerr << f.at(i).val() << " ";
  // cerr << endl;
  // rep(i, 31) cerr << g.at(i).val() << " ";
  // cerr << endl;
  mint ans = 0;
  rep(i, MX) ans += g.at(i) * i;
  cout << ans.val() << endl;
  return 0;
}