#ifndef MATRICE_H
#define MATRICE_H
#include "Universal.h"

template<typename type>
class Matrice : public ArrayStream
{
    public:
        Matrice();
        Matrice(unsigned int dim, type value);
        Matrice(type **a, unsigned int dim);
         ~Matrice();
        Matrice(const Matrice& other);
        Matrice& operator=(const Matrice& other);
        type& operator() (unsigned int row, unsigned int column);
        type operator() (unsigned int row, unsigned int column) const;
        unsigned int getSize() const { return size; }
        void resize(unsigned int t_size, bool keepData=false);

    protected:
        void allocateMatrix(type **&m_alloc, unsigned int m_size);
        void cleanUpMatrix(type **&m_alloc, unsigned int m_size);
        void matrixCopy(type **&dest, type **src, unsigned int m_size);

    private:
        type **m_data = nullptr;
        unsigned int size;
        void print(ostream& out) const;
        void read(istream& in);
};

#endif // MATRICE_H
