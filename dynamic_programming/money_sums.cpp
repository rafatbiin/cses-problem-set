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
int a[105], dp[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0 ;
    cin >>n ;

    for(int i = 1 ;i<=n ; i++){
        cin >>a[i] ;
        sum+=a[i] ;
    }

    dp[0] = 1 ;

    for(int i = 1 ;i<=n ; i++){
        for(int j = sum-a[i] ; j>=0 ; j--){
            dp[j+a[i]]|=dp[j] ;
        }
    }

    vector<int>ans ;
    int count = 0 ;

    for(int i = 1 ; i<=sum ; i++){
        if(dp[i]){
            count++;
            ans.pb(i) ;
        }
    }
    
    cout << count << endl;
    for(int i = 0 ; i<ans.size() ; i++){
        cout << ans[i] << ' ' ;
    }



    return 0 ;
}