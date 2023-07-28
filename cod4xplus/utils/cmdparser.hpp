#pragma once
#include <vector>
#include <string>
namespace utils
{
    class cmdparser
    {
    public:
        cmdparser(const std::string args)
        {
            ParseArguments(args);
        }

        const std::vector<std::string>& getArguments() const
        {
            return args;
        }

        bool contains(const char* arg) const
        {
            for (const std::string& argument : args)
            {
                if (argument == arg)
                {
                    return true;
                }
            }
            return false;
        }

    private:
        std::vector<std::string> args;

        void ParseArguments(const std::string& inputArgs)
        {
            args.clear();
            std::string currentArg;
            bool insideQuotes = false;
            for (size_t i = 0; i < inputArgs.size(); i++)
            {
                char currentChar = inputArgs[i];

                if (currentChar == ' ' && !insideQuotes) 
                {

                    if (!currentArg.empty()) {
                        args.push_back(currentArg);
                        currentArg.clear();
                    }
                }
                else if (currentChar == '"') 
                {
                    insideQuotes = !insideQuotes;
                }
                else 
                {
                    currentArg.push_back(currentChar);
                }
            }

            if (!currentArg.empty())
            {
                args.push_back(currentArg);
            }
        }

    };
}

