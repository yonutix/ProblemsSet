#include <iostream>

using namespace std;

int main()
{
   int a,n,i,k=0,max=0;
   cin>>n;
   for(i=1;i<=n;i++)
   {
       cin>>a;
       if (a%2==0)
       {
           k=k+1;
       }
           else
            k=0;

       if(k>max)
        max=k;
   }
   cout<<max;
   return 0;
}
