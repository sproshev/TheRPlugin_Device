#include "primary_device.h"

#include <string.h>

namespace device {
    namespace primary {
        namespace {

            pDevDesc secondaryDesc() {
                return ((pGEDevDesc) INSTANCE->dev->deviceSpecific)->dev;
            }

            void circle(double x, double y, double r, const pGEcontext context, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->circle(x, y, r, context, secondaryDevDesc);
            }

            void clip(double x1, double x2, double y1, double y2, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->clip(x1, x2, y1, y2, secondaryDevDesc);
            }

            void close(pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->close(secondaryDevDesc);

                delete INSTANCE->dev;
                INSTANCE->dev = NULL;

                INSTANCE = NULL;
            }

            void line(double x1, double y1, double x2, double y2, const pGEcontext context, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->line(x1, y1, x2, y2, context, secondaryDevDesc);
            }

            void metricInfo(int character,
                            const pGEcontext context,
                            double* ascent,
                            double* descent,
                            double* width,
                            pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->metricInfo(character, context, ascent, descent, width, secondaryDevDesc);
            }

            void mode(int mode, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->mode(mode, secondaryDevDesc);
            }

            void newPage(const pGEcontext context, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->newPage(context, secondaryDevDesc);
            }

            void polygon(int n, double* x, double* y, const pGEcontext context, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->polygon(n, x, y, context, secondaryDevDesc);
            }

            void polyline(int n, double* x, double* y, const pGEcontext context, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->polyline(n, x, y, context, secondaryDevDesc);
            }

            void rect(double x1, double y1, double x2, double y2, const pGEcontext context, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->rect(x1, y1, x2, y2, context, secondaryDevDesc);
            }

            void path(double* x,
                      double* y,
                      int npoly,
                      int* nper,
                      Rboolean winding,
                      const pGEcontext context,
                      pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->path(x, y, npoly, nper, winding, context, secondaryDevDesc);
            }

            void raster(unsigned int* raster,
                        int w,
                        int h,
                        double x,
                        double y,
                        double width,
                        double height,
                        double rot,
                        Rboolean interpolate,
                        const pGEcontext context,
                        pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->raster(
                        raster, w, h, x, y, width, height, rot, interpolate, context, secondaryDevDesc
                );
            }

            void size(double* left, double* right, double* bottom, double* top, pDevDesc devDesc) {
                *left = 0.0;
                *right = currentWidth;
                *bottom = currentHeight;
                *top = 0.0;
            }

            double strWidth(const char* str, const pGEcontext context, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                return secondaryDevDesc->strWidth(str, context, secondaryDevDesc);
            }

            void text(double x,
                      double y,
                      const char* str,
                      double rot,
                      double hadj,
                      const pGEcontext context,
                      pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->text(x, y, str, rot, hadj, context, secondaryDevDesc);
            }

            void textUTF8(double x,
                          double y,
                          const char* str,
                          double rot,
                          double hadj,
                          const pGEcontext context,
                          pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                secondaryDevDesc->textUTF8(x, y, str, rot, hadj, context, secondaryDevDesc);
            }

            double strWidthUTF8(const char* str, const pGEcontext context, pDevDesc devDesc) {
                pDevDesc secondaryDevDesc = secondaryDesc();

                return secondaryDevDesc->strWidthUTF8(str, context, devDesc);
            }

        } // anonymous

