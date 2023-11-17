#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class authenticate
{
    string username;
    string password;

public:
    authenticate()
    {
        this->username = "OPERATOR";
        this->password = "bus1234";
    }
    string ret_un()
    {
        return this->username;
    }
    string ret_pass()
    {
        return this->password;
    }
};

class bus
{
private:
    string bus_name;
    string source;
    string destination;
    double price;
    string time;
    int tickets;

public:
    // constructor for bus class.......
    bus(string bus_name = " ", string source = " ", string destination = " ",
        double price = 0, string time = " ", int tickets = 0)
    {
        this->bus_name = bus_name;
        this->destination = destination;
        this->source = source;
        this->time = time;
        this->price = price;
        this->tickets = tickets;
    }
    string ret_bus()
    {
        return bus_name;
    }
    string ret_source()
    {
        return source;
    }
    string ret_desti()
    {
        return destination;
    }
    double ret_price()
    {
        return price;
    }
    string ret_time()
    {
        return time;
    }
    int ret_tickets()
    {
        return tickets;
    }
    void set_bus_n(string bn)
    {
        bus_name = bn;
    }
    void set_sour(string sr)
    {
        source = sr;
    }
    void set_dest(string d)
    {
        destination = d;
    }
    void set_time(string t)
    {
        time = t;
    }
    void set_price(double d)
    {
        price = d;
    }
    void set_tickets(int tick)
    {
        tickets = tick;
    }
    void list_bus()
    {
        fstream f;
        f.open("bus.txt", ios::in);
        int count = 0;
        while (f >> bus_name >> source >> destination >> price >> time >> tickets)
        {
            cout << endl;
            count++;
            cout << "BUS " << count << endl;
            cout << "Bus Name: " << bus_name << endl;
            cout << "Boarding Point: " << source << endl;
            cout << "Destination: " << destination << endl;
            cout << "Price: " << price << endl;
            cout << "Date: " << time << endl;
            cout << "Available Tickets: " << tickets << endl;
            cout << endl;
        }
        f.close();
    }
    bool bus_by_source_and_destination(string src, string dest)
    {
        fstream f;
        f.open("bus.txt", ios::in);
        int count = 0;
        bool flag = false;
        while (f >> bus_name >> source >> destination >> price >> time >> tickets)
        {
            if (src == source and destination == dest)
            {
                flag = true;
                count++;
                cout << "BUS " << count << endl;
                cout << "Bus Name : " << bus_name << endl;
                cout << "Boarding Point : " << source << endl;
                cout << "Destination : " << destination << endl;
                cout << "Price : " << price << endl;
                cout << "Date : " << time << endl;
                cout << "Available Tickets: " << tickets << endl;
                cout << endl;
            }
        }
        f.close();
        if (flag == false)
        {
            return false;
        }
        return true;
    }
};

// !==================================================================================

class bus_operator : public bus
{
private:
    string bn, sou, dest, time;
    double pri;
    int tick;

public:
    void add_bus()
    {

        cout << "Enter the bus name" << endl;
        cin >> bn;
        cout << "Enter the Boarding Point" << endl;
        cin >> sou;
        cout << "Enter the Destination" << endl;
        cin >> dest;
        cout << "Enter the Date" << endl;
        cin >> time;
        cout << "Enter the price for a single ticket" << endl;
        cin >> pri;
        cout << "Enter the available tickets" << endl;
        cin >> tick;
        fstream f;
        f.open("bus.txt", ios::app | ios::out);

        f << " " << bn << " " << sou << " " << dest << " " << pri << " " << time << " " << tick << endl;
        f.close();
    }
    void delete_bus()
    {
        cout << "Enter the bus_name you want to delete" << endl;
        string k;
        cin >> k;
        fstream f1, f2;
        f1.open("bus.txt", ios::in);
        f2.open("bus1.txt", ios::app | ios::out);
        f1 >> bn >> sou >> dest >> pri >> time >> tick;
        while (!f1.eof())
        {
            if (bn != k)
            {
                f2 << bn << " " << sou << " " << dest << " " << pri << " " << time << " " << tick << endl;
            }
            f1 >> bn >> sou >> dest >> pri >> time >> tick;
        }
        f1.close();
        f2.close();
        remove("bus.txt");
        rename("bus1.txt", "bus.txt");
    }
    void list_tickets()
    {
        int pnr, age;
        double price;
        string name, mobile_no, email, src, dest, time, b_n;
        int count = 0;
        fstream f1;
        f1.open("ticket.txt", ios::in);
        while (f1 >> pnr >> name >> age >> mobile_no >> email >> b_n >> src >> dest >> price >> time)
        {
            count++;
            cout << "TICKET " << count << endl;
            cout << "PNR: " << pnr << endl;
            cout << "NAME: " << name << endl;
            cout << "AGE: " << age << endl;
            cout << "MOBILE NO: " << mobile_no << endl;
            cout << "EMAIL ID: " << email << endl;
            cout << "BUS NAME: " << b_n << endl;
            cout << "SOURCE: " << src << endl;
            cout << "DESTINATION: " << dest << endl;
            cout << "PRICE: " << price << endl;
            cout << "TIME: " << time << endl;
        }
        f1.close();
    }
};
// !==================================================================================

