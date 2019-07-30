#include<log4cpp/PatternLayout.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/RollingFileAppender.hh> 
#include<log4cpp/Category.hh>
#include<log4cpp/Priority.hh>
#include<iostream>
using std::cout;
using std::endl;
//using namespace log4cpp;
int main()
{
    //1.格式化器==>PatternLayout
    log4cpp::PatternLayout *ptnLayout1=new log4cpp::PatternLayout();
    ptnLayout1->setConversionPattern("%d [%p] %m%n");
    log4cpp::PatternLayout *ptnLayout2=new log4cpp::PatternLayout();
    ptnLayout2->setConversionPattern("%d [%p] %m%n");
    log4cpp::PatternLayout *ptnLayout3=new log4cpp::PatternLayout();
    ptnLayout3->setConversionPattern("%d [%p] %m%n");
    //2.输出目的地==>OstreamAppender(输出流)/FileAppender(文件流)/RollingFileAppender(回卷文件)
    log4cpp::OstreamAppender *ostreamAppender=new log4cpp::OstreamAppender("ostreamAppender",&cout);
    ostreamAppender->setLayout(ptnLayout1);
    log4cpp::FileAppender *fileAppender=new log4cpp::FileAppender("fileAppender","wangdao.log");
    fileAppender->setLayout(ptnLayout2);
    log4cpp::RollingFileAppender *rollingFileAppender=new log4cpp::RollingFileAppender("rollingFileAppender","rollwangdao.log",512,5);
    rollingFileAppender->setLayout(ptnLayout3);
    //3、日志记录器==>Category
    log4cpp:: Category & mycategory=log4cpp::Category::getRoot().getInstance("mycategory");
    //4、设置日志记录器优先级
    mycategory.setPriority(log4cpp::Priority::DEBUG);
    //5、添加输出目的地：
    mycategory.addAppender(ostreamAppender);
    mycategory.addAppender(fileAppender);
    mycategory.addAppender(rollingFileAppender);

    for(int idx=0;idx!=50;++idx)
    {
        mycategory.alert("%d this is alert message",idx);//记录一条具有报警优先级的信息
        mycategory.crit("%d this is crit message",idx);
        mycategory.error("%d this is error message",idx);
        mycategory.warn("%d this is warn message",idx);
        mycategory.info("%d this is info message",idx);
        mycategory.notice("%d this is notice message",idx);
    }
    //删除所有Appender
    log4cpp::Category::shutdown();
    return 0;
}