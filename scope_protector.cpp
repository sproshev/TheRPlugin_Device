#include "scope_protector.h"

namespace device {
    namespace scope_protector {

        class scope_protector::impl {
        public:
            impl() : count_(0) {
            }

            virtual ~impl() {
                if (count_ > 0) {
                    UNPROTECT(count_);
                }
            }

            void add(SEXP sexp) {
                PROTECT(sexp);
                count_++;
            }

        private:
            int count_;
        };

        scope_protector::scope_protector() : p_impl(new impl) {
        }

        scope_protector::~scope_protector() {
            p_impl->~impl();
        }


        void scope_protector::add(SEXP sexp) {
            p_impl->add(sexp);
        }
    }
}


