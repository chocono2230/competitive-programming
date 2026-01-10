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
  vector<pair<int, int>> v;
  rep(i, n) {
    int in;
    cin >> in;
    v.push_back({in, i + 1});
  }
  sort(ALL(v));
  rep(i, 3) {
    if (i != 0) cout << " ";
    cout << v.at(i).second;
  }
  cout << endl;
  return 0;
}