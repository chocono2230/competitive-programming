#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

ll calcNumOfCombination(ll n, ll r) {
  ll num = 1;
  for (ll i = 1; i <= r; i++) {
    num = num * (n - i + 1) / i;
  }
  return num;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n, 0);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v.at(a)++;
    v.at(b)++;
  }
  vector<ll> ans(n, 0);
  rep(i, n) {
    int co = n - v.at(i) - 1;
    if (co < 3) continue;
    ans.at(i) = calcNumOfCombination(co, 3);
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}