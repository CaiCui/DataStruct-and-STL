#include<bits/stdc++.h>
using namespace std;
/*
  acm链表操作:单/双链表，循环链表，双向循环链表等，本次以双向链表为例其他链表类似，只是端点处理时可能需要注意下
*/
/*
几种结点定义的写法：
typedef struct node{
   int a;
   struct node *next;
   struct node *pre;
}node_t;

typedef struct node{
   int a;
   node *next;
   node *pre;
}node_t;

struct node{
 int a;
 struct node *next;
 struct node *pre;
};
typedef struct node node_t;

struct node{
 int a;
 node *next;
 node *pre;
};
typedef struct node node_t;
*/
typedef struct node{
   int a;
   struct node *next;
   struct node *pre;
}node_t, *Node;
//建表，带表头，表头不算第一个元素
Node CreateH()
{
    Node L,p,r;
    L=(node_t*)malloc(sizeof(node_t));//表头: L=(Node)malloc(sizeof(node_t)); 数值为-1
    L->next=NULL;
    L->pre=NULL;
    L->a=-1;
    r=L;
    r->next=NULL;
    int x;
    while(scanf("%d",&x)!=EOF)
    {
      p=(Node)malloc(sizeof(node_t));
      p->a=x;
      p->next=NULL;
      p->pre=r;
      r->next=p;
      r=p;
    }
    r->next=NULL;
    return L;
}
//建表，不带表头，第一个元素就是链表头
Node Create()
{
    Node L=NULL,p,r;
    int x;
    while(scanf("%d",&x)!=EOF)
    {
      if(L==NULL)//第一个元素
      {
           p=(Node)malloc(sizeof(node_t));
           p->a=x;
           p->next=NULL;
           p->pre=NULL;
           L=r=p;
           continue;
      }
      p=(Node)malloc(sizeof(node_t));
      p->a=x;
      p->next=NULL;
      p->pre=r;
      r->next=p;
      r=p;
    }
    r->next=NULL;
    return L;
}
//遍历
void ScanX(Node L)
{
  Node p;
  p=L;
  if(p==NULL){printf("NULL\n");return;}
  while(p!=NULL)
  {
      printf("%d\t",p->a);//也可以 printf("%d\t",(*p).a);
      p=p->next;
  }
  printf("\n");
}
//逆向遍历
void ScanY(Node L)
{
  Node p,Last;
  Last=p=L;
  if(p==NULL){printf("NULL\n");return;}
  while(p!=NULL)
  {
      Last=p;
      p=p->next;
  }
  while(Last!=NULL)
  {
       printf("%d\t",(*Last).a);
       Last=Last->pre;
  }
   printf("\n");
}

//查找x
int FindX(Node L,int x)
{
    Node p=L;
    p=p->next;
    while(p!=NULL)
    {
        if(p->a==x)
            return 1;
        p=p->next;
    }
    return -1;
}

//带表头插入，表头不动，在双链表的第i个位置插入值为x的元素（在原来第i个位置前）,i从0开始
Node InsertHX(Node l,int i,int x)
{
    Node L,p,r,tmp;
    L=tmp=l;
    tmp=tmp->next;//第一个元素,下标为0
    int countX=0;
    while(tmp!=NULL)
    {
      if(countX==i)
         break;
      tmp=tmp->next;
      countX++;
    }//如果插入时的位置大于了链表长度，就在尾部插入即可，这里就不实现了
    p=(Node)malloc(sizeof(node_t));
    p->next=tmp;
    p->a=x;
    p->pre=tmp->pre;
    p->pre->next=p;
    tmp->pre=p;
    return L;
}

//不带表头插入，在双链表的第i个位置插入值为x的元素（在原来第i个位置前）,i从0开始
Node InsertX(Node l,int i,int x)
{
    Node L,p,r,tmp;
    L=tmp=l;
    int countX=0;
    while(tmp!=NULL)
    {
      if(countX==i)
         break;
      tmp=tmp->next;
      countX++;
    }//如果插入时的位置大于了链表长度，就在尾部插入即可，这里就不实现了
    p=(Node)malloc(sizeof(node_t));
    p->next=tmp;
    p->a=x;
    p->pre=tmp->pre;
    if(p->pre!=NULL)//p不是第一个元素
      p->pre->next=p;
    else
      L=p;
    tmp->pre=p;
    return L;
}

//带表头删除,i从0开始
void DeleteH(Node &l,int i)
{
    int countX=0;
    Node p,r;
    p=l;
    p=p->next;
    while(p!=NULL)
    {
        if(countX==i)
            break;
        p=p->next;
        countX++;
    }
    if(p==NULL&&i>=countX)
    {
        printf("不存在该元素!\n");
        return;
    }
    p->pre->next=p->next;
    if(p->next!=NULL)//p不是链表尾部
        p->next->pre=p->pre;
    p->next=NULL;
    p->pre=NULL;
    free((void *)p);
}

//不带表头删除,i从0开始
void Delete(Node &l,int i)
{
    int countX=0;
    Node p,r;
    p=l;
    while(p!=NULL)
    {
        if(countX==i)
            break;
        p=p->next;
        countX++;
    }
    if(p==NULL&&i>=countX)
    {
        printf("不存在该元素!\n");
        return;
    }
    if(p->pre==NULL && p->next==NULL)//只有一个节点
    {
        free((void *)p);
        l=NULL;
        return;
    }
    if(p->pre!=NULL)//p不是链表第一个
        p->pre->next=p->next;
    if(p->next!=NULL)//p不是链表尾部
        {
            p->next->pre=p->pre;
            if(p->pre==NULL)//如果是链表头部，更新L
             l=p->next;
        }
    p->next=NULL;
    p->pre=NULL;
    free((void *)p);

}

int main()
{

    node_t *Linklist=NULL;
    Linklist=CreateH();
    ScanX(Linklist);
    ScanY(Linklist);
    if(FindX(Linklist,2)==1)
        printf("ok\n");

    Node LinklistNew=InsertHX(Linklist,0,100);
    ScanX(LinklistNew);
    ScanY(LinklistNew);

    DeleteH(Linklist,1);
    ScanX(Linklist);
    ScanY(Linklist);*/

    Node Linklist2=NULL;
    Linklist2=Create();
    ScanX(Linklist2);
    ScanY(Linklist2);

    Node Linklist2New=InsertX(Linklist2,0,100);
    ScanX(Linklist2New);
    ScanY(Linklist2New);

    Delete(Linklist2,0);
    ScanX(Linklist2);
    ScanY(Linklist2);

    return 0;
}
