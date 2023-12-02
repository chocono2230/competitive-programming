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
  int n;
  cin >> n;
  vector<pair<int, int>> ai(n);
  rep(i, n) {
    int in;
    cin >> in;
    ai.at(i) = {in, i};
  }
  sort(ALL(ai));
  ll sum = 0, psum = 0;
  vector<ll> ans(n, 0);
  rrep(i, n) {
    auto [a, idx] = ai.at(i);
    if (i != n - 1 && a < ai.at(i + 1).first) {
      sum += psum;
      psum = 0;
    }
    ans.at(idx) = sum;
    psum += a;
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}