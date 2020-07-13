#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 1111111
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int a[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n , prev_num = 0, curr_num = 0;
    ll ans = 0 ;
    cin >> n ;

    while(n--){
        cin >> curr_num ;
        if(curr_num < prev_num){
            ans+=ll(prev_num - curr_num) ;
            curr_num = prev_num ;
        }
        prev_num = curr_num ;
    }
    cout << ans << endl ;

    return 0 ;
}