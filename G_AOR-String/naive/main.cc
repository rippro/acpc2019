#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int n;
char s[111][111];
int idx[111];

int main(){
    scanf("%d",&n);
    if(n > 10) exit(1);
    rep(i,n) scanf("%s",s[i]), idx[i] = i;
    int ans = 0;
    do {
        char S[10010] = {};
        rep(i,n) strcat(S, s[idx[i]]);
        int cnt = 0;
        for(char *c = S; c[2]; ++c) if(c[0]=='A' && c[1]=='O' && c[2] == 'R') ++cnt;
        ans = max(ans, cnt);
    } while(next_permutation(idx, idx+n));
    printf("%d\n",ans);
}
