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

    int n , ans = 0, start, end, prevEndTime = 0;
    cin >> n ;

    pii p[n+2] ;

    for(int i = 0 ; i<n ;i++){
        cin >> p[i].second >> p[i].first ;
    }
    sort(p, p+n) ;

    for(int i = 0 ;i<n ;i++){
        end = p[i].first ;
        start = p[i].second ;

        if(start >= prevEndTime){
            ans++ ;
            prevEndTime = end ;
        }
    }

    cout << ans << endl ;

    return 0 ;
}