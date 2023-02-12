// list.cpp
#include "list.hpp"

bool List::isValidPos(const int& pos) { return pos >= 0 and pos <= last; }

void List::copyAll(const List& otherList) {
  for (size_t i = 0; i < otherList.last; i++) {
    BestRanking[i] = otherList.BestRanking[i];
  }
  last = otherList.last;
}

List::List() : last(-1) {}

List::List(const List& otherList) { copyAll(otherList); }

bool List::isEmpty() { return last == -1; }

bool List::isFull() { return last == 499; }

void List::insertSong(const int& pos,
                      const Song& element)  // pos +1 becouse the insert is
                                            // after the point of interes
{
  if (isFull()) {
    throw ListException("Desbordamiento de datos, insertSong()");
  }
  if (pos != -1 and !isValidPos(pos)) {
    // std::cout << "error";
    throw ListException("Posicion invalida, insertSong()");
  }

  int i(last);
  for (i; i > pos; i--) {
    BestRanking[i + 1] = BestRanking[i];
  }
  BestRanking[pos + 1] = element;
  last++;
}

void List::deleteSong(const int& pos) {
  if (!isValidPos(pos)) {
    throw ListException("Posicion invalida, deleteSong()");
  }
  int i(pos);
  for (i; i < last; i++) {
    BestRanking[i] = BestRanking[i + 1];
  }
  last--;
}

int List::getFirstPos() {
  if (isEmpty()) {
    return -1;
  }
  return 0;
}

int List::getLastPos() { return last; }

int List::getPrevPos(const int& pos) {
  if (pos == getFirstPos() or !isValidPos(pos)) {
    return -1;
  }
  return pos - 1;
}

int List::getNextPos(const int& pos) {
  if (pos == last or !isValidPos(pos)) {
    return -1;
  }

  return pos + 1;
}

Song List::retriveSong(const int& pos) {
  if (!isValidPos(pos)) {
    throw ListException("Posicion invalida, retriveSong()");
  }
  return BestRanking[pos];
}

std::string List::toString() {
  std::string temp;
  char output[50];
  for (int i = getFirstPos(); i <= last; i++) {
    if (getFirstPos() == -1) {
      break;
    }

    sprintf(output, "%i", i);
    temp += output;
    temp += ".";
    temp += BestRanking[i].toString();
    temp += "\n";
  }
  return temp;
}

void List::deleteAll() { last = -1; }

List& List::operator=(const List& otherList) {
  copyAll(otherList);
  return *this;
}
