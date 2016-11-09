#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<functional>//提供STL堆操作make_heap()
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define INF 0x0fffffff
#define MANX INF
//map 一些常见用法
/**map:映射<key,value>它是一一对应的单射;multimap:<key,value>一个key可以对应多个value,即一个key可以插入多个value,显示的时候是依次显示的，如1 sss 1 ttt 2 ddd这种
  *内部也是红黑树实现，默认升序排列，不允许重复的key
  *由于map的每个数据对应红黑树上的一个节点，这个节点在不保存你的数据时，是占用16个字节的，一个父节点指针，左右孩子指针，还有一个枚举值（标示红黑的，相当于平衡二叉树中的平衡因子），我想大家应该知道，这些地方很费内存了。
  **/
	typedef struct tagStudentInfo
	{
	       int      nID;
	       string   strName;
	       bool operator < (tagStudentInfo const& _A) const
	       {
              //这个函数指定排序策略，按nID排序，如果nID相等的话，按strName排序
	              if(nID < _A.nID)  return true;
	              if(nID == _A.nID) return strName.compare(_A.strName) < 0;
	              return false;
	       }
	}StudentInfo, *PStudentInfo;  //学生信息

int main(void){
  //常见用法举例,只对map举例，multimap同map,经比较发现map和set很多方法的操作一样，细节的部分可以模仿set
  //初始化：和set略相似,不过多讲

  map<int,string> mapStudent;
  map<int,string> mapStudent2(mapStudent);
  //三种插入数据的方法
  //01 pair 4种写法
  pair<int,string>p1;
  p1=make_pair(1,"cui");
  pair<int,string>p2(2,"ss");
  mapStudent.insert(p1);
  mapStudent.insert(p2);
  mapStudent.insert(pair<int,string>(3,"ssss"));
  mapStudent.insert(make_pair(4,"666"));
  //02 value_type
  mapStudent.insert(map<int,string>::value_type(5,"777"));
  //03 数组，速度低于上面两种 ,并且用数组方式可以覆盖以前该关键字对应的值，而前两种方法则不能达到这种效果
  mapStudent[6]="cuicui";
  //大小
  int nSize = mapStudent.size();
  //遍历，也是三种，前向迭代器，反向迭代器和数组遍历，前两种同set
  map<int,string>::iterator iter;
  for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
  {
    cout<<iter->first<<"  "<<iter->second<<endl; //key value
  }
  map<int, string>::reverse_iterator  riter;
  for(riter = mapStudent.rbegin(); riter != mapStudent.rend(); riter++)
  {
    cout<<riter->first<<"   "<<riter->second<<endl;
  }
  for(int nIndex = 1; nIndex <= nSize; nIndex++)
  {
         cout<<mapStudent[nIndex]<<endl;
  }
  //查找.（包括判定这个关键字是否在map中出现） 2种方法
  //01 用count函数来判定关键字是否出现，其缺点是无法定位数据出现位置, int count(value & Key) 返回等于key的元素数量，0或1

  //02 用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器
  map<int, string>::iterator iter2;
  iter2 = mapStudent.find(1);
  if(iter != mapStudent.end())
  {
       cout<<"Find, the value is "<<iter->second<<endl;
  }
  else
  {
      cout<<"Do not Find"<<endl;
  }
  //清空 判空 clear() 和empty() 函数 empty返回true则说明是空map
  //删除 也是和set一样的三种删除方法
  //如果要删除1,用迭代器删除
  map<int, string>::iterator ite;
  ite = mapStudent.find(1);
  mapStudent.erase(ite);
  //如果要删除1，用关键字删除
  int n = mapStudent.erase(1);//如果删除了会返回1，否则返回0
  //用迭代器，成片的删除
  //一下代码把整个map清空
  mapStudent.erase(mapStudent.begin(), mapStudent.end());
  //成片删除要注意的是，也是STL的特性，删除区间是一个前闭后开的集合

  //自定义排序
  //01结构体 重载< 后直接如下插入元素即可
  map<StudentInfo, int>mapStudent3;
  StudentInfo studentInfo;
  studentInfo.nID = 1;
  studentInfo.strName = "student_one";
  mapStudent3.insert(pair<StudentInfo, int>(studentInfo, 90));

  //02普通排序 仿函数的应用 以下内容直接写在main()里面了，用的时候移除去即可
  	typedef struct tagStudentInfo
	{
	       int      nID;
	       string   strName;
	}StudentInfo, *PStudentInfo;  //学生信息
    class sort
	{
	       public:
	       bool operator() (StudentInfo const &_A, StudentInfo const &_B) const
	       {
	              If(_A.nID < _B.nID) return true;
	              If(_A.nID == _B.nID) return _A.strName.compare(_B.strName) < 0;
	              Return false;
      }
	};
    //用学生信息映射分数
     map<StudentInfo, int, sort>mapStudent;
     StudentInfo studentInfo;
     studentInfo.nID = 1;
     studentInfo.strName = "student_one";
     mapStudent.insert(pair<StudentInfo, int>(studentInfo, 90));
     studentInfo.nID = 2;
     studentInfo.strName = "student_two";
     mapStudent.insert(pair<StudentInfo, int>(studentInfo, 80));

   
  ################################
  //1对2的多value举例
  multimap<int,string>ss;
  ss.insert(make_pair(1,"sas"));
  ss.insert(make_pair(1,"sadddds"));
  ss.insert(make_pair(2,"sas"));

  multimap<int,string>::iterator sa;
  for(sa=ss.begin();sa!=ss.end();sa++)
    cout<<sa->first<<' '<<sa->second<<endl;//显示 1 sas 1 saddds 2 sas
  multimap<int,string>::iterator s2;
  s2=ss.find(1);
  if(s2!=ss.end())
  {
      cout<<s2->second<<endl;//第一个元素sas
      s2++;
      cout<<s2->second<<endl;//第二个元素sadddds
      s2++;
      cout<<s2->second<<endl;//第3个元素,竟然又是sas，猜测看来是%循环链表类似的结构
  }
  cout<<ss.count(1)<<endl;//2
  cout<<ss.size()<<endl;//3

  return 0;
}


