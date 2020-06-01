#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include <string.h>
#include <unistd.h>

class Person
{
protected:
    char* Name;
    int size;
    int Age;
    char Gender;
public:
    Person()
    {
        Name=nullptr;
        size=0;
        Age=0;
        Gender='n';
    }
    Person(char name[], int a, char g)
    {
        size=strlen(name)+1;
        Name=new char[size];
        strcpy(Name,name);
        Age=a;
        Gender=g;
    }
    virtual ~Person()
    {
        if(Name!= nullptr)
            delete[] Name;
        Name=nullptr;
    }
    virtual void print()
    {
        if(Name== nullptr)
            cout<<"No infromation available\n";
        else
        {
            cout << "Name: " << Name;
            cout<<"\nAge: "<<Age<<endl;
            cout<<"Gender: ";
            if(Gender=='f')
                cout<<"Female\n";
            else
                cout<<"Male\n";
        }
    }
    Person& operator=(Person& p)
    {
        if(Name!=nullptr)
            delete[] Name;
        size=p.size;
        Name=new char[size];
        strcpy(Name,p.Name);

        Age=p.Age;
        Gender=p.Gender;

        return *this;
    }
    friend void testFunction();
};
class Adult :public Person
{
    char* Occupation;
    char* Qualification;
    char* NIC;
public:
    Adult() :Person()
    {
        Occupation=nullptr;
        Qualification=nullptr;
        NIC=nullptr;
    }
    Adult(char name[], int a, char g, char occ[],char qual[], char nic[]): Person(name,a,g)
    {
        Occupation=new char[strlen(occ)+1];
        strcpy(Occupation,occ);

        Qualification=new char[strlen(qual)+1];
        strcpy(Qualification,qual);

        NIC=new char[strlen(nic)+1];
        strcpy(NIC,nic);
    }
    ~Adult()
    {
        if(Occupation!= nullptr)
        {
            delete[] Occupation;
            delete[] Qualification;
            delete[] NIC;
        }
        Occupation=nullptr;
        Qualification=nullptr;
        NIC=nullptr;
    }
    void print()
    {
        Person::print();
        cout<<"Occupation: "<<Occupation;
        cout<<"\nQualification: "<<Qualification;
        cout<<"\nNIC: "<<NIC<<endl;
    }
    Adult& operator=(Adult& a)
    {
        if(Name!=nullptr)
            delete[] Name;
        size=a.size;
        Name=new char[size];
        strcpy(Name,a.Name);

        Age=a.Age;
        Gender=a.Gender;

        if(Occupation!=nullptr)
            delete[] Occupation;
        Occupation=new char[strlen(a.Occupation)+1];
        strcpy(Occupation,a.Occupation);

        if(Qualification!=nullptr)
            delete[] Qualification;
        Qualification=new char[strlen(a.Qualification)+1];
        strcpy(Qualification,a.Qualification);

        if(NIC!=nullptr)
            delete[] NIC;
        NIC=new char[strlen(a.NIC)+1];
        strcpy(NIC,a.NIC);

        return *this;
    }
    friend istream& operator>>(istream& in, Adult& a)
    {
        char arr[100];
        cout<<"Please input the Name of your Adult: ";
        in.ignore(100,'\n');
        in.getline(arr,99,'\n');

        if(a.Name!=nullptr)
            delete[] a.Name;
        a.size=strlen(arr)+1;
        a.Name=new char[a.size];
        strcpy(a.Name,arr);

        cout<<"PLease enter the Age of your Adult: ";
        in>>a.Age;
        while(a.Age<0)
        {
            cout<<"Invalid input, enter again: ";
            in>>a.Age;
        }
        cout<<"Please enter 'f' if your Adult is Female or 'm' if your Adult is Male: ";
        in>>a.Gender;
        while(a.Gender!='f' && a.Gender!='m')
        {
            cout<<"Invalid input, enter again: ";
            in>>a.Gender;
        }

        cout<<"Please input the Occupation of your Adult: ";
        in.ignore(100,'\n');
        in.getline(arr,99,'\n');

        if(a.Occupation!=nullptr)
            delete[] a.Occupation;
        a.Occupation=new char[strlen(arr)+1];
        strcpy(a.Occupation,arr);

        cout<<"Please input the Qualification of your Adult: ";
        in.getline(arr,99,'\n');
        if(a.Qualification!=nullptr)
            delete[] a.Qualification;
        a.Qualification=new char[strlen(arr)+1];
        strcpy(a.Qualification,arr);

        cout<<"Please input the NIC of your Adult: ";
        in.getline(arr,99,'\n');
        if(a.NIC!=nullptr)
            delete[] a.NIC;
        a.NIC=new char[strlen(arr)+1];
        strcpy(a.NIC,arr);

        return in;
    }
    friend void testFunction();
};
class kid :public Person
{
    char* B_form_number;
public:
    kid() :Person()
    {
        B_form_number=nullptr;
    }
    kid(char name[], int a, char g, char bform[]): Person(name,a,g)
    {
        B_form_number=new char(strlen(bform)+1);
        strcpy(B_form_number,bform);
    }
    ~kid()
    {
        if(B_form_number!= nullptr)
            delete[] B_form_number;
        B_form_number=nullptr;
    }
    void print()
    {
        Person::print();
        cout<<"B-form Number: "<<B_form_number<<endl;
    }
    kid& operator=(kid& k)
    {
        if(Name!=nullptr)
            delete[] Name;
        size=k.size;
        Name=new char[size];
        strcpy(Name,k.Name);

        Age=k.Age;
        Gender=k.Gender;

        if(B_form_number!=nullptr)
            delete[] B_form_number;
        B_form_number=new char[strlen(k.B_form_number)+1];
        strcpy(B_form_number,k.B_form_number);

        return *this;
    }
    friend istream& operator>>(istream& in, kid& k)
    {
        char arr[100];
        cout<<"Please input the Name of your Kid: ";
        in.ignore(100,'\n');
        in.getline(arr,99,'\n');

        if(k.Name!=nullptr)
            delete[] k.Name;
        k.size=strlen(arr)+1;
        k.Name=new char[k.size];
        strcpy(k.Name,arr);

        cout<<"PLease enter the Age of your Kid: ";
        in>>k.Age;
        while(k.Age<0)
        {
            cout<<"Invalid input, enter again: ";
            in>>k.Age;
        }
        cout<<"Please enter 'f' if your Kid is Female or 'm' if your Kid is Male: ";
        in>>k.Gender;
        while(k.Gender!='f' && k.Gender!='m')
        {
            cout<<"Invalid input, enter again: ";
            in>>k.Gender;
        }

        cout<<"Please input the B-Form Number of your Kid: ";
        in.ignore(100,'\n');
        in.getline(arr,99,'\n');

        if(k.B_form_number!=nullptr)
            delete[] k.B_form_number;
        k.B_form_number=new char[strlen(arr)+1];
        strcpy(k.B_form_number,arr);

        return in;
    }
    friend void testFunction();
};
class Family
{
    Adult* Adults;
    int a;
    kid* kids;
    int k;
    char* familyName;
public:
    Family()
    {
        Adults=nullptr;
        kids=nullptr;
        a=0;
        k=0;
        familyName= nullptr;
    }
    Family(Adult adults[],int a, kid kids[], int k, char name[])
    {
        this->a=a;
        this->k=k;
        Adults=new Adult[a];
        for(int i=0;i<a;i++)
        {
            Adults[i]=adults[i];
        }

        this->kids=new kid[k];
        for(int i=0;i<k;i++)
        {
            this->kids[i]=kids[i];
        }

        familyName=new char[strlen(name)+1];
        strcpy(familyName,name);
    }
    ~Family()
    {
        if(Adults!= nullptr)
            delete[] Adults;
        Adults=nullptr;
        if(kids!= nullptr)
            delete[] kids;
        kids=nullptr;
        if(familyName!= nullptr)
            delete[] familyName;
        familyName=nullptr;
    }
    void print()
    {
        cout<<"Family Name: "<<familyName<<endl;
        for(int i=0;i<a;i++)
        {
            cout<<"Adult number "<<i+1<<": "<<endl;
            Adults[i].print();
        }
        if(a==0)
            cout<<"There are no Adults in this Family.\n";
        for(int i=0;i<k;i++)
        {
            cout<<"Kid number "<<i+1<<": "<<endl;
            kids[i].print();
        }
        if(k==0)
            cout<<"There are no Kids in this Family.\n";
    }
    friend istream& operator>>(istream& in, Family& fam)
    {
        char name[100];
        cout<<"Please input your Family name: ";
        in.ignore(100,'\n');
        in.getline(name,99,'\n');
        if(fam.familyName!=nullptr)
            delete[] fam.familyName;
        fam.familyName=new char[strlen(name)+1];
        strcpy(fam.familyName,name);

        int num;
        cout<<"Enter the number of Adults in the family: ";
        in>>num;
        while(num>4 || num<0)
        {
            cout<<"The Adults can only be between 0 to 4, please enter again: ";
            in>>num;
        }
        fam.a=num;
        if(fam.Adults!= nullptr)
            delete[] fam.Adults;
        fam.Adults=new Adult[num];
        for(int i=0;i<num;i++)
        {
            cout<<"Please enter the data for Adult number "<<i+1<<" :\n";
            in>>fam.Adults[i];
        }


        cout<<"Enter the number of Kids in the family: ";
        in>>num;
        while(num>6 || num<0)
        {
            cout<<"The Kids can only be between 0 to 6, please enter again: ";
            in>>num;
        }
        fam.k=num;
        if(fam.kids!= nullptr)
            delete[] fam.kids;
        fam.kids=new kid[num];
        for(int i=0;i<num;i++)
        {
            cout<<"Please enter the data for Kid number "<<i+1<<" :\n";
            in>>fam.kids[i];
        }

        return in;

    }
    Family& operator=(Family& fam)
    {
        if(familyName!= nullptr)
            delete[] familyName;
        familyName=nullptr;
        if(fam.familyName!=nullptr)
        {
            familyName = new char[strlen(fam.familyName)+1];
            strcpy(familyName, fam.familyName);
        }

        if(Adults!= nullptr)
            delete[] Adults;
        Adults=nullptr;
        this->a=fam.a;
        if(fam.Adults!=nullptr)
        {
            Adults = new Adult[a];
            for (int i = 0; i < a; i++)
            {
                Adults[i] = fam.Adults[i];
            }
        }


        if(kids!=nullptr)
            delete[] kids;
        kids=nullptr;
        this->k=fam.k;
        if(fam.kids!= nullptr)
        {
            kids = new kid[k];
            for (int i = 0; i < k; i++)
            {
                this->kids[i] = fam.kids[i];
            }
        }
        return *this;
    }
    friend void testFunction();
};
class Bogie
{
    Bogie *next;
    Family *family;
public:
    int Bogie_ID;
    Bogie()
    {
        Bogie_ID=-1;
        next=nullptr;
        family=nullptr;
    }
    Bogie(int id)
    {
        Bogie_ID=id;
        next=nullptr;
        family=nullptr;
    }
    Bogie(int id,Bogie& next,Family& fam)
    {
        Bogie_ID=id;
        this->next=new Bogie[1];
        this->next[0]=next;
        family=new Family[1];
        family[0]=fam;
    }
    Bogie(const Bogie& b)
    {
        Bogie_ID=b.Bogie_ID;
        next=b.next;
        if(b.family!= nullptr)
        {
            family = new Family[1];
            family[0] = b.family[0];
        }
        else
            family=nullptr;
    }
    bool AddPassengers(Family& fam) // should add adults and kids information etc
    {
        if(family!=nullptr)
            delete[] family;
        family=new Family[1];
        family[0]=fam;
    }
    void Print()
    {
        cout<<"Bogie ID: "<<Bogie_ID<<endl;
        if(next== nullptr)
            cout<<"This is the last Bogie.\n";
        else
            cout<<"Next Bogie's ID: "<<next->Bogie_ID<<endl;

        if(family== nullptr)
            cout<<"This bogie has not ben reserved by anyone.\n";
        else
        {
            cout<<"Family in the Bogie:\n";
            family[0].print();
        }
    }
    void setNext(Bogie& n)
    {
        next=new Bogie[1];
        next[0]=n;

    }
    void setNextNull()
    {
        next=nullptr;
    }
    ~Bogie()
    {
        if(next!=nullptr)
            delete[] next;
        next=nullptr;
        if(family!=nullptr)
            delete[] family;
        family=nullptr;
    }
    Bogie& operator=(Bogie& b)
    {
        Bogie_ID=b.Bogie_ID;
        if(next!=nullptr)
            delete next;
        next=nullptr;
        if(b.next!=nullptr)
            next=b.next;
        if(family!=nullptr)
            delete[] family;
        family=nullptr;
        if(b.family!=nullptr)
        {
            family = new Family[1];

            family[0] = b.family[0];
        }
        return *this;
    }
    bool isAvailable()
    {
        if(family== nullptr)
            return true;
        return false;
    }
    friend void testFunction();
};
class train
{
    Bogie * engine;
    Bogie* bogies;
    int number;
public:
    train()
    {
        engine = nullptr;
        bogies= nullptr;
        number=0;
    }
    train(Bogie en)
    {
        engine=new Bogie[1];
        engine[0]=en;
        bogies=nullptr;
        number=0;
    }
    train(Bogie en, Bogie array[], int num)
    {
        engine=new Bogie[1];
        engine[0]=en;
        number=num;
        bogies=new Bogie[number];
        for(int i=0;i<number;i++)
        {
            bogies[i]=array[i];
        }
    }
    void fixReferences()
    {
        engine->setNext(bogies[0]);
        for(int i=0;i<number-1;i++)
        {
            bogies[i].setNext(bogies[i+1]);
        }
        bogies[number-1].setNextNull();
    }
    void addBogie(Bogie& b)
    {
        if(bogies==nullptr)
        {
            number=1;
            bogies=new Bogie[number];
            bogies[0]=b;
            engine->setNext(bogies[0]);
        }
        else
        {
            Bogie temp[number+1];
            for(int i=0;i<number;i++)
                temp[i]=bogies[i];
            temp[number]=b;
            number++;
            delete[] bogies;
            bogies=new Bogie[number];
            for(int i=0;i<number;i++)
                bogies[i]=temp[i];

            this->fixReferences();

        }
    }
    bool removeBogie(int id)//search the bogie and delete it
    {
        int index=-1;
        for(int i=0;i<number;i++)
        {
            if(bogies[i].Bogie_ID==id)
                index=i;
        }
        if(index==-1)
            return false;
        if(number!=1)
        {
            Bogie temp[--number];
            int j = 0;
            for (int i = 0; i < number; i++, j++) {
                if (j == index)
                    j++;
                temp[i] = bogies[j];
            }
            delete[] bogies;
            bogies = new Bogie[number];
            for (int i = 0; i < number; i++)
                bogies[i] = temp[i];

            this->fixReferences();
        }
        else
        {
            number--;
            delete[] bogies;
            bogies=NULL;
            engine->setNextNull();
        }

        return true;
    }
    void printTrain() //print only the Bogie_ID of all bogies
    {
        if(engine== nullptr)
            cout<<"The train does not have any Engine or Bogie.\n";
        else
        {
            cout<<"ENGINE:\n";
            engine->Print();
            if(bogies== nullptr)
                cout<<"No Bogies have yet been added to the train.\n";
            else
            {
                for(int i=0;i<number;i++)
                {
                    cout<<"ID of Bogie Number "<<i+1<<": "<<bogies[i].Bogie_ID<<endl;
                }
            }
        }
    }
    int SearchBogie(int ID)//search the particular bogie
    {
        int index=-1;
        if(engine->Bogie_ID==ID)
            return index;
        for(int i=0;i<number;i++)
        {
            if(bogies[i].Bogie_ID==ID)
                index=i;
        }
        if(index==-1)
            return 0;
        else
            return index+1;
    }
    void setEngine(Bogie en)
    {
        engine=&en;
    }
    bool printAvailable()
    {
        if(bogies==nullptr)
            return false;
        else
        {
            int check=0;
            for(int i=0;i<number;i++)
            {
                if(bogies[i].isAvailable())
                {
                    cout << bogies[i].Bogie_ID << endl;
                    check=1;
                }
            }
            if(check==0)
                return false;
            return true;
        }
    }
    bool hasAvailable()
    {
        if(bogies==nullptr)
            return false;
        else
        {
            int check = 0;
            for (int i = 0; i < number; i++)
            {
                if (bogies[i].isAvailable())
                    check = 1;
            }
            if (check == 0)
                return false;
            return true;
        }
    }
    bool isAvailable(int id)
    {
        for(int i=0;i<number;i++)
        {
            if(bogies[i].Bogie_ID==id && bogies[i].isAvailable())
            {
                return true;
            }
        }
        return false;
    }
    void addPassengers(int id, Family& fam)
    {
        for(int i=0;i<number;i++)
        {
            if(bogies[i].Bogie_ID==id)
                bogies[i].AddPassengers(fam);
        }
    }
    void printBogie(int index)
    {
        if(index==-1)
            engine->Print();
        else
            bogies[index-1].Print();
    }
    ~train()
    {
        if(engine!=nullptr)
            delete[]  engine;
        engine=nullptr;
        if(bogies!= nullptr)
            delete[] bogies;
        bogies=nullptr;
    }
};

