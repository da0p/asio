#include <boost/asio.hpp>
#include <boost/asio/detail/chrono.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/steady_timer.hpp>
#include <iostream>
#include <thread>

void
print(boost::system::error_code const& e)
{
  std::cout << "Hello, world!"
            << "\n";
}

int
main()
{
  boost::asio::io_context io;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

  // Perform an asynchronous wait
  t.async_wait(&print);

  // We must call the io_context::run() member function on the io_context object
  // The asio library provides a guarantee that completion handlers will only be
  // called from threads that are currently calling io_context::run().
  // Therefore, unless the io_context::run() function is called, the completion
  // handler for the asynchronous wait completion will never be invoked.

  std::jthread anotherThread([&io] { io.run(); });

  std::cout << "I am dying..."
            << "\n";

  return 0;
}