#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin>>str;

    int len=str.length();

    int arr[26]={0};

    //mapping freq
    for(int i=0; i<len; i++)
    {
        arr[str[i]-'a']++;
    }

    int max=0;
    int min =1000000;

    //finding max and min freq
    for(int i=0; i<26; i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
        if(min>arr[i] && arr[i]!=0)
        {
            min=arr[i];
        }
    }
    
    for(int i=0; i<26; i++)
    {
        if(arr[i]!=0)
        {
            if(arr[i]==max || arr[i]==min)
            {
                continue;
            }
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    if(max==min)
    {
        cout<<"YES"<<endl;

    }
    else
    {
        //common and uncommon
        int freq_max=0;
        int freq_min=0;
        for(int i=0; i<26; i++)
        {
            if(arr[i]==max)
            {
                freq_max++;
            }
            if(arr[i]==min)
            {
                freq_min++;
            }
        }

        if(max-min!=1)
        {
            if(min==1 && freq_min==1)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
            if(freq_min==1 || freq_max==1)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }



    return 0;
}