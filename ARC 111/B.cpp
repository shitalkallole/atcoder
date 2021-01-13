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


int dfs(int start,vector<vector<int>> &graph,vector<bool> &visited,int &edges){
    visited[start]=true;
    int ans=0;

    for(int i=0;i<graph[start].size();i++){
        edges+=1;
        if(!visited[graph[start][i]]){
            ans+=dfs(graph[start][i],graph,visited,edges);
        }
    }

    return 1+ans;
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
        int n;
        cin>>n;

        int limit=400000+5;
        vector<vector<int>> graph(limit);
        int a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(limit,false);


        int edges=0;
        int ans=0;
        for(int i=0;i<limit;i++){
            if(!visited[i] && graph[i].size()!=0){
                edges=0;
                int nodes = dfs(i,graph,visited,edges);
                if(edges==((nodes-1)*2))
                    ans+=nodes-1;
                else
                    ans+=nodes;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}

