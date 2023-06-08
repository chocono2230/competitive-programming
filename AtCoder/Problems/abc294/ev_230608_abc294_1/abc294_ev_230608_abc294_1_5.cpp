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
  ll l, n1, n2;
  cin >> l >> n1 >> n2;
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>,
                 greater<tuple<ll, int, int>>>
      q;
  ll s1 = 0, s2 = 0;
  rep(i, n1) {
    int a;
    ll b;
    cin >> a >> b;
    q.push({s1, 1, a});
    s1 += b;
  }
  rep(i, n2) {
    int a;
    ll b;
    cin >> a >> b;
    q.push({s2, 2, a});
    s2 += b;
  }
  q.push({l, 1, 1001001001});

  ll ddx = 0;
  int m1 = 0, m2 = 1001001002;
  ll ans = 0;
  while (!q.empty()) {
    auto [pos, idx, z] = q.top();
    q.pop();
    if (m1 == m2) {
      auto cd = [&](ll pos) -> ll { return max(0LL, pos - ddx); };
      ans += cd(pos);
    }
    if (idx == 1) {
      m1 = z;
    } else {
      m2 = z;
    }
    ddx = pos;
  }
  cout << ans << endl;
  return 0;
}