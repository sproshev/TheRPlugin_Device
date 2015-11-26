#ifndef MASTER_DEVICE_H
#define MASTER_DEVICE_H

#include <string>

#include <Rinternals.h>
#include <R_ext/GraphicsEngine.h>

namespace jetbrains {
namespace ther {
namespace device {
namespace master {
namespace {

const std::string NAME = "TheRPlugin_Device";

double currentWidth = 0.0;
double currentHeight = 0.0;

pGEDevDesc INSTANCE = NULL;

} // anonymous

void init();

pGEDevDesc instance();

} // master
} // device
} // ther
} // jetbrains

#endif // MASTER_DEVICE_H
