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

    int n, x, temp_length ;
    cin >> x >> n ;

    for(int i = 0 ;i<n ;i++)cin >> a[i] ;

    set<int> points ;
    multiset<int> lengths ;
    points.insert(0) ; 
    points.insert(x) ;
    lengths.insert(x);

    for(int i = 0 ; i<n ;i++){
        auto it = points.insert(points.begin(), a[i]) ;
        auto prev = it ;
        auto next = it ;
        prev--, next++ ;
        temp_length = *next - *prev ;

        lengths.erase(lengths.find(temp_length)) ;
        lengths.insert(*it-*prev) ;
        lengths.insert(*next -*it) ;

        cout << *lengths.rbegin() <<" ";
    }
    cout <<endl ;
    return 0 ;
}