#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
 
using namespace std;
 
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second
 
/* Relevant code begins here */
 
/* Input from file or online */
 
void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}
 
/* Input opener ends */
 
ull mul_mod(ull a,ull b,ull m) {
    ull ah = a>>32, al = a&0xffffffffull;
    ull bh = b>>32, bl = b&0xffffffffull;
    ull rh = ah*bh, rl = al*bl;
    ull x = ah*bl, y = al*bh;
    rh += (x>>32)+(y>>32);
    x <<= 32; y <<= 32;
    rl += x;
    if ( rl < x ) rh++;
    rl += y;
    if ( rl < y ) rh++;
    if ( rh >= m ) rh %= m;
    for ( int i = 0; i < 64; ++i ) {
        rh <<= 1;
        if ( rl&(1ull<<63) ) rh |= 1;
        rl <<= 1;
        if ( rh >= m ) rh -= m;
    }
    return rh;
}
 
ull l[1005];
ull a,b,c;
ull a1,a0;
char s[1005];
int n, start, end;
 
int main() {
    input();
    int t; S(t);
    while ( t-- ) {
        S(n); F(i,0,n) scanf("%llu",&l[i]);
        scanf("%llu %llu %llu",&a,&b,&c);
        scanf("%s",s);
        a1 = 1; a0 = 0;
        start = 0; end = n-1;
        F(i,0,n) {
            if ( s[i] == 'R' ) {
                swap(start,end);
            } else if ( s[i] == 'A' ) {
                a0 = (a0+a) % c;
            } else {
                a1 = mul_mod(a1,b,c);
                a0 = mul_mod(a0,b,c);
            }
            ull ans = ( mul_mod(a1,l[start],c) + a0 ) % c;
            printf("%llu ", ans);
            if ( start < end ) start++;
            else start--;
        } printf("\n");
    }
    return 0;
} 