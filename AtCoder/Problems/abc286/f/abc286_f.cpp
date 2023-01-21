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

int input() {
  int in;
  cin >> in;
  if (in == -1) exit(0);
  return in;
}

int main() {
  int m = 3;
  cout << m << endl;
  vector<int> a(m);
  rep(i, m) a.at(i) = input();
  vector<int> b(m);
  rep(i, m) b.at(i) = input();
  int ans = 0;
  cout << ans << endl;

  return 0;
}