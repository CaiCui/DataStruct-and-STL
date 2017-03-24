#include <bits/stdc++.h>
using namespace std;
/*
    acm链表: stl版
    STL:list，它本身是一个双向链表,可以高效的进行数据插入删除，不支持随机访问!!!!!!头文件#include<list>,list属于std命名域的内容,需要using指令
*/
int comp(int n1,int n2){
    return n1>n2;
}
int comp2(int n)
{
   return n<2;
}
int main()
{
       //list常用方法
      list<int>l;//空表
      list<int>ll(10);//建一个含10个默认值是0的元素的链表
      list<int>lll(10,2);//建一个含10个值均为2的元素的链表
      list<int>l2(l); //建一个l的copy链表
      list<int>l3(ll.begin(),ll.end()); ////含ll一个区域的元素[_First, _Last)

      //正向遍历
      list<int>a1(5,2);
      list<int>::iterator it;
      for(it=a1.begin();it!=a1.end();it++){
        cout<<*it<<"\t";
      }
      cout<<endl;

      //逆向遍历
      //rbegin(): 返回逆向链表的第一个元素,即链表的最后一个数据。rend():返回逆向链表的最后一个元素的下一个位置,即链表的第一个数据再往前的位置。
      list<int>::reverse_iterator it1;
      for(it1 = a1.rbegin();it1!=a1.rend();it1++){
         cout << *it1 << "\t";
      }
      cout << endl;

      //a1直接复制给l
      l=a1;

      //赋值
      //c.assign(n,num)     将n个num拷贝赋值给链表c。
      //c.assign(beg,end)   将[beg,end)区间的元素拷贝赋值给链表c。
      a1.assign(6,2);
      int test[4]{1,2,3,4};
      a1.assign(test,test+4);

      //front()返回第一个元素，back()返回最后一个元素,
      //size()返回元素个数
      //empty()判断是否为空
      //max_size()返回链表可容纳的最大元素数量
      //clear()清除链表中所有的元素
      l.front();
      l.back();
      l.size();
      l.clear();
      l.max_size();
      if(!l.empty())
         cout<<"bu kong"<<endl;
       else
         cout<<"kong"<<endl;
      /*
      c.insert(pos,num)        在pos位置插入元素num。
      c.insert(pos,n,num)      在pos位置插入n个元素num。
      c.insert(pos,beg,end)    在pos位置插入区间为[beg,end)的元素。
      c.erase(pos)　　　　     删除pos位置的元素,不可随机访问
      c.erase(c.begin(),c.end()) 删除区间内的元素
      */
      l.insert(l.begin(),3);
      l.insert(++l.begin(),3,6);
      l.insert(++l.begin(),test,test+2);
      list<int>::iterator itl;
      for(itl=l.begin();itl!=l.end();itl++){
        cout<<*itl<<"\t";
      }
      cout<<endl;

      l.erase(l.begin());//l.erase(0); l.erase(l.begin()+1) 均不对，因为不支持随机访问
      l.erase(l.begin(),++l.begin());
      /*
      c.push_back(num)   在末尾增加一个元素。
      c.pop_back()       删除末尾的元素。
      c.push_front(num)  在开始位置增加一个元素。
      c.pop_front()      删除第一个元素。
      */
      l.push_back(23);
      l.pop_back();
      l.push_front(14);
      l.pop_front();

      /*
      resize(n)      从新定义链表的长度,超出原始长度部分用0代替,小于原始部分删除。
      resize(n,num)  从新定义链表的长度,超出原始长度部分用num代替。
      */
      l.resize(100);
      l.resize(15,4);

      /*
      c1.swap(c2);      将c1和c2交换。
      swap(c1,c2);      同上。
      */
      l.swap(a1);

      /*
      c1.merge(c2)      合并2个有序的链表并使之有序,从新放到c1里,释放c2。
      c1.merge(c2,comp) 合并2个有序的链表并使之按照自定义规则排序之后从新放到c1中,释放c2。
      */
      l.merge(a1);
      l.merge(a1,comp);

      //c1.splice(c1.beg,c2)      将c2连接在c1的beg位置,释放c2
      //c1.splice(c1.beg,c2,c2.beg)   将c2的beg位置的元素连接到c1的beg位置，并且在c2中施放掉beg位置的元素
      //c1.splice(c1.beg,c2,c2.beg,c2.end)   将c2的[beg,end)位置的元素连接到c1的beg位置并且释放c2的[beg,end)位置的元素
      l.splice(l.begin(),a1);
      l.splice(l.begin(),a1,++a1.begin());
      l.splice(l.begin(),a1,a1.begin(),a1.end());

      //remove(num)        删除链表中匹配num的元素。
      //remove_if(comp)    删除条件满足的元素,参数为自定义的回调函数。
      l.remove(3);
      l.remove_if(comp2);

      //reverse()       反转链表
      //unique()       删除相邻的重复元素
      //c.sort()       将链表排序，默认升序
      //c.sort(comp)       自定义回调函数实现自定义排序
      l.unique();
      l.reverse();
      l.sort();
      l.sort(comp);
      l.sort(greater<int>());//内置模板函数,降序
      l.sort(less<int>());
      return 0;
}
