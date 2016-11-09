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
// set/multiset 一些常见用法
/**set集合容器实现了红黑树（Red-Black Tree）的平衡二叉检索树。插入元素时就进行了元素自动的调整，set中数元素的值不能直接被改变
  *以确保每个子树根节点的键值大于左子树所有节点的键值，而小于右子树所有节点的键值
  *另外，还得确保根节点的左子树的高度与右子树的高度相等，这样，二叉树的高度最小，从而检索速度最快。
  *要注意的是，它不会重复插入相同键值的元素，而采取忽略处理。set查找速度较快，高于vector、deque、和list的容器
  *构造set集合的主要目的是为了快速检索，也可以统计非重复的元素数量，即实现单词统计。
  *mutilset 和 set 区别：前者允许插入重复元素，并且默认也是升序存储
  常用方法
  *begin()   返回set容器的第一个元素
  *end()  返回set容器的最后一个元素
  *clear()  删除set容器中的所有元素
  *empty()  判断set容器是否为空
  *max_size()  返回set容器可能包含的元素最大个数
  *size()   返回当前set容器中的元素个数
  *count() 该函数也判断某一键值是否在set中出现过，0或1
  *erase(iterator), 删除定位器iterator指向的值 第一种删除
  *erase(first, second)  删除定位器first和second之间的值 第二种删除
  *erase(key_value)   删除键值key_value的值  第三种删除
  *find() 返回给定值的定位器，如果没找到则返回end()
  *insert(key_value)  将key_value插入到set中，返回值是pair<set<int>::iterator,bool>，bool标志着插入是否成功，而iterator代表插入的位置，若key_value已经在set中，则iterator表示的key_value在set中的位置。
  *insert(first, second) 将定位器first到second之间的元素插入到set中，返回值是void
  *const_iterator lower_bound(key_value)  返回第一个大于等于key_value的定位器
  *const_iterator upper_bound(key_value)  返回最后一个大于等于key_value的定位器
  *equal_range()  ，返回一对定位器，分别表示第一个大于或等于给定关键值的元素和 第一个大于给定关键值的元素，这个返回值是一个pair类型，如果这一对定位器中哪个返回失败，就会等于end()的值。
  *void swap(set& s):交换集合元素
  *void swap(multiset& s):交换多集合元素
  **/
struct mycomp{
  //普通的自定义比较函数，重载“（）”操作符
  bool operator() (const int &a,const int &b) const //最后一个const可有可无
  {
     return a>b;
  }
};
struct Info //结构体重载比较写在结构体本身内部
{
    string name;
    double score;
    bool operator < (const Info &a) const // 重载“<”操作符，自定义排序规则
    {
        //按score由大到小排序。如果要由小到大排序，使用“>”即可。
        return a.score < score;
    }
};
int main(void){
    //常见用法举例,只对set举例，multiset同set
    //初始化:
    int a[] = {1,2,3};
    set<int>s;
    set<int,mycomp>s1;
    set<int>s11(a,a+3);
    set<int,mycomp>s12(a,a+3);
    set<int>p(s); //复制
    set<int>pp(s.begin(),s.end());
    multiset<int>ss;
    multiset<int>ss1(a,a+3);
    //插入,默认是从小到大插入，可以自己定义比较函数。
    s.insert(5); //第一次插入5，可以插入
    s.insert(1);
    s.insert(6);
    s.insert(3);
    s.insert(5); //第二次插入5，重复元素，不会插入
    s.insert(a,a+3);
    //s.insert (it,25); 指定it位置处插入元素
    ss.insert(5); //第一次插入5，可以插入
    ss.insert(1);
    ss.insert(6);
    ss.insert(3);
    ss.insert(5); //第二次插入5，重复元素，会插入
    set<int>::iterator it;//定义前向迭代器
    //中序遍历元素
    multiset<int>::iterator itt;//定义前向迭代器
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
    set<int>::reverse_iterator rit;//定义反向迭代器
    for(rit=s.rbegin();rit!=s.rend();rit++)
    {
        cout<<*rit<<endl;
    }
    //验证insert返回值
    pair<set<int>::iterator,bool> prr;
	prr = s.insert(5);
	if(prr.second)
	{
		cout<<*prr.first<<endl;
	}

    //删除元素
    //第一种删除
	s.erase(s.begin());
	//第二种删除 指定区间删除
	set<int>::iterator first;
	set<int>::iterator second;
	first = s.begin();
	second = s.begin();
	second++;
	second++;
	s.erase(first,second);
	//或者第二种删除这样写
	it=s.begin();
    for(int i=0;i<2;i++)
      s.erase(it++);//删除前两个元素.it可以通过++迭代运算，但是不能直接做加法来增加或减少
    //第三种删除， 删除键值为6的元素
    s.erase(6);
    s.clear();//清空
    s.erase(s.begin(),s.end());//清空

    //查找
     it = s.find(6); //查找键值为6的元素
     if(it != s.end())
        cout << *it << endl;
     else
        cout << "not find it" << endl;

    //自定义比较元素,从大到小
    set<int,mycomp>test;
    //结构体的话，比较函数就直接写在结构体内部
    set<Info>info;

    //equal_range()
    pair<set<int>::const_iterator,set<int>::const_iterator>pr;
    pr = s.equal_range(3);
    cout<<"第一个大于等于 3 的数是 ："<<*pr.first<<endl;
	cout<<"第一个大于 3的数是 ： "<<*pr.second<<endl;

	//lower_bound upper_bound ,s就是set集合
	cout<<*s.lower_bound(2)<<endl;
	cout<<*s.lower_bound(3)<<endl;
	cout<<*s.upper_bound(3)<<endl;

    //析构，释放内存
    s.~set();
  return 0;
}


