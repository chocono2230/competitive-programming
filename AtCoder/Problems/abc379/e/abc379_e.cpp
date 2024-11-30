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
  string s;
  cin >> s;
  vector<ll> v(n, 0);
  ll now = 0;
  rep(i, n) {
    now += (ll)(s.at(i) - '0') * (i + 1);
    v.at(i) = now;
  }
  now = 0;
  string ans;
  rrep(i, n) {
    now += v.at(i);
    int p = now % 10;
    ans.push_back(p + '0');
    now /= 10;
  }
  while (now != 0) {
    int p = now % 10;
    ans.push_back(p + '0');
    now /= 10;
  }
  reverse(ALL(ans));
  cout << ans << endl;
  return 0;
}