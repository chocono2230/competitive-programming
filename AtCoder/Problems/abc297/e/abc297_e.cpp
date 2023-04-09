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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  priority_queue<ll, vector<ll>, greater<ll>> q;
  q.push(0);
  ll ans = -1;
  set<ll> se;
  while (!q.empty()) {
    ll now = q.top();
    q.pop();
    ans++;
    if (ans == k) {
      ans = now;
      break;
    }
    rep(i, n) {
      ll nx = now + a.at(i);
      if (se.find(nx) != se.end()) continue;
      q.push(nx);
      se.insert(nx);
    }
  }
  cout << ans << endl;
  return 0;
}