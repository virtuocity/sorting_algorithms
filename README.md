# 0x1B. C - Sorting algorithms & Big O

## Notes
a sorting algorithm is an algorithm that puts elements of a list into an order.  
The most frequently used orders are *numerical* order and *lexicographical* order, and either ascending or descending. Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) that require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output.  
For optimum efficiency, the input data should be stored in a data structure which allows random access rather than one that allows only sequential access.  
### Big O Notation
Big Oh notation is a relative representation of the complexity of an algorithm.  
+ relative: you can only compare apples to apples. You can't compare an algorithm that does arithmetic multiplication to an algorithm that sorts a list of integers. But a comparison of two algorithms to do arithmetic operations (one multiplication, one addition) will tell you something meaningful;
+ representation: BigOh (in its simplest form) reduces the comparison between algorithms to a single variable. That variable is chosen based on observations or assumptions. For example, sorting algorithms are typically compared based on comparison operations (comparing two nodes to determine their relative ordering). This assumes that comparison is expensive. But what if the comparison is cheap but swapping is expensive? It changes the comparison; and 
+ complexity: if it takes me one second to sort 10,000 elements, how long will it take me to sort one million? Complexity in this instance is a relative measure to something else.

O(n) - Linear complexity as in when traversing a list  
O(n²) - Quadratic complexity as in a nested loop or calculating n*n  
O(logn) - when halving a problem e.g binary search.   
    In BigOh terms this is O(log n) or **logarithmic complexity**. Now the logarithm in question could be ln (base e), log10, log2 or some other base. It doesn't matter it's still O(log n) just like O(2n2) and O(100n2) are still both O(n2).  
It's worthwhile at this point to explain that BigOh can be used to determine three cases with an algorithm:  
+ Best Case: In the telephone book search, the best case is that we find the name in one comparison. This is O(1) or **constant complexity**;  
+ Expected/Average Case: As discussed above this is O(log n); and
Worst Case: This is also O(log n).
### The Traveling Salesman
This is quite a famous problem in computer science and deserves a mention. In this problem, you have N towns. Each of those towns is linked to 1 or more other towns by a road of a certain distance. The Traveling Salesman problem is to find the shortest tour that visits every town.

Sounds simple? Think again.  

If you have 3 towns A, B, and C with roads between all pairs then you could go:  

+ A → B → C
+ A → C → B
+ B → C → A
+ B → A → C
+ C → A → B
+ C → B → A

Take this to 4 towns and you have 12 possibilities.
With 5 it's 60.
6 becomes 360
This makes a factorial or combinatorial complexity:   
**O(n!)**  

### Quicksort Algorithm
Is a divide and conquer algorithm  
The key process in quickSort is a **partition()**. The target of partitions is, given an array and an element x of an array as the pivot, put x at its correct position in a sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.  

### Pseudo Code for recursive QuickSort function:
/* low  –> Starting ,  high  –> Ending index array*/ 
```c
quickSort(arr[], low, high) {  
    if (low < high) {  

        /* pi is partitioning index, arr[pi] is now at right place */  

        pi = partition(arr, low, high);  

        quickSort(arr, low, pi – 1);  // Before pi    

        quickSort(arr, pi + 1, high); // After pi

    }

}
```

### Pseudo code for partition()  

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */

```c
partition (arr[], low, high)
{
    // pivot (Element to be placed at right position)
    pivot = arr[high];  

    i = (low – 1)  // Index of smaller element and indicates the 
    // right position of pivot found so far

    for (j = low; j <= high- 1; j++){

        // If current element is smaller than the pivot
        if (arr[j] < pivot){
            i++;    // increment index of smaller element
            swap arr[i] and arr[j]
        }
    }
    swap arr[i + 1] and arr[high])
    return (i + 1)
}
```
### Lomuto’s Partition Scheme - In Quicksort:

This algorithm works by assuming the pivot element as the last element. If any other element is given as a pivot element then swap it first with the last element. 

### Hoare’s Partition Scheme:
works by initializing two indexes that start at two ends, the two indexes move toward each other until an inversion is (A smaller value on the left side and greater value on the right side) found. When an inversion is found, two values are swapped and the process is repeated.


## Links
+ Sorting Algorithm  
https://en.wikipedia.org/wiki/Sorting_algorithm  
+ Big O Notation  
https://stackoverflow.com/questions/487258/what-is-a-plain-english-explanation-of-big-o-notation  
+ All about sorting algorithms  
https://www.geeksforgeeks.org/sorting-algorithms/  
+ CS50 Algorithms explanation in detail by David Malan  
https://www.youtube.com/watch?v=yb0PY3LX2x8&t=2s  
+ Computational complexity of Fibonacci Sequence
https://stackoverflow.com/questions/360748/computational-complexity-of-fibonacci-sequence  
+ Hoare’s vs Lomuto partition scheme in QuickSort
https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/  