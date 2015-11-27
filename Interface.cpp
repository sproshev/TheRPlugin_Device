#include "Interface.h"

extern "C" SEXP jetbrains_ther_device_init() {
  jetbrains::ther::device::master::init();

  return R_NilValue;
}
