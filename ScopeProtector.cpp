#include "ScopeProtector.h"

namespace device {
namespace protector {

class ScopeProtector::Impl {
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

ScopeProtector::ScopeProtector() : pImpl(new Impl) {
}

ScopeProtector::~ScopeProtector() = default;

void ScopeProtector::add(const SEXP sexp) {
  pImpl->add(sexp);
}

} // protector
} // device


