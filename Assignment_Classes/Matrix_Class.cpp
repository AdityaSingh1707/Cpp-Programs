#include<iostream> 
using namespace std;

template<class T>
class Matrix;
template<class T>
istream& operator>>(istream &in, Matrix<T> &obj);
template<class T>
ostream& operator<<(ostream &out ,const Matrix<T> &obj);

template<class T>
class Matrix
{
    private:
        T **arr;
        int rows, columns;
    public:
        Matrix()
        {
            rows = columns = 0, arr = NULL;
        }
        Matrix(int rows, int columns)
        {
            this->rows = rows, this->columns = columns;
            arr = new T*[rows];
            for(int i = 0; i<rows; i++)
            {
                arr[i] = new T[columns];
            }
        }
        Matrix(int order)
        {
            rows = columns = order;
            arr = new T*[rows];
            for(int i = 0; i<rows; i++)
            {
                arr[i] = new T[columns];
            }
        }
        Matrix(const Matrix<T> &ob)
        {
            rows = ob.rows, columns = ob.columns;
            arr = new T*[rows];
            for(int i = 0; i<rows; i++)
            {
                arr[i] = new T[columns];
            }

            for(int i = 0; i<rows; i++)
            {
                for(int j = 0; j<columns; j++)
                {
                    arr[i][j] = ob.arr[i][j];
                }
            }
        }
        Matrix<T>& operator=(const Matrix &ob)
        {
            if(arr != NULL && rows != 0 && columns != 0)
            {
                for(int i = 0; i<rows; i++)
                {
                    delete[] arr[i];
                }
                arr = NULL, rows = 0, columns = 0;
            }
            rows = ob.rows, columns = ob.columns;
            arr = new T*[rows];
            for(int i = 0; i<rows; i++)
            {
                arr[i] = new T[columns];
            }

            for(int i = 0; i<rows; i++)
            {
                for(int j = 0; j<columns; j++)
                {
                    arr[i][j] = ob.arr[i][j];
                }
            }
            return *this;
        }
        Matrix<T> operator+(const Matrix<T> &ob)
        {
            Matrix<T> res(rows, columns);
            for(int i = 0; i<rows; i++)
            {
                for(int j = 0; j<columns; j++)
                {
                    res.arr[i][j] = this->arr[i][j] + ob.arr[i][j];
                }
            }
            return res;
        }
        Matrix<T> operator-(const Matrix<T> &ob)
        {
            Matrix res(rows, columns);
            for(int i = 0; i<rows; i++)
            {
                for(int j = 0; j<columns; j++)
                {
                    res.arr[i][j] = arr[i][j] - ob.arr[i][j];
                }
            }
            return res;
        }
        Matrix<T> operator*(const Matrix<T> &ob)
        {
            Matrix<T> res(rows, ob.columns);
            for(int i = 0; i<rows; i++)
            {
                for(int j = 0; j<ob.columns; j++)
                {
                    res.arr[i][j] = 0;
                    for(int k = 0; k<ob.rows; k++)
                    {
                        res.arr[i][j] += arr[i][k] * ob.arr[k][j];
                    }
                }
            }
            return res;
        }
        void transpose()
        {
            Matrix<T> res(columns, rows);
            for(int i = 0; i<columns; i++)
            {
                for(int j = 0; j<rows; j++)
                {
                    res.arr[i][j] = arr[j][i]; 
                }
            }
        }
        ~Matrix()
        {
            for(int i = 0; i<rows; i++)
            {
                delete[] arr[i];
            }
            arr = NULL, rows = 0, columns = 0;
        }
        friend istream& operator>><T>(istream &in, Matrix<T> &obj);
        friend ostream& operator<<<T>(ostream &out, const Matrix<T> &obj);
};

template<class T>
istream& operator>>(istream &in, Matrix<T> &obj)
{
    if(obj.arr == NULL && obj.rows == 0 && obj.columns == 0)
    {
        cout<<"Enter the no of rows and columns of Matrix :"<<endl;
        in>>obj.rows>>obj.columns;
        obj.arr = new int*[obj.rows];
        for(int i = 0; i<obj.rows; i++)
        {
            obj.arr[i] = new int[obj.columns];
        }
    }
    cout<<"Enter the elements of Matrix :"<<endl;
    for (int i = 0; i < obj.rows; i++)
    {
        for (int j = 0; j < obj.columns; j++)
        {
            in>>obj.arr[i][j];
        }
    }
    return in;
}

template<class T>
ostream& operator<<(ostream &out, const Matrix<T> &obj)
{
    if(obj.arr == NULL && obj.rows == 0 && obj.columns == 0)
        cout<<"Matrix is Destroyed(Empty)"<<endl;
    else
    {
        cout<<"Displaying Matrix :"<<endl;
        for (int i = 0; i < obj.rows; i++)
        {
            for (int j = 0; j < obj.columns; j++)
            {
                out<<obj.arr[i][j]<<" ";
            }
            out<<endl;
        }
    }
    return out;
}

int main()
{
    Matrix<int> m1;
    cin>>m1; 
    cout<<m1;

    Matrix<int> m2(m1); 
    cout<<m2;

    Matrix<int> sum, diff;
    sum = m1 + m2;
    cout<<"ADDITION :"<<endl;
    cout<<sum;
    diff = m1 - m2;
    cout<<"Substraction :"<<endl;
    cout<<diff;

    Matrix<int> res_copy;
    res_copy = sum = diff;
    cout<<"ASSIGNMENT :"<<endl;
    cout<<res_copy;

    Matrix<int> product(m1*m2);
    cout<<"Multiplication:"<<endl;
    cout<<product;

    product.~Matrix();
    cout<<product;

    m1 = product;
    return 0;
}
