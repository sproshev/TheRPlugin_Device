#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <string>

#include <Rinternals.h>

#include "ScopeProtector.h"

namespace device {
namespace evaluator {

void evaluate(const std::string &command);

SEXP evaluate(const std::string &command, device::protector::ScopeProtector *protector);

} // evaluator
} // device

#endif // EVALUATOR_H
