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

#ifdef CHOCONO_LOCAL
const bool local = true;
#else
const bool local = false;
#endif

const int P_MAX = 5000;

int N, M, K;
vector<pair<int, int>> xy;
vector gr(0, vector<pair<int, int>>());
vector<pair<int, int>> edge;
vector<int> ew;
vector<pair<int, int>> ab;

const clock_t start_time = clock();
double time_limit = 1.95;
double time_from_clock() {
  return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 202306112,
                       w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

double xor_shift() {
  double b = xor128() % LLONG_MAX;
  return b / LLONG_MAX;
}

void input() {
  cin >> N >> M >> K;
  xy.resize(N);
  gr.resize(N);
  edge.resize(M);
  ew.resize(M);
  ab.resize(K);
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
  }
  rep(i, M) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    gr.at(u).push_back({v, i});
    gr.at(v).push_back({u, i});
    ew.at(i) = w;
    edge.at(i) = {u, v};
  }
  rep(i, K) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = {a, b};
  }
}

void calc_score_dfs(vector<bool> &tb, int now) {
  for (auto [nx, cost] : gr.at(now)) {
    if (tb.at(nx)) continue;
    tb.at(nx) = true;
    calc_score_dfs(tb, nx);
  }
}

pair<int, double> calc_score(const vector<int> &p, const vector<bool> &b) {
  vector<bool> tb(N, false);
  tb.front() = true;
  calc_score_dfs(tb, 0);
  vector<bool> kc(K, false);
  rep(i, N) {
    if (!tb.at(i) || p.at(i) == 0) continue;
    auto [x1, y1] = xy.at(i);
    rep(j, K) {
      if (kc.at(j)) continue;
      auto [x, y] = ab.at(j);
      double h = round(hypot(x - x1, y - y1));
      if (h <= p.at(i)) {
        kc.at(j) = true;
      }
    }
  }
  int co = 0;
  rep(i, K) {
    if (kc.at(i)) co++;
  }
  if (co != K) {
    return {co, round(1e6 * (double)(co + 1) / K)};
  }
  double s = 0;
  rep(i, N) { s += (double)p.at(i) * p.at(i); }
  rep(i, M) {
    if (b.at(i)) s += ew.at(i);
  }
  return {co, round(1e6 * (1 + 1e8 / (s + 1e7)))};
}

pair<int, double> output(const vector<int> &p, const vector<bool> &b) {
  rep(i, N) {
    if (i != 0) cout << " ";
    cout << p.at(i);
  }
  cout << endl;
  rep(i, M) {
    if (i != 0) cout << " ";
    if (b.at(i))
      cout << 1;
    else
      cout << 0;
  }
  cout << endl;
  return calc_score(p, b);
}

vector<bool> make_mst() {
  vector<bool> res(M, false);
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      q;
  q.push({0, 0, -1});
  vector<bool> chk(N, false);
  while (!q.empty()) {
    auto [cost, now, bfe] = q.top();
    q.pop();
    if (chk.at(now)) continue;
    chk.at(now) = true;
    if (bfe != -1) {
      res.at(bfe) = true;
    }
    for (auto [nx, cidx] : gr.at(now)) {
      if (chk.at(nx)) continue;
      int cc = ew.at(cidx);
      q.push({cc, nx, cidx});
    }
  }
  return res;
}

void random_shuffle(vector<int> &p) {
  rrep2(i, 1, p.size()) {
    int z = xor128() % (i + 1);
    swap(p.at(i), p.at(z));
  }
}

bool remove_edge_dfs(vector<vector<pair<int, int>>> &mgr, const vector<int> &p,
                     vector<int> &remove, int now, int bf) {
  bool res = false;
  if (p.at(now) != 0) res = true;
  for (auto [nx, eidx] : mgr.at(now)) {
    if (nx == bf) continue;
    auto r = remove_edge_dfs(mgr, p, remove, nx, now);
    if (!r) {
      remove.push_back(eidx);
    }
    res |= r;
  }
  return res;
}

vector<bool> remove_edge(const vector<int> &p, const vector<bool> &b) {
  vector mgr(N, vector<pair<int, int>>());
  rep(i, b.size()) {
    if (!b.at(i)) continue;
    auto [u, v] = edge.at(i);
    mgr.at(u).push_back({v, i});
    mgr.at(v).push_back({u, i});
  }
  vector<int> remove;
  remove_edge_dfs(mgr, p, remove, 0, -1);
  vector<bool> res(M, false);
  for (auto idx : remove) {
    res.at(idx) = true;
  }
  return res;
}

int main() {
  input();
  auto base = make_mst();
  vector<int> ans_p;
  vector<bool> ans_b;
  double mxs = 0;
  int dbg_loop = 0;

  while (time_from_clock() < time_limit) {
    dbg_loop++;
    vector<int> p(N, 0);
    vector<int> uk(K);
    rep(i, K) uk.at(i) = i;
    random_shuffle(uk);
    for (auto ki : uk) {
      auto [x1, y1] = ab.at(ki);
      double mn = 1e18;
      int mni = 0;
      rep(i, N) {
        auto [x, y] = xy.at(i);
        double d = hypot(x - x1, y - y1);
        if (p.at(i) >= d) {
          mni = -1;
          break;
        }
        if (d >= P_MAX) continue;
        if (d - p.at(i) < mn) {
          mn = d - p.at(i);
          mni = i;
        }
      }
      if (mni == -1) continue;
      auto [x, y] = xy.at(mni);
      double d = hypot(x - x1, y - y1);
      p.at(mni) = ceil(d);
    }

    auto b = base;
    int dbg_remove_co = 0;
    auto bb = remove_edge(p, b);
    rep(i, M) {
      if (bb.at(i)) {
        dbg_remove_co++;
        b.at(i) = false;
      }
    }
    auto r = calc_score(p, b);
    if (r.second > mxs) {
      mxs = r.second;
      swap(ans_b, b);
      swap(ans_p, p);
    }
  }
  auto r = output(ans_p, ans_b);

  if (local) {
    ll es = 0, ps = 0;
    rep(i, ans_b.size()) {
      if (ans_b.at(i)) {
        es += ew.at(i);
      }
    }
    rep(i, ans_p.size()) { ps += (ll)ans_p.at(i) * ans_p.at(i); }
    cerr << r.first << " " << r.second << " " << dbg_loop << " "
         << time_from_clock() << endl;
    cerr << es << " " << ps << " " << es - ps << endl;
    cerr << (ll)round(r.second) << endl;
  }
  return 0;
}
