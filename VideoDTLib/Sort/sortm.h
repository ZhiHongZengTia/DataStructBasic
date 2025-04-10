#ifndef SORTM_H
#define SORTM_H

#include "object.h"
#include "arraym.h"

namespace DTLib
{

class SortM: public Object
{
private:
    SortM();  // 说明不可能创建对象，可以调用static 函数
    SortM(const SortM&);
    SortM& operator= (const SortM&);

    template <typename T>
    static void Swap(T& a, T& b)
    {
        T c(a);
        a =b;
        b= c;
    }


public:

    template <typename T>
    static void SelectSort(T array[], int len, bool min2max = true)  // default: min to max
    {
        for(int i = 0; i < len; ++i)
        {
            int min = i;
            for(int j = i+1 ; j< len; ++j)
            {
                if( min2max ? (array[min] > array[j]) :  (array[min] < array[j]) )
                {
                    min = j;
                }
            }
            if(i != min)  //
            {
                Swap(array[i], array[min]);
            }
        }
    }

    template <typename T>
    static void InsertSort(T array[], int len, bool min2max = true)  // default: min to max
    {
        for(int i = 0 ; i <len ; ++i)
        {
            int k = i;
            T e  = array[i];
            for(int j = i-1; (j>=0) && ( min2max ? (array[j] > e) : (array[j] < e) ); --j)
            {
                array[j+1] = array[j];
                k = j;
            }
            if(k!= i)
            {
                array[k] = e;
            }
        }
    }

    template <typename T>
    static void BubbleSort(T array[], int len, bool min2max = true)  // default: min to max
    {
        bool exchangeFlag  = true;
        for(int i = 0 ; (i <len) && exchangeFlag; ++i )
        {
            exchangeFlag = false;
            for(int j = len -1; j>i ;j--)
            {
                if(  min2max ? (array[j] < array[j-1]) :  (array[j] > array[j-1]))
                {
                    Swap(array[j],array[j -1]);
                    exchangeFlag = true;
                }
            }
        }
    }

    template <typename T>
    static void ShellSort(T array[], int len, bool min2max = true)  // default: min to max
    {
        int d = len;
        do
        {
            d = d/3 + 1;  // or d--

            for(int i = d; i<len; i+=d)
            {
                int k = i;
                T e  = array[i];
                for(int j = i-d; (j>=0) && ( min2max ? (array[j] > e) : (array[j] < e) ); j-=d)
                {
                    array[j+d] = array[j];
                    k = j;
                }
                if(k!= i)
                {
                    array[k] = e;
                }
            }

        }while ( d > 1);
    }

    template <typename T>
    static void MergeSort(T src[], T helper[],int begin,int mid, int end, bool min2max = true)  // default: min to max
    {
        int i = begin;
        int j = mid+1;
        int k = begin;
        while( (i<= mid) && (j<=end) )
        {
            if( min2max ? (src[i] < src[j]) : (src[i] > src[j]) )
            {
                helper[k] = src[i];
                k++;
                i++;
            }
            else
            {
                helper[k] = src[j];
                k++;
                j++;
            }
        }


        while( i<= mid)
        {
            helper[k] =src[i];
            k++;
            i++;
        }
        while( j<= end)
        {
            helper[k] =src[j];
            k++;
            j++;
        }

        for(i = begin; i<=end; ++i)
        {
            src[i] = helper[i];
        }
    }

    template <typename T>
    static void MergeSort(T src[], T helper[],int begin, int end, bool min2max = true)  // default: min to max
    {
        if(begin < end)
        {
            int mid = (begin + end)/2;

            MergeSort(src,helper,begin,mid,min2max);
            MergeSort(src,helper,mid+1,end,min2max);

            MergeSort(src,helper,begin,mid,end,min2max);
        }
    }

    template <typename T>
    static void MergeSort(T array[], int len, bool min2max = true)  // default: min to max
    {
     T* helper = new T(len);
     if(helper != nullptr)
     {
        MergeSort(array,helper,0,len-1,min2max);
     }
     delete[] helper;
    }


    template <typename T>
    static int Partition(T array[], int begin, int end, bool min2max = true)
    {
        T pv = array[begin];
        while( begin < end)
        {
            while( (begin < end) && ( min2max ? (array[end] > pv) : (array[end] < pv ))    )
            {
                end--;
            }
            Swap(array[begin], array[end]);
            while(begin < end && ( min2max ?  (array[begin] <= pv) : (array[begin] >= pv) ) )
            {
                begin ++;
            }
            Swap(array[begin], array[end]);
        }
        array[begin] = pv;
        return begin;
    }

    template <typename T>
    static void QuickSort(T array[], int begin,int end, bool min2max = true)  // default: min to max
    {
        if(begin < end)
        {
            int  pivot = Partition(array,begin,end,min2max);
            QuickSort(array,begin,pivot-1,min2max);
            QuickSort(array,pivot+1,end,min2max);
        }

    }

    template <typename T>
    static void QuickSort(T array[], int len, bool min2max = true)  // default: min to max
    {
        QuickSort(array,0,len-1,min2max);
    }




    template <typename T>
    static void SelectSortForArray(ArrayM<T>& arr, bool min2max = true )
    {
        SelectSort(arr.array(), arr.length(), min2max);  // default: min to max
    }

    template <typename T>
    static void InsertSortForArray(ArrayM<T>& arr, bool min2max = true)
    {
        InsertSort(arr.array(), arr.length(), min2max);  // default: min to max
    }

    template <typename T>
    static void BubbleSortForArray(ArrayM<T>& arr, bool min2max = true)
    {
        BubbleSort(arr.array(), arr.length(), min2max);  // default: min to max
    }

    template <typename T>
    static void ShellSortForArray(ArrayM<T>& arr, bool min2max = true)
    {
        ShellSort(arr.array(), arr.length(), min2max);  // default: min to max
    }

    template <typename T>
    static void MergeSortForArray(ArrayM<T>& arr, bool min2max = true)
    {
        MergeSort(arr.array(), arr.length(), min2max);  // default: min to max
    }

    template <typename T>
    static void QickSortForArray(ArrayM<T>& arr, bool min2max = true)
    {
        QuickSort(arr.array(), arr.length(), min2max);  // default: min to max
    }


};

}

#endif // SORTM_H
