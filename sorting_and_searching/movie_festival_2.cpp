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
pii a[N] ;
bool visited[N] ;

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k , count = 0;
    cin >> n >> k ;

    for(int i = 0 ;i<n ;i++)cin >>a[i].first >> a[i].second ;
    sort(a, a+n, compare) ;


    multiset<int> s ;
    for(int i = 0 ;i <k ; i++)s.insert(0) ;


    for(int i = 0 ; i<n ;i++){
        if(*s.begin() <=a[i].first){
            auto it = s.upper_bound(a[i].first) ;
            it-- ;
            s.erase(it) ;
            s.insert(a[i].second) ;
            count++ ;
        }
    }
    cout << count << endl ;

    

    return 0 ;
}