#include<stdio.h>
#include<stdlib.h>

void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void maxHeapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n&&arr[left]>arr[largest])
        largest=left;

    if(right<n&&arr[right]>arr[largest])
        largest=right;

    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr,n,largest);
    }
}

void buildHeap(int arr[],int n){
    int i;
    for(i=(n/2)-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}

int deleteMax(int arr[],int*n){
    if(*n<=0){
        printf("Heap is empty\n");
        return-1;
    }

    int maxElement=arr[0];

    arr[0]=arr[*n-1];
    (*n)--;

    // Modify maxHeapify to maintain the max heap property
    int i=0;
    while(1){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<*n&&arr[left]>arr[largest])
            largest=left;

        if(right<*n&&arr[right]>arr[largest])
            largest=right;

        if(largest!=i){
            swap(&arr[i],&arr[largest]);
            i=largest;
        }else{
            break;
        }
    }

    return maxElement;
}

void heapSort(int arr[],int n){
    buildHeap(arr,n);

    int i;
    for(i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        maxHeapify(arr,i,0);
    }
}

void printArray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={1,5,6,8,9,7,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr,n);

    buildHeap(arr,n);

    printf("Max Heap: ");
    printArray(arr,n);

    int max=deleteMax(arr,&n);
    printf("Deleted Max Element: %d\n",max);
    printf("Max Heap after deletion: ");
    printArray(arr,n);

    heapSort(arr,n);
    printf("Sorted array using Heap Sort: ");
    printArray(arr,n);

    return 0;
}
