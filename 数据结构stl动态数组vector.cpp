#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/**
动态数组用法:
1 基本操作
(1)头文件#include<vector>.
(2)创建vector对象，vector<int> vec;
(3)尾部插入数字：vec.push_back(a);
(4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。
(5)使用迭代器访问元素.
 vector<int>::iterator it;
 for(it=vec.begin();it!=vec.end();it++)
    cout<<*it<<endl;
(6)插入元素：  vec.insert(vec.begin()+i,a);在第i+1个元素前面插入a;
(7)删除元素：  vec.erase(vec.begin()+2);删除第3个元素
 vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始
(8)向量大小:vec.size();
(9)清空:vec.clear();
vec.front() - 回传 vector 第一个元素的引用。
vec.back() - 回传 vector 最尾元素的引用。
vec.pop_back() - 删除 vector 最尾端的元素。
vec.empty() - 如果 vector 内部为空，则传回 true 值
算法

(1) 使用reverse将元素翻转：需要头文件#include<algorithm>

reverse(vec.begin(),vec.end());将元素翻转(在vector中，如果一个函数中需要两个迭代器，

一般后一个都不包含.)

(2)使用sort排序：需要头文件#include<algorithm>，

sort(vec.begin(),vec.end());(默认是按升序排列,即从小到大).

可以通过重写排序比较函数按照降序比较，如下：

定义排序比较函数：

bool Comp(const int &a,const int &b)
{
    return a>b;
}
调用时:sort(vec.begin(),vec.end(),Comp)，这样就降序排序。
*/

int main()
{
    double n;
    double i,j;
    vector<int>a;
    vector<double>b;
    while(cin>>n)
    {   if(fabs(n-0)<1e-6)break;
        b.push_back(n);

    }
    vector<double>::iterator it;
    for(it=b.begin();it!=b.end();it++)
        cout<<*it<<" ";
    cout<<b.at(6)<<endl;///相当曲输出第a[6]个元素 或者cout<<a[6]<<endl;
    i=b.front();
    j=b.back();
    cout<<i<<" "<<j<<" "<<b.size()<<endl;

}
