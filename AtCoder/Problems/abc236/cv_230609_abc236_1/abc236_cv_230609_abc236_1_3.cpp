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
  set<string> se;
  vector<string> ans;
  rep(i, n) {
    string s;
    cin >> s;
    ans.push_back(s);
    se.insert(s);
  }
  rep(i, m) {
    string t;
    cin >> t;
    se.erase(t);
  }
  rep(i, n) {
    if (se.find(ans.at(i)) == se.end())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}