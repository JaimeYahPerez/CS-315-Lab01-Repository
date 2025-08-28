#include "SortedVectorDict.hpp"
void SortedVectorDict::insert(int key) {

	if (data.size() == 0) {
		data.push_back(key);
		return;
	}

	auto i = 0;
	while (i < data.size() && key > data[i]) {
		i++;
	}

	data.insert(data.begin() + i, key);

}

std::size_t SortedVectorDict::lookup_idx(int key) const {
	int low = 0;
	int high = data.size() - 1;

	while (low <= high) {
		int mid = ((high - low) / 2) + low;

		if (data[mid] == key) {
			return mid;
		}

		if (data[mid] > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}

	}

	return data.size();
}

bool SortedVectorDict::lookup(int key) const { 

	auto idx = lookup_idx(key);
	return idx != data.size();
}

void SortedVectorDict::remove(int key) {
	auto idx = lookup_idx(key);
	if (idx != data.size()) {
		data.erase(data.begin() + idx);
	}
}