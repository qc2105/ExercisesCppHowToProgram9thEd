#include "utils.h"
#include <algorithm>

// From n choose r, fill indices with combination(n, k) indices of size r
void getCombinations(size_t n, size_t r, std::vector<std::vector<size_t> > &indices)
{
	std::vector<bool> v(n);
	std::fill(v.begin(), v.begin() + r, true);

	do {
		std::vector<size_t> oneCombination;
		for (size_t i = 0; i < n; ++i) {
			if (v[i]) {
				//std::cout << (i + 1) << " ";
				oneCombination.push_back(i);
			}
		}
		indices.push_back(oneCombination);
		//std::cout << "\n";
	} while (std::prev_permutation(v.begin(), v.end()));
}