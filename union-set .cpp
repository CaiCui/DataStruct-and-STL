#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define INF 0x0fffffff
#define MANX INF
//并查集复习 并查集作用：用于判断元素是属于哪个集合的 例如：整幅图一共有几个连通分支，也就是被分成了几个互相独立的块
/**find()功能：边查找，边构造更新树结构，由一条链，最后形成一课两层的树，不同树形成森林，
  *     A    ...      B
  *  / / \ \       / / \ \
  *  1 2 3..n      d c s ..3
  *
  */
int F[MAXN];
int find(int x)
{
    if(F[x]==-1) return x;
    else return F[x]=find(F[x]);//更新路径上的每一个点，使它指向当前新的根，使树的高度降为2
}
int main(void){

  memset(F,-1,sizeof(f));
  int t1,t2,u,v;
  cin>>u>>v;
  t1=find(u);
  t2=find(v);
  if(t1!=t2)
  {
      F[t1]=t2;
  }
  return 0;
}
