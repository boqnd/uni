#include<iostream>
 
class Matrix
{
public:
    unsigned int rows;
    unsigned int columns;
    int **data;
    void copy(const Matrix& other);
    friend std::ostream& operator<< (std::ostream& out, const Matrix& item);
    friend std::istream& operator>> (std::istream& in, Matrix& item);
    bool operator==(const Matrix& other) const;
    Matrix operator+(const Matrix& other);
    Matrix(unsigned int r,unsigned int c,int **d):rows(r), columns(c)
   {
       c = 0;
       r = 0;
       if (*d != nullptr)
       {
           int size = (sizeof(d)/sizeof(d[0][0]));
           *data = new int[size + 1]; 
           if(*d == nullptr)
           {
               std::cout << "The matrix is empty" << std::endl;
           }  
       }
       else
       {
           *d = *data;
       }
 
   }
    ~Matrix()
    {
        if (data != nullptr)
        {
            delete[] data;
        }
 
    }
 
   Matrix operator=(const Matrix& other)
   {
       if (this->data != nullptr)
       {
           delete[] this->data;
           this->data = nullptr;
       }
       this->copy(other);
       return *this;
 
   }
   Matrix(const Matrix& other)
   {
       this->copy(other);
   }
 
};
void Matrix::copy(const Matrix& other)
{
    this->rows = other.rows;
    this->columns = other.columns;
    this->data = other.data;
}
std::ostream& operator<<(std::ostream& out, const Matrix& other)
{
    out << "Rows"<< other.rows << "Columns" << other.columns << "Data" <<other.data<<std::endl;
    return out;
}
std::istream& operator>>(std::istream& in, Matrix& other)
{
    in >> other.rows >> other.columns;
    return in;
}
 
bool Matrix::operator==(const Matrix& other) const {
    return (this->rows == other.rows && this->columns == other.columns && this->data == other.data);
}
Matrix Matrix::operator+(const Matrix& other) 
{
 
    for (size_t i = 0; i < sizeof(data)/sizeof(data[0][0]); i++)
    {
       other.data[i][i] += data[i][i]; 
    }
 
    return (other);
}