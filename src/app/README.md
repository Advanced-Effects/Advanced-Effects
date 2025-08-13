# app/

`app/` contains the start of the application.

- `CMakeLists.txt` creates the application's main executable and links it to `main.cpp` and all the application's libraries and dependencies.
- `main.cpp` Creates the Application, passes command line arguments to it, and runs it.
- `application.h` Initializes and deinits modules, and runs the `QApplication`.

```
============================================
=  CMakeLists -> main.cpp -> application.h =
============================================
```
