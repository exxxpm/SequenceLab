#include <sequence/sequence.h>
#include <stdexcept>

using namespace sequence;
using namespace std;

SequanceContainer::SequanceContainer(const SequanceContainer& arr) {
	sequence_array.reserve(arr.size());
	for (const auto& seq : arr.sequence_array) {
		sequence_array.push_back(seq->clone_item());
	}
}

int SequanceContainer::size() const {
	return sequence_array.size();
}

void SequanceContainer::remove(int index) {
	if (index >= 0 && index < sequence_array.size()) {
		sequence_array.erase(sequence_array.begin() + index);
	}
}

void SequanceContainer::insert(SequancePtr elem) {
	sequence_array.push_back(elem);
}

void SequanceContainer::swap(SequanceContainer& arr) {
	std::swap(this->sequence_array, arr.sequence_array);
}

SequancePtr SequanceContainer::operator[](int index) const {
	if (index >= 0 && index < sequence_array.size()) {
		return sequence_array[index];
	}
	return nullptr;
}

SequanceContainer& SequanceContainer::operator=(SequanceContainer& arr) {
	if (this != &arr) {
		SequanceContainer temp(arr);
		sequence_array.swap(temp.sequence_array);
	}
	return *this;
}

int sequence::max_summ_nth_elem(const SequanceContainer& sequence, int n) {
	int max_index = -1;
	double max_value = 0;
	const auto size = sequence.size();
	for (int i = 0; i < size; ++i) {
		const auto value = sequence[i]->calc_summ_nth_elem(n);
		if (value >= max_value) {
			max_index = i;
			max_value = value;
		}
	}
	return max_index;
}
