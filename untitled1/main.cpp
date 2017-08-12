#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<iostream>
using namespace std;
#define MAXD 1000 + 10
#define INF 10000
char str[MAXD];
int dp[MAXD][MAXD];
int dfs(int start,int last){
    if(dp[start][last] != -1)
        return dp[start][last];
    if(start == last)
        return dp[start][last] = 0;
    if(str[start] == str[last]){
        if(start + 1 == last)
            return dp[start][last] = 0;
        else
            return dp[start][last] = dfs(start + 1 , last - 1);
    }
    dp[start][last] = INF;
    if(last - 1 >= start)
    dp[start][last] = min(dp[start][last],dfs(start,last - 1) + 1);
    if(start + 1 <= last)
    dp[start][last] = min(dp[start][last],dfs(start + 1, last) + 1);
    if(start + 1 <= last - 1)
    dp[start][last] = min(dp[start][last],dfs(start + 1,last - 1) + 1);
    return dp[start][last];
}
int main(){
    int T;
    scanf("%d",&T);
    for(int Case = 1; Case <= T; Case ++){
        scanf("%s",str);
        memset(dp,-1,sizeof(dp));
        int ans = dfs(0,strlen(str) - 1);
        printf("Case %d: %d\n",Case,ans);
    }
    return 0;
}
