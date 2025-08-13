# appshell/

`appshell/` handles the UI layer of the application. You can think of it like `ui/` or `gui/` folder.

- `appshellmodule` includes .qml files (`Q_INIT_RESOURCE(appshell)`) and injects C++ types into the QmlEngine.
- UI Application begins at `qml/Main.qml`, which is then loaded into the `QQmlApplicationEngine` using `->load("qrc:/Main.qml");`.
- `import Muse.UiComponents` refers to `thirdparty/framework/uicomponents`
- `import Muse.Ui` refers to `thirdparty/framework/ui`
- You'll see imports like `import Application.AppShell`. That refers to types that have been injected using C++ using `qmlRegisterType<T>("Application.AppShell", ...)`. The name `Application.AppShell` is arbitrary, it could be anything else.
- You'll see many components refer to a misterious `ui` object (`ui.theme.backgroundPrimaryColor
`). That is a special object called `UiEngine` that's injected into the app using `QQmlApplicationEngine->setContextProperty("ui", UiEngine);`. It's also the reason we use the `qmlAppEngine()` from `UiEngine` instead of creating one (`new QQmlApplicationEngine();`); `UiEngine` creates the `QQmlApplicationEngine` and then adds this object, which we utilize.
