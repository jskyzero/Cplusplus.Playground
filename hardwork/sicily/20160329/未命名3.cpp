Complex & operator++() {real += 1; imag += 1; return *this ;}     
     Complex operator++(int){Complex temp = *this;	imag += 1;	real += 1;	return temp;};   
     Complex & operator--(){real -= 1; imag -= 1; return *this;}   
     Complex operator--(int){Complex temp = *this;	imag -= 1;	real -= 1;	return temp;}; 
