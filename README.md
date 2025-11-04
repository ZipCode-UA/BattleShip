# BattleShip
Implementation of the game battleship.
## Contributing
### Prerequisites

Before contributing, ensure the following:

You are part of the organization and have been added to the specific team for this project. If you need to be added contact a project manager in discord or during a meeting.

You have the following tools installed on your system:
- CMake
- Make
- A C++ compiler (e.g., GCC, Clang, or MSVC)

### Contribution Steps
1. Assign an issue to yourself and move it to In Progress.
2. Clone the repository:
    ```bash
    git clone https://github.com/ZipCode-UA/BattleShip
    cd ./Battleship
    ```
3. Create and switch to a new branch for your issue:
    ```bash
    git checkout -b <branchName>
    ```
4. Push your new branch to GitHub:
    ```bash
    git push --set-upstream origin <branchName>
    ```
5. Create a build directory and configure the project:
    ```bash
    mkdir build
    cd build
    cmake -G "<Your build tool, e.g. 'MinGW Makefiles'>" ..
    ```
6. Build the project:
    ```bash
    make
    ```
7. Make your changes locally.
8. Test your changes by running the program to confirm basic functionality.
9. Commit your changes:
    ```bash
    git commit -am "<Describe what you changed>"
    ```
10. Push your changes:
    ```bash
    git push
    ```
11. When your changes are ready, open a Pull Request on GitHub:
    - Go to the Pull Requests tab.
    - Click New Pull Request.
    - Select your branch as the compare branch.

**Note**: Contributors must be members of the organization and added to the appropriate team to access this repository.