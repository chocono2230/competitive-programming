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
  vector<int> a(3 * n);
  rep(i, 3 * n) cin >> a.at(i);
  rep(i, 3 * n) a.at(i)--;
  vector<int> co(n, 0);
  vector<pair<int, int>> ans(n, {-1, -1});
  rep(i, n * 3) {
    co.at(a.at(i))++;
    if (co.at(a.at(i)) == 2) ans.at(a.at(i)) = {i, a.at(i)};
  }
  sort(ALL(ans));
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i).second + 1;
  }
  cout << endl;
  return 0;
}