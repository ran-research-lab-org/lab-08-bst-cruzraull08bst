#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BinarySearchTree.hpp"
#include "doctest.h"
#include <sstream>
#include <stdexcept>

using namespace std;

TEST_CASE("BinarySearchTree basic operations") {
  BinarySearchTree<int> B;
  B.insert(10);

  B.insert(4);
  B.insert(2);
  B.insert(15);
  B.insert(31);
  B.insert(1);
  B.insert(56);
  CHECK(B.toInorderStr() == "1,2,4,10,15,31,56");
  CHECK(B.BFT() == "[[10],[4,15],[2,31],[1,56]]");
  BinarySearchTree<int> C;
  for (auto e :
       {16, 8, 24, 28, 20, 12, 4, 2, 6, 10, 14, 18, 22, 26, 30, 15, 7, 3}) {
    C.insert(e);
  }

  CHECK(C.toInorderStr() == "2,3,4,6,7,8,10,12,14,15,16,18,20,22,24,26,28,30");
  CHECK(C.BFT() ==
        "[[16],[8,24],[4,12,20,28],[2,6,10,14,18,22,26,30],[3,7,15]]");
  
  BinarySearchTree<int> D;
  CHECK(D.BFT()== "[]");

  D.insert(8);
  D.insert(3);
  D.insert(10);
  D.insert(1);
  D.insert(6);
  D.insert(14);
  D.insert(4);
  D.insert(7);
  D.insert(13);

  CHECK(D.BFT()== "[[8],[3,10],[1,6,14],[4,7,13]]");
  CHECK(D.BFT() != "[[8],[3,10],[4,7,13],[1,6,14]]");

  D.remove(10);
  D.remove(1);
  D.remove(13);

  CHECK(D.toInorderStr() == "3,4,6,7,8,14");

  D.insert(44);
  D.insert(0);
  D.insert(5);

  CHECK(D.toInorderStr() == "0,3,4,5,6,7,8,14,44");

  D.BFT();

}
