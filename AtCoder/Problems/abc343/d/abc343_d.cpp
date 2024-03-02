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
  int n, t;
  cin >> n >> t;
  map<ll, int> mp;
  mp[0] = n;
  vector<ll> p(n, 0);
  while (t--) {
    int a, b;
    cin >> a >> b;
    a--;
    mp[p.at(a)]--;
    if (mp[p.at(a)] == 0) mp.erase(p.at(a));
    p.at(a) += b;
    mp[p.at(a)]++;
    cout << mp.size() << endl;
  }
  return 0;
}