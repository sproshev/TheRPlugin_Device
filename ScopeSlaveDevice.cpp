#include <iostream>
#include <boost/format.hpp>

#include "Evaluator.h"
#include "Common.h"
#include "ScopeSlaveDevice.h"

namespace jetbrains {
namespace ther {
namespace device {
namespace slave {

class ScopeSlaveDevice::Impl {
 public:
  Impl(double width, double height) {
    DEVICE_TRACE;

    boost::format format("grDevices:::png(\"%1%\", %2%, %3%, res = %4%)");
    const std::string command = boost::str(format % "snapshot.png" % width % height % 96);

    jetbrains::ther::device::evaluator::evaluate(command);

    device = GEcurrentDevice();
  }

  virtual ~Impl() {
    DEVICE_TRACE;

    GEkillDevice(device);
  }

  pDevDesc devDesc() {
    DEVICE_TRACE;

    return device->dev;
  }

  void copy(pDevDesc devDesc) {
    DEVICE_TRACE;

    GEcopyDisplayList(ndevNumber(devDesc));
  }

 private:
  pGEDevDesc device;
};

ScopeSlaveDevice::ScopeSlaveDevice(double width, double height) : pImpl(new Impl(width, height)) {
}

ScopeSlaveDevice::~ScopeSlaveDevice() = default;

pDevDesc ScopeSlaveDevice::devDesc() {
  return pImpl->devDesc();
}

void ScopeSlaveDevice::copy(pDevDesc devDesc) {
  pImpl->copy(devDesc);
}

} // slave
} // device
} // ther
} // jetbrains