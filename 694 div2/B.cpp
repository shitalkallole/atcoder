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
#define PI 3.14159265358979323846264338327950L

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
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // freopen("inputf.txt","r",stdin);
    // freopen("outputf.txt","w",stdout);
    
    int t=1;
    cin>>t;
    while(t--){
    	int n;
    	ll x;

    	cin>>n>>x;

    	vector<ll> data(n);
    	for(int i=0;i<n;i++)
    		cin>>data[i];

    	//find depth
    	int minDepth;
    	int minIndex;
    	bool assigned=false;

    	for(int i=0;i<n;i++){
    		int current = 0;
    		ll val = data[i];
    		
    		while(val%x==0){
    			current+=1;
    			val/=x;
    		}
    		if(!assigned){
    			minDepth = current;
    			minIndex = i;
    			assigned=true;

    		}else{
    			if(minDepth>current){
    				minDepth=current;
    				minIndex=i;
    			}
    		}
    	}

    	ll ans=0;
    	for(int i=0;i<n;i++){
    		ans+=data[i];
    		int limit = minDepth;
    		
    		if(i<minIndex)
    			limit = minDepth+1;

    		ll current = data[i];
    		ll copy=1;
    		while(limit!=0){
    			ll div = current/x;
    			ans+=div*x*copy;

   				current = div;
    			copy=copy*x;
    			limit--;
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}













