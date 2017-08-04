#progame once
#include<iostream>
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
  virtual void DoSort(TaoBaoItem item[], int size);
};
 
class SortBySales : public SortInterface {
 public:
  virtual void DoSort(TaoBaoItem item[], int size);
};
 
class TaoBao {
 public:
  TaoBao(SortInterface* strategy);
  
  void SetSortStrategy(SortInterface* strategy);
 
  // Use current strategy_ to do the sort.
  void sort(TaoBaoItem item[], int size);
 
 private:
  SortInterface *strategy_;
};
