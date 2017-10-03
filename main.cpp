#include "mainwindow.hpp"
#include <QApplication>

#include <iostream>

#include "creature_types.hpp"
#include "tga_image.hpp"

using namespace std;



/**
 * @brief main          Entry point of the program.
 * @param argc          Number of command line arguments stored in argv.
 * @param argv          Pointer on all command line arguments.
 *
 * The main function gets the locations of the creature types as Parameter in the second
 * entry of argv. One instance of both CreatureTypes and TgaImage is created.
 */
int main(int argc, char *argv[]) {

    if(argc < 2) {
        cout << "not enough arguments to identify a filepath" << endl;
        return 0;
    }

    CreatureTypes creatureTypes(argv[1]);

    cout << endl;

    TgaImage tanne("images/land/tanne.tga");
    tanne.printTGAHeader();

    cout << endl;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
