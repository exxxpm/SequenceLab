#include <sequence/sequence.h>
#include <stdexcept>

using namespace sequence;
using namespace std;

SequanceContainer::~SequanceContainer() {
    for (int i = 0; i < user_size; i++) {
        delete sequence_array[i];
    }
    delete[] sequence_array;
}

SequanceContainer::SequanceContainer(const SequanceContainer& arr) {
    user_size = arr.user_size;
    sequence_array = new SequanceItem * [user_size];
    for (int i = 0; i < user_size; i++) {
        sequence_array[i] = new SequanceItem(*arr.sequence_array[i]);
    }
}

SequanceContainer::SequanceContainer(int size) {
    if (size < 0) throw std::invalid_argument("Size of array should be positive");
    user_size = size;
    sequence_array = new SequanceItem * [size];
    for (int i = 0; i < size; i++) {
        sequence_array[i] = new SequanceItem();
    }
}

SequanceItem& SequanceContainer::operator[](int index) {
    if (index < 0 || index >= user_size) {
        throw out_of_range("Index out of range.");
    }
    return *(sequence_array[index]);
}

SequanceItem SequanceContainer::operator[](int index) const {
    if (index < 0 || index >= user_size) {
        throw out_of_range("Index out of range.");
    }
    return *(sequence_array[index]);
}

SequanceContainer& ::SequanceContainer::operator=(SequanceContainer arr) {
    this->swap(arr);
    return *this;
}

int SequanceContainer::get_size() const {
    return user_size;
}

void SequanceContainer::swap(SequanceContainer& arr) {
    std::swap(user_size, arr.user_size);
    std::swap(sequence_array, arr.sequence_array);
}

void SequanceContainer::insert(int index, SequanceItem& elem) {
    if (index > user_size || index < 0) { throw out_of_range("Invalid index");}
    SequanceItem** new_sequence_array = new SequanceItem * [user_size + 1];

    for (int i = 0; i < index; i++) {
        new_sequence_array[i] = sequence_array[i];
    }

    new_sequence_array[index] = new SequanceItem(elem);
    ++user_size;

    for (int i = index + 1; i < user_size; i++) {
        new_sequence_array[i] = sequence_array[i - 1];
    }

    delete[] sequence_array;
    sequence_array = new_sequence_array;
}


void SequanceContainer::remove(int index) {
    if (index < 0 || index >= user_size) { throw out_of_range("Invalid index."); }

    SequanceItem** ptr = new SequanceItem * [user_size - 1];

    std::copy(sequence_array, sequence_array + index, ptr);
    std::copy(sequence_array + index + 1, sequence_array + user_size, ptr + index);

    delete sequence_array[index];
    delete[] sequence_array;

    sequence_array = ptr;
    user_size--;
}


int sequence::max_summ_nth_elem(const SequanceContainer& sequence, int n) {
    int max_index = -1;
    double max_value = 0;
    const auto size = sequence.get_size();
    for (int i = 0; i < size; ++i) {
        const auto value = sequence[i].calc_summ_nth_elem(n);
        if (value >= max_value) {
            max_index = i;
            max_value = value;
        }
    }
    return max_index;
}
