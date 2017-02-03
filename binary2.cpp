#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
using namespace std;
parti_tion(int *a,int start,int last)
{
    int pivot=a[last];
    int i=start;
    for(int j=start;j<=(last-1);j++)
    {
        if(a[j]<=pivot)
        {
            int c;
            c=a[j];
            a[j]=a[i];
            a[i]=c;
            i++;
        }
    }
    int p;
    p=a[i];
    a[i]=a[last];
    a[last]=p;
    return i;
}
quick_sort(int *a,int start,int last)
{
    if(start<last)
    {
        int  i=parti_tion(&a[0],start,last);
        quick_sort(&a[0],start,i-1);
        quick_sort(&a[0],i+1,last);
    }
}

binary(int *a,int f,int n)
{

    int low=0,high=n,cn=0;
while(low<=high)
{
    cn++;
    int mid=(low+high)/2;
    if(a[mid]>f)
    {
        high=mid-1;

    }
            else if(a[mid]<f)
            {
             low=mid+1;
            }

    else
    {
         cout<<"the no. of comparisons "<<cn;
        return mid+1;
    }
        }
        cout<<"the no.  of comparisons "<<cn;
return -1;


}
int main()
{
  srand((unsigned)time(0));
int  i,f,p,a[10000];
cout<<"\nENTER THE  NO. OF TERMS->";
cin>>p;
for(i=0;i<p;i++)
{
    a[i]=1+rand()%p;
}
  quick_sort(&a[0],0,p);
for(i=0;i<p;i++)
{
    cout<<a[i]<<" ";
}
if(p!=0)
{
cout<<endl<<"THE ELEMENT TO BE SEARCH\n";
cin>>f;
}
else
exit(1);
int r=binary(&a[0],f,p);
if(r==-1)
    cout<<"\nSEARCH IS UNSUCCESFUL";
else
    cout<<"\nSEARCH IS SUCCESFUL\n"<<"THE POSITION OF SEACH NO. IS->"<<r;
}

