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

    ll n, x, y, ans ;
    cin >> n ;

    while(n--){
        cin >> x >>y ;
        if(x>y){
            if(x&1){
                x-- ;
                ans = x*x; 
                cout << ans + y << endl ;
            }else{
                ans = x*x; 
                cout << ans - y +1 << endl ;
            }
        }
        else {
            if(y&1){
                ans = y*y ;
                cout << ans - x + 1 << endl ;
            }
            else {
                y-- ;
                ans = y*y ;
                cout << ans +x <<endl ;
            }
        }
    }

    return 0 ;
}