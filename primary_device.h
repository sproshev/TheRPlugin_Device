#ifndef R_UNIVERSAL_DEVICE_PRIMARY_DEVICE_H
#define R_UNIVERSAL_DEVICE_PRIMARY_DEVICE_H

#include <Rinternals.h>
#include <R_ext/GraphicsEngine.h>

namespace device {
    namespace primary {
        namespace {

            double currentWidth = 0.0;
            double currentHeight = 0.0;

            pGEDevDesc INSTANCE = NULL;

        } // anonymous namespace

        const char *NAME = "RUniversalDevice";

        void init(pGEDevDesc secondaryDevice);

        pGEDevDesc instance();

    } // primary
} // device

#endif //R_UNIVERSAL_DEVICE_PRIMARY_DEVICE_H
