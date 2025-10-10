# Advanced Effects

![An early image of Advanced Effects](https://raw.githubusercontent.com/Advanced-Effects/Muse-Qml-App-Template/refs/heads/main/screenshot.webp)

Are you a?

- YouTuber that wants to create animations for his videos?
- A Public Relations experts who wants to make an ad?
- You want to do motion graphics?

Up until now, the industry standard (and expensive) After Effects had no contestant. There are similar open source programs.
- Like [Friction](), which has a really good UI but terrible Code.
- Or [Glaxnimate](), which has beautiful code but terrible UI

Here arrives Advanced Effects, what aims to be the After Effects killer. A good-looking open-source animation software that couldn't be possible without Friction, Glaxnimate, and MuseScore!

- 🪥 Clean and easy-to-grasp codebase (or I try to)
- 🔮 Good looking

## 🗺️ Roadmap

- [x] 💻 A Minimal App that shows a window.
- [x] 🧭 With a Complex Navigation System.
- [x] 🎨 That shows an OpenGL canvas with Skia2D.
- [ ] 📁 That can open and save project files.
- [ ] 🟦 Where you can drag objects around.
- [ ] 🚄 And animate them.
- [ ] 🎥 And render that to a video file.

## ⚠️ Ethical warning

This piece of software wouldn't be available without the sustained hard work and research of the authors of Friction, Glaxnimate, and MuseScore. If you are honest, **you should not** **resell copies** of this software. More details on how GNU GPL v2 works: https://choosealicense.com/

YOU came here looking for a free SVG animation alternative to propietary software. Do something good for the rest :)

## ❓ Why this

The idea of developing this was born out of frustration with Friction's codebase and Glaxnimate's poor UI.

## 🏃 How to run

I recommend using Qt Creator to run this software as it does most things for you.

You **can't install Qt through the system manager** because in Ubuntu only Qt 6.4 is distributed and **6.9** is required to run this.

- CMake and Ninja
- C++17 compiler
- Qt 6.9+ with QtQuick 2
- FFmpeg (libav)
- Skia

If you **don't want** to use **Qt Creator**, here's how to run the software:

**1. Clone or download** the repository: `git clone https://github.com/Advanced-Effects/Advanced-Effects.git`.

**2. Open a terminal** and enter the directory where the repository is located: `cd /path/to/Advanced-Effects`.

**3. Setup the build environment:** by getting a C++17 compiler like `gcc`, `CMake`, and `Ninja`.

**4. Get the dependencies:** by getting the [Muse's framework dependencies](https://github.com/musescore/MuseScore/wiki/Install-dependencies), OpenGL and `glfw3`, and [Qt 6.9.1](https://www.qt.io/product/qt6)

**5. Create a build directory** where the project's output files will be by executing `mkdir build` and then go into it using `cd build`.

**6. Finally, compile the project** by setting up the CMake environment `cmake ..` and compiling the project `cmake --build .`

**✅ If everything has gone right, you now have a Debug version of the application in `<your project directory>/build/src/app/AdvancedEffects`**

## ❤️ Credits

- The UI is inspired on After Effects and, mostly, MuseScore.
- The codebase is inspired on Akira and Glaxnimate.
- Experience was gained contributing to Friction/enve2d.
- The template used is: https://github.com/emericg/QmlAppTemplate

Thanks to all who made this possible :heart: (rodlie, MaurycyLiebner, Alecadd, MuseScore team, emericg) and the Friction community.


## Debug

Set these environment variables to inspect the application:

- `QML_IMPORT_TRACE`: When set to 'ON', shows the QML Engine log when importing modules (is a Qt environment variable).
- `APP_LIST_QRT`: When set to '1', prints the Qt Resource Tree (`src/application/main.cpp`)
- `-DAPP_LIST_QUI`: When set to 'ON' (`cmake .. -DAPP_LIST_QUI=ON`), prints the QQmlApplicationEngine UI hierarchy.

