#ifndef BIT_BUFFER
#define BIT_BUFFER 1

#include <climits>  // for UINT_MAX
#include <vector>   // for vector

#define INT_BIT_SIZE (sizeof(int) * 8)

// a class to buffer bit
class BitBuffer {
 private:
  std::vector<uint> buffer;
  uint last_int_index;

  constexpr uint bitInInt(uint value, uint index) const {
    //   87654321
    //   01010101       6
    // 01010101         << (8 - 6)
    //        00010101  >> (6 - 1) + (8 - 6) = (8 - 1)
    return (value << (INT_BIT_SIZE - index)) >> (INT_BIT_SIZE - 1);
  }

  constexpr uint intMasker(int begin, int end) const {
    //    87654321
    //    11111111      2   6
    //  11111111        << (8 - 6)
    //     00111111     >> (2 - 1) + (8 - 6) = (8 - 1 + 2 - 6)
    return (UINT_MAX << (INT_BIT_SIZE - end)) >>
           (INT_BIT_SIZE - 1 + begin - end);
  }

  void checkLastIntIndexFull() {
    if (last_int_index == INT_BIT_SIZE) {
      buffer.push_back(0);
      last_int_index = 0;
    }
  }

 public:
  BitBuffer(uint const value, uint const bit_size) {
    buffer = std::vector<uint>{value};
    last_int_index = bit_size;
  }

  BitBuffer() : BitBuffer(0, 0) {}

  uint size() const {
    return (buffer.size() - 1) * INT_BIT_SIZE + last_int_index;
  }

  uint at(int const index) const {
    int buffer_index = index / INT_BIT_SIZE;
    int int_index = index % INT_BIT_SIZE;
    return bitInInt(buffer[buffer_index], int_index + 1);
  }

  BitBuffer& addBit(uint value) {
    checkLastIntIndexFull();
    buffer.back() = (buffer.back() & intMasker(1, last_int_index)) |
                    (value << last_int_index);
    last_int_index += 1;
    return *this;
  }

  BitBuffer& operator+(const BitBuffer& bit_buffer) {
    for (uint i = 0; i < bit_buffer.size(); i++) {
      this->addBit(bit_buffer.at(i));
    }
    return *this;
  }

  std::ostream& operator<<(std::ostream& out) const {
    for (uint i = 0; i < this->size(); i++) {
      out << this->at(i);
    }
    return out;
  }

  friend std::ostream& operator<<(std::ostream& out,
                                  const BitBuffer& bit_buffer) {
    return bit_buffer << out;
  }

  void saveToFile(std::ostream& out) {
    int buffer_index = buffer.size();
    int int_index = last_int_index;
    out.write((char*)&buffer_index, sizeof(buffer_index));
    out.write((char*)&int_index, sizeof(int_index));
    out.write(reinterpret_cast<const char*>(&buffer[0]),
              buffer.size() * sizeof(uint));
  }

  void readFromFile(std::istream& in) {
    int buffer_index, int_index;
    in.read((char*)&buffer_index, sizeof(buffer_index));
    in.read((char*)&int_index, sizeof(int_index));
    last_int_index = int_index;
    buffer = std::vector<uint>(buffer_index);
    in.read(reinterpret_cast<char*>(&buffer[0]), buffer_index * sizeof(uint));
  }
};

struct BitBufferCompare {
  bool operator()(const BitBuffer& lhs, const BitBuffer& rhs) const {
    if (lhs.size() == rhs.size()) {
      for (uint i = 0; i < rhs.size(); i++) {
        if (lhs.at(i) != rhs.at(i))
          return lhs.at(i) < rhs.at(i);
      }
      return false;
    } else {
      return lhs.size() < rhs.size();
    }
  }
};

#endif