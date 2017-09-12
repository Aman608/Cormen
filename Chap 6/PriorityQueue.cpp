#include<bits/stdc++.h>
using namespace std;
int left(int i)
{
    return (2*i + 1);
}
int right(int i)
{
    return (2*i+2);
}
int parent(int i)
{
    return (i-1)/2;
}
void swap(int *a, int*b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
class Priority_queue
{
	private:
		vector<int> a;
		int heap_size;
		void increase_key(int i, int key)
		{
			if(a[i]>key)
				return;
			else
				a[i] = key;
				while(i>=0 && a[parent(i)] < a[i])
				{
					swap(&a[parent(i)], &a[i]);
					i = parent(i);
				}
		}
	public:
		Priority_queue() : heap_size(0) {}

        int size()
        {
            return heap_size;
        }
		void max_heapify_iterative(int i,int n)
		{

			while(true)
			{

				int l = left(i);
				int largest;
				int r = right(i);


				if(l < n && a[l]>a[i])
					largest = l;
				else
					largest = i;
				if(r<n && a[r] > a[largest])
					largest = r;

				if(largest!=i)
					{swap(&a[largest], &a[i]);
						i = largest;
					}
				else
					break;
			}
		}
		void build_heap()
		{
			int n = heap_size/2 + 1;
			for(int i=n; i>=0;i--)
				this->max_heapify_iterative(i,n);
		}
		void heap_sort()
		{

			this->build_heap();
			for(int i= heap_size-1;i>=1;i--)
			{
				swap(&a[0], &a[i]);
				this->max_heapify_iterative(0,i);
			}
		}
		int heap_max()
		{
			return a[0];
		}

		int heap_extract_max()
		{
			int maxima;
			if(heap_size<1)
				return 0;
			else
				maxima = this->heap_max();
				swap(&a[0], &a[heap_size-1]);

				heap_size = heap_size-1;
				this->max_heapify_iterative(0,heap_size);
				return maxima;
		}



		void insert_key(int key)
		{
			heap_size+=1;
			a.push_back(INT_MIN);
			this->increase_key(heap_size-1, key);

		}

};



int main()
{
    Priority_queue p1;
    p1.insert_key(3);
    p1.insert_key(6);
    p1.insert_key(10);
    p1.insert_key(5);
    p1.insert_key(90);
    p1.insert_key(55);

   while(p1.size()!=0)
   {
       cout << p1.heap_extract_max() << endl;
   }
}
