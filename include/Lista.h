#ifndef LISTA_H
#define LISTA_H
#include "Universal.h"
#include "Vector.h"

template<typename type>
class Node
{
public:
    Node* next;
    Vector<type> data;
};

template<typename type>
class Lista : public ArrayStream
{
public:
    Lista();
    //Lista(unsigned int dim);
    Lista(Vector<type> *l, unsigned int vl_dim);
    virtual ~Lista();
    Lista(const Lista& other);
    Lista& operator=(const Lista& other);
    void addNode(Vector<type> item);
    Vector<type> &operator[] (unsigned int index);
    Vector<type> operator[] (unsigned int index) const;
    Node<type> *getElementByIndex(unsigned int index) const;
    void deleteElementByIndex(unsigned int index);
    void popBack();
    bool isListEmpty() const { return head == nullptr && tail == nullptr; }
    void emptyList();
    unsigned int getSize() const;
protected:

private:
    static unsigned int counter_help;
    void print(ostream& out) const;
    void read(istream& in);
    Node<type> *head, *tail;
};

#endif // LISTA_H
