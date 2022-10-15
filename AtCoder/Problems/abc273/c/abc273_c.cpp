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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  sort(ALL(a));
  vector<int> ans(n, 0);
  ans.front()++;
  int co = 0;
  rrep(i, n - 1) {
    if (a.at(i) == a.at(i + 1)) co++;
    int p = n - 1 - i - co;
    // cerr << n - 1 - i << " " << co << " " << p << endl;
    ans.at(p)++;
  }
  for (auto i : ans) cout << i << endl;
  return 0;
}