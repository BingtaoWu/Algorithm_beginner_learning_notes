#include <iostream>
using namespace std;

// ǰ������
class NoblePhantasm;
class Servant;
class Battle;

// ����ս����
class Battle
{
public:
    static void startBattle(Servant &s1, Servant &s2);
};

// ����Ӣ����
class Servant
{
public:
    Servant(char *name, char *class_type, int strength);

    // �ǳ�Ա��������Ϊ��Ԫ
    friend void compareStrength(const Servant &s1, const Servant &s2);

    // ��Ա��������Ϊ��Ԫ
    friend void Battle::startBattle(Servant &s1, Servant &s2);

    void show(NoblePhantasm *np);

private:
    char *m_name;       // Ӣ������
    char *m_class_type; // Ӣ��ְ��
    int m_strength;     // Ӣ��ǿ��
};

// ����������
class NoblePhantasm
{
public:
    NoblePhantasm(char *name, char *rank, char *type);

    // ��Ӣ��������Ϊ���������Ԫ��
    friend class Servant;

private:
    char *m_name; // ��������
    char *m_rank; // ���ߵȼ�
    char *m_type; // ��������
};

// ʵ��Ӣ����
Servant::Servant(char *name, char *class_type, int strength)
    : m_name(name), m_class_type(class_type), m_strength(strength) {}

void Servant::show(NoblePhantasm *np)
{
    cout << "Ӣ�飺" << m_name << "��ְ�ף�" << m_class_type << "��ǿ�ȣ�" << m_strength << endl;
    cout << "���ߣ�" << np->m_name << "���ȼ���" << np->m_rank << "�����ͣ�" << np->m_type << endl;
}

// ʵ�ֱ�����
NoblePhantasm::NoblePhantasm(char *name, char *rank, char *type)
{
    m_name = name;
    m_rank = rank;
    m_type = type;
}

// �ǳ�Ա������Ϊ��Ԫ���Ƚ�����Ӣ���ǿ��
void compareStrength(const Servant &s1, const Servant &s2)
{
    if (s1.m_strength > s2.m_strength)
    {
        cout << s1.m_name << " ��ǿ�� (" << s1.m_strength << ") ���� " << s2.m_name << " ��ǿ�� (" << s2.m_strength << ")" << endl;
    }
    else if (s1.m_strength < s2.m_strength)
    {
        cout << s2.m_name << " ��ǿ�� (" << s2.m_strength << ") ���� " << s1.m_name << " ��ǿ�� (" << s1.m_strength << ")" << endl;
    }
    else
    {
        cout << s1.m_name << " �� " << s2.m_name << " ��ǿ����ͬ (" << s1.m_strength << ")" << endl;
    }
}

// ��Ա������Ϊ��Ԫ��ģ��ս��
void Battle::startBattle(Servant &s1, Servant &s2)
{
    cout << "ս����ʼ��" << s1.m_name << " vs " << s2.m_name << endl;
    if (s1.m_strength > s2.m_strength)
    {
        cout << s1.m_name << " ��ʤ��" << endl;
    }
    else if (s1.m_strength < s2.m_strength)
    {
        cout << s2.m_name << " ��ʤ��" << endl;
    }
    else
    {
        cout << "ƽ�֣�" << endl;
    }
}

int main()
{
    // ����Ӣ��ͱ���ʵ��
    Servant saber((char *)"����������", (char *)"Saber", 90);
    NoblePhantasm excalibur((char *)"��Լʤ��֮��", (char *)"EX", (char *)"�Ծ�����");
    saber.show(&excalibur);

    Servant archer((char *)"����", (char *)"Archer", 85);
    NoblePhantasm ubw((char *)"���޽���", (char *)"E~A++", (char *)"��ʵ����");
    archer.show(&ubw);

    Servant rider((char *)"����ɯ", (char *)"Rider", 88);
    NoblePhantasm bellerophon((char *)"������֮��", (char *)"A++", (char *)"�ԳǱ���");
    rider.show(&bellerophon);

    Servant lancer((char *)"��¬ľ��", (char *)"Lancer", 87);
    NoblePhantasm gae_bolg((char *)"����Swift", (char *)"A+++", (char *)"���˱���");
    lancer.show(&gae_bolg);

    // ʹ�÷ǳ�Ա������Ԫ�Ƚ�ǿ��
    compareStrength(saber, archer);
    compareStrength(rider, lancer);

    // ʹ�ó�Ա������Ԫģ��ս��
    Battle::startBattle(saber, rider);
    Battle::startBattle(archer, lancer);

    return 0;
}