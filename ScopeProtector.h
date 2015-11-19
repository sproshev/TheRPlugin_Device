#ifndef SCOPE_PROTECTOR_H
#define SCOPE_PROTECTOR_H

#include <boost/noncopyable.hpp>
#include <memory>

#include <Rinternals.h>

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

#endif // SCOPE_PROTECTOR_H
