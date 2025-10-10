#pragma once

#include "modularity/imoduleinterface.h"
#include "types/ret.h"

#include "io/path.h"
#include "async/notification.h"

namespace mu::appshell {
class IAppShellConfiguration : MODULE_EXPORT_INTERFACE
{
    INTERFACE_ID(IAppshellConfiguration)

public:
    virtual ~IAppShellConfiguration() = default;

    virtual bool hasCompletedFirstLaunchSetup() const = 0;
    virtual void setHasCompletedFirstLaunchSetup(bool has) = 0;

    virtual bool welcomeDialogShowOnStartup() const = 0;
    virtual void setWelcomeDialogShowOnStartup(bool show) = 0;
    virtual muse::async::Notification welcomeDialogShowOnStartupChanged() const = 0;

    virtual std::string welcomeDialogLastShownVersion() const = 0;
    virtual void setWelcomeDialogLastShownVersion(const std::string& version) = 0;

    virtual int welcomeDialogLastShownIndex() const = 0;
    virtual void setWelcomeDialogLastShownIndex(int index) = 0;

    virtual muse::io::path_t userDataPath() const = 0;

    virtual std::string handbookUrl() const = 0;
    virtual std::string askForHelpUrl() const = 0;
    virtual std::string appUrl() const = 0;
    virtual std::string appForumUrl() const = 0;
    virtual std::string appContributionUrl() const = 0;
    virtual std::string appVersion() const = 0;
    virtual std::string appRevision() const = 0;

    virtual bool needShowSplashScreen() const = 0;
    virtual void setNeedShowSplashScreen(bool show) = 0;

    virtual const QString& preferencesDialogLastOpenedPageId() const = 0;
    virtual void setPreferencesDialogLastOpenedPageId(const QString& lastOpenedPageId) = 0;

    virtual void startEditSettings() = 0;
    virtual void applySettings() = 0;
    virtual void rollbackSettings() = 0;

    virtual void revertToFactorySettings(bool keepDefaultSettings = false, bool notifyAboutChanges = true,
                                         bool notifyOtherInstances = true) const = 0;

    virtual muse::io::paths_t sessionProjectsPaths() const = 0;
    virtual muse::Ret setSessionProjectsPaths(const muse::io::paths_t& paths) = 0;
};
}
