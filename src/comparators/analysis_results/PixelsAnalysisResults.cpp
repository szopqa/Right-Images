#include "./PixelsAnalysisResults.h"

void PixelsAnalysisResults::setResults(Pixel* pixResult)
{
    this->pixResult = pixResult;
}

Pixel* PixelsAnalysisResults::getResults()
{
    return this->pixResult;
}
