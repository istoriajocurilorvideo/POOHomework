#include "Matrice.h"

template<typename type>
Matrice<type>::Matrice() : size(0) {}

template<typename type>
Matrice<type>::Matrice(unsigned int dim, type value) : size(dim)
{
    allocateMatrix(m_data, dim);
    unsigned ind1, ind2;
    for(ind1 = 0; ind1 < size; ind1++) {
        for(ind2 = 0; ind2 < size; ind2++)
            m_data[ind1][ind2] = value;
    }
}

template<typename type>
Matrice<type>::Matrice(type **a, unsigned int dim) : size(dim)
{
    allocateMatrix(m_data, dim);
    matrixCopy(m_data, a, dim);
}

template<typename type>
Matrice<type>::~Matrice()
{
    cleanUpMatrix(m_data, size);
}

template<typename type>
Matrice<type>::Matrice(const Matrice& other)
{
    unsigned int other_size = other.getSize();
    if(other_size != size) {
        cleanUpMatrix(m_data, size);
        other_size = size;
        allocateMatrix(m_data, other_size);
    }
    matrixCopy(m_data, other.m_data, other_size);
}

template<typename type>
Matrice<type>& Matrice<type>::operator=(const Matrice<type>& rhs)
{
    if (this == &rhs)
        return *this;
    unsigned int rhs_size = rhs.getSize();
    if(rhs_size != size) {
        cleanUpMatrix(m_data, size);
        rhs_size = size;
        allocateMatrix(m_data, rhs_size);
    }
    matrixCopy(m_data, rhs.m_data, size);
    return *this;
}

template<typename type>
type& Matrice<type>::operator()(unsigned int row, unsigned int column)
{
    if(row <  0 && column >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_data[row][column];
}

template<typename type>
type Matrice<type>::operator()(unsigned int row, unsigned int column) const
{
    if(row < 0 && column >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_data[row][column];
}

template<typename type>
void Matrice<type>::allocateMatrix(type **&m_alloc, unsigned int m_size)
{
    try {
        m_alloc = new type*[m_size];
        for(unsigned int i = 0; i < m_size; ++i)
            m_alloc[i] = new type[m_size];
    } catch(std::bad_alloc& ba) {
        cout<<"Error : "<<ba.what()<<" for temp_data";
    }
}

template<typename type>
void Matrice<type>::cleanUpMatrix(type **&m_alloc, unsigned int m_size)
{
    for(unsigned int i = 0; i < m_size; ++i)
        delete [] m_alloc[i];
    delete [] m_alloc;
}

template<typename type>
void Matrice<type>::matrixCopy(type **&dest, type **src, unsigned int m_size)
{
    unsigned int index1, index2;
    for(index1 = 0; index1 < m_size; index1 ++) {
        for(index2 = 0; index2 < m_size; index2 ++)
            dest[index1][index2] = src[index1][index2];
    }
}

template<typename type>
void Matrice<type>::resize(unsigned int t_size, bool keepData)
{
    type **temp_matrix;
    if(t_size != 0) {
        allocateMatrix(temp_matrix, t_size);

        if(keepData) {
            unsigned int smallest = (t_size < size) ? size : t_size;
            matrixCopy(temp_matrix, m_data, smallest);
        }
    }
    if(m_data != nullptr)
        delete []m_data;
    if(t_size != 0) {
        allocateMatrix(m_data, t_size);
        matrixCopy(m_data, temp_matrix, t_size);
    }
    size = t_size;
}

template<typename type>
void Matrice<type>::print(ostream& out) const
{
    unsigned int i, j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++)
            out<<m_data[i][j]<<" ";
        out<<endl;
    }
}

template<typename type>
void Matrice<type>::read(istream& in)
{
    unsigned int i, j;
    if(size > 0) {
        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++)
                in>>m_data[i][j];
        }
    }
    else throw zero_length_error("matrix data is empty");
}

template class Matrice<int>;
