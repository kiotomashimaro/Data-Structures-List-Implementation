// list.hpp
#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <string>

#include "listexception.hpp"
#include "song.hpp"
class List {
 private:
  Song BestRanking[50];
  int last;

  bool isValidPos(const int&);

  void copyAll(const List&);

 public:
  List();
  List(const List&);  // constructor copia

  bool isEmpty();
  bool isFull();

  void insertSong(const int&, const Song&);  // pos, elem

  void deleteSong(const int&);  // pos

  int getFirstPos();
  int getLastPos();
  int getPrevPos(const int&);  // pos
  int getNextPos(const int&);  // pos

  Song retriveSong(const int&);  // pos , retorna elem

  std::string toString();

  void deleteAll();

  List& operator=(const List&);
};

#endif  // __LIST_H__