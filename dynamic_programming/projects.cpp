#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 1111111
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
ll dp[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, pos;
    cin >>n;

  vector<pair<pii,int>> a;
  pair<pii, int> p ;

    for(int i = 0;i<n ;i++){
        cin >> p.first.first >> p.first.second >> p.second ;
        a.pb(p) ;
    }

    sort(a.begin(), a.end()) ;
    dp[n-1] = a[n-1].second;

    for(int i = n-2 ; i>=0 ;i--){
        pos = lower_bound(a.begin()+i+1, a.end(), make_pair(make_pair(a[i].first.second+1, 0), 0)) - a.begin();
        dp[i] = max(dp[i+1], dp[pos]+a[i].second);
        
    }

    // auto it =lower_bound(a.begin()+1, a.end(), make_pair(make_pair(9, 0), 0)) - a.begin();
    // cout <<it << endl;
    cout << dp[0] << endl;

    return 0 ;
}