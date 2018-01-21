#include <iostream>

using namespace std;

int main()
{
   int n,a,afisare,i,copa,k=0,max=0;
   cin>>n;
   for(i=1;i<=n;i++)
   {


    cin>>a;
    if (k==0)
        copa=a;


   if(copa==a)
   {
       k=k+1;
       if (k>max)
       {

        max=k;
        afisare=a;
       }

copa=a;


    }
    else k=0;
   }

while (max!=-1)
{

    cout<<afisare;
max=max-1;
}

return 0;
}
