#pragma once
#include "IndexedList.h"
#include <string>

namespace name19_29
{
	class NamesIndexedList : public IndexedList<std::string>
	{
	public:

		NamesIndexedList() :
			IndexedList<std::string>(26)
		{

		}

	private:
		virtual size_t getIndex(const std::string& data) override
		{
			return static_cast<size_t>(::toupper(data[0])) - 'A';
		}
	};
}