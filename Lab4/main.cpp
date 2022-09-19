#include <iostream>
#include <chrono> // для функций из std::chrono
 
class Timer
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    
    std::chrono::time_point<clock_t> m_beg;
 
public:
    Timer() : m_beg(clock_t::now())
    {
    }
    
    void reset()
    {
        m_beg = clock_t::now();
    }
    
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

struct Spisok
{
    
    Spisok* next;
    int Chis;
    
};


void ADD (Spisok* head, int Znac)
{
    Spisok* p = new Spisok;
    p->Chis=Znac;
    
    p->next = head->next;
    head->next = p;
    
}

void POISK (Spisok* head, int Znac)
{
    Spisok* p = head->next;
    int count=0;
    while (p!=nullptr)
    {
        if (Znac == p->Chis) count++;
        p = p->next;
    }
    
    std::cout << count << " ";
}

void CLEAR (Spisok* head)
{
    Spisok* temp = new Spisok;
    Spisok* p = head->next;
    
    while (p!=nullptr)
    {
        temp=p;
        p = p->next;
        delete temp;
    }
}

int main()
{
    
    std::cout << "Alg1:" << std::endl;
    
    Timer t1;
    
    Spisok* head = new Spisok;
    head->next=nullptr;
    
    for (int i=0; i<10000; i++)
    {
        ADD(head, 1+rand()%1000);
    }

    for (int i=0; i<1000; i++)
    {
        POISK(head, i);
    }
    
    std::cout << "Time:"<< t1.elapsed() << std::endl;
    
    std::cout << "Alg2:" << std::endl;
    
    Timer t2;
    
    int Mass[10000]; int count=0;
    
    for (int i=0; i<10000; i++)
    {
        Mass[i]=1+rand()%1000;
    }
    
    for (int i=0; i<1000; i++)
    {
        count=0;
        for (int j=0; j<10000; j++)
        {
            if (Mass[j]==i) count++;
        }
        std::cout << count << " ";
    }
    
    std::cout << "Time:"<< t2.elapsed() << std::endl;
    
    CLEAR(head);
    delete head;
    return 0;
}
