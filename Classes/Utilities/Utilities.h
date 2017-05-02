#ifndef Utilities_H
#define Utilities_H

#include <random>
#include <sstream>
#include <time.h>
#include <numeric> 

#pragma warning(disable: 4996)

#if COCOS2D_DEBUG
    #define DynamicCast dynamic_cast
#else
    #define DynamicCast static_cast
#endif

#define MAX_LEN     (cocos2d::kMaxLogLen + 1)


#define RAND_LIMIT    32767

#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

#define LocalizePicName(str) \
( Application::getInstance()->getCurrentLanguage() == LanguageType::CHINESE ? std::string(str) + std::string(".png") : std::string(str) + std::string("_en.png") )

#define LocalizePlistName(str) \
( Application::getInstance()->getCurrentLanguage() == LanguageType::CHINESE ? std::string(str) + std::string(".plist") : std::string(str) + std::string("_en.plist") )

/*
/// Random number in range [-1,1]
inline float RandomFloat()
{
    float r = (float)(std::rand() & (RAND_LIMIT));
    r /= RAND_LIMIT;
    r = 2.0f * r - 1.0f;
    return r;
}
*/
/*
/// Random floating point number in range [lo, hi]
inline float RandomFloat(float lo, float hi)
{
    float r = (float)(std::rand() & (RAND_LIMIT));
    r /= RAND_LIMIT;
    r = (hi - lo) * r + lo;
    return r;
}
*/
inline std::string IntToString(const int in)
{
    std::stringstream ss;
    ss << in;
    return ss.str();
}

static std::default_random_engine g_worldGenerator(time(nullptr));

inline unsigned int Fitness_proportionate_selection(const std::vector<double>& weights)
{
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    double rand = dis(g_worldGenerator) * std::accumulate(weights.begin(), weights.end(), 0.0);

    for (size_t i = 0; i < weights.size(); ++i)
    {
        rand -= weights[i];
        if (rand < 0)
        {
            return i;
        }
    }

    return -1;
}

static const unsigned int g_circleMaxEdgeSize = 3;

static const unsigned int g_normalScore = 50;
static const unsigned int g_goodScore = 100;
static const unsigned int g_perfectScore = 300;

static const long g_cdTimeForEachRound = 3500;

#define RECORD_TAG 1000
#define RECORDSTAR_TAG 1001
#define RECORD_LAYERCOLOR_TAG 1002

#endif //Utilities_H
