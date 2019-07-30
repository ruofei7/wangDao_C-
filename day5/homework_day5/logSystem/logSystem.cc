#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Mylogger
{
public:
    void LogWarn(const char *message, const char *filename, const char *funcName, const int line)
    {
        char buff[300] = {0};
        sprintf(buff, "%s %s %d %s", filename, funcName, line, message);
        _mycategory.warn(buff);
    }
    void LogError(const char *message, const char *filename, const char *funcName, const int line)
    {
        char buff[300] = {0};
        sprintf(buff, "%s %s %d %s", filename, funcName, line, message);
        _mycategory.error(buff);
    }
    void LogDebug(const char *message, const char *filename, const char *funcName, const int line)
    {
        char buff[300] = {0};
        sprintf(buff, "%s %s %d %s", filename, funcName, line, message);
        _mycategory.debug(buff);
    }
    void LogInfo(const char *message, const char *filename, const char *funcName, const int line)
    {
        char buff[300] = {0};
        sprintf(buff, "%s %s %d %s", filename, funcName, line, message);
        _mycategory.info(buff);
    }
    static Mylogger *getInstance(string ostreamAppender = "ostreamAppender", string fileAppender = "fileAppender", string filename = "wangdao.log", string mycategory = "mycategory")
    {
        if (nullptr == _pInstance)
        {
            _pInstance = new Mylogger(ostreamAppender, fileAppender, filename, mycategory);
        }
        return _pInstance;
    }
    static void destroy()
    {
        if (_pInstance)
        {
            delete _pInstance;
        }
    }

private:
    Mylogger(string ostreamAppender, string fileAppender, string filename, string mycategory)
        : _ptnLayout1(new log4cpp::PatternLayout), _ptnLayout2(new log4cpp::PatternLayout), _ostreamAppender(new log4cpp::OstreamAppender(ostreamAppender, &cout)), _fileAppender(new log4cpp::FileAppender(fileAppender, filename)), _mycategory(log4cpp::Category::getRoot().getInstance(mycategory))
    {
        _ptnLayout1->setConversionPattern("%d [%p]\t%m%n");
        _ptnLayout2->setConversionPattern("%d [%p]\t%m%n");
        _ostreamAppender->setLayout(_ptnLayout1);
        _fileAppender->setLayout(_ptnLayout2);
        _mycategory.setPriority(log4cpp::Priority::DEBUG);
        _mycategory.addAppender(_ostreamAppender);
        _mycategory.addAppender(_fileAppender);
    }
    ~Mylogger()
    {
        //delete _ptnLayout1;
        //delete _ptnLayout2;
        //delete _ostreamAppender;
        //delete _fileAppender;
        //直接调用shutdown()就可以全部回收
        log4cpp::Category::shutdown();
    }

private:
    log4cpp::PatternLayout *_ptnLayout1;
    log4cpp::PatternLayout *_ptnLayout2;
    log4cpp::OstreamAppender *_ostreamAppender;
    log4cpp::FileAppender *_fileAppender;
    log4cpp::Category &_mycategory;
    static Mylogger *_pInstance;
};
Mylogger *Mylogger::_pInstance = nullptr;
void test0(void)
{
    Mylogger *plog = Mylogger::getInstance();
    for (int i = 0; i < 3; i++)
    {

        plog->LogInfo("this is a info message", __FILE__, __FUNCTION__, __LINE__);
        plog->LogError("this is a error message", __FILE__, __FUNCTION__, __LINE__);
        plog->LogWarn("this is a warn message", __FILE__, __FUNCTION__, __LINE__);
        plog->LogDebug("this is a debug message", __FILE__, __FUNCTION__, __LINE__);
    }
    Mylogger::destroy();
}
int main(void)
{
    test0();
    return 0;
}
