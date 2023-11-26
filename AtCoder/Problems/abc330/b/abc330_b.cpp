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
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> ans(n);
  rep(i, n) {
    int in;
    cin >> in;
    if (l <= in && in <= r) {
      ans.at(i) = in;
      continue;
    }
    int lx = abs(in - l), rx = abs(in - r);
    if (lx > rx)
      ans.at(i) = r;
    else
      ans.at(i) = l;
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}