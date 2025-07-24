#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
#define For(start, end) for(int i = (start); i < (end); i++)
#define no "NO"
#define yes "YES"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define len(x) (ll)x.size()
using ull = unsigned long long;
const long long INF = 1000000000000000000ll;
typedef pair<int, int>ii;
typedef vector<int>vi;
typedef vector<pair<ll, ll>>vll;
typedef vector<ll>vl;
typedef vector<ii> vii;
int dx[] = {-1,1, 0, 0, -1,-1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
const unsigned int MOD = 1000000007;
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
//__builtin_popcount(num)
//stringstream ss(s) //can take input as ss >> x;
//ll gcd(ll A, ll B) { return __gcd(A, B); }
//ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

void solve() 
{
	ll n, k; cin >> n >> k;
	priority_queue<ll, vector<ll>, greater<ll>>q;
	ll sum = 0;
	for(int i = 0; i < n; i++)
	{
		ll x; cin >> x;
		q.push(x);
		sum+=x;
	}
	for(int i = 0; i < k; i++)
	{
		ll val1 = q.top();
		q.pop();
		ll val2 = q.top();
		q.pop();
		ll val = (val1+val2+1)/2;
		sum+=val;
		q.push(val1);
		q.push(val2);
		q.push(val);
	}
	cout << sum << endl;
}
 
int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout); 

	ll TC = 1;
//	cin >> TC;
    while (TC--) 
    {
        solve();
    }
}
