#include "doubly-linked-list.h"

DoublyLinkedList::Node::Node(DataType data) {
    value = data;
    next = nullptr;
    prev = nullptr;
}


DoublyLinkedList::DoublyLinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}


DoublyLinkedList::~DoublyLinkedList() {
    if (size_ == 0)
        return;
    for(int i=0; i<size_; i++)
    {
        Node *temp = head_;
        head_ = head_ -> next;
        delete temp;
        temp = nullptr;
    }
    delete head_;
    head_ = nullptr;
    delete tail_;
    tail_ = nullptr;
    size_ = 0;
}


unsigned int DoublyLinkedList::size() const {
    return size_;
}


unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}


bool DoublyLinkedList::empty() const {
    if (size_ == 0)
        return true;
    else
        return false;
}


bool DoublyLinkedList::full() const {
    if (size_ == CAPACITY)
        return true;
    else
        return false;
}


DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    if (index >= size_)
        return (tail_ -> value);
    else{
        Node *current = head_;
        for(int i = 0; i<index; i++){
            current = current->next;
        }
        return (current->value);
    }
}


unsigned int DoublyLinkedList::search(DataType value) const {
    Node *current = head_;
    for(int i = 0; i<size_; i++)
        {
        if (current->value == value)
            {
            return i;
            }
        current = current->next;
        }
    return size_;
}


void DoublyLinkedList::print() const {
    if (size_ == 0)
    {
    std::cout << "List is empty";
    return;
    }

    else
    {
    Node *temp = head_;
    while (temp != nullptr)
        {
        std::cout << temp->value << " ";
        temp = temp->next;
        }
    }
}


DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    if(index == 0){
        return head_;
    }
    else {
        Node *current = head_;
        for (int i = 0; i < (index - 1); i++) {
            current = current->next;
        }
        return (current->next);
    }
}


bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if (index > size_ || full())
    {
        return false;
    }

    if (index == 0)
    {
        insert_front(value);
        return true;
    }

    if (index == size_)
    {
        insert_back(value);
        return true;
    }

    else
    {
        Node *newNode = new Node(value);
        Node *after = getNode(index);
        Node *before = after->prev;
        newNode->prev = before;
        newNode->next = after;
        after->prev = newNode;
        before->next = newNode;
        size_ ++;
        return true;
    }
}


bool DoublyLinkedList::insert_front(DataType value) {
    if (full())
        return false;

    Node *newNode = new Node(value);

    if (size_ == 0)
    {
        head_ = newNode;
        tail_ = head_;
        size_ = 1;
        return true;
    }

    else
    {
        newNode->next = head_;
        head_->prev = newNode;
        head_ = newNode;
        size_ ++;
        return true;
    }

}


bool DoublyLinkedList::insert_back(DataType value) {
    if (full())
        return false;

    Node *newNode = new Node(value);

    if (size_ == 0)
    {
        head_ = newNode;
        tail_ = head_;
        size_ = 1;
        return true;
    }

    else
    {
        newNode->prev = tail_;
        tail_->next = newNode;
        tail_ = newNode;
        size_ ++;
        return true;
    }

}


bool DoublyLinkedList::remove(unsigned int index) {
    if (index >= size_ || empty())
        return false;

    if (size_ == 1)
    {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        return true;
    }

    if (index == 0)
    {
        Node *temp = head_;
        head_ = head_->next;
        delete temp;
        temp = nullptr;
        size_ --;
        return true;
    }

    if (index == (size_ - 1))
    {
        Node *temp = tail_;
        tail_ = tail_->prev;
        delete temp;
        temp = nullptr;
        size_ --;
        return true;
    }

    else
    {
        Node *current = getNode(index);
        Node *previous = current->prev;
        Node *after = current->next;

        previous->next = after;
        after->prev = previous;
        delete current;
        current = nullptr;
        size_ --;
        return true;
    }

}


bool DoublyLinkedList::remove_front() {
    if (empty())
        return false;

    if (size_ == 1)
    {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        return true;
    }

    Node *temp = head_;
    head_ = head_->next;
    delete temp;
    temp = nullptr;
    size_ --;
    return true;
}


bool DoublyLinkedList::remove_back() {
    if (empty())
        return false;

    if (size_ == 1)
    {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        return true;
    }

    Node *temp = tail_;
    tail_ = tail_->prev;
    delete temp;
    temp = nullptr;
    size_ --;
    return true;
}


bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if (index >= size_ || empty())
        return false;

    Node *current = getNode(index);
    current->value = value;
    return true;
}
