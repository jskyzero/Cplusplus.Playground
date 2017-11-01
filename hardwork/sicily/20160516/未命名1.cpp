
#include<cstring>
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>  

  template <typename T>
 int find_lower_bound(T seq[], int n, const T& value)
 {  
 	std::vector<T> v(seq,seq+n);
    std::sort (v.begin(), v.end());
    std::vector<int>::iterator low,up;
  	low=std::lower_bound (v.begin(), v.end(), value);
  	if(0 == (low- v.begin()))return -1;
	else return (low- v.begin());
 }
 
 int main()
 {
 	std::cout << ("123"<"234");
}                                 
