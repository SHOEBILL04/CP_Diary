#include<bits/stdc++.h>
using namespace std;

#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll gen_random(ll l, ll r)
{
	return uniform_int_distribution<ll>(l, r)(rng);
}
// for real number
// make ll to double and, unifform_int_distribution to uniform_real_distribution<double>

//for string n = 26, and a+=i
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("/home/rakibul/CODE/CP/input.txt", "w", stdout);
	ll n = gen_random(1, 10);
	ll m = gen_random(1, 10);
	n++;
	cout << n << " " << m << endl;

	for(int i = 0; i < n; i++)
	{
		cout << gen_random(1, 20) << " ";
	}
	cout << endl;
//	for(int j = 0; j < m; j++)
//	{
//		cout << gen_random(1, 20) << " ";
//	}
//	cout << endl;
	//for permutation generation
//	vector<int>v;
//	for(int i = 1; i<=n; i++)
//	{
//		v.push_back(i);
//	}
//	shuffle(v.begin(), v.end(), rng);
//	for(int x: v)cout << x << " ";
//	cout << endl;

	//for specific set of characters
//	vector<char>x = {'x', 'y', 'z'};
//	for(int i = 0; i < n; i++) cout << x[gen_random(0, x.size()-1)];
}
