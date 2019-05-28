#pragma once
#include "./AnalysisResult.h"
#include "../../representations/Pixel.h"

class PixelsAnalysisResults
{
private:
    Pixel* pixResult;
public:
    void setResults(Pixel* pixResult);
    Pixel* getResults();
};
