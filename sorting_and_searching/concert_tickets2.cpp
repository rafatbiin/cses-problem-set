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
int a[N], b[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, temp ;
    multiset<int>s;
    cin >> n >> m ;

    for(int i = 0 ;i<n ;i++){
        cin >> temp ;
        s.insert(temp);
    }
    for(int i = 0 ;i<m ; i++)cin >> a[i] ;
    for(int i = 0 ;i<m ;i++){
        auto it = s.upper_bound(a[i]) ;
        it-- ;
        cout <<*it << endl ;
        s.erase(9) ;
    }

    return 0 ;
}