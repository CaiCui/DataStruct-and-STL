#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<bits/stdc++.h>
using namespace std;
/*
  省选IO并查集:union-set 主要用于判断多个元素是否属于同一个集合，如图的连通分支，或者用于判定图中的环的存在
  find()功能：查找父节点同时更新树结构，由一条链压缩成一棵两层的树，不同的树形成森林
        A    ...      B
     / / \ \       / / \ \
     1 2 3..n      d c s ..3
  复杂度：事实上，路经压缩后的并查集的复杂度是一个很小的常数。
*/
#define MAXN 0x0fffffff
int F[MAXN];//并查集数组
int Find(int x)//节点查找和结构更新，递归写法，容易RE
{
    //方法一、if(F[x]==-1)return x;
    if(F[x]==x)return x;
    return F[x]=Find(F[x]);
}
int Find2(int x)//节点查找和结构更新，非递归写法，不容易RE
{
    int root=x;
    while(root!=F[root])//找到根节点r
    {
        root=F[root];
    }
    int y=x;
    while(y!=root)//路径压缩，变为2层树结构
    {
      int tmp=F[y];
      F[y]=root;//子节点父亲更新为根节点r
      y=tmp;//重复找父节点
    }
    return root;
}
void join(int x, int y)//加入元素
{
    int t1,t2;
    t1=Find(x);
    t2=Find(y);
    if(t1!=t2)
        F[t1]=t2;
}
void init(int n)//初始化并查集
{
    //方法一、memset(F,-1,sizeof(F))
    for(int i=1;i<=n;i++)
    {
        F[i]=i;
    }
}

int main()
{
    int n,v,u;
    cin>>n;
    init(n);
    cin>>v>>u;
    join(u,v);
    return 0;
}
