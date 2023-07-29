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
  vector<int> b(m);
  rep(i, m) cin >> b.at(i);
  sort(ALL(a));
  sort(ALL(b));
  int ok = 1001001001, ng = 0;
  while (ok - ng > 1) {
    int mid = (ok + ng) / 2;
    int ac = upper_bound(ALL(a), mid) - a.begin();
    int bc = b.end() - lower_bound(ALL(b), mid);
    if (ac >= bc)
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}