#include "matrix_cpp.hpp"
#include <pybind11/pybind11.h>

PYBIND11_MODULE(matrix_cpp, m) {
    m.doc() = "This module uses the c++ code to perform simple matrix multiplications"; // optional module docstring

    m.def("test_func", &old_main, "execute old main code");

}
