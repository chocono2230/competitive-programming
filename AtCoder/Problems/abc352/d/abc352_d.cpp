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
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
  }
  vector<int> q(n);
  rep(i, n) q.at(p.at(i)) = i;
  set<int> se;
  rep(i, k) se.insert(q.at(i));
  auto ff = [&]() { return *se.rbegin() - *se.begin(); };
  int ans = ff();
  rep2(i, k, n) {
    se.insert(q.at(i));
    se.erase(q.at(i - k));
    ans = min(ans, ff());
  }
  cout << ans << endl;
  return 0;
}