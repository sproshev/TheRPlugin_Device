#ifndef SLAVE_DEVICE_H
#define SLAVE_DEVICE_H

#include <Rinternals.h>
#include <R_ext/GraphicsEngine.h>

namespace jetbrains {
namespace ther {
namespace device {
namespace slave {

pGEDevDesc instance(double width, double height);

void dump();

} // slave
} // device
} // ther
} // jetbrains

#endif // SLAVE_DEVICE_H
