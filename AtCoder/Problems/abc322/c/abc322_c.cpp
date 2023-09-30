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
  vector<int> a(m);
  rep(i, m) {
    cin >> a.at(i);
    a.at(i)--;
  }
  int idx = m - 1;
  vector<int> ans(n, 0);
  rrep(i, n) {
    if (idx != 0 && a.at(idx - 1) == i) idx--;
    ans.at(i) = a.at(idx) - i;
  }
  for (auto now : ans) cout << now << endl;
  return 0;
}