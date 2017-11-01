// set_intersection example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_intersection, std::sort
#include <set>       // std::set
#include<numeric>

using namespace std;
int sumOfIntersection(const set<int>& set1, const set<int>& set2) {
	std::set<int> v;                      // 0  0  0  0  0  0  0  0  0  0
	std::set_intersection (set1.begin(),set1.end(), set2.begin(),set2.end(), std::insert_iterator< std::set<int> >(v, v.begin() ));
	return  (accumulate(v.begin() , v.end() , 0));
}
int main () {
	set<int>set1;
	set1.insert(5);
	set1.insert(10);
	set1.insert(15);
	set1.insert(20);
	set1.insert(25);

	set<int>set2 ;
	set2.insert(50);
	set2.insert(40);
	set2.insert(30);
	set2.insert(20);
	set2.insert(10);

	std::set<int> v;                      // 0  0  0  0  0  0  0  0  0  0

	std::set_intersection (set1.begin(),set1.end(), set2.begin(),set2.end(), std::insert_iterator< std::set<int> >(v, v.begin() ));

	std::cout << "The intersection has " <<accumulate(v.begin() , v.end() , 0) << " elements:\n";
	return 0;
}


