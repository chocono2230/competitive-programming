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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  auto fc = [&]() {
    vector<bool> chk(m + 1, false);
    chk.at(0) = true;
    for (auto now : a) chk.at(now) = true;
    rep(i, m + 1) if (!chk.at(i)) return true;
    return false;
  };
  rep(i, n + 1) {
    if (fc()) {
      cout << i << endl;
      return 0;
    }
    a.pop_back();
  }
  return 0;
}