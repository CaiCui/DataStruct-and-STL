#include<bits/stdc++.h>
using namespace std;
/*
  省选IO数据结构：stl堆
  一般都用优先队列(实质是堆，之前的总结已实现过)，这里使用heap
  头文件：<algorithm>支持

  stl-heap结构简介：
  heap并不属于STL容器组件，它分为 max heap 和min heap，在缺省情况下，max-heap是优先队列（priority queue）的底层实现机制。
  而这个实现机制中的max-heap实际上是以一个vector表现的完全二叉树（complete binary tree）。
  STL在<algorithm.h>中实现了对存储在vector/deque 中的元素进行堆操作的函数，包括make_heap, pop_heap, push_heap, sort_heap，
  对不愿自己写数据结构堆的C++选手来说，这几个算法函数很有用。

  主要有以下四个函数(所有原型的参数比较函数都可有可无)：
  make_heap()
  函数原型是：void make_heap(first_pointer,end_pointer,compare_function);
  一个参数是数组或向量的头指针，第二个向量是尾指针（注意这里是尾后指针或尾后迭代器，而不是最后一个元素的地址）。第三个参数是比较函数的名字。
  在缺省的时候，默认是大顶堆。（注意如果要自定义比较函数话：最大堆用小于函数；最小堆用大于函数）
  作用：把这一段的数组或向量做成一个堆的结构。范围是[first,last)注意不包括last尾后指针或尾后迭代器

  push_heap()
  函数原型是：void push_heap(first_pointer,end_pointer,compare_function);
  作用：push_heap()假设由[first,last-1)是一个有效的堆，然后，再把堆中的新元素加
  进来做成一个堆，并重新调整。
  原理：
  新添加一个元素在末尾，然后重新调整堆序。也就是把元素添加在底层vector的end()处。
  该算法必须是在一个已经满足堆序的条件下，添加元素。该函数接受两个随机迭代器，分别表示first,end,区间范围。
  关键是执行了一个siftup()函数，上溯函数来重新调整堆序。

  pop_heap()
  函数原型是：void pop_heap(first_pointer,end_pointer,compare_function);
  作用：pop_heap()不是真的把最大（最小）的元素从堆中弹出来。而是重新排序堆。它
  把first和last-1交换，然后将[first,last-1)的数据再做成一个堆。
  原理：
  这个算法跟push_heap类似，参数一样。不同的是我们把堆顶元素取出来，放到了数组或者是vector的末尾，用原来末尾元素去替代，
  然后end迭代器减1，执行siftdown()下溯函数来重新调整堆序。
  注意算法执行完毕后，最大的元素并没有被取走，而是放于底层容器的末尾。如果要真正pop掉，则可以使用底部容器（vector）提供的pop_back()函数,或者back()取出最后元素。

  sort_heap()
  函数原型是：void sort_heap(first_pointer,end_pointer,compare_function);
  作用是sort_heap对[first,last)中的序列进行排序。它假设这个序列是有效堆。（当然
  ，经过排序之后就不是一个有效堆了）
  原理：
  既然每次pop_heap可以获得堆中最大的元素，那么我们持续对整个heap做pop_heap操作，每次将操作的范围向前缩减一个元素。
  当整个程序执行完毕后，我们得到一个非降的序列。注意这个排序执行的前提是，在一个堆上执行。

*/
bool cmpMin(int a,int b)
{
    return a>b;
}
int cmpMax(int a,int b)
{
    return a<b;
}
int main()
{
     /*写法一：
     int i;
     int a[15]={29,23,20,22,17,15,26,51,19,12,35,40};//12个元素测试
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;
     //几种写法
     make_heap(a,a+12);//默认最大堆
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     make_heap(&a[0],&a[12]);
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     make_heap(a,a+12,cmpMax);
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     make_heap(&a[0],&a[12],cmpMin);//小顶堆
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     //加入元素8
     a[12]=8;
     //加入后调整
     push_heap(a,a+13,cmpMin);
     for(i=0;i<13;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     //弹出元素8
     pop_heap(a,a+13,cmpMin);
     for(i=0;i<13;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     //排序,比较函数要反过来，和堆建立、插入的比较函数得到的结果相反
     sort_heap(&a[0],&a[13],cmpMax);
     for(i=0;i<13;i++)
        cout<<a[i]<<" ";
     cout<<endl;
     */
     //写法二
     int a[] = {15, 1, 12, 30, 20};
     vector<int>ivec(a,a+5);
     for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();iter++)
        cout<<*iter<<" ";
	 cout<<endl;

     make_heap(ivec.begin(),ivec.end(),greater<int>());//建立最小堆
     for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

     make_heap(ivec.begin(),ivec.end());//建立最大堆
     for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

	 pop_heap(ivec.begin(),ivec.end());//先pop，再在容器中删除
	 int maxE=ivec.back();//获取vector的最后一个元素，即pop出的最大元素
	 int ss=ivec.front();//获取vector的第一个元素
	 cout<<"最大元素: "<<maxE<<endl;
	 ivec.pop_back();//真正pop
	 for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

	 ivec.push_back(99);//先在容器中加入，再push
	 push_heap(ivec.begin(), ivec.end());
	 for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

	 sort_heap(ivec.begin(), ivec.end());
	 for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

     return 0;
}
