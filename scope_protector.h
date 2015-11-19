#ifndef SCOPE_PROTECTOR_H
#define SCOPE_PROTECTOR_H

#include <boost/noncopyable.hpp>
#include <memory>

#include <Rinternals.h>

namespace device {
namespace protector {

class scope_protector: boost::noncopyable {
 public:
  scope_protector();

  virtual ~scope_protector();

  void add(const SEXP sexp);

 private:
  class Impl;

  std::unique_ptr<Impl> pImpl;
};

} // protector
} // device

#endif // SCOPE_PROTECTOR_H
