#include <iostream>
#include <boost/format.hpp>

#include "evaluator.h"
#include "ScopeSlaveDevice.h"

namespace device {
namespace slave {

ScopeSlaveDevice::ScopeSlaveDevice(const double width, const double height) {
  boost::format format("grDevices:::png(\"%1%\", %2%, %3%, res = %4%)");
  const std::string command = boost::str(format % "snapshot.png" % width % height % 96);

  device::evaluator::evaluate(command);

  instance = GEcurrentDevice();
}

ScopeSlaveDevice::~ScopeSlaveDevice() {
  GEkillDevice(instance);
}

void ScopeSlaveDevice::copy(const pDevDesc devDesc) {
  GEcopyDisplayList(ndevNumber(devDesc));
}

} // slave
} // device
