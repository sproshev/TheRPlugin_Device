#include <boost/format.hpp>

#include "Evaluator.h"
#include "Common.h"
#include "SlaveDevice.h"

namespace jetbrains {
namespace ther {
namespace device {
namespace slave {
namespace {

const int ILLEGAL_DEVICE_NUMBER = -1;

pGEDevDesc INSTANCE = NULL;

pGEDevDesc create(double width, double height) {
  boost::format format("grDevices:::png(\"%1%\", %2%, %3%, res = %4%)");
  const std::string command = str(format % "snapshot.png" % width % height % 96);

  evaluator::evaluate(command);

  return GEcurrentDevice();
}

int getCurrentDeviceNumber() {
  if (!Rf_NoDevices()) {
    return Rf_ndevNumber(GEcurrentDevice()->dev);
  } else {
    return ILLEGAL_DEVICE_NUMBER;
  }
}

pGEDevDesc init(double width, double height) {
  int currentDeviceNumber = getCurrentDeviceNumber();

  pGEDevDesc slaveDevice = create(width, height);

  if (currentDeviceNumber != ILLEGAL_DEVICE_NUMBER) {
    GEcopyDisplayList(currentDeviceNumber);
    Rf_selectDevice(currentDeviceNumber);
  }

  return slaveDevice;
}

} // anonymous

pGEDevDesc instance(double width, double height) {
  DEVICE_TRACE;

  if (INSTANCE == NULL) {
    INSTANCE = init(width, height);
  }

  return INSTANCE;
}

void dump() {
  DEVICE_TRACE;

  GEkillDevice(INSTANCE);

  INSTANCE = NULL;
}

} // slave
} // device
} // ther
} // jetbrains
