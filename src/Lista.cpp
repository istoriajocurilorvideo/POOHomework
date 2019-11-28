#include "Lista.h"
unsigned int Lista::counter_help = 0;

Lista::Lista() : head(nullptr), tail(nullptr) {}

Lista::Lista(Vector *l, unsigned int vl_dim) : head(nullptr), tail(nullptr) {
    unsigned int index = 0;
    for(index = 0; index < vl_dim; index++)
        addNode(l[index]);
}

Lista::~Lista() {
    emptyList();
}

Lista::Lista(const Lista& other) {
    emptyList();
    Node *t_head = other.head;
    while(t_head != nullptr) {
        addNode(t_head->data);
        t_head = t_head -> next;
    }
}

Lista& Lista::operator=(const Lista& rhs) {
    if (this == &rhs)
        return *this;
    emptyList();
    Node *t_head = rhs.head;
    while(t_head != nullptr) {
        addNode(t_head->data);
        t_head = t_head -> next;
    }
    return *this;
}

void Lista::emptyList() {
    if(isListEmpty() == false) {
        Node *cur;
        while(head != nullptr) {
            cur = head;
            head = head->next;
            delete cur;
        }
    } else
        cout<<"List already empty"<<endl;
}

void Lista::addNode(Vector item) {
    Node *tmp = new Node;
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


Vector& Lista::operator[] (unsigned int index) {
    Node *cur = getElementByIndex(index);
    if(cur == nullptr)
        throw out_of_range("Index out of bounds");
    return cur->data;
}

Vector Lista::operator[] (unsigned int index) const {
    Node *cur = getElementByIndex(index);
    if(cur == nullptr)
        throw out_of_range("Index out of bounds");
    return cur->data;
}

Node *Lista::getElementByIndex(unsigned int index) const{
    unsigned long int _index = 0;
    Node *cur = head;
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

void Lista::deleteElementByIndex(unsigned int index) {
    Node *temp = head, *prev;
    for(int i=0; i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}

void Lista::print(ostream& out) const {
    Node *temp = head;
    while(temp != NULL) {
        out<<temp->data<<" ";
        temp = temp->next;
    }
}

void Lista::read(istream& in) {
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

unsigned int Lista::getSize() const {
    Node *temp = head;
    counter_help = 0;
    while(temp != nullptr) {
        counter_help++;
        temp = temp->next;
    }
    return counter_help;
}

void Lista::popBack(){
    Node *temp = head, *pred;
    while(head->next != nullptr){
        pred = head;
        head = head->next;
    }
    pred->next = nullptr;
    delete head;
}
