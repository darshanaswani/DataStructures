#include <iostream>
#include <unordered_map>
using namespace std;

class MyArray {
public:
  int length = 0;
  unordered_map<int, int> data;

public:
  int get(int index) {
    if (!length) {
      return 0;
    }
    return data.at(index);
  }

  int push(int item) {
    data.insert({length, item});
    length++;
    return length;
  }

  int pop() {
    int lastItem = data[length - 1];
    data.erase(length - 1);
    length--;
    return lastItem;
  }

  int remove(int index) {
    int lastItem = data[index];
    shiftItems(index);
    return lastItem;
  }

  void shiftItems(int index) {
    for (int i = index; i < length; i++) {
      data[i] = data[i + 1];
    }
    data.erase(length - 1);
    length--;
  }
};

int main() {
  MyArray array1;
  array1.push(56);
  array1.push(39);
  array1.push(45);
  cout << array1.remove(1);
  cout << array1.length;
}
