#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
/*
    OI省选之单调栈
    单调栈类似单调队列，也是栈内元素均按严格递增或递减顺序删除或插入，常常结合动态规划思想求解问题
    基本知识：
    单调栈有以下两个性质：
    1、若是单调递增栈，则从栈顶到栈底的元素是严格递增的。若是单调递减栈，则从栈顶到栈底的元素是严格递减的。
    2、越靠近栈顶的元素越后进栈。
    单调栈与单调队列不同的地方在于栈只能在栈顶操作，因此一般在应用单调栈的地方不限定它的大小，否则会造成元素无法进栈。
    元素进栈过程：对于单调递增栈，若当前进栈元素为e，从栈顶开始遍历元素，把小于e或者等于e的元素弹出栈，直接遇到一个大于e的元素或者栈为空为止，然后再把e压入栈中。对于单调递减栈，则每次弹出的是大于e或者等于e的元素。
    一个单调递增栈的例子：
    进栈元素分别为3，4，2，6，4，5，2，3
    3进栈：（3）
    3出栈，4进栈：（4）
    2进栈：（4，2）
    2出栈，4出栈，6进栈：（6）
    4进栈：（6，4）
    4出栈，5进栈：（6，5）
    2进栈：（6，5，2）
    2出栈，3进栈：（6，5，3）
    以上左端为栈底，右端为栈顶
    也可反过来，只要保证栈内元素递增或递减即可！！
    单调栈的维护是O(n)级的时间复杂度，因为所有元素只会进入栈一次，并且出栈后再也不会进栈了。
*/
//例题:poj2796
/**
 问题描述：
  给一个n(1<=n<=100000),然后给出n个非负整数(0~10^6)，求出一个子区间使得该区间内的最小值乘以该区间元素之和最大！
  难点：最终求得的区间的长度和端点位置均未知，所以需要用一种巧妙地方法来遍历出所有情况，求出最大值，这题有一点动态规划的思想在里面。
  例如：
  6
  3 1 6 4 5 2
  以4为最小值，向左右延伸，6 4 5  值为60.......
  算法及单调栈特性详解：
  1.本题实现描述：
    设某个区间所有元素的和为height，区间最小元素为width，
    则对于单个元素的区间，height = width = 元素的值。
    建立一个单调递增的栈。从第一个元素开始入栈，对于每个元素入栈之前必须先从栈顶开始删除大于或等于它的元素，
    并且把删除的所有元素的height累加起来计算出tot，这表示把当前元素前面比它大或相等的连续元素的值加起来并乘以最小值，也就是这段区间的参考值。
    若元素入栈时，大于栈顶元素，只需要保留自己的值作为height和value，这么做就相当于把自己确立为一个即将出现的区间的最小值(这里这么说是因为后面的值大于还是小于该值暂时未知，
    如果小于该值，则该值就是一个独立区间，否则，可以作为包含后面值的区间的最小值)，因为左边的数一定比它小，如果包含左侧，
    那么它就不是该区间最小值，所以提前把自己作为可能出现的包含后面数的区间的最小值，这一思想2.里面也提到了。
    每一次删除元素都需要计算一个参考值，取参考值的最大值就是答案了。不过题目还要求给出对应区间的起点和终点，
    因此在栈的操作过程中还得记录当前元素保存的区间的起点和大小，在更新参考值的过程中顺便更新区间的起点和终点就可以了(实现上的一个小难点)。

  2.这个算法思想非常巧妙，用到了动态规划和栈结合的思想，首先建立一个单调递增的栈，所以越靠近栈底的元素值一定越小，而所涵盖的区间也就越大，举个例子
    比如对于2，如果有2的区间要求得最大值，必须使包含2的且2位最小值的区间尽可能最长，这里就是6 4 5 2，同理，对于1，由于它是最小的正整数，所以包含1的
    最大和的区间就是整个区间，同理，按升序依次枚举剩下的数，包含3的区间，可以发现只有3单个数满足条件，这是因为3右侧有1，所以只要3扩展一下它在新的区间就不是最小值了，
    看4，可得6,4,5是4对应的最长区间，5只有自己，因为两边都小于5,6和5同理。所以可得一个经验，只要某个元素中两侧或单侧(两头的元素)小于它，那么它就必然只能由自己构成一个
    区间了，这种规律很像动态规划中自底向上构造最优解的过程，可以看出，单调栈在这里的作用就是构造出一个以1,2,3,4,5,6的顺序作为区间最小值的工具，根据递增栈及栈本身的特性，先求出的就是
    数值比较大的作为最小值的区间的最大值，实际代码也验证了这一点，实际中求出的以某个数作为最小值顺序为，3,6,5,4,2,1，这与栈的进出顺序也相关。

  3.算法中核心值tot即最大值的计算也很有技巧，tot总是放在删除操作中完成，这是因为单调递增栈的特性：入栈元素要删掉大于它的元素，直到找到小于它的第一个元素，然后插在该元素后面，这样
    恰好就把诸如6,4,5这样的以4为最小值且区间最长的元素和求出来了，而以4为最小值的最长区间6,4,5的构造是这样的，当栈中有6，插入4时，4要删掉6，并加上6的值作为height，因为6大于它，可以作为以4为区间最小值的
    一员，当插入5时，不用删除4，若后面还有大于4的元素，依旧入栈，直到出现小于栈顶的元素，这里就是2，此时，就要累加，5,4,6的值，最后结果就是以4为最小值的区间的最大值，对于所有其他元素
    均是这样计算，最终迭代出最优解！！！！本算法的实质也是一种暴力更准确的说是DP，只是运用了一些策略，使复杂度降低很多，这里的策略就是单调栈优化。

  4.代码在下方，可以手写几个例子加深对本题解法的理解。

**/
struct Elem{
   long long sum;
   long long minelem;
   int begin;
   int count;//区间元素个数
};
Elem Stack[10000];//维持一个栈底到栈顶单调递增的栈
int top;
int main(){
    int num,n;
    long long ans,tmp,tot;
    int ansbeg,ansend,count;
    scanf("%d",&n);
    top=0;
    ans=0;
    ansbeg=ansend=1;
    for(int i=0;i<n;i++)//所有元素入栈过程中求解一遍，这一遍求出了以3,6,5,4为最小值的区间的最大值
    {
        scanf("%d",&num);
        tmp=0;//记录删掉的元素的区间和
        count=0;//记录相对begin的偏移值，用于求解end位置
        while( top>0 && Stack[top-1].minelem>=num )//删除操作，删除num前大于num的值，同时计算出这些被删除的num值组成的区间的tot值
        {
            Stack[top-1].count+=count;
            tot=(Stack[top-1].sum+tmp)*Stack[top - 1].minelem;
            if(tot>ans)
            {
                ans = tot;
                ansbeg=Stack[top-1].begin;
                ansend=ansbeg+Stack[top - 1].count - 1;
               // cout<<ans<<":"<<"("<<ansbeg<<","<<ansend<<")"<<endl;//结果:9:(1,1)=3*3 36(3,3)=6*6 60(3,5)=4*(6+4+5)
            }
            tmp+=Stack[top-1].sum;
            count=Stack[top-1].count;
            --top;
        }
        Stack[top].sum=num+tmp;
        Stack[top].minelem=num;
        Stack[top].begin=i+1-count;
        Stack[top++].count=count+1;
    }

    tmp=0;
    count=0;
    while(top>0)//若栈非空，则继续求解以剩下的元素作为区间最小值的区间最大值，这里是2和1。
    {
        Stack[top-1].count+=count;
        tot=(Stack[top-1].sum+tmp)*Stack[top - 1].minelem;
       // cout<<tot<<endl; 结果：6 4 5 2 =34 , 3 1 6 4 5 2=21
        if(tot>ans)
        {
            ans=tot;
            ansbeg=Stack[top-1].begin;
            ansend=ansbeg+Stack[top-1].count-1;

        }
        tmp+=Stack[top-1].sum;
        count=Stack[top-1].count;
        --top;
    }
    printf("%lld\n%d %d\n",ans,ansbeg,ansend);
    return 0;
}
