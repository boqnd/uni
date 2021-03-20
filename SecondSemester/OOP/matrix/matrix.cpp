#include <iostream>

using namespace std;

class Matrix{
  public:
  unsigned int rows;
  unsigned int cols;
  int **data;

  Matrix (unsigned int, unsigned int);
  ~Matrix ();
  Matrix (const Matrix&);
  Matrix& operator= (const Matrix&);
  bool operator== (Matrix);
  Matrix operator+ (Matrix);
  friend std::ostream& operator<<(ostream& out, const Matrix& other);
  friend std::istream& operator>>(istream& in, const Matrix& other);

};

Matrix::Matrix (unsigned int rows, unsigned int cols) {
  this->rows = rows;
  this->cols = cols;
  this->data = nullptr;
}

Matrix::~Matrix () {
  delete[] data;
}

Matrix::Matrix (const Matrix& other) {
  this->rows = other.rows;
  this->cols = other.cols;

  this->data = new int*[rows];
  for (size_t i = 0; i < rows; i++)
  {
    this->data[i] = new int[cols];
    for (size_t j = 0; j < cols; j++)
    {
      this->data[i][j] = other.data[i][j];
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Matrix& other)
{
    for (size_t i = 0; i < other.rows; i++)
    {
        for (size_t j = 0; j < other.cols; j++)
        {
            out << other.data[i][j] << " "; 
        }
        out << std::endl;
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, Matrix& other)
{
    other.data = new int*[other.rows];
    for (int i = 0; i < other.rows; i++)
    {
        other.data[i] = new int[other.cols];
        for (int j = 0; j < other.cols; j++)
        {
            in >> other.data[i][j];

        }
    }

    return in;
}

int main() {
  Matrix a(3,3);
  
  cout << "Enter values for 3x3 matrix" << endl;
  cin >> a;
  cout << endl << "Printing matrix" << endl;
  cout << a << endl;
  return 0;
}