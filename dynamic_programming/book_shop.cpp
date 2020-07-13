#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 101111
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int dp[N],h[N], s[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x ;
    cin >> n >> x ;

    for(int i = 1 ; i<=n ; i++)cin >> h[i] ;
    for(int i =1 ; i<=n ; i++)cin >> s[i] ;

    for(int i = 1; i<=n ;i++){
        for(int j = x ; j>=1 ; j--){
            if(j>=h[i]){
                dp[j] = max(dp[j], dp[j-h[i]] + s[i]) ;
            }
        }
    }

    cout << dp[x] << endl;



    return 0 ;
}