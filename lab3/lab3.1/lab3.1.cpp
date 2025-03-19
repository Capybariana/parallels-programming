#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void initialize(std::vector<double>& vector, int startIndex, int endIndex, int n, std::vector<double>& matrix) {
    for (int i = startIndex; i < endIndex; ++i) {
        for (int j = 0; j < n; j++) {
            matrix[i * n + j] = i + j;
        }
    }
    for (int j = 0; j < n; j++) { 
        vector[j] = j;
    }
}

void multiplication(std::vector<double>& vector, std::vector<double>& matrix, std::vector<double>& result, int startIndex, int endIndex, int n) {
    for (int i = startIndex; i < endIndex; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += matrix[i * n + j] * vector[j];
        }
    }
}

int main() {
    int n, numThreads;
    
    std::cout << "Введите размер матрицы: ";
    std::cin >> n;
    std::cout << "Введите количество потоков: ";
    std::cin >> numThreads;

    std::vector<double> vector(n);
    std::vector<double> matrix(n * n);
    std::vector<double> result(n, 0);

    int chunkSizeVec = n / numThreads;
    int startIndex = 0;
    std::vector<std::jthread> threads;

    for (int i = 0; i < numThreads; ++i) {
        int endIndex = (i == numThreads - 1) ? n : startIndex + chunkSizeVec;
        threads.emplace_back(initialize, std::ref(vector), startIndex, endIndex, n, std::ref(matrix));
        startIndex = endIndex;
    }

    for (auto& thread : threads) {
        thread.join();
    }

    threads.clear();
    startIndex = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numThreads; ++i) {
        int endIndex = (i == numThreads - 1) ? n : startIndex + chunkSizeVec;
        threads.emplace_back(multiplication, std::ref(vector), std::ref(matrix), std::ref(result), startIndex, endIndex, n);
        startIndex = endIndex;
    }

    for (auto& thread : threads) { 
        thread.join();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start; 

    std::vector<double> serial_result(n, 0);
    auto serial_start = std::chrono::high_resolution_clock::now();
    
    multiplication(vector, matrix, serial_result, 0, n, n);
    
    auto serial_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> serial_time = serial_end - serial_start;

    std::cout << "Время выполнения параллельного алгоритма T1: " << elapsed_seconds.count() << " сек\n";
    std::cout << "Время выполнения последовательного алгоритма: " << serial_time.count() << " сек\n";

    double speedup = serial_time.count() / elapsed_seconds.count();
    std::cout << "Ускорение S: " << speedup << '\n';

    return 0;
}