class USER : public bus
{
private:
    string name, email, source, destination;
    int age;
    string contactNo;

public:
    // constructor
    USER(string name = "NONE", string email = "NONE@gmail.com", int age = 0,
         string contactNo = "xxxxxxxxxx", string source = "NONE", string destination = "NONE")
    {
        this->name = name;
        this->email = email;
        this->age = age;
        this->contactNo = contactNo;
        this->source = source;
        this->destination = destination;
    }

    static int transactions;

    void getUserDetails()
    {
        cout << "\nName : " << this->name << endl;
    }
    string ret_name()
    {
        return name;
    }
    string ret_email()
    {
        return email;
    }
    int ret_age()
    {
        return age;
    }
    string ret_contactno()
    {
        return contactNo;
    }
};
int USER::transactions = 0;
// !==================================================================================
vector<USER> v;

class ticket : public USER
{
    int pnr;

public:
    ticket()
    {
        pnr = rand();
    }
    void print_ticket(string b_n)
    {
        system("cls");
        transactions++;

        USER u = v.front();
        string b, src, dest, time;
        int tick;
        double price;
        fstream f1, f2;
        f1.open("bus.txt", ios::in);
        f2.open("ticket.txt", ios::app | ios::out);
        while (f1 >> b >> src >> dest >> price >> time >> tick)
        {
            if (b == b_n)
            {
                cout << "YOUR TICKET IS BOOKED SUCCESSFULLY!\n"
                     << endl;
                cout << "PNR : " << pnr << endl;
                cout << "Name : " << u.ret_name() << endl;
                cout << "Age : " << u.ret_age() << endl;
                cout << "Contact No. : " << u.ret_contactno() << endl;
                cout << "Email : " << u.ret_email() << endl;
                cout << "Bus Name : " << b << endl;
                cout << "Boarding Point : " << src << endl;
                cout << "Destination : " << dest << endl;
                cout << "Price : " << price << endl;
                cout << "Boarding Time : " << time << endl;
                f2 << pnr << " " << u.ret_name() << " " << u.ret_age() << " " << u.ret_contactno() << " " << u.ret_email() << " " << b << " " << src << " "
                   << dest << " " << price << " " << time << endl;
            }
        }
        f1.close();
        f2.close();
    }
    void ticket_by_pnr(int p)
    {
        int pn, age;
        double price;
        string name, mobile_no, email, src, dest, time, b_n;
        fstream f1;
        bool stat = false;
        f1.open("ticket.txt", ios::in);
        while (f1 >> pn >> name >> age >> mobile_no >> email >> b_n >> src >> dest >> price >> time)
        {
            if (pn == p)
            {
                stat = true;
                cout << "PNR: " << pnr << endl;
                cout << "NAME: " << name << endl;
                cout << "AGE: " << age << endl;
                cout << "MOBILE NO: " << mobile_no << endl;
                cout << "EMAIL ID: " << email << endl;
                cout << "BUS NAME: " << b_n << endl;
                cout << "SOURCE: " << src << endl;
                cout << "DESTINATION: " << dest << endl;
                cout << "PRICE: " << price << endl;
                cout << "DATE: " << time << endl;
            }
        }
        if (stat == false)
        {
            cout << "\n\nTICKET NOT FOUND!!\n\n";
        }
        f1.close();
    }
};

