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
  vector a(n, vector<int>());
  rep(i, n) {
    int co;
    cin >> co;
    rep(j, co) {
      int in;
      cin >> in;
      a.at(i).push_back(in);
    }
  }
  int x;
  cin >> x;
  int mn = 1000;
  vector<int> ans;
  rep(i, n) {
    auto itr = find(ALL(a.at(i)), x);
    if (itr == a.at(i).end()) continue;
    if (a.at(i).size() > mn) continue;
    if (a.at(i).size() < mn) {
      mn = a.at(i).size();
      ans.clear();
    }
    ans.push_back(i);
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}