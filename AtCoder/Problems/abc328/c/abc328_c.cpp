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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> memo(n, 0);
  rep2(i, 1, n) {
    memo.at(i) += memo.at(i - 1);
    if (s.at(i) == s.at(i - 1)) memo.at(i)++;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int ans = memo.at(r);
    ans -= memo.at(l);
    cout << ans << endl;
  }
  return 0;
}