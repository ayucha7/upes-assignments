    #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef long long LL;
     
    const int mod = 1000000007;
     
    const int MX = 100000;
    const int N = MX + 5;
     
    int dem[N], cnt[N], a[N], pw[N][32], lt[N];
     
    inline int add(int a, int b) {
        if ((a+=b) >= mod) return a-mod;
        else return a;
    }
     
    inline int sub(int a, int b) {
        if ((a-=b) < 0) return a+mod;
        else return a;
    }
     
    inline int mul(int a, int b) {
        return LL(a) * b % mod;
    }
     
    int power(int a, int b) {
        int r = 1;
        while (b) {
            if (b & 1) r = mul(r, a);
            a = mul(a, a);
            b >>= 1;
        }
        return r;
    }
     
    void solve(int nt) {
        int n;
        scanf("%d", &n);
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", a+i);
            cnt[a[i]]++;
        }
     
        int ans = 1;
     
        for (int i = MX; i >= 1; i--) {
            dem[i] = 0;
            int d = cnt[i];
            for (int j = i+i; j <= MX; j += i) {
                dem[i] -= dem[j];
                if (dem[i] < 0) dem[i] += mod-1;
                d += cnt[j];
            }
            dem[i] += lt[d];
            if (dem[i] >= mod-1) dem[i] -= mod-1;
     
            int b = dem[i];
            int j = 0;
            while (b) {
                if (b & 1) ans = mul(ans, pw[i][j]);
                j++; b >>= 1;
            }
        }
     
        printf("%d\n", ans);
     
        for (int i = 1; i <= n; i++) cnt[a[i]] = 0;
    }
     
    int main() {
        lt[0] = 1;
        for (int i = 1; i <= MX; i++) {
            lt[i] = LL(lt[i-1]) * 2 % (mod-1);
            lt[i-1]--;
            if (lt[i-1] < 0) lt[i-1] += (mod-1);
            pw[i][0] = i;
            for (int j = 1; j <= 30; j++) pw[i][j] = mul(pw[i][j-1], pw[i][j-1]);
        }
        lt[MX]--; if (lt[MX] < 0) lt[MX] += (mod-1);
     
        int ct;
        scanf("%d", &ct);
        for (int i = 1; i <= ct; i++) {
            solve(i);
        }
    } 