#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Task {
    private:
        string task_name;
        string task_description;
        string task_id;
        bool task_completed;
    public:
        Task(string name,string description,string id)
        {
            this->task_name = name;
            this->task_description = description;
            this->task_id = id;
            task_completed = false;
        }

        //getters
        string getname() const {return task_name;}
        string getDescription () const{ return task_description; }

        //setters
          void markCompleted() { task_completed = true; }
};


class ToDoList {
    private:
        vector < Task > tasks;
    public:

    void displayMenu() const
    {
        cout<<endl;
        cout<<endl;
        cout<<"             'Welcome to task manager'         "<<endl;
        cout<<endl;
        cout<<"Select the operation : "<<endl;
        cout<<"1.Add task\n2.Remove task\n3.view task\n4.Mark task as completed\n0.Terminate the program"<<endl;

    }

    //add the new task
    void addTask()
    {
        string task_name,task_description,task_id;
        cout<<"Enter the task to add : ";
        cin.ignore();
        getline(cin,task_name);

        cout<<"Enter the description :";
        getline(cin,task_description);

        cout<<"Enter the id : ";
        getline(cin,task_id);

        tasks.emplace_back(task_name, task_description, task_id);
        cout << "Task added successfully!" << endl;
    }

    void removeTask()
    {
        if(tasks.empty())
        {
            cout<<"No more task to delete"<<endl;
            return;
        }

        cout<<"Tasks as follows : "<<endl;

        for(int i=0; i<static_cast<int>(tasks.size());i++)
        {
            cout<<i+1<<"."<<tasks[i].getname()<<endl;
        }
        cout<<endl;
        int taskTodelete;
        cout<<"Enter task number to delete : ";
        cin>>taskTodelete;

        if(taskTodelete >=1 && taskTodelete<=static_cast<int>(tasks.size()))
        {
            tasks.erase(tasks.begin()+taskTodelete-1);
            cout<<"Task deleted successfully"<<endl;
        }
        else
        {
            cout<<"Invalid task number !!"<<endl;
        }
        
    }

    void viewTask() const
    {
        if(tasks.empty())
        {
            cout<<"No more task exists !! "<<endl;
            return;
        }

        cout<<"Tasks : "<<endl;
        for(int i=0 ; i <  static_cast<int>(tasks.size());i++)
        {
            cout<<i+1<<"."<<tasks[i].getname()<<"--"<<tasks[i].getDescription()<<endl;
        }
        cout<<endl;
    }

    void completedTask()
    {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed!"
                 << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < static_cast<int>(tasks.size()); ++i) {
            cout << i + 1 << ". " << tasks[i].getname()<< endl;
        }
        cout << "Enter the task number to mark as completed: ";
        int taskNumber;
        cin >> taskNumber;

        if(taskNumber >=1 && taskNumber <= static_cast<int>(tasks.size()))
        {
            tasks[taskNumber-1].markCompleted();
            cout << "Task marked as completed!" << endl;    
        }
        else
        {
            cout<<"Invalid Task Numberrrr !! "<<endl;
        }
    }

    void run()
    {
        int choice = -1 ;
        while(choice != 0) {
            cout<<endl;
            displayMenu();
            cout<<"Select the operation : "<<endl;
            cin>>choice;

            switch(choice)
            {
                case 1 : addTask();
                break;
                case 2 : removeTask();
                break;
                case 3 : viewTask();
                break;
                case 4 : completedTask();
                break;
                case 0 : cout<<"Terminate the program !!"<<endl;
                break;
                default :  
                cout << "Invalid choice. Please try again!"<< endl;
                    
            }
        
        }
    }
};


int main()
{
   
    cout<<"Enter your name: ";
    string name;
    cin>>name;

    ToDoList d;
    d.run();
    return 0;
}

//Anish_Patil
//CodSoft
//@CodSoft Internship