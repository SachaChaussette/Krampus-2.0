#pragma once

#include "Color.h"
#include "CoreMinimal.h"

#define LOG(_verbosity, _msg) Logger::PrintLog(_verbosity, _msg, DEBUG_INFO);
#define DEBUG_INFO " (" + string(PATH) + " : " + to_string(__LINE__) + ")"

#define WRITE_IN_LOG(_verbosity)        _verbosity >= Log
#define WRITE_IN_CONSOLE(_verbosity)    _verbosity > Log

#ifdef DEBUG
#define USE_DEBUG 1
#else
#define USE_DEBUG 0
#endif // DEBUG

//#define DEBUG_PATH

#ifdef DEBUG_PATH
#define PATH __FUNCTION__
#else
#define PATH __FILE__
#endif // DEBUG

#ifdef TIME
#define USE_TIME 1
#else
#define USE_TIME 0
#endif // TIME
using namespace std;

enum VerbosityType
{
    VeryVerbose,
    Verbose,
    Log,
    Display,
    Warning,
    Error,
    Fatal,

    VT_COUNT,
};



class VerbosityData
{
    string prefix;
    string color;
    string text;
    string debug;
    bool useDebug;
    bool useTime;

private:
    __forceinline string GetPrefix(const bool _useColor) const
    {
        string _prefix = prefix;
        if (_useColor)
        {
            _prefix = RESET + string("[") + color 
                    + prefix 
                    + RESET + "]" + color;

        }
        return _prefix;
    }
public:
    __forceinline string GetFullText(const bool _useColor = true) const
    {
        const string& _color = _useColor ? color : "";
        const string& _reset = _useColor ? RESET : "";
        string _fullText = _color + GetPrefix(_useColor) + " " + _reset;

        if (USE_TIME || useTime)
        {
            SYSTEMTIME _st;
            GetSystemTime(&_st);
            _fullText += "<" + to_string(_st.wHour + 1) + ":" + to_string(_st.wMinute) + ":" + to_string(_st.wSecond) + "> ";
        }

        _fullText += _color + text;

        if (USE_DEBUG || useDebug)
        {
            _fullText += debug;
        }

        _fullText += _reset;

        return _fullText;
    }

public:
    VerbosityData(const VerbosityType& _type, const string& _text, const string _debug,
                  const bool _useDebug = false, const bool _useTime = false)
    {
        ComputePrefix(_type);
        ComputeColor(_type);
        ComputeUseDebug(_type);
        ComputeUseTime(_type);
        text = _text;
        debug = _debug;
    }

private:
    void ComputePrefix(const VerbosityType& _type)
    {
        if (_type == VT_COUNT)
        {
            throw exception("Exception => invalid VerbosityType !");
        }

        const vector<string>& _verbosityTexts =
        {
            "VeryVerbose",
            "Verbose",
            "Log",
            "Display",
            "Warning",
            "Error",
            "Fatal",
        };

        prefix = _verbosityTexts[_type];
    }
    void ComputeColor(const VerbosityType& _type)
    {
        if (_type == VT_COUNT)
        {
            throw exception("Exception => Invalid VerbosityType !");
        }

        const vector<string>& _verbosityColors =
        {
            WHITE,
            WHITE,
            LIGHT_GRAY,
            GRAY,
            YELLOW,
            RED,
            DARK_RED,
        };

        color = _verbosityColors[_type];
    }
    void ComputeUseDebug(const VerbosityType& _type)
    {
        useDebug = set<VerbosityType>({ Warning, Error, Fatal }).contains(_type);
    }
    void ComputeUseTime(const VerbosityType& _type)
    {
        useTime = set<VerbosityType>({ Warning, Error, Log, Fatal }).contains(_type);
    }
};

class Logger
{
    string prefixLogsPath;
    string logsPath;
    string logsExtension;
    
public:
    Logger();

private:
    static void WriteInConsole(const string& _text);
    static void WriteInLogs(const string& _text);

public:
    static void PrintLog(const VerbosityType& _type, const string& _text, const string& _debug);
};
