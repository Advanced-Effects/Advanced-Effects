#include "translation.hpp"

// MuseScore translation service
#include "translation.h"

using namespace glaxnimate;
using namespace muse;

QString i18n(QString string, QString args, ...) {
        auto translatedString = qtrc("glax", string);
        auto formatedString = translatedString.arg(args);

        return formatedString;
};

QString i18n(QString string) {
        return glaxnimate::kli18n(string);
};

QString kli18n(QString string, QString args, ...) {
        return glaxnimate::i18n(string, args);
};

QString kli18n(QString string) {
        return glaxnimate::kli18n(string);
};
