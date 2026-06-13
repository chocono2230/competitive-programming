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
  vector ans(n, vector<int>());
  rep(i, n) {
    int in;
    cin >> in;
    rep(j, in) {
      int k;
      cin >> k;
      k--;
      ans.at(k).push_back(i);
    }
  }
  for (auto v : ans) {
    cout << v.size();
    for (auto p : v) {
      cout << " " << p + 1;
    }
    cout << endl;
  }
  return 0;
}