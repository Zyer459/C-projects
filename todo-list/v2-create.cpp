#include <iostream>
#include <windows.h>
#include<unistd.h>
#include<cstdlib>
#include<vector>
using namespace std;
void create_task ();
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
        case 5:
            view_tasks ();
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
    cout << "1.Create task" << endl << "5.View tasks" << endl;
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
        c++;
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
        cout << "status: ";
        cin >> newNode->status;
        //scanf ("%s", &newNode->status);
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

void view_tasks ()
{
    timer("fetching");
    temp = head;
    while (temp != NULL)
    {
        /*printf ("task name: %s", temp->task);
        printf ("task name: %s", temp->priority);
        printf ("task name: %s", temp->status);*/
        cout << "task name: " << temp -> task << endl;
        cout << "task priority: " << temp -> priority << endl;
        cout << "task status: " << temp -> status << endl;
        //cout << "data: " << temp -> data << endl;
        temp = temp ->next;
        //cout << temp << endl;
        cout << "-------------------------------------------------------" << endl;
        //later add function to check remaining tasks
    }
}