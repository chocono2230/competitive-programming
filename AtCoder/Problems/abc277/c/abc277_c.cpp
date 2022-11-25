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
  map<int, vector<int>> gr;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    gr[a].push_back(b);
    gr[b].push_back(a);
  }

  queue<int> q;
  set<int> se;
  q.push(1);
  se.insert(1);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto nx : gr[now]) {
      if (se.find(nx) != se.end()) continue;
      se.insert(nx);
      q.push(nx);
    }
  }
  auto itr = se.rbegin();
  cout << *itr << endl;
  return 0;
}