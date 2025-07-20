#pragma once

#include <vector>

#include "../project_file/interfaces/SvgTrait.h"
#include "../project_file/ProjectFile.h"

namespace ae::library::app {

// Contains the state of the currently opened application instance
// - Last used tool
// - Open files
// - Window size and position
struct ApplicationState {
    // AppWindow
    int lastUsedWindowSize[2];
    int lastUsedWindowPosition[2];
    // PageSwitcher
    int currentlyOpenPage;

    // TabBar
    std::vector<ProjectFile*> currentlyOpenedFiles;
    ProjectFile* currentlyOpenFile = nullptr;

    // Timeline
    int currentlySelectedFrame;
};

};
