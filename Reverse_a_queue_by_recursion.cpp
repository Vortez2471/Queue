#include<iostream>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
queue<int>q,q2;

void reverse()
{
	if(q.empty())
		return;
	int c=q.front();
	q.pop();
	reverse();
	q.push(c);
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
	
	reverse();
	
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
}