#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* rlink;
		Node* llink;
};
Node *front=NULL,*rear=NULL;

void deque_enqueue_back()
{
	cout<<"Enter the data"<<endl;
	Node *temp=new Node();
	cin>>temp->data;
	temp->rlink=NULL;
	temp->llink=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		temp->rlink=rear->rlink;
		rear->rlink=temp;
		temp->llink=rear;
		rear=temp;
	}
}

void deque_dequeue_front()
{
	if(front==NULL)
		cout<<"Deque is empty"<<endl;
	else
	{
		Node* temp=front;
		cout<<"Popped element is "<<temp->data<<endl;
		front=front->rlink;
		front->llink=NULL;
		delete temp;
	}
}

void deque_enqueue_front()
{
	cout<<"Enter the data"<<endl;
	Node *temp=new Node();
	cin>>temp->data;
	temp->rlink=NULL;
	temp->llink=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		temp->llink=front->llink;
		temp->rlink=front;
		front->llink=temp;
		front=temp;
	}
}

void deque_dequeue_back()
{
	if(front==NULL)
		cout<<"Deque is empty"<<endl;
	else
	{
		Node* temp=rear;
	    cout<<"Popped element is "<<temp->data<<endl;
		rear=rear->llink;
		rear->rlink=NULL;
		delete temp;
	}
}

void deque_get_front()
{
	if(front==NULL)
		cout<<"Deque is empty"<<endl;
	else
	{
		cout<<"Front element is "<<front->data<<endl;
	}
}

void deque_get_rear()
{
	if(rear==NULL)
		cout<<"Deque is empty"<<endl;
	else
	{
		cout<<"Rear element is "<<rear->data<<endl;
	}
}

void deque_display()
{
	if(front==NULL)
		cout<<"Deque is empty"<<endl;
	else
	{
		Node*temp=front;
		while(temp!=NULL)
		{
			cout<<temp->data<<"<-";
			temp=temp->rlink;
		}
		cout<<endl;
	}
}

int main()
{
	int ch;
	while(1)
	{
		cout<<"Enter your choice\n1.Push_back\n2.Pop_front\n3.Front\n4.Rear\n5.Display\n6.Push_front\n7.Pop_back\n8.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				deque_enqueue_back();
				break;
			case 2:
				deque_dequeue_front();
				break;
			case 3:
				deque_get_front();
				break;
			case 4:
				deque_get_rear();
				break;
			case 5:
				deque_display();
				break;
			case 6:
				deque_enqueue_front();
				break;
			case 7:
				deque_dequeue_back();
				break;
			case 8:
				exit(0);
			default:
			    cout<<"Enter a valid option"<<endl;
		}
	}
}