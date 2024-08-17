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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  auto b = a;
  rep(i, n) b.push_back(a.at(i));
  int c = b.size();
  vector<ll> sums(c + 1, 0);
  rep(i, c) sums.at(i + 1) = sums.at(i) + b.at(i);
  map<int, int> mp;
  rep2(i, 1, n + 1) {
    mp[sums.at(i) % m]++;
    // cerr << i << " " << sums.at(i) % m << endl;
  }
  ll ans = 0;
  rep2(i, n + 1, c + 1) {
    int now = sums.at(i - n) % m;
    mp[now]--;
    now = sums.at(i) % m;
    ans += mp[now];
    mp[now]++;
    // cerr << i - n + 1 << " " << now << " " << mp[now] << endl;
  }
  cout << ans << endl;
  // cerr << sums.back() % m << endl;

  return 0;
}