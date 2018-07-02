

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll mod = 998244353ll;
ll pow_mod(ll a , ll b){
  ll res = 1;
  for( a %= mod;b; b>>=1,a = a *a %mod){
    if(b&1){
      res = res * a%mod;
    }
  }
  return res;
}

const int N = 1000000 + 5000;
ll fact[N], inv[N];
 ll C(ll n, ll m) {
    return ((fact[n] * inv[m] ) % mod) * inv[n - m] % mod;
}
ll n;
ll po(ll a) {
    return pow_mod(3, a);
}
int main() {
    fact[0] = fact[1] = 1;
    for (ll i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % mod;
    for (ll i = 0; i < N; ++i)
        inv[i] = pow_mod(fact[i], mod - 2);
    cin >> n;
    ll ans = 0;
    ll p = 1;
    for(int i = 1; i <= n; i++) {
        ll x = p*C(n, i)*po(i) % mod * po(n*(n-i)) % mod;
        ans += x;
        ans %= mod;
        ans += x;
        ans %= mod;
        ans = (ans - p * C(n, i) * 3ll % mod * po(n*(n-i)))%mod;
        p *= -1;
    }
    p=1;
    for(int i = 1; i <= n; i++) {
        ans = (ans + p * C(n, i) * 3ll * pow_mod(po(n - i) - 1, n)) % mod;
        p *= -1;
    }
    ans += mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}
