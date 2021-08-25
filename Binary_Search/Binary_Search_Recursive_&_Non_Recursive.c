#include<stdio.h>

void input(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
}

void traverse(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d  ",arr[i]);
}

void copy(int arr[],int brr[][2],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		brr[i][0]=arr[i];

		brr[i][1]=i;
	}
}

void merge(int s[][2],int u[][2],int v[][2],int lu,int lv)
{
	int uf=0,vf=0,i;
	for(i=0;i<lu+lv;i++)
	{
		if(uf<lu && vf<lv)
		{
			if(u[uf][0]<v[vf][0])
			{
				s[i][0]=u[uf][0];
				s[i][1]=u[uf][1];
				uf++;
			}
			else
			{
				s[i][0]=v[vf][0];
				s[i][1]=v[vf][1];
				vf++;
			}
		}
		else if(uf<lu)
		{
			s[i][0]=u[uf][0];
			s[i][1]=u[uf][1];
			uf++;
		}
		else
		{
			s[i][0]=v[vf][0];
			s[i][1]=v[vf][1];
			vf++;
		}
	}
}

void merge_sort(int s[][2],int n)
{
	if(n==1)
	return;
	int u[n/2][2],v[n-n/2][2],i;
	for(i=0;i<n/2;i++)
	{
		u[i][0]=s[i][0];
		u[i][1]=s[i][1];
	}
	for(i=0;i<n-n/2;i++)
	{
		v[i][0]=s[i+n/2][0];
		v[i][1]=s[i+n/2][1];
	}

	merge_sort(u,n/2);
	merge_sort(v,n-n/2);
	merge(s,u,v,n/2,n-n/2);
}

int binary_search_recursive(int x[][2],int left,int right,int val)
{
	if(right>=left)
	{
		int mid=(left+right)/2;
		if(x[mid][0]==val)
		return x[mid][1]+1;
		
		if(x[mid][0]>val)
		return binary_search_recursive(x,left,mid-1,val);

		return binary_search_recursive(x,mid+1,right,val);
	}
	return -1;
}

int binary_search_non_recursive(int s[][2],int n,int val)
{
  	int left=0,right=n-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(s[mid][0]==val)
		return s[mid][1]+1;

		if(s[mid][0]>val)
		right=mid-1;

		else
		left=mid+1;
	}
	return -1;
}

int main()
{
	int n,val,pos,ch;

	printf("\nEnter the total no of elements in the array: ");
	scanf("%d",&n);
	int arr[n];

	printf("\nEnter the elements of the array:\n");
	input(arr,n);

	printf("\nThe elements stored in the array is:\n");
	traverse(arr,n);

	printf("\nEnter the no to be searched for: ");
	scanf("%d",&val);

  	printf("\n\nMenu:\n1) Binary Search Recursive.\n2) Binary Search Non-Recursive.\nEnter the choice: ");
  	scanf("%d",&ch);

	int s[n][2];

	copy(arr,s,n);
  	merge_sort(s,n);
  	switch (ch)
  	{
	    case 1:		pos=binary_search_recursive(s,0,n-1,val);
    	          	if(pos!=-1)
        	     	printf("\nMessage: The value %d is found at position '%d' in the array.",val,pos);
            		else
              		printf("\nMessage: The value %d not found in the array.",val);
              		break;
    	case 2:   	pos=binary_search_non_recursive(s,n,val);
        	      	if(pos!=-1)
            	 	printf("\nMessage: The value %d is found at position '%d' in the array.",val,pos);
              		else
              		printf("\nMessage: The value %d not found in the array.",val);
	              	break;
    	default:  	printf("\nError: Invalid choice.");
  	};
}
