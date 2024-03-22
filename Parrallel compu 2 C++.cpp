#include<iostream>
#include<thread>
#include <ctime>
using namespace std;
void parallel_summ(int arr[], int& results, int f_el_idx, int l_el_idx) {
    int sum = 0;
    for (int i = f_el_idx; i < l_el_idx; i++) {
        sum += arr[i];
    }
    results = sum;
}
double sumArr(int hardware_threads, int arr[], int length_arr) {
    int min_per_thread = 2;
    int max_threads = (length_arr + min_per_thread - 1) / min_per_thread;
    int num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    int block_size = length_arr / num_threads;
    int* results = new int[num_threads];
    std::thread* threads = new std::thread[num_threads];
    int start_parallel = clock(); 
    for (int i = 0; i < num_threads; i++)
        threads[i] = thread(parallel_summ, arr, ref(results[i]), block_size * i, block_size * (i + 1));
    for (int i = 0; i < num_threads; i++) {
        if (threads[i].joinable())
            threads[i].join();
    }
    int end_parallel = clock();
    double time_parallel = (double)(end_parallel - start_parallel) / CLOCKS_PER_SEC;
    delete[] results;
    delete[] threads;
    return time_parallel;
}

int main() {
    const int length_arr = 16;
    int arr[length_arr] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    int hardware_threads = std::thread::hardware_concurrency();   
    int min_per_thread = 2;
    int max_threads = (length_arr + min_per_thread - 1) / min_per_thread;
    int num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    int block_size = length_arr / num_threads;
    int* results = new int[num_threads];
    int start = clock(); 
    for (int i = 0; i < num_threads; i++) {
        int sum = 0;
        for (int j = i * block_size; j < (i + 1) * block_size; j++) {
            sum += arr[j];
        }
        results[i] = sum;
    }
    int end = clock(); 
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Method: conventional: " << time << endl;
    cout << "Method: hardware_threads: " << sumArr(hardware_threads, arr, length_arr) << endl;
    cout << "Method: hardware_threads/2: " << sumArr(hardware_threads / 2, arr, length_arr) << endl;
    cout << "Method: 2*hardware_threads: " << sumArr(hardware_threads * 2, arr, length_arr) << endl;
    cout << "Method: 4*hardware_threads: " << sumArr(hardware_threads * 4, arr, length_arr) << endl;
    cout << "Method: 8*hardware_threads: " << sumArr(hardware_threads * 8, arr, length_arr) << endl;
    cout << "Method: 16*hardware_threads: " << sumArr(hardware_threads * 16, arr, length_arr) << endl;
    return 0;
}
