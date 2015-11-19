#include <iostream>
#include <boost/format.hpp>

#include "Evaluator.h"
#include "ScopeSlaveDevice.h"

namespace device {
namespace slave {

class ScopeSlaveDevice::Impl {
 public:
  Impl(const double width, const double height) {
    boost::format format("grDevices:::png(\"%1%\", %2%, %3%, res = %4%)");
    const std::string command = boost::str(format % "snapshot.png" % width % height % 96);

    device::evaluator::evaluate(command);

    device = GEcurrentDevice();
  }

  virtual ~Impl() {
    GEkillDevice(device);
  }

  void copy(const pDevDesc devDesc) {
    GEcopyDisplayList(ndevNumber(devDesc));
  }

 private:
  pGEDevDesc device;
};

ScopeSlaveDevice::ScopeSlaveDevice(const double width, const double height) : pImpl(new Impl(width, height)) {
}

ScopeSlaveDevice::~ScopeSlaveDevice() = default;

void ScopeSlaveDevice::copy(const pDevDesc devDesc) {
  pImpl->copy(devDesc);
}

} // slave
} // device
