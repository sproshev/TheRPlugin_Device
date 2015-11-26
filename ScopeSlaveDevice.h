#ifndef SCOPE_SLAVE_DEVICE_H
#define SCOPE_SLAVE_DEVICE_H

#include <boost/noncopyable.hpp>

#include <Rinternals.h>
#include <R_ext/GraphicsEngine.h>

namespace jetbrains {
namespace ther {
namespace device {
namespace slave {

class ScopeSlaveDevice: boost::noncopyable {
 public:
  ScopeSlaveDevice(double width, double height);

  virtual ~ScopeSlaveDevice();

  pDevDesc devDesc();

  void copy(pDevDesc devDesc);

 private:
  class Impl;

  const std::unique_ptr<Impl> pImpl;
};

} // slave
} // device
} // ther
} // jetbrains

#endif // SCOPE_SLAVE_DEVICE_H
