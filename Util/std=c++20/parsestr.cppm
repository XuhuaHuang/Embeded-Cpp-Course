/*****************************************************************//**
 * \file   parsestr.cpp
 * \brief  Module declaration for template parse_str function in C++20
 *
 * g++ -o modparsestr.exe parsestr.cpp -std=c++2a
 * ./modparsestr.cpp
 *
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

export module parsestr;
import <iostream>;
import <vector>;
import <sstream>;

export std::vector<int> parst_str(const std::string str) {
	std::vector<int> result;

	if (str.length() < 8E5) {
		std::stringstream ss(str);
		while (ss.good()) {
			std::string substr;
			getline(ss, substr, ',');
			result.push_back(stoi(substr));
		}
	}

	return result;
}