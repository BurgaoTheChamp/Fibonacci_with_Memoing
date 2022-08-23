#include <iostream>
#include <unordered_map>
#include <chrono>

uint64_t fib(const uint64_t &n){
    if (n < 3)
    {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}


uint64_t fib_hashed(const uint64_t &n){

    static std::unordered_map <int, uint64_t> container;

    if(n < 3){
        return 1;
    }    
    if(container.count(n)){
        return container[n];
    }
    container[n] =  fib_hashed(n - 1) + fib_hashed(n - 2); 
    return container[n];
}

int main(){
    
    bool keep_going = true;

    while (keep_going)
    {
        uint64_t n;
        std::cout << "Insert Fibonacci position: \n";
        std::cin >> n;
        
        auto start_hashed = std::chrono::steady_clock::now();
        std::cout << "Case one: " << fib_hashed(n) << std::endl;

        auto end_hashed = std::chrono::steady_clock::now();

        std::cout << "Elapsed time was: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_hashed - start_hashed).count() << " ms" << std::endl;

        auto start = std::chrono::steady_clock::now();

        std::cout << "Case two: " << fib(n) << std::endl;

        auto end = std::chrono::steady_clock::now();

        std::cout << "Elapsed time was: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        std::cout << "Do you want to do another time test? (1 or 0) " << std::endl;

        int loop;

        std::cin >>  loop;

        switch (loop)
        {
            case 0:
                keep_going = false;
                break;
            case 1:
                std::cout << "Here we go again " << std::endl;
                break;
            default:
                std::cout << "Invalid answer however i will consider as one :) " << std::endl;
                break;
        }
        
    }
}