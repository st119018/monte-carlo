#include <iostream>
#include <thread>
#include <random>
#include <mutex>

// total number of points
#define POINTS_TOTAL 100000

// generator of random numbers
std::random_device rand_device;
std::mt19937_64 gen(rand_device());
// even distribution between [0;1]
std::uniform_real_distribution<> distr(0, 1);

std::mutex total_mtx;

int total_in_circle{};

void count_points(int num_of_points);

int main(){
    // numbers of threads
    int num_threads;
    std::cout << "Enter number of threads: ";
    std::cin >> num_threads;
    
    // number of points to count in single thread
    int points_per_thread = POINTS_TOTAL / num_threads;

    // array of threads of given quantity
    std::thread threads[num_threads];

    for(auto& th : threads){
        th = std::thread(count_points, points_per_thread);
    }
    // measuring time
    auto begin = std::chrono::steady_clock::now();
    for(auto& th : threads){
        th.join();
    }
    auto end = std::chrono::steady_clock::now();
        
    // counting time
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        
    // calculating pi
    double my_pi = (double)total_in_circle / (points_per_thread * num_threads) * 4;
        
    std::cout << "Calculated pi: " << my_pi << "\n";
    std::cout << "Time spent: " << elapsed.count() <<" us " << // us - microseconds
                 "using "<< num_threads <<" threads\n\n";
    total_in_circle = 0;

    return 0;
}

// counts number of points placed in circle
void count_points(int num_of_points){
    int points_in_circle = 0;

    for(int i = 0; i < num_of_points; ++i){
        // generate random coordinates
        long double x = distr(gen);
        long double y = distr(gen);
        
        if(x * x + y * y <= 1){
            ++points_in_circle;
        }
    }
    
    total_mtx.lock();
    // adding to total number of points in circle
    total_in_circle += points_in_circle;
    total_mtx.unlock();
}


/*
My pi: 3.14122
Time spent: 100334 ms using 4 threads

My pi: 3.13849
Time spent: 75426 ms using 10 threads

My pi: 3.1449
Time spent: 17348 ms using 20 threads
*/
/*
Calculated pi: 3.14379
Time spent: 105016 us using 4 threads

Calculated pi: 3.13935
Time spent: 50510 us using 10 threads

Calculated pi: 3.14183
Time spent: 29554 us using 20 threads
*/
/*
Calculated pi: 3.14105
Time spent: 109958 us using 4 threads

Calculated pi: 3.14197
Time spent: 50918 us using 10 threads

Calculated pi: 3.14215
Time spent: 10112 us using 20 threads
*/

/*
Calculated pi: 3.1422
Time spent: 104048 us using 4 threads

Calculated pi: 3.1409
Time spent: 66782 us using 10 threads

Calculated pi: 3.13874
Time spent: 21983 us using 20 threads
*/