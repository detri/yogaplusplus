#ifndef YOGA_CONFIG_HPP
#define YOGA_CONFIG_HPP

#include <yoga/Yoga.h>

namespace Yoga
{
    class Config
    {
    public:
        Config();
        ~Config();

        void setPointScaleFactor(float pointScaleFactor = 1.0f);

        void setUseWebDefaults(bool useWebDefaults = false);

        void setCloneNodeCallback(YGCloneNodeFunc callback);

        void setContext(void* context);

        void setLogger(YGLogger logger);

        void setErrata(YGErrata errata);

    private:
        YGConfigRef _yogaConfig;
    };
}

#endif //YOGA_CONFIG_HPP
