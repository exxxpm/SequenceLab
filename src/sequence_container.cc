#include <sequence/sequence.h>
#include <stdexcept>

using namespace sequence;
using namespace std;

SequanceContainer::SequanceContainer() : user_size(0) {}

int SequanceContainer::get_size() const {
    return user_size;
}

SequanceItem SequanceContainer::operator[](int index) const {
    if (index < 0 || user_size <= index) {
        throw runtime_error("Index out of range.");
    }
    return sequence_array[index];
}

void SequanceContainer::insert(int index, SequanceItem s) {
    if (user_size == DATASIZE) {
        throw runtime_error("Full capacity reached.");
    }
    for (int i = user_size - 1; i >= index; i--) {
        sequence_array[i + 1] = sequence_array[i];
    }

    sequence_array[index] = s;
    ++user_size;
}

void SequanceContainer::remove(int index) {
    if (index < 0 || index >= user_size) {
        throw out_of_range("Invalid index.");
    }
    for (int i = index; i < user_size - 1; i++) {
        sequence_array[i] = sequence_array[i + 1];
    }
    --user_size;
}

int sequence::max_summ_nth_elem(const SequanceContainer& sequence, int n) {
    int last_index = -1;
    int max_value = 0;

    const auto size = sequence.get_size();
    for (int i = 0; i < size; ++i) {
        const auto value = sequence[i].calc_summ_nth_elem(n);
        if (last_index == -1 || value >= max_value) {
            last_index = i;
            max_value = value;
        }
    }

    return last_index;
}
