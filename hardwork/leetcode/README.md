# LeetCode

> this is some leetcode solution written in c++

## Tips

+ Can I initialize an STL vector with 10 of the same integer in an initializer list?
```
int number_of_elements = 10;
int default_value = 1;
std::vector<int> vec(number_of_elements, default_value);
```

+ How to sum up elements of a C++ vector?
```
for (auto& n : vector)
    sum_of_elems += n;
```