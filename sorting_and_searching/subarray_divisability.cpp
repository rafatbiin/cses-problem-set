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

    int n, remainder ;
    ll count = 0LL, curr_sum = 0LL ;
    cin >> n ;
    for(int i = 0 ;i<n ; i++)cin >> a[i] ;

    for(int i = 0 ;i<n ;i++){
        curr_sum+=a[i] ;
        remainder = curr_sum%n ;
        if(remainder<0){
            remainder = (remainder+n)%n ;
        }
        if(remainder == 0)count++ ;
        count+=b[remainder] ;
        b[remainder]++ ;
    }

    cout << count << endl ;

    return 0 ;
}