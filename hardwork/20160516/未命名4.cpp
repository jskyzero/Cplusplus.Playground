#include <iostream> 
#include<string>
using namespace std;
  template <typename T>
 int find_lower_bound(T seq[], int n, const T& value)
 {  
    T temp;
    T seq2;
    int index = -1; 
    for(int i = 0; i < n ; i++) {
     seq2 = seq[i];
        if(seq2 < value) {
            temp = seq[i];
            index = i;
            break;
         }
     }
     for(int i = 0; i < n ; i++) {
     	seq2 = seq[i];
        if(seq2 < value) {
            if(temp < seq2 ) {
                temp = seq[i];
            index = i;
             }
         }
     }
     return index;
 }
  int main()
 {
 	string a[] = {"1","2"};
 	std::cout<< find_lower_bound(a,2,a[2]); 
}                                    
