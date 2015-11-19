#include "Evaluator.h"

#include <R_ext/Parse.h>

namespace device {
namespace evaluator {
namespace {

using device::protector::ScopeProtector;

SEXP createSexp(const std::string &str, ScopeProtector *protector) {
  SEXP result = Rf_allocVector(STRSXP, 1);

  protector->add(result);

  SET_STRING_ELT(result, 0, Rf_mkChar(str.c_str()));

  return result;
}

SEXP parseSexp(SEXP commandSexp, ScopeProtector *protector) {
  ParseStatus ps;

  SEXP result = R_ParseVector(commandSexp, 1, &ps, R_NilValue);

  protector->add(result);

  return result;
}

SEXP parseCommand(const std::string &str, ScopeProtector *protector) {
  return parseSexp(createSexp(str, protector), protector);
}

SEXP evaluateCommand(SEXP commandSexp, ScopeProtector *protector) {
  int errorCode = 0;

  SEXP result = R_tryEval(commandSexp, R_GlobalEnv, &errorCode);

  protector->add(result);

  return result;
}

} // anonymous

void evaluate(const std::string &command) {
  device::protector::ScopeProtector protector;

  SEXP commandSexp = parseCommand(command, &protector);

  evaluateCommand(commandSexp, &protector);
}


SEXP evaluate(const std::string &command, device::protector::ScopeProtector *protector) {
  SEXP commandSexp = parseCommand(command, protector);

  return evaluateCommand(commandSexp, protector);
}

} // evaluator
} // device
