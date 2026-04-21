#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: Wrong usage. Use ./PmergeMe [numbers]" << std::endl;
		return 1;
	}

	try {
		PmergeMe pm;
		pm.run(av + 1);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}