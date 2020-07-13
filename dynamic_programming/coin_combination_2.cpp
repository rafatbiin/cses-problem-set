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
int dp[N], c[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x ;

    cin >> n >> x ;
    for(int i = 0 ; i<n ;i++){
        cin>>c[i] ;
    }

    dp[0] = 1 ;

    for(int i = 0 ; i<n ;i++){
        for(int j = 1 ;j<=x ; j++){
            if(c[i]<=j){
                dp[j] += dp[j-c[i]] ;
                dp[j]%=M ;
            }
        }
    }

    cout << dp[x] << endl;
    return 0 ;
}