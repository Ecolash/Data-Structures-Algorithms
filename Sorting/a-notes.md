|< SORTING ALGORITHMS >|


--------------------
!-<SELECTION SORT>-!
--------------------

Selection Sort: The selection sort algorithm divides the array into two parts: the sorted part at the beginning and the unsorted part at the end. Initially, the sorted part is empty, and the unsorted part contains all the elements. With each iteration, the smallest element from the unsorted part is selected and moved to its correct position in the sorted part.

Selection sort is an in-place sorting algorithm, meaning it doesn't require additional memory beyond the original array. However, it is not a stable sorting algorithm, as the relative order of equal elements may change during the sorting process.


Time Complexity:
----------------

Best Case: O(n^2)
Average Case: O(n^2)
Worst Case: O(n^2)

Space Complexity:
-----------------

Space complexity: O(1)



The time complexity of selection sort is O(n^2) in the worst case, where n is the number of elements in the array. This is because the algorithm requires two nested loops to compare and swap elements. However, it has a relatively simple implementation and can be efficient for small input sizes or partially sorted arrays.

<selection_sort1.cpp>  | SELECTION SORT (Ascending order)
<selection_sort2.cpp>  | SELECTION SORT (Descending order)
<selection_sort3.cpp>  | 



-----------------
!-<BUBBLE SORT>-!
-----------------

Bubble Sort: The idea behind bubble sort is that in each pass, the largest unsorted element "bubbles" up to its correct position at the end of the list. The algorithm repeats this process until the entire list is sorted in ascending order.

Bubble sort is known for its simplicity, but it can be inefficient for large lists. It has a worst-case time complexity of O(n^2), where n is the number of elements in the list. In the best-case scenario, where the list is already sorted, bubble sort can achieve a time complexity of O(n) by making a single pass through the list without any swaps.


Time Complexity:
----------------

Best Case: O(n)
Average Case: O(n^2)
Worst Case: O(n^2)

Space Complexity:
-----------------

Space complexity: O(1)

Despite its simplicity, bubble sort is not often used for large datasets due to its relatively slow performance compared to more efficient sorting algorithms like merge sort or quicksort. However, it can still be useful for small lists or in cases where simplicity and ease of implementation are more important than efficiency.

<bubble_sort1.cpp>  | BUBBLE SORT (Ascending order)
<bubble_sort2.cpp>  | BUBBLE SORT (Descending order)




--------------------
!-<INSERTION SORT>-!
--------------------

Insertion Sort: The insertion sort algorithm builds the sorted part of the array incrementally by inserting each element in its correct position. At each iteration, the algorithm shifts the elements greater than the key to the right to make space for the key's insertion. Insertion sort is known for its efficiency when the input array is partially sorted or has a small number of elements. It has several advantages, such as simplicity, stability (the relative order of equal elements is maintained), and the ability to sort the array in-place without requiring additional memory.

Time Complexity:
----------------

Best Case: O(n)
Average Case: O(n^2)
Worst Case: O(n^2)

Space Complexity:
-----------------

Space complexity: O(1)

The time complexity of insertion sort is O(n^2) in the worst and average cases, where n is the number of elements in the array. However, in the best case scenario where the array is already sorted, insertion sort has a time complexity of O(n) because no element shifts are required.

Overall, insertion sort is a useful sorting algorithm for small or partially sorted arrays, but it becomes less efficient for larger input sizes compared to more advanced sorting algorithms like merge sort or quicksort.          


<insertion_sort1.cpp>  | INSERTION SORT (Ascending order)
<insertion_sort2.cpp>  | INSERTION SORT (Descending order)




----------------
!-<MERGE SORT>-!
----------------

Merge Sort: The merging step is a key operation in merge sort. It involves comparing elements from the two sorted halves and placing them in the correct order in a temporary array. After merging, the temporary array is copied back to the original array. Merge sort has the following time and space complexities:

Time Complexity:
----------------

Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)


Space Complexity:
-----------------

Space complexity: O(n)

It requires additional memory to store the temporary arrays during the merging process. The amount of additional memory required is proportional to the size of the input array. Merge sort has a stable sorting behavior, meaning that the relative order of equal elements is preserved during the sorting process. It is also an out-of-place sorting algorithm, as it requires additional memory for merging the subarrays.

<merge_sort1.cpp>  | MERGE SORT (Ascending order)
<merge_sort2.cpp>  | MERGE SORT (Descending order)



----------------
!-<QUICK SORT>-!
----------------

Quick Sort: Quick sort is a widely used sorting algorithm that follows the divide-and-conquer strategy. It works by selecting a pivot element from the array and partitioning the other elements into two subarrays, according to whether they are less than or greater than the pivot. The process is recursively applied to the subarrays until the entire array is sorted.

Time Complexity:
----------------

Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n^2)


Space Complexity:
-----------------

Average Case: O(log n)
Worst Case: O(n)

Quick sort has an average and best-case time complexity of O(n log n), where n is the number of elements in the array. This makes it one of the fastest sorting algorithms for large datasets. However, in the worst case, which occurs when the pivot is consistently the smallest or largest element, the time complexity is O(n^2). This worst-case scenario can be mitigated by using randomized pivot selection or choosing a median-of-three pivot.

The space complexity of quick sort is O(log n) in the average case, as it requires auxiliary space for recursive function calls. However, in the worst case, when the recursion depth is equal to the number of elements in the array, the space complexity becomes O(n). This worst-case scenario can be avoided by using an in-place partitioning algorithm.

Quick sort is an efficient and widely used sorting algorithm due to its average-case performance and the ability to sort in-place. It is commonly used in practice and forms the basis for various other algorithms and applications.


<quick_sort1.cpp>  | QUICK SORT (Ascending order)
<quick_sort2.cpp>  | QUICK SORT (Descending order)