void deleteID(int *arr, int& size , int id)
{
    int index=-1;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==id)
            index=i;
    }
    int *temp=new int[--size];
    int j=0;
    for(int i=0;i<size;i++,j++)
    {
        if(j==index)
            j++;
        temp[i]=arr[j];
    }
    delete[] arr;
    arr=new int[size];
    for(int i=0;i<size;i++)
        arr[i]=temp[i];
    delete[] temp;
    temp=nullptr;
}
void addID(int *arr, int& size , int id)
{
    int *temp=new int[size+1];
    for(int i=0;i<size;i++)
    {
        temp[i]=arr[i];
    }
    temp[size]=id;
    size++;
    delete[] arr;
    arr=new int[size];
    for(int i=0;i<size;i++)
        arr[i]=temp[i];
    delete[] temp;
    temp= nullptr;
}
bool checkID(int *arr, int size , int id)
{
    for(int i=0;i<size;i++)
    {
        if (arr[i] == id)
            return true;
    }
    return false;

}


class Button
{
    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;
    int x;
    int y;
    int width;
    int height;
    sf::Color color;
    public:
    Button(float x, float y, float width, float height,sf::Font* font,std::string text,sf::Color color)
    {
        this->x=x;
        this->y=y;
        this->width=width;
        this->height=height;
        this->shape.setPosition(sf::Vector2f(x,y));
        this->shape.setSize(sf::Vector2f(width,height));
        this->font=font;
        this->text.setFont(*this->font);
        this->text.setString(text);
        this->text.setFillColor(sf::Color::Black);
        this->text.setCharacterSize(16);
        this->text.setPosition(x+5,y+5);

        this->shape.setFillColor(color);
    }
    void render(sf::RenderWindow& win)
    {
        win.draw(this->shape);
        win.draw(this->text);
    }
    bool isPressed(sf::Vector2i mousePosition)
    {
        if(mousePosition.x<x+width && mousePosition.x>x && mousePosition.y<y+height && mousePosition.y>y)
            return true;
        return false;
    }
};

