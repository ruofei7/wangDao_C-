#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
class Word
{
public:
    Word(string word)
        : _word(word), _frequency(1)
    {
        //cout << "Word(string word)" << endl;
    }
    int push(string word)
    {
        if (word == _word)
        {
            _frequency++;
            return 0;
        }
        else
            return 1;
    }
    void printWord()
    {
        cout << "|   " << _word << ' ' << _frequency << "    |" << endl;
    }

private:
    string _word;
    int _frequency;
};
void test0(string filename)
{
    std::ifstream ifs(filename, std::ios::ate);
    if (!ifs)
    {
        cout << "ifstream open file" << filename << "error!" << endl;
        return;
    }
    //一次性读入文件所有内容，并把非字母字符转化为空格，把大写字母转化为小写字母
    int length = ifs.tellg();
    //cout << "ifs.tellg()=" << length << endl;
    ifs.seekg(std::ios::beg);
    char buff[length + 1] = {0};
    ifs.read(buff, length);
    for (int i = 0; buff[i] != 0; ++i)
    {
        if (!isalpha(buff[i]))
        {
            buff[i] = ' ';
        }
        else
        {
            tolower(buff[i]);
        }
    }
    //把C分格的buff转化成C++风格的buff,并存储在字符串流中
    string temBuff(buff);
    stringstream content;
    content << temBuff;
    //读取字符串流中的单词，并push入数组中
    string word;
    vector<Word> vec;
    int pushFlag;
    //cout << "content.tellg()" << content.tellg() << endl;
    content.seekg(0);
    while (!content.eof())
    {
        pushFlag = 1; //原数组中是否已经存在该单词
        content >> word;
        for (auto &pushWord : vec)
        {
            pushFlag = pushWord.push(word);
            if (0 == pushFlag)
                break;
        }
        if (1 == pushFlag)
        {
            Word newWord(word);
            vec.push_back(newWord);
        }
    }
    /*for (auto &printWord : vec)
    {
        printWord.printWord();
    } */
    cout << "输出前10个单词的统计结果：" << endl;
    for (size_t idx = 0; idx < 10; ++idx)
    {
        vec[idx].printWord();
    }
    ifs.close();
}
int main(void)
{
    string filename;
    cin >> filename;
    test0(filename);
    return 0;
}