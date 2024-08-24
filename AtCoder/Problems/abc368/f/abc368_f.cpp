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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  vector<int> grd(200005, 0);
  rep2(i, 2, 200005) {
    set<int> se;
    se.insert(grd.at(1));
    for (int j = 2; j * j <= i; j++) {
      if (i % j != 0) continue;
      int k = i / j;
      se.insert(grd.at(j));
      se.insert(grd.at(k));
    }
    int now = 0;
    while (1) {
      if (se.find(now) == se.end()) break;
      now++;
    }
    grd.at(i) = now;
  }
  // rep(i, 10) { cerr << i << " " << grd.at(i) << endl; }
  int ans = 0;
  rep(i, n) { ans ^= grd.at(a.at(i)); }
  if (ans == 0)
    cout << "Bruno" << endl;
  else
    cout << "Anna" << endl;
  return 0;
}