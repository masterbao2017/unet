/*************************************************************************
	> File Name: FileSearched.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月11日 星期一 16时44分21秒
 ************************************************************************/

#include<iostream>
#include<deque>
#include<string.h>
#include<algorithm>
#include<functional>
#include"FileSearched.h"


FileSearched::FileSearched(const std::string& directoryName) :
    directoryPath(directoryName)
{};

FileSearched::FileSearched(const FileSearched& lhs) : 
    directoryPath(lhs.directoryPath),
    fileNameList(lhs.fileNameList),
    directoryBuffer(lhs.directoryBuffer)
{};

FileSearched::FileSearched(FileSearched&& lhs) : 
    directoryPath(std::move(lhs.directoryPath)),
    fileNameList(std::move(lhs.fileNameList)),
    directoryBuffer(std::move(lhs.directoryBuffer))
{};

FileSearched& FileSearched::operator=(const FileSearched& lhs)
{
    if(lhs == *this)
        return *this;

    directoryPath = lhs.directoryPath;
    fileNameList = lhs.fileNameList;
    directoryBuffer = lhs.directoryBuffer;

    return *this;
}

FileSearched& FileSearched::operator=(FileSearched&& lhs)
{
    directoryPath = std::move(lhs.directoryPath);
    fileNameList = std::move(lhs.fileNameList);
    directoryBuffer = std::move(lhs.directoryBuffer);
    return *this;
}
    


int FileSearched::update()
{
    struct dirent* drip = nullptr;
    std::deque<std::string> directoryList;
    struct stat statBuffer;

    directoryList.push_back(directoryPath);

    while(!directoryList.empty())
    {
        const std::string& str = directoryList.front();
        DIR* dp = ::opendir(str.c_str());
        
        if(dp == nullptr)
        {
            std::cerr << __FILE__ << " " << __LINE__ << "opendir error!" << std::endl;
            return -1;
        }

        while((drip=::readdir(dp)) != nullptr)
        {
            if((strcmp(drip->d_name,".")==0) || strcmp(drip->d_name,"..")==0)
                continue;
        
            ::lstat(drip->d_name,&statBuffer);
            if(S_ISDIR(statBuffer.st_mode))
                directoryList.push_back(drip->d_name);
            else
            {
                std::string str = drip->d_name;
                str.push_back('\t');
                str += std::to_string(statBuffer.st_size);
            }
        }

        ::closedir(dp);
    }

    return 0;
}
