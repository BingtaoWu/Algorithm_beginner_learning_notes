#include <iostream>
#include <string>

using namespace std;

class MyComputer
{
public:
    ~MyComputer();                                  // ����������������
    MyComputer(string cpu, string gpu, int memory); // ���ǹ��캯������
    string get_cpu();                               // ��ȡCPU��Ϣ
    string get_gpu();                               // ��ȡGPU��Ϣ
    int get_memory();                               // ��ȡ�ڴ���Ϣ

private:
    string cpu;
    string gpu;
    int memory;
};

// ��Ա�������壬�������캯��
MyComputer::MyComputer(string cpu, string gpu, int memory) : cpu(cpu), gpu(gpu), memory(memory)
{
    cout << "Computer is being created" << endl;
    cout << "CPU: " << cpu << endl;
    cout << "GPU: " << gpu << endl;
    cout << "Memory: " << memory << "GB" << endl;
}

MyComputer::~MyComputer()
{
    cout << "Computer is being destroyed" << endl;
}

string MyComputer::get_cpu()
{
    return cpu;
}

string MyComputer::get_gpu()
{
    return gpu;
}

int MyComputer::get_memory()
{
    return memory;
}

int main()
{
    MyComputer computer("Intel 13600kf", "NVIDIA RTX 4060Ti", 16);

    return 0;
}