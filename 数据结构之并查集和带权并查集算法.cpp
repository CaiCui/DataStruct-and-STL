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
  
  省选IO带权并查集：普通并查集加上了节点间的关系参数，涉及节点间关系公式的推算
  解题思想：带权并查集和普通并查集最大的区别在于带权并查集合并的是可以推算关系的点的集合（可以通过集合中的一个已知值推算这个集合中其他元素的值）。  
  而一般并查集合并的意图在于这个元素属于这个集合。带权并查集相当于把“属于”的定义拓展了一下，拓展为有关系的集合。
  通常需要在确立父子并查集树和合并两个子集合时，推算出它们间关系的公式，从而在新的并查集集合中更新每个节点和集合中其他元素的关系，
  基本的代码写法和普通并查集无区别，难点主要是节点的关系值在路径压缩和子集合合并时的更新，需要深入思考探究。
  经典例题：POJ1182 食物链
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
