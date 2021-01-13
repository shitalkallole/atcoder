//2*10^9
//9*10^18
// __int128_t 
#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int

const ll M=1e9+7;

//to handle when remainder is -neg we add + M
//but when rem is +pos that time also we add so use %M
//so it will work for both
ll mod(ll n){
    return (n%M + M)%M; 
}
ll modAdd(ll a, ll b){
    return mod(mod(a)+mod(b));
}
ll modMul(ll a, ll b){
    return mod(mod(a)*mod(b));
}
ll modMinus(ll a, ll b){
    return mod(mod(a)-mod(b));
}
ll modpow(ll x, ll n) 
{ 
    if (n == 0) 
        return 1%M;
    if (n == 1)
        return x%M; 
    ll u = modpow(x,n/2); 
    u = modMul(u,u); 
    if (n%2) 
        u = modMul(u,x); 
    return u; 
}



ll mod1(ll n, ll mod){
    return (n%mod + mod)%mod; 
}
ll modMul1(ll a, ll b, ll mod){
    return mod1(mod1(a,mod)*mod1(b,mod),mod);
}
ll modpow1(ll x, ll n, ll mod) 
{ 
    if (n == 0) 
        return 1%mod;
    if (n == 1)
        return x%mod; 
    ll u = modpow1(x,n/2,mod); 
    u = modMul1(u,u,mod); 
    if (n%2) 
        u = modMul1(u,x,mod); 
    return u; 
}

ll gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
bool isPrime(ll n){
    int end = sqrt(n);
    for(int i=2;i<=end;i++)
        if(n%i==0)
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    
    int t=1;
    //cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        ll result = modpow1(10,n,m*m);
        cout<<(result/m)<<endl;
    }
    return 0;
}

















