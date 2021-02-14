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
    int h,w;
    cin>>h>>w;

    vector<vector<int>> data(h,vector<int>(w,0));
    char c;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>c;
            data[i][j]=(c=='#'?1:0);
        }
    }
    int ans=0;
    //row-wise

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(data[i][j]==1 && data[i-1][j]==0){
                int k=j;
                ans+=1;
                while(k<w && data[i][k]==1 && data[i-1][k]==0)
                    k++;
                j=k;
            }
        }
    }
     for(int i=h-1;i>=0;i--){
        for(int j=0;j<w;j++){
            if(data[i][j]==1 && data[i+1][j]==0){
                int k=j;
                ans+=1;
                while(k<w && data[i][k]==1 && data[i+1][k]==0)
                    k++;
                j=k;
            }
        }
    }

     for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(data[j][i]==1 && data[j][i-1]==0){
                int k=j;
                ans+=1;
                while(k<h && data[k][i]==1 && data[k][i-1]==0)
                    k++;
                j=k;
            }
        }
    }
    

     for(int i=w-1;i>=0;i--){
        for(int j=0;j<h;j++){
            if(data[j][i]==1 && data[j][i+1]==0){
                int k=j;
                ans+=1;
                while(k<h && data[k][i]==1 && data[k][i+1]==0)
                    k++;
                j=k;
            }
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














