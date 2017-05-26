#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
/*
    OI省选之Hash
    poj 3349: 数字Hash,基础Hash表的建立，判断两个圆形数列是否相同
    题目大意：每个雪花都有六个分支，用六个整数代表，这六个整数是从任意一个分支开始，朝顺时针或逆时针方向遍历得到的。输入多个雪花，判断是否有形状一致的雪花存在。
    解题思路：数字哈希，要注意的是每种雪花可以由多种数字组合表示。
    比如输入的是1 2 3 4 5 6，
    则2 3 4 5 6 1，3 4  5 6 1 2，……，6 5 4 3 2 1，5 4 3 2 1 6等都是相同形状的。
    因此可以在读入一个雪花的时候把这些情况全部放入哈希表中，如果某次插入的时候发生冲突，则说明存在重复的雪花，并且后面的不需要再处理。
    Hash结构如下
    head:[  hashValue1 ,hashValue2 ... hashValueN ]   其中head[hashValue]的值对应该hashValue在edge[]数组中的ip头指针
                |
           [edge[ip1]] 
                |               
           [edge[ip2]]
                |
                .
                .
                .
           [edge[ipN]]                 
*/

typedef long long LL;
const int maxn=1200010;
const int mod=1200007;
int head[maxn],ip;
void init()
{
    memset(head,-1,sizeof(head));
    ip=0;
}
struct node{ //雪花
   int num[6];
   int next;//下一个具有同样hashValue的地址
}edge[1200010];

int getHash(int *num)
{
    int h=0;
    for(int i=0;i<6;i++)
    {
        h+=num[i];//hash函数,从和来构建
    }
    return h%mod;
}

void insertHash(int *num,int h)//头插法后来元素插在头部，第一次插入的元素指向-1，建立hash表，同样hash值的num[]序列所有num链在一起，head[h]每次保存新插入的元素的ip,edge[ip].next保存上一次插入的元素的ip,最后一个元素的next为-1
{
    for(int i=0;i<6;i++)
        edge[ip].num[i]=num[i];
    edge[ip].next=head[h];
    head[h]=ip; 
    ip++;
}
bool compare(int *a,int *b)
{
    for(int i=0;i<6;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}
bool searchHash(int *num)
{
    int h=getHash(num);
    for(int i=head[h];i!=-1;i=edge[i].next)
    {
        if(compare(num,edge[i].num))
            return true;
    }
    insertHash(num,h);
    return false;
}
int main(){

    int n,num[2][15];
    scanf("%d",&n);
    init();
    int flag=0;
    while(n--)
    {
        for(int i=0;i<6;i++)
        {
            scanf("%d",&num[0][i]);
            num[0][i+6]=num[0][i];//顺序构造123456123456,这样拼接是为了求出所有可能的形状，因为是环123456 234561 345612...
        }
        if(flag)continue;
        for(int i=0;i<6;i++)
        {
            num[1][i+6]=num[1][i]=num[0][5-i];//逆序654321654321 654321 543216 432165
        }
        for(int i=0;i<6;i++)
        {
            if(searchHash(num[0]+i)||searchHash(num[1]+i))//所有可能序列枚举
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag)printf("Twin snowflakes found.\n");
    else printf("No two snowflakes are alike.\n");
    return 0;
}
