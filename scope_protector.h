#ifndef SCOPE_PROTECTOR_H
#define SCOPE_PROTECTOR_H

#include <Rinternals.h>
#include <boost/noncopyable.hpp>
#include <memory>

namespace device {
    namespace scope_protector {

        class scope_protector : boost::noncopyable {
        public:
            scope_protector();

            virtual ~scope_protector();

            void add(SEXP sexp);

        private:
            class impl;

            std::unique_ptr<impl> p_impl;
        };

    }
}

#endif // SCOPE_PROTECTOR_H
