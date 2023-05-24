#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long
#define ld long double
#define scn(n) scanf("%d", &n)
#define lscn(n) scanf("%lld", &n)
#define lpri(n) printf("%lld", n)
#define pri(n) printf("%d", n)
#define pln() printf("\n")
#define priln(n) printf("%d\n", n)
#define lpriln(n) printf("%lld\n", n)
#define rep(i, init, n) for (int i = init; i < n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN
#define inf INT_MAX
#define lmax LLONG_MAX
#define lmin LLONG_MIN
#define tc      \
    ll ttt;     \
    cin >> ttt; \
    while (ttt--)
#define VC vector<ll>
#define MP map<ll, ll>
#define lb lower_bound
#define ub upper_bound
#define sort(v) sort(v.begin(), v.end())
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define print cout <<
#define take cin >>
const int N=1e5+10;

vector<int> graph[N];
int height[N];
int depth [N];
vector<vector<int>>cc;
vector<int>curr;
bool visited[N];  // not needed in tree traversal
void dfs(int vertex,int parent=0){
    
    for(auto i:graph[vertex]){
        if(i==parent) continue;
        depth[i]= depth[vertex]+1;
        dfs(i,vertex);
        
    }
    
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    int max_depth=-1;
    int max_d_node;

    for(int i=1;i<=n;i++){
        if(max_depth<depth[i]){
            max_depth=depth[i];
            max_d_node=i;
        } 
        
        depth[i]=0;
        
    }
    dfs(max_d_node);
    max_depth=-1;
    for(int i=1;i<=n;i++){
        if(max_depth<depth[i]){
            max_depth=depth[i];
        } 
        
    }
    cout<<max_depth<<endl;

    
    return 0;
} 

