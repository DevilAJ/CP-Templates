/* Author : Aniket Jaiswal ( IIIT - A ) */

#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(ll i=0;i<n;i++)
#define vfo(i,a,n) for(ll i=a;i<n;i++)
#define revfo(i,n) for(ll i=n-1;i>=0;i--)
#define autofo(i,a) for(auto i : a)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ull unsigned long long
#define umap unordered_map
#define uset unordered_set
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define ppb() pop_back()
#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " = " << x << endl
#define deb2(x, y) cerr << #x << " = " << x << " , " << #y << " = " << y << endl
#else
#define deb(x)
#define deb2(x, y)
#endif
#define pb push_back
#define mkp make_pair
#define F first
#define S second
#define insert insert
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define revsortall(x) sort(all(x),greater<>())
#define PI 3.1415926535897932384626
#define sz(x) (int)(x.size())
#define INF 1e18
#define google(i) cout<<"Case #"<<i<<": ";
#define coutno cout<<"NO\n"
#define coutyes cout<<"YES\n"
#define coutnext cout<<"\n"
#define coutnextl cout<<endl
typedef long double lld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
typedef vector<vpii>  vvpi;
typedef vector<vpl>   vvpl;
typedef set<int>      seti;
typedef set<long long> setl;
typedef uset<int>     useti;
typedef uset<long long> usetl;
typedef vector<char>    vc;
typedef vector<vc>      vvc;

void _print(ll t) {cerr << t << " ";}
void _print(int t) {cerr << t << " ";}
void _print(string t) {cerr << t << " ";}
void _print(char t) {cerr << t << " ";}
void _print(lld t) {cerr << t << " ";}
void _print(double t) {cerr << t << " ";}
void _print(ull t) {cerr << t << " ";}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}\n";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]\n";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vl dijkestra(ll s, ll n, vpl v[]) {vl lev(n + 10, INF); vector<bool> vis(n + 10, false); priority_queue<pl> q; q.push({0, s}); lev[s] = 0; while (!q.empty()) {ll x = q.top().F, y = q.top().S; q.pop(); if (vis[y])continue; vis[y] = true; for (auto i : v[y]) {if (lev[i.F] > i.S - x) {lev[i.F] = i.S - x; q.push({ -lev[i.F], i.F});}}} return lev;}
vvl floyd_warshall(vpl gph[], int n) {vvl dis(n + 2, vl(n + 2, INF)); vfo(i, 1, n + 1) dis[i][i] = 0; vfo(i, 1, n + 1) {autofo(j, gph[i])dis[i][j.F] = min(dis[i][j.F], j.S);} vfo(k, 1, n + 1) {vfo(i, 1, n + 1) {vfo(j, 1, n + 1) {dis[i][j] = min( dis[i][j], dis[i][k] + dis[k][j] );}}} return dis;}
/*--------------------------------------------------------------------------------------------------------------------------*/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

ull mpow(int base, int exp);
void ipgraph(int n, int m);

void dfs(int node);
vi bfs(int n, int s);

const int mod = 1000000007;
const int N = 3e5, M = N;
vi gph[N];
int vis[N];

/*--------------------------------------------------------------------------------------------------------------------------*/

void solve() {
  ll i, j, n, m;
}

/*--------------------------------------------------------------------------------------------------------------------------*/

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("Debug.txt", "w", stderr);
#endif
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  auto start = chrono::high_resolution_clock::now();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast < chrono::microseconds>(stop - start);
  cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
  return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------*/

ull mpow(int base, int exp) {
  base %= mod;
  ull result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int e) {
  autofo(&i, gph)
  i.clear();
  fo(i, n)
  vis[i] = 0;
  int u, v;
  while (e--) {
    cin >> u >> v;
    gph[u].pb(v);
    gph[v].pb(u);
  }
}

void dfs(int node) {
  vis[node] = 1;
  autofo(i, gph[node]) {
    if (vis[i] == 0) {
      dfs(i);
    }
  }
}

vi bfs(int n, int s) {
  vi v(n + 1, 0);
  vi d(n + 1, 0);
  queue<int>q;
  v[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    autofo(cld, gph[x]) {
      if (v[cld] == 0) {
        v[cld] = 1;
        q.push(cld);
        d[cld] = d[x] + 1;
      }
    }
  }
  return d;
}

/*--------------------------------------------------------------------------------------------------------------------------*/
