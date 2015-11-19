#ifndef SCOPE_SLAVE_DEVICE_H
#define SCOPE_SLAVE_DEVICE_H

#include <boost/noncopyable.hpp>

#include <Rinternals.h>
#include <R_ext/GraphicsEngine.h>

namespace device {
namespace slave {

class ScopeSlaveDevice: boost::noncopyable {
 public:

  ScopeSlaveDevice(const double width, const double height);

  virtual ~ScopeSlaveDevice();

  void copy(const pDevDesc devDesc);

 private:
  pGEDevDesc instance;
};

} // slave
} // device

#endif // SCOPE_SLAVE_DEVICE_H
