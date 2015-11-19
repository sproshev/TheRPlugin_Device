#ifndef MASTER_DEVICE_H
#define MASTER_DEVICE_H

#include <Rinternals.h>
#include <R_ext/GraphicsEngine.h>

namespace device {
namespace master {
namespace {

const std::string NAME = "RUniversalDevice";

double currentWidth = 0.0;
double currentHeight = 0.0;

pGEDevDesc INSTANCE = NULL;

} // anonymous

void init();

pGEDevDesc instance();

} // master
} // device

#endif // MASTER_DEVICE_H
