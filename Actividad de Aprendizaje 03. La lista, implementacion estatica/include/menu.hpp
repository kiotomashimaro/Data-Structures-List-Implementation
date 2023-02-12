// menu.hpp
#ifndef __MENU_H__
#define __MENU_H__
#include "list.hpp"

class Menu {
 private:
  List* menuListPtr;

 public:
  Menu();
  Menu(List&);

  void fillData();
  void execute();
  void addNewSong();
  void removeSong();
  bool exit();
};

#endif  // __MENU_H__