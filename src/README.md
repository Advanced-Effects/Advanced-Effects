# Source code overview

- The code starts at `app/`: it includes the application's icon, and main.cpp. In there all the libraries are linked together with the main executable. Hence, app is always the final step in CMakeLists.

- `appshell/`: Is essentially a synonym for `ui/`. Contains application-specific widgets that closely rely on the application's state (e.g. GeneralBar, BaseCanvas...).

- `library/`: Contains core code that doesn't rely on the UI to work (application data types, file and conversion operations, services...)

- `thirdparty/`: is a dumpster for third party code we only need to **use** (namely, MuseScore's UI gallery).

## Wanna see how it works?

We covered the topmost-most important folders here. Under this, code is divided into logical pieces (called modules). Modules are loaded with script `buildscripts/cmake/DeclareModuleSetup.cmake` (it comes from MuseScore).

-> Find a UI piece of code to improve
-> How to add a feature