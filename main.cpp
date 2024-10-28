#include "src/Application.h"

int main() {
    auto* app = new Application();
    app->init();

    app->createShaders();
    app->createModels();
    app->run();

    return 0;
}
