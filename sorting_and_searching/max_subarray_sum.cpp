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
ll a[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ; 
    ll max_so_far , curr_max ;
    cin >> n ;
    for(int i = 0 ;i<n ;i++)cin>>a[i] ;

    max_so_far = a[0] ;
    curr_max = a[0] ;

    for(int i = 1 ;i<n ;i++){
        curr_max = max(curr_max+a[i], a[i]) ;
        max_so_far = max(max_so_far, curr_max) ;
    }

    cout << max_so_far << endl ;

    return 0 ;
}