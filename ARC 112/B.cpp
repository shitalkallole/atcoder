//2*10^9   -- int
//9*10^18  -- long long int
//10^38    -- __int128_t 

//we also have long double
/*A better way to compare ﬂoating point numbers is to assume that 
two numbers are equal if the difference between them is less than ε, where ε is a small number.(ε=10−9) */

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
#define endl "\n"
#define sp " "
#define PI 3.14159265358979323846264338327950L

const ll dif=1e-9;
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

int getParent(vector<int>&parent,int s){
    if(parent[s]==s)
        return s;
    return getParent(parent,parent[s]);
}

void solve(){
    ll b,c;
    cin>>b>>c;

    ll ans=0;
    if(b==0){
        ll div = c/2;
        ans = div*2;

        if(c%2==0)
            ans-=1;

        ans+=1;
    }
    else{

        if(b>0){
            //b is positive
            //cal left
            ll leftside=0;
            ll div = c/2;
            leftside = div*2;

            if(c%2==0)
                leftside-=1;
            leftside = min(leftside,(b-1)*2+1);

            //cal right
            ll temp=c-1;
            ll rightside=1;

            div = temp/2;
            rightside=rightside+(div*2);
            if(temp!=0 && temp%2==0)
                rightside-=1;

            ans = leftside+rightside+1;
        }else{
            //b is neg
            //cal leftside
            ll leftside=0;
            ll div = c/2;

            leftside=div*2;

            if(c%2==0)
                leftside-=1;

            //cal right
            ll temp=c-1;
            ll rightside=1;

            div = temp/2;
            rightside = rightside+(div*2);
            if(temp!=0 && temp%2==0)
                rightside-=1;

            b=b*(-1);
            rightside = min(rightside,(b-1)*2+1+1);

            ans= leftside+rightside+1;
        }

    }
    cout<<ans<<endl;
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
        solve();
    }
    return 0;
}














