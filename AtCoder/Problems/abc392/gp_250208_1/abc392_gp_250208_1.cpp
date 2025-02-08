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

int main() {
  int n;
  cin >> n;
  vector<ll> co(1000005, 0);
  rep(i, n) {
    int in;
    cin >> in;
    co.at(in)++;
  }
  auto p = convolution(co, co);
  ll ans = 0;
  rep(i, co.size() - 2) {
    if (co.at(i) == 0) continue;
    ans += (p.at(i * 2) - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}