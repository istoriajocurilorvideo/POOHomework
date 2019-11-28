#include "Vector.h"
Vector::Vector() : vSize(0) {}

Vector::Vector(unsigned int dim, int value) : vSize(dim)
{
    allocateVecData(vData, vSize);
    v_init(value);
}

Vector::Vector(int *v, unsigned int dim) : vSize(dim)
{

    allocateVecData(vData, vSize);
    for(unsigned int index = 0; index < vSize; index++)
        vData[index] = v[index];

}

Vector::~Vector()
{
    delete[] vData;
}

Vector::Vector(const Vector& other)
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

Vector& Vector::operator=(const Vector& rhs)
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

int& Vector::operator[] (unsigned int index)
{
    if(index < 0 || index >= vSize)
        throw out_of_range("Index out of bounds");
    return vData[index];
}

int Vector::operator[] (unsigned int index) const
{
    if(index < 0 || index >= vSize)
        throw out_of_range("Index out of bounds");
    return vData[index];
}

void Vector::pushBack(const int& item)
{
    if(vSize == 0) {
        allocateVecData(vData, 1);
        vSize = 1;
        vData[0] = item;
    } else {
        int *temp_data;
        allocateVecData(temp_data, vSize + 1);
        copyVector(temp_data, vData, vSize);
        temp_data[vSize] = item;
        delete []vData;
        allocateVecData(vData, vSize + 1);
        copyVector(vData, temp_data, vSize + 1);
        vSize++;
    }
}

void Vector::resize(unsigned int size, bool keepData)
{
    int *temp_data;
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

void Vector::allocateVecData(int *&v_data, unsigned int size)
{
    try {
        v_data = new int[size];
    } catch(bad_alloc& ba) {
        cout<<"Error : "<<ba.what()<<" : not able to allocate vector";
    }
}

void Vector::cleanUpVector(int *&v_data, unsigned int size)
{
    delete[] v_data;
}

void Vector::copyVector(int *&v_dest, int *src, unsigned int size)
{
    for(unsigned int index = 0; index < size; index++)
        v_dest[index] = src[index];
}

void Vector::v_init(int value)
{
    for(unsigned int index = 0; index < vSize; index++)
        vData[index] = value;
}

void Vector::print(ostream& out) const
{
    if(vSize != 0) {
        for(unsigned int index = 0; index < vSize; index++)
            out<<vData[index]<<" ";
    }
}

void Vector::read(istream& in)
{
    int value;
    in>>value;
    pushBack(value);
}
/*
bool Vector::operator== (const Vector &v)
{
    for(int index=0; index < vSize; index++)
        if(vData[index] != v[index])
            return false;
    return true;
}

bool Vector::operator!= (const Vector &v)
{
    for(int index=0; index < vSize; index++)
        if(vData[index] != v[index])
            return true;
    return false;
}*/

void Vector::deleteItemByItem(const int &item)
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

void Vector::deleteItemByIndex(unsigned int ind)
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

bool Vector::searchItem(const int &item){
    for(unsigned int index = 0; index < vSize; index ++)
        if(vData[index] == item)
            return true;
    return false;
}
