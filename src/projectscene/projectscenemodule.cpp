#include "projectscenemodule.h"

#include "modularity/ioc.h"

#include "view/timeline/keysview.h"

// Links the module to the .qrc file
// WE put it outside of the app::appshell namespace
// because Q_INIT_RESOURCE can't be located inside a namespace
// (either it fails with error "couldn't find qLinkResources_app()")
static void projectscene_init_qrc()
{
    Q_INIT_RESOURCE(projectscene);
};

namespace app::projectscene {

ProjectSceneModule::ProjectSceneModule() {};

std::string ProjectSceneModule::moduleName() const {
    return "projectscene";
};

void ProjectSceneModule::registerResources() {
    projectscene_init_qrc();
};

void ProjectSceneModule::registerExports() {
        qmlRegisterType<KeysView>("App.ProjectScene", 1, 0, "KeysView");
};

};
