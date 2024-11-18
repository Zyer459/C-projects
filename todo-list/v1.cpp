#include <iostream>
#include <windows.h>
#include<unistd.h>
#include<cstdlib>
#include<vector>
using namespace std;
void create_task ();
void insert_task ();
void delete_task ();
void update_task ();
void view_tasks ();
void timer (string name);
int counter (struct node *temp);
int menu ();
struct node *head, *temp, *newNode, *pre;
string user;
int option;
int count;

struct node{
    //int data;
    //vector <char> task, status, priority;
    char task[30], status[30], priority[30];
    //string task, priority, status;
    struct node *next;
};

int main ()
{
    cout << "starting program";
    for (int i = 0; i < 10; i++)
    {
        cout << ".";
        Sleep(400);
    }
    cout << endl;
    head = temp = NULL;
    do
    {
        option = menu ();
        if (option < 0 || option > 5)
        {
            cout << "input not recognized" << endl;
            break;
        }

        switch (option)
        {
        case 1:
            create_task ();
            break;
        case 2:
            insert_task ();
            break;
        case 3:
            delete_task ();
            break;
        case 4:
            update_task ();
            break;
        case 5:
            view_tasks ();
            break;
        case 0:
            //create_task ();
            break;
        
        default:
            cout << "error" << endl;
        }
        cout << "goto menu? (yes/no): ";
        cin >> user;
    } while (user == "yes");
    cout << "self-destructing in 10 seconds";
    for (int i = 0; i < 10; i++)
    {
        cout << ".";
        Sleep(1000);
    }
    cout << "BOOM!!!! LOL!" << endl;
    return 0;
}

int menu (void)
{
    int x;
    cout << "Hello user" << endl << "what would you like to do today?" << endl;
    cout << "1.Create task" << endl << "2.Insert task" << endl << "3.Delete task" << endl << "4.Update task" << endl << "5.View tasks" << endl << "0.exit" << endl;
    cout << "please enter the corresponding number to execute an action: ";
    cin >> x;
    return x;
}

void timer (string name)
{
    cout << name << " task";
    for (int e = 0; e < 10; e++)
    {
        cout << '.';
        Sleep(325);
    }
    cout << "done!" << endl;
}

int counter (struct node *temp)
{
    int c = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    return c;
}

void create_task ()
{
    head = NULL;
    do
    {
        newNode = (struct node*)malloc(sizeof (struct node));
        newNode -> next = NULL;
        cout << "task name: ";
        cin >> newNode->task;
        //scanf ("%s", &newNode->task);
        //cin.ignore();
        //getline(cin, newNode->task);
        cout << "priority: ";
        cin >> newNode->priority;
        //scanf ("%s", &newNode->priority);
        //cin.ignore();
        //getline(cin, newNode->priority);
        //newNode -> status = "incomplete";
        /*cout << "data : ";
        cin >> newNode->data;*/
        
        if (head == NULL)
        temp = head = newNode;
        else
        {
            if (temp == NULL)
            {
                temp = head;
                while (temp -> next != NULL)
                {
                    temp = temp -> next;
                }
            }
            temp -> next = newNode;
            temp = newNode;
        }
        timer ("creating");
        cout << "create new task (yes/no) ? : ";
        cin >> user;
    } while (user == "yes");
}

void insert_task ()
{
    int pos;
    temp = head;
    do
    {
        cout << "insert new task at position: ";
        cin >> pos;
        //count = counter (temp);
        if (pos > counter(temp))
        break;

        else if (pos == 1)
        {
            temp = head;
            newNode = (struct node*)malloc(sizeof (struct node));
            //newNode -> status = "incomplete";
            cout << "task name: ";
            cin >> newNode -> task;
            cout << "priority: ";
            cin >> newNode -> priority;

            head = newNode;
            head -> next = temp;
        }
        else
        {
            temp = head;
            for (int i = 0; i < pos; i++)
            {
                pre = temp;
                temp = temp -> next;
            }
            newNode = (struct node*)malloc(sizeof (struct node));
            //newNode -> status = "incomplete";
            cout << "task name: ";
            cin >> newNode -> task;
            cout << "priority: ";
            cin >> newNode -> priority;
            newNode -> next = temp;
            pre -> next = newNode;
        }
        timer("inserting");
        cout << "insert another task? : ";
        cin >> user;
    } while (user == "yes");
}

