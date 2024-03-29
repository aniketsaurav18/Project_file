
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x){
            return mid;
        }

        if (arr[mid] > x){
            return binarySearch(arr, l, mid - 1, x);
        }else{
            return binarySearch(arr, mid + 1, r, x);
        }
        
    }
    return -1;
}
 
int main()
{
    printf("Enter size of sorted array");
    int n;
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of sorted array");
    for(int i = 0; i < n; ++i) {
     scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter the number you want to search");
    scanf("%d",&x)
    int result = binarySearch(arr, 0, n - 1, x);
    if(result == -1){
        printf("Element is not present in array")
    }else{
        printf("Element is present at index %d", result);
    }
    
    
        
    return 0;
}