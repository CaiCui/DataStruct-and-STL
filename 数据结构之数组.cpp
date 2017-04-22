#include <bits/stdc++.h>
using namespace std;
/*
    acm数组小结。注意：很大的数组要开在函数外的堆空间上
*/
int main()
{
      //定义
      int a[10];
      int b[10]={1,2,3,5};
      int c[10]{1,2,3,4,5};
      int m=10,n=10,h=10;

      //动态分配c++一维数组m，释放
      int *d=new int[m];
      d[0]=1;
      delete []d;//或delete d;

      //动态分配c++二维数组mxn，释放
      int **dd=new int *[m];
      for(int i=0;i<m;i++)
        dd[i]=new int [n];
      for(int i=0;i<m;i++)
        delete []dd[i];
      delete dd;

      //三维以此类推 mxnxh
      int ***ddd=new int **[m];
      for(int i=0;i<m;i++)
      {
         ddd[i]=new int *[n];
         for(int j=0;j<n;j++)
             ddd[i][j]=new int [h];
      }
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              delete ddd[i][j];//释放第三维的一维数组h
          }
          delete ddd[i];//释放第二维的二维数组
      }
      delete ddd;//释放第一维三维数组

      //动态分配c语言一维数组，释放
      int *p=NULL;
      p=(int *)malloc(sizeof(int)*n);
      p[0]=2;
      cout<<p[0]<<endl;
      free((void*)p);//此时p[0]为一个任意数

      //动态分配c语言二维数组mxn，释放
      int **pp;
      pp=(int **)malloc(m*sizeof(int *));
      for(int i=0;i<m;i++)
       pp[i]=(int *)malloc(sizeof(int)*n);
      for(int i=0;i<m;i++)
         free((void*)pp[i]);
      free ((void *)pp);

      //动态分配c语言三维数组mxnxh，释放
      int ***ppp;
      ppp=(int ***)malloc(m*sizeof(int**));
      for(int i=0;i<m;i++)
        ppp[i]=(int **)malloc(n*sizeof(int *));
      for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
         ppp[i][j]=(int *)malloc(h*sizeof(int));
      for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
         free((void*)ppp[i][j]);
      for(int i=0;i<m;i++)
         free((void*)ppp[i]);
      free((void *)ppp);

      return 0;
}
