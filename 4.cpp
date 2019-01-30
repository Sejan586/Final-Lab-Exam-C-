
#include<bits/stdc++.h>
using namespace std;
class Person1
{
public:
    string name;
    int age;
    int id;
};
class Date
{
public:
    string date;
    Date() {};
    Date(string d)
    {
        date=d;
    }
};
class Person
{
public:
    string name;
    Date date1;
    Person()
    {};
    Person(string n)
    {
        this->name=n;
    };
    Person(string name,string date)
    {
        this->name=name;
        date1.date=date;
    };

};
class Department
{
public:
    string department_name;
    Department() {};
    Department(string name)
    {
        department_name=name;
    }
};
class Contestant : public Person
{
public:
    string id;
    int prob_solve;
    Department department;
    Contestant() {};
    Contestant(string name,string date,Department dp_name,string id_no,int prob_solve) : Person(name,date)
    {
        this->prob_solve=prob_solve;
        id=id_no;
        department=dp_name;
    }
    view_Contestant_info()
    {
        cout<<"Name                 : "<<name<<endl;
        cout<<"Department           : "<<department.department_name<<endl;
        cout<<"Contestant ID        : "<<id<<endl;
        cout<<"Contestant solve no  : "<<prob_solve<<endl;
    }

};
class ACM_finalist: public Person
{
public:
    string id2;
    int prob_solve2;
    Department department2;
    ACM_finalist() {};
    ACM_finalist(string name,string date,Department dp_name,string id_no2,int prob_solve2) : Person(name,date)
    {
        this->prob_solve2=prob_solve2;
        id2=id_no2;
        department2=dp_name;
    }
    view_ACM_finalist_info()
    {
        cout<<"Name                 : "<<name<<endl;
        cout<<"Department           : "<<department2.department_name<<endl;
        cout<<"finalist ID          : "<<id2<<endl;
        cout<<"finalist solve no    : "<<prob_solve2<<endl;
    }
    friend dotdisplay();
    friend optionDisplay();

};
dotdisplay()
{
    cout<<"\n................................."<<endl;
}
optionDisplay()
{
    cout<<"1.View faculty members\n2.View all contestants\n3.View selected Contestants whom problems may be included\n0.Break"<<endl;
}

class Faculty : public Person
{
public:
    string designation;
    Department department;
    Faculty() {};
    Faculty(string designation,string name,Department department1):Person(name)
    {
        this->designation=designation;
        department=department1;
    }
    view_faculty()
    {
        cout<<"................................."<<endl;
        cout<<"Name       : "<<name<<endl;
        cout<<"Department : "<<department.department_name<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout<<"................................."<<endl;
    }

};

