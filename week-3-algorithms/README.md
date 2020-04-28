# Algorithms

## Week 3

### Topics

- C - `typeef struct`
- Recursion
- [Linear Search](#linear-search)
- [Binary Search](#binary-search)
- Sort Algorithms
    - [Bubble Sort](#bubble-sort)
    - [Selection Sort](#selection-sort)
    - Insertion Sort
    - Merge Sort

---

### **Linear Search**

**Iterate across a data structure from left to right, searching for a specificied element.**

**In pseudocode**:

- Repeat, starting at the first element:
    - If the first element is what you're looking for (target), stop.
    - Otherwise, move to the next element.

![linear search](./assets/linear-search.gif)

#### Complexity

| Worse-case | Best-case |
|------------|-------------------|
| O(n): look at every single element | Ω(1): find the element immediately as the first element|

### **Binary Search**

**In binary search, the idea of the algorithm is to divide and conquer, reducing the search area by half each time, trying to find a target number.**

**The data structure must be sorted, because everything to the left must be lower than the right side.**

**In pseudocode**:

- Repeat until the there is no way to divide the data structure:
    - Calculate de middle point of the current sub(array).
    - If the target is at the middle, stop.
    - Otherwise, if the target is less than what's at the middle, repeat, changing the end point to be just to the left of the middle.
    - Otherwise, of the target is greater than what's at the middle, repeat, changing the start point to be just to the right of the middle.

![binary search](./assets/binary-search.jpg)

#### Complexity

| Worse-case | Best-case |
|------------|-------------------|
| O(log n): Divide that array on `log of n` time when the element does not exist or is at the last division. | Ω(1): The element being searched is at the first half of the array.|


### **Bubble Sort**

**The idea of the algorithm is to move higher valued elements generally towards the right and lower values elements generally towards the left.**

**In pseudocode**:
    - Set swap counter to a non-zero value
    - Repeat until the swap counter is 0:
        - reset swap counter to 0
        - look at each adjacent pair
            - if two adjacent elements are not in order, swap them and add one to the swap counter

![bubble sort gif](./assets/bubble-sort.gif)

#### Complexity

| Worse-case | Best-case |
|------------|-------------------|
| O(n²): To have to move/swap all the `n` elements. | Ω(n): In case of all elements are already sorted, and not having to swap any element.|

### **Selection Sort**

**The idea of the algorithm is to find the smallest unsorted element and add it to the end of the sorted list.**

**Effectively what this algorithm does is build a sorted list one element at a time.**

**In pseudocode**:
    - Repeat until no unsorted elements remain:
        - Search the unsorted part of the data to find the smallest value
        - Swap the smallest found value with the first element of the unsorted part.

![selection sort gif](./assets/selection-sort.gif)

#### Complexity

| Worse-case | Best-case |
|------------|-----------|
| O(n²): To look over all the elements of the array to find the smallest unsorted element, and repeat that `n` times. | Ω(n²): Same as Worse-case scenario :( |
