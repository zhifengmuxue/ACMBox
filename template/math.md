1 GCD（最大公约数）

欧几里得算法：

int gcd(int a,int b){
    return b==0 ? a : gcd(b,a%b);
}

非递归版本：

int gcd(int a,int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

时间复杂度：

O(log n)
2 LCM（最小公倍数）

公式：

lcm(a,b) = a / gcd(a,b) * b

模板：

long long lcm(long long a,long long b){
    return a / gcd(a,b) * b;
}

注意：

先除再乘防止溢出
3 模运算模板
快速幂（模）
long long qpow(long long a,long long b,long long mod){
    long long res = 1;
    a %= mod;

    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

复杂度：

O(log n)
模逆元（费马小定理）

适用于：

mod 为素数

公式：

a^-1 ≡ a^(mod-2) mod mod

代码：

long long inv(long long a,long long mod){
    return qpow(a,mod-2,mod);
}
4 素数判断
基础版
bool isPrime(int n){
    if(n < 2) return false;

    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }

    return true;
}

复杂度：

O(√n)
5 素数筛（埃氏筛）

求 1 ~ n 所有素数：

const int MAXN = 1000000;

bool isPrime[MAXN+1];

void sieve(int n){

    for(int i=0;i<=n;i++) isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;

    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
}

复杂度：

O(n log log n)
6 线性筛（更优）
const int MAXN = 1000000;

int prime[MAXN];
bool vis[MAXN];
int cnt = 0;

void linear_sieve(int n){

    for(int i=2;i<=n;i++){

        if(!vis[i]) prime[cnt++] = i;

        for(int j=0;j<cnt && i*prime[j] <= n;j++){

            vis[i*prime[j]] = true;

            if(i % prime[j] == 0) break;
        }
    }
}

复杂度：

O(n)
7 高斯消元（解线性方程组）

求解：

Ax = b

模板：

const int MAXN = 105;

double a[MAXN][MAXN];

int gauss(int n){

    for(int i=1;i<=n;i++){

        int maxRow = i;

        for(int j=i+1;j<=n;j++){
            if(abs(a[j][i]) > abs(a[maxRow][i]))
                maxRow = j;
        }

        for(int j=i;j<=n+1;j++)
            swap(a[i][j],a[maxRow][j]);

        if(a[i][i] == 0) return 0;

        for(int j=i+1;j<=n;j++){

            double f = a[j][i] / a[i][i];

            for(int k=i;k<=n+1;k++)
                a[j][k] -= f * a[i][k];
        }
    }

    for(int i=n;i>=1;i--){

        for(int j=i+1;j<=n;j++)
            a[i][n+1] -= a[i][j] * a[j][n+1];

        a[i][n+1] /= a[i][i];
    }

    return 1;
}

结果：

a[i][n+1] 即 xi