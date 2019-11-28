#include "Lista.h"
template<typename type>
unsigned int Lista<type>::counter_help = 0;

template<typename type>
Lista<type>::Lista() : head(nullptr), tail(nullptr) {}

template<typename type>
Lista<type>::Lista(Vector<type> *l, unsigned int vl_dim) : head(nullptr), tail(nullptr) {
    unsigned int index = 0;
    for(index = 0; index < vl_dim; index++)
        addNode(l[index]);
}

template<typename type>
Lista<type>::~Lista() {
    emptyList();
}

template<typename type>
Lista<type>::Lista(const Lista& other) {
    emptyList();
    Node<type> *t_head = other.head;
    while(t_head != nullptr) {
        addNode(t_head->data);
        t_head = t_head -> next;
    }
}

template<typename type>
Lista<type>& Lista<type>::operator=(const Lista<type>& rhs) {
    if (this == &rhs)
        return *this;
    emptyList();
    Node<type> *t_head = rhs.head;
    while(t_head != nullptr) {
        addNode(t_head->data);
        t_head = t_head -> next;
    }
    return *this;
}

template<typename type>
void Lista<type>::emptyList() {
    if(isListEmpty() == false) {
        Node<type> *cur;
        while(head != nullptr) {
            cur = head;
            head = head->next;
            delete cur;
        }
    } else
        cout<<"List already empty"<<endl;
}

template<typename type>
void Lista<type>::addNode(Vector<type> item) {
    Node<type> *tmp = new Node<type>;
    tmp->data = item;
    tmp->next = NULL;

    if(head == nullptr) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tail->next;
    }
}

template<typename type>
Vector<type>& Lista<type>::operator[] (unsigned int index) {
    Node<type> *cur = getElementByIndex(index);
    if(cur == nullptr)
        throw out_of_range("Index out of bounds");
    return cur->data;
}

template<typename type>
Vector<type> Lista<type>::operator[] (unsigned int index) const {
    Node<type> *cur = getElementByIndex(index);
    if(cur == nullptr)
        throw out_of_range("Index out of bounds");
    return cur->data;
}

template<typename type>
Node<type> *Lista<type>::getElementByIndex(unsigned int index) const{
    unsigned long int _index = 0;
    Node<type> *cur = head;
    while(cur->next != nullptr && _index != index) {
        cur = cur->next;
        _index++;
    }
    try {
        if(cur == nullptr) {
            throw "Error : item not found";
            return nullptr;
        }
    } catch (const char* message) {
        std::cout<<message;
    }

    return cur;
}

template<typename type>
void Lista<type>::deleteElementByIndex(unsigned int index) {
    Node<type> *temp = head, *prev;
    for(int i=0; i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}

template<typename type>
void Lista<type>::print(ostream& out) const {
    Node<type> *temp = head;
    while(temp != NULL) {
        out<<temp->data<<" ";
        temp = temp->next;
    }
}

template<typename type>
void Lista<type>::read(istream& in) {
    if(!isListEmpty()){
        unsigned int i, j, v, size;
        while(head != nullptr){
            size = head->data.getSize();
            head->data.resize(0);
            for(i=0; i<size; i++){
                in>>v;
                head->data.pushBack(v);
            }
            head = head->next;
        }
    }else throw zero_length_error("list empty");
}

template<typename type>
unsigned int Lista<type>::getSize() const {
    Node<type> *temp = head;
    counter_help = 0;
    while(temp != nullptr) {
        counter_help++;
        temp = temp->next;
    }
    return counter_help;
}

template<typename type>
void Lista<type>::popBack(){
    Node<type> *temp = head, *pred;
    while(head->next != nullptr){
        pred = head;
        head = head->next;
    }
    pred->next = nullptr;
    delete head;
}

template class Lista<int>;
