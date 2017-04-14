#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
/*
     OI省选之STL栈
     Stack：先进后出的数据结构(LIFO)
     C++ STL 的堆栈泛化是直接通过现有的序列容器来实现的，默认使用双端队列deque的数据结构，当然，可以采用其他线性结构（vector 或 list等），
     只要提供堆栈的入栈、出栈、栈顶元素访问和判断是否为空的操作即可。由于堆栈的底层使用的是其他容器，因此，堆栈可看做是一种适配器，将一种容器转换为另一种容器(堆栈容器)。
     为了严格遵循堆栈的数据后进先出原则，stack 不提供元素的任何迭代器操作，因此，stack 容器也就不会向外部提供可用的前向或反向迭代器类型。

     acm爆栈解决办法：
     递归易爆栈，一般几万层递归就爆了，通常的规避方法是用stack或者手写stack模拟栈的递归过程。但是实际这种方法效率很低
     某大神给出的办法：
     文件头加#pragma comment(linker, "/STACK:1024000000,1024000000")后面两个数字随便写。。。你觉得能过就好，另外不要超了栈内存的真正上限。适用：C++语言编写的代码且用VC++编译器编译，若用GCC/G++编译，则可使用汇编命令来增栈
     当然咯，这个代码必须拿C++来提交，所以C++会出现的那种long long 和__int64的问题也要注意到。。。
     某题stack模拟dfs 2500+ms，开放了栈内存的普通dfs 300＋ms。。。不解释。。windows伤不起啊。
*/

int main(){
    //常用STL操作，比较简单
    stack<int>s;//默认使用deque作为底层数据结构
    stack<int,list<int> >ss;//指定vector或list为底层数据结构
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    if(!s.empty())
        printf("%d\n",s.size());
     printf("%d\n",s.top());
    return 0;
}
