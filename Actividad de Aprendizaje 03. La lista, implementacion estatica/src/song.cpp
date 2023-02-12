// song.cpp
#include "song.hpp"
Song::Song() : name(""), author(""), interpreter(""), ranking(0) {}

Song::Song(const std::string& n, const std::string& a, const std::string& in,
           const int& r)
    : name(n), author(a), interpreter(in), ranking(r) {}

void Song::setName(const std::string& n) { name = n; }

void Song::setAuthor(const std::string& a) { author = a; }

void Song::setInterpreter(const std::string& in) { interpreter = in; }

void Song::setRanking(const int& r) { ranking = r; }

std::string Song::getName() const { return name; }

std::string Song::getAuthor() const { return author; }

std::string Song::getInterpreter() const { return interpreter; }

int Song::getRanking() const { return ranking; }

std::string Song::toString() const {
  std::string temp;
  char output[10];

  temp += name;
  temp.resize(20, ' ');
  temp += " | ";
  temp += author;
  temp.resize(40, ' ');
  temp += " | ";
  temp += interpreter;
  temp.resize(80, ' ');
  temp += " | ";
  sprintf(output, "%i", ranking);
  temp += output;

  return temp;
}

Song& Song::operator=(const Song& other) {
  this->name = other.name;
  this->author = other.author;
  this->interpreter = other.interpreter;
  this->ranking = other.ranking;

  return *this;
}
