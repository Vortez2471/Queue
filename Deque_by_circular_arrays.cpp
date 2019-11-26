#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int capacity=6;

int arr[capacity];
int rear=-1,front=-1;

int isEmpty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if((front==0&&rear==capacity-1)||(rear==front-1))
		return 1;
	else
		return 0;
}

void deque_enqueue_back()
{
	if(isFull())
		cout<<"Deque is full"<<endl;
	else
	{
		int n;
		cout<<"Enter the number"<<endl;
		cin>>n;
		if(isEmpty())
		{
			front=0;
			rear=0;
			arr[rear]=n;
		}
		else if(rear==capacity-1&&front!=0)
		{
			rear=0;
			arr[rear]=n;
		}
		else
		{
			rear++;
			arr[rear]=n;
		}
	}
}

void deque_dequeue_front()
{
	if(isEmpty())
		cout<<"Deque is empty"<<endl;
	else
	{
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		if(front==capacity-1)
		{
			cout<<"The dequeued element is "<<arr[front]<<endl;
			arr[front]=-1;
		    front=0;
		}
		else
		{
			cout<<"The dequeued element is "<<arr[front]<<endl;
			arr[front]=-1;
			front++;
		}
		
	}
}

void deque_enqueue_front()
{
	if(isFull())
		cout<<"Deque is full"<<endl;
	else
	{
		int n;
		cout<<"Enter the number"<<endl;
		cin>>n;
		if(isEmpty())
		{
			front=0;
			rear=0;
			arr[rear]=n;
		}
		else if(front==0)
		{
			front=capacity-1;
			arr[front]=n;
		}
		else
		{
			front--;
			arr[front]=n;
		}	
	}
}

void deque_dequeue_back()
{
	if(isEmpty())
		cout<<"Deque is empty"<<endl;
	else
	{
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		if(rear==0)
		{
			cout<<"The dequeued element is "<<arr[rear]<<endl;
			arr[rear]=-1;
		    rear=capacity-1;;
		}
		else
		{
			cout<<"The dequeued element is "<<arr[rear]<<endl;
			arr[rear]=-1;
			rear--;
		}
		
	}
}

void deque_get_rear()
{
	if(isEmpty())
	{
		cout<<"Deque is empty"<<endl;
		return;
	}
	cout<<"Rear element is "<<arr[rear]<<endl;
}

void deque_get_front()
{
	if(isEmpty())
	{
		cout<<"Deque is empty"<<endl;
		return;
	}
	cout<<"Front element is "<<arr[front]<<endl;
}

void deque_display()
{
	if(isEmpty())
		cout<<"Deque is empty"<<endl;
	if(rear>=front) 
    { 
        for(int i=front;i<=rear;i++) 
            cout<<arr[i]<<" "; 
    } 
    else
    { 
        for(int i=front;i<capacity;i++) 
            cout<<arr[i]<<" "; 
  
        for(int i=0;i<=rear;i++) 
            cout<<arr[i]<<" "; 
    } 
	cout<<endl;
}

int main()
{
	int ch;
	while(1)
	{
		cout<<"Enter your choice\n1.Push Back\n2.Pop Front\n3.Front\n4.Rear\n5.Display\n6.Push Front\n7.Pop Back\n8.Exit"<<endl;
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