int main()
{
    Department dpt("cse");
    int i, j, k, l;
    int x=0,y=0;
    int ind=0,ind1=0,z;
    Faculty *faculty_member[5]=
    {
        new Faculty("Assistant Professor","Partha Chakraborty",dpt),
        new Faculty("Assistant Professor","Kamal Hossain Chowdhury",dpt),
        new Faculty("Assistant Professor","Mahmudul Hasan",dpt),
        new Faculty("Assistant Professor","Faisal Ahmed",dpt),
        new Faculty("Assistant Professor","Hafiz Ahmed",dpt)
    };
    cout<<" Press 3 To See Contestant: "<<endl;
    cin>>x;
    cout<<"Press 4 To See Acm finalist list: "<<endl;
    cin>>y;

    Contestant *a1[]=
    {

        new Contestant("Arif","1-1-97",dpt,"172820",15),
        new Contestant("Joy","1-3-98",dpt,"172830",14),
        new Contestant("Helal","1-10-97",dpt,"172832",15),

        new Contestant("Akas","1-8-97",dpt,"172834",16),

        new Contestant("Sabbir","1-6-97",dpt,"172835",17)
    };
    ACM_finalist *a2[]=
    {
        new ACM_finalist("Nabil","10-09-96",dpt,"101101",4),
        new ACM_finalist("Tanvir","10-10-96",dpt,"101102",1),
        new ACM_finalist("Raihan","11-11-98",dpt,"101103",7),
        new ACM_finalist("Fahim","11-12-97",dpt,"101104",11),
        new ACM_finalist("Mohib","10-01-96",dpt,"101105",11)
    };


    if(y==0)
    {
        int max1;
        for(int z=0; z<x; z++)
        {
            if(z==0)
            {
                max1=a1[z]->prob_solve;
            }
            if(z>0)
            {
                if(a1[z]->prob_solve>max1)
                {
                    ind=z;
                    max1 = a1[z]->prob_solve;
                }
            }
            if(z==x-1)
            {
                int max2;

                for(int m=0; m<x; m++)
                {
                    if(m==0)
                    {
                        max2=a1[m]->prob_solve;
                    }
                    if(m>0)
                    {
                        if(m!=ind&&a1[m]->prob_solve>max2)
                        {
                            ind=m;
                            max2 = a1[m]->prob_solve;
                        }
                    }
                }
            }
        }
    }


    else if(y==1)
    {
        int max1;
        for(int z=0; z<x; z++)
        {
            if(z==0)
            {
                max1=a1[z]->prob_solve;
            }
            if(z>0)
            {
                if(a1[z]->prob_solve>max1)
                {
                    ind=z;
                    max1 = a1[z]->prob_solve;
                }
            }
            ind1=0;
        }
    }

    else if(y>1)
    {
        int max1;
        for(int z=0; z<y; z++)
        {
            if(z==0)
            {
                max1=a2[z]->prob_solve2;
            }
            if(z>0)
            {
                if(a2[z]->prob_solve2>max1)
                {
                    ind=z;
                    max1 = a2[z]->prob_solve2;
                }
            }
            if(z==y-1)
            {
                int max2;

                for(int m=0; m<y; m++)
                {
                    if(m==0)
                    {
                        max2=a2[m]->prob_solve2;
                    }
                    if(m>0)
                    {
                        if(m!=ind&&a2[m]->prob_solve2>max2)
                        {
                            ind1=m;
                            max2 = a2[m]->prob_solve2;
                        }
                    }
                }
            }
        }
    }
    optionDisplay();
    int w;
    while(1)
    {

        cin>>w;
        if(w==0)
            break;
        switch(w)
        {
        case 1:
            for(int k=0; k<3; k++)
            {
                faculty_member[k]->view_faculty();

            }
            optionDisplay();
            break;
        case 2:
        {
            for(int l=0; l<x; l++)
            {
                dotdisplay();
                a1[l]->view_Contestant_info();
            }
            dotdisplay();
            for(int l=0; l<y; l++)
            {
                dotdisplay();
                a2[l]->view_ACM_finalist_info();
            }
        }
        optionDisplay();
        break;
        case 3:
            if(y==0)
            {
                cout<<"\n\nSELECTED CONTESTANT 1:"<<endl;
                a1[ind]->view_Contestant_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[1]->view_faculty();
                dotdisplay();
                cout<<"\nSELECTED CONTESTANT 2:"<<endl;
                a1[ind1]->view_Contestant_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[1]->view_faculty();
                dotdisplay();
                optionDisplay();
                break;
            }
            else if(y==1)
            {
                cout<<"\n\nSELECTED CONTESTANT 1:"<<endl;
                a1[ind]->view_Contestant_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[0]->view_faculty();
                dotdisplay();
                cout<<"\nSELECTED CONTESTANT 2:"<<endl;
                a2[ind1]->view_ACM_finalist_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[1]->view_faculty();
                dotdisplay();
                optionDisplay();
                break;
            }
            else if(y>=2)
            {
                cout<<"\n\nSELECTED CONTESTANT 1:"<<endl;
                a2[ind]->view_ACM_finalist_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[0]->view_faculty();
                dotdisplay();
                cout<<"\nSELECTED CONTESTANT 2:"<<endl;
                a2[ind1]->view_ACM_finalist_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[1]->view_faculty();
                dotdisplay();
                optionDisplay();
                break;
            }
            optionDisplay();
            break;


        default:
            cout<<"\"Type again correcty\""<<endl;
            optionDisplay();
        }

    }

    return 0;
}
