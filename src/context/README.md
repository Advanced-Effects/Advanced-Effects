# context/

What does `context/` mean? what is `iuicontextresolver`? This module has **2 FUNCTIONS:**

The context module handles **global application state.**

1. Things like *currently open projects* or any kind of *data* go into the `IGlobalContext` - an interface later implemented by `internal/globalcontext.cpp/h`. **Whatever you need comes here.**

2. In MuseScore there's a concept called `UiContext`. It refers basically to the thing that's focused currently (page, project view...). This concept is declared in `framework/ui`, specifically `uicontextresolver.h` and `uiaction.h` with basic states such as `UiCtxUnknown`, `UiCtxHomeOpened`, `UiCtxProjectOpened`. The function of this module is to extend these states. You can add your own states here.
- `IUiContextResolver`'s task is, simplifying, to give you the `currentUiContext`.
- `UiContext` yet again is a very messy and intricate way to say a `String`. See:`ui/uiaction.h`: `char* const_data` and `static constexpr UiContext UiCtxUnknown = "UiCtxUnknown";
`.
