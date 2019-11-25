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

void cir_enqueue()
{
	cout<<"Enter the data"<<endl;
	Node *temp=new Node();
	cin>>temp->data;
	temp->link=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
		rear->link=front;
	}
	else
	{
		temp->link=rear->link;
		rear->link=temp;
		rear=temp;
	}
	
}

void cir_dequeue()
{
	if(front==NULL)
		cout<<"Circular queue is empty"<<endl;
	else
	{
		Node* temp=front;
		front=front->link;
		rear->link=front;
		delete temp;
	}
}

void cir_get_front()
{
	if(front==NULL)
		cout<<"Circular queue is empty"<<endl;
	else
	{
		cout<<"Front element is "<<front->data<<endl;
	}
}

void cir_get_rear()
{
	if(rear==NULL)
		cout<<"Circular queue is empty"<<endl;
	else
	{
		cout<<"Rear element is "<<rear->data<<endl;
	}
}

void cir_display()
{
	if(front==NULL)
		cout<<"Circular queue is empty"<<endl;
	else
	{
		Node*temp=front;
		cout<<temp->data<<"<-";
		temp=temp->link;
		while(temp!=front)
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
				cir_enqueue();
				break;
			case 2:
				cir_dequeue();
				break;
			case 3:
				cir_get_front();
				break;
			case 4:
				cir_get_rear();
				break;
			case 5:
				cir_display();
				break;
			case 6:
				exit(0);
			default:
			    cout<<"Enter a valid option"<<endl;
		}
	}
}