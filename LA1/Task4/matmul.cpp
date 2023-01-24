#include <boost/python/numpy.hpp>
#include <iostream>

namespace p = boost::python;
namespace np = boost::python::numpy;

// Actual C++/C code for matrix multiplication
void matrix_multiply(double* matA, int rowsA, int colsA, double* matB, int rowsB, int colsB, double* output) {
    if (colsA != rowsB) {
        PyErr_SetString(PyExc_ValueError, "The number of columns of the first matrix must be equal to the number of rows of the second matrix");
        p::throw_error_already_set();
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            double sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += matA[i*colsA + k] * matB[k*colsB + j];
            }
            output[i*colsB + j] = sum;
        }
    }
}

// Translator function to convert numpy arrays to C++ pointers
np::ndarray wrap_matrix_multiply(np::ndarray const & matA, np::ndarray const & matB) {
    if (matA.get_dtype() != np::dtype::get_builtin<double>() || matB.get_dtype() != np::dtype::get_builtin<double>()) {
        PyErr_SetString(PyExc_TypeError, "Incorrect array data type, both matrices should be of type double");
        p::throw_error_already_set();
    }

    int rowsA = matA.shape(0);
    int colsA = matA.shape(1);
    int rowsB = matB.shape(0);
    int colsB = matB.shape(1);

    // Allocate memory for the output matrix
    double* output = new double[rowsA * colsB];
    memset(output, 0, sizeof(double) * rowsA * colsB);

    // Call the matrix multiplication function
    matrix_multiply(reinterpret_cast<double*>(matA.get_data()), rowsA, colsA, reinterpret_cast<double*>(matB.get_data()), rowsB, colsB, output);
    
    // Turn the output into a numpy array
    np::dtype dt = np::dtype::get_builtin<double>();
    p::tuple shape = p::make_tuple(rowsA, colsB);
    p::tuple stride = p::make_tuple(sizeof(double) * colsB, sizeof(double));
    np::ndarray result = np::from_data(output, dt, shape, stride, p::object());

    // Deallocate memory
    delete[] output;

    return result;
}

BOOST_PYTHON_MODULE(example) {
    Py_Initialize();
    np::initialize();
    p::def("matrix_multiply", wrap_matrix_multiply);
}
