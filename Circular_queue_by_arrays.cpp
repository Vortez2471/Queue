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
	if((front==0&&rear==capacity-1)||(rear==(front-1)%(capacity-1)))
		return 1;
	else
		return 0;
}

void cir_enqueue()
{
	if(isFull())
		cout<<"Circular queue is full"<<endl;
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

void cir_dequeue()
{
	if(isEmpty())
		cout<<"Circular queue is empty"<<endl;
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

void cir_get_rear()
{
	if(isEmpty())
	{
		cout<<"Circular queue is empty"<<endl;
		return;
	}
	cout<<"Rear element is "<<arr[rear]<<endl;
}

void cir_get_front()
{
	if(isEmpty())
	{
		cout<<"Circular queue is empty"<<endl;
		return;
	}
	cout<<"Front element is "<<arr[front]<<endl;
}

void cir_display()
{
	if(isEmpty())
		cout<<"Circular queue is empty"<<endl;
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