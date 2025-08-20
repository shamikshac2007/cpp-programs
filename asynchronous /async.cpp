#include <iostream>
#include <future>    // Required for std::async and std::future
#include <thread>    // Required for std::this_thread::sleep_for 
#include <chrono>    // Required for std::chrono::seconds

// Function that stimulates a long running task 
int long_running_task(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    return seconds * 2 ; // Just an example computation 
}

int main() {
    // Launch the long running task asynchronously
    std::future<int> result = std::async(std::launch::async , long_running_task , 5);

    std::cout << "Doing some other work while waiting...." << std::endl;

    // Get the result of the long running task (this will block until its ready )
    int result_value = result.get();

    std::cout << "Task completed. Result: " << result_value << std::endl;

    return 0;
}