// !==================================================================================
void MainMenu()
{
    cout << "- - - - - - - - - -  - - - - - - -  - - - - - - \n"
         << endl;
    cout << "Who Are you?? " << endl;
    cout << "1. Bus Operator \n2. Passenger\n";
    cout << endl;
    cout << "- - - - - - - - - -  - - - - - - -  - - - - - - \n"
         << endl;
}
void MainMenu2()
{
    system("cls");
    cout << "- - - - - - - - - -  - - - - - - -  - - - - - - \n"
         << endl;

    cout << "HOW CAN WE HELP YOU?\n"
         << endl;
    cout << "1. Enter 1 to book a ticket\n"
         << endl
         << "2. Enter 2 to know status of your ticket\n"
         << endl;

    cout << "- - - - - - - - - -  - - - - - - -  - - - - - - \n"
         << endl;
}

// !==================================================================================

bool isValidEmail(const string &email)
{
    const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
bool isValidContact(string s)
{
    const regex pattern("(0|91)?[6-9][0-9]{9}");
    if (regex_match(s, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ?==================================================================================
int main()
{
m:
    system("pause");
    system("cls");
    MainMenu();
    authenticate au;
    bus_operator bo;
    ticket t;
    bus b;

    int sel = 0;
    cin >> sel;
    if (sel == 1)
    {
        system("cls");
        // !Admin panel
        string username;
        string password;
        cout << "ENTER USERNAME: ";
        cin >> username;
        cout << "PASSWORD: ";
        cin >> password;
        if (au.ret_pass() == password && au.ret_un() == username)
        {
            system("cls");
            cout << "<-------- LOGGED IN AS ADMIN ------------> \n"
                 << endl;

            int choiceOp = 0;
            cout << "1. ADD A NEW BUS " << endl
                 << "2. DELETE AN EXISTING BUS" << endl
                 << "3. LIST OF ALL TRANSACTIONS" << endl
                 << "4. LIST OF ALL BUSES" << endl;

            cin >> choiceOp;

            if (choiceOp == 1)
            {
                system("cls");
                bo.add_bus();
            }
            else if (choiceOp == 2)
            {
                system("cls");
                bo.delete_bus();
            }
            else if (choiceOp == 3)
            {
                system("cls");
                cout << "NUMBER OF TICKETS BOOKED TODAY: " << t.transactions << endl
                     << endl;
                bo.list_tickets();
            }
            else if (choiceOp == 4)
            {
                system("cls");
                cout << "AVAILABLE BUSES :\n"
                     << endl;
                b.list_bus();
            }
        }
        else
        {
            cout << "USER NOT VERIFIED!" << endl;
        }
    }
    else if (sel == 2)
    {
        // !User details:
        string name, email, source, destination;
        int age;
        string contactNo;
        int PNR;
        int choice;
        string busName;
        MainMenu2();
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            cout << "ENTER USER DETAILS:\n"
                 << endl;
            cout << "Name : ";
            cin >> name;
            while (1)
            {
                cout << "Email : ";
                cin >> email;
                bool ans = isValidEmail(email);
                if (!ans)
                {
                    cout << "!! ENTER VALID EMAIL !!" << endl;
                }
                else
                {
                    break;
                }
            }

            cout << "Age : ";
            cin >> age;
            while (1)
            {
                cout << "Contact No. : ";
                cin >> contactNo;
                if (!isValidContact(contactNo))
                {
                    cout << "!! ENTER VALID PHONE NUMBER !!" << endl;
                }
                else
                {
                    break;
                }
            }
            cout << endl;
            cout << endl;
            cout << "!! USER REGISTERED SUCCESSFULLY !!\n"
                 << endl;
            system("pause");
            system("cls");
            cout << "ENTER BOARDING POINT : ";
            cin >> source;
            cout << "ENTER DESTINATION POINT : ";
            cin >> destination;
            // *User object
            USER user(name, email, age, contactNo, source, destination);
            system("cls");

            cout << "<------------- AVAILABLE BUSES -------------> : " << endl
                 << endl;
            bool available = user.bus_by_source_and_destination(source, destination);
            if (!available)
            {
                cout << "NO BUS FOUND FOR THE GIVEN ROUTE!\n"
                     << endl;
            }
            else
            {

                cout << "<============================================>\n"
                     << endl;
                cout << "PLEASE ENTER THE BUS NAME YOU WANT TO TRAVEL IN: " << endl;
                cin >> busName;
                v.push_back(user);
                t.print_ticket(busName);
            }
        }

        else if (choice == 2)
        {
            system("cls");

            cout << "Enter your PNR number: ";
            cin >> PNR;
            t.ticket_by_pnr(PNR);
        }

        else
        {
            cout << "Invalid Choice! Try Again." << endl;
        }
    }
    else
    {
        cout << "Enter a valid choice!!" << endl;
    }

    goto m;

    return 0;
}