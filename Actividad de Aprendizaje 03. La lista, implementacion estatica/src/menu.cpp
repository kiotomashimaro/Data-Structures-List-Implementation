// menu.cpp
#include "menu.hpp"
using namespace std;
Menu::Menu() {}
Menu::Menu(List& reciveList) { menuListPtr = &reciveList; }

void Menu::fillData() {
  int i = menuListPtr->getFirstPos();  // i =-1
  string name, author, interpreter;
  int ranking;
  while (i <= 26)  // FILLS 28 SONGS
  {
    cout << "Name: " << endl;
    getline(cin, name);
    cout << "Author: " << endl;
    getline(cin, author);
    cout << "Interpreter: " << endl;
    getline(cin, interpreter);
    cout << "Ranking: " << endl;
    cin >> ranking;
    cin.ignore();
    Song temporalSong(name, author, interpreter, ranking);
    menuListPtr->insertSong(menuListPtr->getLastPos(), temporalSong);
    i++;
  }
}

void Menu::execute() {
  int option;
  bool flag = true;
  while (flag) {
    system("cls");
    cout << "---------------------------------PLAYLIST DE "
            "MUSICA---------------------------------"
         << endl;
    string output;
    output += "\nNOMBRE";
    output.resize(21, ' ');
    output += " | ";
    output += "AUTOR";
    output.resize(41, ' ');
    output += " | ";
    output += "INTERPRETE";
    output.resize(81, ' ');
    output += " | ";
    output += "RANKING\n";
    cout << output << endl;
    cout << menuListPtr->toString();
    cout << "\nElige una opcion: \n [1]Agregar Cancion \n [2]Eliminar "
            "Cancion\n [3]Salir\n";
    cin >> option;
    switch (option) {
      case 1:
        addNewSong();
        break;
      case 2:
        removeSong();
        break;
      case 3:
        flag = exit();
        break;
      default:
        break;
    }
  }
}

void Menu::addNewSong() {
  int pos, ranking;
  string name, author, interpreter;
  cout << "Dime la posicion de la cancion: \n";
  cin >> pos;
  cin.ignore();
  cout << "Nombre: " << endl;
  getline(cin, name);
  cout << "Autor: " << endl;
  getline(cin, author);
  cout << "Interprete: " << endl;
  getline(cin, interpreter);
  cout << "Ranking: " << endl;
  cin >> ranking;
  Song temporalSong(name, author, interpreter, ranking);
  menuListPtr->insertSong(pos, temporalSong);
}

void Menu::removeSong() {
  int pos;
  cout << "Dime la posicion de la cancion: \n";
  cin >> pos;
  menuListPtr->deleteSong(pos);
}

bool Menu::exit() { return false; }
