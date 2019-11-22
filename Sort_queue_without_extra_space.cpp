#include<iostream>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
queue<int>q,q2;

void sort(int n,int d,int size)
{
	if(n==0)
		return;
	int min=INT_MAX;
	for(int i=0;i<size;i++)
	{
		if(q.front()<min&&q.front()>d)
			min=q.front();
		int f=q.front();
		q.pop();
		q.push(f);
	}

	int i=0;
	while(i<size)
	{
		if(q.front()!=min)
		{
			q.push(q.front());
			q.pop();
		}
		else
		{
			q.pop();
		}
		i++;
	}
	q.push(min);
	sort(n-1,min,size);
}
int main()
{
	int n,t;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>t;
		q.push(t);
	}

	q2=q;
	while(!q2.empty())
	{
		cout<<q2.front()<<" ";
		q2.pop();
	}
	cout<<endl;
	sort(q.size(),INT_MIN,q.size());
	
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
}
