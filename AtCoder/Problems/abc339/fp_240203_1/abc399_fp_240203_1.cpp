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

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 202402034,
                       w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int main() {
  int n;
  cin >> n;
  vector<ll> mod(30);
  ll base = 1000000000;
  rep(i, mod.size()) { mod.at(i) = base + xor128() % base; }
  vector a(n, vector<ll>(30));
  map<vector<ll>, int> mp;
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, 30) {
      ll now = 0;
      for (auto c : s) {
        now *= 10;
        now += c - '0';
        now %= mod.at(j);
      }
      a.at(i).at(j) = now;
    }
    mp[a.at(i)]++;
  }
  int ans = 0;
  rep(i, n) rep(j, n) {
    vector<ll> nx(30);
    rep(k, 30) {
      nx.at(k) = a.at(i).at(k) * a.at(j).at(k);
      nx.at(k) %= mod.at(k);
    }
    auto itr = mp.find(nx);
    if (itr != mp.end()) ans += itr->second;
  }
  cout << ans << endl;
  return 0;
}