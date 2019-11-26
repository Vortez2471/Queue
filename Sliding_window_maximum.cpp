#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long

queue<int>q;

ll n,k,j;

void window(ll arr[])
{
	ll max=INT_MIN;
    for(int i=0;i<k;i++)
    {
    	q.push(arr[i]);
    	if(max<q.back())
    		max=q.back();
    }
    cout<<max<<" ";
	for(int i=k;i<n;i++)
	{
		max=INT_MIN;
		j=k;
		while(j--)
		{
			if(max<q.front())
			{
				if(q.front()==arr[i-k]&&max<arr[i])
					max=arr[i];
				max=q.front();
			}
			if(q.front()!=arr[i-k])
			{
				q.push(q.front());
				q.pop();
			}
			else
				q.pop();
		}
		q.push(arr[i]);
		if(q.back()>max)
			max=q.back();
		cout<<max<<" ";
	}

}

int main()
{
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	ll arr[n];
	cout<<"Enter the window size"<<endl;
	cin>>k;
	cout<<"Enter array elements"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
    window(arr);
	
}