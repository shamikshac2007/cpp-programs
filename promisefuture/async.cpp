#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

void makePayment(std::promise<int> paymentPromise) {
    // simulate some delay (like product preparation)
    this_thread::sleep_for(chrono::seconds(5));
    paymentPromise.set_value(501);  // Set the promised value (currency)
}

int main() {
    std::promise<int> promiseObj ;  // The currency note (promise)
    std::future<int> futureObj = promiseObj.get_future() ; // Buyer holds the future

    std::thread seller(makePayment, std::move(promiseObj)); // Seller prepares the value 

    cout << "Waiting for payment....\n";
    int payment = futureObj.get();  // Buyer waits until value is available 
    cout << "Recieved payment: " << payment << " units.\n";

    seller.join();
    return 0 ;

}









// g++ async.cpp -o async.exe
// ./async.exe