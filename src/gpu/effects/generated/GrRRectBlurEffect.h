/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrRRectBlurEffect.fp; do not modify.
 **************************************************************************************************/
#ifndef GrRRectBlurEffect_DEFINED
#define GrRRectBlurEffect_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"

#include "include/core/SkRect.h"
class GrRecordingContext;
class SkRRect;

#include "src/gpu/GrFragmentProcessor.h"

class GrRRectBlurEffect : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(std::unique_ptr<GrFragmentProcessor> inputFP,
                                                     GrRecordingContext* context,
                                                     float sigma,
                                                     float xformedSigma,
                                                     const SkRRect& srcRRect,
                                                     const SkRRect& devRRect);
    GrRRectBlurEffect(const GrRRectBlurEffect& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "RRectBlurEffect"; }
    float sigma;
    SkRect rect;
    float cornerRadius;

private:
    GrRRectBlurEffect(std::unique_ptr<GrFragmentProcessor> inputFP,
                      float sigma,
                      SkRect rect,
                      float cornerRadius,
                      std::unique_ptr<GrFragmentProcessor> ninePatchFP)
            : INHERITED(kGrRRectBlurEffect_ClassID,
                        (OptimizationFlags)(inputFP ? ProcessorOptimizationFlags(inputFP.get())
                                                    : kAll_OptimizationFlags) &
                                kCompatibleWithCoverageAsAlpha_OptimizationFlag)
            , sigma(sigma)
            , rect(rect)
            , cornerRadius(cornerRadius) {
        this->registerChild(std::move(inputFP), SkSL::SampleUsage::PassThrough());
        SkASSERT(ninePatchFP);
        this->registerChild(std::move(ninePatchFP), SkSL::SampleUsage::Explicit());
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
#if GR_TEST_UTILS
    SkString onDumpInfo() const override;
#endif
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    typedef GrFragmentProcessor INHERITED;
};
#endif
