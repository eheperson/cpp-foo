# STL Tutorials

## Notes
- If you know the size of the data use `std::array`, if you don't use `std::vector`.
- `std::array`'s are for fast access, `std::vector`'s are for dynamicly changing sizes.
- `insert()` and `emplace()` is equal for premetive data-types but when we deal with heavy objects we should use `emplace()` if we can for efficiency.
- You should use `std::forward_list` instead of `traditional single-linked-list`, because it is **well tested** and it has **bunch of available functions**.
- If you want to use `unique()` method, you have to use `sort()` before using `unique()`, because `unique()` removes only adjacent-duplicates.

---

* **STL :** Standard Template Library
* It consist of three elements : 
  * **Container :** Containers are used to manage collections of objects of a certain kind.
  * **Iterator :** Iterators are used to step through the elements of collections of objects.
  * **Algorithm :** Algorithms act on container.
  
---

## Containers

### Sequence Containers:
`Sequence containers implement data structures that can be accessed sequentially.`
* **Array :** Static contiguous array (class template)
* **Vector :** Dynamic contiguous array (class template)
* **Deque :** Double-ended queue (class template)
* **Forward List :** Singly-linked list (class template)
* **List :** Doubly-linked list (class template)

## Associative Containers
`Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).`
* **Set :** Collection of unique keys, sorted by keys (class template)
* **Multiset :** Collection of keys, sorted by keys (class template)
* **Map :** Collection of key-value pairs, sorted by keys, keys are unique (class template).
* **Multimap:** Collection of key-value pairs, sorted by keys (class template)

## Unordered Associative Containers
`Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) amortized, O(n) worst-case complexity). `
* **Unordered Set :** Collection of unique keys, hashed by keys. (class template)
* **Unordered Multset :** Collection of key-value pairs, hashed by keys, keys are unique. (class template)
* **Unordered Map :** Collection of keys, hashed by keys (class template)
* **Unordered Multimap:** Collection of key-value pairs, hashed by keys (class template)

## Adaptive Containers (Container Adaptors)
`Container adaptors provide a different interface for sequential containers. `
* **Stack :** Adapts a container to provide stack (LIFO data structure) (class template).
* **Queue :** Adapts a container to provide queue (FIFO data structure) (class template).
* **Priority Queue :** Adapts a container to provide priority queue (class template). 

## Iterators
stl iterators info goes here 

## Algorithms
stl algorithms info goes here 
