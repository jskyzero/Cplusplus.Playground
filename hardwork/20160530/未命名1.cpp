// Problem#: 18479
// Submission#: 4739759
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 18479
// Submission#: 4739674
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>


using namespace std;

template< typename T >

class Set {
	public:

		Set() {
			count = 0 ;
			maxSize = 0;
			date  = NULL;
		}
		Set( int maxSize ) {
			this->count = 0 ;
			this->maxSize =  maxSize;
			date  = new T[ maxSize];
		}

		~Set() {
			delete date;
		}
		Set( const Set& p) {
			this->count = p.getCount();
			this->maxSize = p.getMaxSize();
			delete date;
			this->date = new T[maxSize];
			T* ptr = p.getData();
			int n = count;
			while (n--) {
				date[n] = ptr[n];
			}
		}
		void operator=( const Set& p ) {
			this->count = p.getCount();
			this->maxSize = p.getMaxSize();
			delete date;
			this->date = new T[maxSize];
			T* ptr = p.getData();
			int n = count;
			while (n--) {
				date[n] = ptr[n];
			}
		}
		bool insert( T newItem ) {
			int n = count;
			while (n--) {
				if(date[n] == newItem)
					return 0;
			}
			date[count] = newItem;
			count++;
			return 1;
		}
		bool erase( T targetItem ) {
			int N = 0;
			for(int i = 0; i<count; i++) {
				if(date[i] == targetItem) {
					N = i;
					break;
				}
				if(i == count-1) return 0;
			}
			for(int i = N ; i<count-1; i++) {
				date[i] = date[i+1];
			}
			count--;
			return 1;
		}


		void print() const {
			int n = count;
			for(int i =0; i<count; i++)
				cout << date[i] <<' ';
			cout <<endl;
		}
		T* getData() const {
			return date;
		}
		int getCount() const {
			return count;
		}
		int getMaxSize() const {
			return maxSize;
		}

		Set operator+( const Set& s ) {
			int N = s.getMaxSize() + maxSize;
			Set<T> temp( N );

			int ns = s.getCount();
			T* p = s.getData();

			for(int i =0; i<count; i++)
				temp.insert(date[i]);

			bool same = 0;
			for(int i =0; i<ns; i++) {

				temp.insert(p[i]);
			}
			return temp;
		}
		Set operator-( const Set& s ) {

			int N = s.getMaxSize() + maxSize;
			Set<T>temp( N );


			int ns = s.getCount();
			T* p = s.getData();
			int n = count;
			for(int i =0; i<count; i++)
				temp.insert(date[i]);

			bool same = 0;
			for(int i = 0; i < ns; i++)
				temp.erase(p[i]);

			return temp;
		}
	private:
		int count ;
		int maxSize ;
		T* date ;
};
int main() {

	Set<int> s1( 10 ), s2( 10 ), s_plus, s_minus ;

	s1.insert( 1 ) ;
	s1.insert( 2 ) ;
	s1.insert( 2 ) ;
	s1.insert( 4 ) ;
	cout << "Items in s1 are : " ;
	s1.print() ;

	s2.insert( 3 ) ;
	s2.insert( 3 ) ;
	s2.insert( 1 ) ;
	s2.insert( 2 ) ;
	cout << "Items in s2 are: " ;
	s2.print() ;

	s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;

	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
}
