#include<bits/stdc++.h>
using namespace std;
/*
  省选OI数据结构之队列: STL队列(单向，双端，优先)实例
  队列:F-I-F-O，尾进头出
*/
//自定义的优先队列的比较函数
struct cmp1{
    bool operator()(int &a,int &b){
        return a>b;//最小值优先
  }
};
struct cmp2{
    bool operator()(int &a,int &b){
        return a<b;//最大值优先
    }
};
//定义使用优先队列的结构体
struct number1{
   int x;
   bool operator <(const number1 &a)const
   {
       return x>a.x;//最小优先
   }
};
struct number2{
   int x;
   bool operator <(const number2 &a)const
   {
       return x<a.x;//最大的优先
   }
};
struct node1{
  friend bool operator <(node1 n1,node1 n2)//不可重载>
  {
      return n1.priority< n2.priority; //最大的优先
  }
  int priority;
  int value;
};
struct node2{
  friend bool operator <(node2 n1,node2 n2)//不可重载>
  {
      return n1.priority> n2.priority;//小者优先
  }
  int priority;
  int value;
};

int main()
{
    //STL-Queue，单向，无iterator对象，所以不可用迭代器遍历
    //构造函数
    queue<int>Qd;
    queue<int>Qd2(Qd);
    int fr,ba;
    //常用操作
    Qd.push(1);
    Qd.push(2);
    Qd.push(3);
    Qd.push(4);
    fr=Qd.front();//队头
    ba=Qd.back();//队尾
    printf("%d %d\n",fr,ba);
    Qd.pop();//出队
    fr=Qd.front();//队头
    ba=Qd.back();//队尾
    printf("%d %d\n",fr,ba);
    if(!Qd.empty())
        {
            printf("Not Empty\nSize: %d\n",Qd.size());
        }
    //遍历
    while(!Qd.empty())
    {
        printf("%d\n",Qd.front());
        Qd.pop();
    }

    //STL-Dequeue，双端队列，与vector类似，支持随机访问和快速插入删除， 它在容器中某一位置上的操作所花费的是线性时间。与vector不同的是，deque还支持从开始端插入数据：push_front()。
    //许多操作类似list和vector，详细操作参见“数据结构stl双端队列deque.docx”
    deque<int>c,d;
    d=c;
    c.push_back(2);
    c.push_front(1);
    printf("%d\n",c[1]);
    deque<int>::iterator it;
    for(it=c.begin();it!=c.end();it++)
        printf("%d \t",*it);
    printf("\n");
    c.clear();

    //STL-Priority_Queue，优先队列，即堆，优先队列有两种，一种是最大优先队列；一种是最小优先队列；每次取自队列的第一个元素分别是优先级最大和优先级最小的元素。
    priority_queue<int>pq;//默认为最大优先队列<
    priority_queue<int,vector<int>,greater<int> >qp1;//设置最小优先队列>，参数：元素类型，容器类型，比较函数
    priority_queue<int,vector<int>,less<int> >qp2;//设置最大优先队列<，参数：元素类型，容器类型，比较函数
    pq.push(5);
    pq.push(8);
    pq.push(1);
    pq.push(-10);
    if(!pq.empty())
      printf("%d\n",pq.size());
    printf("%d\n",pq.top());
    pq.pop();
    printf("%d\n",pq.top());

    qp1.push(5);
    qp1.push(8);
    qp1.push(1);
    qp1.push(-10);
    printf("%d\n",qp1.top());

    //自定义的优先队列类型和比较函数实例
    priority_queue<node1>qn;
    node1 b[5];
    b[0].priority = 6; b[0].value = 1;
    b[1].priority = 9; b[1].value = 5;
    b[2].priority = 2; b[2].value = 3;
    b[3].priority = 8; b[3].value = 2;
    b[4].priority = 1; b[4].value = 4;
    for(int i=0;i<5;i++)
        qn.push(b[i]);
    for(int i = 0; i < 5; i++)
    {
        cout<<qn.top().priority<<'\t'<<qn.top().value<<endl;
        qn.pop();
    }

    priority_queue<int,vector<int>,cmp1>qp3;//自定义最小优先队列比较函数
    priority_queue<int,vector<int>,cmp2>qp4;//自定义最大优先队列比较函数
    priority_queue<number1>numq1;
    priority_queue<number2>numq2;
    number1 num1[]{-10,10,-100,66};
    number2 num2[]{-10,10,-100,66};
    numq1.push(num1[0]);
    numq1.push(num1[1]);
    numq1.push(num1[2]);
    numq1.push(num1[3]);
    printf("%d\n",numq1.top());
    numq2.push(num2[0]);
    numq2.push(num2[1]);
    numq2.push(num2[2]);
    numq2.push(num2[3]);
    printf("%d\n",numq2.top());
    return 0;
}
