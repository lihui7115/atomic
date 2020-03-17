#include <boost/atomic.hpp>
#include <thread>
#include <iostream>

boost::atomic<int> a{0};
int b = 0;

void thread1()
{
  b = 1;
  a.store(1, boost::memory_order_release);

  // Memory accesses that appear in the code before the boost::memory_order_release statement
  // are executed before the boost::memory_order_release statement is executed.

  // Compilers and processors must not move memory accesses from before to after boost::memory_order_release.
  // However, they may move memory accesses from after to before boost::memory_order_release.
  
  // uses boost::memory_order_release in the first thread to make sure that b is set to 1
  // before a is set to 1. boost::memory_order_release guarantees that the memory access on b occurs
  // before the memory access on a.


}

void thread2()
{
  while (a.load(boost::memory_order_acquire) != 1)
    ;
  std::cout << b << '\n';
}

int main()
{
  std::thread t1{thread1};
  std::thread t2{thread2};
  t1.join();
  t2.join();
}
