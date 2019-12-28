#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define nmax 35
using namespace std;
int a[nmax][nmax];
int x[nmax];
int hashback[nmax][nmax];
int free_x[nmax];
char mp[nmax][nmax];
int ans1,ans2;
int equ,var;
int Gauss(){
    int max_r;
    int col=0,num = 0;
    int k;
    for(int i = 0;i<=var;++i) x[i] = free_x[i] = 0;
    for(k = 0;k < equ && col < var;k++,col++){
        max_r=k;
        for(int i=k+1;i<equ;i++){
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        }
        if(max_r!=k){
            for(int j=k ;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0){
            free_x[num++] = col;
            k--; continue;
        }
        for(int i=k+1;i<equ;i++){
            if(a[i][col]!=0){
                for(int j=col;j<var+1;j++){
                    a[i][j]^=a[k][j];;
                }
            }
        }
    }
    for(int i = k;i<equ;++i){
        if(a[i][col] != 0) return -1;
    }
    if(k < var) return var - k;
    for(int i = var - 1; i >= 0; i--){
        x[i]=a[i][var];
        for(int j = i + 1; j < var; j++){
            x[i] ^= ( a[i][j] && x[j]);
        }
    }
    return 0;
}
//2^k枚举自由元，然后根据自由元对应方程上三角矩形的最小面k行，代入前n-k-1行得到其余变量，然后最小即是答案
void enum_freex(int n,int & ans){
    int num = (1<<(n));
    ans = 1e9+7;
    for(int i = 0;i<num;++i){
        int cnt = 0;
        for(int j = 0;j<n;++j){
            if(i&(1<<j)){
                cnt++;
                x[free_x[j]] = 1;
            }else x[free_x[j]] = 0;
        }
        for(int k = var-n-1;k>=0;--k){// 没有自由元的最下面一行
            int index = 0;
            for(index = k;k<var;index++){// 在当前行找到第一个非0自由元(如果存在的话)
                if(a[k][index]) break;
            }
            x[index] = a[k][var];
            for(int j = index+1;j<var;++j){// 向后依次计算出结果
                if(a[k][j]) x[index] ^= x[j];
            }
            cnt += x[index]; // 如果结果为1，则统计
        }
        ans = min(ans,cnt);
    }
}

