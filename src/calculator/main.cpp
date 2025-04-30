/**
 * @file        main.cpp
 * @author      František Janota
 * @date        13.04.2025
 * @brief       Entry point for the Qt-based calculator application.
 *
 * This is the main function of the graphical calculator application.
 * It initializes the Qt application, creates the main window, and starts
 * the application event loop. The main window handles user interactions
 * and uses the custom math library for computations.
 *
 * @see MainWindow
 * @see mathlib.h
 */

 #include "mainwindow.h"
 #include <QApplication>
 
 /**
  * @brief Starts the Qt GUI application.
  *
  * Initializes QApplication with command-line arguments,
  * shows the main window, and enters the main event loop.
  *
  * @param argc Argument count from the command line.
  * @param argv Argument values from the command line.
  * @return Application exit code.
  */
 int main(int argc, char *argv[])
 {
     QApplication a(argc, argv);
     MainWindow w;
     w.show();
     return a.exec();
 }

  /** END OF FILE STDDEV.CPP */
  