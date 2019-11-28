#ifndef VECTOR_H
#define VECTOR_H
#include "Universal.h"

template<typename type>
class Vector : public ArrayStream
{
    public:
        explicit Vector();
        Vector(unsigned int dim, type value);
        Vector(type *v, unsigned int dim);
        virtual ~Vector();
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);
        type& operator[] (unsigned int index);
        type operator[] (unsigned int index) const;
        //bool operator== (const Vector &v);
        //bool operator!= (const Vector &v);
        void pushBack(const type& item);
        void pop(unsigned int index);
        void deleteItemByItem(const type &item);
        void deleteItemByIndex(unsigned int ind);
        void resize(unsigned int size, bool keepData=false);
        bool isEmpty() const { return vSize > 0; };
        bool searchItem(const type &item);
        unsigned int getSize() const { return vSize; }
        void v_init(type value);
    protected:
        void allocateVecData(type *&v_data, unsigned int size);
        void cleanUpVector(type *&v_data, unsigned int size);
        void copyVector(type *&v_dest, type *src, unsigned int size);

    private:
        unsigned int vSize;
        type *vData = nullptr;
        void print(ostream& o) const;
        void read(istream& in);
};

#endif // VECTOR_H
