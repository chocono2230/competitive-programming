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
  int ans = 0;
  sort(ALL(a), greater<int>());
  while (1) {
    ans++;
    a.at(0)--;
    a.at(1)--;
    sort(ALL(a), greater<int>());
    while (!a.empty()) {
      if (a.back() > 0) break;
      a.pop_back();
    }
    if (a.size() <= 1) break;
  }
  cout << ans << endl;
  return 0;
}