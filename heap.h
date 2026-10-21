#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <cstddef>

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
  int m;
  PComparator comp; 



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m(m), comp(c) {
  if(m < 2) {
    throw std::invalid_argument("Heap arity must be at least 2");
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() = default;

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data.empty();
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
  return data[0];


}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data.push_back(item);
  size_t child = data.size() - 1;

  //Move the new item upward while it has priority over its parent
  while (child > 0){
    size_t parent = (child - 1) / m;

    if(!comp(data[child], data[parent])) {
      break;
    }
    T temp = data[child];
    data[child] = data[parent];
    data[parent] = temp;

    child = parent;
  }
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
  if(data.size() == 1) {
    data.pop_back();
    return;
  }
  //Move the last item to the root
  data[0] = data.back();
  data.pop_back();

  size_t parent = 0;

  //Move the new root downward till the heap is valid
  while(true) {
    size_t firstChild = m * parent + 1;
    if(firstChild >= data.size()) {
      break;
    }
    //Find the child with the highest priority
    size_t bestChild = firstChild;
    size_t endChild = firstChild + m;

    if(endChild > data.size()) {
      endChild = data.size();
    }
    for(size_t child = firstChild + 1; child < endChild; child++) {
      if(comp(data[child], data[bestChild])) {
        bestChild = child;
      }
    }
    //Stop if the parent already has priority
    if(!comp(data[bestChild], data[parent])) {
      break;
    }
    T temp = data[parent];
    data[parent] = data[bestChild];
    data[bestChild] = temp;

    parent = bestChild;
  }



}



#endif

