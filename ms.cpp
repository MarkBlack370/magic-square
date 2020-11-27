#include<iostream>

#include<iomanip>

#define N 100

using namespace std;

extern int n;

int a[N][N];



void swap(int A[N][N],int a1,int a2,int b1,int b2)

{

 int T;

 T=a[a1][a2];

 a[a1][a2]=a[b1][b2];

 a[b1][b2]=T;

}



int main()

{

 int f1(int x);

 int f2(int x);

 int f3(int x);

 int i,j;

 int n;

 cout<<"Please input a natural number: ";

 cin>>n;

 cout<<endl;

 for(i=0;i<n;i++)

 {

     for(j=0;j<n;j++)

     {

      a[i][j]=0;

  }

    }

 if(n==1)

 {

     cout<<"1";

     return 1;

 }

 else if(n>2)

 {

  if(n%2!=0)

      f1(n);

  else if(n%2==0&&n%4==0)

      f2(n);

  else if(n%2==0&&n%4!=0)

      f3(n);

 }

 else

 {

     cout<<"Error:something is wrong."<<endl;

  return 1;

 }

 for(i=0;i<n;i++)

 {

     for(j=0;j<n;j++)

     {

      cout<<setw(4)<<a[i][j]<<" ";

  }

 cout<<endl;

    }

 return 0;

}



int f1(int x)

{

 int i,j,i1,j1,m;

 i=0;

 j=(x-1)/2;

 a[i][j]=1;

 for(m=2;m<=x*x;m++)

 {

  i1=i;

  j1=j;

     if(i==0&&j<x-1)

     {

   i=x-1;

   j++;

  }

     else if(j==x-1&&i>0)

  {

   j=0;

   i--;

  }

     else if(i==0&&j==x-1)

   i++;

  else

     {

      i--;

      j++;

  }



     if(a[i][j]==0)

      a[i][j]=m;

     else

     {

      (i1!=x-1)?(i1+=1):(i1=0);

      a[i1][j1]=m;

      i=i1;

      j=j1;

  }

    }

 return 0;

}



int f2(int x)

{

 int i,j;

 for(i=0;i<x;i++)

     for(j=0;j<x;j++)

      a[i][j]=i*x+j+1;

    for(i=x/4;i<(x*3/4);i++)

     for(j=0;j<x/2;j++)

      swap(a,i,j,i,x-j-1);

    for(j=x/4;j<(x*3/4);j++)

     for(i=0;i<x/2;i++)

      swap(a,i,j,x-i-1,j);

    return 0;

}



int f3(int x)

{

 int i,j,k=(x-2)/4,k1,k2,hi;

 k1=k;

 k2=3*k+1;

 for(i=0;i<x;i++)

     for(j=0;j<x;j++)

      a[i][j]=i*x+j+1;

    for(hi=k1+1;hi<k2;hi++)

  swap(a,hi,0,x-hi-1,x-1);

    for(hi=k1+1;hi<k2;hi++)

  swap(a,0,hi,x-1,x-hi-1);

    swap(a,k1,0,k1,x-1);

 swap(a,k1+1,0,k1+1,x-1);

 swap(a,k2,0,k2,x-1);

 for(hi=k1+1;hi<k2;hi++)

  swap(a,k1,hi,k1,x-hi-1);



    for(i=0;i<x/2;i++)

    {

        if(i==k1)

            continue;

        else

         swap(a,i,k1,x-i-1,k1);

 }

    for(hi=k1+1;hi<k2;hi++)

     swap(a,k1,hi,k2,hi);

    for(hi=k1+1;hi<k2;hi++)

    {

        if(hi==2*k)

            continue;

        else

         swap(a,hi,k1,hi,k2);

 }

 swap(a,k1,0,k2,0);

    for(hi=k1+1;hi<x/2;hi++)

  swap(a,k1,hi,k1,x-hi-1);

 return 0;
}