int main()
{

    sf::RenderWindow window(sf::VideoMode(1125, 562.5), "TRAIN STATION APP",sf::Style::Close);

    sf::RectangleShape background(sf::Vector2f(1125.0f,562.5f));
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.jpg");
    background.setTexture(&backgroundTexture);

    sf::Font buttonFont;
    buttonFont.loadFromFile("Raleway-Medium.ttf");

    Button addButton(950,300,120,30,&buttonFont,"Add Bogie",sf::Color(255,255,255,180));
    Button deleteButton(950,340,120,30,&buttonFont,"Delete Bogie",sf::Color(255,255,255,180));
    Button reserveButton(950,380,120,30,&buttonFont,"Reserve Bogie",sf::Color(255,255,255,180));
    Button findButton(950,420,120,30,&buttonFont,"Find Bogie",sf::Color(255,255,255,180));
    Button printButton(950,460,120,30,&buttonFont,"Print Train",sf::Color(255,255,255,180));
    Button quitButton(950,500,120,30,&buttonFont,"Quit",sf::Color(255,255,255,180));

    sf::Font titleFont;
    titleFont.loadFromFile("PlayfairDisplay-Bold.otf");

    sf::Text Heading1;
    Heading1.setString("WELCOME TO PLATFORM  9 3/4");
    Heading1.setFont(titleFont);
    Heading1.setCharacterSize(40);
    Heading1.setFillColor(sf::Color(255,255,255,255));
    Heading1.setOutlineColor(sf::Color::Black);
    Heading1.setPosition(75,40);

    sf::Text Heading2;
    Heading2.setString("THIS IS YOUR HOGWARTS EXPRESS!!");
    Heading2.setFont(titleFont);
    Heading2.setCharacterSize(20);
    Heading2.setFillColor(sf::Color(255,255,255,255));
    Heading2.setOutlineColor(sf::Color::Black);
    Heading2.setPosition(180,100);

    sf::Text Heading3;
    Heading3.setString("Please select one \nof the following \noptions to proceed:");
    Heading3.setFont(titleFont);
    Heading3.setCharacterSize(16);
    Heading3.setFillColor(sf::Color(255,255,255,255));
    Heading3.setPosition(935,230);


    sf::RectangleShape messageBox;
    messageBox.setSize(sf::Vector2f (400,210));
    messageBox.setPosition(sf::Vector2f (300,320));
    messageBox.setFillColor(sf::Color(255,255,255,150));

    sf::Text message;
    message.setFont(buttonFont);
    message.setCharacterSize(15);
    message.setFillColor(sf::Color::Black);
    message.setPosition(310,330);

    string s="PLEASE INPUT THE ID OF YOUR ENGINE IN CONSOLE TO LAUNCH YOUR TRAIN STATION APP.";
    sf::Text firstPrompt;
    firstPrompt.setString(s);
    firstPrompt.setFont(titleFont);
    firstPrompt.setCharacterSize(20);
    firstPrompt.setFillColor(sf::Color::White);
    firstPrompt.setPosition(100,250);
    window.clear();
    window.draw(firstPrompt);
    window.display();


    int *arrayOfIDs;
    int arraySize=0;
    int ID;
    cout<<"The engine for your Hogwarts Express has been created\nPlease input the ID for your engine:";
    cin>>ID;
    Bogie engineTemp(ID);
    train HogwartsExpress(engineTemp);
    cout<<"The ID "<<ID<<" has been assigned to your train engine.\n";

    arraySize++;
    arrayOfIDs=new int[arraySize];
    arrayOfIDs[0]=ID;


    while (window.isOpen())
    {

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if(quitButton.isPressed(mousePosition))
                window.close();
            else if(addButton.isPressed(mousePosition))
            {
                window.draw(messageBox);
                string stringMessage="\nPlease proceed to the console window\n to input info of the bogie you want \nto add to Hogwarts express:";
                message.setString(stringMessage);
                window.draw(message);
                window.display();

                int id;
                cout<<"Please enter the ID for your new bogie: ";
                cin>>id;
                while(checkID(arrayOfIDs,arraySize,id))
                {
                    cout<<"The bogie of this ID already exists, please input again: ";
                    cin>>id;
                }
                Bogie temp(id);
                HogwartsExpress.addBogie(temp);
                addID(arrayOfIDs,arraySize,id);
                cout<<"\nINPUT COMPLETE PROCEED TO THE GUI WINDOW.\n\n";

                window.clear();
                window.draw(background);

                window.draw(Heading1);
                window.draw(Heading2);
                window.draw(Heading3);

                addButton.render(window);
                deleteButton.render(window);
                reserveButton.render(window);
                findButton.render(window);
                printButton.render(window);
                quitButton.render(window);

                window.draw(messageBox);
                stringMessage="\nYour Bogie has successfully been added \nto the end of Hogwarts Express.\n";
                message.setString(stringMessage);
                window.draw(message);

                window.display();
                sleep(6);
            }
            else if(deleteButton.isPressed(mousePosition))
            {
                window.draw(messageBox);
                string stringMessage="\nPlease proceed to the console window\n to input ID of the bogie you want \nto delete from Hogwarts express:";
                message.setString(stringMessage);
                window.draw(message);
                window.display();


                int id;
                cout<<"Please enter the ID of the bogie you want to delete: ";
                cin>>id;
                if(!HogwartsExpress.SearchBogie(id) && HogwartsExpress.SearchBogie(id)!=-1)
                    stringMessage="\nThe bogie of your entered ID does not exist.\n";
                else if(HogwartsExpress.SearchBogie(id)==-1)
                    stringMessage="\nThe engine of the Hogwarts Express can not be deleted.\n";
                else
                {
                    bool temp=HogwartsExpress.removeBogie(id);
                    deleteID(arrayOfIDs,arraySize,id);
                    stringMessage="\nYour Bogie has successfully been deleted \nfrom Hogwarts Express.\n";
                }
                cout<<"\nINPUT COMPLETE PROCEED TO THE GUI WINDOW.\n\n";

                window.clear();
                window.draw(background);

                window.draw(Heading1);
                window.draw(Heading2);
                window.draw(Heading3);

                addButton.render(window);
                deleteButton.render(window);
                reserveButton.render(window);
                findButton.render(window);
                printButton.render(window);
                quitButton.render(window);

                window.draw(messageBox);
                message.setString(stringMessage);
                window.draw(message);

                window.display();
                sleep(6);
            }
            else if(reserveButton.isPressed(mousePosition))
            {
                string stringMessage;
                if(!HogwartsExpress.hasAvailable())
                    stringMessage = "\nNo bogies are available for reservation.\n";
                else
                {
                    window.draw(messageBox);
                    stringMessage="\nPlease proceed to the console window\n to input info of the\n bogie you want to reserve in Hogwarts express:";
                    message.setString(stringMessage);
                    window.draw(message);
                    window.display();
                    int id;
                    cout << "The following bogies are available for reservation:\n";
                    HogwartsExpress.printAvailable();
                    cout<<"Please choose an ID: ";
                    cin>>id;
                    if(HogwartsExpress.isAvailable(id))
                    {
                        Family temp;
                        cin>>temp;
                        HogwartsExpress.addPassengers(id,temp);
                        stringMessage ="\nYour Bogie has been successfully reserved.\n";
                    }
                    else
                    {
                        stringMessage ="\nNo such Bogie exists.\n";
                    }
                    cout<<"\nINPUT COMPLETE PROCEED TO THE GUI WINDOW.\n\n";
                }
                window.clear();
                window.draw(background);

                window.draw(Heading1);
                window.draw(Heading2);
                window.draw(Heading3);

                addButton.render(window);
                deleteButton.render(window);
                reserveButton.render(window);
                findButton.render(window);
                printButton.render(window);
                quitButton.render(window);

                window.draw(messageBox);
                message.setString(stringMessage);
                window.draw(message);

                window.display();
                sleep(6);
            }
            else if(findButton.isPressed(mousePosition))
            {
                window.draw(messageBox);
                string stringMessage="\nPlease proceed to the console window\n to input ID of the bogie you want \nto find in Hogwarts express:";
                message.setString(stringMessage);
                window.draw(message);
                window.display();

                int id;
                cout<<"Enter the ID of the bogie you wish to find: ";
                cin>>id;
                if(!HogwartsExpress.SearchBogie(id) && HogwartsExpress.SearchBogie(id)!=-1)
                {
                    cout<<"\nThe bogie of ID "<<id<<" does not exist.\n";
                }
                else if(HogwartsExpress.SearchBogie(id)==-1)
                {

                    cout << "\nYour bogie of ID " << id << " is the engine.\nBOGIE INFO:\n";
                    HogwartsExpress.printBogie(-1);
                }
                else
                {
                    cout<<"\nThe bogie of ID "<<id<<" has successfully been found at position number "<<HogwartsExpress.SearchBogie(id)<<endl<<"BOGIE INFO:\n";
                    HogwartsExpress.printBogie(HogwartsExpress.SearchBogie(id));
                }
                cout<<"\nINPUT COMPLETE PROCEED TO THE GUI WINDOW.\n\n";

                window.clear();
                window.draw(background);

                window.draw(Heading1);
                window.draw(Heading2);
                window.draw(Heading3);

                addButton.render(window);
                deleteButton.render(window);
                reserveButton.render(window);
                findButton.render(window);
                printButton.render(window);
                quitButton.render(window);

                window.draw(messageBox);
                stringMessage="\nYour Bogie has successfully been found \nin the end of the Hogwarts Express.\n";
                message.setString(stringMessage);
                window.draw(message);

                window.display();
                sleep(6);
            }
            else if(printButton.isPressed(mousePosition))
            {
                window.draw(messageBox);
                string stringMessage="\nPlease proceed to the console window\n to see the printed info of the\n Hogwarts express:";
                message.setString(stringMessage);
                window.draw(message);
                window.display();
                HogwartsExpress.printTrain();
                sleep(10);
            }
        }

        window.clear();

        window.draw(background);

        window.draw(Heading1);
        window.draw(Heading2);
        window.draw(Heading3);

        addButton.render(window);
        deleteButton.render(window);
        reserveButton.render(window);
        findButton.render(window);
        printButton.render(window);
        quitButton.render(window);

        window.display();
    }

    delete[] arrayOfIDs;
    arrayOfIDs=nullptr;
    return 0;
}
