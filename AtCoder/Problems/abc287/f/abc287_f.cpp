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

vector memo(3, vector(5001, vector<mint>(5001, 0)));
vector sz(5001, 0);
void rc(vector<vector<int>> &tree, int now, int bf) {
  static vector<bool> chk(5001, false);
  chk.at(now) = true;
  vector<mint> nv(5001, 0);
  vector<mint> tv(5001, 0);
  nv.at(0) = 1;
  tv.at(1) = 1;
  bool st = false;
  sz.at(now)++;
  for (auto nx : tree.at(now)) {
    if (nx == bf) continue;
    if (!chk.at(nx)) rc(tree, nx, now);
    sz.at(now) += sz.at(nx);
    if (!st) {
      nv = memo.at(2).at(nx);
      tv = memo.at(1).at(nx);
      rep2(i, 0, 5000) {
        if (i > sz.at(nx)) break;
        tv.at(i + 1) += memo.at(0).at(nx).at(i);
      }
      st = true;
      continue;
    }
    vector<mint> ss(5001, 0);
    rep(i, 5001) {
      if (i > sz.at(now)) break;
      rep(j, 5001) {
        if (j > sz.at(nx)) break;
        if (i + j > 5000) break;
        ss.at(i + j) += nv.at(i) * memo.at(2).at(nx).at(j);
      }
    }
    vector<mint> tt(5001, 0);
    rep(i, 5001) {
      if (i > sz.at(now)) break;
      rep(j, 5001) {
        if (j > sz.at(nx)) break;
        if (i + j > 5000) break;
        tt.at(i + j) += tv.at(i) * memo.at(0).at(nx).at(j);
      }
    }
    rep(i, 5001) {
      if (i > sz.at(now)) break;
      rep(j, 5001) {
        if (j > sz.at(nx)) break;
        if (i + j > 5000) break;
        if (i + j - 1 < 0) continue;
        tt.at(i + j - 1) += tv.at(i) * memo.at(0).at(nx).at(j);
      }
    }
    swap(ss, nv);
    swap(tt, tv);
  }
  vector<mint> tot(5001, 0);
  rep(i, 5001) tot.at(i) = nv.at(i) + tv.at(i);
  memo.at(0).at(now) = nv;
  memo.at(1).at(now) = tv;
  memo.at(2).at(now) = tot;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  rc(tree, 0, -1);
  rep2(i, 1, n + 1) { cout << memo.at(2).at(0).at(i).val() << endl; }
  return 0;
}