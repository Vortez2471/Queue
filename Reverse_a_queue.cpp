#include<iostream>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
queue<int>q,q2;

void reverse()
{
	stack<int>s;
	while(!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}

int main()
{
	int n,t;
	cout<<"Enter the number of elements you want to push"<<endl;
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
	reverse();
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
}