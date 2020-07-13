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
int a[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, a, b, mx, mn ;
    cin >> t ;
    while(t--){
        cin >> a >> b ;
        mx = max(a, b) ;
        mn = min(a,b) ;

        if(mn*2 < mx)cout <<"NO"<<endl ;
        else if((mx+mn)%3 ==0)cout <<"YES"<<endl ;
        else cout <<"NO"<<endl;

    }

    return 0 ;
}