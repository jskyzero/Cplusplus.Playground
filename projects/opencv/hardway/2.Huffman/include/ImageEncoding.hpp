#ifndef IMAGE_ENCODING
#define IMAGE_ENCODING 1

#include <functional>  // for function
#include <iostream>    // for cout
#include <map>         // for map
#include <opencv2/opencv.hpp>
#include <queue>   // for queue
#include <vector>  // for vector

#include <Huffman.hpp>

class ImageEncoding {
 public:
  void compress(char const* const file_path) {
    auto img = cv::imread(file_path);
    if (img.data == NULL) {
      perror("fail to open file");
      exit(-1);
    }

    auto weight_table = std::vector<uint>(256, 0);
    for (int x = 0; x < img.rows; x++) {
      for (int y = 0; y < img.cols; y++) {
        auto vec = img.at<cv::Vec3b>(x, y);
        for (int i = 0; i < 3; i++) {
          weight_table[vec[i]]++;
        }
      }
    }

    // transform table
    auto transform_table = std::map<uchar, BitBuffer>();
    Hunffman::huffmanEncoding(weight_table, transform_table);

    auto huffman_bits = BitBuffer();
    for (int x = 0; x < img.rows; x++) {
      for (int y = 0; y < img.cols; y++) {
        auto vec = img.at<cv::Vec3b>(x, y);
        for (int i = 0; i < 3; i++) {
          // std::cout << (uint)vec[i] << std::endl;
          huffman_bits + transform_table[vec[i]];
        }
      }
    }
    std::ofstream out(std::string(file_path) + ".huffman",
                      std::ofstream::out | std::ofstream::binary);
    int width = img.cols, height = img.rows;

    out.write((char*)&width, sizeof(width));
    out.write((char*)&height, sizeof(height));
    out.write(reinterpret_cast<const char*>(&weight_table[0]),
              weight_table.size() * sizeof(uint));
    huffman_bits.saveToFile(out);
    out.close();

#ifdef DEBUG
    int size = 0;
    for (auto i : transform_table) {
      std::cout << (uint)i.first << " " << i.second << std::endl;
      size += weight_table[i.first] * (i.second.size() - 1);
    }
    std::cout << size << std::endl;
#endif
  }

  void decompress(char const* const file_path) {
    int width, height;
    auto huffman_bits = BitBuffer();
    auto weight_table = std::vector<uint>(256, 0);
    auto transform_table = std::map<uchar, BitBuffer>();
    auto back_transform_table = std::map<BitBuffer, uchar, BitBufferCompare>();

    std::ifstream in(file_path, std::ios::in | std::ios::binary);
    in.read((char*)&width, sizeof(width));
    in.read((char*)&height, sizeof(height));
    in.read(reinterpret_cast<char*>(&weight_table[0]),
            weight_table.size() * sizeof(uint));
    huffman_bits.readFromFile(in);

    Hunffman::huffmanEncoding(weight_table, transform_table);
#ifdef DEBUG
    int size = 0;
    for (auto i : transform_table) {
      std::cout << (uint)i.first << " " << i.second << std::endl;
      size += weight_table[i.first] * (i.second.size() - 1);
    }
    std::cout << size << std::endl;
#endif
    for (auto i : transform_table) {
      auto new_bits_buffer = i.second;
      back_transform_table[new_bits_buffer] = i.first;
    }

#ifdef DEBUG
    int size = 0;
    for (auto i : back_transform_table) {
      std::cout << i.first << " " << (uint)i.second << std::endl;
    }
    std::cout << size << std::endl;
#endif

    auto new_img = cv::Mat(height, width, CV_8UC3);
    auto bits = BitBuffer();
    auto value_queue = std::queue<uchar>();
    for (uint i = 0; i < huffman_bits.size(); i++) {
      bits.addBit(huffman_bits.at(i));
      if (back_transform_table.find(bits) == back_transform_table.end()) {
        // not found
      } else {
        value_queue.push(back_transform_table[bits]);
        // std::cout << (uint)back_transform_table[bits] << std::endl;
        bits = BitBuffer();
      }
    }

    for (int x = 0; x < new_img.rows; x++) {
      for (int y = 0; y < new_img.cols; y++) {
        for (int i = 0; i < 3; i++) {
          new_img.at<cv::Vec3b>(x, y)[i] = value_queue.front();
          value_queue.pop();
        }
      }
    }

    cv::imwrite(std::string(file_path) + ".bmp", new_img);
  }
};

#endif