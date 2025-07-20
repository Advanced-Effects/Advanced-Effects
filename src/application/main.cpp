#include <QQmlApplicationEngine>

#include "app.h"
#include "cmdline.h"

using namespace ae::app;

int main(int argc, char *argv[]) {
    Application application;

    QQmlApplicationEngine engine;
    CommandLineParser parser(argc, argv);

    return application.exec(engine, parser);
};

