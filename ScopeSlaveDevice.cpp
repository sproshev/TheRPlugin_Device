#include <iostream>
#include <boost/format.hpp>

#include "Evaluator.h"
#include "ScopeSlaveDevice.h"

namespace device {
namespace slave {

class ScopeSlaveDevice::Impl {
 public:
  Impl(double width, double height) {
    boost::format format("grDevices:::png(\"%1%\", %2%, %3%, res = %4%)");
    const std::string command = boost::str(format % "snapshot.png" % width % height % 96);

    device::evaluator::evaluate(command);

    device = GEcurrentDevice();
  }

  virtual ~Impl() {
    GEkillDevice(device);
  }

  pDevDesc devDesc() {
    return device->dev;
  }

  void copy(pDevDesc devDesc) {
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
