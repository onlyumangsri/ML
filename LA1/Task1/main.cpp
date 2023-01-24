#include "matrix.h"
#include <chrono>

using namespace std;

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<double>> A = {{1, 3, 3, 4, 5, 6, 7, 8 }, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 888}};
    std::vector<std::vector<double>> B = {{3, 4, 8, 10, 1024, 666, 777, 888}, {1, 2, 3, 4, 5, 6, 7, 8 }, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 88228}, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 888}, {3, 4, 8, 10, 1024, 666, 777, 888}};
    std::vector<std::vector<double>> C = matrix_multiply(A, B);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    // int n = A.size();
    // int m = B[0].size();
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout<<C[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}