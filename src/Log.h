#ifndef LOG_H
#define LOG_H
#include <Arduino.h>
#include <list>

class Log
{
public:
	Log(uint32_t maxSize = 80 * 40) : maxSize(maxSize) {} // save about 20 lines
	void addLine(const String& line);
	void addBytes(const String& header, const uint8_t* bytes, uint8_t len);
	String getLines(uint32_t from_idx = 0) const;

private:
	std::list<std::pair<uint32_t,String>> logLines;
	uint32_t current_id = 0;
	uint32_t logSize = 0;
	uint32_t maxSize = 80 * 40;
};
#endif
