// Problem C:--- Professor Dhumketu and the Mysterious Overlaps
#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,m,tr[N],ans[N];
vector<int>t;
vector<array<int,3> >p;
void add(int x,int y=1){
	for(;x<N;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	return x?ask(x&(x-1))+tr[x]:0;
} 
int main(){
	// ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1,l,r;i<=n;i++)
		cin>>l>>r,p.push_back({-l,r,0});
	for(int i=1,c;i<=m;i++){
		cin>>c,t.resize(c+2),t[0]=0,t[c+1]=N;
		for(int j=1;j<=c;j++)
			cin>>t[j];
		for(int j=1;j<=c+1;j++)
			if(t[j-1]<t[j]-1)
				p.push_back({-t[j-1]-1,t[j]-1,i});
	}
	sort(p.begin(),p.end());
	for(auto&i:p)
		if(i[2])
			ans[i[2]]+=ask(i[1]);
		else
			add(i[1]);
	for(int i=1;i<=m;i++)
		cout<<n-ans[i]<<"\n";
}





// -------------------------------------------------------------------------------------------------------

// Solution by winning Team - WeAreLoosers	Accepted 484 ms	22800 KB

#include <bits/stdc++.h>
using namespace std;

#define mod1 1000000007
#define mod2 998244353
#define PI 3.1415926535897932384626433832795
#define ll long long int
#define ull unsigned long long int
#define lld long double
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define mkp make_pair
#define en endl
#define nl cout << en
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define rloop(i, a, b) for (ll i = a; i >= b; i--)

const ll INF = 1e18;
ll dx[] = {-1, 0, +1, 0};
ll dy[] = {0, +1, 0, -1};
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
ll max(ll a, ll b) { return (a > b) ? a : b; }
ll min(ll a, ll b) { return (a < b) ? a : b; }
ll ceil(ll a, ll b) { return (a + b - 1) / b; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll pow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b = b >> 1;
    }
    return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll getBit(ll n, ll ind) { return ((n & (1 << ind)) != 0); }
ll mod_add(ll a, ll b, ll m) { return ((((a % m) + (b % m)) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((((a % m) * (b % m)) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((((a % m) - (b % m)) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m) { return (mod_mul(a % m, mminvprime(b % m, m), m) + m) % m; }
ll fact(ll n)
{
    ll res = 1;
    loop(i, 1, n + 1) { res = (res * 1ll * i) % mod1; }
    return res;
}
ll ncr(ll n, ll r)
{
    ll cnt1 = 1;
    loop(i, 0, r)
    {
        cnt1 *= (n - i);
        cnt1 /= (i + 1);
    }
    return cnt1;
}
ll nCr(ll n, ll k) { return (mod_mul(fact(n), expo(fact(k), mod1 - 2, mod1), mod1) * expo(fact(n - k), mod1 - 2, mod1)) % mod1; }
vector<ll> sieve(ll n)
{
    vector<ll> nums(n + 1);
    vector<ll> vect;
    loop(i, 2, n + 1)
    {
        if (nums[i] == 0)
        {
            vect.pb(i);
            for (ll j = 2 * i; j <= n; j += i)
            {
                nums[j] = 1;
            }
        }
    }
    return vect;
}
bool isPrime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    loop(i, 2, sqrt(n) + 1)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
void precision(int a) { cout << setprecision(a) << fixed; }
void input(vector<ll> &nums)
{
    for (auto &x : nums)
        cin >> x;
}
void printv(vector<ll> &nums)
{
    for (auto x : nums)
        cout << x << " ";
    nl;
}
bool cmp(vector<ll> &a, vector<ll> &b) { return a < b; }
ll const N = 1000010;
int n, m, tr[N], ans[N];
vector<int> t;
vector<array<int, 3>> p;
void add(int x, int y = 1)
{
    for (; x < N; x += x & -x)
    {
        tr[x] += y;
    }
}
int ask(int x)
{
    return x ? ask(x & (x - 1)) + tr[x] : 0;
}

void sol()
{
    cin >> n >> m;
    loop(i, 1, n + 1)
    {
        int l, r;
        cin >> l >> r;
        p.push_back({-l, r, 0});
    }
    loop(i, 1, m + 1)
    {
        ll c;
        cin >> c;
        t.resize(c + 2);
        t[0] = 0, t[c + 1] = N;
        loop(j, 1, c + 1)
        {
            cin >> t[j];
        }
        loop(j, 1, c + 2)
        {
            if (t[j - 1] < t[j] - 1)
            {
                p.push_back({-t[j - 1] - 1, t[j] - 1, i});
            }
        }
    }
    sort(p.begin(), p.end());
    for (auto &i : p)
    {
        if (i[2])
        {
            ans[i[2]] += ask(i[1]);
        }
        else
        {
            add(i[1]);
        }
    }
    loop(i, 1, m + 1)
    {
        cout << n - ans[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tc = 1;
    // cin >> tc;
    precision(0);

    loop(i, 0, tc)
    {
        sol();
    }
}

