#ifndef R_UNIVERSAL_DEVICE_PRIMARY_DEVICE_H
#define R_UNIVERSAL_DEVICE_PRIMARY_DEVICE_H

#include <R_ext/GraphicsDevice.h>

namespace device {
    namespace primary {

        namespace {
            pGEDevDesc INSTANCE = NULL;
        }

        const char *NAME = "RUniversalDevice";

        void init(const double initWidth, const double initHeight, pGEDevDesc secondaryDevice);

        pGEDevDesc instance();

    } // primary
} // device

#endif //R_UNIVERSAL_DEVICE_PRIMARY_DEVICE_H
