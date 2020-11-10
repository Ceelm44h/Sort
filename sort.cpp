#include <iostream>
#include <vector>

void swap(int* x, int* y)
{
    int bufor = *y;
    *y = *x;
    *x = bufor;
}

class Heap
{
    void buildHeap()
    {
        for(int i = numbers.size()/2 - 1; i >= 0; --i)
            heapify(i, numbers.size());
    }

    void heapify(int i, int size)
    {
        int max = i, left = 2*i + 1, right = 2*i + 2;
        if(left < size && numbers[left] > numbers[max])
            max = left;
        
        if(right < size && numbers[right] > numbers[max])
            max = right;

        if(max != i)
        {
            swap(&numbers[i], &numbers[max]);
            heapify(max, size);
        }
    }

public:
    std::vector<int> numbers;

    Heap(std::vector<int>* numbersToCopy)
    {
        numbers = *numbersToCopy;
    }

    std::vector<int>& heapSort()
    {
        buildHeap();

        for(int i = numbers.size() - 1; i >= 1; --i)
        {
            swap(&numbers[0], &numbers[i]);
            heapify(0, i);
        }

        return numbers;
    }
};

class Sort
{
    private:
    
    std::vector<int> numbers = {6, 12, 5, 6, 21, 42, 1, 13, 33, 2};
    
    public:
    int numbersSize = numbers.size();

    void insertionSort()
    {
        for(int i = 1; i <= numbers.size(); ++i)
        {
            int element = numbers[i], j = i - 1;

            while(j >= 0 && numbers[j] > element)
            {
                numbers[j+1] = numbers[j];
                j--;
            }

            numbers[j+1] = element;
        }
    }

    void mergeSort(int left, int right)
    {
        if(left < right)
        {
            int mid = (left + right) / 2;

            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    void merge(int left, int mid, int right)
    {
        int sizeFirst = mid - left + 1, sizeSecond = right - mid;
        int arrLeft[sizeFirst], arrRight[sizeSecond];

        for(int i = 0; i < sizeFirst; ++i)
            arrLeft[i] = numbers[left + i];
        
        for(int i = 0; i < sizeSecond; ++i)
            arrRight[i] = numbers[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while(i < sizeFirst && j < sizeSecond)
        {
            if(arrLeft[i] > arrRight[j])
            {
                numbers[k] = arrRight[j];
                j++; 
            }
            else
            {
                numbers[k] = arrLeft[i];
                i++;
            }
            k++;
        }

        while(i < sizeFirst)
        {
            numbers[k] = arrLeft[i];
            k++;
            i++;
        }

        while(j < sizeSecond)
        {
            numbers[k] = arrRight[j];
            k++;
            j++;
        }
        
    }

    void heapSort()
    {
        Heap heap(&numbers);
        numbers = heap.heapSort();
    }

    bool verify()
    {
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(numbers[i] > numbers[i+1])
                return false;                       
        }

        return true;
    }

    void display()
    {
        for(auto element : numbers)
        {
            std::cout << element << " ";
        }

        std::cout << std::endl;
    }
};

int main()
{
    Sort sort;
    sort.display();

    //sort.insertionSort();
    //sort.mergeSort(0, sort.numbersSize - 1);
    sort.heapSort();
    
    std::cout << sort.verify() << std::endl;
    sort.display();

    return 0;
}