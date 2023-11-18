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
  vector<int> co(n, 0);
  set<pair<int, int>> se;
  rep(i, n) se.insert({0, -i});
  rep(i, m) {
    int in;
    cin >> in;
    in--;
    se.erase({co.at(in), -in});
    co.at(in)++;
    se.insert({co.at(in), -in});
    cout << se.rbegin()->second * -1 + 1 << endl;
  }
  return 0;
}