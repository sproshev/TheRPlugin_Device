#include "scope_protector.h"

namespace device {
namespace protector {

class scope_protector::Impl {
 public:
  Impl() : count(0) {
  }

  virtual ~Impl() {
    if (count > 0) {
      UNPROTECT(count);
    }
  }

  void add(const SEXP sexp) {
    PROTECT(sexp);
    count++;
  }

 private:
  int count;
};

scope_protector::scope_protector() : pImpl(new Impl) {
}

scope_protector::~scope_protector() = default;

void scope_protector::add(const SEXP sexp) {
  pImpl->add(sexp);
}

} // protector
} // device


