#include<bits/stdc++.h>
using namespace std;
/*
  省选OI数据结构：单调队列，具体介绍位于“数据结构之单调队列.docx”中
  单调递增队列：队列中的元素从队头到队尾呈现不减趋势
  单调递减队列：队列中的元素从队头到队尾呈现不增趋势
  单调队列，只能在队尾添加元素，但是可以在队首队头进行删除元素
  例如这样一组数（1，3，2，1，5，6），进入单调不减队列的过程如下：
  1入队，得到队列（1）；
  3入队，得到队列（1，3）；
  2入队，这时，队尾的的元素3>2，将3从队尾弹出，新的队尾元素1<2，不用弹出，将2入队，得到队列（1，2）；
  1入队，2>1，将2从队尾弹出，得到队列（1，1）；
  5入队，得到队列（1，1，5）；
  6入队，得到队列（1，1，5，6）；
  单调递减同理
*/
/*单调队列模板方法如下
typedef struct MQueue{
    int *q;
    int qsize;
    int f;//首指针
    int r;//尾指针
    MQueue(){}
    MQueue(int n)
    {
     qsize=n;
     q=(int *)malloc(sizeof(int)*n);
     r=f=0;
    }

    void pushU(int val)//单调递增队列
    {
        while( r > f && q[r-1] > val)//弹出大于新元素的队尾元素
        {
            r--;
        }
        q[r++]=val;
    }

    void pushD(int val)//单调减队列
    {
        while( r > f && q[r-1] < val)//弹出小于新元素的队尾元素
        {
            r--;
        }
        q[r++]=val;
    }

    int front()
    {
        if(f<r)
        {
            return q[f];
        }
        return -1;
    }

    void pop_front()
    {
        if(f<r)
            f++;
    }

    bool isempty()
    {
        return f==r;
    }

    void clear(void)
    {
        f = r = 0;
    }
    ~MQueue(){
     free((void *)q);
    }

}_MQueue;
int main()
{
  _MQueue q(6);
    q.pushU(1);
     q.pushU(3);
      q.pushU(2);
       q.pushU(1);
        q.pushU(5);
         q.pushU(6);
     while (!q.isempty())
        {
            cout << q.front() << endl;
            q.pop_front();
        }

    _MQueue p(6);
    p.pushD(8);
     p.pushD(7);
      p.pushD(12);
       p.pushD(5);
        p.pushD(16);
         p.pushD(9);
     while (!p.isempty())
        {
            cout << p.front() << endl;
            p.pop_front();
        }
    return 0;
}
*/
//poj2823经典题目，描述：给定一个数列，从左至右输出每个长度为m的数列段内的最小数和最大数。数列长度：N <=10^6 ，m<=N
struct node{
 int x,y;
}v[1000000];//x表示值，y表示下标
int a[1000],n,m,mx[100000],mn[100000];
void getmin()//单点递增队列
{
    int i,head=1,tail=0; //默认起始位置为1 因为插入是v[++tail]故初始化为0
    for(i=1;i<m;i++)
    {
        while(head<=tail && v[tail].x>=a[i]) tail--;
        v[++tail].x=a[i],v[tail].y=i;// 根据题目 前m-1个先直接进入队列

    }
    for(;i<=n;i++)
    {
        while(head<=tail && v[tail].x>=a[i]) tail--;
        v[++tail].x=a[i],v[tail].y=i;
        while(v[head].y<i-m+1) head++;//要把已经超出范围的从head开始排出,然后每个队首则是目前m个数的最小值
        mn[i-m+1]=v[head].x;

    }
}
void getmax()
{
    int i,h,t;
    h=1;//头
    t=0;//尾
    for(i=1;i<m;i++)//单调递减队列初始化，首先把m-1个数值入队
    {
        while( t>=h && v[t].x<=a[i])t--;
        v[++t].x=a[i],v[t].y=i;
    }
    for(;i<=n;i++)//单调递减队列，计算m到n的结果,此时可以开始着手找每个m区间的最大值了
    {
        while( t>=h && v[t].x<=a[i])t--;
        v[++t].x=a[i],v[t].y=i;
        //处理队列头部的删除，当头部已经不在m大小窗口内，头指针h++
        while(v[h].y<i-m+1)h++;
        mx[i-m+1]=v[h].x;//最大值就是每次单调队列头
    }
}
int main()
{
     int i,j;
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
     getmax();
     getmin();
     for(int i=1;i<=n-m+1;i++)
         if(i==1)printf("%d",mn[i]);
         else printf(" %d",mn[i]);
     printf("\n");

    for(int i=1;i<=n-m+1;i++)
         if(i==1)printf("%d",mx[i]);
         else printf(" %d",mx[i]);
     printf("\n");
     return 0;
}
