
# cpp-simple-matrix

This is just a fixed-size, templated, 2D array without any numeric operations and boundary checking. This is useful when passing 2D data to a function. However, if it's not what you are looking for. For a fully functional matrix on linear algebra, see [uBLAS of Boost](https://www.google.com/search?q=boost+ublas). For a higher dimension array, see [MultiArray of Boost](https://www.google.com/search?q=boost+multiarray).

## Usage

Download the [`matrix.h`](https://raw.github.com/YiPo/cpp-simple-matrix/master/matrix.h) file and include it. No library is needed to be linked.

## Reference

The `matrix` class template is defined as follows.

`template <typename T> class matrix;`

* `T`: the type of the elements

### Constructors

- `matrix()`                  (the default constructor)

- `matrix(int m, int n)`      constructs an m-by-n matrix.

- `matrix(const matrix &mat)` (the copy constructor)

### Member Functions

- `matrix &operator =` (the copy assignment)

- `int get_m() const`  returns the number of rows.

- `int get_n() const`  returns the number of columns.

###### element access

There are 3 ways to access the (i,j)th element.

| #  | declaration                   | description                        | example        |
|:---|:------------------------------|:-----------------------------------|:---------------|
| 1. | `T &at(int i, int j)`         | by the member function             | `foo.at(i, j)` |
| 2. | `T &operator ()`              | by a more compact syntax           | `foo(i, j)`    |
| 3. | `T &operator [] .operator []` | as a traditional 2D array (slower) | `foo[i][j]`    |

### Non-member functions

- `void swap(matrix<T> &a, matrix<T> &b)` exchanges the contents of two matrices.

