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

mint p = 1, rp = 0;

mint rc(int now) {
  static vector<mint> dp(200005, 0);
  static vector<bool> chk(200005, false);
  if (now <= 0) return 0;
  if (chk.at(now)) return dp.at(now);
  chk.at(now) = true;
  mint res = (rc(now - 1) + 1) * rp + (rc(now - 2) + 1) * p;
  return dp.at(now) = res;
}

int main() {
  int n, ip;
  cin >> n >> ip;
  p = (mint)ip / 100;
  rp = (mint)(100 - ip) / 100;
  cout << rc(n).val() << endl;
  return 0;
}