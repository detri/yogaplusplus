#include "yogaplusplus/config.hpp"

namespace Yoga
{
    Config::Config(): _yogaConfig{YGConfigNew()}
    {}

    Config::~Config()
    { YGConfigFree(_yogaConfig); }

    void Config::setPointScaleFactor(const float pointScaleFactor)
    {
        YGConfigSetPointScaleFactor(_yogaConfig, pointScaleFactor);
    }

    void Config::setUseWebDefaults(const bool useWebDefaults)
    {
        YGConfigSetUseWebDefaults(_yogaConfig, useWebDefaults);
    }

    void Config::setCloneNodeCallback(const YGCloneNodeFunc callback)
    {
        YGConfigSetCloneNodeFunc(_yogaConfig, callback);
    }

    void Config::setContext(void* context)
    {
        YGConfigSetContext(_yogaConfig, context);
    }

    void Config::setLogger(const YGLogger logger)
    {
        YGConfigSetLogger(_yogaConfig, logger);
    }

    void Config::setErrata(const YGErrata errata)
    {
        YGConfigSetErrata(_yogaConfig, errata);
    }
}
