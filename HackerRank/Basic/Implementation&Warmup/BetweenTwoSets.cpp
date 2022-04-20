#include<iostream>

using namespace std;

 int main()

{

    int n,m,j=0,k,number=0,p=0,x;

    cin>>n>>m;

    int a[n],b[m];

    for(int i=0;i<n;i++)

    {

        cin>>a[i];

    }

    for(int i=0;i<m;i++)

    {

        cin>>b[i];

    }

   x=a[n-1];

    int c[100];

    while(x<=b[0])

    {

        for(int i=0;i<n;i++)

        {

            if(x%a[i]==0)

            {

                p=1;

            }

            else

            {

                p=0;

                break;

            }

        }

         if(p==1)

         {

             c[j]=x;

             j++;

         }

         x++;

        }

        for(int i=0;i<j;i++)

        {

            for(k=0;k<m;k++)

            {

                if(b[k]%c[i]==0)

                {

                    p=1;

                }

                else

                {

                    p=0;

                    break;

                }

            }

            if(p==1)

            {

                number++;

            }

            }

            cout<<number;

            return 0;

        }