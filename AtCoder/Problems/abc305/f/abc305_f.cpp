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

vector<int> inout(int x) {
  cout << x + 1 << endl;
  string s;
  cin >> s;
  if (s == "OK" || s == "-1") return {};
  vector<int> res;
  rep(i, stoi(s)) {
    int in;
    cin >> in;
    in--;
    res.push_back(in);
  }
  // cerr << "X";
  // for (auto i : res) cerr << i << " ";
  // cerr << endl;
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> next;
  int id;
  cin >> id;
  rep(i, id) {
    int in;
    cin >> in;
    in--;
    next.push_back(in);
  }
  vector<int> par(n, -1);
  par.at(0) = -2;
  int now = 0;
  while (1) {
    int anx = par.at(now);
    bool z = false;
    for (auto nx : next) {
      if (par.at(nx) == -1) {
        anx = nx;
        z = true;
        break;
      }
    }
    if (next.back() == n - 1) anx = next.back();
    if (z) {
      par.at(anx) = now;
    }
    now = anx;
    auto r = inout(now);
    if (r.size() == 0) break;
    next = r;
  }
  return 0;
}