#pragma once
#include "./ImageAnalyzer.h"
#include "../analysis_results/PixelsAnalysisResults.h"

class PixelsValuesAnalyzer : public ImageAnalyzer
{
private:
    /* data */
public:
    PixelsValuesAnalyzer(/* args */);
    ~PixelsValuesAnalyzer();
    // PixelsAnalysisResults analyze(Image* img) override;    
};
