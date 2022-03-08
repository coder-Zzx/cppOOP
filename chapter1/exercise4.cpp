/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
#include<cstring>
using namespace std;

class LLNode
{
public:
    char s[20];
    int s_length=0;
    LLNode* next;
    LLNode(char s[])
    {
        strcpy(this->s,s);
        this->s_length=strlen(this->s);
        this->next=NULL;
    }
};

class LList
{
public:
    LLNode* head;
    LLNode* current_node;
    LList()
    {
        this->head=NULL;
        this->current_node=NULL;
    }
    void insert(LLNode *p)
    {
        if (this->head==NULL)
        {
            this->head=p;
            this->current_node=p;
        }
        else
        {
            this->current_node->next=p;
            this->current_node=p;
        }
    }
    char* MyStrCat()
    {
        LLNode *start=this->head;
        int total_sum=0;
        while (start!=NULL)
        {
            total_sum+=start->s_length;
            start=start->next;
        }
        char* result=new char[total_sum]();
        while (this->head!=NULL)
        {
            strcat(result,head->s);
            head=head->next;
        }
        // cout<<result<<endl;
        return result;
    }
    ~LList()
    {
        while (this->head!=NULL)
        {
            LLNode *p=this->head;
            delete p;
            this->head=this->head->next;
        }
    }
};

int main()
{
    LList StringLinkList;
    char str[20];
    while(cin>>str)
    {
        LLNode *node=new LLNode(str);
        StringLinkList.insert(node);
    }
    char *output=StringLinkList.MyStrCat();
    cout<<output<<endl;
    // system("pause");
    return 0;
}
