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
  vector vv(3, vector<int>());
  rep(i, n) {
    int t, x;
    cin >> t >> x;
    vv.at(t).push_back(x);
  }
  rep(i, 3) sort(ALL(vv.at(i)), greater<int>());

  ll sum = 0, z = 0;
  priority_queue<int, vector<int>, greater<int>> q;
  rep(i, vv.at(0).size()) {
    sum += vv.at(0).at(i);
    q.push(vv.at(0).at(i));
    if ((int)q.size() > m) {
      z += q.top();
      q.pop();
    }
  }
  ll ans = sum - z;
  // cerr << ans << " " << sum << " " << z << endl;
  int idx = 0;
  for (auto co : vv.at(2)) {
    while (co != 0 && idx != (int)vv.at(1).size()) {
      sum += vv.at(1).at(idx);
      q.push(vv.at(1).at(idx++));
      co--;
    }
    m--;
    if (m == 0) break;
    while ((int)q.size() > m) {
      z += q.top();
      q.pop();
    }
    ans = max(ans, sum - z);
  }
  cout << ans << endl;
  return 0;
}