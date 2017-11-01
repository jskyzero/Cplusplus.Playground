#include <iostream>
#include <string>
using namespace std;
struct TaoBaoItem {
  int price;
  int volume_of_sales;
};
class SortInterface {
 public:
  virtual ~SortInterface() {};
 
  virtual void DoSort(TaoBaoItem item[], int size) = 0;
};
class SortByPrice : public SortInterface {
 public:
  virtual void DoSort(TaoBaoItem item[], int size){
  	int i,j;
  	TaoBaoItem temp;
  	for (i = 0;i < size - 1; i++){
  		for (j = i + 1; j < size; j++){
  			if (item[j].price < item[i].price){
  				temp = item[i];
  				item[i] = item[j];
  				item[j] = temp;
			  } 
		  }
	  }
  }
};
 
class SortBySales : public SortInterface {
 public:
  virtual void DoSort(TaoBaoItem item[], int size){
  	int i,j;
  	TaoBaoItem temp;
  	for (i = 0;i < size - 1; i++){
  		for (j = i + 1; j < size; j++){
  			if (item[j].volume_of_sales < item[i].volume_of_sales){
  				temp = item[i];
  				item[i] = item[j];
  				item[j] = temp;
			  } 
		  }
	  }
  }
};
class TaoBao {
 public:
  TaoBao(SortInterface* strategy){
  	strategy_ = strategy;
  }
  
  void SetSortStrategy(SortInterface* strategy){
  	strategy_ = strategy;
  }
 
  // Use current strategy_ to do the sort.
void sort(TaoBaoItem item[], int size){
  	strategy_->DoSort(&item[0], size);
}
 
 private:
  SortInterface *strategy_;
};
void printItem(TaoBaoItem arr[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << arr[i].price << " " << arr[i].volume_of_sales << endl;
  }
}

int main(int argc, char *argv[]) {
  TaoBaoItem item[4] = {
    {1, 2},
    {2, 3},
    {5, 1},
    {3, 10}
  };
  SortByPrice price;
  SortBySales sales;

  TaoBao taobao(&price); 
  taobao.sort(item, 4);
  printItem(item, 4);
  
  taobao.SetSortStrategy(&sales);
  taobao.sort(item, 4);
  printItem(item, 4);

  return 0;
}

