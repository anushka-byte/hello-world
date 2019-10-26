#include <bits/stdc++.h>
#define s second
#define f first
#define mp make_pair
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
 
ll n, h, w, dp[5004];
vector<pair<ll, ll> > lis;
map<pair<ll, ll>, ll> mep;
 
ll solve(ll u)
{
    if(dp[u])
        return dp[u];
    if(u==n-1)
        return dp[u]=1;
    ll maxi=0;
    for(int i=u+1; i<n; i++)
    {
        if(lis[u].s<lis[i].s&&lis[u].f<lis[i].f)
            maxi = max(maxi,solve(i));
    }
    return dp[u] = 1+maxi;
}
 
int main() {
    cin>>n>>w>>h;
    for(int i=1; i<=n; i++)
    {
        ll a, b;
        cin>>a>>b;
        mep[mp(a, b)]=i;
        lis.pb(mp(a, b));
    }
    sort(lis.begin(), lis.end());
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        //cout<<lis[i].f<<" "<<lis[i].s<<" ";
        if(lis[i].f>w&&lis[i].s>h){
            //cout<<i<<"\n";
            ans=max(ans, solve(i));
        }
        else
            dp[i]=-1;
    }
    cout<<ans<<endl;
    while(ans)
    {
        for(int i=0; i<n; i++)
        {
            if(dp[i]==ans){
                //cout<<lis[i].f<<" "<<lis[i].s<<endl;
                cout<<mep[lis[i]]<<" ";
                ans-=1;
                break;
            }
        }
    }
	return 0;
 }
