#include<bits/stdc++.h>
using namespace std;
/*
  省选IO数据结构：堆(c实现)
  主要就是实现"上调"和"下滑"调整算法
  堆是一种经过排序的完全二叉树，
  其中任一非终端节点的数据值均不大于（或不小于）其左孩子和右孩子节点的值。
*/
//实现：最大/小堆区别在于tmp和arr[j]大小比较换一下，并且arr[j]和arr[j+1]也要交换，就会由小堆变大堆，用数组实现完全二叉树堆

//最小堆
//上调算法，用于元素添加进堆后的调整，即把待调整元素i一直和父节点比较直到一个合适的位置。
void fix_up_min_heap(int arr[],int i)//把当前第i个子节点向堆顶调整
{
    int j;
    j=(i-1)/2;//父节点
    int tmp=arr[i];
    while(j>=0&&tmp<arr[j])
    {
        arr[i]=arr[j];
        i=j;
        if(j>0)
            j=(j-1)/2;//继续找父亲
        else
            break;
    }
    arr[i]=tmp;
}
//下滑算法，从上向下调整，用于堆顶元素删除pop操作后的调整,即把待调整元素i一直和两个孩子节点中较大或较小的比较直到找到一个合适的位置。
void fix_down_min_heap(int arr[],int len,int i)//len:当前长度,而数组元素是从0开始的
{
   int j;
   j=2*i+1;//孩子节点
   int tmp=arr[i];
   while(j<len)
   {
       if(j<len-1 && arr[j+1]<arr[j])//预防数组末尾元素越界，保证数组不会越界，同时选出孩子中较小的点和tmp比较
       {
           j++;
       }
       if(arr[j]<tmp)
       {
         arr[i]=arr[j];
         i=j;
         j=2*i+1;
       }
       else
         break;
   }
   arr[i]=tmp;
}

//堆插入push,插入尾部，每次要和父结点比较，用上调算法
int insert_min_heap(int arr[],int n,int len,int x)
{
    if(n==len)return -1;
    arr[len++]=x;
    fix_up_min_heap(arr,len-1);
    return 1;
}
//取堆顶元素top
int top_min_heap(int arr[])
{
   return arr[0];
}
//堆删除pop,把最后一个元素覆盖到堆顶，然后做下调算法
void pop_min_heap(int arr[],int len)
{
    arr[0]=arr[--len];
    fix_down_min_heap(arr,len,0);
}

//最大堆调整算法
//上调算法，用于元素添加进堆后的调整，即把待调整元素i一直和父节点比较直到一个合适的位置。
void fix_up_max_heap(int arr[],int i)//把当前第i个子节点向堆顶调整
{
    int j;
    j=(i-1)/2;//父节点
    int tmp=arr[i];
    while(j>=0&&tmp>arr[j])
    {
        arr[i]=arr[j];
        i=j;
        if(j>0)
            j=(j-1)/2;//继续找父亲
        else
            break;
    }
    arr[i]=tmp;
}
//下滑算法，从上向下调整，用于堆顶元素删除pop操作后的调整,即把待调整元素i一直和两个孩子节点中较大或较小的比较直到找到一个合适的位置。
void fix_down_max_heap(int arr[],int len,int i)//len:当前长度,而数组元素是从0开始的
{
   int j;
   j=2*i+1;//孩子节点
   int tmp=arr[i];
   while(j<len)
   {
       if(j<len-1 && arr[j+1]>arr[j])//预防数组末尾元素越界，保证数组不会越界，同时选出孩子中较大的点和tmp比较
       {
           j++;
       }
       if(arr[j]>tmp)
       {
         arr[i]=arr[j];
         i=j;
         j=2*i+1;
       }
       else
         break;
   }
   arr[i]=tmp;
}

int main()
{
    int p[10];
	int t;
	int i;
	for(i=0;i<5;i++)
	{
		cin>>p[i];
        t=i;
        insert_min_heap(p,5,t,p[i]);
	}

	for(i=0;i<5;i++)
		cout<<p[i]<<' ';
    cout<<endl;
	for(i=5;i>0;i--)
	{
		t=i;
		cout<<top_min_heap(p)<<" ";
		pop_min_heap(p,t);
	}
	cout<<endl;

     return 0;
}
