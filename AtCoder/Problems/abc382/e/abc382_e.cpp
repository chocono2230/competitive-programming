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
  int n, x;
  cin >> n >> x;
  vector<int> p(n);
  rep(i, n) cin >> p.at(i);
  vector<double> nxb(n + 1, 0);
  auto nx = nxb;
  nx.front() = 1;
  rep(i, n) {
    auto nnx = nxb;
    double np = (double)p.at(i) / 100.0;
    double nq = 1 - np;
    rep(i, n) {
      nnx.at(i + 1) += nx.at(i) * np;
      nnx.at(i) += nx.at(i) * nq;
    }
    swap(nx, nnx);
  }
  rep(i, n + 1) cerr << nx.at(i) << " ";
  cerr << endl;
  double rp = 1.0 / (1.0 - nx.at(0));
  rep2(i, 1, n + 1) { nx.at(i) *= rp; }

  vector<double> dp(x + 1, 0);
  vector<double> pbase(x + 1, 0);
  auto pp = pbase;
  pp.front() = 1;
  double ans = 0;
  rep(i, x) { auto nxpp = pbase; }
  cout << fixed << setprecision(10) << dp.back() << endl;
  return 0;
}