#ifndef INTERFACE_H
#define INTERFACE_H

#include "MasterDevice.h"

extern "C" SEXP jetbrains_ther_device_init() {
  jetbrains::ther::device::master::init();

  return R_NilValue;
}

#endif // INTERFACE_H
