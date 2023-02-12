// song.hpp
#ifndef __SONG_H__
#define __SONG_H__

#include <string>
class Song {
 private:
  std::string name;
  std::string author;
  std::string interpreter;
  int ranking;

 public:
  Song();
  Song(const std::string&, const std::string&, const std::string&, const int&);

  void setName(const std::string&);
  void setAuthor(const std::string&);
  void setInterpreter(const std::string&);
  void setRanking(const int&);

  std::string getName() const;
  std::string getAuthor() const;
  std::string getInterpreter() const;
  int getRanking() const;

  std::string toString() const;
  Song& operator=(const Song&);
};

#endif  // __SONG_H__