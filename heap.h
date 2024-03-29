#ifndef HEAP_H
#define HEAP_H
// include the vector class for further use
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();
  
  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int ary;
  PComparator comp;

  void trickleUp(size_t idx);

  void trickleDown(size_t idx);


};

// Add implementation of member functions here
template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : ary(m), comp(c), data() {
    // Constructor implementation
}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
    // No need to manually delete or clear the vector `data`,
    // as its destructor will automatically take care of that.
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return data.empty();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    data.push_back(item);
    trickleUp(data.size() - 1);
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return data.size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }

  data.front() = data.back();
  data.pop_back();
  trickleDown(0);

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t idx) {
    while (idx > 0) {
        size_t parentIdx = (idx - 1) / ary;
        if (comp(data[idx], data[parentIdx])) {
            std::swap(data[idx], data[parentIdx]);
            idx = parentIdx;
        } else {
            break;
        }
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(size_t idx) {
    size_t childIdx = ary * idx + 1;
    while (childIdx < data.size()) {
        // Find the smallest/largest among the node and all its children
        size_t minMaxIdx = idx;
        for (int i = 0; i < ary && i + childIdx < data.size(); ++i) {
            if (comp(data[childIdx + i], data[minMaxIdx])) {
                minMaxIdx = childIdx + i;
            }
        }
        // If the smallest/largest is not the parent, swap and continue
        if (minMaxIdx != idx) {
            std::swap(data[idx], data[minMaxIdx]);
            idx = minMaxIdx;
            childIdx = ary * idx + 1;
        } else {
            break;
        }
    }
}

#endif

