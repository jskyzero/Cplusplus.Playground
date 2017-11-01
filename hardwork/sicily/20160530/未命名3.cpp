#include <iostream>
#include <vector>
#include <algorithm> sort
using namespace std;


template< typename T >
class SortableArray 
{
	private :
		vector<T> a;
		typename vector<T>::iterator it;
	public :
		SortableArray(int n = 0) {
		
		}
		void pushBack(T temp) {
			a.push_back(temp);
		}
		void sort() {
			std::stable_sort(a.begin(),a.end());
		}
		void printArray() {
			
			for(it = a.begin();it!=a.end();it++) {
				cout << *it;
				if(it!=a.end()-1) cout << " ";
				else cout <<endl;
			} 
		}
		void printfArray() {
			for(it = a.begin();it!=a.end();it++) {
				
				cout << *it;
				if(it!=a.end()-1) cout << " ";
				else cout <<endl;
			} 
		}
		 		
};


int main() {

	int maxSize = 10 ;

	SortableArray< int > arr( maxSize ) ;

	arr.pushBack( 45 ) ;

	arr.pushBack( 32 ) ;

	arr.pushBack( 41 ) ;

	arr.printArray() ;

	arr.sort() ;

	arr.printfArray() ;
}
