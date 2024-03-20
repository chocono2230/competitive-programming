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

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  int dh, dw;
  cin >> dh >> dw;
  vector a(h, vector<int>(w, 0));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  vector sum(h + 1, vector(w + 1, vector<int>(n, 0)));
  vector<int> co(n, 0);
  rep(i, h) rep(j, w) {
    int ni = i + 1;
    int nj = j + 1;
    rep(k, n) { sum.at(ni).at(nj).at(k) -= sum.at(i).at(j).at(k); }
    int now = a.at(i).at(j) - 1;
    co.at(now)++;
    sum.at(ni).at(nj).at(now)++;
    rep(k, n) {
      if (i != h - 1) sum.at(ni + 1).at(nj).at(k) += sum.at(ni).at(nj).at(k);
      if (j != w - 1) sum.at(ni).at(nj + 1).at(k) += sum.at(ni).at(nj).at(k);
    }
  }

  vector ans(h - dh + 1, vector<int>(w - dw + 1, 0));
  rep(i, h - dh + 1) rep(j, w - dw + 1) {
    vector<int> ss(n, 0);
    auto fc = [&](int i, int j, int mul) {
      rep(k, n) ss.at(k) += sum.at(i).at(j).at(k) * mul;
    };
    fc(i + dh, j + dw, 1);
    fc(i + dh, j, -1);
    fc(i, j + dw, -1);
    fc(i, j, 1);
    int add = 0;
    rep(i, n) {
      if (co.at(i) != 0 && co.at(i) != ss.at(i)) add++;
    }
    ans.at(i).at(j) = add;
  }
  rep(i, ans.size()) {
    rep(j, ans.at(i).size()) {
      if (j != 0) cout << " ";
      cout << ans.at(i).at(j);
    }
    cout << endl;
  }
  return 0;
}