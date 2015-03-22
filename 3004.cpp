#include <stdio.h>
#include <vector>

using namespace std;

#define SIZE_MAX_1 100001
#define SIZE_MAX_2 10001

int n, k, tmp, que_input[SIZE_MAX_1], size;
long long heap[SIZE_MAX_2], answer = 0, maximal = -1;

void heap_heapify(int index)
{
   if (index*2 + 1 <= size)
   {
       tmp = index*2 + (heap[index*2] > heap[index*2 + 1]);
       if (heap[index] > heap[tmp])
       {
           swap(heap[index], heap[tmp]);    
           heap_heapify(tmp);
       }
   }
   else if (index*2 <= size && heap[index] > heap[index*2])
   {
       swap(heap[index], heap[index*2]);
       heap_heapify(index*2);
   }
}

void heap_push(int x)
{
   size++;
   heap[size] = x;
   
   tmp = size;
   while(tmp != 1 && heap[tmp] < heap[tmp / 2])
   {
       swap(heap[tmp], heap[tmp / 2]);
       tmp /= 2;
   }
}

void heap_pop()
{
   heap[1] = heap[size];
   size--;
   heap_heapify(1);
}

void heap_multiple_add(long long x)
{
   for (int i = 1; i<=size; i++) heap[i] +=x;
}

int main()
{
    scanf("%d %d\n", &n, &k);
   
    for (int i = 0; i<n; i++) scanf("%d ", &que_input[i]);
   
    if (k <= n)
    {
        for (int i = 0; i < k; i++) heap_push(que_input[i]);
        for (int i = k; i < n; i++) 
        {
           heap[1] += que_input[i];
           heap_heapify(1);
        }
       
        answer += heap[1];
        heap_multiple_add(-heap[1]);
        /*while(size)
        {
            answer += heap[1];
            heap_multiple_add(-heap[1]);
            heap_pop();
        }*/
        for (int i = 1; i<=size; i++) maximal = max(maximal, heap[i]);
        answer += maximal;
    }    
    else
    {
        for (int i = 0; i<n; i++) answer = max(answer, (long long)que_input[i]);
    }
   
    printf("%lld\n", answer);
}