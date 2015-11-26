#ifndef SCOPE_PROTECTOR_H
#define SCOPE_PROTECTOR_H

#include <boost/noncopyable.hpp>
#include <memory>

#include <Rinternals.h>

namespace jetbrains {
namespace ther {
namespace device {
namespace protector {

class ScopeProtector: boost::noncopyable {
 public:
  ScopeProtector();

  virtual ~ScopeProtector();

  void add(SEXP sexp);

 private:
  class Impl;

  const std::unique_ptr<Impl> pImpl;
};

} // protector
} // device
} // ther
} // jetbrains

#endif // SCOPE_PROTECTOR_H
