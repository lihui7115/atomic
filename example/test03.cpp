#include <boost/atomic.hpp>
#include <thread>
#include <iostream>

boost::atomic<int> a{0};

void thread()
{

//enum class memory_order : unsigned int
//{
//    relaxed = 0,
//    consume = 1,
//    acquire = 2,
//    release = 4,
//    acq_rel = 6, // acquire | release
//    seq_cst = 14 // acq_rel | 8
//};

//BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_relaxed = memory_order::relaxed;
//BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_consume = memory_order::consume;
//BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_acquire = memory_order::acquire;
//BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_release = memory_order::release;
//BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_acq_rel = memory_order::acq_rel;
//BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_seq_cst = memory_order::seq_cst;
//

//  a.fetch_add(1, boost::memory_order_seq_cst);   // sequential consistency
  std::cout << std::this_thread::get_id() << " begin:" << a.load() << std::endl;
  int a1 = a.fetch_add(1);
  std::cout << std::this_thread::get_id() << " fetch_add:" << a1 << std::endl;
  int a2 = a++;
  std::cout << std::this_thread::get_id() << " post++:" << a2 << std::endl;
}

int main()
{
  std::thread t1{thread};
  std::thread t2{thread};
  t1.join();
  t2.join();
  std::cout << a << '\n';
}
