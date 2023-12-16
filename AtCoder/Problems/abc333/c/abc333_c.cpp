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
  // set<ll> se;
  // rep(i, 10) rep(j, 10) rep(k, 10) {
  //   ll add = 0;
  //   auto ff = [](int x) {
  //     ll res = 1;
  //     rep(i, x - 1) {
  //       res *= 10;
  //       res++;
  //     }
  //     return res;
  //   };
  //   add += ff(i + 1);
  //   add += ff(j + 1);
  //   add += ff(k + 1);
  //   se.insert(add);
  // }
  // for (auto now : se) {
  //   cout << now << endl;
  // }
  priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>,
                 greater<tuple<ll, ll, ll, ll>>>
      q;
  q.push({3, 1, 1, 1});
  ll now = 0;
  ll ans = 0;
  while (1) {
    auto [ss, a, b, c] = q.top();
    q.pop();
    if (now >= ss) continue;
    if (n == 1) {
      ans = ss;
      break;
    }
    n--;
    now = ss;
    c *= 10;
    c++;
    q.push({a + b + c, a, b, c});
    c /= 10;
    b *= 10;
    b++;
    q.push({a + b + c, a, b, c});
    b /= 10;
    a *= 10;
    a++;
    q.push({a + b + c, a, b, c});
    a /= 10;
  }
  cout << ans << endl;
  return 0;
}