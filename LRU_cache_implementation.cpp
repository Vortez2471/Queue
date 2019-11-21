#include<iostream>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
queue<int>q,q2;
unordered_map<int,int>ua;

void lru_cache(unsigned int n,unsigned int k)
{
	while(k--)
	{
		int t;
		cin>>t;
		if(q.size()<=n)
		{
			if(ua.find(t)==ua.end()||ua3[t]==0)
			{
				if(q.size()==n)
				{
					int last=q.front();
					ua[last]=0;
					q.pop();
				}
				q.push(t);
				ua[t]=1;
			}
			else if(ua[t]==1)
		    {
				while(!q.empty())
				{
					if(q.front()!=t)
					{
						q2.push(q.front());
						q.pop();
					}
					else
					{
						q.pop();
					}
				}
				q2.push(t);
				q=q2;
		    }
		}
		q2=q;
	}
}

int main()
{
	int n,k;
	cout<<"Enter the number of cores"<<endl;
	cin>>n;
	cout<<"Enter the number of tasks"<<endl;
	cin>>k;
	lru_cache(n,k);
	for(int i=1;i<=n;i++)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
}