void delete_task ()
{
    int pos;
    temp = head;
    do
    {
        cout << "delete task from position: ";
        cin >> pos;
        if (pos > counter(temp))
        break;

        else if (pos == 1)
        {
            //temp = head;
            head = head -> next;//head = null
            free(temp);
        }
        else
        {
            //temp = head;
            for (int i = 0; i < pos; i++)
            {
                pre = temp;
                temp = temp -> next;
            }
            pre -> next = temp -> next;
            free(temp);
        }
        timer("deleting");
        cout << "delete another task? : ";
        cin >> user;
    } while (user == "yes");
}

void update_task ()
{
    int pos;
    string input;
    temp = head;
    do
    {
        cout << "update task at position: ";
        cin >> pos;
        if (pos > counter(temp))
        break;

        cout << "update task name, status, priority or all? (name/status/priority/all) : ";
        cin >> input;
        if (pos == 1)
        {
                if (input == "name")
            {
                for (int i = 0; i < pos; i++)
                {
                    temp = temp -> next;
                }
                cout << "new task name : ";
                cin >> temp -> task;
                timer("updating");
            }
            else if (input == "status")
            {
                for (int i = 0; i < pos; i++)
                {
                    temp = temp -> next;
                }
                cout << "new task status : ";
                cin >> temp -> status;
                timer("updating");
            }
            else if (input == "priority")
            {
                for (int i = 0; i < pos; i++)
                {
                    temp = temp -> next;
                }
                cout << "new task priority : ";
                cin >> temp -> priority;
                timer("updating");
            }
            else if (input == "all")
            {
                for (int i = 0; i < pos; i++)
                {
                    temp = temp -> next;
                }
                cout << "new task name : ";
                cin >> temp -> task;
                cout << "new task status : ";
                cin >> temp -> status;
                cout << "new task priority : ";
                cin >> temp -> priority;
                timer("updating");
            }
            else
            cout << "input not recognized" << endl;
        }
        else
        {
            if (input == "name")
            {
                for (int i = 0; i < pos; i++)
                {
                    temp = temp -> next;
                }
                cout << "new task name : ";
                cin >> temp -> task;
                timer("updating");
            }
            else if (input == "status")
            {
                for (int i = 0; i < pos; i++)
                {
                    temp = temp -> next;
                }
                cout << "new task status : ";
                cin >> temp -> status;
                timer("updating");
            }
            else if (input == "priority")
            {
                for (int i = 0; i < pos; i++)
                {
                    temp = temp -> next;
                }
                cout << "new task priority : ";
                cin >> temp -> priority;
                timer("updating");
            }
            else if (input == "all")
            {
                for (int i = 0; i < pos; i++)
                {
                    temp = temp -> next;
                }
                cout << "new task name : ";
                cin >> temp -> task;
                cout << "new task status : ";
                cin >> temp -> status;
                cout << "new task priority : ";
                cin >> temp -> priority;
                timer("updating");
            }
            else
            cout << "input not recognized" << endl;
        }
    } while (user == "yes");
}

void view_tasks ()
{
    //cout << "fetching data";
    timer("fetching");
    temp = head;
    while (temp != NULL)
    {
        //printf ("task name: %s", temp->task);
        //printf ("task name: %s", temp->priority);
        //printf ("task name: %s", temp->status);
        cout << "task name: " << temp -> task << endl;
        cout << "task priority: " << temp -> priority << endl;
        cout << "task status: " << temp -> status << endl;
        //cout << "data: " << temp -> data << endl;
        temp = temp ->next;
        cout << temp << endl;
        cout << "-------------------------------------------------------" << endl;
        //later add function to check remaining tasks
    }
}