

import numpy as np
import example

import time
start = time.perf_counter()

# Create two matrices
A = np.array([[1, 2, 3, 4, 5, 6, 7, 8 ], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888]])
B = np.array([[3, 4, 8, 10, 1024, 666, 777, 888], [1, 2, 3, 4, 5, 6, 7, 8 ], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888]])

# Multiply the matrices and store the result
C = example.matrix_multiply(A.astype(np.double), B.astype(np.double))

end = time.perf_counter()
print(f"Time taken: {(end - start) * 1000000:0.6f} microseconds")


# print(C)

# Run this code
# g++ -Wall -Wextra -fPIC -shared -I/home/onlyumangsri/anaconda3/include/python3.9/ -L/home/onlyumangsri/anaconda3/lib/ matmul.cpp -o example.so -lboost_python39 -lboost_numpy39

