#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
vector<T> vec_fill(T x) {
	vector<T> result;
	for(int i = 0; i < 10; i++) {
		result.push_back(i + x);
	}
	return result;
}

template<typename U>
vector<U> order(U& a, U& b, U& c) {
	vector <U> results;
	results.push_back(a);
	results.push_back(b);
	results.push_back(c);
	for(int i = 0; i < results.size(); i++) {
		for (int j = i + 1; j < results.size(); j++) {
			if (results[i] < results[j]) {
				U temp = results[i];
				results[i] = results[j];
				results[j] = temp;
			}
		}
	}
	return results;
}

template<typename V>
bool search(V begin, V end, int x) {
	//vector<V> result;
	for (V it = begin; it != end; ++it) {
		if (*it == x) {
			return true;
		}
	}

	return false;
}

int main()
{
	vector<int> num = vec_fill(0);
	assert(num[0] == 0);
	assert(num[9] == 9);

	vector<int> sorted = order(num[3], num[5], num[9]);
	assert(sorted[0] == 9);
	assert(sorted[1] == 5);
	assert(sorted[2] == 3);

	assert(search(num.begin(), num.end(), 5));
	assert(search(num.begin(), num.end(), 9));

	cout << "All tests passed!" << endl;



}
