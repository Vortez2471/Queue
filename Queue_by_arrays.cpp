#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int capacity=6;

int arr[capacity];
int rear=0,front=0;

int isEmpty()
{
	if(rear==front)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(rear==capacity)
		return 1;
	else
		return 0;
}

void enqueue()
{
	if(isFull())
		cout<<"Queue is full"<<endl;
	else
	{
		int n;
		cout<<"Enter the number"<<endl;
		cin>>n;
		arr[rear]=n;
		rear++;
	}
}

void dequeue()
{
	if(isEmpty())
		cout<<"Queue is empty"<<endl;
	else
	{
		cout<<"The dequeued element is "<<arr[front]<<endl;
		for(int i=1;i<rear;i++)
			arr[i-1]=arr[i];
	}
}

void get_rear()
{
	if(isEmpty())
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	cout<<"Rear element is "<<arr[rear-1]<<endl;
}

void get_front()
{
	if(isEmpty())
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	cout<<"Front element is "<<arr[front]<<endl;
}

void display()
{
	if(isEmpty())
		cout<<"Queue is empty"<<endl;
	else
	{
		for(int i=0;i<rear;i++)
			cout<<arr[i]<<"->";
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