#include "Vector.h"

template<typename type>
Vector<type>::Vector() : vSize(0) {}

template<typename type>
Vector<type>::Vector(unsigned int dim, type value) : vSize(dim)
{
    allocateVecData(vData, vSize);
    v_init(value);
}

template<typename type>
Vector<type>::Vector(type *v, unsigned int dim) : vSize(dim)
{

    allocateVecData(vData, vSize);
    for(unsigned int index = 0; index < vSize; index++)
        vData[index] = v[index];

}

template<typename type>
Vector<type>::~Vector()
{
    delete[] vData;
}

template<typename type>
Vector<type>::Vector(const Vector& other)
{
    if(vData == nullptr) {
        allocateVecData(vData, other.vSize);
    } else if(vSize != other.vSize) {
        delete []vData;
        allocateVecData(vData, other.vSize);
    }

    copyVector(vData, other.vData, other.vSize);
    vSize = other.vSize;
}

template<typename type>
Vector<type>& Vector<type>::operator=(const Vector<type>& rhs)
{
    if (this == &rhs)
        return *this;

    if(vData == nullptr) {
        allocateVecData(vData, rhs.vSize);
    } else if(vSize != rhs.vSize) {
        delete []vData;
        allocateVecData(vData, rhs.vSize);
    }

    copyVector(vData, rhs.vData, rhs.vSize);
    vSize = rhs.vSize;
    return *this;
}

template<typename type>
type& Vector<type>::operator[] (unsigned int index)
{
    if(index < 0 || index >= vSize)
        throw out_of_range("Index out of bounds");
    return vData[index];
}

template<typename type>
type Vector<type>::operator[] (unsigned int index) const
{
    if(index < 0 || index >= vSize)
        throw out_of_range("Index out of bounds");
    return vData[index];
}

template<typename type>
void Vector<type>::pushBack(const type& item)
{
    if(vSize == 0) {
        allocateVecData(vData, 1);
        vSize = 1;
        vData[0] = item;
    } else {
        type *temp_data;
        allocateVecData(temp_data, vSize + 1);
        copyVector(temp_data, vData, vSize);
        temp_data[vSize] = item;
        delete []vData;
        allocateVecData(vData, vSize + 1);
        copyVector(vData, temp_data, vSize + 1);
        vSize++;
    }
}

template<typename type>
void Vector<type>::resize(unsigned int size, bool keepData)
{
    type *temp_data;
    if(size != 0) {
        allocateVecData(temp_data, size);
        if(keepData) {
            unsigned int smallest = (size < vSize) ? size : vSize;
            for(unsigned int index=0; index < smallest; index++)
                temp_data[index] = vData[index];
        }
    }
    if(vData != nullptr)
        delete [] vData;

    vSize = size;
    if(size != 0) vData = temp_data;
}

template<typename type>
void Vector<type>::allocateVecData(type *&v_data, unsigned int size)
{
    try {
        v_data = new type[size];
    } catch(bad_alloc& ba) {
        cout<<"Error : "<<ba.what()<<" : not able to allocate vector";
    }
}

template<typename type>
void Vector<type>::cleanUpVector(type *&v_data, unsigned int size)
{
    delete[] v_data;
}

template<typename type>
void Vector<type>::copyVector(type *&v_dest, type *src, unsigned int size)
{
    for(unsigned int index = 0; index < size; index++)
        v_dest[index] = src[index];
}

template<typename type>
void Vector<type>::v_init(type value)
{
    for(unsigned int index = 0; index < vSize; index++)
        vData[index] = value;
}

template<typename type>
void Vector<type>::print(ostream& out) const
{
    if(vSize != 0) {
        for(unsigned int index = 0; index < vSize; index++)
            out<<vData[index]<<" ";
    }
}

template<typename type>
void Vector<type>::read(istream& in)
{
    type value;
    in>>value;
    pushBack(value);
}
/*
bool Vector<type>::operator== (const Vector &v)
{
    for(int index=0; index < vSize; index++)
        if(vData[index] != v[index])
            return false;
    return true;
}

bool Vector<type>::operator!= (const Vector &v)
{
    for(int index=0; index < vSize; index++)
        if(vData[index] != v[index])
            return true;
    return false;
}*/

template<typename type>
void Vector<type>::deleteItemByItem(const type &item)
{
    unsigned int index, index2;
    for(index=0; index < vSize; index++) {
        if(vData[index] == item) {
            for(index2 = index; index2 < vSize-1; index2 ++)
                vData[index2] = vData[index2+1];
            resize(vSize-1, true);
        }
    }
}

template<typename type>
void Vector<type>::deleteItemByIndex(unsigned int ind)
{
    unsigned int index, index2;
    for(index=0; index < vSize; index++) {
        if(index == ind) {
            for(index2 = index; index2 < vSize-1; index2 ++)
                vData[index2] = vData[index2+1];
            resize(vSize-1, true);
        }
    }
}

template<typename type>
bool Vector<type>::searchItem(const type &item){
    for(unsigned int index = 0; index < vSize; index ++)
        if(vData[index] == item)
            return true;
    return false;
}

template class Vector<int>;
