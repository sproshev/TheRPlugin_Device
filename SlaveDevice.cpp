#include <boost/format.hpp>

#include "Evaluator.h"
#include "Common.h"
#include "SlaveDevice.h"

namespace jetbrains {
namespace ther {
namespace device {
namespace slave {
namespace {

pGEDevDesc INSTANCE = NULL;

class InitHelper {
 public:
  InitHelper() : previousDevice(NULL) {
    if (!Rf_NoDevices()) {
      previousDevice = GEcurrentDevice();
    }
  }

  virtual ~InitHelper() {
    if (previousDevice != NULL) {
      int previousDeviceNumber = Rf_ndevNumber(previousDevice->dev);

      GEcopyDisplayList(previousDeviceNumber);
      Rf_selectDevice(previousDeviceNumber);
    }
  }

 private:
  pGEDevDesc previousDevice;
};

pGEDevDesc init(double width, double height) {
  InitHelper helper; // helper backups and restores active device and copies its display list to slave device

  boost::format format("grDevices:::png(\"%1%\", %2%, %3%, res = %4%)");
  const std::string command = str(format % "snapshot.png" % width % height % 96);

  evaluator::evaluate(command);

  return GEcurrentDevice();
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
