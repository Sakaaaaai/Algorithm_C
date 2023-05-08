/*
input
insert 8
insert 2
extract
insert 10
extract
insert 11
extract
extract
end

output
8
10
11
2
*/

#include <stdio.h>
#include <limits.h>

int heap[2000005];
int heap_size;

int parent(int i) {
    return i/2;
}

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

void maxHeapify(int A[], int i) {
    int l = left(i);
    int r = right(i);
    int largest;
    if(l <= heap_size && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }
   
    if(r <= heap_size && A[r] > A[largest]) {
        largest = r;
    }
    if(largest != i) {
        int t = A[i];
        A[i] = A[largest];
        A[largest] = t;
        maxHeapify(A, largest);
    }
}

void buildMaxHeap(int A[]) {
    int i;
    for(i=heap_size/2;i>0;i--) {
        maxHeapify(A, i);
    }
}

int heapExtractMax(int A[]) {
	int max;
    if(heap_size < 1) {
        return INT_MIN;	// エラー
    }
    max = A[1];
    A[1] = A[heap_size];
    heap_size = heap_size - 1;
    maxHeapify(A, 1);
    return max;
}

void heapIncreaseKey(int A[], int i, int key) {
    if(key < A[i]) {
        return; // error 新しいキーは現在のキーより小さい
    }
    A[i] = key;
    while(i > 1 && A[parent(i)] < A[i]) {
    	int t = A[i];
    	A[i] = A[parent(i)];
    	A[parent(i)] = t;
        i = parent(i);
    }
}

void maxHeapInsert(int A[], int key) {
    heap_size = heap_size + 1;
    A[heap_size] = INT_MIN;
    heapIncreaseKey(A, heap_size, key);
}

int main(void) {
    int n;
    char buff[100];
    heap_size = 0;
   
	while(scanf("%s %d\n", buff, &n)>0) {
		if(buff[2] == 'd') break;
		switch(buff[2]) {
			case 's': // insert
				maxHeapInsert(heap, n);
				break;
			case 't': // extract
				printf("%d\n", heapExtractMax(heap));
				break;
		}
	}

    return 0;
}
