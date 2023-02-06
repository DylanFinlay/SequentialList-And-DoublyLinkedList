#include "sequential-list.h"

SequentialList::SequentialList(unsigned int cap) {
data_ = new DataType[cap];
capacity_ = cap;
size_ = 0;
}


SequentialList::~SequentialList() {
delete[]data_;
data_ = nullptr;
}


unsigned int SequentialList::size() const {
return size_;
}


unsigned int SequentialList::capacity() const {
return capacity_;
}


bool SequentialList::empty() const {
if(size_ == 0)
    return true;
else
    return false;
}


bool SequentialList::full() const {
if (size_ == capacity_)
    return true;
else
    return false;
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
if (index >= size_)
    return data_[size_ -1];
else
    return data_[index];
}


unsigned int SequentialList::search(DataType val) const {
for(int i=0; i<size_; i++)
{
    if (data_[i] == val)
    return i;
}
return size_;
}


void SequentialList::print() const {
if(empty() == true){
    std::cout << "List is empty";
    return;
}
else {
    std::cout << "Elements of array: ";
    for (int i = 0; i < capacity_; i++) {
        std::cout << data_[i] << " ";
    }
}
}


bool SequentialList::insert(DataType val, unsigned int index) {
if (index > size_ || full() == true)
    return false;
size_ ++;
for (int i = size_; i > index; i--){
    data_[i] = data_[i - 1];
}
data_[index] = val;
return true;
}


bool SequentialList::insert_front(DataType val) {
if (full() == true)
    return false;
size_ ++;
for (int i = size_; i > 0; i--){
    data_[i] = data_[i - 1];
}
data_[0] = val;
return true;
}


bool SequentialList::insert_back(DataType val) {
if (full() == true)
    return false;
data_[size_] = val;
size_ ++;
return true;
}


bool SequentialList::remove(unsigned int index) {
if (index >= capacity_ || empty())
    return false;
for (int i = index; i < (size_ - 1) ;i++){
data_[i] = data_[i+1];
}
data_[size_ - 1] = 0;
size_ --;
return true;
}


bool SequentialList::remove_front() {
if (empty() == true)
    return false;
for (int i=0; i < (size_ - 1); i++){
    data_[i] = data_[i+1];
}
    data_[size_ - 1] = 0;
    size_ --;
    return true;
}


bool SequentialList::remove_back() {
if (empty() == true)
    return false;
data_[size_ - 1] = 0;
size_ --;
return true;
}


bool SequentialList::replace(unsigned int index, DataType val) {
if (index >= capacity_ || data_[index] == 0)
    return false;
data_[index] = val;
return true;
}
