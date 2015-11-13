#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <Rinternals.h>
#include <string>

namespace device {
    namespace evaluator {

        SEXP evaluate(const std::string &command);

    }
}

#endif // EVALUATOR_H
