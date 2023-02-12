// main.cpp
#include "menu.hpp"

using namespace std;
int main(int argc, char *argv[]) {
  List mySongs;
  Menu mainMenu(mySongs);
  mainMenu.fillData();
  mainMenu.execute();
}