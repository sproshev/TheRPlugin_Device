#ifndef MASTER_DEVICE_H
#define MASTER_DEVICE_H

#include <string>

#include <Rinternals.h>
#include <R_ext/GraphicsEngine.h>

namespace jetbrains {
namespace ther {
namespace device {
namespace master {

void init();

pGEDevDesc instance();

} // master
} // device
} // ther
} // jetbrains

#endif // MASTER_DEVICE_H
