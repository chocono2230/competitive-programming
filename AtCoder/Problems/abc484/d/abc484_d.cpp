#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  ll ans = 1;
  map<int, int> mp;
  mp[a.front()]++;
  rep2(i, 1, n) {
    if (a.at(i) == a.at(i - 1)) {
      mp[a.at(i)]++;
      continue;
    }
    // cerr << i << " " << i - mp[a.at(i)] << endl;
    ans += i - mp[a.at(i)];
    mp[a.at(i)]++;
  }
  cout << ans << endl;
  return 0;
}