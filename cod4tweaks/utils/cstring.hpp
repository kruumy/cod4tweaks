#pragma once

namespace utils::cstring
{
	inline bool starts_with(const char* str, const char* prefix)
	{
		const size_t strLen = strlen(str);
		const size_t prefixLen = strlen(prefix);
		return strLen >= prefixLen && strncmp(str, prefix, prefixLen) == 0;
	}

	inline bool contains_any(const char* target, const char* const* subjects, size_t subjectCount)
	{
		for (size_t i = 0; i < subjectCount; i++)
		{
			if (strstr(target, subjects[i]) != nullptr)
			{
				return true;
			}
		}
		return false;
	}

	void replace_all(char* str, const char target, const char replacement) 
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == target)
			{
				str[i] = replacement;
			}
		}
	}
}