#include <iostream>

/*
Одна запись в списке запланированных дел представляет собой структуру Dailyltem, которая содержит время начала и окончания работы, описание и признак выполнения.

Реализовать класс DailySchedule, представляющий собой план работ на день. 
Реализовать методы добавления, удаления и изменения планируемой работы. 
При добавлении проверять корректность временных рамок (они не должны пересекаться с уже запланированными мероприятиями). 
Реализовать метод поиска свободного промежутка времени. Условие поиска задает размер искомого интервала, а также временные рамки, в которые он должен попадать. 
Метод поиска возвращает структуру Dailylten с пустым описанием вида работ. 
Реализовать операцию генерации объекта Redo (еще раз), содержащего список дел. не выполненных в течение дня, из объекта типа DailySchedule.
*/

//TODO:TContainer
//TODO:Changing timef and times from standalone function (*Schedule)
struct Time
{
    int hour,minute,second;
    Time(int _h=24, int _m=0,int _s=0)
    {
        // TODO:Добавить чек времени
        hour=_h;
        minute=_m;
        second=_s;
    }
    
    Time(Time t)
    {
        hour=t.hour;
        minute=t.minute;
        second=t.second;
    }
    
    bool operator>(Time t)
    {
        return hour*3600+minute*60+second>t.hour*3600+t.minute*60+t.second;
    }
    
    //TODO:operator>> (text->int);
    
};

class Dailyltem
{
    Time times,timef;
    char* desc;
    char* complition;
    bool complete=0;
public:

//Constructs------------------------------
    Dailyltem()
    {
        desc = new char[1e4];
        complition = new char[1e4];
    }
    Dailyltem(DailyItem t)
    {
        strcpy(desc,t.desc);
        strcpy(complition,t.complition);
        bool complete=t.complete;
        times=t.times;
        timef=t.timef;
    }
//---------------------------------------


//Реализовать методы добавления,изменения планируемой работы.
void SetDesc(char* text)
{
    strcpy(desc,text);
}
void SetCompl(char* text)
{
    strcpy(complition,text);
}
void SetTime()
{
    std::cout<<"Input start time:"
    std::cin>>times;
    std::cin>>timef;
}
void Complete()
{
    complete=1;
}


    Dailyltem* operator=(DailyItem t)
    {
        strcpy(desc,t.desc);
        strcpy(complition,t.complition);
        bool complete=t.complete;
        times=t.times;
        timef=t.timef;
        return this;
    }
    
    ~Dailyltem()
    {
        delete desc[];
        delete complition[];
    }
    
    
    
}




//TODO: Add a cout operator like a list of tasks
//TODO: Add SORT
class DailySchedule
{
    Dailyltem* Schedule=new Schedule[1e5];
    int cur_pos=1;
public:
    DailySchedule(DailySchedule t)
    {
        for(int i=0;i<1e5;++i)
        {
            Schedule[i]=t.Schedule[i];
        }
    }
    
    //you cannot complete without knowing the position in list
    void SetComplete(int i)
    {
        Schedule[i].Complete();
    }
    
    //Реализовать методы добавления, удаления и изменения планируемой работы.
    
    void AddEl()
    {
        std::cout<<"Set your Description:\n";
        char* text;
        gets(text);
        Schedule[cur_pos].SetDesc(text);
        
        std::cout<<"Set your Complition:\n";
        char* text;
        gets(text);
        Schedule[cur_pos].SetCompl();
        Schedule[cur_pos].SetTime();
        //TODO:При добавлении проверять корректность временных рамок (они не должны пересекаться с уже запланированными мероприятиями).
        //TODO: Add sorting positions
    }
    void ChangeEl(int i)
    {
        std::cout<<"Set your Description (If you don't need it,left it blank):\n";
        char* text;
        gets(text);
        if(strcmp(text," ")==0)
            Schedule[i].SetDesc(text);
        
        std::cout<<"Set your Complition (If you don't need it,left it blank):\n";
        char* text;
        gets(text);
        if(strcmp(text," ")==0)
            Schedule[i].SetCompl();
        
        //TODO:Change time(Del cur + Add new)
    }
    //you cannot delete without knowing the position in list
    void DeleteEl(int pos)
    {
        swap();
    }
    
    //------------------------------------------------------------------------
    
    /*Реализовать метод поиска свободного промежутка времени. Условие поиска задает размер искомого интервала, а также временные рамки, в которые он должен попадать. 
    Метод поиска возвращает структуру Dailylten с пустым описанием вида работ.*/
    Dailyltem Search(int interval,Time start,Time finish)
    {
        
    }
    //------------------------------------------------------------------------
    
    ~DailySchedule()
    {
       Schedule[]; 
    }
};

int main()
{
    
    
    return 0;
}
