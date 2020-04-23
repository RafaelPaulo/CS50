# Algorithms

## Week 3

### Topics

- C - `typeef struct`
- Recursion
- [Linear Search](#linear-search)
- Binary Search
- Sort Algorithms
    - Bubble Sort
    - Selection Sort
    - Insertion Sort
    - Merge Sort

### **Linear Search**

**Iterate across a data structure from left to right, searching for a specificied element.**

**In pseudocode**:

- Repeat, starting at the first element:
    - if the first element is what you're looking for (target), stop.
    - Otherwise, move to the next element

#### Complexity

| Worse-case | Best-case |
|------------|-------------------|
| O(n): look at every single element | Ω(1): find the element immediately as the first element|
