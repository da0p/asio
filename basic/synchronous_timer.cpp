#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <iostream>

int
main()
{
  // All programs that use asio need to have at least one I/O execution context
  // such as an io_context or thread_pool object. An I/O execution context
  // provides access to I/O functionality.
  boost::asio::io_context io;

  // The core asio classes that provide I/O functionality (or as in this case
  // timer functionality) always take an executor, or a reference to an
  // execution context (such as io_context), as their first constructor
  // argument.
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

  t.wait();

  std::cout << "Hello, world!"
            << "\n";

  return 0;
}