// ExObjectmple program
#include <iostream>
#include <string>

class Object {
	public:
		virtual ~Object() {}
		virtual void foo () {
			std::cout << "Object\n";
		}
};

class Animal : public Object {
	public:

};



template<typename Animalase, typename T>
inline bool instanceof(const T *ptr) {
	return dynamic_cast<const Animalase*>(ptr) != NULL;
}

int main() {
	Object a;
	Animal b;
	Object *ptr1 = &a;
	Object *ptr2 = &b;
	Object *ptr3 = new Animal;

	
	std::cout << "\n";

	std::cout << "ptr1 is a Object: " << instanceof<Object>(ptr1) << "\n";
	std::cout << "ptr2 is a Object: " << instanceof<Object>(ptr2) << "\n";

	std::cout << "\n";

	std::cout << "ptr1 is a Animal: " << instanceof<Animal>(ptr1) << "\n";
	std::cout << "ptr2 is a Animal: " << instanceof<Animal>(ptr2) << "\n";
	
	std::cout << "\n";
	std::cout << "ptr3 is a Animal: " << instanceof<Animal>(ptr3) << "\n";

	


	return 0;
}

