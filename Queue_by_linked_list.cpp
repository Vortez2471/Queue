#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* link;
};
Node *front=NULL,*rear=NULL;

void enqueue()
{
	cout<<"Enter the data"<<endl;
	Node *temp=new Node();
	cin>>temp->data;
	temp->link=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->link=temp;
		rear=rear->link;
	}
}

void dequeue()
{
	if(front==NULL)
		cout<<"Queue is empty"<<endl;
	else
	{
		Node* temp=front;
		front=front->link;
		delete temp;
	}
}

void get_front()
{
	if(front==NULL)
		cout<<"Queue is empty"<<endl;
	else
	{
		cout<<"Front element is "<<front->data<<endl;
	}
}

void get_rear()
{
	if(rear==NULL)
		cout<<"Queue is empty"<<endl;
	else
	{
		cout<<"Rear element is "<<rear->data<<endl;
	}
}

void display()
{
	if(front==NULL)
		cout<<"Queue is empty"<<endl;
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
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				get_front();
				break;
			case 4:
				get_rear();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
			default:
			    cout<<"Enter a valid option"<<endl;
		}
	}
}