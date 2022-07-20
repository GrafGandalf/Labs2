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

int Sort1 (int Mass[], int Nreal, int N)
{
    for (int i=0; i<Nreal; i++)
    {
        if (Mass[i]%2==0)
        {
            for (int j=Nreal; j>i; j--)
            {
                std::swap(Mass[j], Mass[j-1]);
            }
            Mass[i]=Mass[i+1];
            i++; Nreal++;
        }
    }
    
    return Nreal;
}
int Sort2 (int Mass[], int Nreal, int N)
{
    for (int i=0; i<Nreal; i++)
    {
        if (Mass[i]%2==0)
        {
            int *MassZ = new int[Nreal+1];
            
            for (int j=0; j<Nreal+1; j++)
            {
                if (j<i) MassZ[j]=Mass[j];
                if ((j==i)||(j==i+1)) MassZ[j]=Mass[j];
                if (j>i) MassZ[j]=Mass[j-1];
            }
            i++; Nreal++;
            for (int j=0; j<Nreal; j++)
            {
                Mass[j]=MassZ[j];
            }
            delete [] MassZ;
        }
    }
    
    return Nreal;
}
int Sort3 (int Mass[], int Nreal, int N)
{
    int *MassZ = new int[N];
    for (int j=0; j<Nreal; j++)
    {
        MassZ[2*j]=Mass[j];
        MassZ[2*j+1]=Mass[j];
    }
    Nreal = N;
    
    for (int i=0; i<Nreal; i++)
    {
        
        if (Mass[i]%2==1)
        {
            for (int j=i; j<Nreal*2-1; j++)
            {
                Mass[j]=Mass[j+1];
            }
            Nreal--;
        }
        else
        {
            i++;
        }
    }
    
    for (int j=0; j<Nreal; j++)
    {
        Mass[j]=MassZ[j];
    }
    
    delete [] MassZ;
    return Nreal;
}


int main()
{
    int N=0; int Nreal=0;
    std::cin>>N; Nreal=N; N=N*2;
    int NZ=N; int NrealZ=Nreal;
    
    int *Mass = new int[N];
    int *MassZamen = new int[Nreal];
    
    for (int i=0; i<N; i++)
    {
        if (i<Nreal) Mass[i]=rand()%10+1;
        else Mass[i]=0;
        MassZamen[i]=Mass[i];
    }
    
    std::cout << "Alg1:" << std::endl;
    
    Timer t1;
    
    Nreal = Sort1(Mass, Nreal, N);
    
    std::cout << "Time:"<< t1.elapsed() << std::endl;
    
    N=NZ; Nreal=NrealZ;
    for (int i=0; i<N; i++)
    {
        Mass[i]=MassZamen[i];
    }
    
    std::cout << "Alg2:" << std::endl;
    
    Timer t2;
    
    Nreal = Sort2(Mass, Nreal, N);
    
    std::cout << "Time:"<< t2.elapsed() << std::endl;
    
    N=NZ; Nreal=NrealZ;
    for (int i=0; i<N; i++)
    {
        Mass[i]=MassZamen[i];
    }
    
    std::cout << "Alg3:" << std::endl;
    
    Timer t3;
    
    Nreal = Sort3(Mass, Nreal, N);
    
    std::cout << "Time:"<< t3.elapsed() << std::endl;
    
    
    delete [] Mass; delete [] MassZamen;
    return 0;
}
