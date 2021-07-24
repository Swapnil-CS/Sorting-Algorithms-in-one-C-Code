#include<stdio.h>
#include<stdlib.h>
void print_array(int *arr, int n)
{
	int i;
	printf("\nArray after sorting is\n");
		for(i=0;i<n;i++)
		{
			printf("\t%d",*(arr+i));
		}
}
void bubble_iter(int *arr,int n)	//function for iterative bubble sort
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(*(arr+j)>*(arr+j+1))
			{
				temp=*(arr+j);
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
			}
		}
	}
	print_array(arr,n);
}
void bubble_rec(int *arr,int lb,int ub)		//function for recursive bubble sort
{
	int j,temp;
	if(lb>ub)
	{
		print_array(arr,ub+1);
	}
	else
	{
		for(j=0;j<ub-lb;j++)
		{
			if(*(arr+j)>*(arr+j+1))
			{
				temp=*(arr+j);
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
			}
		}
		return bubble_rec(arr,lb+1,ub);
	}
}
void modified_bubble_iter(int *arr,int n)	//function for iterative modified bubble sort
{
	int i,j,temp,flag;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(*(arr+j)>*(arr+j+1))
			{
				temp=*(arr+j);
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
				flag=1;
			}
		}
		if(flag==0)		//it indicates no swaping done in the last iteration and if its true the sorting is done
		break;
	}
	print_array(arr,n);
}
void modified_bubble_rec(int *arr,int lb,int ub)	//function for recursive modified bubble sort
{
	int j,temp,flag;
	if(lb>ub)
	{
		print_array(arr,ub+1);
	}
	else
	{
		flag=0;
		for(j=0;j<ub-lb;j++)
		{
			if(*(arr+j)>*(arr+j+1))
			{
				temp=*(arr+j);
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
				flag=1;
			}
		}
		if(flag==0)		//it indicates no swaping done in the last iteration and if its true the sorting is done
		{
			print_array(arr,ub+1);
		}
		else
		{
			return modified_bubble_rec(arr,lb+1,ub);	//when if cond. does'nt satisfy we continue sorting
		}
	}
}
void selection_iter(int *arr,int n)		//function for iterative selection sort
{
	int i,j,min_index,temp;
	for(i=0;i<n-1;i++)
	{
		min_index=i;
		for(j=i+1;j<n;j++)
		{
			if(*(arr+min_index)>*(arr+j))
			{
				min_index=j;
			}
		}
		if(*(arr+min_index)<*(arr+i))
		{
			temp=*(arr+min_index);
			*(arr+min_index)=*(arr+i);
			*(arr+i)=temp;
		}
	}
	print_array(arr,n);
}
void selection_rec(int *arr,int lb,int ub)		//function for recursive selection sort
{
	int j,temp,min_index;
	if(lb>ub)
	{
		print_array(arr,ub+1);
	}
	else
	{
		min_index=lb;
		for(j=lb+1;j<=ub;j++)
		{
			if(*(arr+min_index)>*(arr+j))
			{
				min_index=j;
			}
		}
		if(*(arr+min_index)<*(arr+lb))
		{
			temp=*(arr+min_index);
			*(arr+min_index)=*(arr+lb);
			*(arr+lb)=temp;
		}
		return selection_rec(arr,lb+1,ub);
	}
}
void insertion_iter(int *arr,int n)		//function for iterative insertion sort
{
	int i,j,item;
	for(i=1;i<n;i++)
	{
		item=*(arr+i);
		j=i-1;
		while(j>=0 && *(arr+j)>item)
		{
			*(arr+j+1)=*(arr+j);
			j=j-1;
		}
		*(arr+j+1)=item;
	}
	print_array(arr,n);
}
void insertion_rec(int *arr,int lb,int ub)		//function for recursive insertion sort
{
	int j,item;
	if(lb>ub)
	{
		print_array(arr,ub+1);
	}
	else
	{
		item=*(arr+lb);
		j=lb-1;
		while(j>=0 && *(arr+j)>item)
		{
			*(arr+j+1)=*(arr+j);
			j=j-1;
		}
		*(arr+j+1)=item;
		return insertion_rec(arr,lb+1,ub);
	}
}
int partition(int *arr,int lb,int ub)		//partition function for quick sort
{
	int pivot,temp;
	pivot=lb;
	while(ub>lb)
	{
	   	while(*(arr+lb)<=*(arr+pivot))
	   	lb++;
	   	while(*(arr+ub)>*(arr+pivot))
	   	ub--;
	   	if(ub>lb)
	   	{
	   		temp=*(arr+ub);
			*(arr+ub)=*(arr+lb);
			*(arr+lb)=temp;	
		}
	}
	temp=*(arr+ub);
	//*(arr+lb)=*(arr+ub);
	*(arr+ub)=*(arr+pivot);
	*(arr+pivot)=temp;
	return ub;
}
void quickSort_rec(int *arr,int lb,int ub)		//recurive quick sort function
{
	int j;
	if(ub>lb)
	{
		j=partition(arr,lb,ub);
		quickSort_rec(arr,lb,j-1);
		quickSort_rec(arr,j+1,ub);
	}
}
void merge(int *arr,int lb,int mid,int ub)		//merge function for merge sort
{
	int *b,i,j,k;
	b=(int*)malloc((ub+1)*sizeof(int));
	for(i=lb;i<=ub;i++)
	{
		*(b+i)=*(arr+i);
	}
	i=lb;
	j=mid+1;
	k=lb;
	while(i<=mid && j<=ub)
	{
		if(*(b+i)<*(b+j))
		{
			*(arr+k)=*(b+i);
			i++;
			k++;
		}
		else
		{
			*(arr+k)=*(b+j);
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		*(arr+k)=*(b+i);
		i++;
		k++;
	}
	while(j<=ub)
	{
		*(arr+k)=*(b+j);
		j++;
		k++;
	}
}
void merge_sort_rec(int *arr,int lb,int ub)		//recursive merge sort function
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		merge_sort_rec(arr,lb,mid);
		merge_sort_rec(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
void main()
{
	int n,*arr,i,ch;
	char sch;
	do
	{
		do
		{
			printf("\nEnter number of elements to store in the array(enter positive integer other than 0):");
			scanf("%d",&n);
		}while(n<=0);
		arr=(int*)malloc(n*sizeof(int));	//dynamic memory allocation for array
		printf("\nEnter %d elements:",n);
		for(i=0;i<n;i++)
		{
			scanf("%d",arr+i);		//taking input of array
		}
		printf("\n1.Iterative Bubble Sort\n2.Recursive Bubble Sort");
		printf("\n3.Iterative Modified Bubble Sort\n4.Recursive Modified Bubble Sort");
		printf("\n5.Iterative Selection Sort\n6.Recursive Selection Sort");
		printf("\n7.Iterative Insertion Sort\n8.Recursive Insertion Sort");
		printf("\n9.Recursive Quick Sort");
		printf("\n10.Recursive Merge Sort");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)		//switch-case for calling specific sorting functions
		{
			case 1:
				bubble_iter(arr,n);
				break;
			case 2:
				bubble_rec(arr,0,n-1);
				break;
			case 3:
				modified_bubble_iter(arr,n);
				break;
			case 4:
				modified_bubble_rec(arr,0,n-1);
				break;
			case 5:
				selection_iter(arr,n);
				break;
			case 6:
				selection_rec(arr,0,n-1);
				break;
			case 7:
				insertion_iter(arr,n);
				break;
			case 8:
				insertion_rec(arr,0,n-1);
				break;
			case 9:
				quickSort_rec(arr,0,n-1);
				print_array(arr,n);
				break;
			case 10:
				merge_sort_rec(arr,0,n-1);
				print_array(arr,n);
				break;		
			default :
			printf("\nWrong Choice given...!");								
		}
		printf("\nDo you want to continue sorting by entering new elements again?");
		printf("\nPress 'y' to continue and 'n' to Exit from System:");
		sch=getche(sch);
	}while(sch=='y' || sch=='Y');
}
