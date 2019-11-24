#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		int p;
		Node* link;
};
Node *front=NULL,*rear=NULL;

void pq_enqueue()
{
	cout<<"Enter the data"<<endl;
	Node *temp=new Node();
	cin>>temp->data;
	cout<<"Enter the priority"<<endl;
	cin>>temp->p;
	temp->link=NULL;
	if(front==NULL)
	{
		front=temp;
	}
	else
	{
		Node*flag=front;
		while(flag->link!=NULL&&flag->link->p<temp->p)
		{
			flag=flag->link;
		}
		temp->link=flag->link;
		flag->link=temp;
	}
	Node*flag=front;
	while(flag->link!=NULL)
		flag=flag->link;
	rear=flag;
}

void pq_dequeue()
{
	if(front==NULL)
		cout<<"Priority queue is empty"<<endl;
	else
	{
		Node* temp=front;
		front=front->link;
		delete temp;
	}
}

void pq_get_front()
{
	if(front==NULL)
		cout<<"Priority queue is empty"<<endl;
	else
	{
		cout<<"Front element is "<<front->data<<endl;
	}
}

void pq_get_rear()
{
	if(rear==NULL)
		cout<<"Priority queue is empty"<<endl;
	else
	{
		cout<<"Rear element is "<<rear->data<<endl;
	}
}

void pq_display()
{
	if(front==NULL)
		cout<<"Priority queue is empty"<<endl;
	else
	{
		Node*temp=front;
		while(temp!=NULL)
		{
			cout<<temp->data<<"<-";
			temp=temp->link;
		}
		cout<<endl;
	}
}

int main()
{
	int ch;
	while(1)
	{
		cout<<"Enter your choice\n1.Enqueue\n2.Dequeue\n3.Front\n4.Rear\n5.Display\n6.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				pq_enqueue();
				break;
			case 2:
				pq_dequeue();
				break;
			case 3:
				pq_get_front();
				break;
			case 4:
				pq_get_rear();
				break;
			case 5:
				pq_display();
				break;
			case 6:
				exit(0);
			default:
			    cout<<"Enter a valid option"<<endl;
		}
	}
}