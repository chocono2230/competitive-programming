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
  string s;
  cin >> s;
  vector<int> p;
  rep(i, n * 2) {
    if (s.at(i) == 'A') p.push_back(i);
  }
  ll ans1 = 0, ans2 = 0;
  rep(i, n) {
    int add1 = abs(p.at(i) - i * 2);
    int add2 = abs(p.at(i) - (i * 2 + 1));
    ans1 += add1;
    ans2 += add2;
  }
  cout << min(ans1, ans2) << endl;
  return 0;
}