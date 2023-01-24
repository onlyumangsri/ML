def matrix_multiply(A, B):
    rows_A = len(A)
    cols_A = len(A[0])
    rows_B = len(B)
    cols_B = len(B[0])
    
    if cols_A != rows_B:
        raise ValueError("Cannot multiply the two matrices. Incompatible dimensions.")
    
    C = [[0 for row in range(cols_B)] for col in range(rows_A)]
    for i in range(rows_A):
        for j in range(cols_B):
            for k in range(cols_A):
                C[i][j] += A[i][k] * B[k][j]
    return C

import time
start = time.perf_counter()

#Driver Code
A = [[1, 2, 3, 4, 5, 6, 7, 8 ], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888]];

B = [[3, 4, 8, 10, 1024, 666, 777, 888], [1, 2, 3, 4, 5, 6, 7, 8 ], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888], [3, 4, 8, 10, 1024, 666, 777, 888]];

result = matrix_multiply(A, B)
#print(result)

end = time.perf_counter()
print(f"Time taken: {(end - start) * 1000000:0.6f} microseconds")
  

