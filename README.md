# Calculator with GUI
Second project for the IVS course - Nullpointers

### Description

User manual can be found in the file [dokumentace.pdf](./dokumentace.pdf)

This application is an advanced calculator with a graphical user interface that supports basic mathematical operations (+, -, *, /), factorial calculation, exponentiation with natural exponents, and the common square root.  

The program is based on a modular architecture, with the basic mathematical functions implemented as a separate library. The calculator can be operated using the keyboard and includes built-in help. The project includes user and program documentation and an installer allowing easy installation and uninstallation of the application.

### Platform

Linux - Ubuntu 64-bit

## Authors

Team Nullpointers:

Adam Křivka - xkrivka00  
Václav Semerád - xsemerv00  
Frantisek Janota - xjanotf00   
Viktor Čaloud - 260514  

## Prerequisites

### Operating System:
- Linux (e.g., Ubuntu 20.04+ or compatible distributions)

### Compiler:
- g++ version >= 9

### Build Tools:
- cmake version >= 3.16
- make

### Libraries:
- Qt5 (or alternatively Qt6) with the following modules:
  - Core
  - Gui
  - Widgets
- libc6 (this is a core library, typically always available in the system)

### Additional Tools:
- cpack (bundled with cmake, used for generating .deb packages)

## Installation

### Ubuntu / Debian-based Systems

#### GUI Calculator
1. Download the `calculator.deb` package from the [Releases](#) section.
2. Open the folder containing the file in a terminal.
3. Run the following command to install:
   ```bash 
   sudo apt install ./calculator.deb
#### Stddev CLI program
1. Download the `stddev.deb` package from the [Releases](#) section.
2. Open the folder containing the file in a terminal.
3. Run the following command to install:
   ```bash 
   sudo dpkg -i ./stddev.deb
## Uninstallation
1. Run the following command in terminal to uninstall these programs:
   ```bash 
   sudo apt remove calculator
   sudo apt remove stddev
## License
This project is licensed under the terms of the GNU General Public License v3.0 (GPL-3.0).

You are free to use, modify, and distribute this software under the same license,
provided that the original copyright and license
notice are preserved.

See the full license text in the [LICENSE](./LICENSE) file or at [gnu.org/licenses/gpl-3.0](https://www.gnu.org/licenses/gpl-3.0).
