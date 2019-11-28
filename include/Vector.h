#ifndef VECTOR_H
#define VECTOR_H
#include "Universal.h"


class Vector : public ArrayStream
{
    public:
        explicit Vector();
        Vector(unsigned int dim, int value=0);
        Vector(int *v, unsigned int dim);
        virtual ~Vector();
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);
        int& operator[] (unsigned int index);
        int operator[] (unsigned int index) const;
        //bool operator== (const Vector &v);
        //bool operator!= (const Vector &v);
        void pushBack(const int& item);
        void pop(unsigned int index);
        void deleteItemByItem(const int &item);
        void deleteItemByIndex(unsigned int ind);
        void resize(unsigned int size, bool keepData=false);
        bool isEmpty() const { return vSize > 0; };
        bool searchItem(const int &item);
        unsigned int getSize() const { return vSize; }
        void v_init(int value);
    protected:
        void allocateVecData(int *&v_data, unsigned int size);
        void cleanUpVector(int *&v_data, unsigned int size);
        void copyVector(int *&v_dest, int *src, unsigned int size);

    private:
        unsigned int vSize;
        int *vData = nullptr;
        void print(ostream& o) const;
        void read(istream& in);
};

#endif // VECTOR_H
