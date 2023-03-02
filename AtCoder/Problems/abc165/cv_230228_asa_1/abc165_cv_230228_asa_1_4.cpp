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

int m;
vector<tuple<int, int, int, int>> abcd;
vector<int> ans;

int rv(int lv, int p) {
  if (lv == ans.size()) {
    int res = 0;
    for (auto [a, b, c, d] : abcd) {
      if (ans.at(b) - ans.at(a) == c) {
        res += d;
      }
    }
    return res;
  }
  int res = 0;
  rep2(add, p, m + 1) {
    ans.at(lv) = add;
    res = max(res, rv(lv + 1, add));
  }
  return res;
}

int main() {
  int n, q;
  cin >> n >> m >> q;
  abcd.resize(q);
  ans.resize(n);
  rep(i, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    abcd.at(i) = {a, b, c, d};
  }
  cout << rv(0, 1) << endl;
  return 0;
}