        void init(pGEDevDesc secondaryDevice) {
            pDevDesc primaryDevDesc = new DevDesc;
            pDevDesc secondaryDevDesc = secondaryDevice->dev;

            size(
                    &(primaryDevDesc->left),
                    &(primaryDevDesc->right),
                    &(primaryDevDesc->bottom),
                    &(primaryDevDesc->top),
                    primaryDevDesc
            );

            primaryDevDesc->clipLeft = primaryDevDesc->left;
            primaryDevDesc->clipRight = primaryDevDesc->right;
            primaryDevDesc->clipBottom = primaryDevDesc->bottom;
            primaryDevDesc->clipTop = primaryDevDesc->top;

            primaryDevDesc->xCharOffset = secondaryDevDesc->xCharOffset;
            primaryDevDesc->yCharOffset = secondaryDevDesc->yCharOffset;
            primaryDevDesc->yLineBias = secondaryDevDesc->yLineBias;
            primaryDevDesc->ipr[0] = secondaryDevDesc->ipr[0];
            primaryDevDesc->ipr[1] = secondaryDevDesc->ipr[1];

            primaryDevDesc->cra[0] = secondaryDevDesc->cra[0];
            primaryDevDesc->cra[1] = secondaryDevDesc->cra[1];
            primaryDevDesc->gamma = secondaryDevDesc->gamma;

            primaryDevDesc->canClip = secondaryDevDesc->canClip;
            primaryDevDesc->canChangeGamma = secondaryDevDesc->canChangeGamma;
            primaryDevDesc->canHAdj = secondaryDevDesc->canHAdj;

            primaryDevDesc->startps = secondaryDevDesc->startps;
            primaryDevDesc->startcol = secondaryDevDesc->startcol;
            primaryDevDesc->startfill = secondaryDevDesc->startfill;
            primaryDevDesc->startlty = secondaryDevDesc->startlty;
            primaryDevDesc->startfont = secondaryDevDesc->startfont;
            primaryDevDesc->startgamma = secondaryDevDesc->startgamma;

            primaryDevDesc->deviceSpecific = secondaryDevice;

            primaryDevDesc->displayListOn = TRUE;

            primaryDevDesc->canGenMouseDown = FALSE;
            primaryDevDesc->canGenMouseMove = FALSE;
            primaryDevDesc->canGenMouseUp = FALSE;
            primaryDevDesc->canGenKeybd = FALSE;
            primaryDevDesc->gettingEvent = FALSE;

            primaryDevDesc->activate = NULL;
            primaryDevDesc->circle = circle;
            primaryDevDesc->clip = clip;
            primaryDevDesc->close = close;
            primaryDevDesc->deactivate = NULL;
            primaryDevDesc->locator = NULL;
            primaryDevDesc->line = line;
            primaryDevDesc->metricInfo = metricInfo;
            primaryDevDesc->mode = mode;
            primaryDevDesc->newPage = newPage;
            primaryDevDesc->polygon = polygon;
            primaryDevDesc->polyline = polyline;
            primaryDevDesc->rect = rect;
            primaryDevDesc->path = path;
            primaryDevDesc->raster = raster;
            primaryDevDesc->size = size;
            primaryDevDesc->strWidth = strWidth;
            primaryDevDesc->text = text;
            primaryDevDesc->onExit = NULL;

            primaryDevDesc->newFrameConfirm = NULL;
            primaryDevDesc->hasTextUTF8 = TRUE;
            primaryDevDesc->textUTF8 = textUTF8;
            primaryDevDesc->strWidthUTF8 = strWidthUTF8;
            primaryDevDesc->wantSymbolUTF8 = TRUE;
            primaryDevDesc->useRotatedTextInContour = FALSE;

            primaryDevDesc->eventEnv = R_NilValue;
            primaryDevDesc->eventHelper = NULL;
            primaryDevDesc->holdflush = NULL;

            primaryDevDesc->haveTransparency = 2;
            primaryDevDesc->haveTransparentBg = 2;
            primaryDevDesc->haveRaster = 2;
            primaryDevDesc->haveCapture = 1;
            primaryDevDesc->haveLocator = 1;

            memset(primaryDevDesc->reserved, 0, 64);

            pGEDevDesc primaryDevice = GEcreateDevDesc(primaryDevDesc);
            GEaddDevice2(primaryDevice, NAME);

            Rf_selectDevice(Rf_ndevNumber(primaryDevice->dev));

            INSTANCE = primaryDevice;
        }

        pGEDevDesc instance() {
            return INSTANCE;
        }

    } // primary
} // device
