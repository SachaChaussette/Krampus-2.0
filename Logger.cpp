#include "Logger.h"

Logger::Logger()
{

}

void Logger::WriteInConsole(const string& _text)
{
	cout << _text << endl;
}

void Logger::WriteInLogs(const string& _text)
{
	const string& _finalPath = "Logs/Log.txt";
	ofstream _stream = ofstream(_finalPath, ios_base::app | ios_base::binary);

	_stream << _text << "\n";
}

void Logger::PrintLog(const VerbosityType& _type, const string& _text, const string& _debug)
{
	if (WRITE_IN_LOG(_type))
	{
		const VerbosityData& _verbosity = VerbosityData(_type, _text, _debug);
		WriteInLogs(_verbosity.GetFullText(false));

		if (WRITE_IN_CONSOLE(_type))
		{
			WriteInConsole(_verbosity.GetFullText(true));
		}
	}
	if (_type == Fatal)
	{
		assert(false, _text);
	}
}
