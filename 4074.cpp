#include <stdio.h>
#include <vector>

using namespace std;

#define SIZE 1000000

int n, tmp_scanf, tmp, size = 0, heap_min[SIZE], heap_max[SIZE], middle;

void heap_min_heapify(int index)
{
   if (index*2 + 1 <= size)
   {
       tmp = index*2 + (heap_min[index*2] > heap_min[index*2 + 1]);
       if (heap_min[index] > heap_min[tmp])
       {
           swap(heap_min[index], heap_min[tmp]);    
           heap_min_heapify(tmp);
       }
   }
   else if (index*2 <= size && heap_min[index] > heap_min[index*2])
   {
       swap(heap_min[index], heap_min[index*2]);
       heap_min_heapify(index*2);
   }
}

void heap_min_push(int x)
{
   heap_min[size] = x;
   
   tmp = size;
   while(tmp != 1 && heap_min[tmp] < heap_min[tmp / 2])
   {
       swap(heap_min[tmp], heap_min[tmp / 2]);
       tmp /= 2;
   }
}

void heap_max_heapify(int index)
{
   if (index*2 + 1 <= size)
   {
       tmp = index*2 + (heap_max[index*2] < heap_max[index*2 + 1]);
       if (heap_max[index] < heap_max[tmp])
       {
           swap(heap_max[index], heap_max[tmp]);    
           heap_max_heapify(tmp);
       }
   }
   else if (index*2 <= size && heap_max[index] < heap_max[index*2])
   {
       swap(heap_max[index], heap_max[index*2]);
       heap_max_heapify(index*2);
   }
}

void heap_max_push(int x)
{
   heap_max[size] = x;
   
   tmp = size;
   while(tmp != 1 && heap_max[tmp] > heap_max[tmp / 2])
   {
       swap(heap_max[tmp], heap_max[tmp / 2]);
       tmp /= 2;
   }
}

int main()
{
    for (n = 1; scanf("%d\n", &tmp_scanf) != EOF; n++)
    {
        if (n == 1) 
        {
            middle = tmp_scanf;
            printf("%d\n", middle);
        }
        else if (n % 2)
        {
            middle = tmp_scanf;
            if (middle < heap_max[1]) 
            {
                swap(middle, heap_max[1]);
                heap_max_heapify(1);
            }
            else if (middle > heap_min[1]) 
            {
                swap(middle, heap_min[1]);
                heap_min_heapify(1);
            }

            printf("%d\n", middle);
        }
        else
        {
            if (middle > tmp_scanf) swap(middle, tmp_scanf);
            size++;
            heap_max_push(middle);
            heap_min_push(tmp_scanf);

            printf("%d\n", heap_max[1]/2 + heap_min[1]/2 + (heap_max[1]%2 + heap_min[1]%2)/2);
        }
    }
}