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
  vector<int> a(n), b(n);
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
    b.at(a.at(i)) = i;
  }
  vector<pair<int, int>> ans;
  rep(i, n) {
    if (b.at(i) == i) continue;
    ans.push_back({i, b.at(i)});
    int z = b.at(i);
    b.at(a.at(i)) = b.at(i);
    b.at(i) = i;
    swap(a.at(i), a.at(z));
  }
  cout << ans.size() << endl;
  for (auto [a, b] : ans) cout << a + 1 << " " << b + 1 << endl;
  return 0;
}