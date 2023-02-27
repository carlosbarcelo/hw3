#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
  std::vector<T> data_;
  PComparator comp_;
  int m_;

  int smallChild(int pi) const;

  void heapifyUp(int i);
  void heapifyDown(int i);

  int parent(int ci) const;
  int kthChild(int pi, int k) const;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  m_ = m;
  comp_ = c;
  if(m < 2){
    m = 2;
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
  
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
  return data_[0];
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
  data_.front() = data_.back();
  data_.pop_back();
  heapifyDown(0);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data_.push_back(item);
  heapifyUp(int(data_.size())-1);
}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return data_.size();
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return data_.empty();
}

template <typename T, typename PComparator>
int Heap<T,PComparator>::kthChild(int pi, int k) const {
  return m_ * pi + k;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(int i){
  int child;
  T temp = data_[i];
  while (kthChild(i, 1) < int(data_.size())){
    child = smallChild(i);
    if (comp_(data_[child], temp)){
      data_[i] = data_[child];
    }
    else{
      return;
    }
    i = child;
  }
  data_[i] = temp;
}

template <typename T, typename PComparator>
int Heap<T,PComparator>::parent(int i) const {
  return (i -1) / m_;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(int i){
  T temp = data_[i];
  while (i > 0 && comp_(temp, data_[parent(i)])){
    data_[i] = data_[parent(i)];
    i = parent(i);
  }
  data_[i] = temp;
}

template <typename T, typename PComparator>
int Heap<T,PComparator>::smallChild(int pi) const {
  int best = kthChild(pi, 1);
  if (best >= int(data_.size())){
    return -1;
  }
  for(int k = 2; k <= m_; k++){
    int child = kthChild(pi, k);
    if (child < int(data_.size()) && comp_(data_[child], data_[best])){
      best = child;
    }
  }
  return best;
}


#endif

