#pragma once
#include <string>

// WeatherEntry class to store a full row of data
class WeatherEntry
{
public:
    // Constructor for WeatherEntry
    WeatherEntry(std::string _time,
                 double _atTemperature,
                 double _beTemperature,
                 double _bgTemperature,
                 double _chTemperature,
                 double _czTemperature,
                 double _deTemperature,
                 double _dkTemperature,
                 double _eeTemperature,
                 double _esTemperature,
                 double _fiTemperature,
                 double _frTemperature,
                 double _gbTemperature,
                 double _grTemperature,
                 double _hrTemperature,
                 double _huTemperature,
                 double _ieTemperature,
                 double _itTemperature,
                 double _ltTemperature,
                 double _luTemperature,
                 double _lvTemperature,
                 double _nlTemperature,
                 double _noTemperature,
                 double _plTemperature,
                 double _ptTemperature,
                 double _roTemperature,
                 double _seTemperature,
                 double _siTemperature,
                 double _skTemperature);

    // static OrderBookType stringToOrderBookType(std::string s);

    // Variables for WeatherEntry
    std::string time;
    double atTemperature;
    double beTemperature;
    double bgTemperature;
    double chTemperature;
    double czTemperature;
    double deTemperature;
    double dkTemperature;
    double eeTemperature;
    double esTemperature;
    double fiTemperature;
    double frTemperature;
    double gbTemperature;
    double grTemperature;
    double hrTemperature;
    double huTemperature;
    double ieTemperature;
    double itTemperature;
    double ltTemperature;
    double luTemperature;
    double lvTemperature;
    double nlTemperature;
    double noTemperature;
    double plTemperature;
    double ptTemperature;
    double roTemperature;
    double seTemperature;
    double siTemperature;
    double skTemperature;
};
