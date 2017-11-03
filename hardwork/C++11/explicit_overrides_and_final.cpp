struct Base {
  virtual void some_func(float);
};

struct Derived : Base {
  // virtual void some_func(int) override;   // 錯誤格式：Derive::some_func並沒有override Base::some_func
  virtual void some_func(float) override; // OK：顯式改寫
};

struct Base1 final { };

// struct Derived1 : Base1 { }; // 錯誤格式：class Base1已標明為final

struct Base2 {
    virtual void f() final;
};

struct Derived2 : Base2 {
    // void f(); // 錯誤格式：Base2::f已標明為final
};

int main() {
  
}