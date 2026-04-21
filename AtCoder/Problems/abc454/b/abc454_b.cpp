#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> f(n);
  rep(i, n) cin >> f.at(i);
  map<int, int> mp;
  for (auto i : f) mp[i]++;
  if (mp.size() == n)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  if (mp.size() == m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}