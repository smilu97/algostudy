#include <bits/stdc++.h>
int n,a,b,s;std::vector<int>q[50001];int B(int v) {int r=-1;while(v){++r;v>>=1;}return r;}int f(int u,int p) {int o=0,t=0;for(int v:q[u]){if(v==p)continue;s=f(v,u);t|=o&s;o|=s;}int b=1<<(B(t)+1);while(o&b)b<<=1;return b|(o&~((b<<1)-1));}int main(){scanf("%d",&n);for(int i=1;i<n;i++){scanf("%d%d",&a,&b);q[a].push_back(b);q[b].push_back(a);}printf("%d\n",B(f(1,0)));}