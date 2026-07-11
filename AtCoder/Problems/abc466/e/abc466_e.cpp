#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
template <class T, class U>
inline bool chmax(T& a, const U& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n, k;
  cin >> n >> k;
  k = k * 2;
  vector dp(n + 1, vector<ll>(k + 1, 0));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    int ni = i + 1;
    rep(j, k + 1) {
      int p = (j % 2 == 0 ? a : b);
      int q = (j % 2 != 0 ? b : a);
      chmax(dp.at(ni).at(j), dp.at(i).at(j) + p);
      if (j != k) chmax(dp.at(ni).at(j + 1), dp.at(i).at(j) + q);
    }
  }
  cout << *max_element(ALL(dp.back())) << endl;
  return 0;
}