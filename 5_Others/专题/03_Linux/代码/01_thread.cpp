#include <iostream>       // std::cout
#include <thread>         // std::thread, std::thread::id, std::this_thread::get_id
#include <chrono>         // std::chrono::seconds
 
std::thread::id main_thread_id = std::this_thread::get_id();

void is_main_thread() {

  if ( main_thread_id == std::this_thread::get_id() )
    std::cout << "This is the main thread.\n";
  else
    std::cout << "This is not the main thread.\n";
}

int main() 
{
  is_main_thread();
  std::thread th (is_main_thread);
  th.join();
}