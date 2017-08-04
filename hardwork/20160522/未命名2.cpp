#include<iostream>
#include<afx.h>
using namespace std; 

class CPerson : public CObject  
{  
DECLARE_SERIAL(CPerson)  
private:  
    CString _name;  
    int _age;  
    bool _gender;  
    CString _words;  
public:  
    CPerson();  
    CPerson(CString name, int age, bool gender = true);  
    CString getName();  
    CString getWords();  
    void setWords(CString words);  
    int getAge();  
    bool isMale();  
    void say();  
    void say(CString msg);  
    virtual void Serialize(CArchive& ar);  
}; 

 
 
IMPLEMENT_SERIAL(CPerson, CObject, 1)  
 
CPerson::CPerson()  
{  
    _name = _T("???");  
    _age = 0;  
    _gender = true;  
}  
 
CPerson::CPerson(CString name, int age, bool gender)  
{  
    _name = name;  
    _age = age;  
    _gender = gender;  
}  
 
CString CPerson::getName()  
{  
    return _name;  
}  
 
CString CPerson::getWords()  
{  
    return _words;  
}  
 
void CPerson::setWords(CString words)  
{  
    _words = words;  
}  
 
int CPerson::getAge()  
{  
    return _age;  
}  
 
bool CPerson::isMale()  
{  
    return _gender;  
}  
 
void CPerson::say()  
{  
    say(_words);  
}  
 
void CPerson::say(CString msg)  
{  
    _tprintf(_T("%s: %s\r\n"), _name, msg);  
}  
 
void CPerson::Serialize(CArchive& ar)  
{  
    if (ar.IsStoring())  
    {  
        ar << this->_name<<this->_age<<this->_gender << this->_words;  
    }  
    else 
    {  
        ar >> this->_name>>this->_age>>this->_gender >> this->_words;  
    }  
} 


int main()  
{  
    setlocale(LC_ALL, "chs");  
 
    //??????????  
    CPerson tong(_T("???"), 28, false);  
    tong.setWords(_T("????..."));  
 
    CPerson bai(_T("???"), 27, true);  
    bai.setWords(_T("?????!"));  
 
    //????  
    CFile oFile(_T("persons.archive"),CFile::
modeCreate|CFile::modeWrite);  
    CArchive oar(&oFile, CArchive::store);  
 
    //??????  
    oar << &tong << &bai;  
    //oar.WriteObject(&tong);  
    //oar.WriteObject(&bai);  
 
    oar.Close();  
    oFile.Close();  
 
    //????  
    CFile iFile(_T("persons.archive"), CFile::modeRead);  
    CArchive iar(&iFile, CArchive::load);  
 
    CPerson *p1, * p2;  
 
    //??????  
    iar >> p1 >> p2;  
    //p1 = iar.ReadObject(RUNTIME_CLASS(CPerson));  
    //p2 = iar.ReadObject(RUNTIME_CLASS(CPerson));  
 
    //?????????*_*ii  
    p1->say();  
    p2->say();  
 
    delete p1;  
    delete p2;  
} 
