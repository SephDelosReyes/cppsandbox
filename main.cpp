#include <iostream>
#include <new>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void *operator new(size_t size) {
  cout << "Allocated " << size << " bytes" << endl;
  return malloc(size);
}

void ptrThings() {
  cout << "--testing pointers--" << endl;
  int a = 100;
  int *addr = &a;
  int **doublePtr = &addr;
  // base case
  cout << "int a " << a << endl;
  // location of a
  cout << "addr of a " << addr << endl;
  // dereference - pointer back the address. i.e. what am i?
  cout << "*addr of a " << *addr << endl;
  // location of the location.
  cout << "&addr of a " << &addr << endl;
  cout << "pointer to addr of addr" << doublePtr << endl;
}

void testStrings() {

  string smallString = "012345678901234";
  cout << smallString << endl;
  string bigString =
      "asdfasdhfkajshdfkjhasdhfkjahsdkfjhakjsdhfkjh012345678901234";
  cout << bigString << endl;
}

void testDynamicArraysWithPointers() {
  int arrSize = 0;
  cout << "enter size of array: ";
  cin >> arrSize;

  int *dynarray = new int[arrSize];

  for (int i = 0; i < arrSize; i++) {
    cout << "dynarray[" << i << "]:" << dynarray[i] << endl;
  }
}

void testVectors() {
  vector<string> testVector;
  cout << testVector.empty();

  testVector.push_back("something1");
  testVector.push_back("something2");

  cout << testVector.data();
}

enum Way { UP, DOWN, LEFT, RIGHT };

struct Person {
  int age;
  string name;
  Way move() { return UP; };
};
Person *testStructs() {
  Person *person = new Person;
  person->age = 100;
  // samplenametestnamelongname
  person->name = "leavemealone";
  cout << "addr of person" << person << endl;
  cout << "in struct" << endl;
  cout << "name: " << person->name << endl;
  cout << "age: " << person->age << endl;
  return person;
}

// refresher if I still know my algo shit.
// also testing out pointer arithmetic coz arrays are just contiguous pointers
bool binarySearch(int *arr, int size, int val) {
  int low = 0, high = size - 1, mid = (size / 2) - 1;
  while (*(arr + mid) != val) {
    if (low >= high) {
      cout << "search digit " << val << " not found\n";
      return false;
    }
    if (*(arr + mid) > val) {
      high = mid - 1;
      mid = (high - low) / 2;
    } else if (*(arr + mid) < val) {
      low = mid + 1;
      mid = (high + low) / 2;
    } else {
      break;
    }
  }
  cout << "search digit " << val << " found at arr[" << mid << "]\n";
  return true;
}

void testBinarySearch() {
  int testArray[10] = {1, 3, 5, 6, 8, 11, 15, 23, 34};
  int testArray2[13] = {1, 3, 5, 6, 8, 11, 15, 23, 34, 37, 56, 99};

  cout << "even case [1, 3, 5, 6, 8, 11, 15, 23, 34]\n";
  binarySearch(testArray, 10, 0);
  binarySearch(testArray, 10, 100);
  binarySearch(testArray, 10, 1);
  binarySearch(testArray, 10, 5);
  binarySearch(testArray, 10, 4);
  binarySearch(testArray, 10, 34);
  binarySearch(testArray, 10, 15);
  binarySearch(testArray, 10, 22);
  cout << "odd case [1, 3, 5, 6, 8, 11, 15, 23, 34, 37, 56, 99]\n";
  binarySearch(testArray2, 13, 0);
  binarySearch(testArray2, 13, 100);
  binarySearch(testArray2, 13, 1);
  binarySearch(testArray2, 13, 8);
  binarySearch(testArray2, 13, 7);
  binarySearch(testArray2, 13, 99);
  binarySearch(testArray2, 13, 37);
  binarySearch(testArray2, 13, 72);
}

int main() {
  // testVectors();
  // testDynamicArraysWithPointers();
  // testStrings();
  //
  // Person *person = testStructs();
  // cout << "x addr of person" << person << endl;
  // cout << "out struct" << endl;
  // cout << "name: " << person->name << endl;
  // cout << "age: " << person->age << endl;
  // delete person;
  testBinarySearch();
  return 0;
}
