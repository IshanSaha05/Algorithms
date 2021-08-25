def copy(arr):
  s=[]
  for i in range(len(arr)):
    s.append([arr[i],i])
  return s

def binary_search_recursive(x,left,right,val):
  if right>=left:
    mid=(left+right)//2
    if x[mid][0]==val:
      return x[mid][1]+1

    if x[mid][0]>val:
      return binary_search_recursive(x,left,mid-1,val)
    
    return binary_search_recursive(x,mid+1,right,val)
  return -1

def binary_search_non_recursive(x,n,val):
  left,right=0,n-1
  while left<=right:
    mid=(left+right)//2
    if x[mid][0]==val:
      return x[mid][1]+1

    if x[mid][0]>val:
      right=mid-1

    else:
      left=mid+1
  
  return -1

arr=list(map(int,input('Enter the elements of the array:\n').split(' ')))
print('\nThe elements stored in the array is:')
for i in arr:
  print(i,end=' ')
val=int(input('\nEnter the no to be searched for: '))

print('\nMenu:\n1) Binary Search Recursive.\n2) Binary Search Non-Recursive.')
ch=int(input('Enter the choice: '))

s=copy(arr)
s.sort(key=lambda x: x[0])

if ch==1:
  pos=binary_search_recursive(s,0,len(arr)-1,val)
  if pos!=-1:
    print('\nMessage: The value {:d} is found at position {:d} in the array.'.format(val,pos))
  else:
    print('\nError: The value {:d} not found in the array.'.format(val))
elif ch==2:
  pos=binary_search_non_recursive(s,len(arr),val)
  if pos!=-1:
    print('\nMessage: The value {:d} is found at position {:d} in the array.'.format(val,pos))
  else:
    print('\nError: The value {:d} not found in the array.'.format(val))
else:
  print('Error: Invalid choice.')
  print(s)
