#include "evaluator.h"
#include "scope_protector.h"

#include <R_ext/Parse.h>

namespace device {
    namespace evaluator {
        namespace {

            using device::scope_protector::scope_protector;

            SEXP createSexp(const std::string& str, scope_protector* protector) {
                SEXP result = Rf_allocVector(STRSXP, 1);

                protector->add(result);

                SET_STRING_ELT(result, 0, Rf_mkChar(str.c_str()));

                return result;
            }

            SEXP parseSexp(SEXP commandSexp, scope_protector* protector) {
                ParseStatus ps;

                SEXP result = R_ParseVector(commandSexp, 1, &ps, R_NilValue);

                protector->add(result);

                return result;
            }

            SEXP parseCommand(const std::string& str, scope_protector* protector) {
                return parseSexp(createSexp(str, protector), protector);
            }

            SEXP evaluateCommand(SEXP commandSexp, scope_protector* protector) {
                int errorCode = 0;

                SEXP result = R_tryEval(commandSexp, R_GlobalEnv, &errorCode);

                protector->add(result);

                return result;
            }
        } // anonymous

        SEXP evaluate(const std::string& command) {
            device::scope_protector::scope_protector protector;

            SEXP commandSexp = parseCommand(command, &protector);

            return evaluateCommand(commandSexp, &protector);
        }

    } // evaluator
} // device
