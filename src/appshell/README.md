# src/appshell

Appshell is the folder that contains the program's UI. It is divided between:
- `qml/`: Contains the barebones UI components in QML language (similar to ReactJS, HTML...)
- `internal/`: contains the C++ code that tells the UI components how to work and behave.

## How to create a new widget.

It is more comfortable to work with Qt Creator IDE. It automatically adds files to CMakeLists.txt. If not, create the qml file `appshell/qml/SomeWidget.qml`and add it to the CMakeLists file. Then, if necessary, create the correspondent `.h` (header) and `.cpp` (source) files under `internal/`.